#include <iostream>

namespace Monster {
    enum class MonsterType {
        ogre,
        dragon,
        orc,
        giant_spider,
        slime,
    };

    struct Monster {
        MonsterType type{};
        std::string name{};
        int health{};
    };
}

void printMonster(const Monster::Monster& monster) {
    std::string_view type{};
    switch(monster.type) {
        case Monster::MonsterType::ogre: type = {"Ogre"}; break;
        case Monster::MonsterType::dragon: type = {"Dragon"}; break;
        case Monster::MonsterType::orc: type = {"Orc"}; break;
        case Monster::MonsterType::giant_spider: type = {"Giant Spider"}; break;
        case Monster::MonsterType::slime: type = {"Slime"}; break;
        default: type = {"Unknown"}; break;
    }
    std::cout << "This " << type << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main() {
    Monster::Monster ogre{Monster::MonsterType::ogre, "Torg", 145};
    Monster::Monster slime{Monster::MonsterType::slime, "Blurp", 23};

    printMonster(ogre);
    printMonster(slime);
}
