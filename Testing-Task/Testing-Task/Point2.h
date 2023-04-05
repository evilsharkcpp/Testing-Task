#pragma once

class Point2
{
public:
   double x, y;
   Point2() : x(0), y(0) {}
   Point2(double x, double y) : x(x), y(y) {}
   Point2(const Point2& p) : x(p.x), y(p.y) {}

   Point2& operator=(const Point2& p);
   Point2& operator+=(const Point2& p);
   Point2& operator-=(const Point2& p);
   Point2& operator/=(double a);

   friend Point2 operator+(const Point2& p1, const Point2& p2);
   friend Point2 operator-(const Point2& p1, const Point2& p2);
   friend Point2 operator*(const Point2& p, double a);
   friend Point2 operator*(double a, const Point2& p);
   friend Point2 operator/(const Point2& p, double a);
   friend Point2 operator/(double a, const Point2& p);
   friend bool operator>(Point2& p1, Point2& p2);
   friend bool operator<(Point2& p1, Point2& p2);

   Point2 rotate(double angle);
   Point2 rotate(double angle, Point2& axis, Point2 center = {0, 0});
   Point2 symmetry();
   void normalize();
   bool equals(Point2& p);
};