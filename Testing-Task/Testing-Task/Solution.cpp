#include "Solution.h"
#include <fstream>
#include <iostream>

void Solution::runSolution(std::string fileName, double epsilon)
{
   try
   {
      auto poly{ readPolygon(fileName) };
      auto result{ poly.findAxesOfSymmetry(epsilon) };
      std::cout << "Output:\n" << std::endl;
      if (result.size() == 0)
         std::cout << "non-symmetric" << std::endl;
      else
         writeAxes(result);
   }
   catch (std::exception& ex)
   {
      throw ex;
   }

}

Polygon Solution::readPolygon(std::string fileName)
{
   std::ifstream in(fileName);
   if (!in.is_open())
      throw std::exception("File not found");

   std::vector<Point2> nodes{};
   while (!in.eof())
   {
      double x{}, y{};
      in >> x >> y;
      nodes.push_back(Point2(x, y));
   }
   in.close();

   return Polygon(move(nodes));
}

void Solution::writeAxes(std::vector<Axis>& axes)
{
   for (const auto& axis : axes)
      std::cout << axis.toString() << std::endl;
}
