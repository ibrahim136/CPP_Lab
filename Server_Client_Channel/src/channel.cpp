#include "channel.h"

Channel::Channel()
{
    capacity = default_capacity;
    array = new int[default_capacity];
    read_index = 0;
    write_index = 0;
    count =0;
}

Channel::Channel(int capacity)
{
    this->capacity = capacity;
    array = new int[capacity];
    read_index = 0;
    write_index = 0;
    count =0;
}

Channel::Channel(int *array, int capacity)
{
    this->capacity = capacity;
    this->array = new int[capacity];
    for (int i{0}; i < capacity; i++)
    {
        this->array[i] = array[i];
    }
    read_index = 0;
    write_index = 0;
    count = this->capacity;
}

Channel::~Channel()
{
    delete array;
    array = nullptr;
}

int Channel::increment_index(int index)
{
    return (++index % capacity);
}

bool Channel::is_empty()
{
    return count ==0;
}

bool Channel::is_full()
{
    return count == capacity;
}

std::pair<bool, int> Channel::Read()
{
    if (is_empty()){
        return std::make_pair(false,0);
    }
    int ret = array[read_index];
    read_index = increment_index(read_index);
    count--;
    return std::make_pair(true, ret);
}

bool Channel::write(int value)
{
    if (is_full()){
        return false;
    }
    array[write_index] = value;
    write_index = increment_index(write_index);
    count++;
    return true;
}
