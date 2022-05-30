#pragma once
#include<iostream>
using namespace std;
class Section {
	char name;
public:
	Section() {
		name = '\0';
	}
	Section(char n) {
		name = n;
	}
	void SetName(char n) {
		name = n;
	}
	char GetName() {
		return name;
	}
};