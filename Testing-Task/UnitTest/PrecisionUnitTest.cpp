#include "pch.h"
#include "CppUnitTest.h"
#include <Polygon.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PrecisionUnitTest
{
   static constexpr double epsilon{ 1e-16 };
   static constexpr double multiplier{ 1e-10 };

   static bool compareAxes(std::vector<Axis>& a, std::vector<Axis>& b)
   {
      if (a.size() != b.size())
         return false;
      for (int i{}; i < a.size(); i++)
      {
         bool isEqual{};
         for (int j{}; j < b.size(); j++)
         {
            if (a[i].equals(b[j], epsilon))
               isEqual = true;
         }
         if (!isEqual)
            return false;
      }
      return true;
   }
   

   TEST_CLASS(CompareAxes)
   {
   public:

      TEST_METHOD(SquareAxes)
      {
         std::vector<Axis> axes
         {
            { multiplier * Point2(0,0),   multiplier * Point2(1,1) },
            { multiplier * Point2(1,0),   multiplier * Point2(0,1) },
            { multiplier * Point2(0.5,0), multiplier * Point2(0.5,1) },
            { multiplier * Point2(0,0.5), multiplier * Point2(1,0.5) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               {multiplier * 0,multiplier * 0},
               {multiplier * 1,multiplier * 0},
               {multiplier * 1,multiplier * 1},
               {multiplier * 0,multiplier * 1},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(QuadrangleAxes)
      {
         std::vector<Axis> axes
         {
            { multiplier * Point2(0,0), multiplier * Point2(0,3) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               {multiplier * 0, multiplier * 0},
               {multiplier * 2, multiplier * 1},
               {multiplier * 0, multiplier * 3},
               {multiplier * -2,multiplier * 1},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(NonSymmetryPentagonAxes)
      {
         std::vector<Axis> axes{};
         Polygon poly
         {
            std::vector<Point2>
            {
               { multiplier * 0.1, multiplier * 1.0},
               { multiplier * -1.0, multiplier * 0.0},
               { multiplier * 0.0, multiplier * -1.0},
               { multiplier * 1.0, multiplier * -0.5},
               { multiplier * 2.0, multiplier * 1.0},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(EquilateralTriangleAxes)
      {
         std::vector<Axis> axes
         {
            { multiplier * Point2(0.5,0), multiplier * Point2(0.5,sqrt(3) / 2.0) },
            { multiplier * Point2(0,0), multiplier * Point2(0.75,sqrt(3) / 4.0) },
            { multiplier * Point2(1,0), multiplier * Point2(0.25,sqrt(3) / 4.0) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               { multiplier * 0, multiplier * 0 },
               { multiplier * 1, multiplier * 0 },
               { multiplier * 0.5, multiplier * sqrt(3) / 2.0 },
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(RectangleAxes)
      {
         std::vector<Axis> axes
         {
            { multiplier * Point2(1,0), multiplier * Point2(1,1) },
            { multiplier * Point2(0,0.5), multiplier * Point2(2,0.5) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               {multiplier * 0, multiplier * 0},
               {multiplier * 2, multiplier * 0},
               {multiplier * 2, multiplier * 1},
               {multiplier * 0, multiplier * 1},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(ParallelogramAxes)
      {
         std::vector<Axis> axes{};
         Polygon poly
         {
            std::vector<Point2>
            {
               {multiplier * 0, multiplier * 0},
               {multiplier * 2, multiplier * 0},
               {multiplier * 2.5, multiplier * 1},
               {multiplier * 0.5, multiplier * 1},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(SymmetricHexagonAxes)
      {
         std::vector<Axis> axes
         {
            { multiplier * Point2(-5,0), multiplier * Point2(5,0) },
            { multiplier * Point2(0,-1), multiplier * Point2(0,1) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               {multiplier * -5,multiplier * 0},
               {multiplier * -2,multiplier * -1},
               {multiplier * 2,multiplier * -1},
               {multiplier * 5,multiplier * 0},
               {multiplier * 2,multiplier * 1},
               {multiplier * -2,multiplier * 1},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }
   };
}
