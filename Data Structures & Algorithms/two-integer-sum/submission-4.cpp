class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> difference_index{};

        for (int i = 0; i < nums.size(); ++i) {

            if (difference_index.contains(target-nums[i])) {
                
                int index = difference_index[target-nums[i]];
                return { index, i };
            }

            difference_index[nums[i]] = i;

        }

        return { 0 };
        
    }
};
