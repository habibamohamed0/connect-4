
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
srand(time(0));//seed the rand function


// Play again loop
char playAgain = 'y';

while(playAgain == 'y' || playAgain == 'Y') {

//welcome message:
cout<<endl;
cout<<"============================================="<<endl;
cout<<"===== WELCOME TO OUR CONNECT 4 GAME! ======"<<endl;
cout<<"============================================="<<endl;
cout<<endl;

// choose mode
int mode;
cout<<"Choose mode:"<<endl;
cout<<"1. Player vs Player"<<endl;
cout<<"2. Player vs Computer"<<endl;
cout<<"Enter choice: (1 or 2)";
cin>>mode;


string player1,player2;
//players names input:
 if(mode == 1) {//pvp
cout<<"Enter player 1 name: ";
cin>>player1;
cout<<"Enter player 2 name: ";
cin>>player2;
} else {//if player vs computer assign player 2 to be the computer
cout<<"Enter your name: ";
cin>>player1;
player2 = "Computer";
}

//assign symbols
cout << player1 << " will be X" << endl;
cout << player2 << " will be O" << endl;
cout << endl;


char player ='X';
int turns=0; //count turns to determine draw
bool gameWon = false;


//board grid(6x7):
char board[6][7];
for (int i= 0 ; i<6 ; i++){
for(int j = 0 ; j<7 ; j++){
board[i][j] ={' '};}}

// game loop
while (!gameWon && turns < 42) {

// Add spacing for better visuals
cout<<endl<<endl<<endl;

//numbering the board
for (int i = 1;i<=7; i++){
cout<<"  "<<i<<"   ";}
cout<<endl;

// Top border line
for(int i=0; i<7; i++){
cout<<"+-----";}
cout<<"+"<<endl;


//board
for (int i= 0 ; i<6 ; i++){// repeats the procces 6 times (for rows)

for(int j = 0 ; j<7 ; j++){ //1 row with pieces
cout<<"|  "<<board[i][j]<<"  ";}
cout<<"|"<<endl; //1 extra for outline

for(int k=0; k<7; k++)//after each row print another horizontal line
cout<<"+-----";
cout<<"+"<<endl;// 1 extra for outline
}
cout<<endl;//space


int choice;
if(mode == 2 && player == 'O') {//computers turn
cout<<player2<<"'s turn (O): "<<endl;
do {
choice = (rand() % 7) + 1;   // random column 1–7
} while(board[0][choice-1] != ' '); // retry if column full
cout<<"Computer chooses column "<<choice<<endl;
} else {

//pvp mode
if(player == 'X')
cout<<player1<<"'s turn (X): "<<endl;
else
cout<<player2<<"'s turn (O): "<<endl;

// fixing wrong inputs
string input; // to accept both integers and letters
cout << "Choose a column from 1-7: ";
cin >> input;
if (input.size() != 1 || input[0] < '1' || input[0] > '7') {
    cout << "Wrong input! Choose a column from (1-7)" << endl;//only accepts single digits
    continue;
}

choice = input[0] - '0';//to make the computer see the number as a number
}

// input validation
int result = choice-1;// to fit array syntax
bool place =false; // place false means empty space
int row = -1;
for(int r =5; r>=0; r--){ //starts with row 5 first (lowest row)
if (board[r][result]== ' '){
board [r][result]=player;
place= true;
row = r; //removes last row because its not empty anymore
break;//when piece is placed in the lowest row the loop stops
    }
}

// column full retry without switching players
if(!place){
cout << "Column full! Try another."<<endl;
continue; //If the column is full skips the rest of the loop and lets the player try another column.

}

// check for wins (only after successfully placing a piece to be able to see all 4 pieces)(error 2)
// Horizontal win(row is constant and column changes)
int r = row;
int c = result;
int count = 0;
int cc = 0;
do {
if (board[r][cc] == player) {
++count;
if (count >= 4) {
gameWon = true;
break;//the loop stops. stop scanning
}
} else {
count = 0;
}
++cc;// checks all columns
} while (cc < 7);

// Vertical win (column is constant and row changes)
if(!gameWon) {
count = 0;
int rr = 0;
do {
if (board[rr][c] == player) {
++count;
if (count >= 4) {
gameWon = true;
break;//the loop stops. stop scanning
}
} else {
count = 0;
}
++rr;
} while (rr < 6);
}

// Diagonal win
if(!gameWon) {
count = 0;
int i = r, j = c;
// step to the top-left end
while (i > 0 && j > 0) { --i; --j; }
do {
if (board[i][j] == player) {
++count;
if (count >= 4) {
gameWon = true;
break;//the loop stops. stop scanning
}
} else {
count = 0;
}
++i; ++j;
} while (i < 6 && j < 7);
}

//other diagonal win
if(!gameWon) {
count = 0;
int i = r, j = c;
// step to the bottom-left end
while (i < 5 && j > 0) { ++i; --j; }
do {
if (board[i][j] == player) {
++count;
if (count >= 4) {
gameWon = true;
break;//the loop stops. stop scanning
}
} else {
count = 0;
}
--i; ++j;
} while (i >= 0 && j < 7);
}

// when someone wins display final board
if(gameWon) {
cout<<endl<<endl;
for (int i = 1;i<=7; i++)
cout<<"  "<<i<<"   ";
cout<<endl;

for(int i=0; i<7; i++)
cout<<"+-----";
cout<<"+"<<endl;

for (int i= 0 ; i<6 ; i++){
for(int j = 0 ; j<7 ; j++){
cout<<"|  "<<board[i][j]<<"  ";}
cout<<"|"<<endl;

for(int k=0; k<7; k++)
cout<<"+-----";
cout<<"+"<<endl;
    }
cout<<endl;
cout<<"============================================="<<endl;
if(player == 'X') {
cout<<"          "<<player1<<" (X) WINS!"<<endl;
    }
else {
cout<<"          "<<player2<<" (O) WINS!"<<endl;
    }
cout<<"============================================="<<endl;
}

// count the move to check for draw, displays board
if(!gameWon) {
turns++;
if(turns == 42){
cout<<endl<<endl;

for (int i = 1;i<=7; i++)
cout<<"  "<<i<<"   ";
cout<<endl;

for(int i=0; i<7; i++)
cout<<"+-----";
cout<<"+"<<endl;

for (int i= 0 ; i<6 ; i++){
for(int j = 0 ; j<7 ; j++){
cout<<"|  "<<board[i][j]<<"  ";}
cout<<"|"<<endl;

for(int k=0; k<7; k++)
cout<<"+-----";
cout<<"+"<<endl;
}
cout<<endl;
cout<<"============================================="<<endl;
cout<<"              IT'S A DRAW!                  "<<endl;
cout<<"============================================="<<endl;
}

// switch players
if (player=='X'){
player='O';
}
else{
player ='X';
}
}

} // end of game loop

// Play again
cout<<endl;
cout<<"Play again? (y/n): ";
cin>>playAgain;

} // end of play again loop

cout<<endl;
cout<<"Thanks for playing!"<<endl;

    return 0;
}
