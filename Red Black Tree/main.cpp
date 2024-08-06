#include<iostream>
using namespace std;
#include "RBT.h"
void Menu(RBT Tree1)
{
	int choice = 0, Val = 0, val = 0;
	cout << "Enter 1 For Insertion" << endl;
	cout << "Enter 2 For Search" << endl;
	cout << "Enter 3 For Pre-Order NLR" << endl;
	cout << "Enter 4 For In-Order LNR" << endl;
	cout << "Enter 5 For Post-Order LRN" << endl;
	cout << "Enter 6 For Pre-Order NRL" << endl;
	cout << "Enter 7 For In-Order RNL" << endl;
	cout << "Enter 8 For Post-Order RLN" << endl;
	cout << "Enter 9 For Displaying Parent of Node" << endl;
	cout << "Enter 10 To Read values from the File" << endl;
	cout << "Enter 11 To Delete all duplicate values" << endl;
	cout << "Enter 12 To Destroy the complete tree" << endl;
	cout << "Enter 13 To EXIT" << endl;
	cout << "Enter Choice:"; cin >> choice; cout << endl;
	switch (choice)
	{
	case 1:
		cout << endl << "Enter a value to insert, (-999) to stop inserting: ";
		while (val != -999)
		{
			cin >> val;
			if(val!=-999)
			Tree1.MenuRBTinsertion(val);
		}
		cout << endl;
		Menu(Tree1);
		break;
	case 2:
		cout << "Enter Number: "; cin >> Val;
		if (Tree1.MenuSearchVal(Val) == 0)
		{
			cout << "Not Found " << endl;
		}
		else
		{
			cout << "Found " << endl;
		}
		Menu(Tree1);
		break;
	case 3:
		Tree1.MenupreorderTraversalNLR();
		cout << endl;
		Menu(Tree1);
		break;
	case 4:
		Tree1.MenuinorderTraversalLNR();
		cout << endl;
		Menu(Tree1);
		break;
	case 5:
		Tree1.MenupostorderTraversalLRN();
		cout << endl;
		Menu(Tree1);
		break;
	case 6:
		Tree1.MenupreorderTraversalNRL();
		cout << endl;
		Menu(Tree1);
		break;
	case 7:
		Tree1.MenuinorderTraversalRNL();
		cout << endl;
		Menu(Tree1);
		break;
	case 8:
		Tree1.MenupostorderTraversalRLN();
		Menu(Tree1);
		break;
	case 9:
		cout << "Enter Number to find its parent :"; cin >> Val;
		Tree1.MenuFindParent(Val);
		cout << endl;
		Menu(Tree1);
		break;
	case 10:
		Tree1.Menuinsertfromfile();
		cout << endl;
		Menu(Tree1);
		break;
	case 11:
		Tree1.MenudeleteDuplicate();
		cout << endl;
		Menu(Tree1);
		break;
	case 12:
		Tree1.MenuDestroyTree();
		cout << endl;
		cout << "Tree Destroyed" << endl << endl;
		exit(EXIT_SUCCESS);
	case 13:
		exit(EXIT_SUCCESS);
	}
}
int main()
{
	RBT Tree1;
	Menu(Tree1);
}
