class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> ump;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            ump[s[i]] = i;
        for (int i = 0; i < t.size(); i++)
            ans += abs(i - ump[t[i]]);
        return ans;
    }
};