#include <iostream>
#include <vector>

void print_values(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << "\n";
}

int sum(const std::vector<int>& values) {
    int total = 0;

    for (int value : values) {
        total += value;
    }

    return total;
}

void add_to_all(std::vector<int>& values, int amount) {
    for (int& value : values) {
        value += amount;
    }
}

int main() {
    std::vector<int> values{12, 7, 18, 4, 21, 9};

    std::cout << "Original: ";
    print_values(values);
    std::cout << "Sum: " << sum(values) << '\n';

    add_to_all(values, 5);

    std::cout << "Modified: ";
    print_values(values);
    std::cout << "New sum: " << sum(values) << '\n';
}
