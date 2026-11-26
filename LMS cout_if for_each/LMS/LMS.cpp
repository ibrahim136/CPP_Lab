#include "LMS.h"
#include "math.h"
LMS::LMS(double threshold) : threshold(threshold) , warnings{0}
{
    detection_rule1 = [threshold](double input)
    { return abs(input) > threshold; };
    detection_rule2 = [threshold,this](double input)
    { if (abs(input) > threshold) this->warnings++; };
}
std::function<bool(double)> LMS::Rule1Getter()
{
    return detection_rule1;
}
std::function<void(double)> LMS::Rule2Getter()
{
    return detection_rule2;
}
int LMS::warnings_getter()
{
    return warnings;
}