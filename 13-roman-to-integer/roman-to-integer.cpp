class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};

        int numb = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if(m[s[i]] >= m[s[i+1]]){
                numb = numb + m[s[i]];
                cout << s[i]<<'\n';
            }else{
                numb = numb + (m[s[i+1]] - m[s[i]]);
                cout << numb<<'\n';
                i++;
            }
        }

        return numb;
    }
};