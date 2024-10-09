#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n  = s.length();
        int open = 0,closed = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                open++;
            }else{
                if(open>0) open--;
                else closed++;
            }
        }

        return open+closed;
    }
};

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n  = s.length();
        stack<char>st;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(!st.empty() and st.top() == '('){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }

        return st.size();
    }
};

int main() {
    Solution sol;
    return 0;
}