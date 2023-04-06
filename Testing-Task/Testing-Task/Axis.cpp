#include "Axis.h"

std::string Axis::toString() const
{
   return start.toString() + " - " + end.toString();
}

bool Axis::equals(Axis& axis, double epsilon)
{
   return start.equals(axis.start, epsilon) && end.equals(axis.end, epsilon) ||
      start.equals(axis.end, epsilon) && end.equals(axis.start, epsilon);
}
