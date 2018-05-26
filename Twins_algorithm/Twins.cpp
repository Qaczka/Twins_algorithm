#include <iostream>

using namespace std;

int main(int argc, char* argv)
{
	int potega;
	bool pamiec[2048];
	int proces[6][3];//wielkosc - adres wpisu - dlugosc
	proces[0][0] = 10;
	proces[1][0] = 218;
	proces[2][0] = 583;
	proces[3][0] = 46;
	proces[4][0] = 87;
	proces[5][0] = 114;

	for (int i = 0; i < 2048; i++)
	{
		pamiec[i] = true;
	}

	for (int i = 0; i < 6; i++)
	{
		potega = 2048;
		while (proces[i][0] < potega/2)
		{
			potega /= 2;
		}
		cout << proces[i][0] << " zmiesci sie w " << potega << " bajtach" << endl;

		int sektor = 0;

		while (pamiec[sektor*potega] == false)
		{
			sektor += 1;
			if (sektor*potega > 2048)
			{
				cout << "Nie znaleziono miejsca dla " << proces[i];
				break;
			}
		}

		for (int c = 0; c < potega; c++)
		{
			pamiec[sektor*potega+c] = false;
		}
		cout << "Zajalem sektor od " << sektor * potega << " do " << sektor * potega + potega << endl;
		proces[i][1] = sektor * potega;
		proces[i][2] = potega;
	}

	for (int i = 0; i < 2048; i++)
	{
		if (pamiec[i] == true)
		{
			cout << ".";
		}
		else
		{
			cout << "x";
		}
		if (i % 100 == 0)
		{
			cout << endl;
		}
	}

	cout << endl << endl << "Teraz zwalnianie 4 z nich" << endl;

	for (int i = 2; i < 6; i++)
	{
		for (int c = 0; c < proces[i][2]; c++)
		{
			pamiec[proces[i][1] + c] = true;
		}
		cout << "Zwolnilem sektor od " << proces[i][1] << " do " << proces[i][1] + proces[i][2]<< endl;
	}

	for (int i = 0; i < 2048; i++)
	{
		if (pamiec[i] == true)
		{
			cout << ".";
		}
		else
		{
			cout << "x";
		}
		if (i % 100 == 0)
		{
			cout << endl;
		}
	}

	potega = 2048;
	while (32 < potega / 2)
	{
		potega /= 2;
	}
	cout << 32 << " zmiesci sie w " << potega << " bajtach" << endl;

	int sektor = 0;

	while (pamiec[sektor*potega] == false)
	{
		sektor += 1;
		if (sektor*potega > 2048)
		{
			cout << "Nie znaleziono miejsca dla " << 32;
			break;
		}
	}

	for (int c = 0; c < potega; c++)
	{
		pamiec[sektor*potega + c] = false;
	}
	cout << "Zajalem sektor od " << sektor * potega << " do " << sektor * potega + potega << endl;

	for (int i = 0; i < 2048; i++)
	{
		if (pamiec[i] == true)
		{
			cout << ".";
		}
		else
		{
			cout << "x";
		}
		if (i % 100 == 0)
		{
			cout << endl;
		}
	}


	system("PAUSE");
	return 0;
}