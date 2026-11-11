# Week 10 Reflection

1. Draw a left rotation when the pivot has a **nonempty left subtree** B. Why must B become the old root's right subtree?
Before left rotation:

    10
      \
       30
      /
     20 (B)

After left rotation:

       30
      /
     10
       \
        20 (B)
During a left rotation, subtree B becomes the old root's right subtree. This keeps the BST order because all keys in B are greater than the old root but smaller than the pivot.
2. Why must the old root's cached height be refreshed before the promoted pivot's height?
After a rotation, the old root becomes a child of the new root. We must update the old root's height first because the new root's height depends on its children's heights. Otherwise, we could use an outdated height.
3. Give one LR and one RL insertion sequence; identify each individual rotation.
An LR case happens when inserting 30, 10, 20. First, we rotate left at 10, then right at 30. An RL case happens when inserting 10, 30, 20. First, we rotate right at 30, then left at 10. In both cases, 20 becomes the root.
4. Why is checking only the root's balance factor not enough?
Checking only the root is not enough because the root can be balanced while some nodes deeper in the tree are not. In an AVL tree, every node must have a balance factor between -1 and 1.
5. State worst-case time and auxiliary space for AVL search and recursive insert. Why does a constant-time rotation not make insertion constant-time?
AVL search takes O(log n) time and O(1) extra space because it is iterative. Recursive insertion takes O(log n) time and O(log n) stack space. A rotation takes O(1) time, but insertion still needs to travel down the tree and update the ancestors, so the total time is O(log n).
6. Why can AVL deletion require more than one ancestor to be rebalanced?
Deleting a node can decrease the height of a subtree. This change can make several ancestors unbalanced. After fixing one node, the height may decrease again, so we may need to rebalance other ancestors on the path to the root.

**Two additional tests implemented:**

- Test A:Tested a longer insertion sequence (20, 10, 40, 30, 50, 25). Verified that rotations preserve the middle subtree, all keys remain present, and the AVL invariant holds.
- Test B:Tested negative keys and duplicate insertions. Verified sorted inorder traversal, correct tree size, and that duplicate keys are rejected.
