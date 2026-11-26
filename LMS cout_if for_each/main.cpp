#include "LMS.h"
#include "vector"
#include "algorithm"
#include "iostream"


int main()
{
    std::vector<double> readings = {0.1,-0.1,0.6,-0.6,0.7,-0.7,0.75,-0.75,-0.8,0.8};
    LMS obj(0.7);
    int warnings1 = std::count_if(readings.begin(),readings.end(),obj.Rule1Getter());
    std::for_each(readings.begin(),readings.end(),obj.Rule2Getter());
    std::cout << "count_if: " << warnings1 << "\nfor_each: " << obj.warnings_getter();
}