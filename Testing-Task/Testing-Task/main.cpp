#include <vector>
#include "Point2.h"
#include "Polygon.h"

using namespace std;

int main(int argc, char* argv[])
{
  vector<Point2> nodes
  {
     Point2(0,0),
     Point2(1e-16,0),
     Point2(1e-16,1e-16),
     Point2(0,1e-16),
  };
  Polygon pol(nodes);
  auto res = pol.findAxes();
}