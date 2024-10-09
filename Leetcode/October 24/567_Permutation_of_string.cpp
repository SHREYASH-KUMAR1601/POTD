#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        if (len1 > len2) return false; 

        vector<int> freq1(26, 0), freq2(26, 0);

        for (int i = 0; i < len1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        for (int i = len1; i < len2; i++) {
            if (freq1 == freq2) return true;

            freq2[s2[i] - 'a']++;
            freq2[s2[i - len1] - 'a']--;
        }

        return freq1 == freq2;
    }
};


int main() {
    Solution sol;
    return 0;
}