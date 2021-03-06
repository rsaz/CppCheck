// App.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CppCheck.h" // Just add the CppCheck.h "header file"

using namespace std;
using namespace cck; // Add the namespace

int main()
{
	// Examples of how to use CppCheck Classes

	//Using CppCheck Class 
	CppCheck cc;
	cc.Start(); // Start recording time

	//Using CppCheck1 Static Class
	auto const start = CppCheck1::Start(); // Start recording time

	//Using CppCheck2 Class
	CppCheck2 cc2;
	cc2.Start(); // Start recording time

	// Portion of c++ code to analyze
	for (int i{}; i < 100; ++i)
	{
		cout << i << " ";
	}

	cout << endl;
	// End of code to be analyzed

	cc.Stop(); // End recording time for CppCheck
	cc2.Stop(); // End recording time for CppCheck2

	cout << CppCheck1::Elapsed(start) << endl; // End recording time for CppCheck1 and printing out the result
	cout << cc.Elapsed() << endl; // End recording time for CppCheck and printing out the result
	cout << cc2.ElapsedMilliseconds() << endl; // End recording time for CppCheck2 and printing out the result	

	cin.get();
	
	return 0;
}

