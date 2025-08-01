#include <iostream>
#include <vector>

void print(const std::vector<int>& stack) {
    std::cout << "\t(Stack:";

    if(stack.empty()) {
        std::cout << " empty)\n";
        return;
    }

    for(auto num : stack) {
        std::cout << ' ' << num;
    }
    std::cout << ")\n";
}

void push(std::vector<int>& stack, int num) {
    stack.push_back(num);
    std::cout << "Push " << num;
    print(stack);
}

void pop(std::vector<int>& stack) {
    stack.pop_back();
    std::cout << "Pop";
    print(stack);
}

int main() {
    std::vector<int> stack{};

    print(stack);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    pop(stack);
    push(stack, 4);
    pop(stack);
    pop(stack);
    pop(stack);

    return 0;
}
