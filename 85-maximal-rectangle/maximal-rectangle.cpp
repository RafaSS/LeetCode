class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols + 1, 0);
    int max_area = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1')
                heights[j] += 1;
            else
                heights[j] = 0;
        }

        stack<int> s;
        for (int j = 0; j < cols + 1; ++j) {
            while (!s.empty() && heights[j] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? j : j - s.top() - 1;
                max_area = max(max_area, h * w);
            }
            s.push(j);
        }
    }

    return max_area;
}
};