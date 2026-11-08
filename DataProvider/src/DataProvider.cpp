#include "../inc/DataProvider.h"

DataProvider::DataProvider() = default;
DataProvider::~DataProvider() = default;
void DataProvider::register_(ICommBus *BUS)
{
    v.emplace_back(BUS);
}
void DataProvider::BroadCast(int val)
{
    for (ICommBus* x : v)
    {
        x->send(val);
    }
}