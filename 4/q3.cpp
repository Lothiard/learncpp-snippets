#include <iostream>

const double gravity{9.8};

int getTowerHeight() {
    std::cout << "Enter the height of the tower in meters: ";
    int input{};
    std::cin >> input;
    return input;
}

double updateBall(int time) {
    return gravity * time * time / 2.0;
}

void print(int time, double height) {
    if(height < 0) height = 0;
    std::cout << "At " << time << "seconds, the ball is at height: " << height 
    << '\n';
}

int main() {
    int towerHeight{getTowerHeight()};
    int time{};
    double newHeight{towerHeight - updateBall(time)};
    print(time, newHeight);

    newHeight -= updateBall(++time);
    print(time, newHeight);
    newHeight -= updateBall(++time);
    print(time, newHeight);
    newHeight -= updateBall(++time);
    print(time, newHeight);
    newHeight -= updateBall(++time);
    print(time, newHeight);

    return 0;
}
