#include <stdio.h>
#include <string.h>

void MinimumSwapOperations(string s)
{
	bool zero_exist = false;
	bool multiple_of_2 = false;
	int sum = 0;
	int index_of_zero;
	bool more_zero = false;

	for (int i = 0; i < strlen(s); i++) {
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
		printf("-1\n");
			}
         int last_val = s[strlen(s)- 1];
	int second_last_val = s[strlen(s)- 2];

	// Condition for zero swaps
	// means the number is already
	// is divisible by 3
	if (last_val == 0 && second_last_val % 2 == 0)
		printf("0\n");

	// Condition for only one swap
	else if ((last_v al == 0 && second_last_val % 2 != 0)|| (last_val % 2 == 0 && second_last_val == 0))
		printf("1\n");

	else if (more_zero == true && (last_val == 0 && second_last_val % 2 != 0))
		printf("1\n");
        // Otherwise 2 swaps required
	else
		printf("2\n");
}

// Driver Code
int main()
{
	string N = "20";

	MinimumSwapOperations(N);

	return 0;
}
