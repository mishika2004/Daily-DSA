1class Solution {
2public:
3    int numEnclaves(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        queue<pair<int,int>> q;
7        int count=0;
8
9        for(int i=0;i<n;i++){
10            for(int j=0;j<m;j++){
11                if(i==0 || j==0 || i==n-1 || j==m-1){
12                  if(grid[i][j]==1){
13                    grid[i][j]=0;
14                    q.push({i,j});
15                }
16            }
17        }
18    }
19                    while(!q.empty()){
20                        int row=q.front().first;
21                        int col=q.front().second;
22                        q.pop();
23
24                        if(row-1>=0 && grid[row-1][col]==1){
25                            grid[row-1][col]=0;
26                            q.push({row-1, col});
27                        }
28
29                        if(row+1<n && grid[row+1][col]==1){
30                            grid[row+1][col]=0;
31                            q.push({row+1, col});
32                        }
33
34                        if(col-1>=0 && grid[row][col-1]==1){
35                            grid[row][col-1]=0;
36                            q.push({row, col-1});
37                        }
38
39                        if(col+1<m && grid[row][col+1]==1){
40                            grid[row][col+1]=0;
41                            q.push({row, col+1});
42                        }
43                    }
44
45                for(int i=0;i<n;i++){
46                    for(int j=0;j<m;j++){
47                        if(grid[i][j]==1){
48                            count++;
49                        }
50                    }
51                }
52         return count;
53    }
54};