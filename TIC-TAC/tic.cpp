#include<iostream>
#include<conio.h>
using namespace std;
const int cap = 100;
int computer = 0;
int human = 1;

void sleep(int k) {
	for (int i = 0; i < 1000 * k; i++) {

	}
}

void innit(char B[][100], int& Dim, char sym[cap], char Pname[][cap], int& Nop, int& Turn, int &WinC) {
	cout << "Enter the dimensions of the board:\n";
	cin >> Dim;
	for (int i = 0; i < Dim; i++) {
		for (int j = 0; j < Dim; j++) {
			B[i][j] = '-';
		}
	}
	cout << "Enter the number of players: \n";
	cin >> Nop;
	for (int i = 0; i < Nop; i++) {
		cout << "Enter Name: \n";
		cin >> Pname[i];
		cout << "Enter symbol: \n";
		cin >> sym[i];
	}
	cout << "Enter how many consecutive symbols to win? \n";
	cin >> WinC;
	Turn = rand() % Nop; 
}

void innit2(char B[][100], int& Dim, char sym[cap], string Pname[], int& Nop, int& Turn, int& WinC) {
	Nop = 2;
	cout << "Enter the dimensions of the board:\n";
	cin >> Dim;
	for (int i = 0; i < Dim; i++) {
		for (int j = 0; j < Dim; j++) {
			B[i][j] = '-';
		}
	}
	/*cout << "Enter the number of players: \n";
	cin >> Nop;*/
	
		cout << "Enter Name: \n";
		cin >> Pname[1];11
		cout << "Enter symbol: \n";
		cin >> sym[1];
		sym[0] = 'c';
		Pname[0] = "Computer";
	cout << "Enter how many consecutive symbols to win? \n";
	cin >> WinC;
	Turn = rand() % Nop;
}
void PrintBoard(char B[][cap], int Dim) {
	system("cls");
	for (int i = 0; i < Dim; i++) {
		for (int j = 0; j < Dim; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
}

void PlaceMove(char  B[][cap], int pr, int pc, int Dim, char sym) {
	B[pr][pc] = sym;
}
void SelectPos(int& pr, int& pc, int Dim) {
	cout << "\nEnter row: (1-" << Dim << "): ";
	cin >> pr;
	cout << "\nEnter column: (1-" << Dim << "): ";
	cin >> pc;
	pr--;
	pc--;
}

void TurnMsg(char N[cap]) {
	cout << N << "'s turn";
}
void TurnMsg2(string N) {
	cout << N << "'s turn";
}

void TurnChnage(int& Turn, int Nop) {
	Turn = (Turn + 1) % Nop;
}
bool IsValid(int pr, int pc, char B[][cap], int Dim) {
	/*if (pr > Dim || pc > Dim || pr < 1 || pc < 1) {
		return false;
	}*/
	if (B[pr][pc] != '-') {
		return false;
	}
	
	return true;
}
bool WinHor(char B[][cap], int Dim, char sym, int WinC, int row, int col) {
	if (col + WinC -1 >= Dim) {
		return false;
	}
	int c = 0;
	for (int i = 0; i < WinC; i++) {
		if (B[row][col + i] == sym) {
			c++;
		}
	}
	if (c == WinC) {
		return true;
	}
	else {
		return false;
	}
}
bool WinVer(char B[][cap], int Dim, char sym, int WinC, int row, int col) {
	if (row + WinC - 1 >= Dim) {
		return false;
	}
	int c = 0;
	for (int i = 0; i < WinC; i++) {
		if (B[row+i][col] == sym) {
			c++;
		}
	}
	if (c == WinC) {
		return true;
	}
	else {
		return false;
	}
}
bool WinDiag1(char B[][cap], int Dim, char sym, int WinC, int row, int col) {
	/*if (row + WinC  >= Dim || col + WinC >= Dim) {
		return false;
	}*/
	int count = 0;
	for (int i = 0; i < WinC; i++) {
		if (B[row + i][col + i] == sym) {
			count++;
		}
	}
	
	if (count == WinC) {
		return true;
	}
	else {
		return false;
	}
	

}
bool WinDiag2(char B[][cap], int Dim, char sym, int WinC, int row, int col) {
	/*if (row + WinC  >= Dim || col + WinC >= Dim) {
		return false;
	}*/
	int count = 0;
	for (int i = 0; i < WinC; i++) {
		if (B[row + i][col - i] == sym) {
			count++;
		}
	}
	if (count == WinC) {
		return true;
	}
	else {
		return false;
	}
}
bool Win(char B[][cap], int Dim, char sym, int WinC, int row, int col) {
	if (WinHor(B, Dim, sym, WinC, row, col)) {
		return true;
	}
	if (WinVer(B, Dim, sym, WinC, row, col)) {
		return true;
	} 
	if (WinDiag1(B, Dim, sym, WinC, row, col)) {
		return true;
	}
	if (WinDiag2(B, Dim, sym, WinC, row, col)) {
		return true;
	}
	return false;
}

bool IsWin(char B[][cap], int Dim, char Ps, int WinC) {
	for (int ri = 0; ri < Dim; ri++) {
		for (int ci = 0; ci < Dim; ci++) {
			if (Win(B , Dim, Ps, WinC, ri , ci)) {
				return true;
			}
		}
	}
	return false;
}
bool IsDraw(char B[][cap], int Dim) {
	int x = Dim * Dim;
	int count = 0;
	for (int ri = 0; ri < Dim; ri++) {
		for (int ci = 0; ci < Dim; ci++) {
			if (B[ri][ci] != '-') {
				count++;
			}
		}
	}
	if (count == x) {
		return true;
	}
	return false;
}
void CompMove(char B[][cap], int Dim, int &pr, int &pc, int WinC,char sym[cap]) {
	
		for (int ri = 0; ri < Dim; ri++) {
			for (int ci = 0; ci < Dim; ci++) {
				pr = ri;
				pc = ci;
				if (IsValid(pr, pc, B, Dim)) {
					B[ri][ci] = sym[computer];
					if (IsWin(B, Dim, sym[computer], WinC)) {
						B[ri][ci] = '-';
						return;
					}
					B[ri][ci] = '-';
				}

			}
		}
	
	for(int c = WinC; c>0 ; c--){
		for (int ri = 0; ri < Dim; ri++) {
			for (int ci = 0; ci < Dim; ci++) {
				pr = ri;
				pc = ci;
				if (IsValid(pr, pc, B, Dim)) {
					B[ri][ci] = sym[human];
					if (IsWin(B, Dim, sym[human], WinC)) {
						B[ri][ci] = '-';
						return;

					}
					B[ri][ci] = '-';

				}

			}
		}
	}


	do {
		pr = rand() % Dim;
		pc = rand() % Dim;


	} while (!IsValid(pr, pc, B, Dim));
}


int main()
{
	int c = 0;
	cout << "Which game?\n1.Human vs Human\n2.Comp vs Human\n";
	cin >> c;
	if (c == 1) {
		char B[cap][cap];
		char Sym[cap];
		char Pname[cap][100];
		int Nop, turn, pr, pc, Dim, winC = 0, winnersC = 0;
		int WinO[cap];
		innit(B, Dim, Sym, Pname, Nop, turn, winC);
		bool GameOver;
		PrintBoard(B, Dim);
		do {
			GameOver = false;
			TurnMsg(Pname[turn]);
				do {
					SelectPos(pr, pc, Dim);
				} while (!IsValid(pr, pc, B, Dim));
				PlaceMove(B, pr, pc, Dim, Sym[turn]);
			
			PrintBoard(B, Dim);
			if (IsWin(B, Dim, Sym[turn], winC)) {
				WinO[winnersC] = turn;
				winnersC++;
				cout << Pname[turn] << " wins!!";
			}
			if (IsDraw(B, Dim)) {
				GameOver = true;
				cout << "\nGame Draw\n";
			}
			if (winnersC == Nop - 1) {
				GameOver = true;
			}
			TurnChnage(turn, Nop);
		} while (!GameOver);

	}
	if (c == 2) {
		char B[cap][cap];
		char Sym[cap];
		string Pname[cap];
		int Nop = 2, turn, pr, pc, Dim, winC = 0, winnersC = 0;
		int WinO[cap];
		innit2(B, Dim, Sym, Pname, Nop, turn, winC);
		bool GameOver;
		PrintBoard(B, Dim);
		do {
			GameOver = false;
			sleep(1000);
			TurnMsg2(Pname[turn]);
			if (turn == computer) {
				CompMove(B, Dim, pr, pc, winC, Sym);
			}
			else {
				do {
					SelectPos(pr, pc, Dim);
				} while (!IsValid(pr, pc, B, Dim));
			}
			PlaceMove(B, pr, pc, Dim, Sym[turn]);
			if(turn == 0){
				sleep(100);
			}
			PrintBoard(B, Dim);
			if (IsWin(B, Dim, Sym[turn], winC)) {
				WinO[winnersC] = turn;
				winnersC++;
				cout << Pname[turn] << " wins!!";
			}
			if (IsDraw(B, Dim)) {
				GameOver = true;
				cout << "\nGame Draw\n";
			}
			if (winnersC == Nop - 1) {
				GameOver = true;
			}
			TurnChnage(turn, Nop);
		} while (!GameOver);

	}








	return _getch();
}