#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// This makes it so we don't have to type "std::" before every standard library function.
using namespace std;

// This function reverses the words in a given string.
string reverseWords(string s) {
    // 1. Use a stringstream to easily split the string by spaces.
    stringstream ss(s);
    string word;
    vector<string> words;

    // 2. Read each word from the stringstream and add it to our vector.
    // The '>>' operator automatically extracts words separated by whitespace.
    while (ss >> word) {
        words.push_back(word);
    }

    // 3. Reverse the order of the words in the vector.
    reverse(words.begin(), words.end());

    // 4. Join the words back together with a space in between.
    string result = "";
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        // Add a space after each word except the last one.
        if (i < words.size() - 1) {
            result += " ";
        }
    }

    return result;
}

// --- Main function to test the code ---
int main() {
    string my_string = "the sky is blue";
    string reversed_string = reverseWords(my_string);

    cout << "Original: \"" << my_string << "\"" << endl;
    cout << "Reversed: \"" << reversed_string << "\"" << endl;

    return 0;
}
