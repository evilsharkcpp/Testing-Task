#include "Polygon.h"
#include <algorithm>

std::vector<Axis> Polygon::findAxes()
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
         if (abs(atan2(dy, dx) - atan2(ty, tx)) < std::numeric_limits<double>::epsilon())
            candidates.push_back(Axis(nodes[i], nodes[j]));
      }

   /*if (abs((center.y - nodes[i].y) * (nodes[j].x - nodes[i].x) -
      (center.x - nodes[i].x) * (nodes[j].y - nodes[i].y)) < std::numeric_limits<double>::epsilon())*/
      //candidates.push_back(Axis(nodes[i], nodes[j]));

   std::vector<Axis> result{};

   for (const auto& candidate : candidates)
   {
      auto direction{ candidate.end - candidate.start };
      direction.normalize();
      auto rotated{ this->getRotated(acos(1), direction, center) };
      auto mirrored{ this->getRotated(acos(-1), direction, center) };
      if (rotated.equals(mirrored))
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

void Polygon::centering()
{
   auto center{ getCenter() };
   for (auto& node : _nodes)
      node -= center;
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

bool Polygon::equals(const Polygon& p)
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
         if (nodes1[i].equals(nodes2[j]))
            isFound = true;
      }
      if (!isFound)
         return isFound;
   }
   return true;
}
