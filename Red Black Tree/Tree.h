#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class Tree
{
protected:
	Node* Root;
public:
	Tree()      //Constructor
	{
		Root = nullptr;
	}
	virtual void MenupreorderTraversalNLR()=0;//NLR
	virtual void MenupostorderTraversalLRN()=0;//LRN
	virtual void MenupostorderTraversalRLN()=0;//RLN
	virtual void MenupreorderTraversalNRL()=0;//NRL
	virtual void MenuinorderTraversalRNL()=0;//RNL
	virtual void MenuinorderTraversalLNR()=0;//LNR
	
};




