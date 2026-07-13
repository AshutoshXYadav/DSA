class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int min_dist = INT_MAX;
        
        for (int k = 0; k < n; k++) {
            mp[nums[k]].push_back(k);
            
            if (mp[nums[k]].size() >= 3) {
                int size = mp[nums[k]].size();
                int i = mp[nums[k]][size - 3];
                min_dist = min(min_dist, 2 * (k - i));
            }
        }
        
        return (min_dist == INT_MAX) ? -1 : min_dist;
    }
};