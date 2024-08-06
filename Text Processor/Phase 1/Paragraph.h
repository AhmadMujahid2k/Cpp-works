#pragma once
#include<fstream>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
class Paragraph
{
private:
	char**** paragraph;
	int** count_word;
	int* count_sent;
	int count_para, total_char, total_pun;
public:
	Paragraph()
	{
		paragraph = new char*** [1]{};
		paragraph[0] = new char** [1]{};
		paragraph[0][0] = new char* [1]{};
		paragraph[0][0][0] = new char[1]{};
		total_char = 0;
		total_pun = 0;
		count_para = 1;
		count_sent = new int[1]{ 1 };
		count_word = new int* [1];
		count_word[0] = new int[1]{ 1 };
	}
	bool operator ==(Paragraph obj);
	bool operator !=(Paragraph obj);
	bool operator=(Paragraph obj);
	bool operator+();
	bool operator-();
	char**** getpara();
	int* getCountSent();
	int** getCountWord();
	int getCpara();
	int getTchar();
	int getTpun();
	void punctuation();
	void frequency();
	void frequency(ofstream& output);
	void regrowWord(char*& p, char data);
	void regrowWordsArray(char**& p, int& size);
	void regrowSentenceArray(char***& p, int& size);
	void regrowParagraphArray(char****& p, int& size);
	void regrowSenetenceSize(int*& p, int& size);
	void regrowSentencesNumber(int**& p, int& size);
	friend ifstream& operator>>(ifstream& input, Paragraph& obj);
	~Paragraph()
	{
		for (int i = 0; i < count_para; i++)
		{
			for (int j = 0; j < count_sent[i]; j++)
			{
				for (int k = 0; k < count_word[i][j]; k++)
				{
					delete[] paragraph[i][j][k];
				}
				delete[] paragraph[i][j];
			}
			delete[] paragraph[i];
		}
		delete[] paragraph;
	}
};

