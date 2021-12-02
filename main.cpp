#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

class toetactic
{

private:

	string p1="", p2=""; //string containers for player names
	int p1score=0, p2score=0, drawscore=0, menuchoice=0, boxchoice=0; //int containers for scores and choices
	char p1symbol = 'X', p2symbol = 'O'; //X and O symbols for players
	char array[9] = { '1','2','3','4','5','6','7','8','9' }; //the tictactoe boards that holds X or O
	int turn = 1; //initialized player1's turn to start game
	bool istherewinner = false; //flag that confirms is there a winner currently and is used in my checkwinner functions
	int compmove = 0;//marker for comp to choose moves
	int totalmovecounter = 0;// container for total moves for draw
	//int compchoice = 0;//int container for comp choice

public:

	toetactic() { mmenu(); }//default constructor that calls the main menu function

	void displayboard() //board display function
	{
		system("cls");
		cout << "		          T!C-t@c-TOe			             Maxthecoder\n";
		cout << "		          ~~~~~~~~~~\n";
		cout << "			 ___ ___ ___" << endl <<endl;
		cout << "			[ " << array[0] << " | " << array[1] << " | " << array[2] << " ]" << endl;
		cout << "			 ___ ___ ___" << endl<<endl;
		cout << "			[ " << array[3] << " | " << array[4] << " | " << array[5] << " ]" << endl;
		cout << "			 ___ ___ ___" << endl<<endl;
		cout << "			[ " << array[6] << " | " << array[7] << " | " << array[8] << " ]" << endl;
		cout << "			 ___ ___ ___" << endl<<endl;
	}

	void setboardwithchoice(int c) //this function takes the choice and matches it to the proper board box
	{
			switch (c)
			{
			case 1:
				if (turn % 2 != 0) { array[0] = p1symbol;  }
				else array[0] = p2symbol; break;

			case 2:
				if (turn % 2 != 0) { array[1] = p1symbol;  }
				else array[1] = p2symbol; break;

			case 3:
				if (turn % 2 != 0) { array[2] = p1symbol; }
				else array[2] = p2symbol; break;

			case 4:
				if (turn % 2 != 0) { array[3] = p1symbol;  }
				else array[3] = p2symbol; break;

			case 5:
				if (turn % 2 != 0) { array[4] = p1symbol;  }
				else array[4] = p2symbol; break;

			case 6:
				if (turn % 2 != 0) { array[5] = p1symbol;  }
				else array[5] = p2symbol; break;

			case 7:
				if (turn % 2 != 0) { array[6] = p1symbol;  }
				else array[6] = p2symbol; break;

			case 8:
				if (turn % 2 != 0) { array[7] = p1symbol;  }
				else array[7] = p2symbol; break;

			case 9:
				if (turn % 2 != 0) { array[8] = p1symbol; }
				else array[8] = p2symbol; break;
			}
	}

	void displayscore() //my scoreboard
	{
		cout <<        "		            SCORE\n";
		cout << "		            ~~~~~\n";
		cout <<"	  "<< p1 <<"		    DRAW		"<< p2 << endl;
		cout << "	   " <<p1score <<"	 	      "<<drawscore<<"			 " << p2score << endl << endl;

	}

	void hrungetmove() //I called it hrun getmove because it is specifically for a 2 human player game mode that allows for taking of turns and checking the board for a winner after everyturn then incrementing the turn variable
	{
		do {
			displayboard();
			if (turn % 2 != 0)
			{
				cout << p1 << " which numbered box do you choose?";
				cin >> boxchoice;
				setboardwithchoice(boxchoice);
				totalmovecounter++;
			}
			else
			{
				cout << p2 << " which numbered box do you choose?";
				cin >> boxchoice;
				setboardwithchoice(boxchoice);
				totalmovecounter++;
			}
			hcheckforwin();
			++turn;
		} while (istherewinner==false);

	}


	void hcheckforwin() //checks for wins then provides a menu
	{
		if (((array[0] == 'X') && (array[1] == 'X') && (array[2] == 'X')) || ((array[3] == 'X') && (array[4] == 'X') && (array[5] == 'X')) || ((array[6] == 'X') && (array[7] == 'X') && (array[8] == 'X'))) { displayboard(); istherewinner = true; cout << p1 << " is the WINNER with a horizontal win!\n\n"; ++p1score; displayscore(); hmenu(); }
		else if (((array[0] == 'O') && (array[1] == 'O') && (array[2] == 'O')) || ((array[3] == 'O') && (array[4] == 'O') && (array[5] == 'O')) || ((array[6] == 'O') && (array[7] == 'O') && (array[8] == 'O'))) { displayboard(); istherewinner = true; cout << p2 << " is the WINNER with a horizontal win!\n\n"; ++p2score; displayscore(); hmenu(); }
		else if (((array[0] == 'X') && (array[3] == 'X') && (array[6] == 'X')) || ((array[1] == 'X') && (array[4] == 'X') && (array[7] == 'X')) || ((array[2] == 'X') && (array[5] == 'X') && (array[8] == 'X'))) { displayboard(); istherewinner = true; cout << p1 << " is the WINNER with a vertical win!\n\n"; ++p1score; displayscore(); hmenu(); }
		else if (((array[0] == 'O') && (array[3] == 'O') && (array[6] == 'O')) || ((array[1] == 'O') && (array[4] == 'O') && (array[7] == 'O')) || ((array[2] == 'O') && (array[5] == 'O') && (array[8] == 'O'))) { displayboard(); istherewinner = true; cout << p2 << " is the WINNER with a vertical win!\n\n"; ++p2score; displayscore(); hmenu(); }
		else if (((array[0] == 'X') && (array[4] == 'X') && (array[8] == 'X')) || ((array[2] == 'X') && (array[4] == 'X') && (array[6] == 'X'))) { displayboard(); istherewinner = true; cout << p1 << " is the WINNER with a diagonal win!\n\n"; ++p1score; displayscore(); hmenu(); }
		else if (((array[0] == 'O') && (array[4] == 'O') && (array[8] == 'O')) || ((array[2] == 'O') && (array[4] == 'O') && (array[6] == 'O'))) { displayboard(); istherewinner = true; cout << p2 << " is the WINNER with a diagonal win!\n\n"; ++p2score; displayscore(); hmenu(); }

		else if (totalmovecounter==9){
			displayboard(); istherewinner = true; cout << "THERE IS NO WINNER! IT IS A DRAW\n\n"; ++drawscore; displayscore(); hmenu();
		}
	}

	void crun()
	{  if(p1=="COMP")
		do {
			compstrategy();
			totalmovecounter++;
			hcheckforwin();
			++turn;
			displayboard();
			cout << p2 << " which numbered box do you choose?";
			cin >> boxchoice;
			setboardwithchoice(boxchoice);
			totalmovecounter++;
			hcheckforwin();
			++turn;
		} while (istherewinner == false);
	else if(p2=="COMP")
		do {
			displayboard();
			cout << p1 << " which numbered box do you choose?";
			cin >> boxchoice;
			setboardwithchoice(boxchoice);
			totalmovecounter++;
			hcheckforwin();
			++turn;
			compstrategy();
			totalmovecounter++;
			hcheckforwin();
			++turn;
		} while (istherewinner == false);

	}


	void compstrategy()
	{
		if (p1 == "COMP" && compmove == 0) { setboardwithchoice(5); compmove++; }

		else if (p1 == "COMP"&& compmove == 1)
		{
			if (array[2] == '3') { setboardwithchoice(3); compmove++; }
			else if (array[8] == '9') { setboardwithchoice(9); compmove++; }
		}

		else if (p1 == "COMP"&& compmove == 2)
		{
			if (array[2] == 'X') {
				if (array[6] == '7') { setboardwithchoice(7); compmove++; }
				else if (array[8] == '9') { setboardwithchoice(9); compmove++; }
				else if (array[0] == '1') { setboardwithchoice(1); compmove++; }
			}
			if (array[8] == 'X') {
				if (array[0] == '1') { setboardwithchoice(1); compmove++; }
				else if (array[6] == '7') { setboardwithchoice(7); compmove++; }
			}
		}

		else if (p1 == "COMP"&& compmove == 3)
		{
			if (array[2] == 'X') {
				if (array[5] == '6') { setboardwithchoice(6); compmove++; }
				else if (array[0] == '1') { setboardwithchoice(1); compmove++; }
			}
			if (array[8] == 'X') {
				if (array[7] == '8') { setboardwithchoice(8); compmove++; }
				else if (array[2] == '3') { setboardwithchoice(3); compmove++; }
			}
		}

		else if (p2 == "COMP" && compmove == 0)
		{
			if (array[4] == '5') { setboardwithchoice(5); compmove++; }
			else if (array[2] == '3') { setboardwithchoice(3); compmove++; }
		}


		else if (p2 == "COMP"&& compmove == 1)
		{
			if (array[2] == '3') { setboardwithchoice(3); compmove++; }
			else if (array[8] == '9') { setboardwithchoice(9); compmove++; }
		}

		else if (p2 == "COMP"&& compmove == 2)
		{
			if (array[2] == 'O') {
				if (array[6] == '7') { setboardwithchoice(7); compmove++; }
				else if (array[8] == '9') { setboardwithchoice(9); compmove++; }
				else if (array[0] == '1') { setboardwithchoice(1); compmove++; }

			}
			if (array[8] == 'O') {
			 if (array[6] == '7') { setboardwithchoice(7); compmove++; }
			 else if (array[0] == '1') { setboardwithchoice(1); compmove++; }
			}
		}
		else if (p2 == "COMP"&& compmove == 3)
		{
			if (array[2] == 'O') {
				if (array[5] == '6') { setboardwithchoice(6); compmove++; }
				else if (array[0] == '1') { setboardwithchoice(1); compmove++; }
			}
			if (array[8] == 'O') {
				if (array[0] == '1') { setboardwithchoice(1); compmove++; }
				if (array[7] == '8') { setboardwithchoice(8); compmove++; }
				else if (array[2] == '3') { setboardwithchoice(3); compmove++; }
			}
		}
		else if (p2 == "COMP"&& compmove == 4)
		{
			if (array[2] == 'O') {
				if (array[5] == '6') { setboardwithchoice(6); compmove++; }
				else if (array[0] == '1') { setboardwithchoice(1); compmove++; }
			}
			if (array[8] == 'O') {
				if (array[7] == '8') { setboardwithchoice(8); compmove++; }
				else if (array[2] == '3') { setboardwithchoice(3); compmove++; }
			}
		}
	}



	void hmenu()
	{
		cout << "1.Play Again?\n2.Main Menu\n3.Quit\n";
		cin >> menuchoice;
		switch (menuchoice)
		{
		case 1:
			hresetboard();
			if (p1 == "COMP" || p2 == "COMP") { crun(); }
			else { hrungetmove();  }
			break;

		case 2:resetscores(); hresetboard(); mmenu(); break;

		case 3: exit(0);
		}
	}

	void mmenu()
	{
		system("cls");
		cout << "		 Welcome to Maxthecoder's Console\n			  T!C-t@c-TOe\n\n";
		cout << "			  Main Menu\n";
		cout << "			  ~~~~~~~~~\n";
		cout << "			1. vs COMPUTER\n";
		cout << "			2. 2 Human Players\n";
		cout << "			3. How to Play T!C-t@c-TOe?\n";
		cout << "			4. Quit\n\n";
		cin >> menuchoice;

		switch (menuchoice)
		{
		case 1:cout << "CHOOSE:\n1.Player1\n2.Player2\n";
			cin >> menuchoice;
			if (menuchoice == 1) {
				p2 = "COMP"; cout << "What is your nickname Player 1?\n"; cin >> p1;
			}
			else { p1 = "COMP"; cout << "What is your nickname Player 2?\n"; cin >> p2;  }
			crun();
			break;

		case 2:
			cout << "PLAYER 1 WHAT IS YOUR NICKNAME? ";
			cin >> p1;
			cout << "PLAYER 2 WHAT IS YOUR NICKNAME? ";
			cin >> p2;
			hrungetmove();
			break;

		case 3:
			cout << "TAKE TURNS, GET 3 OF YOUR SYMBOLS IN A ROW AND YOU WIN! SIMPLE!\n";
			system("pause"); mmenu(); break;

		case 4: exit(0);
		}
	}

void resetscores(){ p1score = 0, p2score = 0, drawscore = 0, p1 = "", p2 = "";}

void hresetboard()
{
	totalmovecounter = 0;
	array[0] = '1';
	array[1] = '2';
	array[2] = '3';
	array[3] = '4';
	array[4] = '5';
	array[5] = '6';
	array[6] = '7';
	array[7] = '8';
	array[8] = '9';
	turn = 1;
	istherewinner = false;
	compmove = 0;
}




};

int main()
{
	srand(time(NULL));
	system("COLOR 7C");
	toetactic a;
	system("PAUSE");
}
