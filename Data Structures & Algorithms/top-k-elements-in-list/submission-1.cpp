class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<vector<int>> ans(nums.size() + 1);
        unordered_map<int, int> counts{};


        for (const auto& n : nums) {
            counts[n] = 1 + counts[n];
        }

        for (const auto& [key, value] : counts) {

            ans[value].push_back(key);

        }

        vector<int> res{};
        for (size_t i {ans.size() - 1 }; i >= 0; i--) {

            for (const auto& n : ans[i]) {
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }

        return {0};
    }
};
