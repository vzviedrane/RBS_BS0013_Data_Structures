#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{10, 20, 30};

    values.push_back(40);
    values.push_back(50);

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::cout << "Size: " << values.size() << '\n';
    std::cout << "First: " << values.front() << '\n';
    std::cout << "Last: " << values.back() << '\n';

    // TODO: add 50, then print the size, first element, and last element.
}

