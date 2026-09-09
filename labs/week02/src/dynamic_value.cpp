#include <iostream>

int main() {
    int* p = new int{42};

    std::cout << "initial = " << *p << '\n';
    *p = 100;
    std::cout << "changed = " << *p << '\n';

    delete p;
    p = nullptr;
    
    return 0;
}
