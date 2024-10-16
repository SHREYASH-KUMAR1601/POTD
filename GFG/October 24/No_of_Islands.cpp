//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    void markAllConnected(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, int n, int m) {
        // Check boundaries
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == '0') {
            return;
        }

        vis[i][j] = true;

        markAllConnected(i + 1, j, grid, vis, n, m);     // Down
        markAllConnected(i - 1, j, grid, vis, n, m);     // Up
        markAllConnected(i, j + 1, grid, vis, n, m);     // Right
        markAllConnected(i, j - 1, grid, vis, n, m);     // Left
        markAllConnected(i + 1, j + 1, grid, vis, n, m); // Down-Right
        markAllConnected(i - 1, j + 1, grid, vis, n, m); // Up-Right
        markAllConnected(i + 1, j - 1, grid, vis, n, m); // Down-Left
        markAllConnected(i - 1, j - 1, grid, vis, n, m); // Up-Left
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    markAllConnected(i, j, grid, vis, n, m);
                }
            }
        }

        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends