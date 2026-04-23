1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        //int n=times.size();
5        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
6        vector<int> dist(n+1,1e9);
7        dist[k]=0;
8
9        vector<pair<int,int>> adj[n+1];
10        for(auto &i: times){
11            int u=i[0];
12            int v=i[1];
13            int w=i[2];
14            adj[u].push_back({v,w});
15        }
16
17        pq.push({0,k});
18        while(!pq.empty()){
19            auto [d,node]=pq.top();
20            pq.pop();
21            for(auto &it: adj[node]){
22                int adjNode=it.first;
23                int wt=it.second;
24
25                if(d+wt<dist[adjNode]){
26                    dist[adjNode]=d+wt;
27                    pq.push({dist[adjNode], adjNode});
28                }
29            }
30        }
31        int maxi=0;
32        for(int i=1;i<=n;i++){
33            if(dist[i]==1e9) return -1;
34            maxi=max(maxi,dist[i]);
35        }
36        return maxi;
37    }
38};