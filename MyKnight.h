/*
Name:Ankita Sawant
CS 570B
CWID:10412051

*/
#pragma once
#include<iostream>
#include<vector>

using namespace std;
class myKnight {
private:
	vector <vector<int>> board;

public:
	auto getBoard() {
		return board;
	}
	void setBoard(vector<vector<int>>& temp) {
		board = temp;
	}
	myKnight() {
		board.resize(0);
	}
	myKnight(int n) {
		vector <vector<int>> board(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = 0;

		setBoard(board);
	}
	void checkKnight(int row, int column, vector<vector<int>>
		&board, int &temp);


	void callCheckKnight(vector<vector<int>> &board, int &temp);

	void display(vector<vector<int>> board);
	//check all possible moves of Knight conditions
	int chkcond1(int i, int j, vector<vector<int>> board, int flag);
	int chkcond2(int i, int j, vector<vector<int>> board, int flag);
	int chkcond3(int i, int j, vector<vector<int>> board, int flag);
	int chkcond4(int i, int j, vector<vector<int>> board, int flag);
	int chkcond5(int i, int j, vector<vector<int>> board, int flag);
	int chkcond6(int i, int j, vector<vector<int>> board, int flag);
	int chkcond7(int i, int j, vector<vector<int>> board, int flag);
	int chkcond8(int i, int j, vector<vector<int>> board, int flag);
	void getAllSolutions(int n);

};

//call the check function
void myKnight::callCheckKnight(vector<vector<int>> &board, int &temp) {
	int n = board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			checkKnight(i, j, board, temp);
		}
	}
	cout << "**************************************" << endl;
}

//check function 
void myKnight::checkKnight(int row, int column, vector<vector<int>> &board, int &temp) {
	int n = board.size();

	int flag = 1;

	int i = row, j = column;

	//check all moves of knight
	flag = chkcond1(i, j, board, flag);
	flag = chkcond2(i, j, board, flag);
	flag = chkcond3(i, j, board, flag);
	flag = chkcond4(i, j, board, flag);
	flag = chkcond5(i, j, board, flag);
	flag = chkcond6(i, j, board, flag);
	flag = chkcond7(i, j, board, flag);
	flag = chkcond8(i, j, board, flag);

	if (flag == 9 && temp>0)
	{
		board[i][j] = 1;
		temp--;

	}
}
//display function
void myKnight::display(vector<vector<int>> board) {
	int tempK = 1;
	int n = board.size();
	cout << "______________________________" << endl;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1) {
				cout << "|___k" << tempK << "__|";
				tempK++;
			}
			else
				cout << "|___" << board[i][j] << "___|";
		}
		cout << endl;

	}

}

int myKnight::chkcond1(int i, int j, vector<vector<int>> board, int flag) {
	//condition 1
	int n = board.size();
	if ((i + 1) < n && (j + 2) < n)
	{
		if (board[i + 1][j + 2] != 1)
			flag++;
		else flag = 0;
	}
	else flag++;
	return flag;
}
int myKnight::chkcond2(int i, int j, vector<vector<int>> board, int flag) {
	//condition 2
	int n = board.size();
	if ((i + 2) < n && (j + 1) < n)
	{
		if (board[i + 2][j + 1] != 1)
			flag++;
		else flag = 0;
	}
	else flag++;

	return flag;
}
int myKnight::chkcond3(int i, int j, vector<vector<int>> board, int flag) {
	//condition 3
	int n = board.size();
	if ((i - 1) >= 0 && (j - 2) >= 0)
	{
		if (board[i - 1][j - 2] != 1)
			flag++;
		else flag = 0;
	}
	else flag++;


	return flag;
}
int myKnight::chkcond4(int i, int j, vector<vector<int>> board, int flag) {
	//condition 4
	int n = board.size();
	if ((i - 2) >= 0 && (j - 1) >= 0)
	{
		if (board[i - 2][j - 1] != 1)
			flag++;
		else flag = 0;
	}
	else flag++;
	return flag;
}
int myKnight::chkcond5(int i, int j, vector<vector<int>> board, int flag) {
	//condition 5
	int n = board.size();
	if ((i - 2) >= 0 && (j + 1) <n)
	{
		if (board[i - 2][j + 1] != 1)
			flag++;
		else flag = 0;
	}
	else flag++;

	return flag;
}
int myKnight::chkcond6(int i, int j, vector<vector<int>> board, int flag) {
	//condition 6
	int n = board.size();
	if ((i + 2) <n && (j - 1) >= 0)
	{
		if (board[i + 2][j - 1] != 1)
			flag++;
		else flag = 0;
	}
	else flag++;

	return flag;
}
int myKnight::chkcond7(int i, int j, vector<vector<int>> board, int flag) {
	int n = board.size();
	//condition 7
	if ((i - 1) >= 0 && (j + 2) <n)
	{
		if (board[i - 1][j + 2] != 1)
			flag++;

		else flag = 0;

	}
	else flag++;

	return flag;
}
int myKnight::chkcond8(int i, int j, vector<vector<int>> board, int flag) {
	//condition 8
	int n = board.size();
	//condition 8
	if ((i + 1) <n && (j - 2) >= 0)
	{
		if (board[i + 1][j - 2] != 1)
			flag++;
		else flag = 0;
	}
	else flag++;
	return flag;
}

void myKnight::getAllSolutions(int n) {
	int temp_percent = 0;
	
	int k = 0;
	
	int total_soln = n*n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			k++;
			int temp = 2 * n;
			if (n != 4)
				temp--;

			auto board = getBoard();
			//place knight at different positions
			board[i][j] = 1;
			//call checkKnight function
			callCheckKnight(board, temp);
			display(board);
			
			temp_percent = (k * 100) / total_soln;
			cout << "|----------------------|" << endl;
			cout << "|*" << temp_percent << "% completed        |" << endl;
			
			cout << "|----------------------|" << endl;
			

		}


	}
	cout << "**************************************" << endl;
	cout << "Total number of solutions are " << total_soln << endl;
}