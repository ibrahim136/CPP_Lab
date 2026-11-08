#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "STD_types.h"
#include <climits>

static constexpr size_t DEFAULT_CAPACITY = 5;
static constexpr size_t heap_size = 2048;

class Channel {
private:
    int *array; 
    int capacity;
    int count;
    int read_index;
    int write_index;
    int increment_index(int index);
    bool is_empty();
    bool is_full();

public:
    Channel();
    Channel(int capacity);
    Channel(int *array, int capacity);
    ~Channel(); 
    
    void* operator new(size_t size);
    void operator delete(void* ptr);
    void* operator new[](size_t size);
    void operator delete[](void* ptr);
    

    int read(); 
    bool write(int value);
};

#endif