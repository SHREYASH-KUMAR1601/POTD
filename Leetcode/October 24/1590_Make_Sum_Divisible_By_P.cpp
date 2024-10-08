#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int sum = 0;
        int n = nums.size();

        for (int x : nums)
        {
            sum = (sum % p + x % p) % p;
        }

        if (sum % p == 0)
        {
            return 0;
        }

        int remainder = sum % p;
        unordered_map<int, int> prefixMap; //(prefixSum%p,index)
        prefixMap[0] = -1;
        int prefixSum = 0;
        int minLen = n;

        for (int i = 0; i < n; ++i)
        {
            prefixSum = (prefixSum + nums[i]) % p;

            // We need to find a previous prefix sum such that
            // (prefixSum - previousPrefixSum) % p == remainder
            int target = (prefixSum - remainder + p) % p;

            if (prefixMap.count(target))
            {
                minLen = min(minLen, i - prefixMap[target]);
            }
            prefixMap[prefixSum] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};

int main()
{
    Solution sol;
    return 0;
}