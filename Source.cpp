#include "Header.h"

Student::Student()
{
	cout << "\tEnter name, surname, group and age of a student\n";
	cin >> Name >> Surname >> Group >> Age;

	Marks["English"] = 0;
	Marks["Maths"] = 0;
	Marks["Literature"] = 0;
	Marks["PE"] = 0;
	Marks["IT"] = 0;
	Marks["History"] = 0;
	Marks["Physics"] = 0;

	for (map<string, int>::iterator SetIt = Marks.begin(); SetIt != Marks.end(); SetIt++)
	{
		cout << "\tEnter student's " << SetIt->first << " mark\n";
		cin >> SetIt->second;
	}
}

void Student::getStudent()
{
	cout << "\tInfo about student\n\t" << Name << " " << Surname << " " << Group << " " << Age << endl;
	cout << "\tStudent's marks are:\n";

	for (map<string, int>::const_iterator GetIt = Marks.begin(); GetIt != Marks.end(); GetIt++)
	{
		cout << "\t" << GetIt->first << " - " << GetIt->second << endl;
	}
}

void Student::replaceInfo()
{
	cout << "\tWhat info you want to replace? Type 'Name', 'Surname', 'Group' or 'Age'\n";
	string *temp = new string;
	WI:
	cin >> *temp;

	SWITCH(*temp)
	{
		CASE("Name") :
		{
			cout << "\tEnter new name\n";
			cin >> *temp;
			Name = *temp;
			break;
		}
		CASE("Surname") :
		{
			cout << "\tEnter new surname\n";
			cin >> *temp;
			Surname = *temp;
			break;
		}
		CASE("Group") :
		{
			cout << "\tEnter new group\n";
			cin >> *temp;
			Group = *temp;
			break;
		}
		CASE("Age") :
		{
			int *tempI = new int;
			cout << "\tEnter new age\n";
			cin >> *tempI;
			Age = *tempI;
			delete tempI;
			break;
		}
	DEFAULT :
		{
			cout << "\tWrong input, try again\n";
			goto WI;
			break;
		}
	}

	delete temp;
}

void Student::replaceMarks()
{
	cout << "\tWhich mark you want to replace? Type 'English', 'Maths', 'Literature', 'PE', 'History', 'Physics' or 'IT'\n";
	string* temp = new string;
	int *tempI = new int;
	WIM:
	cin >> *temp;

	if (*temp == "English" || *temp == "Maths" || *temp == "Literature" || *temp == "PE" || *temp == "IT" || *temp == "History" || *temp == "Physics")
	{
		cout << "\tEnter new " << *temp << " mark\n";
		cin >> *tempI;
		Marks[*temp] = *tempI;
	}
	else
	{
		cout << "\tWrong input, try again\n";
		goto WIM;
	}

	delete temp;
	delete tempI;
}

void Student::addStudent()
{
	Student* temp = new Student;
	StudentsVector.push_back(*temp);
}

void Student::deleteStudent()
{
	if (StudentsVector.size() == 0)
	{
		cout << "\tThere are no students, add first\n";
	}
	else
	{
		int* temp = new int;
		cout << "\tThere are " << StudentsVector.size() << " students, choose who you want to delete\n";
		cin >> *temp;

		if (*temp < 1 || *temp > StudentsVector.size())
		{
			cout << "\tThere is no student under this number, try again\n";
		}
		else
		{
			StudentsVector.erase(StudentsVector.begin() + *temp - 1);
			cout << "\tStudent number " << *temp << " was deleted\n";
		}
		
		delete temp;
	}
}

void Student::getAll()
{
	int *temp = new int;

	if (StudentsVector.size() == 0)
	{
		cout << "\tThere are no students, add first\n";
	}
	else
	{
		cout << "\tThere are " << StudentsVector.size() << " students, choose whom info you want to get\n";
		cin >> *temp;

		if (*temp < 1 || *temp > StudentsVector.size())
		{
			cout << "\tThere is no student under this number, try again\n";
		}
		else
		{
			StudentsVector[*temp - 1].getStudent();
		}
	}

	delete temp;
}

void Student::replaceAll()
{
	if (StudentsVector.size() == 0)
	{
		cout << "\tThere are no students, add first\n";
	}
	else
	{
		int* tempI = new int;
		cout << "\tThere are " << StudentsVector.size() << " students, choose whom info you want to replace\n";
		cin >> *tempI;

		if (*tempI < 1 || *tempI > StudentsVector.size())
		{
			cout << "\tThere is no student under this number, try again\n";
		}
		else
		{
			cout << "\tEnter what you want to replace, 'Marks' or 'General'\n";
			string* temp = new string;
			cin >> *temp;
			if (*temp == "Marks")
				StudentsVector[*tempI - 1].replaceMarks();
			else
			{
				if (*temp == "General") StudentsVector[*tempI - 1].replaceInfo();
				else
				{
					cout << "\tWrong input, try again\n";
				}
			}

			delete temp;
		}

		delete tempI;
	}
}