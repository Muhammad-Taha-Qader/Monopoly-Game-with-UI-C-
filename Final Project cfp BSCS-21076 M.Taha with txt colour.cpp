#include <iostream>
#include<windows.h>
#include <stdlib.h>
using namespace std;

const int boxl = 2, boxw = 6;
int numOfRounds, roundCheck1, roundCheck2, conti = 0;
int plentyGreenBox[4] = { 5,16,27,38 };
int digonalSkyBlueBox[4] = { 7, 18, 29, 40 };
int lossTurnMagentaBox[4] = { 3, 14, 24, 35 };
int bonousTurnRedBox[4] = { 11, 22, 32, 36 };

int diseRoll()
{
	int roll = rand() % 6;
	return roll + 1;
}

void plenty(int& p1)
{

	conti = 0;
	if (plentyGreenBox[0] == p1)
	{
		cout << "U were standing on Plenty Green box " << p1 << " u have been shifted to pos 1\n";
		p1 = 1;
		conti = 1;
	}
	if (plentyGreenBox[1] == p1)
	{
		cout << "U were standing on Plenty Green box " << p1 << " u have been shifted to Yellow box pos 8\n";
		p1 = 8;
		conti = 1;
	}
	if (plentyGreenBox[2] == p1)
	{
		cout << "U were standing on Plenty Green box " << p1 << " u have been shifted to Yellow box pos 19\n";
		p1 = 19;
		conti = 1;
	}
	if (plentyGreenBox[3] == p1)
	{
		cout << "U were standing on Plenty Green box " << p1 << " u have been shifted to Yellow box pos 30\n";
		p1 = 30;
		conti = 1;
	}
}
void diagonalPassing(int& p1, int roundCheck)
{

	if (digonalSkyBlueBox[0] == p1)
	{
		cout << "U were standing on Sky Blue bonous box " << p1 << " u have been shifted to Solid Blue pos 17\n";
		p1 = 17;
	}
	else if (digonalSkyBlueBox[1] == p1)
	{
		cout << "U were standing on Sky Blue bonous box " << p1 << " u have been shifted to Solid Blue pos 28\n";
		p1 = 28;
	}
	else if (digonalSkyBlueBox[2] == p1)
	{
		cout << "U were standing on Sky Blue bonous box " << p1 << " u have been shifted to Solid Blue pos 39\n";
		p1 = 39;
	}
	else if (digonalSkyBlueBox[3] == p1 && roundCheck == (numOfRounds - 1))
	{
		cout << "U were standing on Sky Blue bonous box " << p1 << " but according to instruction last bypass bonous has been off\n";
	}
	else if (digonalSkyBlueBox[3] == p1)
	{
		cout << "U were standing on Sky Blue box " << p1 << " u have been shifted to Solid Blue pos 6\n";
		p1 = 6;
	}
	else if (conti == 0)
	{
		cout << "U are standing on normal case box... Continue\n";
	}

}

bool MagentaBox(int p1)
{

	if (lossTurnMagentaBox[0] == p1)
	{
		cout << "U will be standing on loss Turn Magenta Box " << p1 << " Opposit player will get +1 turn \n";
		return true;
	}
	if (lossTurnMagentaBox[1] == p1)
	{
		cout << "U will be standing on loss Turn Magenta Box " << p1 << " Opposit player will get +1 turn \n";
		return true;
	}
	if (lossTurnMagentaBox[2] == p1)
	{
		cout << "U will be standing on loss Turn Magenta Box " << p1 << " Opposit player will get +1 turn \n";
		return true;
	}
	if (lossTurnMagentaBox[3] == p1)
	{
		cout << "U will be standing on loss Turn Magenta Box " << p1 << " Opposit player will get +1 turn \n";
		return true;
	}

}

bool RedBox(int p1)
{

	if (bonousTurnRedBox[0] == p1)
	{
		cout << "U will be  standing on BONOUS Turn Red Box " << p1 << "U get +1 turn \n";
		return true;
	}
	if (bonousTurnRedBox[1] == p1)
	{
		cout << "U will be  standing on BONOUS Turn Red Box " << p1 << "U get +1 turn \n";
		return true;
	}
	if (bonousTurnRedBox[2] == p1)
	{
		cout << "U will be standing on BONOUS Turn Red Box " << p1 << "U get +1 turn \n";
		return true;
	}
	if (bonousTurnRedBox[3] == p1)
	{
		cout << "U will be  standing on BONOUS Turn Red Box " << p1 << "U get +1 turn \n";
		return true;
	}
}



void DisplayP1(int p1pos, char p1sym)
{
	static const HANDLE sym = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	if (p1pos > 0 && p1pos <= 12)
	{
		COORD coordinate = { (SHORT)1,(SHORT)(12 - p1pos) * boxl + boxl / 2 };
		SetConsoleCursorPosition(sym, coordinate);
		cout << p1sym;
	}
	else if (p1pos > 12 && p1pos < 24)
	{
		COORD coordinate = { (SHORT)(p1pos - 12) * boxw + 1,(SHORT)boxl / 2 };
		SetConsoleCursorPosition(sym, coordinate);
		cout << p1sym;
	}
	else if (p1pos >= 24 && p1pos <= 34)
	{
		COORD coordinate = { (SHORT)11 * boxw + 1,(SHORT)(p1pos - 23) * boxl + boxl / 2 };
		SetConsoleCursorPosition(sym, coordinate);
		cout << p1sym;
	}
	else if (p1pos > 34 && p1pos <= 45)
	{
		COORD coordinate = { (SHORT)(45 - p1pos) * boxw + 1,(SHORT)11 * boxl + boxl / 2 };
		SetConsoleCursorPosition(sym, coordinate);
		cout << p1sym;
	}
	else
		cout << "entered wrong position\n";

}

void DisplayP2(int p2pos, char p2sym)
{
	static const HANDLE sym = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	if (p2pos > 0 && p2pos <= 12)
	{
		COORD coordinate = { (SHORT)5,(SHORT)(12 - p2pos) * boxl + boxl / 2 };
		SetConsoleCursorPosition(sym, coordinate);
		cout << p2sym;
		for (int i = 0; ((p2pos * 3) + 9) > i; i++)
			cout << endl;
	}
	else if (p2pos > 12 && p2pos < 24)
	{
		COORD coordinate = { (SHORT)(p2pos - 12) * boxw + 5,(SHORT)boxl / 2 };
		SetConsoleCursorPosition(sym, coordinate);
		cout << p2sym;
		cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n\n";
	}
	else if (p2pos >= 24 && p2pos <= 34)
	{
		COORD coordinate = { (SHORT)11 * boxw + 5,(SHORT)(p2pos - 23) * boxl + boxl / 2 };
		SetConsoleCursorPosition(sym, coordinate);
		cout << p2sym;
		for (int i = 0; ((38 - p2pos) * 3) > i; i++)
			cout << endl;
	}
	else if (p2pos > 34 && p2pos <= 45)
	{
		COORD coordinate = { (SHORT)(45 - p2pos) * boxw + 5,(SHORT)11 * boxl + boxl / 2 };
		SetConsoleCursorPosition(sym, coordinate);
		cout << p2sym;
		cout << "\n \n \n \n \n \n \n \n \n \n \n \n ";
	}
	else
		cout << "entered wrong position\n";

}


void displaySquare(int x, int y, char p1sym = ' ', char p2sym = ' ', char colour = ' ')
{
	static const HANDLE boxDis = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coordinate = { (SHORT)x,(SHORT)y };
	SetConsoleCursorPosition(boxDis, coordinate);

	cout << " _____\n";
	y += 1;
	coordinate = { (SHORT)x,(SHORT)y };
	SetConsoleCursorPosition(boxDis, coordinate);

	cout << "|" << p1sym << " " << colour << " " << p2sym << "|\n";
	y += 1;

	coordinate = { (SHORT)x,(SHORT)y };
	SetConsoleCursorPosition(boxDis, coordinate);

	cout << "|_____|\n";
	y += 1;
}


void DisplayBoard()
{
	HANDLE txt;
	txt = GetStdHandle(STD_OUTPUT_HANDLE);  //to change boxes colours

	char empty = ' ';
	for (int col = 0; col < 12; col++)
	{
		for (int row = 0; row < 12; row++)
		{
			if (col == 0 && row == 11)
				displaySquare(col * boxw, row * boxl, empty, empty, 'B');//B=Black

			else if (col == 0 && row == 7 || col == 4 && row == 0 || col == 11 && row == 4 || col == 7 && row == 11)
			{
				SetConsoleTextAttribute(txt, 2);
				displaySquare(col * boxw, row * boxl, empty, empty, 'G');//G=Green
			}
			else if (col == 0 && row == 9 || col == 2 && row == 0 || col == 11 && row == 1 || col == 10 && row == 11)
			{
				SetConsoleTextAttribute(txt, 5);
				displaySquare(col * boxw, row * boxl, empty, empty, 'M');//M=Mjannenda/Purpal
			}
			else if (col == 0 && row == 6 || col == 5 && row == 0 || col == 11 && row == 5 || col == 6 && row == 11)
			{
				SetConsoleTextAttribute(txt, 1);
				displaySquare(col * boxw, row * boxl, empty, empty, 'D');//D=Dark Blue
			}
			else if (col == 0 && row == 5 || col == 6 && row == 0 || col == 11 && row == 6 || col == 5 && row == 11)
			{
				SetConsoleTextAttribute(txt, 3);
				displaySquare(col * boxw, row * boxl, empty, empty, 'S');//S=Sky Blue
			}
			else if (col == 0 && row == 4 || col == 7 && row == 0 || col == 11 && row == 7 || col == 4 && row == 11)
			{
				SetConsoleTextAttribute(txt, 6);
				displaySquare(col * boxw, row * boxl, empty, empty, 'Y');//Y=Yellow
			}
			else if (col == 0 && row == 1 || col == 10 && row == 0 || col == 11 && row == 9 || col == 9 && row == 11)
			{
				SetConsoleTextAttribute(txt, 4);
				displaySquare(col * boxw, row * boxl, empty, empty, 'R');//R=Red
			}
			else if (col == 0 || row == 0 || col == 11 || row == 11)
			{
				SetConsoleTextAttribute(txt, 12);
				displaySquare(col * boxw, row * boxl, empty, empty, 'P');//P=Peach
			}
			else if ((row == 1 || row == 10) && (col == 4 || col == 7) ||
				(row == 2 || row == 9) && (col == 3 || col == 8) ||
				(row == 3 || row == 8) && (col == 2 || col == 9) ||
				(row == 4 || row == 7) && (col == 1 || col == 10))
			{
				SetConsoleTextAttribute(txt, 12);
				displaySquare(col * boxw, row * boxl, empty, empty, 'P');
			}
			

             SetConsoleTextAttribute(txt, 7);
		}
	}
	cout << " B=Black\n G=Green\n M=Mjannenda/Purpal\n D=Dark Blue \n S=Sky Blue\n Y=Yellow\n R=Red\n P=Peach\n P1 in round=" << roundCheck1 + 1 << "  P2 in round = " << roundCheck2 + 1;

}

void MagentaBoxCheck(int& currentposP1, int& currentposP2, char p1sym, char p2sym, bool red, int p, int& a);

void RedBoxCheck(int& currentposP1, int& currentposP2, char p1sym, char p2sym, bool magenta, int p, int& a)
{
	bool red = false;


	if (p == 1)
	{
		red = RedBox(currentposP1);
		if (red == true)
		{
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			cout << "Roll dise for p1\n";
			system("pause");
			int rollP1 = diseRoll();

			cout << rollP1 << endl;

			if (currentposP1 + rollP1 == 45 && roundCheck1 == (numOfRounds - 1))
			{
				cout << "*******************   P1 WINS!!!   ************************\n";
			}
			else if (currentposP1 + rollP1 > 45 && roundCheck1 == (numOfRounds - 1))
				cout << "Position index exceded\n";
			else if (currentposP1 + rollP1 > 45)
			{
				currentposP1 = currentposP1 + rollP1;
				currentposP1 = currentposP1 - 44;
				a = 1;
				roundCheck1++;
				cout << roundCheck1 + 1 << " Round started for P1 " << endl;
			}
			else
				currentposP1 = currentposP1 + rollP1;

			RedBoxCheck(currentposP1, currentposP2, p1sym, p2sym, magenta, 1, a);
			MagentaBoxCheck(currentposP1, currentposP2, p1sym, p2sym, red, 1, a);


			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			plenty(currentposP1);
			diagonalPassing(currentposP1, roundCheck1);
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
		}
	}

	if (p == 2)
	{
		red = RedBox(currentposP2);
		if (red == true)
		{
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			cout << "Roll dise for p2\n";
			system("pause");
			int rollP2 = diseRoll();

			cout << rollP2 << endl;
			if (currentposP2 + rollP2 == 45 && roundCheck2 == (numOfRounds - 1))
			{
				cout << "*******************   P2 WINS!!!   ************************\n";
			}
			else if (currentposP2 + rollP2 > 45 && roundCheck2 == (numOfRounds - 1))
				cout << "Position index exceded\n";
			else if (currentposP2 + rollP2 > 45)
			{
				currentposP2 = currentposP2 + rollP2;
				currentposP2 = currentposP2 - 44;
				a = 1;
				roundCheck2++;
				cout << roundCheck2 + 1 << " Round started for P2 " << endl;
			}
			else
				currentposP2 = currentposP2 + rollP2;

			RedBoxCheck(currentposP1, currentposP2, p1sym, p2sym, magenta, 2, a);
			MagentaBoxCheck(currentposP1, currentposP2, p1sym, p2sym, red, 2, a);

			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			plenty(currentposP2);
			diagonalPassing(currentposP2, roundCheck2);
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
		}
	}


}




void MagentaBoxCheck(int& currentposP1, int& currentposP2, char p1sym, char p2sym, bool red, int p, int& a)
{
	bool magenta = false;
	if (p == 1)
	{
		magenta = MagentaBox(currentposP1);
		if (magenta == true)
		{
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			cout << "Roll dise for p2\n";
			system("pause");
			int rollP2 = diseRoll();

			cout << rollP2 << endl;
			if (currentposP2 + rollP2 == 45 && roundCheck2 == (numOfRounds - 1))
			{
				cout << "*******************   P2 WINS!!!   ************************\n";
			}
			else if (currentposP2 + rollP2 > 45 && roundCheck2 == (numOfRounds - 1))
				cout << "Position index exceded\n";
			else if (currentposP2 + rollP2 > 45)
			{
				currentposP2 = currentposP2 + rollP2;
				currentposP2 = currentposP2 - 44;
				a = 1;
				roundCheck2++;
				cout << roundCheck2 + 1 << " Round started for P2 " << endl;
			}
			else
				currentposP2 = currentposP2 + rollP2;

			RedBoxCheck(currentposP1, currentposP2, p1sym, p2sym, magenta, 2, a);
			MagentaBoxCheck(currentposP1, currentposP2, p1sym, p2sym, red, 2, a);

			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			plenty(currentposP2);
			diagonalPassing(currentposP2, roundCheck2);
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
		}
	}

	if (p == 2)
	{
		magenta = MagentaBox(currentposP2);
		if (magenta == true)
		{
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			cout << "Roll dise for p1\n";
			system("pause");
			int rollP1 = diseRoll();


			cout << rollP1 << endl;
			if (currentposP1 + rollP1 == 45 && roundCheck1 == (numOfRounds - 1))
			{
				cout << "*******************   P1 WINS!!!   ************************\n";
			}
			else if (currentposP1 + rollP1 > 45 && roundCheck1 == (numOfRounds - 1))
				cout << "Position index exceded\n";
			else if (currentposP1 + rollP1 > 45)
			{
				currentposP1 = currentposP1 + rollP1;
				currentposP1 = currentposP1 - 44;
				a = 1;
				roundCheck1++;
				cout << roundCheck1 + 1 << " Round started for P1 " << endl;
			}
			else
				currentposP1 = currentposP1 + rollP1;

			RedBoxCheck(currentposP1, currentposP2, p1sym, p2sym, magenta, 1, a);
			MagentaBoxCheck(currentposP1, currentposP2, p1sym, p2sym, red, 1, a);

			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			plenty(currentposP1);
			diagonalPassing(currentposP1, roundCheck1);
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
		}
	}


}



int main()
{

	int  currentposP1 = 1, currentposP2 = 1;
	bool magenta = false, red = false;
	cout << "Enter number of rounds of the game\n";
	cin >> numOfRounds;
	char p1sym = '0', p2sym = 'X';
	int a = 0, ended = 0;

	for (roundCheck1 = 0, roundCheck2 = 0; roundCheck1 < numOfRounds && roundCheck2 < numOfRounds; )
	{
		cout << "Roll dise for p1\n";
		system("pause");
		int rollP1 = diseRoll();
		cout << rollP1 << endl;
		if (currentposP1 + rollP1 == 45 && roundCheck1 == (numOfRounds - 1))
		{
			cout << "*******************   P1 WINS!!!   ************************\n";
			currentposP1 = currentposP1 + rollP1;
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			break;
		}
		else if (currentposP1 + rollP1 > 45 && roundCheck1 == (numOfRounds - 1))
			cout << "Position index exceeded. Your turn wasted\n";
		else if (currentposP1 + rollP1 > 45)
		{
			currentposP1 = currentposP1 + rollP1;
			currentposP1 = currentposP1 - 44;
			roundCheck1++;
			cout << roundCheck1 + 1 << " Round started for P1 " << endl;
		}
		else
			currentposP1 = currentposP1 + rollP1;

		RedBoxCheck(currentposP1, currentposP2, p1sym, p2sym, magenta, 1, a);
		MagentaBoxCheck(currentposP1, currentposP2, p1sym, p2sym, red, 1, a);

		system("pause");
		system("cls");
		DisplayBoard();
		DisplayP1(currentposP1, p1sym);
		DisplayP2(currentposP2, p2sym);
		plenty(currentposP1);
		diagonalPassing(currentposP1, roundCheck1);
		system("pause");
		system("cls");
		DisplayBoard();
		DisplayP1(currentposP1, p1sym);
		DisplayP2(currentposP2, p2sym);



		cout << "Roll dise for p2\n";
		system("pause");
		int rollP2 = diseRoll();

		cout << rollP2 << endl;

		if (currentposP2 + rollP2 == 45 && roundCheck2 == (numOfRounds - 1))
		{
			cout << "*******************   P2 WINS!!!   ***********************\n";
			currentposP2 = currentposP2 + rollP2;
			system("pause");
			system("cls");
			DisplayBoard();
			DisplayP1(currentposP1, p1sym);
			DisplayP2(currentposP2, p2sym);
			break;
		}
		else if (currentposP2 + rollP2 > 45 && roundCheck2 == (numOfRounds - 1))
			cout << "Position index exceeded. Your turn wasted\n";
		else if (currentposP2 + rollP2 > 45)
		{
			currentposP2 = currentposP2 + rollP2;
			currentposP2 = currentposP2 - 44;
			roundCheck2++;
			cout << roundCheck2 + 1 << " Round started for P2 " << endl;
		}
		else
			currentposP2 = currentposP2 + rollP2;

		RedBoxCheck(currentposP1, currentposP2, p1sym, p2sym, magenta, 2, a);
		MagentaBoxCheck(currentposP1, currentposP2, p1sym, p2sym, red, 2, a);

		system("pause");
		system("cls");
		DisplayBoard();
		DisplayP1(currentposP1, p1sym);
		DisplayP2(currentposP2, p2sym);
		plenty(currentposP2);
		diagonalPassing(currentposP2, roundCheck2);
		system("pause");
		system("cls");
		DisplayBoard();
		DisplayP1(currentposP1, p1sym);
		DisplayP2(currentposP2, p2sym);
	}
}