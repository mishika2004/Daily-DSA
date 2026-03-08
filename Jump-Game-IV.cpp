1class Solution {
2public:
3    int minJumps(vector<int>& arr) {
4        
5        int n = arr.size();
6        if(n <= 1) return 0;
7
8        unordered_map<int, vector<int>> mp;
9
10        for(int i = 0; i < n; i++){
11            mp[arr[i]].push_back(i);
12        }
13
14        queue<int> q;
15        vector<bool> vis(n,false);
16
17        q.push(0);
18        vis[0] = true;
19
20        int steps = 0;
21
22        while(!q.empty()){
23
24            int size = q.size();
25
26            while(size--){
27
28                int i = q.front();
29                q.pop();
30
31                if(i == n-1) return steps;
32
33                if(i+1 < n && !vis[i+1]){
34                    vis[i+1] = true;
35                    q.push(i+1);
36                }
37
38                if(i-1 >= 0 && !vis[i-1]){
39                    vis[i-1] = true;
40                    q.push(i-1);
41                }
42
43                for(int j : mp[arr[i]]){
44                    if(!vis[j]){
45                        vis[j] = true;
46                        q.push(j);
47                    }
48                }
49
50                mp[arr[i]].clear();  
51            }
52
53            steps++;
54        }
55
56        return -1;
57    }
58};