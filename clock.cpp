#include <iostream>
using namespace std;

// Broken clock moves "rate" seconds each second
// Returns how many times the two clocks would be the same after "hours" number of hours (ignore am and pm)
// Assume both clocks start at 12:00:00
// e.g. checkTime(1, 24) would return 86400 since the broken and normal clock will be at the same time for 24 hours straight
// e.g. checkTime(43200, 24) would return 2 since broken clock moves 12 hours at a time; both clocks will only be the same after 12 hours and 24 hours
int checkTime(int rate, int hours) {
	// All times will be represented as an integer in the range [0, 43200), with 0 being 12:00:00
	// In essence, the question is asking for the number of solutions to (rate - 1)X = 0(mod 43200)
	int brokenTime = 0;
	int normalTime = 0;

	int result = 0;
	int seconds = hours * 60 * 60;
	for (int i = 0; i < seconds; ++i) 
	{
		++normalTime;
		normalTime %= 43200;

		brokenTime += rate;
		brokenTime %= 43200;

		if (brokenTime == normalTime)
			++result;
	}
	return result;
}