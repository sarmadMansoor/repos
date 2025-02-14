#include <iostream>
#include "Array.h"
#include <fstream>
#include "Matrix.h"
using namespace  std;
ostream& operator << (ostream & rfs, Array & r)
{
	for (int i = 0; i < r.size; i++)
	{
		if (r.size - 1 == i)
		{
			cout << r.data[i];
		}
		else
		{
			cout << r.data[i] << " ";
		}
	}
	return rfs;
}
int main()
{

	Matrix  m{ 7,21 };
	for (int i = 0; i < m.getRows(); i++)
	{
		for (int j = 0; j < m.getCols(); j++)
		{
			m[i][j] = 1;
		}
	}
	m.display();
	//Matrix a{ 3,3 };
	//a[0][0] = 1;
	//a[0][1] = 2;
	//a[0][2] = 3;
	//a[1][0] = 4;
	//a[1][1] = 5;
	//a[1][2] = 6;
	//a[2][0] = 7;
	//a[2][1] = 8;
	//a[2][2] = 9;
	//int r = a.getRows();
	//int c = a.getCols();
	//a.reSize(1, 1);
	//a[0][0] = 1;

	//a.display();
	//ofstream  ofs("mat.txt", ios::binary);
	//ofs.write((char*)&r, sizeof(int));
	//ofs.write((char*)&c, sizeof(int));
	////cout << r << "  " << c << endl;
	//for (int i = 0; i < r; i++)
	//{
	//	ofs.write((char*)&(a[i][0]),4*c);
	//}
	////ofs.write((char*)&(a[0][0]),);
	////ofs.write((char*)&(a[1][0]), sizeof(4 * c));
	////ofs.write((char*)&(a[2][0]), sizeof(4 * c));

	//ofs.close();

	/*int tr;
	int tc;
	Matrix m;
	ifstream ifs("mat.txt", ios::binary);
	ifs.read((char*)&tr, sizeof(int));
	ifs.read((char*)&tc, sizeof(int));
	m.reSize(tr, tc);
	for (int i=0;i<tr;i++)
	{
		ifs.read((char*)&(m[i][0]), 4*tc);
	}
	ifs.close();

	m.display();*/
////	a.display();
//	//Array a{ 3,2,1 };
//	////cout << a[1] << endl;;
//	////cout << a[0];
//	////a[3] = 7;
//	//cout << a;


	/*Array h = { 5,1,2,3,4,5 };
	cout << h;*/

	/*Array h = { 5,1,2,3,4,5 };
	Array h1 = { 5,1,2,3,4,5 };
	Array h2 = { 5,11,22,33,44,55 };
	Array h3 = { 5,4,5,3,4,5 };
	ofstream ofs("test.txt", ios::binary);


	int szieOfH = h.getSize();
	ofs.write((char*)&szieOfH,sizeof(int));
	ofs.write((char*)&h[0], h.getSize()*4);

	int szieOfH1 = h1.getSize();
	ofs.write((char*)&szieOfH1, sizeof(int));
	ofs.write((char*)&h1[0], h1.getSize() * 4);


	int szieOfH2 = h2.getSize();
	ofs.write((char*)&szieOfH2, sizeof(int));
	ofs.write((char*)&h2[0], h2.getSize() * 4);

	int szieOfH3 = h3.getSize();
	ofs.write((char*)&szieOfH3, sizeof(int));
	ofs.write((char*)&h3[0], h3.getSize() * 4);
	ofs.close();
	ifstream ifs("test.txt", ios::binary);
	if (!ifs)
	{
		cout << "file not found\n";
	}
	Array k{0};
	int size;
	ifs.seekg(0,ios::end);
	cout << ifs.peek() << endl;
	cout << "eof () is : " << ifs.eof() << endl;
	cout << "fail () is : " << ifs.fail() << endl;
	char a;
	ifs >> a;*/
	//cout << "fail () is : " << ifs.fail() << endl;

	/*ifs.read((char*)&size, sizeof(int));
	k.reSize(size);
	cout << "size is : " << size << endl;
	ifs.read((char*)&k[0], size * 4);*/
	//ifs.close();
	//cout << k << endl;;
	//cout << "ah";

	return 0;
}