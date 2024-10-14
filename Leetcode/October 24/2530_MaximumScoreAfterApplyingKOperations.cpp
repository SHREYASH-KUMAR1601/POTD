#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end()); 

        long long ans = 0;

        while (k-- > 0) {
            int el = pq.top();
            pq.pop();
            ans += el;

            if (el > 1) {
                pq.push((el + 2) / 3); 
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;
    return 0;
}