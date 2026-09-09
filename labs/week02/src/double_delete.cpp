int main() {
    int* p = new int{42};
    int* q = p;

    delete p;

    // Intentionally invalid for the AddressSanitizer exercise.
    delete q;

    // p and q are 2 separate pointer variables, but they store the same address.
    // Only 1 int was allocated with new, so there is only 1 allocation.
    // After delete p, that allocation is already released, so delete q tries
    // to release the same memory a second time (double delete).
}
