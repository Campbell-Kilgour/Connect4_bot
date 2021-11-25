#include <iostream>

//this defines the size of the Connect4 Board
const int num_rows = 6;
const int num_colm = 7;

//declarations of methods
void printBoard(int *cl1, int *cl2, int *cl3, int *cl4, int *cl5, int *cl6, int *cl7);
void addMove(int playerInput, int *cl1, int *cl2, int *cl3, int *cl4, int *cl5, int *cl6, int *cl7);
int checkFall(int *colm);
int playerTurn();
bool checkWin(int *cl1, int *cl2, int *cl3, int *cl4, int *cl5, int *cl6, int *cl7);
void printMatrix(int matrix[][num_colm], int rows);

int main() {

    //Board Variable declarations
    int column1[6] = {0,0,0,0,0,0};
    int column2[6] = {0,0,0,0,0,0};
    int column3[6] = {0,0,0,0,0,0};
    int column4[6] = {0,0,0,0,0,0};
    int column5[6] = {0,0,0,0,0,0};
    int column6[6] = {0,0,0,0,0,0};
    int column7[6] = {0,0,0,0,0,0};

    int *cl1 = column1;
    int *cl2 = column2;
    int *cl3 = column3;
    int *cl4 = column4;
    int *cl5 = column5;
    int *cl6 = column6;
    int *cl7 = column7;

    //TODO: Make into 2D array for easy of use in checkWin function

    //Declares board array with all 0s
    int board[num_rows][num_colm];

    for(int row = 0; row < num_rows; row++){
        for(int elem = 0; elem < num_colm; elem++){
            board[row][elem] = 0;
        }
    }

    printMatrix(board, num_rows);

    /*bool win =  false;

    while(!win){
        bool player_turn = true;

        if(player_turn){

            std:: cout << "Player_1's turn..." << std:: endl;

            player_turn =  false;
        }else if(!player_turn){

            std::cout << "Player_2's turn..." << std::endl;

            player_turn =  true;
        }

        win = checkWin(cl1, cl2, cl3, cl4, cl5 ,cl6, cl7);
    }
*/
    //printBoard(cl1, cl2, cl3, cl4, cl5, cl6, cl7);

    //std::cout << playerTurn();

    return 0;
}

void printMatrix(int matrix[][num_colm], int rows){
    for(int col = 0; col < num_colm; col++){
        for(int row = 0; row < rows; row++){
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
}


//prints the Connect4 Board
void printBoard(int *cl1, int *cl2, int *cl3, int *cl4, int *cl5, int *cl6, int *cl7){

    std::cout << "1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7 " << std::endl;
    std::cout << "______________" << std::endl;

    //prints all element of an array
    for(int i = 0; i < 6; i++) {
        std::cout << cl1[i] << " " << cl2[i] << " " << cl3[i] << " " << cl4[i] << " " << cl5[i] << " " << cl6[i] << " " << cl7[i] << std::endl;
    }
}

//asks and takes an input from the player for their next move
int playerTurn(){
    int move;
    std::cout << "\nChoose your next move: \n1|2|3|4|5|6|7  \n";
    std::cin >> move;
    std::cout << std::endl;
    //turns the player input into a number that the array can use
    move--;
    return move;
}

void addMove(int playerInput, int player, int *cl1, int *cl2, int *cl3, int *cl4, int *cl5, int *cl6, int *cl7){

    if(player != 1 && player != 2){
        std::cout << "Player number out of bounds." << std::endl;
    }else{
        int pos;
        switch(playerInput){
            case 1:
                pos = checkFall(cl1);
                cl1[pos] = player;
                break;
            case 2:
                pos = checkFall(cl2);
                cl2[pos] = player;
                break;
            case 3:
                pos = checkFall(cl3);
                cl3[pos] = player;
                break;
            case 4:
                pos = checkFall(cl4);
                cl4[pos] = player;
                break;
            case 5:
                pos = checkFall(cl5);
                cl5[pos] = player;
                break;
            case 6:
                pos = checkFall(cl6);
                cl6[pos] = player;
                break;
            case 7:
                pos = checkFall(cl7);
                cl7[pos] = player;
                break;
            default:
                std::cout << "Player input out of bounds!" << std::endl;
        }
    }
}

//find which position the new move falls to
int checkFall(int *colm){
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

//check if the win condition is met, FALSE is not WIN, TRUE is WIN
bool checkWin(int *cl1, int *cl2, int *cl3, int *cl4, int *cl5, int *cl6, int *cl7){
    bool win = false;

    //TODO: Add win condition check

    /*
     *  {0,0,0
     *   0,A,0  Shape of array relative to the element in question (A)
     *   0,0,0}
     */
    int adjacent[8] = {0,0,0,0,0,0,0,0};




    return win;
}

