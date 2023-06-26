/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.*/

//Two solutions today: "The Molases Architect" and "The Sew-From-The-Hip Quilter"

//My first solution "The Molases Architect" was in the 27th percentie for speed and 45th percentile for memory.
//I decided to use a map because I wanted to track instances of a number.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, n, k;
        char c;
        map<char, int> m;

        //horizontal
        for (i = 0; i < 9; i++){
            for (j = 0; j < 9; j++){
                c = board[i][j];
                if (c != '.'){
                    m[c]++;
                    if (m[c] > 1) return false;
                }
            }
            m.clear();
        }

        //vertical
        for (i = 0; i < 9; i++){
            for (j = 0; j < 9; j++){
                c = board[j][i];
                if (c != '.'){
                    m[c]++;
                    if (m[c] > 1) return false;
                }
            }
            m.clear();
        }

        //cells
        for (i = 0; i <= 6; i+= 3){
            for (j = 0; j <= 6; j+= 3){
                for (n = i; n < i+3; n++){
                    for (k = j; k < j+3; k++){
                        c = board[n][k];
                        if (c != '.'){
                            m[c]++;
                            if (m[c] > 1) return false;
                        }
                    }
                }
                m.clear();
            }
        }
        return true;
    }
};

//My second solution "The Sew-From-The-Hip Quilter" was more algorithmic and saved time and memory, arguably less readable.
//It was 98th percentile for speed at 12 ms. and 62nd percentile for memory eficiency at 18 mb (top .4% used 17.7 mb).
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a[9][9] = {0}, b[9][9] = {0}, c[9][9] = {0};
        int i, j, k, n;
        char ch;
        for (i = 0; i < 9; i++){
            for (j = 0; j < 9; j++){
                ch = board[i][j];
                if (ch != '.'){
                    n = ch - '0' - 1;
                    k = i/3*3 + j/3;
                    if (a[i][n] || b[j][n] || c[k][n]) return false;
                    a[i][n] = b[j][n] = c[k][n] = 1; 
                }
            }
        }
        return true;
    }
};
