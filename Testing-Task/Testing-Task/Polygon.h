#pragma once
#include "Point2.h"
#include "Axis.h"
#include<vector>
#include <string>

/// <summary>
/// It is a representation of a polygon consisting of a list of nodes
/// </summary>
class Polygon
{
public:
   /// <summary>
   /// Copy constructor
   /// </summary>
   /// <param name="nodes">list of nodes</param>
   Polygon(const std::vector<Point2>& nodes) : _nodes(std::vector<Point2>(nodes)) {}

   /// <summary>
   /// Initializer constructor
   /// </summary>
   /// <param name="nodes">list of nodes</param>
   Polygon(std::vector<Point2>&& nodes) : _nodes(std::vector<Point2>(nodes)) {}

   /// <summary>
   /// Compute center of polygon
   /// </summary>
   /// <returns>center as point</returns>
   Point2 getCenter();

   /// <summary>
   /// Rotate polygon by angle
   /// </summary>
   /// <param name="angle">rotate angle in radians</param>
   void rotate(double angle);

   /// <summary>
   /// Rotate polygon by angle around specific axis and center
   /// </summary>
   /// <param name="angle">rotate angle in radians</param>
   /// <param name="axis">direction axis</param>
   /// <param name="center">center of polygon for rotate</param>
   void rotate(double angle, Point2& axis, Point2 center = { 0, 0 });

   /// <summary>
   /// Rotate polygon by angle
   /// </summary>
   /// <param name="angle">rotate angle in radians</param>
   /// <returns>rotated polygon</returns>
   Polygon getRotated(double angle);

   /// <summary>
   /// Rotate polygon by angle around specific axis and center
   /// </summary>
   /// <param name="angle">rotate angle in radians</param>
   /// <param name="axis">direction axis</param>
   /// <param name="center">center of polygon for rotate</param>
   /// <returns>rotated polygon</returns>
   Polygon getRotated(double angle, Point2& axis, Point2 center = { 0, 0 });

   /// <summary>
   /// Equal two polygons
   /// </summary>
   /// <param name="p">second polygon</param>
   /// <param name="epsilon">precision for accept equal</param>
   /// <returns>true if equal, else false</returns>
   bool equals(const Polygon& p, double epsilon);

   /// <summary>
   /// Symmetry polygon around specific axis and center
   /// </summary>
   /// <param name="axis">direction axis</param>
   /// <param name="center">center of polygon for rotate</param>
   /// <returns>symmetried polygon</returns>
   Polygon getSymmetry(Point2& axis, Point2 center);

   /// <summary>
   /// Find all axes of symmetry for this polygon
   /// </summary>
   /// <param name="epsilon">precision for accept equal</param>
   /// <returns>list of axes of symmetry</returns>
   std::vector<Axis> findAxesOfSymmetry(double epsilon);

private:
   std::vector<Point2> _nodes;
   /// <summary>
   /// Find all candidates for axes of symmetry
   /// </summary>
   /// <param name="epsilon">precision for accept candidate</param>
   /// <returns>list of candidates</returns>
   std::vector<Axis> getCandidates(double epsilon);
};