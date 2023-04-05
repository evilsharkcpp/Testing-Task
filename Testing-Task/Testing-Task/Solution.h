#pragma once
#include <string>
#include "Polygon.h"

class Solution
{
public:
   Solution() {}
   void runSolution();

private:
   Polygon readPolygon(std::string fileName);
   void writeAxes(std::vector<Axis>& axes);
};

