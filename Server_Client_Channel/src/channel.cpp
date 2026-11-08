#include "channel.h"

Channel::Channel()
{
    capacity = DEFAULT_CAPACITY;
    read_index = 0;
    write_index = 0;
    count =0;
}

Channel::Channel(int capacity)
{
    this->capacity = capacity;
    read_index = 0;
    write_index = 0;
    count =0;
}

Channel::~Channel(){}

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

Channel_RPM::Channel_RPM() : array{new int [capacity]}{}

Channel_RPM::Channel_RPM(int capacity) : Channel(capacity) array{new int [capacity]}{}


Channel_RPM::Channel_RPM(int* array,int capacity) : Channel(capacity) array{array}{}

int Channel_RPM::read()
{
    if (is_empty()){
        return INT_MIN;
    }
    int ret = array[read_index];
    read_index = increment_index(read_index);
    count--;
    return ret;
}

bool 