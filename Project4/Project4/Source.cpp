#include <iostream>
#include <fstream>
using namespace std;
bool isRecordPresent(int rollNumber)
{
	ifstream fin;
	fin.open("studentDB.txt");
	int rollNo;
	fin >> rollNo;
	while (!fin.eof())
	{
		if (rollNo == rollNumber)
		{
			return true;
		}
		else
		{
			fin.ignore();
			fin.ignore(100,'\n');
			fin.ignore(100, '\n');
		}
		fin >> rollNo;
	}
	fin.close();
	return false;
}
void addRecord(int rollNo, const char * arr , float gpa)
{
	ofstream fout;
	fout.open("studentDB.txt",ios::app);
	if (!isRecordPresent(rollNo))
	{
		fout << rollNo << endl;
		fout << arr << endl;
		fout << gpa << endl;
	}
	fout.close();
}
void deleteRecord(int rollNo)
{
	int rollNumber;
	char name[100];
	float gpa;
	ifstream fin;
	fin.open("studentDB.txt");
	fin >> rollNumber;
	ofstream temp;
	temp.open("temperory.txt");
	while (!fin.eof())
	{
		if (rollNo == rollNumber)
		{
			fin.ignore();
			fin.ignore(100, '\n');
			fin.ignore(100, '\n');
		}
		else
		{
			temp << rollNumber << endl;
			fin.ignore();
			fin.getline(name,100);
			temp << name << endl;
			//fin.ignore();
			fin >> gpa;
			fin.ignore();
			temp << gpa << endl;
		}
		fin >> rollNumber;
	}
	fin.close();
	temp.close();
	remove("studentDB.txt");
	rename("temperory.txt", "studentDB.txt");
}
int main()
{
	//cout<<isRecordPresent(4);
	//addRecord(5, "Anas Shafiq", 2.9);
	//deleteRecord(5);
	cout << endl;
	return 0;
}
