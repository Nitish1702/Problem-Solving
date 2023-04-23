class Solution {
public:
    bool check(vector<vector<char>>& board,int i,int j,int q,string word){
        int m=board.size(),n=board[0].size();
        if (q==word.length())return true;
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] != word[q]) return false;
        q++;
        auto temp = board[i][j];
        board[i][j] = '.';
        if (check(board,i+1,j,q,word)) return true;
        if (check(board,i,j+1,q,word)) return true;
        if (check(board,i-1,j,q,word)) return true;
        if (check(board,i,j-1,q,word)) return true;
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int c=0,n=board.size(),m=board[0].size();
        if(c==word.length())return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(check(board,i,j,0,word)){
                        return true;
                    }
                }
            }

        }
        return false;
    }
};
