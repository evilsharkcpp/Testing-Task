#include <vector>
#include "Point2.h"
#include "Polygon.h"
#include <iostream>
#include "Solution.h"

using namespace std;

int main(int argc, char* argv[])
{
   try
   {
      if (argc < 2)
         throw exception("run program with filename as parameter");
      string filename{ argv[1] };
      Solution soln{};
      soln.runSolution(filename, 1e-16);
   }
   catch (exception& ex)
   {
      cerr << ex.what() << endl;
   }
}