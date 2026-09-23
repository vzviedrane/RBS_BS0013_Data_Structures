# Week 4 Reflection

Answer concisely after your implementation passes the public tests and sanitizer run.

1. Why can logical adjacency differ from physical address order in a linked list?
Nodes are connected by pointers, so they do not need to be next to each other in memory.
2. Why is numeric indexed access Θ(n) in a simple singly linked list?
Because we have to start from the head and follow the nodes until we reach the needed position.
3. Under what precise precondition is insertion by pointer rewiring Θ(1)?
When we already have a pointer to the node where the isnertion should happen.
4. Why is `insert_after_first(target, value)` still Θ(n) in the worst case?
Because we may need to search through the whole list to find the target.
5. What invariant responsibility is added by caching `tail_`?
`tail_` must always point to the last node, and its `next` must be `nullptr`.
6. Why must a removed node's successor be obtained before deleting the node?
Because after deleting the node, we cannot safely access its `next` pointer anymore.
7. Give one structural bug that a memory sanitizer may not directly identify as a linked-list invariant violation.
`tail_` could point to the wrong existing node even if all memory accesses are still valid.
8. Why can dynamic-array traversal outperform linked-list traversal even though both are Θ(n)?
Array elements are stored next to each other in memory, while linked-list nodes can be in different memory locations.
9. Give one workload favoring the Week 4 representation and one favoring Week 3's dynamic array.
A linked list is useful for frequent insertions when we already know the position. A dynamic array is bette for frequent indexed access.
10. How do these representation choices prepare you to implement stacks and queues next week?
They show how elements can be added and removed using different structures, which can be used to build stacks and queues.
