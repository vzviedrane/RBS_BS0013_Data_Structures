# Week 9 Reflection — BST

1. **Global invariant:** Give one tree that passes immediate parent/child ordering checks but violates the BST invariant.

For example, root 50 has left child 30, and 30 has right child 60. Each direct parent-child comparison is correct, but 60 is in the left subtree of 50 and is greater than 50. This breaks the global BST invariant.
2. **Pointer semantics:** Explain why Node*& is useful when inserting into an empty tree or deleting the root.

Node*& is a reference to a pointer. It allows us to change the actual pointer in the tree. When inserting into an empty tree, we can update root_. When deleting the root, we can replace root_ with its child or nullptr.
3. **Deletion trace:** Start with 50,30,70,20,40,60,80. Delete 50 using the inorder successor. Identify exactly which node is freed.

The inorder successor of 50 is 60, because it is the smallest key in the right subtree. We replace the key 50 with 60. Then we delete the original node containing 60 from the left child of 70. Only the original node 6o is freed, and the tree size decreases by one.
4. **Complexity:** State contains, insert and erase costs in h and in n for a well-shaped versus degenerate BST. Distinguish iterative search space from recursive operation space.

Contains, insert and erase take O(h) time, where h is the tree height. In a well-shaped BST, h is O(log n), so the operations take O(log n). In a degenerate BST, h is O(n), so they take O(n). Iterative contains uses O(1) extra space, while recursive insert and erase use O(h) stack space.
5. **Height:** Compare insertion orders [4,2,6,1,3,5,7] and [1,2,3,4,5,6,7]; why does a plain BST not guarantee logarithmic time?

The first insertion order creates a well-shaped tree with height 3. The second order creates a chain with height 7. A plain BST does not balance itself, so its shape depends on insertion order. This is why operations are not always O(log n) and can take O(n) time.
6. **Ownership and production:** Why is this raw-pointer tree noncopyable? Explain one benefit of std::set<int> in production C++.

This tree is noncopyable because it owns nodes through raw pointers. A simple copy would share the same nodes and could cause double deletion. In production C++, std::set<int> is safer because it manages memory automatically and keeps the tree balanced, providing O(log n) search, insertion and deletion.