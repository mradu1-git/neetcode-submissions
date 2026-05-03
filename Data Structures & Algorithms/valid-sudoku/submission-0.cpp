class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= board.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    if (mp.find(board[i][j]) != mp.end()) {
                        return false;
                    } else {
                        mp[board[i][j]]++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j= 0; j < n; j++) {
                if (board[j][i] != '.') {
                    if (mp.find(board[j][i]) != mp.end()) {
                        return false;
                    } else {
                        mp[board[j][i]]++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j= 0; j < n; j++) {
                int row = (i / 3) * 3 + (j / 3);
                int col = (i % 3) * 3 + (j % 3);
                if (board[row][col] != '.') {
                    if (mp.find(board[row][col]) != mp.end()) {
                        return false;
                    } else {
                        mp[board[row][col]]++;
                    }
                }
            }
        }
        return true;
    }
};