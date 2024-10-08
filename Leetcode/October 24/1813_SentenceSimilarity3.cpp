#include <bits/stdc++.h>
using namespace std;


//Important:: stringstream is used to get input as a stream of words. It can be used to split a sentence into words.

/*stringstream ss(str);
string word;
while(ss>>word){    //Gives count of words in a sentence
    count++;
}
*/

class Solution {

public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split sentences into words
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);

        // Ensure words1 is the shorter one
        if (words1.size() > words2.size()) {
            swap(words1, words2);
        }

        int n = words1.size(), m = words2.size();
        int i = 0, j = 0;

        // Find the longest common prefix
        while (i < n && words1[i] == words2[i]) {
            i++;
        }

        // Find the longest common suffix
        while (j < n && words1[n - 1 - j] == words2[m - 1 - j]) {
            j++;
        }

        // Check if the prefix and suffix together cover the entire shorter sentence
        return i + j >= n;
    }

private:
    vector<string> split(const string& sentence) {
        vector<string> result;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }
};


int main() {
    Solution sol;
    return 0;
}