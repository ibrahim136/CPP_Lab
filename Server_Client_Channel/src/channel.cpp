#include "channel.h"

Channel::Channel(int capacity) {
    this->capacity = capacity;
    read_index = 0;
    write_index = 0;
    count = 0;
    array = new int[capacity];
}

Channel::~Channel() {
    delete[] array;
}

int Channel::increment_index(int index) {
    return (index + 1) % capacity;
}

bool Channel::is_empty() { return count == 0; }
bool Channel::is_full() { return count == capacity; }

Channel_RPM::Channel_RPM(int capacity) : Channel(capacity) {}
Channel_RPM::~Channel_RPM() {}

int Channel_RPM::read() {
    if (is_empty()) return INT_MIN;
    int ret = array[read_index];
    read_index = increment_index(read_index);
    count--;
    std::cout << "[RPM Channel] Read value: " << ret << "\n";
    return ret;
}

bool Channel_RPM::write(int value) {
    if (is_full()) return false;
    array[write_index] = value;
    write_index = increment_index(write_index);
    count++;
    std::cout << "[RPM Channel] Wrote value: " << value << "\n";
    return true;
}

Channel_Speed::Channel_Speed(int capacity) : Channel(capacity) {}
Channel_Speed::~Channel_Speed() {}

int Channel_Speed::read() {
    if (is_empty()) return INT_MIN;
    int ret = array[read_index];
    read_index = increment_index(read_index);
    count--;
    std::cout << "[Speed Channel] Read value: " << ret << "\n";
    return ret;
}

bool Channel_Speed::write(int value) {
    if (is_full()) return false;
    array[write_index] = value;
    write_index = increment_index(write_index);
    count++;
    std::cout << "[Speed Channel] Wrote value: " << value << "\n";
    return true;
}

Channel_Temp::Channel_Temp(int capacity) : Channel(capacity) {}
Channel_Temp::~Channel_Temp() {}

int Channel_Temp::read() {
    if (is_empty()) return INT_MIN;
    int ret = array[read_index];
    read_index = increment_index(read_index);
    count--;
    std::cout << "[Temp Channel] Read value: " << ret << "\n";
    return ret;
}

bool Channel_Temp::write(int value) {
    if (is_full()) return false;
    array[write_index] = value;
    write_index = increment_index(write_index);
    count++;
    std::cout << "[Temp Channel] Wrote value: " << value << "\n";
    return true;
}