#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(target - nums[i]) != umap.end()) {
                int j = umap.at(target - nums[i]);
                if (i != j)
                    return {i, j};
            }
        }
        return {};
    }
};