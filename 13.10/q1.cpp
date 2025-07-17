#include <iostream>

struct Revenue {
    int watchedAds{};
    double clickedPrecentage{};
    double averageEarningPerAd{};
};

double calculateRevenue(const Revenue& revenue) {
    return revenue.watchedAds * revenue.clickedPrecentage * revenue.averageEarningPerAd;
}

int main() {
    Revenue siteRevenue{8, 40.0, 0.15};
    std::cout << calculateRevenue(siteRevenue);

    return 0;
}
