#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        // 1. Loop from the end of the string to the beginning.
        for (int i = num.length() - 1; i >= 0; --i) {
            // 2. Get the numeric value of the character.
            int digit = num[i] - '0';

            // 3. Check if the digit is odd.
            if (digit % 2 != 0) {
                // 4. If it is, return the substring from the start up to this character.
                return num.substr(0, i + 1);
            }
        }

        // 5. If the loop finishes, no odd digit was found.
        return "";
    }
};

// --- Main function to test ---
int main() {
    Solution sol;
    string test_num = "754238";
    cout << "Largest odd number in " << test_num << " is: " << sol.largestOddNumber(test_num) << endl; // Output: 75423

    test_num = "4206";
    cout << "Largest odd number in " << test_num << " is: \"" << sol.largestOddNumber(test_num) << "\"" << endl; // Output: ""
    return 0;
}