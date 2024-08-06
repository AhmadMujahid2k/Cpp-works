#include "My_Paragraph.h"
My_Paragraph  My_Paragraph :: operator+(const My_Paragraph& two)
{
    My_Paragraph obj;
    int temp = this->counter2 ;
    obj.counter2 = this->counter2 + two.counter2 ;
    obj.sentence_index = this->sentence_index + two.sentence_index;
    for (int i = 0; i < this->counter2 ; i++)
    {
        obj.sentence_arr[i] = this->sentence_arr[i];
    }
    for (int i = 0; i < two.counter2 ; i++)
    {
        obj.sentence_arr[temp] = two.sentence_arr[i];
        temp++;
    }
    return obj;
}
bool My_Paragraph :: operator+()
{
    bool check = true;
    for (int i = 0; i < counter2; i++)
    {
        check = sentence_arr[i].operator+();
    }
    return check;
}
bool My_Paragraph :: operator-()
{
    bool check = true;
    for (int i = 0; i < counter2; i++)
    {
        check = sentence_arr[i].operator-();
    }
    return check;
}
bool My_Paragraph :: operator%(int e)
{
    bool check = true;
    for (int i = 0; i < counter2; i++)
    {
       check =  sentence_arr[i].operator%(e);
    }
    return check;
}
bool My_Paragraph :: operator*(int d)
{
    bool check = true;
    for (int i = 0; i < counter2; i++)
    {
        check = sentence_arr[i].operator*(d);
    }
    return check;
}
bool My_Paragraph :: operator==(const My_Paragraph& obj)
{
    if (this->counter2 == obj.counter2)
    {
        for (int i = 0; i < this->counter2; i++)
        {
            if (this->sentence_arr[i] == obj.sentence_arr[i])
            {

            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}
void My_Paragraph:: para_Dictionary()
{
    for (int i = 0; i < counter2; i++)
    {
        sentence_arr[i].sent_Dictionary();
    }
}
void My_Paragraph::SetParagraph(char* w, char Check)
{
    if (w[strlen(w) - 1] != '.' && w[strlen(w) - 1] != '?' && w[strlen(w) - 1] != '!')
    {
        sentence_arr[counter2].setSentence(w);
    }
    else if ((w[strlen(w) - 1] == '.' || w[strlen(w) - 1] == '?' || w[strlen(w) - 1] == '!') && (Check == ' ' || Check == '\n'))
    {
        sentence_arr[counter2].setSentence(w);
        sentence_arr = Regrow(sentence_arr);
        sentence_index++;
        counter2++;

    }
}
void My_Paragraph::displayParagraph()
{
    for (int i = 0; i < counter2; i++)
    {
        sentence_arr[i].displaySentence();
    }
}
void My_Paragraph::CountChar()
{
    for (int i = 0; i < counter2; i++)
    {
        cout << "Sentence number " << i + 1 << " : " << endl;
        sentence_arr[i].WordLength();
    }
}
void My_Paragraph::CountChar(ofstream& output)
{
    for (int i = 0; i < counter2; i++)
    {
        output << "Sentence number " << i + 1 << " : " << endl;
        sentence_arr[i].WordLength(output);
    }
}
void My_Paragraph::CountPunctuation(int& Punctuation)
{
    for (int i = 0; i < counter2; i++)
    {
        sentence_arr[i].CountPunctuation(Punctuation);
    }
}
int My_Paragraph::count_words()
{
    int Total = 0;
    for (int i = 0; i < counter2; i++)
    {
        Total = Total + sentence_arr[i].CountWord();
    }
    return Total;
}
int My_Paragraph::getNumberOfSentence()
{
    return counter2;
}
My_Sentence* My_Paragraph::Regrow(My_Sentence* oldArray)
{
    My_Sentence* newArray = NULL;
    newArray = new My_Sentence[sentence_index + 1];
    for (int i = 0; i < sentence_index; i++)
    {
        newArray[i] = oldArray[i];
    }
    oldArray = NULL;
    delete[]oldArray;
    return newArray;
}
My_Sentence* My_Paragraph::GetSentenceList()
{
    return sentence_arr;
}