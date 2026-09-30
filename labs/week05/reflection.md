# Week 5 Reflection — Circular Queue

Answer briefly after your implementation works.

1. Why is `enqueue` Θ(1) **worst case** in this fixed-capacity queue?
Because the queue has fixed storage and adding an element only requires calculating its position and storing the value.
2. Why is `dequeue` Θ(1) worst case?
Because we only move `front_` to the next position and decrease `size_`. We do not shift the other elements.
3. Why would a dynamically growing circular queue normally describe enqueue as **amortized Θ(1)** instead?
Because sometimes the storage would need to grow and the existing elements would have to be copied.
4. In the expression `(front_ + i) % capacity()`, what does `i` mean: a physical index or a logical position?
`i` is a logical poistion in the queue.
5. Why can the physical array still contain an old integer after `dequeue()` without that value remaining part of the logical queue?
Beacause `dequeue()` changes `front_` and `size_`. The old value can stay in memory, but it is no longer part of the logical queue.
6. Give one practical advantage of a circular array over a linked queue.
A circular array does not need a separate memory allocation for every element.
7. Give one practical limitation of this fixed-capacity circular queue.
It cannot accept more elements when it reaches its fixed capacity.
8. Which of these statements belongs to the **queue ADT**, and which belongs only to our **representation**?

Queue ADT:
   - first inserted remaining element is removed first;
   - `front()` returns the next element to be removed.

Representation:
   - storage is a `std::vector<int>`;
   - elements may wrap around index 0;
