class Solution {
public:
    int majorityElement(vector<int>& nums) {

        size_t amount{nums.size() / 2 };

        unordered_map<int, int> num_freq{};

        for (const auto& num : nums) {

            num_freq[num] = num_freq[num] + 1;
            
            if (num_freq[num] > amount) return num;

        }

        return {0};
        
    }
};