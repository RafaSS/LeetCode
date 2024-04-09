class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<float> AB;
        AB.reserve(nums1.size() + nums2.size());
        AB.insert(AB.end(), nums1.begin(), nums1.end());
        AB.insert(AB.end(), nums2.begin(), nums2.end());
        int size = AB.size();
        sort(AB.begin(), AB.end());
        if (size % 2 == 0) {
            return (AB[size / 2 - 1] + AB[size / 2]) / 2;
        } else {
            return AB[size / 2];
        }
    }
};