#include "My_Sentence.h"
bool My_Sentence :: operator+()
{
    if (check_Upper == false)
    {
        for (int i = 0; i < counter1; i++)
        {
            if (word_arr[i] >= 'a' && word_arr[i] <= 'z')
            {
                word_arr[i] = word_arr[i] - 32;
            }
        }
        check_Upper = true;
        return check_Upper;
    }
    else
    {
        return false;
    }
}
bool My_Sentence ::operator-()
{
    if (check_Upper == true)
    {
        for (int i = 0; i < counter1; i++)
        {
            if (word_arr[i] >= 'A' && word_arr[i] <= 'Z')
            {
                word_arr[i] = word_arr[i] + 32;
            }
        }
        check_Upper = false;
        return true;
    }
    else
    {
        return false;
    }
}
bool My_Sentence :: operator%(int e)
{
    
    if (check_Encrypt == false)
    {
        for (int i = 0; i < counter1; i++)
        {
            int upper = (word_arr[i] + e);
            upper = upper - 65;
            upper = upper % 26;
            upper = upper + 65;
            int lower = (word_arr[i] + e );
            lower = lower - 97;
            lower = lower % 26;
            lower = lower + 97;
            if (word_arr[i] >= 'A' && word_arr[i] <= 'Z')
            {
                word_arr[i] = char(upper);
            }
            else if (word_arr[i] >= 'a' && word_arr[i] <= 'z')
            {
                word_arr[i] = char(lower);
            }
            else
            {
                word_arr[i] = word_arr[i] + e;
            }
        }
        check_Encrypt = true;
        return check_Encrypt;
    }
    else
    {
        return false;
    }
}
bool My_Sentence :: operator*(int d)
{
    if (check_Encrypt == true)
    {
        for (int i = 0; i < counter1; i++)
        {
            int upper = (word_arr[i] + (26 - d));
            upper = upper - 65;
            upper = upper % 26;
            upper = upper + 65;
            int lower = (word_arr[i] + (26 - d));
            lower = lower - 97;
            lower = lower % 26;
            lower = lower + 97;
            if (word_arr[i] >= 'A' && word_arr[i] <= 'Z')
            {
                word_arr[i] = char(upper);
            }
            else if (word_arr[i] >= 'a' && word_arr[i] <= 'z')
            {
                word_arr[i] = char(lower);
            }
            else
            {
                word_arr[i] = word_arr[i] - d;
            }
        }
        check_Encrypt = false;
        return true;
    }
    else
    {
        return false;
    }   
}
bool My_Sentence ::operator==(const My_Sentence& obj)
{
    if (this->counter1 == obj.counter1)
    {
        for (int i = 0; i < counter1; i++)
        {
            if (this->word_arr[i] != obj.word_arr[i])
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
void My_Sentence::sent_Dictionary()
{
    string word, dictionary;
    for (int i = 0; i < counter1; i++)
    {
        if (word_arr[i] >= 'A' && word_arr[i] <= 'Z')
        {
            word_arr[i] = word_arr[i] + 32;
        }
    }
    bool flag = true, go = false;
    int index = 0;
    for (int i = 0; i < counter1; i++)
    {
        while (word_arr[index] >= 'a' && word_arr[index] <= 'z')
        {
            word = word + word_arr[index];
            i++;
            index++;
            go = true;
        }
        index++;
        if (go == true)
        {
            ifstream fin("Dictionary.txt");
            for (int j = 0; !fin.eof(); j++)
            {
                fin >> dictionary;
                if (word == dictionary)
                {
                    flag = true;
                    break;
                }
                else
                {
                    flag = false;
                }
            }
            if (flag == false)
            {
                cout << word << endl;
            }
            word = "";
            fin.close();
            go = false;
        }
    }
}
void My_Sentence::setSentence(char* w)
{
    for (int i = 0; i < strlen(w); i++)
    {
        word_arr[counter1] = w[i];
        word_arr = Regrow_sent(word_arr, word_index);
        word_index++;
        counter1++;
    }
    word_arr[counter1] = ' ';
    word_arr = Regrow_sent(word_arr, word_index);
    word_index++;
    counter1++;
}
void My_Sentence::displaySentence()
{
    for (int i = 0; i < counter1; i++)
    {
        cout << word_arr[i];
    }
}
void My_Sentence::WordLength()
{
    int Word_counter = 1;
    int total = 0;
    for (int i = 0; i < counter1; i++)
    {
        if (word_arr[i] >= 'a' && word_arr[i] <= 'z' || word_arr[i] >= 'A' && word_arr[i] <= 'Z')
        {
            total++;
        }
        else if (word_arr[i] != '.' && word_arr[i] != '?' && word_arr[i] != '!' && word_arr[i] != ',' && word_arr[i] != ';' && word_arr[i] != ':' && word_arr[i] != '_' && word_arr[i] != '-' && word_arr[i] != '(' && word_arr[i] != ')' && word_arr[i] != '{' && word_arr[i] != '}' && word_arr[i] != '[' && word_arr[i] != ']' && word_arr[i] != 39 && word_arr[i] != '"' && word_arr[i] != '*')
        {
            cout << "Total number of characters in word " << Word_counter << " are : " << total << endl;
            total = 0;
            Word_counter++;
        }
    }
}
void My_Sentence::WordLength(ofstream& output)
{
    int Word_counter = 1;
    int total = 0;
    for (int i = 0; i < counter1; i++)
    {
        if (word_arr[i] >= 'a' && word_arr[i] <= 'z' || word_arr[i] >= 'A' && word_arr[i] <= 'Z')
        {
            total++;
        }
        else if (word_arr[i] != '.' && word_arr[i] != '?' && word_arr[i] != '!' && word_arr[i] != ',' && word_arr[i] != ';' && word_arr[i] != ':' && word_arr[i] != '_' && word_arr[i] != '-' && word_arr[i] != '(' && word_arr[i] != ')' && word_arr[i] != '{' && word_arr[i] != '}' && word_arr[i] != '[' && word_arr[i] != ']' && word_arr[i] != 39 && word_arr[i] != '"' && word_arr[i] != '*')
        {
            output << "Total number of characters in word " << Word_counter << " are : " << total << endl;
            total = 0;
            Word_counter++;
        }
    }
}
void My_Sentence::CountPunctuation(int& Punctuation)
{
    for (int i = 0; i < counter1; i++) {

        if (word_arr[i] == '.' || word_arr[i] == '?' || word_arr[i] == '!' || word_arr[i] == ',' || word_arr[i] == ';' || word_arr[i] == ':' || word_arr[i] == '_' || word_arr[i] == '-' || word_arr[i] == '(' || word_arr[i] == ')' || word_arr[i] == '{' || word_arr[i] == '}' || word_arr[i] == '[' || word_arr[i] == ']' || word_arr[i] == 39 || word_arr[i] == '"' || word_arr[i] == '*')
        {
            Punctuation++;
        }

    }
}
char* My_Sentence::Regrow_sent(char* oldArray, int size)
{
    char* newArray = NULL;
    newArray = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = oldArray[i];
        newArray[i + 1] = '\0';
    }
    size++;
    oldArray = NULL;
    delete[]oldArray;
    return newArray;
}
char* My_Sentence::GetSetence()
{
    return word_arr;
}
int My_Sentence::CountWord()
{
    int total = 0;
    for (int i = 0; i < counter1; i++)
    {
        if (word_arr[i] == ' ')
        {
            total++;
        }
    }
    return total;
}