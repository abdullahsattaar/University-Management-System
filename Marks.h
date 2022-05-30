#pragma once
#include<iostream>
using namespace std;
class Marks {
	int assign;
	int quiz;
	int mid;
	int finals;
	int wassign;
	int wmid;
	int wquiz;
	int wfinals;
public:
	Marks() {
		assign=0;
		quiz=0;
		mid=0;
		finals=0;
		wassign = 0;
		wmid = 0;
		wquiz = 0;
		wfinals = 0;
	}
	int GetAssign() {
		return assign;
	}
	int Getquiz() {
		return quiz;
	}
	int Getmid() {
		return mid;
	}
	int Getfinals() {
		return finals;
	}
	void SetAssign(int s){
		assign = s;
	}
	void SetMid(int s){
		mid = s;
	}
	void SetQuiz(int s){
		quiz = s;
	}
	void SetFinals(int s){
		finals = s;
	}
	int GetWAssign() {
		return wassign;
	}
	int GetWquiz() {
		return wquiz;
	}
	int GetWmid() {
		return wmid;
	}
	int GetWfinals() {
		return wfinals;
	}
	void SetWAssign(int s) {
		wassign = s;
	}
	void SetWMid(int s) {
		wmid = s;
	}
	void SetWQuiz(int s) {
		wquiz = s;
	}
	void SetWFinals(int s) {
		wfinals = s;
	}
};