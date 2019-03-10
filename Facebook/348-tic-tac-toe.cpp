class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): rows(n,0), columns(n,0),diagonal(0),antidiagonal(0), size(n){
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        // cout << row << " " << col << " " << player << endl;
        int toAdd = player == 1 ? 1 : -1;
        
        rows[row] += toAdd;
        columns[col] += toAdd;
        if( row == col ) {
            diagonal += toAdd;
        }
        
        if( col == (size - row - 1)) {
            antidiagonal += toAdd;
        }
           
        
        if(abs(rows[row]) == size || 
           abs(columns[col]) == size ||
           abs(diagonal) == size||
           abs(antidiagonal) == size){
            return player;
        }
        return 0;
    }
    
    vector<int> rows;
    vector<int> columns;
    int diagonal;
    int antidiagonal;
    int size;
    
};