1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int n=mat.size();
5        int m=mat[0].size();
6        queue <pair<int,int>> q;
7        vector<vector<int>> dist(n, vector<int>(m,-1)); 
8
9        for(int i=0;i<n;i++){
10            for(int j=0;j<m;j++){
11                if(mat[i][j]==0){
12                    q.push({i,j});
13                    dist[i][j]=0;
14                }
15            }
16        }
17
18        while(!q.empty()){
19            int row=q.front().first;
20            int col=q.front().second;
21            q.pop();
22
23            if(row-1>=0 && dist[row-1][col]==-1){
24                        dist[row-1][col]=dist[row][col]+1;
25                        q.push({row-1, col});
26                        
27                    }
28
29                    if(row+1<n && dist[row+1][col]==-1){
30                         dist[row+1][col]=dist[row][col]+1;
31                         q.push({row+1, col});
32
33                    }
34
35                    if(col+1<m && dist[row][col+1]==-1){
36                        dist[row][col+1]=dist[row][col]+1;
37                        q.push({row, col+1});
38                        
39                    }
40
41                    if(col-1>=0 && dist[row][col-1]==-1){
42                        dist[row][col-1]=dist[row][col]+1;
43                        q.push({row, col-1});
44                      
45                    }
46                }
47        
48        return dist;
49    }
50};