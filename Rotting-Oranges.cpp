1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        int fresh=0;
7        queue <pair<int,int>> q;
8        
9        int time=0;
10
11        for(int i=0;i<n;i++){
12            for(int j=0;j<m;j++){
13                if(grid[i][j]==2){
14                    q.push({i,j});
15                }
16                else if(grid[i][j]==1){
17                   fresh++;
18                }
19            }
20        }
21          
22              if(fresh==0) return 0;
23
24         while(!q.empty()){
25                bool infected=false;
26                int size=q.size();
27                    
28                for(int i=0;i<size;i++){
29                    int row=q.front().first;
30                    int col=q.front().second;
31                    q.pop();
32
33                    if(row-1>=0 && grid[row-1][col]==1){
34                        grid[row-1][col]=2;
35                        q.push({row-1, col});
36                        fresh--;
37                        infected=true;
38                    }
39
40                    if(row+1<n && grid[row+1][col]==1){
41                    grid[row+1][col]=2;
42                        q.push({row+1, col});
43                        fresh--;
44                        infected=true;
45                    }
46
47                    if(col+1<m && grid[row][col+1]==1){
48                        grid[row][col+1]=2;
49                        q.push({row, col+1});
50                        fresh--;
51                        infected=true;
52                    }
53
54                    if(col-1>=0 && grid[row][col-1]==1){
55                        grid[row][col-1]=2;
56                        q.push({row, col-1});
57                        fresh--;
58                        infected=true;
59                    }
60                }
61                 if(infected) time++;
62            }
63    
64   return (fresh==0)?time: -1;
65  }
66};