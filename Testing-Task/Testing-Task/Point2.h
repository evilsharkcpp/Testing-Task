#pragma once
#include <string>

class Point2
{
public:

   double x, y;
   /// <summary>
   /// Base constructor
   /// </summary>
   Point2() : x(0), y(0) {}
   
   /// <summary>
   /// Initializer constructor
   /// </summary>
   /// <param name="x">x-coordinate</param>
   /// <param name="y">y-coordinate</param>
   Point2(double x, double y) : x(x), y(y) {}

   /// <summary>
   /// Copy constructor
   /// </summary>
   /// <param name="p">copied point</param>
   Point2(const Point2& p) : x(p.x), y(p.y) {}

   //Assignment Operations

   Point2& operator=(const Point2& p);
   Point2& operator+=(const Point2& p);
   Point2& operator-=(const Point2& p);
   Point2& operator/=(double a);

   //Math operations

   friend Point2 operator+(const Point2& p1, const Point2& p2);
   friend Point2 operator-(const Point2& p1, const Point2& p2);
   friend Point2 operator*(const Point2& p, double a);
   friend Point2 operator*(double a, const Point2& p);
   friend Point2 operator/(const Point2& p, double a);
   friend Point2 operator/(double a, const Point2& p);

   /// <summary>
   /// Rotate point by angle
   /// </summary>
   /// <param name="angle">rotate angle in radians</param>
   /// <returns></returns>
   Point2 rotate(double angle);

   /// <summary>
   /// Rotate point by angle around specific axis and center
   /// </summary>
   /// <param name="angle">rotate angle in radians</param>
   /// <param name="axis">rotate axis</param>
   /// <param name="center">center point</param>
   /// <returns>rotated point</returns>
   Point2 rotate(double angle, Point2& axis, Point2 center = { 0, 0 });

   /// <summary>
   /// Symmetry point around axis and center
   /// </summary>
   /// <param name="axis"rotate axis></param>
   /// <param name="center">center point</param>
   /// <returns>symmetried point</returns>
   Point2 symmetry(Point2& axis, Point2 center);

   /// <summary>
   /// Normalize point
   /// </summary>
   void normalize();

   /// <summary>
   /// Compute norm for point
   /// </summary>
   /// <returns>norm</returns>
   double getNorm();
   
   /// <summary>
   /// Equal two points
   /// </summary>
   /// <param name="p">second point</param>
   /// <param name="epsilon">precision for accept equal</param>
   /// <returns>true if equal, else false</returns>
   bool equals(Point2& p, double epsilon);

   /// <summary>
   /// Convert point to string
   /// </summary>
   /// <returns>converted point in string</returns>
   std::string toString() const;
   void symmetry();

private:

   /// <summary>
   /// Equal two double values
   /// </summary>
   /// <param name="a">first double value</param>
   /// <param name="b">second double value</param>
   /// <param name="epsilon">precision for accept equal</param>
   /// <returns>true if equal, else false</returns>
   bool equalValues(double a, double b, double epsilon);
};