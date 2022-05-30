#pragma once
#include<iostream>
#include"Courses.h"
#include"Marks.h"
#include"Student.h"
using namespace std;
int randi(int lo, int hi)
{
	int n = hi - lo + 1;
	int i = rand() % n;
	if (i < 0) i = -i;
	return lo + i;
}
class Registration {
	Courses course;
	string student;
	char grade;
	Marks marks;
public:
	Registration() {
		course;
		student;
		int r = randi(1,4);
		if (r == 1)
			grade = 'A';
		if (r == 2)
			grade = 'B';
		if (r == 3)
			grade = 'C';
		if(r==4)
			grade = 'D';
	}
	void Setcourse(string c) {
		course.SetCode(c);
	}
	void Setcourse(Courses c) {
		course = c;
	}
	void Setgrade(char g) {
		grade = g;
	}
	Courses Getcourse() {
		return course;
	}
	char GetGrade() {
		return grade;
	}
	void SetStudent(string s) {
		student = s;
	}
	string Getstudent() {
		return student;
	}
	Marks GetMarks() {
		return marks;
	}
};