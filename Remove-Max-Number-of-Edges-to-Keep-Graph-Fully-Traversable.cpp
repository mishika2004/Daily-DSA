1class Solution {
2public:
3    
4struct DSU{
5    vector<int> parent;
6    vector<int> rank;
7
8    int findParent(int x){
9        if(parent[x]==x) return x;
10        return parent[x]=findParent(parent[x]);
11    }
12     
13    DSU(int n){
14        parent.resize(n);
15        rank.resize(n,0);
16        for(int i=0;i<n;i++){
17            parent[i]=i;
18        }
19    }
20
21    bool Union(int a,int b){
22        int pa=findParent(a);
23        int pb=findParent(b);
24        if(pa==pb) return false;
25        else if(rank[pa]>rank[pb]){
26            parent[pb]=pa;
27        }
28        else if(rank[pa]<rank[pb]){
29            parent[pa]=pb;
30        }
31        else{
32            parent[pb]=pa;
33            rank[pa]++;
34        }
35        return true;
36    }
37};
38    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
39        DSU dsuAlice(n+1), dsuBob(n+1);
40        int redundantEdges=0;
41        int aliceEdges=0;
42        int bobEdges=0;
43        for(auto &e: edges){
44            if(e[0]==3){
45                int n1=e[1];
46                int n2=e[2];
47                if(dsuAlice.findParent(n1) != dsuAlice.findParent(n2) ||
48                    dsuBob.findParent(n1) != dsuBob.findParent(n2)){
49                        dsuAlice.Union(n1,n2);
50                        dsuBob.Union(n1,n2);
51                        aliceEdges++;
52                        bobEdges++;
53                    }
54                else {
55                    redundantEdges++;
56                }
57            }
58        }
59
60        for(auto &e: edges){
61            int n1=e[1];
62            int n2=e[2];
63            if(e[0]==1){
64                if(dsuAlice.findParent(n1)!=dsuAlice.findParent(n2)){
65                    dsuAlice.Union(n1,n2);
66                    aliceEdges++;
67                }
68                 else{
69                    redundantEdges++;
70                 }
71            }
72            else if(e[0]==2){
73                if(dsuBob.findParent(n1)!=dsuBob.findParent(n2)){
74                    dsuBob.Union(n1,n2);
75                    bobEdges++;
76                }
77                else{
78                    redundantEdges++;
79                }
80            }
81        }
82        return (aliceEdges==n-1) && (bobEdges==n-1) ? redundantEdges:-1;
83    }
84};