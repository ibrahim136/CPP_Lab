#ifndef _LMS_H
#define _LMS_H

#include "functional"

class LMS
{
private:
    std::function<bool(double)> detection_rule1;
    std::function<void(double)> detection_rule2;
    double threshold;
    int warnings;
public:
    LMS(double threshold);
    std::function<bool(double)> Rule1Getter();
    std::function<void(double)> Rule2Getter();
    int warnings_getter();
};

#endif