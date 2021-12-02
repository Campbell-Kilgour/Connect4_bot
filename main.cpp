#include <iostream>

//this defines the size of the Connect4 Board
const int num_rows = 6;
const int num_colm = 7;

//declarations of methods
void printBoard(int (*pBoard)[num_rows][num_colm]);
void addMove(int playerInput, int *cl1, int *cl2, int *cl3, int *cl4, int *cl5, int *cl6, int *cl7);
int checkFall(int *colm);
int playerTurn();
void printMatrix(int matrix[][num_colm], int rows);
int getDir(int orow, int ocol, int crow, int ccol);

int main() {

    //Declares board array with all 0s
    int board[num_rows][num_colm];
    int count = 1; //DEBUG
    for(int row = 0; row < num_rows; row++){
        for(int elem = 0; elem < num_colm; elem++){
            board[row][elem] = count;
            count++; //DEBUG
        }
    }

    //declared the pointer to the Connect4 Board
    int  (*pBoard)[num_rows][num_colm] = &board;
    std::cout << *pBoard[2][0] << std::endl;

    printBoard(pBoard);
    std::cout << std::endl;
    printMatrix(board, num_rows);




    return 0;
}

void printBoard(int (*pBoard)[num_rows][num_colm]){
    std::cout << "1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7 " << std::endl;
    std::cout << "-------------" << std::endl;

    for(int row = 0 ; row < num_rows; row++){
        for(int col = 0; col < num_colm; col++){
            std::cout << *pBoard[row][col] << " ";
        }
        std::cout << std::endl;
    }

}


//prints the board
void printMatrix(int matrix[][num_colm], int rows){

    std::cout << "1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7 " << std::endl;
    std::cout << "-------------" << std::endl;

    for(int row = 0; row < rows; row++){
        for(int col = 0; col < num_colm; col++) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

//asks and takes an input from the player for their next move
int playerTurn(){
    int move;
    bool loop = true;

    while(loop) {
        std::cout << "\nChoose your next move: \n1|2|3|4|5|6|7  \n";
        std::cin >> move;
        std::cout << std::endl;
        //Checks if player inputted a valid column
        if (move < 1 || move > 7) {
            loop = true;
            std::cout << "Your move was out of bounds! Please try again." << std::endl;
        }else{
            loop = false;
        }
    }
    //turns the player input into a number that the array can use
    move--;
    return move;
}

/*void addMove(int playerInput, int player, int *board[][num_colm], int rows){
    //TODO: Remake for 2D array
    if(player != 1 && player != 2){
        std::cout << "ERROR: Player number out of bounds." << std::endl;
    }else{
        int pos;
        switch(playerInput){
            case 0:
                pos = checkFall(cl1);
                cl1[pos] = player;
                break;
            case 1:
                pos = checkFall(cl2);
                cl2[pos] = player;
                break;
            case 2:
                pos = checkFall(cl3);
                cl3[pos] = player;
                break;
            case 3:
                pos = checkFall(cl4);
                cl4[pos] = player;
                break;
            case 4:
                pos = checkFall(cl5);
                cl5[pos] = player;
                break;
            case 5:
                pos = checkFall(cl6);
                cl6[pos] = player;
                break;
            case 6:
                pos = checkFall(cl7);
                cl7[pos] = player;
                break;
            default:
                std::cout << "Player input out of bounds!" << std::endl;
        }
    }
}*/

//find which position the new move falls to
int checkFall(int *colm){
    //TODO: Fix for 2D Array
    int pos;
    bool flag = true;
    int i = 6;
    while(i >= 0 && flag){
        if(colm[i] != 1 && colm[i] != 2 && colm[i] == 0){
            pos = i;
            flag = false;
        }else{
            std::cout << "Error in value stored in board array" << std::endl;
        }
        i--;
    }
    return pos;
}

/*
bool checkWin(int board[][num_colm], int rows){

    //Check every element for adjacent comman 1 or 2 (only is !0)
    //Get direction of adjacent comman
    //Check element in the direction either side

    int row, col;

    int dir[2];

    int player = board[row][col];

    for(int checkrow = -1; checkrow < 2; checkrow++) {
        for (int checkcol = -1; checkcol < 2; checkcol++) {
            if (player == board[checkrow][checkcol]){
                //dir = getDir(row, col, checkrow, checkcol);
            }
        }
    }
}*/

/*void getDir(int orow, int ocol, int crow, int ccol, int *dir[]){

    if(crow < orow){
        if(ccol < ocol){
            dir = 1;
            dir[0] = -1;
            dir[1] = -1;
        }else if(ccol == ocol){
            dir = 2;
        }else if(ccol > ocol){
            dir = 3;
        }
    }else if(crow == orow){
        if(ccol < ocol){
            dir = 4;
        }else if(crow > ocol){
            dir = 5;
        }
    }else if (crow > orow){
        if(ccol < ocol){
            dir = 6;
        }else if(ccol == ocol){
            dir = 7;
        }else if(ccol > ocol){
            dir = 8;
        }
    }
}*/

