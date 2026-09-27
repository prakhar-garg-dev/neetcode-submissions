class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9); 
        vector<unordered_set<char>> grids(9);
        int r=board.size();
        int c=board[0].size();

        // For checking the seen elements in a row.
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if (board[i][j]=='.')
                    continue;
                if (rows[i].count(board[i][j])>0){
                    return false;
                }
                rows[i].insert(board[i][j]);
                if (cols[j].count(board[i][j])>0){
                    return false;
                }
                cols[j].insert(board[i][j]);
                int rowGridIndex=i/3;
                int colGridIndex=j/3;
                // This calculation depends on how you are traversing the grid if you are traversing the sudoku row wise then this would be the formula otherwise it would be 
                // int gridIndex=(colGridIndex/3)*3+rowGridIndex;
                int gridIndex=(rowGridIndex)*3+colGridIndex;
                if (grids[gridIndex].count(board[i][j])>0){
                    return false;
                }
                grids[gridIndex].insert(board[i][j]);
            }
        }
        
        return true;
    }
};