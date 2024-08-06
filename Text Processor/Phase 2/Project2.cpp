#include <iostream>
#include <fstream>
#include"My_File.h"
using namespace std;
ifstream& operator>>(ifstream& input, My_File& F)
{
    char* word = new char[20],Check;
    while (!input.eof())
    {
        input >> word;
        input.get(Check);
        F.setfile(word, Check);
    }
    return input;
}
ofstream& operator<<(ofstream& output, My_File& F)
{
    F.output_Frequency(output);
    return output;
}
ostream& operator<<(ostream& out, My_File& F)
{
    F.displayFile();
    return out;
}
int main()
{
    My_File my_file_obj;
    char filename[10];
    int option = 0, key = 0, temp_key = 0;
    cout << "Enter file name along with .txt : ";
    cin >> filename;

    ifstream input;
    input.open(filename);
    input >> my_file_obj;
    cout << endl << my_file_obj << endl;

    ofstream output;
    output.open("Frequency.txt");
    output  << my_file_obj;
    do 
    {
        cout << "Enter your desire option : " << endl;
        cout << "Enter 1 to see the Frequency of file ." << endl;
        cout << "Enter 2 to see File in Upper case ." << endl;
        cout << "Enter 3 to see File in Lower case ." << endl;
        cout << "Enter 4 to calculate punctuation ." << endl;
        cout << "Enter 5 to Encrypt File ." << endl;
        cout << "Enter 6 to Decrypt File ." << endl;
        cout << "Enter 7 to check two paragraph ." << endl;
        cout << "Enter 8 to merge two paragraph ." << endl;
        cout << "Enter 9 to check spelling ." << endl;
        cout << "Enter 0 Exit ." << endl;
        cin >> option;
        if (option == 1)
        {
            my_file_obj.display_Frequency();
            cout << endl << endl;
        }
        else if (option == 2)
        {
            if (my_file_obj.operator+() == true)
            {
                cout << endl << "File converted in UpperCase Successfuly." << endl;
                cout << "File : " << endl;
                cout << my_file_obj << endl;
            }
            else if (my_file_obj.operator+() == false)
            {
                cout << endl << "File is already in UpperCase." << endl;
                cout << "File : " << endl;
                cout << my_file_obj << endl;
            }
            cout << endl << endl;
        }
        else if (option == 3)
        {
            if (my_file_obj.operator-() == true)
            {
                cout << endl << "File converted in LowerCase Successfuly." << endl;
                cout << "File : " << endl;
                cout << my_file_obj << endl;
            }
            else if (my_file_obj.operator-() == false)
            {
                cout << endl << "File is already in LowerCase." << endl;
                cout << "File : " << endl;
                cout << my_file_obj << endl;
            }
            cout << endl << endl;
        }
        else if (option == 4)
        {
            my_file_obj.CountPunctuation();
            cout << endl << endl;
        }
        else if (option == 5)
        {
            cout << "Enter Encrypt key :";
            cin >> key;
            if (my_file_obj.operator%(key) == true)
            {
                cout << "Encrypted Successfuly" << endl << endl;
                cout << "File : " << endl;
                cout << my_file_obj;
                temp_key = key;
            }
            else if (my_file_obj.operator%(key) == false)
            {
                cout << "Already Encrypted" << endl;
                cout << "File : " << endl;
                cout << my_file_obj;
                key = temp_key;
            }
            cout << endl << endl;
        }
        else if (option == 6)
        {
            int key2 = 0;
            cout << "Enter Decrypt key :";
            cin >> key2;
            if (my_file_obj.operator*(key) == true)
            {
                if (key == key2)
                {
                    cout << "Decrypted Successfuly" << endl;
                    cout << "File : " << endl;
                    cout << my_file_obj;
                }
                else
                {
                    cout << "Wrong key input";
                }
            }
            else if (my_file_obj.operator*(key) == false)
            {
                cout << "Already Decrypted" << endl;
                cout << "File : " << endl;
                cout << my_file_obj;
            }
            cout << endl << endl;
        }
        else if (option == 7)
        {
            my_file_obj.check_Paragraph();
            cout << endl << endl;
        }
        else if (option == 8)
        {
            my_file_obj.merge_Paragraph();
            cout << endl << endl;
        }
        else if (option == 9)
        {
            my_file_obj.file_Dictionary();
            cout << endl << endl;
        }
    } while (option != 0);

    input.close();
    output.close();
}