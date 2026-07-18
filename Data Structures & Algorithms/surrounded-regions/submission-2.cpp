class Solution {
public:
    bool isValid(int i,int j, int m, int n, vector<vector<char>>& board){
        if(i>=0 && i<m && j>=0 && j<n && board[i][j]=='O') return true;
        return false;
    }
    void dfs(int i,int j, int m, int n, vector<vector<char>>& board){
        board[i][j]='B';
        if(isValid(i+1,j,m,n,board)) dfs(i+1,j,m,n,board);
        if(isValid(i-1,j,m,n,board)) dfs(i-1,j,m,n,board);
        if(isValid(i,j+1,m,n,board)) dfs(i,j+1,m,n,board);
        if(isValid(i,j-1,m,n,board)) dfs(i,j-1,m,n,board);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            int j=0;
            if(board[i][j]=='O') dfs(i,j,m,n,board);
            j=n-1;
            if(board[i][j]=='O') dfs(i,j,m,n,board);
        }
        for(int j=0;j<n;j++){
            int i=0;
            if(board[i][j]=='O') dfs(i,j,m,n,board);
            i=m-1;
            if(board[i][j]=='O') dfs(i,j,m,n,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='B') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
