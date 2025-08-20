#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> map;

        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            if (map.find(t[i]) != map.end()) {
                map[t[i]]--;
                if (map[t[i]] == 0) map.erase(t[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<pair<string, string>> testcases = {
        {"anagram", "nagaram"}, // true
        {"rat", "car"},         // false
        {"listen", "silent"},   // true
        {"hello", "world"}      // false
    };

    for (auto &tc : testcases) {
        cout << "s = " << tc.first << ", t = " << tc.second
             << " -> " << (sol.isAnagram(tc.first, tc.second) ? "true" : "false")
             << endl;
    }

    return 0;
}
