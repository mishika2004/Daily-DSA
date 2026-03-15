1class Solution {
2public:
3    bool isPossible(vector<int>& arr, int hours, int speed){
4            long long time=0;
5            for(int i=0;i<arr.size();i++){
6                time+=ceil((double)arr[i]/speed);
7            }
8            if(time<=hours) return true;
9            return false;
10    }
11    int minEatingSpeed(vector<int>& piles, int h) {
12        int n=*max_element(piles.begin(),piles.end());
13        int start =1;
14        int end=n;
15        int ans=0;
16        while(start<=end){
17            int mid=(start+end)/2;
18            if(isPossible(piles, h, mid)){
19                ans=mid;
20                end=mid-1;
21            }
22            else {
23                start=mid+1;
24            }
25        }
26        return ans;
27    }
28};