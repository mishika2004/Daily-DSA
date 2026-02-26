1class Solution {
2public:
3    int swimInWater(vector<vector<int>>& grid) {
4        int n=grid.size();
5        priority_queue<
6          pair<int,pair<int,int>>, 
7          vector<pair<int, pair<int,int>>>,
8          greater<pair<int, pair<int,int>>>
9        > pq;
10        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
11        dist[0][0]=grid[0][0];
12        pq.push({grid[0][0], {0,0}});
13
14        int dx[4] = {0, 0, -1, 1};
15        int dy[4] = {-1, 1, 0, 0};
16        while(!pq.empty()){
17            auto [time,node]=pq.top();
18            pq.pop();
19            int x=node.first;
20            int y=node.second;
21            if (x==n-1 && y==n-1)
22                return time;
23            
24            if (time>dist[x][y]) continue;
25            for(int i=0;i<4;i++){
26                int nx=x+dx[i];
27                int ny=y+dy[i];
28                if(nx>=0 && nx<n && ny>=0 && ny<n){
29                    int newTime = max(time,grid[nx][ny]);
30                    if(newTime<dist[nx][ny]){
31                        dist[nx][ny]=newTime;
32                        pq.push({newTime,{nx,ny}});
33                    }
34                }
35            }
36        }
37        return -1;
38    }
39};