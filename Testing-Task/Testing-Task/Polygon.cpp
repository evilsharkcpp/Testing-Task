#include "Polygon.h"
#include <algorithm>

std::vector<Axis> Polygon::getCandidates(double epsilon)
{
   std::vector<Point2> nodes(_nodes);
   auto size{ nodes.size() };
   for (int i{}; i < size - 1; i++)
      nodes.push_back((nodes[i] + nodes[i + 1]) / 2.0);
   nodes.push_back((nodes[0] + nodes[size - 1]) / 2.0);

   std::vector<Axis> candidates{};
   auto center{ this->getCenter() };
   for (int i{}; i < nodes.size() - 1; i++)
      for (int j{ i + 1 }; j < nodes.size(); j++)
      {
         auto dx{ (center.x - nodes[i].x) }, dy{ (center.y - nodes[i].y) },
            tx{ (nodes[j].x - nodes[i].x) }, ty{ (nodes[j].y - nodes[i].y) };
         if (abs(atan2(dy, dx) - atan2(ty, tx)) < epsilon)
            candidates.push_back(Axis(nodes[i], nodes[j]));
      }
   return candidates;
}

std::vector<Axis> Polygon::findAxesOfSymmetry(double epsilon)
{
   auto candidates{ getCandidates(epsilon) };
   auto center{ getCenter() };
   std::vector<Axis> result{};

   for (const auto& candidate : candidates)
   {
      auto direction{ candidate.end - candidate.start };
      direction.normalize();
      auto rotated{ this->getRotated(acos(1), direction, center) };
      auto mirrored{ this->getSymmetry(direction, center) };
      if (rotated.equals(mirrored, epsilon))
         result.push_back(candidate);
   }
   return result;
}

Point2 Polygon::getCenter()
{
   Point2 center{};
   for (const auto& node : _nodes)
      center += node;
   center /= (double)_nodes.size();
   return center;
}

void Polygon::rotate(double angle)
{
   for (auto& node : _nodes)
      node = node.rotate(angle);
}

void Polygon::rotate(double angle, Point2& axis, Point2 center)
{
   for (auto& node : _nodes)
      node = node.rotate(angle, axis, center);
}

Polygon Polygon::getRotated(double angle)
{
   auto poly{ *this };
   poly.rotate(angle);
   return poly;
}

Polygon Polygon::getRotated(double angle, Point2& axis, Point2 center)
{
   auto poly{ *this };
   poly.rotate(angle, axis, center);
   return poly;
}

bool Polygon::equals(const Polygon& p, double epsilon)
{
   if (p._nodes.size() != _nodes.size())
      return false;

   std::vector<Point2> nodes1(_nodes);
   std::vector<Point2> nodes2(p._nodes);

   bool isFound{};
   for (int i{}; i < nodes1.size(); i++)
   {
      isFound = false;
      for (int j{}; j < nodes2.size(); j++)
      {
         if (nodes1[i].equals(nodes2[j], epsilon))
            isFound = true;
      }
      if (!isFound)
         return isFound;
   }
   return true;
}

Polygon Polygon::getSymmetry(Point2& axis, Point2 center)
{
   auto poly{ *this };
   for (auto& node : poly._nodes)
      node = node.symmetry(axis, center);
   return poly;
}