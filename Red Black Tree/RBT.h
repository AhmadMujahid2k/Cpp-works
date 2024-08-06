#pragma once
#include "Tree.h"
#include <iostream>
#include <fstream>
using namespace std;
class RBT : public Tree
{
public:
    void MenuRBTinsertion(int val)
    {
        Node *temp = Root;
        RBTinsertionCode(val, temp);
        if (!Checkroot(Root)) //Change Color In function
        {
            Root->color = 'b';
        }
    }
    void MenuinorderTraversalLNR() //Recursive Function of INOrder Traversal NRL
    {
        if (is_Empty())
        {
            cout << "Tree is Empty" << endl;
        }
        else
        {
            InOrderTraversalLNR(Root);
        }
    }
    void MenupostorderTraversalLRN()
    {
        if (is_Empty())
        {
            cout << "Tree is Empty";
        }
        else
        {
            PostOrderTraversalLRN(Root);
        }
    }
    void MenupreorderTraversalNLR()
    {
        if (is_Empty())
        {
            cout << "Tree is Empty";
        }
        else
        {
            PreOrderTraversalNLR(Root);
        }
    }
    void MenupostorderTraversalRLN() //Recursive Function of PostOrder Traversal NRL
    {
        if (is_Empty())
        {
            cout << "Tree is Empty";
        }
        else
        {
            PostOrderTraversalRLN(Root);
        }
    }
    void MenupreorderTraversalNRL() //Recursive Function of PreOrder Traversal NRL
    {
        if (is_Empty())
        {
            cout << "Tree is Empty" << endl;
        }
        else
        {
            PreOrderTraversalNRL(Root);
        }
    }
    void MenuinorderTraversalRNL() //Recursive Function of In-Order Traversal RNL
    {
        if (is_Empty())
        {
            cout << "Tree is Empty" << endl;
        }
        else
        {
            InOrderTraversalRNL(Root);
        }
    }
    void Menuinsertfromfile() //Function used to insert values from File
    {
        ifstream fin("input.txt");
        if (!fin.is_open())
        {
            cout << "File's not Open" << endl;
        }
        else
        {
            int val = 0;
            while (!fin.eof())
            {
                fin >> val;
                RBTinsertionCode(val, Root);
                if (!Checkroot(Root))
                {
                    Root->color = 'b';
                }
            }
        }
    }
    void MenudeleteDuplicate() //Function to delete duplicate entries in RBT
    {
        // Not Done
    }
    void MenuDestroyTree() //Function used to destroy rbt all nodes and leafs
    {
        if (is_Empty())
        {
            cout << "Tree is Empty";
        }
        else
        {
            destroyTree(Root);
        }
    }
    void MenuFindParent(int val)
    {
        if (is_Empty())
        {
            cout << "Tree is Empty";
        }
        else
        {
            Node *temp = FindParent(val);
            cout << "Parent of " << val << " is " << temp->data << endl;
        }
    }
    int MenuSearchVal(int val) //Fucntion to Search Values in RBT
    {
        if (is_Empty())
        {
            cout << "Tree is Empty" << endl;
            return 0;
        }
        else
        {
            return SearchRecursively(val, Root);
        }
    }

private:
    // Printing Functions
    void InOrderTraversalLNR(Node *temp) //Recurrsive Function of In-Order Traversal LNR
    {
        if (temp != nullptr)
        {
            InOrderTraversalLNR(temp->LeftChild);
            cout << temp->data << " ";
            if (temp->color == 'r')
            {
                cout << "Red" << endl;
            }
            else
            {
                cout << "Black" << endl;
            }
            InOrderTraversalLNR(temp->RightChild);
        }
    }
    void PostOrderTraversalLRN(Node *temp) //Recurrsive Function of Post-Order Traversal LRN
    {
        if (temp != nullptr)
        {
            PostOrderTraversalLRN(temp->LeftChild);
            PostOrderTraversalLRN(temp->RightChild);
            cout << temp->data << endl;
            if (temp->color == 'r')
            {
                cout << "Red" << endl;
            }
            else
            {
                cout << "Black" << endl;
            }
        }
    }
    void PreOrderTraversalNLR(Node *temp) //Recurrsive Function of Pre-Order Traversal NLR
    {
        if (temp != nullptr)
        {
            cout << temp->data << endl;
            if (temp->color == 'r')
            {
                cout << "Red" << endl;
            }
            else
            {
                cout << "Black" << endl;
            }
            PreOrderTraversalNLR(temp->LeftChild);
            PreOrderTraversalNLR(temp->RightChild);
        }
    }
    void PostOrderTraversalRLN(Node *temp) //Recurrsive Function of Post-Order Traversal RLN
    {
        if (temp != nullptr)
        {
            PostOrderTraversalRLN(temp->RightChild);
            PostOrderTraversalRLN(temp->LeftChild);
            cout << temp->data << endl;
            if (temp->color == 'r')
            {
                cout << "Red" << endl;
            }
            else
            {
                cout << "Black" << endl;
            }
        }
    }
    void PreOrderTraversalNRL(Node *temp) //Recurrsive Function of Pre-Order Traversal NRL
    {
        if (temp != nullptr)
        {
            cout << temp->data << endl;
            if (temp->color == 'r')
            {
                cout << "Red" << endl;
            }
            else
            {
                cout << "Black" << endl;
            }
            PreOrderTraversalNRL(temp->RightChild);
            PreOrderTraversalNRL(temp->LeftChild);
        }
    }
    void InOrderTraversalRNL(Node *temp)
    {
        if (temp != nullptr)
        {
            InOrderTraversalRNL(temp->RightChild);
            cout << temp->data << endl;
            if (temp->color == 'r')
            {
                cout << "Red" << endl;
            }
            else
            {
                cout << "Black" << endl;
            }
            InOrderTraversalRNL(temp->LeftChild);
        }
    }

    bool is_Empty() //Fucntion to Check either the Root is empty or not
    {
        if (Root == nullptr)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int SearchRecursively(int val, Node *temp) //Recursive Function of Searching Value.
    {
        if (temp->data == val) //if found return 
        {
            return temp->data;
        }
        else if (val >= temp->data) //Searching on Right Side
        {
            if (temp->RightChild == nullptr)
            {
                return 0;
            }
            temp = temp->RightChild;
            SearchRecursively(val, temp);
        }
        else if (val < temp->data) //Searching on Left Side
        {
            if (temp->LeftChild == nullptr)
            {
                return 0;
            }
            temp = temp->LeftChild;
            SearchRecursively(val, temp);
        }
    }
    Node *FindParent(int val)
    {
        Node *temp = Root;
            if (val == Root->data) //checking if the value is equal to the number/value of Root node
            {
                cout << "It is Root Node." << endl;
                return nullptr;
            }
            while(true)
            {
                if (val > temp->data)
                {
                    if (temp->RightChild->data == val)
                    {
                        return temp;
                        break;
                    }
                    else
                    {
                        temp = temp->RightChild;
                    }
                }
                else if (val < temp->data)
                {
                    if (temp->LeftChild == nullptr)
                    {
                        break;
                    }
                    if (temp->LeftChild->data == val)
                    {
                        return temp;
                        break;
                    }
                    else
                    {
                        temp = temp->LeftChild;
                    }
                }
            }
        return 0;
    }
    Node *FindGrandParent(int val) //Function to find Grand ParentNode in RBT
    {
        Node *temp = FindParent(val);
            if (temp == nullptr)
            {
                cout << "Parent Node Doesn't Exist" << endl;
                return 0;
            }
            else
            {
                temp = FindParent(temp->data);
                if (temp == nullptr)
                {
                    cout << "Grand Parent Node Doesn't Exist" << endl;
                    return nullptr;
                }
                else
                {
                    return temp;
                }
            }
    }
    Node *FindUncle(int val) //Function to find Uncle in RBT
    {
        Node *GrandParent = FindGrandParent(val);
            if (GrandParent != nullptr)
            {
                Node *parent =  FindParent(val); //Parent
                if (parent == nullptr)
                {
                    return 0;
                }
                else
                {
                    if (GrandParent->RightChild == parent)
                    {
                        return GrandParent->LeftChild;
                    }
                    else if (GrandParent->LeftChild == parent)
                    {
                        return GrandParent->RightChild;
                    }
                    else if (GrandParent->LeftChild == nullptr || GrandParent->RightChild == nullptr)
                    {
                        return 0;
                    }
                }
            }
            else
            {
                cout << "The GrandParent dosent Exists." << endl;
                return 0;
            }
        return 0;
    }
    bool Recolor(int val) //Function to Recolor node
    {
        char newColor;              
        Node *GrandParent = FindGrandParent(val); 
        Node *Parent = nullptr;
            if (GrandParent != nullptr)
            {
                newColor = GrandParent->color;
                Parent = FindParent(val);
                GrandParent->color = Parent->color;
                Parent->color = newColor;
                Parent = FindUncle(val);
                Parent->color = newColor;
                return 1;
            }
            else
            {
                cout << "Grand Parent Node doesn't Exist." << endl;
                return 0;
            }
    }
    bool rightRotation(int val)
    {
            Node *ParentNode = FindParent(val);
            Node *GrandParentNode = FindGrandParent(val);
            Node *GreatGrandParent = FindParent(GrandParentNode->data); 
            Node* PLeftChild = nullptr;
            bool check = false, temp = false;
            if (GreatGrandParent != nullptr)
            {
                temp = true;
            }
            if (ParentNode->LeftChild != nullptr)
            {
                if (ParentNode->LeftChild->color == 'b')
                {
                    PLeftChild = ParentNode->LeftChild;
                    ParentNode->LeftChild = nullptr;
                    check = true;
                }
                else if (ParentNode->LeftChild->color == 'r')
                {
                    GrandParentNode->RightChild = nullptr;
                    GrandParentNode->RightChild = ParentNode->LeftChild;
                    ParentNode->LeftChild = nullptr;
                    GrandParentNode->RightChild->RightChild = ParentNode;
                    return true;
                }
            }
            GrandParentNode = FindGrandParent(val);
            GrandParentNode->RightChild = nullptr;
            GrandParentNode->color = 'r';
            ParentNode->color = 'b';
            if (check ==true)
            {
                GrandParentNode->RightChild = PLeftChild;
            }
            ParentNode->LeftChild = GrandParentNode;
            if (temp == true)
            {
                GreatGrandParent->RightChild = nullptr;
                GreatGrandParent->RightChild = ParentNode;
            }
            if (temp == false)
            {
                Root = ParentNode;
                if (!Checkroot(ParentNode))
                {
                    Root->color = 'b';
                }
            }
            return 1;
    }
    bool leftRotation(int val) //Function to rotate value to left if it voilates any conditions of rbt
    {
            Node *ParentNode= FindParent(val);
            Node *GrandParentNode =  FindGrandParent(val);
            Node *GreatGrandParent = FindGrandParent(ParentNode->data);
            Node *pRightChild = nullptr;
            bool check = 0,temp = 0;  

            if (GreatGrandParent != nullptr)
            {
                temp = true;
            }
            if (ParentNode->RightChild != nullptr)
            {
                pRightChild = ParentNode->RightChild;
                ParentNode->RightChild = nullptr;
                check = true;
            }
            GrandParentNode->LeftChild = nullptr;
            ParentNode->RightChild = GrandParentNode;
            ParentNode->color = 'b';
            GrandParentNode->color = 'r';
            if (check == true)
            {
                GrandParentNode->LeftChild = pRightChild;
            }
            if (temp == false)
            {
                Root = ParentNode;
            }
            if (temp == true)
            {
                GreatGrandParent->LeftChild = nullptr;
                GreatGrandParent->LeftChild = ParentNode;
            }
        return 0;
    }
    bool Checkroot(Node *temp) //Function to check wether the node is Root node or not
    {
        if (is_Empty())
        {
            cout << "Tree is Empty" << endl;
            return 0;
        }
        if (temp->color == 'b')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void RBTinsertionCode(int val, Node *temp) //function to insert Values into RBT
    {
        Node *newNode = new Node;
        newNode->LeftChild = nullptr;
        newNode->RightChild = nullptr;
        newNode->data = val;
        newNode->color = 'r';

        if (is_Empty())
        {
            Root = newNode;
            newNode->color = 'b';
        }
        else
        {
            Node *ParentNode = nullptr;
            Node *UncleNode = nullptr;
            Node *GrandParentNode = nullptr;
            if (val >= temp->data)
            {
                if (temp->RightChild == nullptr)
                {
                    temp->RightChild = newNode;
                    ParentNode = FindParent(newNode->data);
                    if (newNode->color == 'r' && ParentNode->color == 'r')
                    {
                        GrandParentNode = FindGrandParent(newNode->data);
                        if (ParentNode->RightChild == newNode && GrandParentNode->LeftChild == ParentNode)
                        {
                            GrandParentNode->LeftChild = nullptr;
                            ParentNode->RightChild = nullptr;
                            GrandParentNode->LeftChild = newNode;
                            newNode->LeftChild = ParentNode;
                            leftRotation(ParentNode->data);
                            return;
                        }
                        else if (ParentNode->RightChild == newNode)
                        {
                            UncleNode = FindUncle(newNode->data);
                            if (UncleNode == nullptr)
                            {
                                rightRotation(newNode->data);
                            }
                            else if (UncleNode->color == 'r')
                            {
                                cout << "Recolor" << endl;
                                Recolor(newNode->data);
                            }
                            else if (UncleNode->color == 'b')
                            {
                                rightRotation(newNode->data);
                            }
                        }
                    }
                }
                else
                {
                    temp = temp->RightChild;
                    RBTinsertionCode(val, temp);
                }
            }
            else if (val < temp->data)
            {

                if (temp->LeftChild == nullptr)
                {
                    temp->LeftChild = newNode;
                    ParentNode = FindParent(newNode->data);
                    if (ParentNode->color == 'r' && newNode->color == 'r')
                    {
                        GrandParentNode = FindGrandParent(newNode->data);
                        if (ParentNode->LeftChild == newNode && GrandParentNode->RightChild == ParentNode)
                        {
                            GrandParentNode = FindGrandParent(newNode->data);
                            GrandParentNode->RightChild = nullptr;
                            ParentNode->LeftChild = nullptr;
                            GrandParentNode->RightChild = newNode;
                            newNode->RightChild = ParentNode;
                            rightRotation(ParentNode->data);
                            return;
                        }
                        else if (ParentNode->LeftChild == newNode)
                        {
                            UncleNode = FindUncle(newNode->data);
                            if (UncleNode == nullptr)
                            {
                                leftRotation(newNode->data);
                            }
                            else if (UncleNode->color == 'b')
                            {
                                leftRotation(newNode->data);
                            }
                            else if (UncleNode->color == 'r')
                            {
                                Recolor(newNode->data);
                            }
                        }
                    }
                }
                else
                {
                    temp = temp->LeftChild;
                    RBTinsertionCode(val, temp);
                }
            }
        }
    }
    void destroyTree(Node *temp) //Function to Destroy Tree
    {
        if (temp == nullptr)
        {
            return;
        }
        destroyTree(temp->RightChild);
        destroyTree(temp->LeftChild);

        temp->LeftChild = nullptr;
        temp->RightChild = nullptr;
        temp->color = '\0';
        temp->data = NULL;
        temp->count = NULL;
        delete temp->LeftChild;
        delete temp->RightChild;
        delete temp;

    }
};
