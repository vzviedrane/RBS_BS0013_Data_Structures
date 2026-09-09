# Week 2 Reflection

Answer briefly but precisely.

## 1. Pointer copying

Why does copying a pointer value not copy the pointed-to object?

Copying a pointer copies only the address stored in the pointer.
It does not create a new copy of the object.
Both pointers can point to the same object.

## 2. Reachability versus lifetime

Explain how an object can still be alive but no longer reachable by traversing from a particular head pointer.

A node can still exist even if the head no longer leads to it.
Changing links changes reachability, not the node's lifetime.

## 3. Dangling pointers

When a pointer becomes dangling, what changed: the pointer's stored numeric value, the target object's lifetime, or necessarily both?

Usually the pointer keeps the same address, but the target object's lifetime has ended.
The pointer value itself does not have to change.

## 4. Ownership responsibility

Why can two pointers to one dynamically allocated object not both independently `delete` it?

Two pointers may point to the same allocation, but there is still only one allocated object.
It must be deleted only once.
## 5. `nullptr`

Why does assigning `nullptr` to a raw pointer not release dynamically allocated storage?

'p = nullptr' only changes the address stored in 'p'.
It does not call 'delete', so the allocated memory is not released.

## 6. Linked traversal complexity

Why is traversal of `n` linked nodes Θ(n) even though following one `next` pointer is Θ(1)?

Following one 'next' pointer is Θ(1), but for 'n' nodes we do this 'n' times, so total time is Θ(n).

## 7. Invariants

State two invariants that should hold for the final chain `10 -> 20 -> 25 -> 30 -> null`.

Traversal from the head reaches '10, 20, 25, 30' exactly once.
The last node has 'next == nullptr'.