#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i], tc = t[i];
            if (mapST.count(sc) && mapST[sc] != tc) return false;
            if (mapTS.count(tc) && mapTS[tc] != sc) return false;

            mapST[sc] = tc;
            mapTS[tc] = sc;
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<pair<string,string>> testcases = {
        {"egg", "add"},     // true
        {"foo", "bar"},     // false
        {"paper", "title"}, // true
        {"badc", "baba"}    // false
    };

    for (auto &tc : testcases) {
        cout << "s = " << tc.first << ", t = " << tc.second 
             << " -> " << (sol.isIsomorphic(tc.first, tc.second) ? "true" : "false") 
             << endl;
    }

    return 0;
}
