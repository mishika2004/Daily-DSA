1class Solution {
2public:
3    bool isPossible(vector<int>& bloomDay, int m, int k, int day){
4        int n=bloomDay.size();
5        int bouquets=0;
6        int count=0;
7        for(int i=0;i<n;i++){
8            if(bloomDay[i]<=day){
9                count++;
10
11                if(count==k){
12                bouquets++;
13                count=0;
14            }
15        } 
16        else count=0;
17        }
18        if(bouquets>=m) return true;
19        else return false;
20    }
21    int minDays(vector<int>& bloomDay, int m, int k) {
22        int n=bloomDay.size();
23        int start = *min_element(bloomDay.begin(),bloomDay.end());
24        int end = *max_element(bloomDay.begin(),bloomDay.end());
25        int ans=0;
26        if(m > bloomDay.size()/k) return -1;
27        while(start<=end){
28            int mid = start + (end - start)/2;
29            if(isPossible(bloomDay, m, k, mid)){
30                ans=mid;
31                end=mid-1;
32            }
33            else{
34                start=mid+1;
35            }
36        }
37        return start;
38    }
39};