1class Solution {
2public:
3    bool isPossible(vector<int> weights, int days, int capacity){
4        int currdays=1;
5        int load=0;//curr ship load
6        for(int i=0;i<weights.size();i++){
7            if(load+weights[i]>capacity){  // load+weights[i]--> current ship load only weights[i] will check just single package.
8                currdays++; //starting new day;
9                load=weights[i];//first package of new day
10            }
11            else{
12                load+=weights[i];
13            }
14          
15        }
16        if(currdays<=days) return true;
17        else return false;
18    }
19    int shipWithinDays(vector<int>& weights, int days) {
20        int n=weights.size();
21        int sum=0;
22        int ans=0;
23        int start=*max_element(weights.begin(),weights.end());
24        for(int i=0;i<n;i++){
25            sum+=weights[i];
26        }
27        int end=sum;
28
29        while(start<=end){
30            int mid=(start+end)/2;
31            if(isPossible(weights, days, mid)){
32                ans=mid;
33                end=mid-1;
34            }
35            else start=mid+1;
36        }
37        return ans;
38    }
39};