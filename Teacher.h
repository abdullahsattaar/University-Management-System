#pragma once
#include<iostream>
#include<string>
using namespace std;
class Teacher {
	string name;
	int id;
public:
	Teacher() {
		name = '\0';
		id = 0;
	}
	Teacher(int i,char n) {
		name = n;
		id = i;
	}
	void SetName(string n) {
		name = n;
	}
	string GetName() {
		return name;
	}
	void SetId(int i) {
		id = i;
	}
	int GetID() {
		return id;
	}
};