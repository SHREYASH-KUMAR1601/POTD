#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        int n = s.length();

        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i] == 'B'){
                (!st.empty() and st.top() == 'A') ? st.pop():st.push(s[i]);
            }else if(s[i] == 'D'){
                (!st.empty() and st.top() == 'C') ? st.pop():st.push(s[i]);
            }else{
                st.push(s[i]);
            }
        }

        return st.size();
    }
};


int main() {
    Solution sol;
    return 0;
}