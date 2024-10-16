//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void swapOne(vector<int> &array, int N) {
        for (int i = 0; i < N; i++) {
            if (array[i] != i + 1) {
                int temp = array[i];
                array[i] = array[temp - 1];
                array[temp - 1] = temp;
                break;
            }
        }
    }
    
    int findUnsortedCount(vector<int> &array, int N) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (array[i] != i + 1) {
                count++;
            }
        }
        return count;
    }

    bool checkSorted(vector<int> &arr) {
        int N = arr.size();
        int count = findUnsortedCount(arr, N);
        
        if (count == 0 || count == 3) {
            return true;
        }
 
        if (count == 4) {
            swapOne(arr, N);
            swapOne(arr, N);
            return findUnsortedCount(arr, N) == 0;
        }

        return false;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends