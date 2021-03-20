/*
Hackerrank::Challenges::Day18:QueuesAndStacks
description:https://www.hackerrank.com/challenges/prettyprint/
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"
#include <iostream>
#include <iomanip>

int prettyPrintChallenge() {
	using std::cin, std::cout, std::endl;
	using std::setiosflags;
	using std::ios;
	using std::setw, std::setfill;
	using std::hex, std::dec;
	using std::left, std::right, std::internal;
	using std::showbase, std::showpos, std::noshowpos;
	using std::nouppercase, std::uppercase;
	using std::fixed, std::scientific;
	using std::setprecision;
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		// LINE 1
		cout << hex << left << showbase << nouppercase; // formatting
		cout << (long long)A << endl; // actual printed part
		// LINE 2
		cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2); // formatting
		cout << B << endl; // actual printed part
		// LINE 3
		cout << scientific << uppercase << noshowpos << setprecision(9); // formatting
		cout << C << endl; // actual printed part
	}
	return 0;
}

/*
std::manipulators http://www.cplusplus.com/reference/library/manipulators/

Independent flags (switch on):

boolalpha		Alphanumerical bool values (function )
showbase		Show numerical base prefixes (function )
showpoint		Show decimal point (function )
showpos			Show positive signs (function )
skipws			Skip whitespaces (function )
unitbuf			Flush buffer after insertions (function )
uppercase		Generate upper-case letters (function )

Independent flags (switch off):

noboolalpha		No alphanumerical bool values (function )
noshowbase		Do not show numerical base prefixes (function )
noshowpoint		Do not show decimal point (function )
noshowpos		Do not show positive signs (function )
noskipws		Do not skip whitespaces (function )
nounitbuf		Do not force flushes after insertions (function )
nouppercase		Do not generate upper case letters (function )

Numerical base format flags ("basefield" flags):
dec				Use decimal base (function )
hex				Use hexadecimal base (function )
oct				Use octal base (function )

Floating-point format flags ("floatfield" flags):
fixed			Use fixed floating-point notation (function )
scientific		Use scientific floating-point notation (function )

Adustment format flags ("adjustfield" flags):
internal		Adjust field by inserting characters at an internal position (function )
left			Adjust output to the left (function )
right			Adjust output to the right (function )

Input manipulators
ws				Extract whitespaces (function )

Output manipulators
endl			Insert newline and flush (function )
ends			Insert null character (function )
flush			Flush stream buffer (function )

Parameterized manipulators
These functions take parameters when used as manipulators.
They require the explicit inclusion of the header file <iomanip>.

setiosflags		Set format flags (function )
resetiosflags	Reset format flags (function )
setbase			Set basefield flag (function )
setfill			Set fill character (function )
setprecision	Set decimal precision (function )
setw			Set field width (function )

*/

/*
comment: https://www.hackerrank.com/cian_j_mcintyre?hr_r=1

Initial Code

This problem actually forces two manipulators on
you initially which don't seem to be helpful at all.
These manipulators are setw and internal.
The former sets a fixed width for the output
(in this case 15 characters wide) and
the latter will align it to the right.
We need to basically undo this in the first printed line because we want
the hexadecimal printout to be left-aligned instead.

Printed Line 1

The manipulators I used here are

hex (which will output the number in hexadecimal format),

left (which will align the number to the left),

showbase (which will make sure the hexadecimal number has a '0x' at the beginning),

and nouppercase (which converts all alphabetic hexadecimal values to lowercase).

Printed Line 2 In this section,
I actually have to undo some of the previous manipulations.

dec: switches numbers from hexadecimal back to decimal.

right: aligns values to the right instead of the left

setw(15): sets a fixed width of 15, as the effect from
the initial code only impacts the first printed line.

setfill('_'): by default, when you have a fixed width,
if your printed value doesn't fill up the entire length (for example,
if you have a width of 15 and only print 7 characters),
the extra characters used to pad are whitespaces.
This function lets you change the padding to whatever character you want.

showpos: Makes sure there is a plus sign before any positive numbers

fixed: ensures that number is printed out entirely and
that scientific notation isn't used for larger numbers

setprecision(2): sets the number of decimal places to 2.

Printed Line 3

scientific: Prints output in scientific notation format

uppercase: Undoes previous nouppercase manipulator and

ensures that the 'E' in the scientific notation is capitalised

noshowpos: Undoes previous showpos manipulator and
gets rid of the plus at the start of positive values
setprecision: Changes the number of digits after the decimal place from 2 to 9.
*/