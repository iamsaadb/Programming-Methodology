#include <iostream>
#include <iomanip>
#include<cstdlib>

using namespace std;

//display grid
void displayBoard(char tab[3][3] ){
for (int i=0; i<3; i++){
    cout << "-------------\n";
        cout << "| " << tab[i][0] << " | " << tab[i][1] << " | " << tab[i][2] << " |" <<  endl;
}
cout << "-------------\n";
}
//prompt a move
void makeAMove(char tab[3][3], char x){
int a,b = 0;
cout << "Enter a row for player " << x << endl;
cin >> a;
cout << "Enter a column for player " << x << endl;
cin >> b;

while(tab[a][b]!=' '){
    cout << "This cell is already occupied. Try a different cell" << endl;
    cout << "Enter a row for player " << x << endl;
    cin >> a;
    cout << "Enter a column for player " << x << endl;
    cin >> b;
}
tab[a][b] = x;
}


//checkRows, checkCols and checkDiag all are methods used by isWon to check if they is a winning combination
bool checkRows(char X, char tab[3][3]){
//check rows
    bool win = false;
    int count = 0;
    for (int i = 0; i<3; i++){
        if (tab[i][0]==tab[i][1] && tab[i][1]==tab[i][2] && tab[i][2]==X){ count ++;}
        if (count == 1) {win = true; break;}
        }
       return win;
}
bool checkCols(char X, char tab[3][3]){
bool win = false;
    int count = 0;
    for (int i = 0; i<3; i++){
        if (tab[0][i]==tab[1][i] && tab[1][i]==tab[2][i] && tab[2][i]==X){ count ++;}
        if (count == 1) {win = true; break;}
        }
       return win;
}
bool checkDiag(char X, char tab[3][3]){
bool win = false;
int count = 0;
if ((tab[0][0] == tab [1][1] && tab [1][1] == tab [2][2] && tab [2][2] == X) ||
    (tab[0][2] == tab [1][1] && tab [1][1] == tab [2][0] && tab [2][0] == X))
{ win = true;

}
return win;
}
//check if the player wins
bool isWon(char X, char tab[3][3]){
    return checkCols(X,tab) || checkRows(X,tab) || checkDiag(X,tab);
    }
//no win, full grid
bool isDraw(char tab[3][3]){
int count = 0;
for (int i=0;i<3;i++){
    for (int j=0; j<3; j++){
        if(tab[i][j]!= ' '){
            count++;
        }
    }
}
if (count == 9){return true;}
else {return false;}
}

//main function
int main() {
	//
	//	PLEASE DO NOT CHANGE main()
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}
