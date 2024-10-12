#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int currGroup = 0 , maxGroup = 0;

        vector<pair<int,int>>events;
        for(auto &interval : intervals){
            events.push_back({interval[0],1});
            events.push_back({interval[1]+1,-1});
        }
        sort(events.begin(),events.end());
        for(auto event : events){
            currGroup += event.second;

            maxGroup = max(maxGroup,currGroup);
        }

        return maxGroup;
    }
};


int main() {
    Solution sol;
    return 0;
}