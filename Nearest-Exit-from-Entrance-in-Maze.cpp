1class Solution {
2public:
3    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
4        int n=maze.size();
5        int m=maze[0].size();
6        queue<pair<int, int>> q;
7
8        q.push({entrance[0], entrance[1]});
9        maze[entrance[0]][entrance[1]]='+';
10        int steps=0;
11
12        int dir[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
13        while(!q.empty()){
14            int sz=q.size();
15            steps++;
16            while(sz--){
17                auto node = q.front();
18                q.pop();
19                int row = node.first;
20                int col = node.second;
21
22                for(int i=0;i<4;i++){
23                    int nr = row+dir[i][0];
24                    int nc = col+dir[i][1];
25
26                    if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]=='.'){
27                        if(nr==0 ||nr==n-1||nc==0||nc==m-1)
28                            return steps;
29
30                        maze[nr][nc]='+';
31                        q.push({nr,nc});
32                    }
33                }  
34            }
35        }
36        return -1;
37    }
38};