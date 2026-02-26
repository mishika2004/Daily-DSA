1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        vector<vector<pair<int,int>>> adj(n);
5        for(int i=0;i<flights.size();i++){
6            int u=flights[i][0];
7            int v=flights[i][1];
8            int price=flights[i][2];
9            adj[u].push_back({v,price});
10
11        }
12        priority_queue<
13        tuple<int,int,int>,
14        vector<tuple<int,int,int>>,
15        greater<tuple<int,int,int>>
16    > pq;
17        vector<int> stop(n,INT_MAX);
18        pq.push({0,src,0});
19        while(!pq.empty()){
20            auto[cost,node,steps]=pq.top();
21            pq.pop();
22            if(node==dst) return cost;
23            if(steps>k || steps>stop[node]) continue;
24             stop[node] = steps;
25            for(int i=0;i<adj[node].size();i++){
26                int next=adj[node][i].first;
27                int price = adj[node][i].second;
28                pq.push({price+cost,next,steps+1});
29                  
30            }
31        }
32        return -1;
33    }
34};