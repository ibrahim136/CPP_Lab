#include "channel.h"

// ==========================================
// 1. الدوال الأساسية لكلاس Channel اللي كانت ناقصة
// ==========================================
Channel::Channel() {
    this->capacity = DEFAULT_CAPACITY;
    this->count = 0;
    this->read_index = 0;
    this->write_index = 0;
    array = new ChannelData[DEFAULT_CAPACITY];
}

Channel::Channel(int capacity) {
    this->capacity = capacity;
    this->count = 0;
    this->read_index = 0;
    this->write_index = 0;
    array = new ChannelData[capacity];
}

Channel::Channel(ChannelData *array, int capacity) {
    this->capacity = capacity;
    this->count = 0;
    this->read_index = 0;
    this->write_index = 0;
    this->array = array;
}

Channel::~Channel() {
    // Custom Heap لا يحتاج إلى delete[] هنا
}

int Channel::increment_index(int index) {
    index++;
    if (index == capacity) {
        index = 0;
    }
    return index;
}

bool Channel::is_empty() {
    return count == 0;
}

bool Channel::is_full() {
    return count == capacity;
}

static char heap_arr[heap_size];
static size_t heap_index = 0;

void* Channel::operator new[](size_t size) {
    if (heap_index + size > heap_size) {
        return nullptr; 
    }
    void* ptr = &heap_arr[heap_index];
    heap_index += size;
    return ptr;
}

void Channel::operator delete[](void* ptr) {
    // Custom delete
}

// ==========================================
// 2. دوال الـ Buffer
// ==========================================
ChannelData Channel::read_buffer() {
    if (is_empty()) return 0;
    ChannelData data = array[read_index];
    read_index = increment_index(read_index);
    count--;
    return data;
}

bool Channel::write_buffer(ChannelData value) {
    if (is_full()) return false;
    array[write_index] = value;
    write_index = increment_index(write_index);
    count++;
    return true;
}

ChannelData SpeedChannel::read() {
    return read_buffer();
}
bool SpeedChannel::write(ChannelData value) {
    return write_buffer(value);
}

ChannelData RPMChannel::read() {
    return read_buffer();
}
bool RPMChannel::write(ChannelData value) {
    return write_buffer(value);
}

ChannelData TempChannel::read() {
    return read_buffer();
}
bool TempChannel::write(ChannelData value) {
    return write_buffer(value);
}