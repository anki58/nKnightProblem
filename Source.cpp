/*
Name:Ankita Sawant
CS 570B
CWID:10412051

*/

#include<iostream>
#include<vector>
#include"myKnight.h"
using namespace std;

int main() {
	int n = 1;
	cout << "*******n-Knights Problem********" << endl;
	char flag = 'n';
	while (flag != 'q' && flag != 'Q') {


		cout << "Enter number of knights " << endl;
		//to check if the input of num of knights is proper.
		while (!(cin >> n)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.\nPlease enter number of knights again: "<<endl;
	
		}

		//create myKnight class object
		myKnight k(n);
		//call getAllSolutions function
		k.getAllSolutions(n);
		//ask if the user needs to quit
		cout <<endl<< "Do you want to continue checking other solutions?\nEnter q/Q to quit!" << endl;
		cin >> flag;
	}


	return 0;
}