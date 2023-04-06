#include "pch.h"
#include "CppUnitTest.h"
#include <Polygon.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
   constexpr double epsilon{ 1e-10 };
   static bool compareAxes(std::vector<Axis>& a, std::vector<Axis>& b)
   {
      if (a.size() != b.size())
         return false;
      for (int i{}; i < a.size(); i++)
      {
         bool isEqual{};
         for (int j{}; j < b.size(); j++)
         {
            if (a[i].equals(b[j],epsilon))
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
            { Point2(0,0), Point2(1,1) },
            { Point2(1,0), Point2(0,1) },
            { Point2(0.5,0), Point2(0.5,1) },
            { Point2(0,0.5), Point2(1,0.5) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               {0,0},
               {1,0},
               {1,1},
               {0,1},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(QuadrangleAxes)
      {
         std::vector<Axis> axes
         {
            { Point2(0,0), Point2(0,3) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               {0,0},
               {2,1},
               {0,3},
               {-2,1},
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
               {0.1,1.0},
               {-1.0,0.0},
               {0.0,-1.0},
               {1.0,-0.5},
               {2.0, 1.0},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(EquilateralTriangleAxes)
      {
         std::vector<Axis> axes
         {
            { Point2(0.5,0), Point2(0.5,sqrt(3)/2.0) },
            { Point2(0,0), Point2(0.75,sqrt(3) / 4.0) },
            { Point2(1,0), Point2(0.25,sqrt(3) / 4.0) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               { 0, 0 },
               { 1, 0 },
               { 0.5, sqrt(3) / 2.0 },
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(RectangleAxes)
      {
         std::vector<Axis> axes
         {
            { Point2(1,0), Point2(1,1) },
            { Point2(0,0.5), Point2(2,0.5) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               {0,0},
               {2,0},
               {2,1},
               {0,1},
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
               {0,0},
               {2,0},
               {2.5,1},
               {0.5,1},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }

      TEST_METHOD(SymmetricHexagonAxes)
      {
         std::vector<Axis> axes
         {
            { Point2(-5,0), Point2(5,0) },
            { Point2(0,-1), Point2(0,1) },
         };
         Polygon poly
         {
            std::vector<Point2>
            {
               {-5,0},
               {-2,-1},
               {2,-1},
               {5,0},
               {2,1},
               {-2,1},
            }
         };
         Assert::IsTrue(compareAxes(axes, poly.findAxesOfSymmetry(epsilon)));
      }
   };
}
