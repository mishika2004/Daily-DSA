1class Solution {
2public:
3    int closedIsland(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        int count=0;
7        queue<pair<int,int>> q;
8
9        for(int i=0;i<n;i++){
10            if(grid[i][0]==0){
11                q.push({i,0});
12                grid[i][0]=1;
13            }
14            if(grid[i][m-1]==0){
15                q.push({i,m-1});
16                grid[i][m-1]=1;
17            }
18        }
19
20        for(int j=0;j<m;j++){
21            if(grid[0][j]==0){
22                q.push({0,j});
23                grid[0][j]=1;
24            }
25            if(grid[n-1][j]==0){
26                q.push({n-1,j});
27                grid[n-1][j]=1;
28            }
29        }
30
31        //for connected lands --- visiting neighbours
32        while(!q.empty()){
33            int row=q.front().first;
34            int col=q.front().second;
35            q.pop();
36
37            if(row-1>=0 && grid[row-1][col]==0){
38                grid[row-1][col]=1;
39                q.push({row-1,col});
40            }
41
42            if(row+1<n && grid[row+1][col]==0){
43                grid[row+1][col]=1;
44                q.push({row+1,col});
45            }
46
47            if(col-1>=0 && grid[row][col-1]==0){
48                grid[row][col-1]=1;
49                q.push({row,col-1});
50            }
51
52            if(col+1<m && grid[row][col+1]==0){
53                grid[row][col+1]=1;
54                q.push({row,col+1});
55            }
56        }
57
58        for(int i=0;i<n;i++){
59            for(int j=0;j<m;j++){
60                if(grid[i][j]==0){
61                    count++; q.push({i,j});
62                    grid[i][j]=1;
63
64
65                    while(!q.empty()){
66            int row=q.front().first;
67            int col=q.front().second;
68            q.pop();
69
70            if(row-1>=0 && grid[row-1][col]==0){
71                grid[row-1][col]=1;
72                q.push({row-1,col});
73            }
74
75            if(row+1<n && grid[row+1][col]==0){
76                grid[row+1][col]=1;
77                q.push({row+1,col});
78            }
79
80            if(col-1>=0 && grid[row][col-1]==0){
81                grid[row][col-1]=1;
82                q.push({row,col-1});
83            }
84
85            if(col+1<m && grid[row][col+1]==0){
86                grid[row][col+1]=1;
87                q.push({row,col+1});
88            }
89        }
90
91                }
92            }
93        }
94    return count;
95    }
96};