#include "int_circular_queue.hpp"

#include <cassert>
#include <stdexcept>

IntCircularQueue::IntCircularQueue(std::size_t capacity)
    : data_(capacity) {
    assert(capacity > 0);
    check_invariant();
}

bool IntCircularQueue::empty() const {
    return size_ == 0;
}

bool IntCircularQueue::full() const {
    return size_ == data_.size();
}

std::size_t IntCircularQueue::size() const {
    return size_;
}

std::size_t IntCircularQueue::capacity() const {
    return data_.size();
}

int& IntCircularQueue::front() {
    if(empty()){
        throw std::out_of_range("front() on empty queue");
    }

    return data_[front_];
}

const int& IntCircularQueue::front() const {
    if(empty()){
        throw std::out_of_range("front() on empty queue");
    }

    return data_[front_];
}

int& IntCircularQueue::back() {
    if(empty()){
        throw std::out_of_range("back() on empty queue");
    }
    return data_[physical_index(size_ - 1)];
}

const int& IntCircularQueue::back() const {
    if(empty()){
        throw std::out_of_range("back() on empty queue");
    }
    return data_[physical_index(size_ - 1)];
}

void IntCircularQueue::enqueue(int value) {
    if(full()){
        throw std::overflow_error("enqueue() on full queue");
    }
    std::size_t index = (front_ +size_) % data_.size();
    data_[index] = value;

    ++size_;
    check_invariant();
}

void IntCircularQueue::dequeue() {
    if(empty()){
        throw std::out_of_range("dequeue() on empty queue");
    }

    front_ = (front_ + 1) % data_.size();
    --size_;

    if(size_ == 0){
        front_ = 0;
    }
    check_invariant();
}

void IntCircularQueue::clear() {
    front_ = 0;
    size_ = 0;

    check_invariant();
}

std::size_t IntCircularQueue::physical_index(std::size_t logical_index) const {
    assert(logical_index < size_);
    return(front_ + logical_index) % data_.size();
}

void IntCircularQueue::check_invariant() const {
    assert(!data_.empty());
    assert(size_ <= data_.size());
    assert(front_ < data_.size());
}
