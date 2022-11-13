// C++ program to find minimum number
// of swap operations required
#include <bits/stdc++.h>
using namespace std;

// Function that print minimum number
// of swap operations required
void MinimumSwapOperations(string s)
{
	bool zero_exist = false;
	bool multiple_of_2 = false;
	int sum = 0;
	int index_of_zero;
	bool more_zero = false;

	for (int i = 0; i < s.length(); i++) {
		int val = s[i] - '0';

		// Condition if more than one
		// zero exist
		if (zero_exist == true)
			more_zero = true;

		// Condition if zero_exist
		if (val == 0) {
			zero_exist = true;
			index_of_zero = i;
		}

		// Computing total sum of all digits
		sum += val;
	}

	// Condition if zero does not exist or
	// the sum is not divisible by 3
	if (zero_exist == false || sum % 3 != 0) {
		cout << "-1"
			<< "\n";
		return;
	}

	for (int i = 0; i < s.length(); i++) {
		int val = s[i] - '0';

		// Condition to find a digit that is
		// multiple of 2 other than one zero
		if (val % 2 == 0 && i != index_of_zero)
			multiple_of_2 = true;
	}

	// Condition if multiple of 2
	// do not exist
	if (multiple_of_2 == false) {
		cout << "-1"
			<< "\n";
		return;
	}

	int last_val = s[s.length() - 1] - '0';
	int second_last_val = s[s.length() - 2]
						- '0';

	// Condition for zero swaps
	// means the number is already
	// is divisible by 60
	if (last_val == 0
		&& second_last_val % 2 == 0)
		cout << 0 << "\n";

	// Condition for only one swap
	else if ((last_val == 0
			&& second_last_val % 2 != 0)
			|| (last_val % 2 == 0
				&& second_last_val == 0))
		cout << 1 << "\n";

	else if (more_zero == true
			&& (last_val == 0
				&& second_last_val % 2 != 0))
		cout << 1 << "\n";

	// Otherwise 2 swaps required
	else
		cout << 2 << "\n";
}

// Driver Code
int main()
{
	string N = "20";

	MinimumSwapOperations(N);

	return 0;
}
