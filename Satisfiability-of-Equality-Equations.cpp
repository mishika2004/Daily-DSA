1class Solution {
2public:
3    vector<int> parent;
4        int find(int x){
5            if(parent[x]==x){
6                return x;
7            }
8            return parent[x]=find(parent[x]);
9        }
10
11        void Union(int a, int b){
12            int pa=find(a);
13            int pb=find(b);
14            if(pa==pb) return;
15            parent[pa]=pb;
16        }
17    bool equationsPossible(vector<string>& equations) {
18        parent.resize(26);
19        for(int i=0;i<26;i++){
20            parent[i]=i;
21
22        }
23        for(auto eq:equations){
24            if(eq[1]=='='){
25                int a= eq[0]-'a';
26                int b=eq[3]-'a';
27                Union(a,b);
28            }
29        }
30        for(auto eq:equations){
31            if(eq[1]=='!'){
32                int a =eq[0]-'a';
33                int b=eq[3]-'a';
34
35                if(find(a)==find(b))
36                  return false;
37            }
38        }
39        return true;
40    }
41};