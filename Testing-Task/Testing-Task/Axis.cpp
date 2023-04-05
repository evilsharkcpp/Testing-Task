#include "Axis.h"

Axis::Axis(std::vector<Point2> axis)
{
   if (axis.size() == 2)
   {
      start = axis.front();
      end = axis.back();
   }
}
