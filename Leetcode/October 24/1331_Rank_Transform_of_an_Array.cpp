#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>nums(n,0);

        for(int i=0;i<n;i++){
            nums[i] = arr[i];
        }

        sort(nums.begin(),nums.end());

        map<int,int>mp;
        int rank = 1;

        for(int i=0;i<n;i++){

            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = rank++;
            }

        }

        for(int i=0;i<n;i++){
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};

int main() {
    Solution sol;
    return 0;
}