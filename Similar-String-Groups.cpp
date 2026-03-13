1class Solution {
2public:
3     vector<int> parent, rank;
4    int find(int x){
5       if(parent[x]==x) return x;
6        return parent[x]=find(parent[x]);
7    }
8
9    void Union(int a,int b){
10        int pa=find(a);
11        int pb=find(b);
12        if(pa==pb) return;
13
14        if(rank[pa]<rank[pb])
15            parent[pa]=pb;
16        else if(rank[pa]>rank[pb])
17            parent[pb]=pa;
18        else{
19            parent[pb]=pa;
20            rank[pa]++;
21        }
22    }
23    int numSimilarGroups(vector<string>& strs) {
24        int n=strs.size();
25        parent.resize(n);
26        rank.resize(n,0);
27        for(int i=0;i<n;i++) parent[i]=i;
28
29        for(int i=0;i<n;i++){
30            for(int j=i+1;j<n;j++){
31                int diff=0;
32
33                for(int k=0;k<strs[i].size();k++){
34                    if(strs[i][k] != strs[j][k]){
35                        diff++;
36                        if(diff > 2) break;
37                    }
38                }
39                  if(diff==0 || diff==2){
40                    Union(i,j);
41                }
42            }
43        }
44         int groups=0;
45        for(int i=0;i<n;i++){
46            if(find(i)==i) groups++;
47        }
48        return groups;
49    }
50};