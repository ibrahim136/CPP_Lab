#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include <climits>
#include <iostream>

static constexpr int DEFAULT_CAPACITY = 5;

class Channel {
protected:
    int *array;
    int capacity;
    int count;
    int read_index;
    int write_index;
    int increment_index(int index);
    bool is_empty();
    bool is_full();

public:
    Channel(int capacity = DEFAULT_CAPACITY);
    Channel(const Channel &) = delete;
    virtual ~Channel();
    virtual int read() = 0;
    virtual bool write(int value) = 0;
};

class Channel_RPM : public Channel {
public:
    Channel_RPM(int capacity = DEFAULT_CAPACITY);
    ~Channel_RPM();
    int read() override;
    bool write(int value) override;
};

class Channel_Speed : public Channel {
public:
    Channel_Speed(int capacity = DEFAULT_CAPACITY);
    ~Channel_Speed();
    int read() override;
    bool write(int value) override;
};

class Channel_Temp : public Channel {
public:
    Channel_Temp(int capacity = DEFAULT_CAPACITY);
    ~Channel_Temp();
    int read() override;
    bool write(int value) override;
};

#endif