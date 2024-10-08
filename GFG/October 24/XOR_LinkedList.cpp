//{ Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        struct Node *head = NULL;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            head = insert(head, number);
        }

        vector<int> vec = getList(head);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// Function to insert a node at the front of the XOR linked list
struct Node* insert(struct Node* head, int data) {
    // Create new node
    Node* newNode = new Node(data);

    // New node's npx will be XOR of null and current head (prev XOR next)
    newNode->npx = XOR(nullptr, head);

    // If the list is not empty, update the head's npx
    if (head != nullptr) {
        // Update the current head's npx to be XOR of the new node and its next node
        Node* next = XOR(nullptr, head->npx);
        head->npx = XOR(newNode, next);
    }

    // The new node is now the head of the list
    return newNode;
}

// Function to get the list elements in order
vector<int> getList(struct Node* head) {
    vector<int> result;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;

    // Traverse the list
    while (curr != nullptr) {
        // Add current node's data to result
        result.push_back(curr->data);

        // Compute the next node (XOR of previous and current node's npx)
        next = XOR(prev, curr->npx);

        // Move to the next node
        prev = curr;
        curr = next;
    }

    return result;
}

