#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int>maxRight(n,0);
        maxRight[n-1] = n-1;
        for(int i=n-2;i>=0;i--){
            int rightMaxIdx = maxRight[i+1];
            int rightMaxElement = s[rightMaxIdx];
            maxRight[i] = s[i] > rightMaxElement ? i : rightMaxIdx;
        }

        for(int i=0;i<n;i++){
            int rightMaxIdx = maxRight[i];
            int rightMaxElement = s[rightMaxIdx];
            if(s[i] < rightMaxElement){
                swap(s[i],s[rightMaxIdx]);
                return stoi(s);
            }
        }
        return num;
    }
};

int main() {
    Solution sol;
    return 0;
}