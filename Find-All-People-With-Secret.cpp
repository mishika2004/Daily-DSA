1class Solution {
2public:
3     static bool comp(vector <int> &a, vector<int> &b){
4        return a[2]<b[2];
5   }
6      struct DSU{
7        vector<int> parent,rank;    
8         DSU(int n){
9        parent.resize(n);
10        rank.resize(n,0);
11        for(int i=0;i<n;i++)
12            parent[i]=i;
13    }      
14        int find(int x){
15            if(parent[x]==x){
16               return x;
17            }
18            return  parent[x]=find(parent[x]);
19        }
20
21        bool Union(int a, int b){
22            int pa=find(a);
23            int pb=find(b);
24            if(pa==pb) return false;
25            else if(rank[pa]>rank[pb]){
26                parent[pb]=pa;
27            }
28            else if(rank[pa]<rank[pb]){
29                parent[pa]=pb;
30            }
31            else{
32                parent[pb]=pa;
33                rank[pa]++;
34            }
35            return true;
36        }
37      };
38    
39    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
40        DSU dsu(n);
41        dsu.Union(0, firstPerson);
42        // parent.resize(n);
43        // rank.resize(n,0);
44        // for(int i=0;i<n;i++){
45        //     parent[i]=i;
46        // }
47        sort(meetings.begin(),meetings.end(),comp);
48        int i=0;
49        int m=meetings.size();
50        while(i<m){
51            int time=meetings[i][2];
52             vector<int> result;
53            int j=i;
54            while(j<m && meetings[j][2]==time){
55                int x=meetings[j][0];
56                int y=meetings[j][1];
57                dsu.Union(x,y);
58                result.push_back(x);
59                result.push_back(y);
60                j++;
61            }
62            for(auto &x:result){
63             if(dsu.find(x)!=dsu.find(0)){
64                dsu.parent[x]=x;
65             }
66            }
67            i=j;
68        }
69         vector<int> ans;
70
71            for(int i=0;i<n;i++){
72                if(dsu.find(i)==dsu.find(0)){
73                    ans.push_back(i);
74                }
75            }
76        
77        return ans;
78    }
79};