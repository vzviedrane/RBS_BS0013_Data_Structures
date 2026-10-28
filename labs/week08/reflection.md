# Week 8 Reflection — Heap and Priority Queue

Answer concisely after your implementation passes the tests.

1. **Representation.** How can a `std::vector` represent a complete binary tree without storing child pointers?

A std::vector stores the heap element sin an array. We can find the parent and children using index formulas, so we do not need pointers. The left child is at 2*i+1 and the right child is at 2*i+2

2. **Invariant.** State the shape invariant and heap-order invariant separately. Why does satisfying the heap-order invariant not make the whole vector sorted?

Thw shape invariant means that all elements are stored next to each other without gaps, so the tree is complete. The heap-order invariant means that every parent is greater than or equal to its children. The vector is not fully sorted because we only compare parents with their children, not every element with the others.

3. **Complexity.** Explain why sift-up and sift-down inspect at most `Θ(log n)` tree levels. Also state the vector-reallocation qualification for an individual `push()`.

Sift-up and sift-down move through one path in the tree, not through all elements. The height of a binary heap is O(log n), so these opeartion stake O(log n) time. During push(), the vector may sometimes need to reallocate memory and move all elements. In that case, one push() can take O(n), but vector insertion is O(1) amortized.

4. **Heapify.** Why can bottom-up heap construction run in `Θ(n)` even though one sift-down can cost `O(log n)`?

Bottom-up heapigy starts from the last parent and moves tpwards the root. Most nodes are near the bottom of the tree, so they need only a few swaps. Leaves do not need any swaps. Because of this, the total time is O(n), even though one sift-down can take O(log n)

5. **Library comparison.** Give one reason to use `std::priority_queue` in production code and one reason implementing `BinaryHeap<T>` is pedagogically useful.

Both BinaryHeap and std::priority_queue allow us to add elements, see the highest-priority element, and remove it. In real projects, I would use std::priority_queue because it is already tested and easier to use. Our BinaryHeap also lets us see the internal vector, while std::priority_queue hides its storage. Implementing my own heap helped me understand how sift-up, sift-down, and heapify work.
