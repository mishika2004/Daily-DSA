1class Solution {
2public:
3
4    void bfs(queue<pair<int,int>> &q, vector<vector<bool>> &vis,
5             vector<vector<int>>& heights){
6
7        int n = heights.size();
8        int m = heights[0].size();
9
10        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
11
12        while(!q.empty()){
13            auto p = q.front();
14            q.pop();
15
16            int r = p.first;
17            int c = p.second;
18
19            for(auto &d : dir){
20                int nr = r + d[0];
21                int nc = c + d[1];
22
23                if(nr>=0 && nr<n && nc>=0 && nc<m &&
24                   !vis[nr][nc] &&
25                   heights[nr][nc] >= heights[r][c]){
26
27                    vis[nr][nc] = true;
28                    q.push({nr,nc});
29                }
30            }
31        }
32    }
33
34    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
35
36        int n = heights.size();
37        int m = heights[0].size();
38
39        vector<vector<bool>> pacific(n, vector<bool>(m,false));
40        vector<vector<bool>> atlantic(n, vector<bool>(m,false));
41
42        queue<pair<int,int>> qp, qa;
43
44        
45        for(int i=0;i<n;i++){
46            qp.push({i,0});
47            pacific[i][0] = true;
48        }
49
50        for(int j=0;j<m;j++){
51            qp.push({0,j});
52            pacific[0][j] = true;
53        }
54
55       
56        for(int i=0;i<n;i++){
57            qa.push({i,m-1});
58            atlantic[i][m-1] = true;
59        }
60
61        for(int j=0;j<m;j++){
62            qa.push({n-1,j});
63            atlantic[n-1][j] = true;
64        }
65
66        bfs(qp, pacific, heights);
67        bfs(qa, atlantic, heights);
68
69        vector<vector<int>> ans;
70
71        for(int i=0;i<n;i++){
72            for(int j=0;j<m;j++){
73                if(pacific[i][j] && atlantic[i][j]){
74                    ans.push_back({i,j});
75                }
76            }
77        }
78
79        return ans;
80    }
81};