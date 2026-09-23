#include "int_linked_list.hpp"

#include <stdexcept>

IntLinkedList::~IntLinkedList() {
    clear();
}

int& IntLinkedList::front() {
    if(head_ == nullptr){
        throw std::out_of_range("front() on empty list");
    }
    return head_->value;
}

const int& IntLinkedList::front() const {
    if(head_ == nullptr){
        throw std::out_of_range("front() on empty list");
    }
    return head_->value;
}

int& IntLinkedList::back() {
    if(tail_ == nullptr){
        throw std::out_of_range("back() on empty list");
    }
    return tail_->value;
}

const int& IntLinkedList::back() const {
    if(tail_ == nullptr){
        throw std::out_of_range("back() on empty list");
    }
    return tail_->value;
}

void IntLinkedList::push_front(int value) {
    Node* new_node = new Node{value, head_};

    head_ = new_node;

    if(size_ == 0){
        tail_ = new_node;
    }
    ++size_;
}

void IntLinkedList::push_back(int value) {
    Node* new_node = new Node{value, nullptr};

    if(size_ == 0){
        head_ = new_node;
        tail_ = new_node;
    } 
    else {
        tail_->next = new_node;
        tail_ = new_node;
    }
    ++size_;
}

void IntLinkedList::pop_front() {
    if(head_ == nullptr){
        throw std::out_of_range("pop_front() on empty list");
    }

    Node* old_head = head_;
    head_ = head_->next;

    delete old_head;
    --size_;

    if(size_ == 0){
        tail_ = nullptr;
    }
}

bool IntLinkedList::contains(int value) const noexcept {
    Node* current = head_;

    while(current != nullptr){
        if(current->value == value){
            return true;
        }
        current = current->next;
    }
    return false;
}

bool IntLinkedList::insert_after_first(int target, int value) {
    Node* current = head_;

    while(current != nullptr){
        if(current->value == target){
            Node* new_node = new Node{value, current->next};
            current->next = new_node;

            if(current == tail_){
                tail_ = new_node;
            }
            ++size_;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool IntLinkedList::erase_after_first(int target) {
    Node* current = head_;

    while(current != nullptr){
        if(current->value == target){
            if(current->next == nullptr){
                return false;
            }

            Node* to_delete = current->next;
            current->next = to_delete->next;

            if(to_delete == tail_){
                tail_ = current;
            }
            delete to_delete;
            --size_;

            return true;
        }
        current = current->next;
    }
    return false;
}

void IntLinkedList::clear() noexcept {
    Node* current = head_;

    while(current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

bool IntLinkedList::check_invariant() const noexcept {
    if(size_ == 0){
        return head_ == nullptr && tail_ == nullptr;
    }

    if(head_ == nullptr || tail_ == nullptr){
        return false;
    }

    std::size_t count = 0;
    Node* current = head_;
    Node* last = nullptr;

    while(current != nullptr && count <= size_){
        last = current;
        current = current->next;
        ++count;
    }

    if(current != nullptr){
        return false;
    }

    return count == size_ &&
            last == tail_ &&
            tail_->next == nullptr;
}
