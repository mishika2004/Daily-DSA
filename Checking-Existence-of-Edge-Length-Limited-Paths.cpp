1class Solution {
2public:
3static bool comp(vector <int> &a, vector<int> &b){
4    return a[2]<b[2];
5   }
6vector<int> parent, rank;
7 int find(int x){
8    if(parent[x]==x) return x;
9    return parent[x]=find(parent[x]);
10 }
11 void Unite(int a, int b){
12        a = find(a);
13        b = find(b);
14
15        if(a == b) return;
16        if(rank[a] > rank[b])
17            parent[b] = a;
18        else if(rank[a] < rank[b])
19            parent[a] = b;
20        else{
21            parent[b] = a;
22            rank[a]++;
23        }
24    }
25    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
26        vector<vector<int>> q;
27        vector<bool> ans(queries.size());
28        parent.resize(n);
29        rank.resize(n,0);
30        for(int i=0;i<n;i++) 
31          parent[i]=i;
32
33        sort(edgeList.begin(),edgeList.end(),comp);
34        
35
36        int j=0;
37        for(int i=0;i<queries.size();i++){
38            q.push_back({
39                queries[i][0],
40                queries[i][1],
41                queries[i][2],i
42            });
43        }
44        sort(q.begin(),q.end(),comp);
45        
46        for(auto &query:q){
47            int u = query[0];
48            int v = query[1];
49            int limit = query[2];
50            int idx = query[3];
51            while(j < edgeList.size() &&edgeList[j][2] <limit){
52                Unite(edgeList[j][0], edgeList[j][1]);
53                j++;
54          }
55          ans[idx]=(find(u) == find(v));
56        }
57        
58        
59        return ans;
60    }
61};