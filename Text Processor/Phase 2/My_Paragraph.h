#include <iostream>
#include <fstream>
#include"My_Sentence.h"
using namespace std;
class My_Paragraph
{
private:
    int sentence_index = 1, counter2 = 0;                           // counter2 = total sentences in each paragraphs 
    My_Sentence* sentence_arr = new My_Sentence[sentence_index];
public:
    My_Paragraph() = default;
    My_Paragraph operator+(const My_Paragraph& two);
    bool operator+();
    bool operator-();
    bool operator%(int e);    
    bool operator*(int d);
    bool operator==(const My_Paragraph& obj);
    void para_Dictionary();
    void SetParagraph(char* w, char Check);
    void displayParagraph();
    void CountChar();
    void CountChar(ofstream& output);
    void CountPunctuation(int& Punctuation);
    int count_words();
    int getNumberOfSentence();
    My_Sentence* Regrow(My_Sentence* oldArray);
    My_Sentence* GetSentenceList();
    ~My_Paragraph()
    {
       // delete[] sentence_arr;
    }
};