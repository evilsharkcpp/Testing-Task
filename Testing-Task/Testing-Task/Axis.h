#pragma once
#include "Point2.h"
#include <vector>
#include <string>

class Axis
{
public:
   Point2 start, end;
   Axis() : start({}), end({}) {}
   Axis(Point2& a, Point2& b) : start(a), end(b) {}
   Axis(std::vector<Point2> axis);
   std::string toString();
private:
};