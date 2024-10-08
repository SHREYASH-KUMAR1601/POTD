#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long n = skill.size();
        map<long long, long long> mp;

        long long sum = 0;
        for (auto x : skill) {
            mp[x]++;
            sum += x;
        }

        if (sum % (n / 2) != 0) {
            return -1;
        }

        long long target_sum = sum / (n / 2);
        long long total_chemistry = 0;

        for (auto& x : mp) {
            long long num = x.first;
            long long count1 = x.second;

            if (count1 == 0) {
                continue;  
            }

            long long complement = target_sum - num;

            if (num == complement) {
                if (count1 % 2 != 0) {
                    return -1;
                }
                total_chemistry += (num * complement) * (count1 / 2);
            } else {
                if (mp[complement] < count1) {
                    return -1;
                }
                total_chemistry += (num * complement) * count1;
                mp[complement] -= count1;  
            }

            mp[num] = 0;
        }

        return total_chemistry;
    }
};

int main() {
    Solution sol;
    return 0;
}