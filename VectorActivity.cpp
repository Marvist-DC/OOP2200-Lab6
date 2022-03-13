/*  Name: Domenic Catalano & Duy Tan Vu
    Date: April 10, 2020
    Program Name: Lab 6 - Vectors
    Program Description: This program will calculate cartesian points using vectors.
*/
 
 #include <iostream>
 #include <vector>	// needed for the use of vector
 #include "MyCartesianPoint.h"	
 #include "MyConsoleInput.h"
 using namespace std;
 using namespace ConsoleInput;
 
 
 int main()
 {
 	// VARIABLE DECLARATIONS
 	vector<CartesianPoint> myPoints;		// Vector
 	CartesianPoint startingPoint(0,0);		// Declare a starting point (0,0)
 	myPoints.push_back(startingPoint);		// Push the starting into the vector
 	
 	// Set minimum and maximum allowable input limit
 	CartesianPoint::SetLimit(10);
 	
 	// Explain the input phase to the user
 	cout << "You will be travelling from (0,0) to (10,10) in as many steps as you like. Enter (10,10) to end.\n";
 	
 	do
 	{
		int pointX, pointY;		// Declare variables to hold X and Y values
		
		// Telling the user where they are and asking where they would like to move to
 		cout << "\nMove from (" << myPoints.back().GetX() << ", " << myPoints.back().GetY() << ")" << " to where?\n";
 		
 		// Storing the input and validating
 		cout << "X: ";
 		pointX = ReadInteger(-(CartesianPoint::GetLimit()),CartesianPoint::GetLimit());
 		
 		cout << "Y: ";
 		pointY = ReadInteger(-(CartesianPoint::GetLimit()),CartesianPoint::GetLimit());
		
		// Adding the input to the vector
 		CartesianPoint newPoint(pointX, pointY);
		myPoints.push_back(newPoint);
	}
	// While (10, 10) is not inputted
	while (myPoints.back().GetX() != 10 && myPoints.back().GetY() != 10);
	
	// DEBUGGING
	cout << "\nDEBUGGING ONLY:\n";
  	for (int i=0; i<(myPoints.size()-1); i++)
    {
        cout << "\nDistance between point " << i+1 << " to " << i+2 << "\n";
        cout << "Distance: " << myPoints[i].GetDistanceTo(myPoints[i+1]);  
    }

	// Display result to the user
    cout << "\n\nThe total distance between " << myPoints.size() << " points is " << CartesianPoint::TotalDistance(myPoints) << endl;
	return 0;
 }

