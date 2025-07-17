#include <iostream>

namespace Monster {
    enum MonsterType {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

int main() {
    [[maybe_unused]] Monster::MonsterType troll{Monster::MonsterType::troll};

    return 0;
}
