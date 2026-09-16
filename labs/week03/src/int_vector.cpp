#include "int_vector.hpp"


IntVector::~IntVector() {
    delete[] data_;
}

IntVector::IntVector(const IntVector& other)
    : size_(other.size_), capacity_(other.capacity_) {

        if(capacity_ > 0){
            data_ = new int[capacity_];

            for(std::size_t i = 0; i < size_; ++i){
                data_[i] = other.data_[i];
            }
        }
        check_invariant();
    }

void IntVector::check_invariant() const {
    assert(size_ <= capacity_);
    assert((capacity_ == 0) == (data_ == nullptr));
}

void IntVector::grow() {
    std::size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;

    int* new_data = new int[new_capacity];

    for (std::size_t i =0; i < size_; ++i) {
        new_data[i] = data_[i];
    }

    delete[] data_;

    data_ = new_data;
    capacity_ = new_capacity;

    check_invariant();
}

void IntVector::push_back(int value) {
    if(size_ == capacity_) {
        grow();
    }

    data_[size_] = value;
    ++size_;

    check_invariant();
}
