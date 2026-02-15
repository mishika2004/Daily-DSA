1class Solution {
2public:
3    int maxDistance(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        queue<pair<int,int>> q;
7        //int maxDist=-1;
8        int currDist=-1;
9
10        for(int i=0;i<n;i++){
11            for(int j=0;j<m;j++){
12                if(grid[i][j]==1){
13                    q.push({i,j});
14        
15                }
16            }
17        }
18
19
20        if(q.empty() || q.size() == n*m) return -1;
21
22        while(!q.empty()){
23            currDist++;
24            
25            int size=q.size();
26            for(int i=0;i<size;i++){
27                int row=q.front().first;
28                int col=q.front().second;
29                q.pop();
30                if(row-1>=0 && grid[row-1][col]==0){
31                    grid[row-1][col]=1;
32                    q.push({row-1, col});
33                }
34
35                if(row+1<n && grid[row+1][col]==0){
36                    grid[row+1][col]=1;
37                    q.push({row+1, col});
38                }
39
40                if(col-1>=0 && grid[row][col-1]==0){
41                    grid[row][col-1]=1;
42                    q.push({row, col-1});
43                }
44
45                if(col+1<m && grid[row][col+1]==0){
46                    grid[row][col+1]=1;
47                    q.push({row, col+1});
48                }
49            }
50        }
51       return currDist;
52    }
53};