#pragma once
#include<iostream>
#include<string>
using namespace std;
class Student {
	string name;
	string id;
	//Courses registered[7];
public:
	Student() {
		name = '\0';
		id = '\0';
	}
	Student(int i, char n) {
		name = n;
		id = i;
	}
	void SetName(string n) {
		name = n;
	}
	string GetName() {
		return name;
	}
	void SetId(string i) {
		id = i;
	}
	string GetID() {
		return id;
	}
};