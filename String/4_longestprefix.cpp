#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(), v.end());
        int n=v.size();
        string first=v[0], last=v[n-1];
        for(int i=0; i<min(first.size(), last.size()); i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> v(n);
    cout << "Enter the strings: \n";
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    string res = sol.longestCommonPrefix(v);
    cout << "Longest Common Prefix: " << res << endl;
    
    return 0;
}
