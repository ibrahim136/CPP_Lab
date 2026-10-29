#ifndef _CHANNEL_H_
#define _CHANNEL_H_
#define default_capacity 10

#include <utility>

class Channel
{
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
    Channel ();
    Channel(int capacity);
    Channel(int * array,int capacity);
    ~Channel();
    std::pair<bool,int> Read();
    bool write(int value);
};



#endif