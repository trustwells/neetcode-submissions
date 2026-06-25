class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> groups{};
        
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            
            for (char c : s) {
                count[c - 'a']++;
            }
            string key{to_string(count[0])};
            for (size_t i{1}; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            groups[key].push_back(s);

        }

        vector<vector<string>> ans{};

        for (const auto& [key, vec_map] : groups) {
            ans.push_back(vec_map);
        }
        return ans;

    }
};
