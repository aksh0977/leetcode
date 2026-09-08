class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                    if(find(board,i,j,word,0)) return true;
            }
        }
        return false;
    }

    bool find(vector<vector<char>>& board, int i, int j, string word, int curr){
        if(curr == word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        if(i < 0 || j < 0 ||
            i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[curr]){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            find(board, i + 1, j, word, curr + 1) ||
            find(board, i - 1, j, word, curr + 1) ||
            find(board, i, j + 1, word, curr + 1) ||
            find(board, i, j - 1, word, curr + 1);

         board[i][j] = temp;

        return found;

    }
};