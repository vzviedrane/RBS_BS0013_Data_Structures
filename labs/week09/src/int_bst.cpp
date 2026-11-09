#include "int_bst.hpp"
#include <algorithm>
#include <stdexcept>

// The postorder destructor is supplied and must not be removed.
IntBST::~IntBST() { destroy(root_); }
void IntBST::destroy(Node* node) noexcept {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
bool IntBST::contains(int key) const {
    Node* current = root_;

    while(current != nullptr){
        if(key == current->key){
            return true;
        }

        if(key < current->key){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return false;
}
bool IntBST::insert(int key) { return insert_at(root_, key); }
bool IntBST::insert_at(Node*& node, int key) {
    if(node == nullptr){
        node = new Node{key, nullptr, nullptr};
        ++size_;
        return true;
    }
    if(key == node->key){
        return false;
    }
    if(key < node->key){
        return insert_at(node->left, key);
    }
    return insert_at(node->right, key);
}
bool IntBST::erase(int key) { return erase_at(root_, key); }
bool IntBST::erase_at(Node*& node, int key) {
    if(node == nullptr){
        return false;
    }
    
    if(key < node->key){
        return erase_at(node->left, key);
    }

    if(key > node->key){
        return erase_at(node->right, key);
    }
    if(node->left == nullptr || node->right == nullptr){
        Node* old = node;

        if(node->left != nullptr){
            node = node->left;
        }else{
            node = node->right;
        }
        delete old;
        --size_;
        return true;
    }
    Node* successor = node->right;

    while(successor->left != nullptr){
        successor = successor->left;
    }
    int successor_key = successor->key;
    node->key = successor_key;

    return erase_at(node->right, successor_key);
}
std::vector<int> IntBST::inorder() const {
    std::vector<int> result;
    result.reserve(size_);
    inorder_at(root_, result);
    return result;
}
void IntBST::inorder_at(const Node* node, std::vector<int>& out) {
    if(node == nullptr){
        return;
    }
    inorder_at(node->left, out);
    out.push_back(node->key);
    inorder_at(node->right, out);
}
int IntBST::height() const noexcept { return height_at(root_); }
int IntBST::height_at(const Node* node) noexcept {
    if(node == nullptr){
        return 0;
    }

    int left_height = height_at(node->left);
    int right_height = height_at(node->right);

    return 1 + std::max(left_height, right_height);
}
bool IntBST::check_invariant() const {
    std::size_t count = 0;
    return validate(root_, std::nullopt, std::nullopt, count) && count == size_;
}
bool IntBST::validate(const Node* node, std::optional<int> lower,
                      std::optional<int> upper, std::size_t& count) {
    if(node == nullptr){
        return true;
    }

    if(lower && node->key <= *lower){
        return false;
    }

    if(upper && node->key >= *upper){
        return false;
    }

    ++count;

    return validate(node->left, lower, node->key, count) && validate(node->right, node->key, upper, count);
}
