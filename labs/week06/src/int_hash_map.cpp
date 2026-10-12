#include "int_hash_map.hpp"

#include <cassert>


IntHashMap::IntHashMap(std::size_t capacity)
    : slots_(capacity) {
    assert(capacity > 0);
}

double IntHashMap::load_factor() const noexcept {
    return static_cast<double>(size_) / static_cast<double>(capacity());
}

std::size_t IntHashMap::bucket(int key) const {
    assert(key >= 0);
    return static_cast<std::size_t>(key) % capacity();
}

std::size_t IntHashMap::find_index(int key) const {
    std::size_t start = bucket(key);

    for(std::size_t i = 0; i < capacity(); ++i){
        std::size_t index = (start + i) % capacity();

        if (slots_[index].state == SlotState::Empty) {
            return capacity();
        }

        if (slots_[index].state == SlotState::Occupied && slots_[index].key == key){
            return index;
        }
    }
    return capacity();
}

bool IntHashMap::contains(int key) const {
    return find(key) != nullptr;
}

int* IntHashMap::find(int key) {
    std::size_t index = find_index(key);
    if (index == capacity()){
        return nullptr;
    }
    return &slots_[index].value;
}

const int* IntHashMap::find(int key) const {
    std::size_t index = find_index(key);
    if(index == capacity()){
        return nullptr;
    }
    return &slots_[index].value;
}

bool IntHashMap::insert_or_assign(int key, int value) {
    assert(key >= 0);

    std::size_t start = bucket(key);
    std::size_t first_deleted = capacity();

    for (std::size_t i = 0; i < capacity(); ++i){
        std::size_t index = (start + i)%capacity();

        if(slots_[index].state == SlotState::Occupied){
            if(slots_[index].key == key){
                slots_[index].value = value;
                return false;
            }
        }else if (slots_[index].state == SlotState::Deleted){
            if(first_deleted == capacity()){
                first_deleted = index;
            }
        }else{
            std::size_t insert_index = (first_deleted != capacity())?first_deleted : index;

            slots_[insert_index].key = key;
            slots_[insert_index].value = value;
            slots_[insert_index].state = SlotState::Occupied;
            ++size_;

            return true;
        }
    }

    if(first_deleted != capacity()){
        slots_[first_deleted].key = key;
        slots_[first_deleted].value = value;
        slots_[first_deleted].state = SlotState::Occupied;
        ++size_;

        return true;
    }
    return false;
}

bool IntHashMap::erase(int key) {
    assert(key >= 0);

    std::size_t index = find_index(key);

    if(index == capacity()){
        return false;
    }

    slots_[index].state = SlotState::Deleted;
    --size_;

    return true;
}

std::size_t IntHashMap::probe_count(int key) const {
    assert(key >= 0);

    std::size_t start = bucket(key);

    for(std::size_t i = 0; i < capacity(); ++i){
        std::size_t index = (start + i)%capacity();

        if(slots_[index].state == SlotState::Empty){
            return i+1;
        }

        if(slots_[index].state == SlotState::Occupied && slots_[index].key == key){
            return i+1;
        }
    }
    return capacity();
}

bool IntHashMap::check_invariant() const {
    if(slots_.empty()){
        return false;
    }

    if(size_ > capacity()){
        return false;
    }

    std::size_t occupied_count = 0;

    for(const HashSlot& slot : slots_){
        if(slot.state ==SlotState::Occupied){
            ++occupied_count;
        }
    }
    return occupied_count == size_;
}