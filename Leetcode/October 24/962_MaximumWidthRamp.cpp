#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i == 0) st.push({nums[i], i});
            else if (nums[i] < st.top().first) {
                st.push({nums[i], i});
            }
        }

        int ans = 0; 

        for (int j = n - 1; j >= 0 && !st.empty(); j--) {
            while (!st.empty() && nums[j] >= st.top().first) {//O(n) because each element is processed only once. New stack is not formedd for other elements.
                auto [k, indx] = st.top();
                ans = max(ans, j - indx);  
                st.pop();
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;
    return 0;
}