#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount, int sum, int* c);
void Stovb(int** a, const int rowCount, const int colCount, int* c);
void Calc(int** a, const int rowCount,int colCount);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	int* c = new int [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Input(a, rowCount, colCount);	
	Print(a, rowCount, colCount, 0, c);
	Stovb(a, rowCount, colCount, c);
	Print(a, rowCount, colCount, 0, c);
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}
void Print(int** a, const int rowCount, const int colCount, int sum, int* c)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		sum = 0;
		for (int j = 0; j < colCount; j++)
		{
			if (a[i][j] > 0 && a[i][j] % 2 == 0) sum += a[i][j];
			cout << setw(4) << a[i][j];
		}
		cout << " sum=" << sum << " ";
		c[i] = sum;
		cout << endl;
	}
	cout << endl;
}
void Stovb(int** a, const int rowCount, const int colCount, int* c)
{
	int n = rowCount, m = colCount;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (c[j] > c[j + 1])
			{
				swap(c[j], c[j + 1]);
				swap(a[j], a[j + 1]);
			}
}
