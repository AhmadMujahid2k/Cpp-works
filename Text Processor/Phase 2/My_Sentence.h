#include <iostream>
#include <fstream>
using namespace std;
class My_Sentence
{
private:
    int word_index = 1, counter1 = 0;
    bool check_Encrypt = false, check_Upper = false;
    char* word_arr = new char[word_index];
public:
    My_Sentence() = default;
    bool operator+();
    bool operator-();
    bool operator%(int e);
    bool operator*(int d);
    bool operator==(const My_Sentence& obj);
    void sent_Dictionary();
    void setSentence(char* w);
    void displaySentence();
    void WordLength();
    void WordLength(ofstream& output);
    void CountPunctuation(int& Punctuation);
    char* Regrow_sent(char* oldArray, int size);
    char* GetSetence();
    int CountWord();
    ~My_Sentence()
    {
       // delete[] word_arr;
    }
};