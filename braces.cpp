#include <stack>
#include <string>

using namespace std;

// Returns the number of balanced braces in a given expression
// Valid "braces" are (), [], and {}
// Assume expression has no other characters besides those 6
int balancedBraces(string expression) {
	stack<char> s;
	int size = expression.size();

	// There can be no balanced braces with less than 2 characters
	if (size < 2)
		return 0;

	int counter = 0;
	for (int i = 0; i < size; ++i) {
		if ((expression[i] == '{') || (expression[i] == '(') || (expression[i] == '[')) 
			s.push(expression[i]);

		else if (!s.empty()) {
			if (expression[i] == '}') {
				if (s.top() == '{') {
					++counter;
					s.pop();
				}
				else 
					return counter;
			}

			else if (expression[i] == ']') {
				if (s.top() == '[') {
					++counter;
					s.pop();
				}
				else 
					return counter;
			}

			else if (expression[i] == ')') {
				if (s.top() == '(') {
					++counter;
					s.pop();
				}
				else
					return counter;
			}
		}
	}
	return counter;
}