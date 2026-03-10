1class Solution {
2public:
3    vector<int> parent;
4    int find(int x){
5        if(parent[x]==x) return x;
6        return parent[x]=find(parent[x]);
7    }
8
9    void Union(int a,int b){
10        int pa=find(a);
11        int pb= find(b);
12        if(pa==pb) return;
13        parent[pa]=pb;
14    }
15    int removeStones(vector<vector<int>>& stones) {
16        int n=stones.size();
17        int components=0;
18        parent.resize(n);
19        for(int i=0;i<parent.size();i++){
20            parent[i]=i;
21        }
22
23        for(int i=0;i<n;i++){
24            for(int j=i+1;j<n;j++){
25                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
26                    Union(i,j);
27                }
28            }
29        }
30        for(int i=0;i<n;i++){
31            if(find(i)==i)
32              components++;
33        }
34        return n-components;
35    }
36};