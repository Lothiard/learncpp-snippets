#include "Random.h"
#include <string>
#include <string_view>
#include <iostream>

class Monster {
public:
    enum Type {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes,
    };

    Monster(Type type, std::string_view name, std::string_view roar, int hitPoints) :
        type_{ type },
        name_{ name },
        roar_{ roar },
        hitPoints_{ hitPoints }
    {}

    constexpr std::string_view getTypeString() const;
    void print() const;

private:
    Type type_{};
    std::string name_{"???"};
    std::string roar_{"???"};
    int hitPoints_{};
};

constexpr std::string_view Monster::getTypeString() const {
    switch(type_) {
    case dragon: return "dragon";
    case goblin: return "goblin";
    case ogre: return "ogre";
    case orc: return "orc";
    case skeleton: return "skeleton";
    case troll: return "troll";
    case vampire: return "vampire";
    case zombie: return "zombie";
    default: return "???";
    }
}

void Monster::print() const {
    std::cout << name_ << " the " << getTypeString();
    if(hitPoints_ <= 0) {
        std::cout << " is dead\n";
    } else {
        std::cout << " has " << hitPoints_
                  << " hit points and says " << roar_ << '\n';
    }
}

namespace MonsterGenerator {
    std::string_view getName(int number) {
        switch(number) {
        case 0: return "Attila";
        case 1: return "Zsolti";
        case 2: return "Szabi";
        case 3: return "Zalan";
        case 4: return "Ricsi";
        case 5: return "Drogos Peti";
        default: return "???";
        }
    }

    std::string_view getRoar(int number) {
        switch(number) {
        case 0: return "jon a lengyel kamion";
        case 1: return "en vagyok a pantolas demonja";
        case 2: return "szerelem az autot";
        case 3: return "megbolondultam";
        case 4: return "hol a kristaly";
        case 5: return "geci";
        default: return "???";
        }
    }

    Monster generate() {
        return Monster{
            static_cast<Monster::Type>(Random::get(0, Monster::Type::maxMonsterTypes - 1)),
            getName(Random::get(0, 5)),
            getRoar(Random::get(0, 5)),
            Random::get(0, 100)
        };
    }
}

int main() {
    Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();

    Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
    vampire.print();

    Monster a{ MonsterGenerator::generate() };
    a.print();

    Monster b{ MonsterGenerator::generate() };
    b.print();

    Monster c{ MonsterGenerator::generate() };
    c.print();

    return 0;
}
