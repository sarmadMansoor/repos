#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout;
	fout.open("test.dat", ios::binary);
	if (!fout.is_open())
	{
		cout << "File is not open\n";
	}
	else
	{
		int arr[5] = { 65,90,97,98,99 };
		int* p = arr;
		fout.write(reinterpret_cast<char*>(p),sizeof(int)*5);
		fout.close();
	}



	ifstream fin;
	fin.open("test.dat", ios::binary);
	if (!fin.is_open())
	{
		cout << "File is not found\n";
	}
	else
	{
		int arr[5];
		int* p = arr;
		fin.read(reinterpret_cast<char*>(p), sizeof(int) * 5);
		fout.close();
		for (int i = 0; i < 5; i++)
		{
			cout << arr[i] << '\t';
		}
	}
}