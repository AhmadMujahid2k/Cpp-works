#include <iostream>
#include <fstream>
#include"My_Paragraph.h"
using namespace std;
class My_File
{
private:
    int paragraph_index = 1, counter3 = 0;                                  // counter3 = total paragraphs in file
    My_Paragraph* paragraph_arr = new My_Paragraph[paragraph_index];
public:
    My_File() = default;
    bool operator+();
    bool operator-();
    bool operator%(int e);
    bool operator*(int d);
    void file_Dictionary();
    void setfile(char* w, char check);
    void displayFile();
    void CountChar(int num);
    void CountChar(int num, ofstream& output);
    void CountPunctuation();
    void display_Frequency();
    void check_Paragraph();
    void merge_Paragraph();
    void output_Frequency(ofstream& output);
    int word_paragraph(int num);
    int getNumberOfParagraphs();
    int GetSentence(int num);
    My_Paragraph* Regrow(My_Paragraph* paragraph_arr);
    My_Paragraph ParagraphNumber(int num);
    ~My_File()
    {
        //delete[] paragraph_arr;
    }
};