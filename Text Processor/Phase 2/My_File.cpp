#include "My_File.h"
bool My_File :: operator+()
{
    bool check = true;
    for (int i = 0; i <= counter3; i++)
    {
        check = paragraph_arr[i].operator+();
    }
    return check;
}
bool My_File :: operator-()
{
    bool check = true;
    for (int i = 0; i <= counter3; i++)
    {
        check = paragraph_arr[i].operator-();
    }
    return check;
}
bool My_File :: operator%(int e)
{
    bool check = true;
    for (int i = 0; i <= counter3; i++)
    {
        check = paragraph_arr[i].operator%(e);
    }
    return check;
}
bool My_File :: operator*(int d)
{
    bool check = true;
    for (int i = 0; i <= counter3; i++)
    {
        check = paragraph_arr[i].operator*(d);
    }
    return check;
}
void My_File:: file_Dictionary()
{
    for (int i = 0; i <= counter3; i++)
    {
        cout << "Words in Paragraphs number " << i + 1 << " not found in Dictionary : " << endl;
        paragraph_arr[i].para_Dictionary();
    }
}
void My_File::setfile(char* w, char check)
{
    if (check != '\n')
    {
        paragraph_arr[counter3].SetParagraph(w, check);
    }
    else if (check == '\n')
    {
        paragraph_arr[counter3].SetParagraph(w, check);
        paragraph_arr = Regrow(paragraph_arr);
        paragraph_index++;
        counter3++;
    }
}
void My_File::displayFile()
{
    for (int i = 0; i <= counter3; i++)
    {
        paragraph_arr[i].displayParagraph();
        cout << endl;
    }
}
void My_File::CountChar(int num)
{
    paragraph_arr[num].CountChar();
}
void My_File::CountChar(int num, ofstream& output)
{
    paragraph_arr[num].CountChar(output);
}
void My_File::CountPunctuation()
{
    int Punctuation = 0, total = 0;
    for (int i = 0; i <= counter3; i++)
    {
        paragraph_arr[i].CountPunctuation(Punctuation);
        total = total + Punctuation;
        cout << "Total Puncuations in Paragraph number " << i +1 << " : " << total << endl;
        total = Punctuation = 0;
    }
}
void My_File::display_Frequency()
{
    for (int i = 0; i <= getNumberOfParagraphs(); i++)
    {
        cout << "Total number of   words   in paragraph number " << i + 1 << " are : " << word_paragraph(i) << endl;
        cout << "Total number of sentences in paragraph number " << i + 1 << " are : " << GetSentence(i) << endl;
        CountChar(i);
        cout << endl;
    }
}
void My_File::check_Paragraph()
{
    cout << "Total number of paragraps are : " << (counter3 + 1 )<< endl;
    int para1 = 0, para2 = 0;
    cout << endl << "To compare 2 paragraphs enter paragraph number below." << endl;
    cout << "First paragraph number: ";
    cin >> para1;
    My_Paragraph p1 = ParagraphNumber((para1 - 1));
    cout << "Second paragraph number: ";
    cin >> para2;
    My_Paragraph p2 = ParagraphNumber((para2 - 1));
    if (p1 == p2)
    {
        cout << "Both paragraphs are same" << endl;
    }
    else
    {
        cout << "Both paragraphs are not the same" << endl;
    }
}
void My_File::merge_Paragraph()
{
    My_Paragraph P;
    cout << "Total number of paragraps are : " << (counter3 + 1) << endl;
    int para1 = 0, para2 = 0;
    cout << endl << "To merge 2 paragraphs enter paragraph number below." << endl;
    cout << "First paragraph number: ";
    cin >> para1;
    My_Paragraph p1 = ParagraphNumber((para1 - 1));
    cout << "Second paragraph number: ";
    cin >> para2;
    My_Paragraph p2 = ParagraphNumber((para2 - 1));
    P = p1 + p2;
    P.displayParagraph();
}
void My_File::output_Frequency(ofstream& output)
{
    for (int i = 0; i <= getNumberOfParagraphs(); i++)
    {
        output << "Total number of words in paragraph number " << i + 1 << " are : " << word_paragraph(i) << endl;
        output << "Total number of sentences in paragraph number " << i + 1 << " are : " << GetSentence(i) << endl;
        CountChar(i, output);
        output << endl;
    }
}
int My_File::word_paragraph(int num)
{
    for (int i = num; i <= counter3; i++)
    {
        return paragraph_arr[i].count_words();
    }
}
int My_File::getNumberOfParagraphs()
{
    return counter3;
}
int My_File::GetSentence(int num)
{
    for (int i = num; i <= counter3; i++)
    {
        return paragraph_arr[i].getNumberOfSentence();
    }
}
My_Paragraph* My_File::Regrow(My_Paragraph* paragraph_arr)
{
    My_Paragraph* newArray = NULL;
    newArray = new My_Paragraph[paragraph_index + 1];
    for (int i = 0; i < paragraph_index; i++)
    {
        newArray[i] = paragraph_arr[i];
    }
    paragraph_arr = NULL;
    delete[]paragraph_arr;
    return newArray;
}
My_Paragraph My_File::ParagraphNumber(int num)
{
    return paragraph_arr[num];
}