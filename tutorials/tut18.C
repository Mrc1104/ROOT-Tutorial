// Compiling ROOT scripts and Checking Performance
// When compiling, you need to add header files

// ROOT specific libraries
#include "TStopwatch.h"
#include "TRandom2.h"

// STD Libraries
#include <iostream>
using std::cout;
using std::endl;

void tut18()
{
	// ROOT provided a TStopwatch class
	TStopwatch t; 

	TRandom2 *r = new TRandom2(0);
	
	double x = 0;
	for(int i =0; i < 1e9; i++){
		x += r->Rndm();
	}
	cout << x << endl;

	t.Print(); // prints out how long the code takes to execute
}
