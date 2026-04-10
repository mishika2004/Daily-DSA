1class Solution {
2public:
3    void solve(int i, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp){
4        if(i==nums.size()) {
5            ans.push_back(temp);
6            return;
7        }
8        solve(i+1, nums, ans, temp);
9        temp.push_back(nums[i]);
10        solve(i+1, nums, ans, temp);
11        temp.pop_back();
12    }
13    vector<vector<int>> subsets(vector<int>& nums) {
14        vector<vector<int>> answer;
15        vector<int> temp;
16        solve(0,nums,answer,temp);
17        return answer;
18    }
19};