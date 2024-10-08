#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty() or st.top() == ']'){
                    st.push(s[i]);
                }else{
                    st.pop();
                }
            }
        }

        return ((st.size()/2)+1)/2;
    }
};

int main() {
    Solution sol;
    return 0;
}