#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long black = 0;
        long long ans = 0;
        for(char c : s){
            if(c == '1'){
                black++;
            }else{
                ans += black;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}