//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// class Solution {
//   public:
//     vector<int> rearrange(const vector<int>& arr) {
//         // Code here
//         int n = arr.size();
//         vector<int>ans(n,0);
//         unordered_set<int>s;
//         for(auto &x : arr){
//             s.insert(x);
//         }
//         for(int i=0;i<n;i++){
//             if(s.find(i) == s.end()){
//                 ans[i] = -1;
//             }else{
//                 ans[i] = i;
//                 s.erase(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution{
public:
    vector<int> rearrange(vector<int> &A){
        // Code here

        int len = A.size();
        for (int i = 0; i < len; i++){
            if (A[i] != -1 && A[i] != i){
                int x = A[i];

                // check if desired place
                // is not vacate
                while (A[x] != -1 && A[x] != x){
                    // store the value from
                    // desired place
                    int y = A[x];

                    // place the x to its correct
                    // position
                    A[x] = x;

                    // now y will become x, now
                    // search the place for x
                    x = y;
                }

                // place the x to its correct
                // position
                A[x] = x;

                // check if while loop hasn't
                // set the correct value at A[i]
                if (A[i] != i){
                    // if not then put -1 at
                    // the vacated place
                    A[i] = -1;
                }
            }
        }

        return A;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends