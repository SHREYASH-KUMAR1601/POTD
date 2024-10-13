#include <bits/stdc++.h>
using namespace std;

#define P pair<int, pair<int, int>> 
// To store {element, {listIdx, idx}}
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        // Min-heap to store {value, {listIndex, elementIndex}}
        priority_queue<P, vector<P>, greater<P>> pq;
        int maxEl = INT_MIN;

        for (int i = 0; i < n; ++i) {
            pq.push({nums[i][0], {i, 0}});  // Push {element, {list index, element index}}
            maxEl = max(maxEl, nums[i][0]);
        }

        pair<int, int> res = {1e-6, 1e6};  

        while (!pq.empty()) {
            auto [minEl, indices] = pq.top();
            pq.pop();
            int listIdx = indices.first;
            int i = indices.second;

            if (res.second - res.first > maxEl - minEl) {
                res = {minEl, maxEl};
            }

            if (i + 1 < nums[listIdx].size()) {
                pq.push({nums[listIdx][i + 1], {listIdx, i + 1}});  
                maxEl = max(maxEl, nums[listIdx][i + 1]); 
            } else {
                break;
            }
        }

        return {res.first, res.second};   
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<int> listIndex(n, 0);

        int start = 0, end = INT_MAX;

        while (true) {
            int minel = INT_MAX, maxel = INT_MIN, minIndex = -1;

            for (int a = 0; a < n; ++a) {
                if (nums[a][listIndex[a]] < minel) {
                    minel = nums[a][listIndex[a]];
                    minIndex = a; 
                }
                if (nums[a][listIndex[a]] > maxel) {
                    maxel = nums[a][listIndex[a]];
                }
            }

            if (maxel - minel < end - start) {
                start = minel;
                end = maxel;
            }

            listIndex[minIndex]++;

            if (listIndex[minIndex] == nums[minIndex].size()) {
                break;
            }
        }

        return {start, end};
    }
};

int main() {
    Solution sol;
    return 0;
}