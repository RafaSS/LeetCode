class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        std::string solved = "123450";
        std::ostringstream start;
        for (const auto& row : board) {
            for (const auto& elem : row) {
                start << elem << "";
            }
        }
        std::unordered_map<int, std::vector<int>> neighbors = {
            {0, {1, 3}}, {1, {0, 2, 4}}, {2, {1, 5}},
            {3, {0, 4}}, {4, {1, 3, 5}}, {5, {2, 4}}};

        std::set<std::string> set;
        set.insert(start.str());
        std::queue<std::pair<std::string, int>> queue;
        queue.push({start.str(), 0});
        while (!queue.empty()) {
            std::pair<std::string, int> front = queue.front();
            std::string state = front.first;
            int moves = front.second;
            queue.pop();
            if (state == solved) {
                return moves;
            }
            int zero_index = state.find('0');
            for (int neighbor : neighbors[zero_index]) {
                std::string temp = state;
                std::swap(temp[neighbor], temp[zero_index]);
                if (set.count(temp) == 0) {
                    queue.push({temp, moves + 1});
                    set.insert(temp);
                }
            }
        }
        return -1;
    }
};