import requests
import xml.etree.ElementTree as ET
from bs4 import BeautifulSoup
from time import sleep

SITEMAP_URL = "https://www.learncpp.com/sitemap.xml"
HEADERS = {"User-Agent": "Mozilla/5.0", "Referer": "https://www.learncpp.com/"}
NAMESPACE = {"ns": "http://www.sitemaps.org/schemas/sitemap/0.9"}


def get_subsitemaps():
    resp = requests.get(SITEMAP_URL, headers=HEADERS, timeout=20)
    root = ET.fromstring(resp.content)
    return [
        sm.find("ns:loc", NAMESPACE).text
        for sm in root.findall(".//ns:sitemap", NAMESPACE)
    ]


def get_lesson_urls(subsitemap_url):
    resp = requests.get(subsitemap_url, headers=HEADERS, timeout=20)
    root = ET.fromstring(resp.content)
    return [
        url.find("ns:loc", NAMESPACE).text
        for url in root.findall(".//ns:url", NAMESPACE)
        if url.find("ns:loc", NAMESPACE) is not None
        and "/cpp-tutorial/" in url.find("ns:loc", NAMESPACE).text
    ]


def extract_best_practices(url):
    try:
        resp = requests.get(url, headers=HEADERS, timeout=15)
        soup = BeautifulSoup(resp.text, "html.parser")
    except Exception as e:
        print(f"Error fetching {url}: {e}")
        return []
    practices = []
    for box in soup.select("div.cpp-note.cpp-lightgreenbackground"):
        ps = box.find_all("p", recursive=True)
        if not ps:
            continue
        title = ps[0].get_text(strip=True).lower()
        if "best practice" in title:
            for advice_p in ps[1:]:
                tip = advice_p.get_text(separator="\n", strip=True)
                if tip:
                    practices.append(tip)
    return practices


def main():
    print("Fetching subsitemaps...")
    subsitemaps = get_subsitemaps()
    all_lessons = set()
    print(f"Found {len(subsitemaps)} subsitemaps.")
    for s in subsitemaps:
        lesson_urls = get_lesson_urls(s)
        all_lessons.update(lesson_urls)
        print(f"  - {s} => {len(lesson_urls)} lessons")
        sleep(0.2)  # Be polite

    print(f"Total unique lessons: {len(all_lessons)}")

    results = []
    for i, url in enumerate(sorted(all_lessons)):
        best_practices = extract_best_practices(url)
        if best_practices:
            print(
                f"[{i+1}/{len(all_lessons)}] {url} -- {len(best_practices)} best practices"
            )
            for bp in best_practices:
                results.append((url, bp))
        else:
            print(f"[{i+1}/{len(all_lessons)}] {url} -- none found")
        sleep(0.5)  # Avoid hammering the site

    # Save to markdown
    with open("learncpp_best_practices.md", "w", encoding="utf-8") as f:
        for url, bp in results:
            f.write(f"### {url}\n\n")
            f.write(f"> {bp}\n\n")

    print(f"Done! {len(results)} best practices saved to learncpp_best_practices.md")


if __name__ == "__main__":
    main()
