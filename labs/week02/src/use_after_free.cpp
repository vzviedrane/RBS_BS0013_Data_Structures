#include <iostream>

int main() {
    int* p = new int{42};
    delete p;

    // Intentionally invalid for the AddressSanitizer exercise.
    std::cout << *p << '\n';

    // Correct repair - do not dereference p after delete.
    // After delete, the object no longer exists and p is dangling.
    // If the pointer is no longer needed, set p = nullptr.
}
