#pragma once
#include "Point2.h"
#include "Axis.h"
#include<vector>
#include <string>


class Polygon
{
public:
   Polygon() : _nodes({}) {}
   Polygon(const std::vector<Point2>& nodes) : _nodes(std::vector<Point2>(nodes)) {}
   Polygon(std::vector<Point2>&& nodes) : _nodes(std::vector<Point2>(nodes)) {}

   Point2 getCenter();
   void centering();
   void rotate(double angle);
   void rotate(double angle, Point2& axis, Point2 center = { 0, 0 });
   Polygon getRotated(double angle);
   Polygon getRotated(double angle, Point2& axis, Point2 center = { 0, 0 });
   bool equals(const Polygon& p);

   std::vector<Axis> findAxes();
private:
   std::vector<Point2> _nodes;
};