#pragma once
#include "Point2.h"
#include <vector>
#include <string>

/// <summary>
/// Axis that consists of start and end points
/// </summary>
class Axis
{
public:
   Point2 start, end;
   /// <summary>
   /// Base constructor
   /// </summary>
   Axis() : start({}), end({}) {}

   /// <summary>
   /// Initializer constructor
   /// </summary>
   /// <param name="a">start point</param>
   /// <param name="b">end point</param>
   Axis(Point2& a, Point2& b) : start(a), end(b) {}

   /// <summary>
   /// Convert axis to string
   /// </summary>
   /// <returns>converted axes in string</returns>
   std::string toString() const;

   /// <summary>
   /// Equal two axis
   /// </summary>
   /// <param name="axis">second axis</param>
   /// <param name="epsilon">precision for accept</param>
   /// <returns>true if equal, else false</returns>
   bool equals(Axis& axis, double epsilon);
private:
};