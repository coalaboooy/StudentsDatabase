#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "str_switch.h"
using namespace std;

class Student
{
private:
	string Name;
	string Surname;
	string Group;
	int Age;
	map <string, int> Marks;
public:
	Student();
	void getStudent();
	void replaceInfo();
	void replaceMarks();
	static void getAll();
	static void replaceAll();
	static void addStudent();
	static void deleteStudent();
};

static vector<Student> StudentsVector;