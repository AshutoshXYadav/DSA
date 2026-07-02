class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int> mpp;
      stack<int> st;
      vector<int> ans;
      for(int nums:nums2){
        while(!st.empty() && nums> st.top()){
            mpp[st.top()]= nums;
            st.pop();
        }
        st.push(nums);
      }  
      while(!st.empty()){
        mpp[st.top()] = -1;
        st.pop();
      }
      for(int num: nums1){
        ans.push_back(mpp[num]);
      }
      return ans;
    }
};