#pragma once
#include <string>
#include "Polygon.h"

/// <summary>
/// Main class of program
/// </summary>
class Solution
{
public:
   /// <summary>
   /// Base constructor
   /// </summary>
   Solution() {}

   /// <summary>
   /// Run task for find all axes of symmetry for polygon, that contains in file
   /// </summary>
   /// <param name="fileName">path for text file, that contains polygon</param>
   /// <param name="epsilon">precision for find axes</param>
   void runSolution(std::string fileName, double epsilon);

private:
   /// <summary>
   /// Read polygon from file
   /// </summary>
   /// <param name="fileName">path for text file, that contains polygon</param>
   /// <returns>polygon</returns>
   Polygon readPolygon(std::string fileName);
   
   /// <summary>
   /// Write all found axes of symmetry into console
   /// </summary>
   /// <param name="axes">list axes of symmetry</param>
   void writeAxes(std::vector<Axis>& axes);
};

