class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int count = 0;
        // std::vector<int> biggest(k, -10000000);
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] >= biggest[i % k]) {
        //         biggest[i % k] = nums[i];
        //         std::cout << biggest[i % k];
        //         std::cout << i % k;
        //         std::cout << "\n";
        //     }
        // }
        std::sort(nums.begin(), nums.end());
        // for (int i = 0; i < biggest.size(); i++) {
            
        // }
        return nums[nums.size()-k];
    }
};