class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxs[9];

        for(int r=0;r<board.size();r++){
            for(int c=0;c<board.size();c++){
                char cell = board[r][c];
                int boxInd = 3*(r/3)+(c/3);
                if(cell == '.') continue;
                if(rows[r].count(cell)) return false;
                    rows[r].insert(cell);

                if(cols[c].count(cell)) return false;
                    cols[c].insert(cell);

                if(boxs[boxInd].count(cell)) return false;
                    boxs[boxInd].insert(cell);
            }
        }
        return true;
    }
};