
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> dirs = {
            {0, {0, 1}}, {1, {0, -1}}, {2, {1, 0}}, {3, {-1, 0}}};
        int m = grid.size(), n = grid[0].size();
        deque<tuple<int, int, int>> q;
        set<pair<int, int>> visited;

        visited.insert({0, 0});

        q.push_front(make_tuple(0, 0, 0));
        while (!q.empty()) {
            auto [x, y, steps] = q.front();
            q.pop_front();
            if (x == m - 1 && y == n - 1) {
                return steps;
            }
            for (int i = 0; i < 4; i++) {
                int dx = dirs[i][0], dy = dirs[i][1];
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (grid[nx][ny] == 0 &&
                    visited.find({nx, ny}) == visited.end()) {
                    visited.insert({nx, ny});
                    q.push_front(make_tuple(nx, ny, steps));
                } else if (grid[nx][ny] == 1 &&
                           visited.find({nx, ny}) == visited.end()) {
                    visited.insert({nx, ny});
                    q.push_back(make_tuple(nx, ny, steps + 1));
                }
            }
        }
        return -1;
    }
};