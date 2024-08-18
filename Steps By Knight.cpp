//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    // Directions a knight can move
        int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
        int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
        
        // To keep track of visited cells
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        
        // BFS queue initialization
        queue<pair<pair<int, int>, int>> q;
        q.push({{KnightPos[0], KnightPos[1]}, 0});
        visited[KnightPos[0]][KnightPos[1]] = true;
        
        // BFS Loop
        while (!q.empty()) 
        {
            auto current = q.front();
            q.pop();
            int x = current.first.first;
            int y = current.first.second;
            int dist = current.second;
            
            // If current position is the target
            if (x == TargetPos[0] && y == TargetPos[1]) 
            {
                return dist;
            }
            
            // Explore all possible moves of a knight
            for (int i = 0; i < 8; i++) 
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                // Check if the new position is inside the board and not visited
                if (newX >= 1 && newX <= N && newY >= 1 && newY <= N && !visited[newX][newY]) 
                {
                    visited[newX][newY] = true;
                    q.push({{newX, newY}, dist + 1});
                }
            }
        }
        
        // If the target is unreachable, return -1
        return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
