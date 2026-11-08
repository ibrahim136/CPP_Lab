#ifndef _CHANNEL_H_
#define _CHANNEL_H_
static constexpr int DEFAULT_CAPACITY = 5;

#include <climits>

class Channel
{
private:
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
    Channel(const Channel &) = delete;
    virtual ~Channel();
    virtual int read() =0;
    virtual bool write(int value)=0;
};

class Channel_RPM : public Channel
{
private:
    int *array;

public:
    Channel_RPM();
    Channel_RPM(int capacity);
    Channel_RPM(int* array, int capacity);
    int read();
    bool write(int value);
};

#endif