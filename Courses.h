#pragma once
#include<iostream>
#include"Section.h"
#include<string>
#include"Marks.h"
using namespace std;

class Courses {
	string coursecode;
	string coursename;
	Section section[10];
	int noOfSection;
	Marks marks;
public:
	Courses() {
		coursecode = '\0';
		coursename = '\0';
		marks;
		for(int i=0;i<10;++i)
			section[i] = 0;
		noOfSection = 0;
	}
	Courses(string cc,string cn)
	{
		coursecode=cc;
		coursename=cn;
		for (int i = 0; i < 10; ++i)
			section[i] = 0;
		noOfSection = 0;
	}
	string GetName() {
		return coursename;
	}
	string GetCode() {
		return coursecode;
	}
	void SetCode(string c){
		coursecode = c;
	}
	void Setname(string c){
		coursename = c;
	}
	void SetSection(char s) {
		int flag=0;
		for (int i = 0; i < 10&&flag==0; ++i) {
			if (section[i].GetName() == s) {
				cout << "Section Already exists " << endl;
				flag = 1;
			}
		}
		if (flag == 0) {
			section[noOfSection].SetName(s);
			noOfSection++;
			cout << "Section successfully added " << endl;
		}
		for (int i = 0; i < noOfSection; ++i)
			cout << section[i].GetName();
	}
	Section* GetSections() {
		return section;
	}
	Marks GetMarks() {
		return marks;
	}
};
//int Courses::noOfSection = 0;