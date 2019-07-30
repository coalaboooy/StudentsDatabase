#include "Header.h"

int main()
{
	int comm;
	bool quit = true;
	
	cout << "\tEnter numbers to use commands\n";
	
	while (quit)
	{
		cout << "\t1 - Add a student\n\t2 - Get information about a student\n\t3 - Change information about a student\n\t4 - Delete a student\n\t0 - Exit\n";
		cin >> comm;
		switch (comm)
		{
		case 1:
		{
			Student::addStudent();
			break;
		}
		case 2:
		{
			Student::getAll();
			break;
		}
		case 3:
		{
			Student::replaceAll();
			break;
		}
		case 4:
		{
			Student::deleteStudent();
			break;
		}
		case 0:
		{
			quit = false;
			break;
		}
		default:
		{
			cout << "\tThere is no such command, try again\n";
			break;
		}
		}
	}
	return 0;
}