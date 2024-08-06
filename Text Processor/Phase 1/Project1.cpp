#include"Paragraph.h"
ostream& operator<<(ostream& out, Paragraph& p1)
{
	for (int i = 0; i < p1.getCpara(); i++)
	{
		for (int j = 0; j < p1.getCountSent()[i]; j++)
		{
			for (int k = 0; k < p1.getCountWord()[i][j]; k++)
			{
				out << p1.getpara()[i][j][k];
			}
		}
	}
	return out;
}
ofstream& operator<<(ofstream& output, Paragraph& p1)
{
	output.open("frequency.txt");
	p1.frequency(output);
	return output;
}
int main()
{
	Paragraph P, p1;
	ifstream input;
	input >> P;

	cout << endl << "Data : " << endl;
	cout << P;

	if (P.operator+() == true)
	{
		cout << endl << "File in UpperCase." << endl;
		cout << P << endl;
	}
	if (P.operator-() == true)
	{
		cout << endl << "File in LowerCase." << endl;
		cout << P << endl;
	}

	cout << endl << "Frequency : " << endl;
	P.frequency();

	cout << endl << "Punctuation : ";
	P.punctuation();
	
	ofstream output;
	output << P;

	input.close();
	output.close();
}

