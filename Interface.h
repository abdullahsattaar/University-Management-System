#pragma once
#include<iostream>
#include<fstream>
#include"AcademicOfficer.h"
#include"Teacher.h"
#include"Student.h"
#include"Courses.h"
#include"Registration.h"
#include<stdlib.h>
#include<string>
using namespace std;
Courses ListOfCourses[100];
Student ListOfStudents[100];
Registration listOfReg[100];
int counterStudent = 0;
int countreg;
int counter = 0;
bool Compare(string key, int &index) {
	for (int i = 0; i < counter; ++i)
		if (key == ListOfCourses[i].GetCode()) {
			index = i;
			return true;
		}
	return false;
}
Courses AddCourse()
{
	string cc, cn;
	cout << "Enter course code: ";
	cin >> cc;
	cout << "Enter course name: ";
	cin >> cn;
	
	Courses Course(cc,cn);
	cout << "\nCourse added\n" << "Course Code: " << cc << "\nCourse Name: " << cn << "\nCurrent No of Sections: " << Course.GetSections() << endl;
	ofstream outfile;
	outfile.open("Courses.txt", std::ios_base::app);
	outfile << Course.GetCode() << " ";
	outfile << Course.GetName() << endl;
	outfile.close();
	return Course;
}
void RemoveCourse()
{
	string key;
	int index;
	cout << "Enter course code to remove: ";
	cin >> key;
	if(Compare(key,index)){
		for (int i = index; i < counter; ++i)
			ListOfCourses[i] = ListOfCourses[i + 1];
		counter--;

		ofstream outfile;
		outfile.open("Courses.txt");
		for (int i = 0; i < counter; ++i) {
			outfile << ListOfCourses[i].GetCode() << " ";
			outfile << ListOfCourses[i].GetName() << endl;
		}
		outfile.close();
	}
	else
		cout << "Invalid Course code " << endl;
		
}
void UpdateCourseInfo()
{
	int index;
	string key;
	cout << "Enter course code: ";
	cin >> key;
	if (Compare(key, index)) {
		string cc, cn;
		cout << "Enter new course code: ";
		cin >> cc;
		cout << "Enter new course name: ";
		cin >> cn;

		ListOfCourses[index].SetCode(cc);
		ListOfCourses[index].Setname(cn);
		cout << "\nCourse Updated\n" << "Course Code: " << cc << "\nCourse Name: " << cn << endl;
		ofstream outfile;
		outfile.open("Courses.txt");
		int i = 0;
		while (i < counter) {
			outfile << ListOfCourses[i].GetCode() << " ";
			outfile << ListOfCourses[i].GetName() << endl;
			++i;
		}
		outfile.close();
	}
	else
		cout << "Invalid course code" << endl;
}
void AddSection()
{
	int index;
	string key;
	char s;
	cout << "Enter course code: ";
	cin >> key;
	if (Compare(key, index)) {
		cout << "Enter section ";
		cin >> s;
		ListOfCourses[index].SetSection(s);
	}
	else
		cout << "Invalid course code" << endl;
}
void RegisterCourse(string id)
{
	int index;
	string key;
	cout << "Enter course code: ";
	cin >> key;
	if (Compare(key, index)) {
		listOfReg[countreg].Setcourse(ListOfCourses[index]);
		listOfReg[countreg].SetStudent(id);
		ofstream outfile;
		outfile.open("Registeration.txt", std::ios_base::app);
		outfile << listOfReg[countreg].Getcourse().GetCode() << " ";
		outfile << listOfReg[countreg].Getstudent() << endl;
		outfile.close();
		countreg++;
		cout << "Course registered successfully " << endl;
	}
	else
		cout << "Invalid code" << endl;
}
void ViewTranscript(string id)
{
	float total=0;
	double cgpa=0;
	for (int i = 0; i < countreg; ++i) {
		if (listOfReg[i].Getstudent() == id)
		{
			total++;
			cout << "Course: " << listOfReg[i].Getcourse().GetCode() << " " << listOfReg[i].Getcourse().GetName() << " Grade: " << listOfReg[i].GetGrade()<<endl;
			if (listOfReg[i].GetGrade() == 'A')
				cgpa = cgpa+ 4;
			if (listOfReg[i].GetGrade() == 'B')
				cgpa = cgpa + 3;
			if (listOfReg[i].GetGrade() == 'C')
				cgpa = cgpa + 2;
			if(listOfReg[i].GetGrade()=='D')
				cgpa = cgpa + 1;
		}
	}
	if (total == 0)
		cout << "Student no registered in any course!!!!!" << endl;
	else {
		cgpa = cgpa / (total * 3);
		cout << "CGPA is: " << cgpa << endl;
	}
}
void SetEvaluations()
{
	int index;
	string key;
	char s;
	cout << "Enter course code: ";
	cin >> key;
	int i=-1;
	if (Compare(key, index)) {
		while (i != 0) {
			cout << "\n\t\t\tEnter <1> Set Assignment Weights"
				<< "\n\t\t\tEnter <2> Set Quiz Weights"
				<< "\n\t\t\tEnter <3> Set Mids Weights"
				<< "\n\t\t\tEnter <4> Set Finals Weights"
				<< "\n\t\t\tEnter <0> To Exit\n";
			cout << "\n\n\t\t\tEnter Your Choice: ";
			cin >> i;
			if (i == 1) {
				cout << "Enter Weights: ";
				int w;
				cin >> w;
				ListOfCourses[index].GetMarks().SetWAssign(w);
				cout << "Weights updated successfully" << endl;
			}
			if (i == 2) {
				cout << "Enter Weights: ";
				int w;
				cin >> w;
				ListOfCourses[index].GetMarks().SetWQuiz(w);
				cout << "Weights updated successfully" << endl;
			}
			if (i == 3) {
				cout << "Enter Weights: ";
				int w;
				cin >> w;
				ListOfCourses[index].GetMarks().SetWMid(w);
				cout << "Weights updated successfully" << endl;
			}
			if (i == 4) {
				cout << "Enter Weights: ";
				int w;
				cin >> w;
				ListOfCourses[index].GetMarks().SetWFinals(w);
				cout << "Weights updated successfully" << endl;
			}
		}
	}
	else
		cout << "Invalid course code" << endl;
}
void EnterMarks()
{
	int j=-1;
	string code,id;
	char s;
	cout << "Enter course code: ";
	cin >> code;
	cout << "Enter student ID: ";
	cin >> id;
	int flag = 0;
	for (int i = 0; i < countreg; ++i) {
		if (listOfReg[i].Getstudent() == id && listOfReg[i].Getcourse().GetCode() == code) {
			while (j != 0) {
				cout << "\n\t\t\tEnter <1> Set Assignment Marks"
					<< "\n\t\t\tEnter <2> Set Quiz Marks"
					<< "\n\t\t\tEnter <3> Set Mids Marks"
					<< "\n\t\t\tEnter <4> Set Finals Marks"
					<< "\n\t\t\tEnter <0> To Exit\n";
				cout << "\n\n\t\t\tEnter Your Choice: ";
				cin >> j;
				if (j == 1) {
					cout << "Enter Marks: ";
					int w;
					cin >> w;
					listOfReg[i].GetMarks().SetAssign(w);
					cout << "Marks updated successfully" << endl;
				}
				if (j == 2) {
					cout << "Enter Marks: ";
					int w;
					cin >> w;
					listOfReg[i].GetMarks().SetQuiz(w);
					cout << "Marks updated successfully" << endl;
				}
				if (j == 3) {
					cout << "Enter Marks: ";
					int w;
					cin >> w;
					listOfReg[i].GetMarks().SetMid(w);
					cout << "Marks updated successfully" << endl;
				}
				if (j == 4) {
					cout << "Enter Marks: ";
					int w;
					cin >> w;
					listOfReg[i].GetMarks().SetFinals(w);
					cout << "Marks updated successfully" << endl;
				}
			}
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "Invalid combination" << endl;
}
void PerformanceReport()
{
	int j = -1;
	string code, id;
	char s;
	cout << "Enter course code: ";
	cin >> code;
	cout << "Enter student ID: ";
	cin >> id;
	int flag = 0;
	for (int i = 0; i < countreg; ++i) {
		if (listOfReg[i].Getstudent() == id && listOfReg[i].Getcourse().GetCode() == code) {
			cout << "Assignment Marks: 4" << listOfReg[i].GetMarks().GetAssign() << endl;
			cout << "Quiz Marks: 2" << listOfReg[i].GetMarks().Getquiz() << endl;
			cout << "Mids Marks: 1" << listOfReg[i].GetMarks().Getmid() << endl;
			cout << "Finals Marks: 7" << listOfReg[i].GetMarks().Getfinals() << endl;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "Invalid combination" << endl;
}

void AcademicOfficer()
{
	system("CLS");
	cout << "\t\t\t-----------------------------------------\n";
	cout << "\t\t\t     University Management System\n";
	cout << "\t\t\t-----------------------------------------\n";
	cout << "\t\t\tAcademic Officer Portal\n";
	int i = -1;
	while (i!=0)
	{
		cout << "\n\t\t\tEnter <1> Add Course"
			<< "\n\t\t\tEnter <2> Remove Course"
			<< "\n\t\t\tEnter <3> Update Course Information"
			<< "\n\t\t\tEnter <4> Add Section to Course"
			<< "\n\t\t\tEnter <0> To Exit\n";
		cout << "\n\n\t\t\tEnter Your Choice: ";
		cin >> i;
		if(i==1){
			ListOfCourses[counter++] = AddCourse();
		}
		else if(i==2){
			RemoveCourse();
		}
		else if(i==3){
			UpdateCourseInfo();
		}
		else if(i==4){
			AddSection();
		}
		else
			cout << "\nWRONG CHOICE!!!\nTRY AGAIN";
	}
}

void Teacher()
{
	system("CLS");
	cout << "\t\t\t-----------------------------------------\n";
	cout << "\t\t\t     University Management System\n";
	cout << "\t\t\t-----------------------------------------\n";
	cout << "\t\t\t Teacher Portal\n";
	int i = -1;
	while (i != 0)
	{
		cout << "\n\t\t\tEnter <1> Set Evaluations"
			<< "\n\t\t\tEnter <2> Enter Marks"
			<< "\n\t\t\tEnter <3> View Performance Report"
			<< "\n\t\t\tEnter <0> To Exit\n";
		cout << "\n\n\t\t\tEnter Your Choice: ";
		cin >> i;
		if (i == 1) 
			SetEvaluations();
		else if (i == 2)
			EnterMarks();
		else if (i == 3)
			PerformanceReport();
		else if (i == 0)
			cout << "";
		else
			cout << "\nWRONG CHOICE!!!\nTRY AGAIN";
		
	}
}

void student()
{
	string id;
	int flag = 0;;
	cout << "Enter your Id ";
	cin >> id;
	for (int i = 0; i < 100; ++i) {
		if (id == ListOfStudents[i].GetID())
			flag = 1;
	}
	if (flag == 1) {
		system("CLS");
		cout << "\t\t\t-----------------------------------------\n";
		cout << "\t\t\t     University Management System\n";
		cout << "\t\t\t-----------------------------------------\n";
		cout << "\t\t\t Student Portal\n";
		int i = -1;
		while (i != 0)
		{
			cout << "\n\t\t\tEnter <1> Register Course"
				<< "\n\t\t\tEnter <2> View Transcript"
				<< "\n\t\t\tEnter <0> To Exit\n";
			cout << "\n\n\t\t\tEnter Your Choice: ";
			cin >> i;
			if (i == 1) {
				RegisterCourse(id);
			}
			if (i == 2) {
				ViewTranscript(id);
			}
		}
	}
	else
		cout << "Invalid ID" << endl;
}

void interface()
{
	ifstream indata; // indata is like cin
	string data;
	indata.open("Courses.txt"); // opens the file
	if (!indata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	indata >> data;
	string cname, ccode;
	while (!indata.eof()) { // keep reading until end-of-file
		ListOfCourses[counter].SetCode(data);
		indata >> data;
		ListOfCourses[counter].Setname(data);
		indata >> data;
		counter++;
	}
	indata.close();
	indata; // indata is like cin
	data;
	indata.open("Students.txt"); // opens the file
	if (!indata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	indata >> data;
	cname, ccode;
	while (!indata.eof()) { // keep reading until end-of-file
		ListOfStudents[counterStudent].SetId(data);
		indata >> data;
		ListOfStudents[counterStudent].SetName(data);
		indata >> data;
		counterStudent++;
	}
	indata.close();

	indata; // indata is like cin
	data;
	indata.open("Registeration.txt"); // opens the file
	if (!indata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	indata >> data;
	cname, ccode;
	while (!indata.eof()) { // keep reading until end-of-file
		listOfReg[countreg].Setcourse(data);
		indata >> data;
		listOfReg[countreg].SetStudent(data);
		indata >> data;
		countreg++;
	}
	indata.close();
	system("CLS");
	int i = -1;
	while (i != 0)
	{
		system("CLS");
		cout << "\t\t\t-----------------------------------------\n";
		cout << "\t\t\t     University Management System\n";
		cout << "\t\t\t-----------------------------------------\n";
		cout << "\n\t\t\tLOGIN AS"
			<< "\n\t\t\tEnter <1> Academic Officer"
			<< "\n\t\t\tEnter <2> Teacher"
			<< "\n\t\t\tEnter <3> Student"
			<< "\n\t\t\tEnter <0> to Exit\n";
		cout << "\n\n\t\t\tEnter Your Choice: ";
		cin >> i;
		switch (i)
		{
			case 1:
				AcademicOfficer();
				break;
			case 2:
				Teacher();
				break;
			case 3:
				student();
				break;
			case 0:
				break;
			default:
				i = -1;
				cout << "\nWRONG CHOICE!!!\nTRY AGAIN";
		}
	}
}
