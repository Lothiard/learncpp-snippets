#ifndef DIRECTION_H
#define DIRECTION_H

class Direction {
public:
    enum Type {
        up,
        down,
        left,
        right,

        maxDirections,
    };

    Direction(Type direction);

    Type direction() const;

    Direction operator-() const;
    static Direction getRandomDirection();

private:
    Type direction_{};
};

#endif
