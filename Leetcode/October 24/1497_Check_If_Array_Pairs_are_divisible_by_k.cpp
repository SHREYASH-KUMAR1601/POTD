#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;

        for(auto &x : arr) {
            x = (x % k + k) % k; 
            mp[x]++;
        }

        for(auto &x : mp) {
            int rem = x.first;
            int freq = x.second;

            if(rem == 0) {
                if(freq % 2 != 0) {
                    return false;
                }
            }
            else if(rem * 2 == k) {
                if(freq % 2 != 0) {
                    return false;
                }
            }
            else {
                if(mp[rem] != mp[k - rem]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    return 0;
}