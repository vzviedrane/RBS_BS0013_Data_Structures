#include "int_avl.hpp"
#include <algorithm>
#include <cstdlib>

IntAVL::~IntAVL() { destroy(root_); }
void IntAVL::destroy(Node* p) noexcept {
    if (!p) return;
    destroy(p->left);
    destroy(p->right);
    delete p;
}
bool IntAVL::contains(int key) const noexcept {
    const Node* p = root_;
    while (p) {
        if (key == p->key) return true;
        p = key < p->key ? p->left : p->right;
    }
    return false;
}
void IntAVL::inorder_at(const Node* p, std::vector<int>& out) {
    if (!p) return;
    inorder_at(p->left, out);
    out.push_back(p->key);
    inorder_at(p->right, out);
}
std::vector<int> IntAVL::inorder() const {
    std::vector<int> result;
    result.reserve(size_);
    inorder_at(root_, result);
    return result;
}
bool IntAVL::insert(int key) { return insert_at(root_, key); }
void IntAVL::refresh(Node* p) noexcept {
    if(p == nullptr){
        return;
    }

    int left_height = p->left ? p->left->height : 0;
    int right_height = p->right ? p->right->height : 0;

    p->height = 1 + std::max(left_height, right_height);
}
void IntAVL::rotate_left(Node*& link) noexcept {
    Node* pivot = link->right;
    Node* middle = pivot->left;

    pivot->left = link;
    link->right = middle;

    refresh(link);
    refresh(pivot);

    link = pivot;
}
void IntAVL::rotate_right(Node*& link) noexcept {
    Node* pivot = link->left;
    Node* middle = pivot->right;

    pivot->right = link;
    link->left = middle;

    refresh(link);
    refresh(pivot);

    link = pivot;
}
void IntAVL::rebalance(Node*& link) noexcept {
    int left_height = link->left ? link->left->height : 0;
    int right_height = link->right ? link->right->height : 0;
    int balance = left_height - right_height;

    if (balance > 1){
        Node* child = link->left;

        int child_left = child->left ? child->left->height : 0;
        int child_right = child->right ? child->right->height : 0;

        if (child_right > child_left){
            rotate_left(link->left);
        }

        rotate_right(link);
    }else if(balance < -1){
        Node* child = link->right;

        int child_left = child->left ? child->left->height : 0;
        int child_right = child->right ? child->right->height : 0;

        if(child_left > child_right){
            rotate_right(link->right);
        }
        rotate_left(link);
    }
}
bool IntAVL::insert_at(Node*& link, int key) {
    if (!link) {
        link = new Node{key};
        ++size_;
        return true;
    }
    if (key == link->key) return false;
    const bool added = key < link->key ? insert_at(link->left, key)
                                       : insert_at(link->right, key);
    if (!added) return false;
    refresh(link);
    rebalance(link);
    return true;
}
bool IntAVL::validate(const Node* p, std::optional<int> lo,
                      std::optional<int> hi, std::size_t& count,
                      int& actual_height) noexcept {
    if (!p) { actual_height = 0; return true; }
    if ((lo && p->key <= *lo) || (hi && p->key >= *hi)) return false;
    ++count;
    int left_height = 0, right_height = 0;
    if (!validate(p->left, lo, p->key, count, left_height) ||
        !validate(p->right, p->key, hi, count, right_height)) return false;
    actual_height = 1 + std::max(left_height, right_height);
    // TODO 5: check stored height and local AVL balance bound.
    if(p->height != actual_height){
        return false;
    }

    if(std::abs(left_height - right_height) > 1){
        return false;
    }

    return true;
}
bool IntAVL::check_invariant() const noexcept {
    std::size_t count = 0;
    int actual_height = 0;
    return validate(root_, std::nullopt, std::nullopt, count, actual_height)
        && count == size_ && actual_height == height();
}
