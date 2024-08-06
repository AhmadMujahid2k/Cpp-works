#include"Paragraph.h"
void Paragraph::punctuation()
{
	int char_counter = 0, pun_counter = 0;
	for (int i = 0; i < count_para - 1; i++)
	{
		cout << "Paragraph number " << i + 1 << " : " << endl;
		char_counter = 0;
		pun_counter = 0;
		for (int j = 0; j < count_sent[i]; j++)
		{
			for (int k = 0; k < count_word[i][j]; k++)
			{
				for (int l = 0; paragraph[i][j][k][l] != ' ' && paragraph[i][j][k][l] != '\0' && paragraph[i][j][k][l] != '\n'; l++)
				{
					if ((paragraph[i][j][k][l] >= 'a' && paragraph[i][j][k][l] <= 'z') || (paragraph[i][j][k][l] >= 'A' && paragraph[i][j][k][l] <= 'Z'))
					{
						char_counter++;
					}
					if (paragraph[i][j][k][l] == '.' || paragraph[i][j][k][l] == '?' || paragraph[i][j][k][l] == ',' || paragraph[i][j][k][l] == '!' || paragraph[i][j][k][l] == ':' || paragraph[i][j][k][l] == ';' || paragraph[i][j][k][l] == '-' || paragraph[i][j][k][l] == '_' || paragraph[i][j][k][l] == '(' || paragraph[i][j][k][l] == ')' || paragraph[i][j][k][l] == '"' || paragraph[i][j][k][l] == 39)
					{
						pun_counter++;
					}
				}
			}
		}
		cout << "Total english characters in paragraph : " << char_counter << endl;
		cout << "Total punctutation marks in paragraph : " << pun_counter << endl;
	}
	
}
void Paragraph::frequency()
{
	int sent_C = 0, word_C = 0, char_C = 0, para_C = count_para - 1;
	cout << "Total paragraphs in file : " << para_C << endl << endl;
	for (int i = 0; i < para_C; i++)
	{
		word_C = 0;
		cout << "Total sentences in Paragraph number " << i + 1 << " : " << count_sent[i] - 1 << endl;
		sent_C = sent_C + (count_sent[i] - 1);

		for (int j = 0; j < count_sent[i] - 1; j++)
		{
			if (paragraph[i][j][0][0] == ' ')
			{
				cout << "Total words in sentence number " << j + 1 << " : " << count_word[i][j] - 1 << endl;
				word_C = word_C + (count_word[i][j] - 1);

				for (int k = 1; k < count_word[i][j]; k++)
				{
					char_C = 0;
					for (int l = 0; paragraph[i][j][k][l] != ' ' && paragraph[i][j][k][l] != '\0' && paragraph[i][j][k][l] != '\n'; l++)
					{
						if ((paragraph[i][j][k][l] >= 'a' && paragraph[i][j][k][l] <= 'z') || (paragraph[i][j][k][l] >= 'A' && paragraph[i][j][k][l] <= 'Z'))
						{
							char_C++;
						}
					}
					cout << "Total characters in word number " << k << " : " << char_C << endl;
				}
			}
			else
			{
				cout << "Total words in sentence number " << j + 1 << " : " << count_word[i][j] << endl;
				word_C = word_C + (count_word[i][j]);

				for (int k = 0; k < count_word[i][j]; k++)
				{
					char_C = 0;
					for (int l = 0; paragraph[i][j][k][l] != ' ' && paragraph[i][j][k][l] != '\n' && paragraph[i][j][k][l] != '\0'; l++)
					{
						if ((paragraph[i][j][k][l] >= 'a' && paragraph[i][j][k][l] <= 'z') || (paragraph[i][j][k][l] >= 'A' && paragraph[i][j][k][l] <= 'Z'))
						{
							char_C++;
						}
					}
					cout << "Total characters in word number " << k + 1 << ": " << char_C << endl;
				}
			}
		}
		cout << "Total words in Paragraph number " << i + 1 << " :" << word_C << endl;
	}
	cout << "Total sentences in file : " << sent_C << endl;
}
void Paragraph::frequency(ofstream& output)
{
	int sent_C = 0, word_C = 0, char_C = 0, para_C = count_para - 1;
	output << "Total paragraphs in file : " << para_C << endl << endl;
	for (int i = 0; i < para_C; i++)
	{
		word_C = 0;
		output << "Total sentences in Paragraph number " << i + 1 << " : " << count_sent[i] - 1 << endl;
		sent_C = sent_C + (count_sent[i] - 1);

		for (int j = 0; j < count_sent[i] - 1; j++)
		{
			if (paragraph[i][j][0][0] == ' ')
			{
				output << "Total words in sentence number " << j + 1 << " : " << count_word[i][j] - 1 << endl;
				word_C = word_C + (count_word[i][j] - 1);

				for (int k = 1; k < count_word[i][j]; k++)
				{
					char_C = 0;
					for (int l = 0; paragraph[i][j][k][l] != ' ' && paragraph[i][j][k][l] != '\0' && paragraph[i][j][k][l] != '\n'; l++)
					{
						if ((paragraph[i][j][k][l] >= 'a' && paragraph[i][j][k][l] <= 'z') || (paragraph[i][j][k][l] >= 'A' && paragraph[i][j][k][l] <= 'Z'))
						{
							char_C++;
						}
					}
					output << "Total characters in word number " << k << " : " << char_C << endl;
				}
			}
			else
			{
				output << "Total words in sentence number " << j + 1 << " : " << count_word[i][j] << endl;
				word_C = word_C + (count_word[i][j]);

				for (int k = 0; k < count_word[i][j]; k++)
				{
					char_C = 0;
					for (int l = 0; paragraph[i][j][k][l] != ' ' && paragraph[i][j][k][l] != '\n' && paragraph[i][j][k][l] != '\0'; l++)
					{
						if ((paragraph[i][j][k][l] >= 'a' && paragraph[i][j][k][l] <= 'z') || (paragraph[i][j][k][l] >= 'A' && paragraph[i][j][k][l] <= 'Z'))
						{
							char_C++;
						}
					}
					output << "Total characters in word number " << k + 1 << ": " << char_C << endl;
				}
			}
		}
		output << "Total words in Paragraph number " << i + 1 << " :" << word_C << endl;
	}
	output << "Total sentences in file : " << sent_C << endl;
}
char**** Paragraph :: getpara()
{
	return paragraph;
}
int* Paragraph::getCountSent()
{
	return count_sent;
}
int** Paragraph::getCountWord()
{
	return count_word;
}
int Paragraph::getCpara()
{
	return count_para;
}
int Paragraph::getTchar()
{
	return total_char;
}
int Paragraph::getTpun()
{
	return total_pun;
}
bool Paragraph::operator+()
{
	for (int i = 0; i < count_para; i++)
	{
		for (int j = 0; j < count_sent[i]; j++)
		{
			for (int k = 0; k < count_word[i][j]; k++)
			{
				for (int l = 0; paragraph[i][j][k][l] != ' ' && paragraph[i][j][k][l] != '\0' && paragraph[i][j][k][l] != '\n'; l++)
				{
					if (paragraph[i][j][k][l] >= 'a' && paragraph[i][j][k][l] <= 'z')
					{
						paragraph[i][j][k][l] = paragraph[i][j][k][l] - 32;
					}
				}
			}
		}
	}
	return true;
}
bool Paragraph::operator-()
{
	for (int i = 0; i < count_para; i++)
	{
		for (int j = 0; j < count_sent[i]; j++)
		{
			for (int k = 0; k < count_word[i][j]; k++)
			{
				for (int l = 0; paragraph[i][j][k][l] != ' ' && paragraph[i][j][k][l] != '\n' && paragraph[i][j][k][l] != '\0'; l++)
				{
					if (paragraph[i][j][k][l] >= 'A' && paragraph[i][j][k][l] <= 'Z')
					{
						paragraph[i][j][k][l] = paragraph[i][j][k][l] + 32;
					}
				}
			}
		}
	}
	return true;
}
bool Paragraph::operator=(Paragraph obj)
{
	for (int i = 0; i < count_para; i++)
	{
		for (int j = 0; j < count_sent[i]; j++)
		{
			for (int k = 0; k < count_word[i][j]; k++)
			{
				this->paragraph[i][j][k] = obj.paragraph[i][j][k];
			}
		}
	}
	return true;
}
bool Paragraph::operator==(Paragraph obj)
{
	bool check = true;
	if (this->count_para == obj.count_para)
	{
		for (int i = 0; i < this->count_para; i++)
		{
			if (this->count_sent[i] == obj.count_sent[i])
			{
				for (int j = 0; j < this->count_sent[i]; j++)
				{
					if (obj.count_word[i][j] == this->count_word[i][j])
					{
						for (int k = 0; k < this->count_word[i][j]; k++)
						{
							if (obj.paragraph[i][j][k] == this->paragraph[i][j][k])
							{
								check = true;
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
				}
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
	return check;
}
bool Paragraph::operator!=(Paragraph obj)
{
	bool check = true;
	for (int i = 0; i < obj.count_para; i++)
	{
		for (int j = 0; j < obj.count_sent[i]; j++)
		{

			for (int k = 0; k < obj.count_word[i][j]; k++)
			{
				if (obj.paragraph[i][j][k] != this->paragraph[i][j][k])
				{
					check = true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return check;
}
void Paragraph::regrowSentencesNumber(int**& para, int& size)
{
	int counter = 0;
	int** temp = new int* [size + 1];
	while (counter < size)
	{
		temp[counter] = para[counter];
		counter++;
	}
	temp[counter] = new int[1]{ 1 };
	delete[] para;
	para = temp;
}
void Paragraph::regrowSenetenceSize(int*& para, int& size)
{
	int counter = 0;
	int* temp = new int[size + 2];
	while (counter < size + 1)
	{
		temp[counter] = para[counter];
		counter++;
	}
	temp[counter] = 1;
	delete[] para;
	para = temp;
	size++;
}
void Paragraph::regrowWord(char*& para, char data)
{
	int counter = 0;
	char* temp = new char[strlen(para) + 2];
	while (para[counter] != '\0')
	{
		temp[counter] = para[counter];
		counter++;
	}
	temp[counter] = data;
	temp[counter + 1] = '\0';
	delete[] para;
	para = temp;
}
void Paragraph::regrowWordsArray(char**& para, int& size)
{
	int counter = 0;
	char** temp = new char* [size + 1];
	while (counter < size)
	{
		temp[counter] = para[counter];
		counter++;
	}
	temp[counter] = new char[1]{};

	delete[] para;
	para = temp;
	size++;
}
void Paragraph::regrowSentenceArray(char***& para, int& size)
{
	int counter = 0;
	char*** temp = new char** [size + 1];
	while (counter < size)
	{
		temp[counter] = para[counter];
		counter++;
	}
	temp[counter] = new char* [1]{};
	temp[counter][0] = new char[1]{};

	delete[] para;
	para = temp;
	size++;
}
void Paragraph::regrowParagraphArray(char****& para, int& size)
{
	int counter = 0;
	char**** temp = new char*** [size + 1];
	while (counter < size)
	{
		temp[counter] = para[counter];
		counter++;
	}
	temp[counter] = new char** [1]{};
	temp[counter][0] = new char* [1]{};
	temp[counter][0][0] = new char[1]{};

	delete[] para;
	para = temp;
	size++;
}
ifstream& operator>>(ifstream& input, Paragraph& obj)
{
	char filename[10],ch;
	cout << "Enter file name along with .txt : ";
	cin >> filename;
	input.open(filename);
	int para_index = 0, sent_index = 0, word_index = 0;
	while (input.get(ch))
	{
		obj.regrowWord(obj.paragraph[para_index][sent_index][word_index], ch);
		if (ch == ' ')
		{

			obj.regrowWordsArray(obj.paragraph[para_index][sent_index], obj.count_word[para_index][sent_index]);
			word_index++;
		}
		else if (ch == '.' || ch == '!' || ch == '?')
		{
			word_index = 0;
			obj.regrowSenetenceSize(obj.count_word[para_index], sent_index);
			obj.regrowSentenceArray(*(obj.paragraph + para_index), obj.count_sent[para_index]);
		}
		else if (ch == '\n')
		{
			sent_index = 0;
			word_index = 0;
			obj.regrowSenetenceSize(obj.count_sent, para_index);
			obj.regrowSentencesNumber(obj.count_word, para_index);
			obj.regrowParagraphArray(obj.paragraph, obj.count_para);
		}
	}
	return input;
}