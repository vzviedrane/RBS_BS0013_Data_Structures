#include "int_avl.hpp"
#include <cassert>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

void check_case(std::vector<int> keys, std::vector<int> expected) {
    IntAVL tree;
    for (int key : keys) {
        assert(tree.insert(key));
        assert(tree.check_invariant());
    }
    assert(tree.inorder() == expected);
    assert(tree.size() == expected.size());
    assert(tree.height() <= 2);
    for (int key : expected) assert(tree.contains(key));
    assert(!tree.contains(999));
}
void test_rotation_with_middle_subtree() {
    IntAVL tree;

    for (int key : {20, 10, 40, 30, 50, 25}) {
        assert(tree.insert(key));
        assert(tree.check_invariant());
    }

    assert((tree.inorder() == std::vector<int>{10, 20, 25, 30, 40, 50}));
    assert(tree.size() == 6);
    assert(tree.height() == 3);

    for (int key : {10, 20, 25, 30, 40, 50}) {
        assert(tree.contains(key));
    }
}
void test_negative_keys_and_duplicates() {
    IntAVL tree;

    for (int key : {-10, -20, -5, -15, -30}) {
        assert(tree.insert(key));
        assert(tree.check_invariant());
    }

    assert(!tree.insert(-20));
    assert(!tree.insert(-10));

    assert(tree.size() == 5);
    assert((tree.inorder() == std::vector<int>{-30, -20, -15, -10, -5}));
    assert(tree.check_invariant());
}
int main() {
    IntAVL empty;
    assert(empty.check_invariant() && empty.height() == 0);
    assert(!empty.contains(10));
    check_case({30,20,10}, {10,20,30}); // LL
    check_case({10,20,30}, {10,20,30}); // RR
    check_case({30,10,20}, {10,20,30}); // LR
    check_case({10,30,20}, {10,20,30}); // RL
    IntAVL t;
    for (int k=1;k<=127;++k) { assert(t.insert(k)); assert(t.check_invariant()); }
    assert(t.height() <= 8);
    assert(t.size() == 127);
    assert(!t.insert(64) && t.size()==127 && t.check_invariant());
    assert(t.insert(INT_MIN) && t.insert(INT_MAX) && t.check_invariant());
    std::set<int> oracle;
    IntAVL stress;
    unsigned x=2026;
    for (int i=0;i<3000;++i) {
        x = x*1664525U + 1013904223U;
        int key = static_cast<int>(x % 5000U) - 2500;
        const bool inserted=oracle.insert(key).second;
        assert(stress.insert(key)==inserted);
        assert(stress.check_invariant());
    }
    assert(stress.inorder()==std::vector<int>(oracle.begin(),oracle.end()));
    test_rotation_with_middle_subtree();
    test_negative_keys_and_duplicates();
    std::cout << "Week 10 AVL tests passed\n";
}
