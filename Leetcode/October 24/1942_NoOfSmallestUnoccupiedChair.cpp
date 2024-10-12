#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<array<int, 3>> friends;
        for (int i = 0; i < n; i++) {
            friends.push_back({times[i][0], times[i][1], i});
        }

        sort(friends.begin(), friends.end());

        priority_queue<int, vector<int>, greater<int>> available;
    
        priority_queue<P, vector<P>, greater<P>> occupied;
        
        int chair = 0;
        
        for (auto& friendInfo : friends) {
            int arrival = friendInfo[0];
            int departure = friendInfo[1];
            int index = friendInfo[2];

            while (!occupied.empty() && arrival >= occupied.top().first) {
                available.push(occupied.top().second); 
                occupied.pop();
            }

            int currChair;
            if (!available.empty()) {
                currChair = available.top();
                available.pop();
            } else {
                currChair = chair;
                chair++;
            }

            if (index == targetFriend) {
                return currChair;
            }

            occupied.push({departure, currChair});
        }

        return -1; 
    }
};


int main() {
    Solution sol;
    return 0;
}