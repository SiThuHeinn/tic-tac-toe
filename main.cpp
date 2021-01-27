#include <iostream>


using namespace std;


char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char current_marker;
int current_player;

void play();
void restartGame();

void drawBoard() {

    cout << " ""      |     " << "      |     " <<endl;
    cout << " " << board[0][0] << "     |     " << board[0][1] << "     |     " << board[0][2] <<endl;
    cout << " ""      |     " << "      |     " <<endl;
    cout << "-----------------------------\n";
    cout << " ""      |     " << "      |     " <<endl;
    cout << " " << board[1][0] << "     |     " << board[1][1] << "     |     " << board[1][2] <<endl;
    cout << " ""      |     " << "      |     " <<endl;
    cout << "-----------------------------\n";
    cout << " ""      |     " << "      |     " <<endl;
    cout << " " << board[2][0] << "     |     " << board[2][1] << "     |     " << board[2][2] <<endl;
    cout << " ""      |     " << "      |     " <<endl;

}

bool placeMarker(int slot)
{

        int row = slot / 3;
        int col;

        if (slot % 3 == 0) {
            row = row - 1;
            col = 2;
        } else {
            col = (slot % 3) - 1;
        }


        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = current_marker;
            return true;
        } else
            return false;


}

int winner()
{
    for (int i = 0; i < 3 ; i++){

        //rows
        if(board[i][0] == board[i][1] && board[i][1]  == board[i][2]) return current_player;

        //columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;

        //diagonal
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) return current_player;


    }

    return 0;
}

void switch_player_marker()
{
    if(current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if (current_player == 1) current_player = 2;
    else current_player = 1;
}

void clearGameBoard(){
     for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; ++j) {

            if( i == 0 && j == 0){
                board[0][0] = '1';
            }else if( i == 0 && j == 1 ){
                board[0][1] = '2';
            }else if(i == 0 && j == 2){
                board[0][2] = '3';
            }else if( i == 1 && j == 0){
                board[1][0] = '4';
            }else if( i == 1 && j == 1){
                board[1][1] = '5';
            }else if ( i == 1 && j == 2){
                board[1][2] = '6';
            }else if ( i == 2 && j == 0){
                board[2][0] = '7';
            }else if (i ==2 && j == 1){
                board[2][1] = '8';
            }else if(i == 2 && j == 2){
                board[2][2] = '9';
            }
        }
    }
}


void play()
{
    cout << "Player One, Choose your marker ..."<<endl;
    char marker;
    cin >> marker;

    current_player = 1;
    current_marker = marker;
    drawBoard();

    int player_won;

    for(int i = 0; i < 9 ; i++){
        cout << "It's Player " << current_player << "'s turn. Enter your slot ...";

        int slot;
        cin >> slot;


        if(slot < 1 || slot > 9){
            cout << "Invalid Slot!"<<endl;
            i--;
            continue;
        }

        if(!placeMarker(slot)){
            cout << "That Slot has been taken! Please Try another slot!"<<endl;
            i--;
            continue;
        }
        drawBoard();

        player_won = winner();

        if(player_won == 1) {
            cout << "Yay... Player One Won! Congratulations!... "<<endl;
            restartGame();
            break;
        }
        if(player_won == 2) {
            cout << "Yay... Player Two Won! Congratulations!... "<<endl;
            restartGame();
            break;
        }

        switch_player_marker();
    }

    if(player_won == 0 ){
        cout << "It's Draw! ";
        restartGame();
    }


}


void restartGame() {
    cout << "Restart the game (y/n)?"<<endl;
    char nextGame;
    cin >> nextGame;

    if(nextGame == 'y'){
        clearGameBoard();
        play();
    }else{
        exit(0);
    }
}

int main()
{
    play();
    return 0;
}
