
#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
class BinaryHeap {
public:
    BinaryHeap() = default;

    explicit BinaryHeap(std::vector<T> values)
        : data_(std::move(values)) {
        heapify();
    }

    [[nodiscard]] bool empty() const noexcept {
        return data_.empty();
    }

    [[nodiscard]] std::size_t size() const noexcept {
        return data_.size();
    }

    [[nodiscard]] const std::vector<T>& storage() const noexcept {
        return data_;
    }

    [[nodiscard]] const T& top() const {
        if(data_.empty()){
            throw std::out_of_range("Heap is empty");
        }
        return data_[0];
    }

    void push(const T& value) {
        data_.push_back(value);
        sift_up(data_.size() - 1);
    }

    void pop() {
        if (data_.empty()){
            throw std::out_of_range("Heap is empty");
        }

        data_[0] = data_.back();
        data_.pop_back();

        if(!data_.empty()){
            sift_down(0);
        }
    }

    [[nodiscard]] bool check_invariant() const {
        for(std::size_t i = 1; i < data_.size(); ++i){
            if(data_[i] > data_[parent(i)]){
                return false;
            }
        }
        return true;
    }

private:
    [[noreturn]] static void todo(const char* operation) {
        throw std::logic_error(operation);
    }

    [[nodiscard]] static std::size_t parent(std::size_t i) {
        return (i - 1)/2;
    }

    [[nodiscard]] static std::size_t left(std::size_t i) {
        return 2*i+1;
    }

    [[nodiscard]] static std::size_t right(std::size_t i) {
        return 2*i+2;
    }

    void sift_up(std::size_t i) {
        while(i > 0){
            std::size_t p = parent(i);

            if(data_[i] <= data_[p]){
                break;
            }

            std::swap(data_[i], data_[p]);
            i = p;
        }
    }

    void sift_down(std::size_t i) {
        std::size_t n = data_.size();

        while (left(i) < n){
            std::size_t largest = left(i);
            std::size_t r = right(i);

            if(r < n && data_[r] > data_[largest]){
                largest = r;
            }

            if (data_[i] >= data_[largest]){
                break;
            }

            std::swap(data_[i], data_[largest]);
            i = largest;
        }
    }

    void heapify() {
        for(std::size_t i = data_.size() / 2; i > 0; --i){
            sift_down(i - 1);
        }
    }

    std::vector<T> data_;
};
