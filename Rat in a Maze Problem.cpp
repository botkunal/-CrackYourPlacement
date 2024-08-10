//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void findPaths(vector<vector<int>> &mat, int n, int x, int y, string path, vector<string> &paths, vector<vector<bool>> &visited) {
    // If destination is reached
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    // Possible directions: 'D', 'L', 'R', 'U'
    string directions = "DLRU";
    int dx[] = {1, 0, 0, -1}; // Corresponding x moves for D, L, R, U
    int dy[] = {0, -1, 1, 0}; // Corresponding y moves for D, L, R, U

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newY >= 0 && newX < n && newY < n && mat[newX][newY] == 1 && !visited[newX][newY]) {
            visited[newX][newY] = true;
            findPaths(mat, n, newX, newY, path + directions[i], paths, visited);
            visited[newX][newY] = false; // Backtrack
        }
    }
}
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();
        vector<string> paths;
    if (mat[0][0] == 0 || mat[n-1][n-1] == 0) {
        return paths; // No possible path if start or end is blocked
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    findPaths(mat, n, 0, 0, "", paths, visited);

    sort(paths.begin(), paths.end()); // Optional: Sort paths lexicographically
    return paths;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
