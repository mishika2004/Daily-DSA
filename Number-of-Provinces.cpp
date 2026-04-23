1class Solution {
2public:
3    void dfs(int i, vector<int> &vis, vector<vector<int>> &isConnected){
4        vis[i]=1;
5        int n=isConnected.size();
6
7        for(int j=0;j<n;j++){
8            if(!vis[j] && isConnected[i][j]==1){
9                dfs(j,vis,isConnected);
10            }
11        }
12    }
13    int findCircleNum(vector<vector<int>>& isConnected) {
14        int n=isConnected.size();
15        int m=isConnected[0].size();
16
17        vector<int> vis(n,0);
18        int provinces=0;
19        for(int i=0;i<n;i++){
20            if(!vis[i]){
21                dfs(i,vis,isConnected);
22                provinces++;
23            }
24        }
25        return provinces;
26    }
27};