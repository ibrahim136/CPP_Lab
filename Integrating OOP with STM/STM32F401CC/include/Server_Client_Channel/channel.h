#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include "STD_types.h"
#include <climits>
#include <variant>

using ChannelData = std::variant<int, float, double>;

static constexpr size_t DEFAULT_CAPACITY = 5;
static constexpr size_t heap_size = 2048;

class Channel {
protected:
    ChannelData *array; 
    int capacity;
    int count;
    int read_index;
    int write_index;
    int increment_index(int index);
    bool is_empty();
    bool is_full();
    

    ChannelData read_buffer(); 
    bool write_buffer(ChannelData value);

public:
    Channel();
    Channel(int capacity);
    Channel(ChannelData *array, int capacity);
    Channel(const Channel&) = delete;
    virtual ~Channel(); 
    
    void* operator new[](size_t);
    void operator delete[](void* ptr);
    

    virtual ChannelData read() = 0; 
    virtual bool write(ChannelData value) = 0;
};


class SpeedChannel : public Channel {
public:
    SpeedChannel() : Channel() {}
    ChannelData read() override;
    bool write(ChannelData value) override;
};

class RPMChannel : public Channel {
public:
    RPMChannel() : Channel() {}
    ChannelData read() override;
    bool write(ChannelData value) override;
};

class TempChannel : public Channel {
public:
    TempChannel() : Channel() {}
    ChannelData read() override;
    bool write(ChannelData value) override;
};

#endif