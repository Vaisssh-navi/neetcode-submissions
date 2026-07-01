class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for(int i=0;i<9;i++){
        //     set<int> st,ts;
        //     for(int j=0;j<9;j++){
        //         if(board[i][j] != '.'){
        //         if(st.count(board[i][j])) return false;
        //         st.insert(board[i][j]);
        //         }
        //         if(board[j][i] != '.'){
        //         if(ts.count(board[j][i])) return false;
        //         ts.insert(board[j][i]);}
        //     }
        // }
        // for(int i=0;i<9;i=i+3){
        //     for(int j=0;j<9;j=j+3){
        //         set<int> s;
        //         for(int k=i;k<i+3;k++){
        //            for(int l=j;l<j+3;l++){
        //                 if(board[k][l] != '.'){
        //                 if(s.count(board[k][l])) return false;
        //                 s.insert(board[k][l]);}
        //             }
        //         }
        //     }
        // }
        // return true;


        bool rows[9][9]={}; // rows[i][d] digit d in i row
        bool cols[9][9]={}; // cols[d][j] digit d in i col
        bool boxes[9][9]={}; // boxes [box][d] digit d in which box
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'1';
                int box= (i/3)*3 + (j/3); // get the box by i,j idx
                if(rows[i][num] || cols[num][j] || boxes[box][num]){
                    return false;
                }
                rows[i][num]=true;
                cols[num][j]=true;
                boxes[box][num]=true;
            }
        }
        return true;
    }
};
