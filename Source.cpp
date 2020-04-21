
//#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;


int sundaram(int n)
{
	int *a = new int[n], i, j, k;
	memset(a, 0, sizeof(int) * n);
	for (i = 1; 3 * i + 1 < n; i++)
	{
		for (j = 1; (k = i + j + 2 * i*j) < n && j <= i; j++)
			a[k] = 1;
	}

	for (i = n - 1; i >= 1; i--)
		if (a[i] == 0)
		{
			return (2 * i + 1);
			break;
		}
	delete[] a;
}

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}

int main()
{


	srand((unsigned)time(NULL));
	int p = rand() % 100;
	int q = rand() % 100;
	int p_simple = sundaram(p);
	int q_simple = sundaram(q);
	unsigned int n = p_simple * q_simple;
	int d, d_simple = 0;
	while (d_simple != 1)
	{
		d = rand() % 100;
		d_simple = gcd(d, ((p_simple - 1)*(q_simple - 1)));
	}
	unsigned int e = 0, e_simple = 0;
	while (e_simple != 1)
	{
		e += 1;
		e_simple = (e*d) % ((p_simple - 1)*(q_simple - 1));
	}

	cout << '{' << e << ','  << n << '}' << " - Open key" << endl;
	cout << '{'  << d << ',' << n << '}' << " - Secret key" << endl << endl;

	int MAX = 32;
	char *Text = new char[MAX];
	cout << "Please enter the Text. Use <Enter> button when done." << endl;
	cin.get(Text, MAX);


	unsigned int *CryptoText = new unsigned int[MAX];
	unsigned int *Tdecrypt = new unsigned int[MAX];

	int b = 301;
	int c;

	for (int j = 0; j < MAX; j++)
	{
		c = 1;
		unsigned int i = 0;
		int ASCIIcode = (static_cast<int>(Text[j])) + b;
		while (i < e)
		{
			c = c * ASCIIcode;
			c = c % n;
			i++;
		}
		CryptoText[j] = c;
		b += 1;
	}

	b = 301;
	int m;
	for (int j = 0; j < MAX; j++)
	{
		m = 1;
		unsigned int i = 0;
		while (i < d)
		{
			m = m * CryptoText[j];
			m = m % n;
			i++;
		}
		m = m - b;
		Tdecrypt[j] = m;
		b += 1;
	}
	cout << "Data:" << endl;
	for (int j = 0; j < MAX; j++)
	{
		if(Text[j]!=NULL);
		cout << Text[j];
	}
	cout << endl;
	cout << "CryptData:" << endl;
	for (int j = 0; j < MAX; j++)
	{
		if (CryptoText[j] != NULL);
		cout << CryptoText[j] << "  ";
	}
	cout << endl;

	cout << "UnCryptData:" << endl;
	for (int j = 0; j < MAX; j++)
	{
		if (Tdecrypt[j] != NULL);
		cout << static_cast<char>(Tdecrypt[j]);
	}
	cout << endl;
	delete[] Text;
	delete[] CryptoText;
	delete[] Tdecrypt;
	system("pause");
	return 0;
}


