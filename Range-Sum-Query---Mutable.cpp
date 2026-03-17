1class NumArray {
2public:
3    vector<int> st;
4    int n;
5
6    NumArray(vector<int>& nums) {
7        n=nums.size();
8        st.resize(4*n);
9        buildTree(nums,0,0,n-1);
10    }
11
12    void buildTree(vector<int> &nums, int i, int lo, int hi){
13            if(lo==hi) {
14                st[i]=nums[lo];
15                return ;
16
17            }
18            int mid=lo+(hi-lo)/2;
19            buildTree(nums,2*i+1,lo,mid);
20            buildTree(nums,2*i+2,mid+1,hi);
21            st[i]=st[2*i+1]+st[2*i+2];
22    }
23    
24    void updateVal(int i, int lo, int hi, int index, int val){
25         if(lo==hi) {
26                st[i]=val;
27                return ;
28
29        }
30        int mid=lo+(hi-lo)/2;
31        if(index<=mid) updateVal(2*i+1,lo,mid,index,val);
32        else  updateVal(2*i+2,mid+1,hi,index,val);
33        st[i]=st[2*i+1]+st[2*i+2];
34    }
35    void update(int index, int val) {
36        //index-> for segment tree
37        //i-> for array
38        updateVal(0,0,n-1,index,val);
39    }
40    
41    int query(int index, int low, int high, int l, int r){
42        if(r<low || high<l) return 0;
43        if(l<=low && high<=r) return st[index];
44        int mid=(low+high)/2;
45        return query(2*index+1, low, mid, l, r)
46             + query(2*index+2, mid+1, high, l, r);
47    }
48
49    int sumRange(int left, int right) {
50           return query(0,0,n-1,left,right);
51    }
52};
53
54/**
55 * Your NumArray object will be instantiated and called as such:
56 * NumArray* obj = new NumArray(nums);
57 * obj->update(index,val);
58 * int param_2 = obj->sumRange(left,right);
59 */