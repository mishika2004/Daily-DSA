1class Solution {
2public:
3    int islandPerimeter(vector<vector<int>>& grid) {
4        int perimeter=0;
5        int n=grid.size();
6        int m=grid[0].size();
7        for(int i=0;i<n;i++){
8            for(int j=0;j<m;j++){
9                if(grid[i][j]==1){
10                     if(i == 0 || grid[i-1][j] == 0)
11                        perimeter++;
12
13                  
14                    if(i == n-1 || grid[i+1][j] == 0)
15                        perimeter++;
16
17               
18                    if(j == 0 || grid[i][j-1] == 0)
19                        perimeter++;
20
21           
22                    if(j == m-1 || grid[i][j+1] == 0)
23                        perimeter++;
24                }
25            }
26        }
27        return perimeter;
28    }
29};