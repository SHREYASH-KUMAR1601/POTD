#include <bits/stdc++.h>
using namespace std;
#define P pair<int, char>

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string res = "";

        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();
            
            int n = res.size();
            
            if (n >= 2 && res[n-1] == ch && res[n-2] == ch) {
                if (pq.empty()) break;  // No other character available
                auto [nextFreq, nextChar] = pq.top();
                pq.pop();
                
                res += nextChar;
                
                if (nextFreq - 1 > 0) pq.push({nextFreq - 1, nextChar});
                
                pq.push({freq, ch});
            } else {
                res += ch;
                
                if (freq - 1 > 0) pq.push({freq - 1, ch});
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}