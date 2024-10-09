//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *down;

    Node(int x) {
        data = x;
        right = NULL;
        down = NULL;
    }
};


// } Driver Code Ends
/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]

class Solution {
public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return NULL;

        Node* head = new Node(mat[0][0]);
        vector<Node*> rowHeads(n, NULL);

        // Create the first row with right pointers
        rowHeads[0] = head;
        Node* temp = head;
        for (int j = 1; j < n; j++) {
            temp->right = new Node(mat[0][j]);
            temp = temp->right;
            rowHeads[j] = temp;
        }

        // Create the rest of the matrix row by row
        for (int i = 1; i < n; i++) {
            temp = new Node(mat[i][0]);
            rowHeads[0]->down = temp;
            rowHeads[0] = temp;

            for (int j = 1; j < n; j++) {
                temp->right = new Node(mat[i][j]);
                temp = temp->right;

                rowHeads[j]->down = temp;
                rowHeads[j] = temp;
            }
        }

        return head;
    }
};




//{ Driver Code Starts.

void display(Node* head) {
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            if (Rp->right)
                cout << Rp->right->data << " ";
            else
                cout << "null ";
            if (Rp->down)
                cout << Rp->down->data << " ";
            else
                cout << "null ";
            Rp = Rp->right;
        }
        Dp = Dp->down;
    }
}

// Driver program
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after integer input

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;

        // Read the first row of the matrix
        while (ss >> num) {
            nums.push_back(num);
        }

        int n = nums.size();
        vector<vector<int>> mat(n, vector<int>(n));
        mat[0] = nums;

        // Read the remaining rows of the matrix
        for (int i = 1; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> nums;
            int num;

            // Read the first row of the matrix
            while (ss >> num) {
                nums.push_back(num);
            }

            mat[i] = nums;
        }

        Solution ob;
        Node* head = ob.constructLinkedMatrix(mat);
        if (!head) {
            cout << "-1\n";
        } else {
            display(head);
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends