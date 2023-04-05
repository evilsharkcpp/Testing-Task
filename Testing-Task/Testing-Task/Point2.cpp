#include "Point2.h"
#include <math.h>
#include <limits>

Point2 operator+(const Point2& p1, const Point2& p2)
{
   return Point2(p1.x + p2.x, p1.y + p2.y);
}

Point2 operator-(const Point2& p1, const Point2& p2)
{
   return Point2(p1.x - p2.x, p1.y - p2.y);
}

Point2 operator*(const Point2& p, double a)
{
   return Point2(a * p.x, a * p.y);
}

Point2 operator*(double a, const Point2& p)
{
   return Point2(a * p.x, a * p.y);
}

Point2 operator/(const Point2& p, double a)
{
   return Point2(p.x / a, p.y / a);
}

Point2 operator/(double a, const Point2& p)
{
   return Point2(a / p.x, a / p.y);
}

bool operator>(Point2& p1, Point2& p2)
{
   return p1.x - p2.x >= 0 && p1.y - p2.y >= 0;
}

bool operator<(Point2& p1, Point2& p2)
{
   return p2.x - p1.x >= 0 && p2.y - p1.y >= 0;
}

Point2& Point2::operator=(const Point2& p)
{
   x = p.x;
   y = p.y;
   return *this;
}

Point2& Point2::operator+=(const Point2& p)
{
   x += p.x;
   y += p.y;
   return *this;
}

Point2& Point2::operator-=(const Point2& p)
{
   x -= p.x;
   y -= p.y;
   return *this;
}

Point2& Point2::operator/=(double a)
{
   x /= a;
   y /= a;
   return *this;
}

Point2 Point2::rotate(double angle)
{
   double x{ this->x * cos(angle) + this->y * sin(angle) },
      y{ this->x * -sin(angle) + this->y * cos(angle) };
   return Point2(x, y);
}

Point2 Point2::rotate(double angle, Point2& axis, Point2 center)
{
   double nx{ (x - center.x) * (cos(angle) + (1 - cos(angle)) * pow(axis.x,2)) + (y - center.y) * ((1 - cos(angle)) * axis.x * axis.y) },
      ny{ (x - center.x) * ((1 - cos(angle)) * axis.x * axis.y) + (y - center.y) * (cos(angle) + (1 - cos(angle)) * pow(axis.y,2)) };
   return Point2(nx, ny);
}

Point2 Point2::symmetry()
{
   return Point2(-x, -y);
}

void Point2::normalize()
{
   auto norm{ sqrt(x * x + y * y) };
   x /= norm;
   y /= norm;
}

bool Point2::equals(Point2& p)
{
   return pow(x - p.x, 2) + pow(y - p.y, 2) < std::numeric_limits<double>::epsilon();
}
