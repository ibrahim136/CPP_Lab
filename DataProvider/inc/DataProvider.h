#ifndef _Data_Provider_H_
#define _Data_Provider_H_

#include "ICommBus.h"
#include <vector>

class DataProvider
{
private:
    std::vector<ICommBus *> v;

public:
DataProvider();
~DataProvider();
    void register_(ICommBus* BUS);
    void BroadCast(int val);
};

#endif