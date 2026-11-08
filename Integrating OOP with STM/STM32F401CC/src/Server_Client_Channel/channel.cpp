#include "channel.h"


static char heap_arr[heap_size];
static size_t heap_index = 0;

void* Channel::operator new(size_t size) {
    if (heap_index + size > heap_size) return nullptr;
    void* ptr = &heap_arr[heap_index];
    heap_index += size;
    return ptr;
}
void Channel::operator delete(void* ptr) {}

void* Channel::operator new[](size_t size) {
    if (heap_index + size > heap_size) return nullptr;
    void* ptr = &heap_arr[heap_index];
    heap_index += size;
    return ptr;
}
void Channel::operator delete[](void* ptr) {}


Channel::Channel() {
    this->capacity = DEFAULT_CAPACITY;
    this->count = 0;
    this->read_index = 0;
    this->write_index = 0;
    array = new int[DEFAULT_CAPACITY]; 
}

Channel::Channel(int capacity) {
    this->capacity = capacity;
    this->count = 0;
    this->read_index = 0;
    this->write_index = 0;
    array = new int[capacity];
}

Channel::Channel(int *array, int capacity) {
    this->capacity = capacity;
    this->count = 0;
    this->read_index = 0;
    this->write_index = 0;
    this->array = array;
}

Channel::~Channel() {}

int Channel::increment_index(int index) {
    index++;
    if (index == capacity) index = 0;
    return index;
}

bool Channel::is_empty() { return count == 0; }
bool Channel::is_full() { return count == capacity; }

int Channel::read() {
    if (is_empty()) return 0;
    int data = array[read_index];
    read_index = increment_index(read_index);
    count--;
    return data;
}

bool Channel::write(int value) {
    if (is_full()) return false;
    array[write_index] = value;
    write_index = increment_index(write_index);
    count++;
    return true;
}