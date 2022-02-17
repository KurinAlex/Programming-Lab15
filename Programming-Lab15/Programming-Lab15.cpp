#include <iostream>
#include <fstream>

#include "Student.h"

using namespace std;

const string file_name = "DA-82.dat";
ifstream fin;
ofstream fout;

void output_list()
{
	fin.open(file_name, ofstream::binary);
	if (!fin.is_open())
	{
		cout << "File cannot open a file for reading" << endl;;
		return;
	}

	int count = 0;
	Student student;
	fin.read((char*)&student, sizeof(Student));
	while (!fin.eof())
	{
		cout << "Student " << ++count << ":" << endl;
		cout << "\tSurname: " << student.surname << endl;
		cout << "\tInitials: " << student.initials << endl;
		cout << "\tPhone number: " << student.phone_number << endl;

		fin.read((char*)&student, sizeof(Student));
	}
	if (count == 0)
	{
		cout << "List is empty" << endl;
	}

	fin.close();
}

void input_list()
{
	fout.open(file_name, ofstream::binary | ofstream::trunc);
	if (!fout.is_open())
	{
		cout << "File cannot open a file for writing" << endl;;
		return;
	}

	int students_count;
	cout << "Enter number of students: ";
	cin >> students_count;
	cout << endl;

	Student student;
	for (int i = 0; i < students_count; i++)
	{
		cout << "Enter student " << i + 1 << endl;

		cout << "\tEnter surname: ";
		cin >> student.surname;

		cout << "\tEnter initials: ";
		cin >> student.initials;

		cout << "\tEnter phone number: ";
		cin >> student.phone_number;

		fout.write((char*)&student, sizeof(Student));
	}
	cout << endl;

	fout.close();
}

void find_phone_number()
{
	fin.open(file_name, ofstream::binary);
	if (!fin.is_open())
	{
		cout << "File cannot open a file for reading" << endl;
		return;
	}

	string surname;
	cout << "Enter student's surname: ";
	cin >> surname;

	string initials;
	cout << "Enter student's initials: ";
	cin >> initials;

	Student student;
	bool is_found = false;
	fin.read((char*)&student, sizeof(Student));
	while (!fin.eof())
	{
		if (student.surname == surname && student.initials == initials)
		{
			cout << "Phone number is: " << student.phone_number << endl;
			is_found = true;
			break;
		}
		fin.read((char*)&student, sizeof(Student));
	}
	if (!is_found)
	{
		cout << "No such student in file" << endl;
	}

	fin.close();
}

int main()
{
	while (true)
	{
		system("cls");

		cout << "   MENU" << endl;
		cout << "1. Output list of students" << endl;
		cout << "2. Input list of students" << endl;
		cout << "3. Find student's phone number" << endl;
		cout << "4. Exit" << endl;
		cout << endl;

		int answer;
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1:
			output_list();
			break;
		case 2:
			input_list();
			break;
		case 3:
			find_phone_number();
			break;
		case 4:
			return 0;
		default:
			cout << "Try one more time..." << endl;;
			break;
		}
		cout << "Press any key..." << endl;
		cin.get();
		cin.get();
	}
}