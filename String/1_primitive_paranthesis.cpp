#include <iostream>
#include <string>
using namespace std;
// --- The Solution Class You Provided ---
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                // If balance > 0, this '(' is not an outermost one.
                if (balance > 0) {
                    res.push_back(c);
                }
                balance++;
            } else { // c must be ')'
                balance--;
                // If balance > 0, this ')' is not an outermost one.
                if (balance > 0) {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};

// --- Main Function to Run the Code ---
int main() {
    // 1. Create an instance of the Solution class.
    Solution sol;

    // 2. Define the input string to test.
    string input = "(()())(())";

    // 3. Call the method and get the result.
    string result = sol.removeOuterParentheses(input);

    // 4. Print the original and final strings to the console.
    cout << "Original: " << input << endl;
    cout << "Result:   " << result << endl;

    return 0; // Indicates the program finished successfully.
}