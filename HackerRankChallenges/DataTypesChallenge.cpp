/*
	Hackerrank::Challenges::CppDataTypes
	https://www.hackerrank.com/challenges/c-tutorial-basic-data-types
*/

#include "Challenges.h"


#include <cstdio>

#include<bits/stdc++.h>
using std::cout;
using std::cin;

/*
	Use fixed floating-point notation
	Sets the floatfield format flag for the str stream to fixed.

	When floatfield is set to fixed, floating-point values are written using fixed-point notation: 
	the value is represented with exactly as many digits in the decimal part as specified 
	by the precision field (precision) and with no exponent part.

	This manipulator is declared in header <iostram>.
*/
using std::scientific;

using std::fixed;											// 
/*
	Sets the decimal precision to be used to format floating-point values on output operations.
	Behaves as if member precision were called with n as argument on the stream on 
	which it is inserted/extracted as a manipulator (it can be inserted/extracted on input streams or output streams).

	This manipulator is declared in header <iomanip>.
*/
using std::setprecision;

/*
	The class ios_base is a multipurpose class that serves as the base class for all I/O stream classes. It maintains several kinds of data:

	1) state information: stream status flags
	2) control information: flags that control formatting of both input and output sequences and the imbued locale
	3) private storage: indexed extensible data structure that allows both long and void* members, which may be implemented as two arbitrary-length arrays or a single array of two-element structs or another container.
	4) callbacks: arbitrary number of user-defined functions to be called from imbue(), copyfmt(), and ~ios_base()

	https://en.cppreference.com/w/cpp/io/ios_base
*/
using std::ios_base;

int PrecisionExample();
int FixedExplanation();


int DataTypesChallenge() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a; long b; char c; float d; double e;
	cin >> a >> b >> c >> d >> e;
	cout << a << "\n" << b << "\n" << c << "\n";
	cout << fixed << setprecision(3) << d << "\n";
	cout << fixed << setprecision(9) << e << "\n";

	//PrecisionExample();
	//FixedExplanation();
	return 0;
}




int PrecisionExample() {

	double f = 3.14159;
	cout << setprecision(5) << f << '\n';  // prints 3.1416 and not 3.141459 why 
	cout << setprecision(9) << f << '\n';
	cout << fixed;
	cout << setprecision(5) << f << '\n';
	cout << setprecision(9) << f << '\n';
	return 0;
}

/*
	Why we need fixed with setprecision?!
*/

/*
	This is because "when floatfield is set to a fixed value, floating point values are written using fixed point notation:
	the value is represented with exactly as many decimal digits as specified by the precision field, and no exponential part."
	http://www.cplusplus.com/reference/ios/fixed/?kw=fixed
*/

int FixedExplanation() {
	
	double a = 3.1415926534;
	double b = 2006.0;
	double c = 1.0e-10;

	cout.precision(5);

	cout << "default:\n";
	cout << a << '\n' << b << '\n' << c << '\n';

	cout << '\n';

	cout << "fixed:\n" << fixed;
	cout << a << '\n' << b << '\n' << c << '\n';

	cout << '\n';
	cout << "scientific:\n" << scientific;
	cout << a << '\n' << b << '\n' << c << '\n';
		
/*
	Output:
	
	default:
	3.1416
	2006
	1e-010

	fixed:
	3.14159
	2006.00000
	0.00000

	scientific:
	3.14159e+000
	2.00600e+003
	1.00000e-010

*/
	return 0;
	
}


