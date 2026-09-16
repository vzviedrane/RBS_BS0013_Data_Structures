# Week 3 Reflection — Dynamic Arrays

Complete this file briefly but precisely.

## 1. Size, capacity, and storage

1. Can `size()` be smaller than `capacity()`? Explain.

Yes. `size()` is the number of stored elements, while `capacity()` is the amount of space currently available.
2. Why must `size()` never exceed `capacity()`?

Beacuse we cannot store more elements than the allocated storage can hold.
3. Does every `push_back` allocate? What did `vector_growth` show?

No. Allocation happens when more capacity is needed. `vector_growth` showed capacity growing from 1 to 2, 4, 8, 16, and 32.
4. What does `data()` identify?

`data()` gives a pointer to the vector's current storage.

## 2. Reallocation and pointer validity

Why can a pointer to an element become invalid after a capacity-changing `push_back`? Explain using **storage lifetime**, not only address changes.

Reallocation creates new storage and ends the lifetime of the old storage. A pointer to the old storage is therefore no longer valid.

## 3. Invariants

State the two representation invariants used by `IntVector`. Why is checking an invariant after every mutating operation useful?

1) `size_ <= capacity_`
2) `capacity_ == 0` if and only if `data_ == nullptr`

Checking them after changes helps detect an invalid state early.

## 4. Complexity

Fill in the table.

| Operation | Complexity | Why? |
|---|---|---|
| `at(i)` | Θ(1) | Direct access by index |
| `push_back` without growth | Θ(1) | Adds one element |
| `push_back` that reallocates | Θ(n) | Existing elements must be copied |
| `push_back` amortized over many appends | Θ(1) | Reallocation does not happen on every append |
| copy construction | Θ(n) | All elements must be copied |

Why does doubling capacity give amortized constant-time append even though some individual appends are linear?

Because each reallocation creates much more free space, so many following `push_back` operations do not need another reallocation.

## 5. Deep copy

What would go wrong if copying `IntVector` only copied `data_`, `size_`, and `capacity_` member-by-member? Name at least two correctness/ownership problems.

Both objects would point to the same array.
1) Changes through one object could affect the other
2) Both destructors could try to delete the same memory
## 6. STL comparison

Give one reason to use `std::vector<int>` in production code instead of this teaching implementation, and one reason implementing `IntVector` is still useful in a data-structures course.

1) `std::vector<int>` is safer and provides more functionality for real programs.
2) Implementing `IntVector` helps understand dynamic memory, capacity growth, copying, and ownership.