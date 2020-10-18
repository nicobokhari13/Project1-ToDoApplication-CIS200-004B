
#include <iostream>
#include "ToDo.h"
#include "Date.h"
#include "ToDoList.h"
// Type { UNASSIGNED = 0, SHOPPING = 1, CHORES = 2, WORK = 3, SCHOOL = 4 };
//enum Status { UNKNOWN = 0, DONE = 100, INCOMPLETE = 50, PLANNED = 10};
using namespace std;
void printMenu();
void copyTwoD(ToDo** arr,ToDoList items, int listSize);
void copythreeD(ToDo*** arr, ToDoList items, int listSize);

int main()
{
	srand(time(0));
	ToDoList arr[3];
	int m;
	int d;
	int y;
	std::cout << "Enter today's date: " << endl;
	std::cout << "Month: ";
	std::cin >> m;
	std::cout << "Day: ";
	std::cin >> d;
	std::cout << "Year: ";
	std::cin >> y;
	Date today = Date(m, d, y);
	char input = 'l';
	string t;
	string descript;
	int status;
	int priority;
	int type;
	int ID;
	int edit;
	string file;
	int pos;
	int listPos;
	printMenu();
	do {
		std::cin >> input;
		switch (input) {
		case 'a': {
			cout << "Which list do you want to add it to? 0 - 2: ";
			cin >> listPos; 
			pos = arr[listPos].addItem(ToDo());
			arr[listPos].list[pos].setID();
			ID = arr[listPos].list[pos].getID();
			cout << "ID: " + ID << endl;
			std::cout << "Enter your item's title: ";
			std::cin >> t;
			arr[listPos].editTitle(ID, t);
			std::cout << "Enter your item's description: ";
			std::cin >> descript;
			arr[listPos].editDescript(ID, descript);
			std::cout << "Enter the status: 100 = DONE, 50 = INCOMPLETE, 10 = PLANNED: ";
			std::cin >> status;
			switch (status) {
			case 100:
				arr[listPos].editStatus(ID, DONE);
				break;
			case 50:
				arr[listPos].editStatus(ID, INCOMPLETE);
				break;
			case 10:
				arr[listPos].editStatus(ID, PLANNED);
				break;
			default:
				arr[listPos].editStatus(ID, UNKNOWN);
				break;
			}
			std::cout << "Enter the priority between 1 and 5: ";
			std::cin >> priority;
			arr[listPos].editPriority(ID, priority);
			std::cout << "Enter the type~ UNASSIGNED = 0, SHOPPING = 1, CHORES = 2, WORK = 3, SCHOOL = 4: ";
			std::cin >> type;
			switch (type) {
			case 1:
				arr[listPos].editType(ID, SHOPPING);
				break;
			case 2:
				arr[listPos].editType(ID, CHORES);
				break;
			case 3:
				arr[listPos].editType(ID, WORK);
				break;
			case 4:
				arr[listPos].editType(ID, SCHOOL);
				break;
			default:
				arr[listPos].editType(ID, UNASSIGNED);
				break;
			}
			std::cout << "Enter the month of the Due Date: ";
			std::cin >> m;
			std::cout << endl;
			std::cout << "Enter the day: ";
			std::cin >> d;
			std::cout << endl;
			std::cout << "Enter the year: ";
			std::cin >> y;
			std::cout << endl;
			arr[listPos].editDue(ID, Date(m, d, y));
			arr[listPos].list[pos].setCreation(today);
			arr[listPos].list[pos].setLastMod(today);
			break;
		}
				//output file
		case 'o': {
			std::cout << "Enter the list you want to print, 0-2";
			cin >> listPos;
			std::cout << "Enter your desired file name: ";
			std::cin >> file;
			arr[listPos].outputToFile(file);
			break;
		}

				//read file
		case 'r':
			std::cout << "Enter the file name that you want to read: ";
			std::cin >> file;
			arr[0].readInFile(file);
			break;
			//clone
		case 'c': {
			arr[0].cloneList(arr[1]);
			break;
		}
				//edit existing todo item
		case 'e':
			for (int i = 0; i < ToDoList::numLists; i++) {
				arr[i].printAll();
			}
			std::cout << "Enter the ID of the To Do item to edit: ";
			std::cin >> ID;
			int list;
			for (int i = 0; i < ToDoList::numLists; i++) {
				for (int j = 0; j < MAX_SIZE; j++) {
					if (arr[i].list[j].getID() == ID) {
						list = i;
						break;
					}
				}
			}
			std::cout << "Enter the attribute to edit: 1 = title, 2 = description, 3 = type, 4 = status, 5 = date: ";
			std::cin >> edit;
			switch (edit) {
			case 1:
				std::cout << "Enter the new title: ";
				std::cin >> t;
				arr[list].editTitle(ID, t);
				break;
			case 2:
				std::cout << "Enter the new description: ";
				std::cin >> descript;
				arr[list].editDescript(ID, descript);
				break;
			case 3:
				std::cout << "Enter the new type: ";
				std::cin >> type;
				switch (type) {
				case 1:
					arr[0].editType(ID, SHOPPING);
					break;
				case 2:
					arr[0].editType(ID, CHORES);
					break;
				case 3:
					arr[0].editType(ID, WORK);
					break;
				case 4:
					arr[0].editType(ID, SCHOOL);
					break;
				default:
					arr[0].editType(ID, UNASSIGNED);
					break;
				}
				break;
			case 4:
				std::cout << "Enter the new status: ";
				std::cin >> status;
				switch (status) {
				case 100:
					arr[0].editStatus(ID, DONE);
					break;
				case 50:
					arr[0].editStatus(ID, INCOMPLETE);
					break;
				case 10:
					arr[0].editStatus(ID, PLANNED);
					break;
				default:
					arr[0].editStatus(ID, UNKNOWN);
					break;
				}
				break;
			case 5:
				std::cout << "Enter the month of the Due Date: ";
				std::cin >> m;
				std::cout << endl;
				std::cout << "Enter the day: ";
				std::cin >> d;
				std::cout << endl;
				std::cout << "Enter the year: ";
				std::cin >> y;
				std::cout << endl;
				arr[0].editDue(ID, Date(m, d, y));
				arr[0].list[pos].setLastMod(today);
				break;
			}
			break;
			//delete item
		case 'd':
			char in;
			std::cout << "How do you want to delete items? " << endl;
			std::cout << "i - by ID, t - type, s - status ";
			std::cin >> in;
			switch (in) {
			case 'i':
				std::cout << "Enter the ID: ";
				std::cin >> ID;
				arr[0].deleteItem(ID);
				break;
			case 's':
				std::cout << "Enter the status to delete: ";
				std::cin >> status;
				switch (status) {
				case 100:
					arr[0].deleteByStatus(DONE);
					break;
				case 50:
					arr[0].deleteByStatus(INCOMPLETE);
					break;
				case 10:
					arr[0].deleteByStatus(PLANNED);
					break;
				default:
					arr[0].deleteByStatus(UNKNOWN);
					break;
				}
				break;
			case 't':
				std::cout << "Enter the type to delete: ";
				std::cin >> type;
				switch (type) {
				case 1:
					arr[0].deleteByType(SHOPPING);
					break;
				case 2:
					arr[0].deleteByType(CHORES);
					break;
				case 3:
					arr[0].deleteByType(WORK);
					break;
				case 4:
					arr[0].deleteByType(SCHOOL);
					break;
				default:
					arr[0].deleteByType(UNASSIGNED);
					break;
				}

			}
			break;
			//sort
		case 's':
			int inp;
			std::cout << "How would you like to sort? 1 - priority, 2 - due, 3 - creation, 4 - type";
			std::cin >> inp;
			switch (inp) {
			case 1:
				arr[0].sortByPriority();
				break;
			case 2:
				arr[0].sortByDue();
				break;
			case 3:
				arr[0].sortByCreation();
				break;
			case 4:
				arr[0].sortByType();
				int choice;
				std::cout << "Would you like to inner sort? 1 - priority, 2 - due date, 3 - no inner sort: ";
				std::cin >> choice;
				switch (choice) {
				case 1:
					arr[0].sortByPriority();
					break;
				case 2:
					arr[0].sortByDue();
					break;
				case 3:
					break;
				}
				break;

			}
			break;
			//print
		case 'p':
			int choice;
			std::cout << "What would you like to print? 1 - all, 2 - print by type, 3 - print by priority, 4 - print by ID: ";
			std::cin >> choice;
			switch (choice) {
			case 1:
				for (int i = 0; i < ToDoList::numLists; i++) {
					arr[i].printAll();
				}
				break;
			case 2:
				std::cout << "Enter the type to print: ";
				std::cin >> type;
				switch (type) {
				case 1:
					arr[0].printByPriority(SHOPPING);
					break;
				case 2:
					arr[0].printByPriority(CHORES);
					break;
				case 3:
					arr[0].printByPriority(WORK);
					break;
				case 4:
					arr[0].printByPriority(SCHOOL);
					break;
				default:
					arr[0].printByPriority(UNASSIGNED);
					break;
				}
				break;
			case 3:
				int choice;
				std::cout << "Enter the priority you want to print, 1-5: ";
				std::cin >> choice;
				arr[0].printByPriority(choice);
				break;
			case 4:
				int num;
				std::cout << "Enter the ID of the item to print: ";
				std::cin >> num;
				arr[0].printByID(num);
				break;
			}
			break;



			//merge two exisitng lists
		case 'm':
			arr[0].mergeList(arr[1]);
			break;
			//new list created by another list
		case 'n':
			arr[2] = ToDoList(arr[1]);
			break;
		}
		printMenu();
	} while (input != 'z');
}
void printMenu() {
	
	std::cout << "Enter Your Action:" << endl;
	std::cout << "a - add an item to a list" << endl;
	std::cout << "e - edit existing todo items" << endl;
	std::cout << "n - create new list by another existing list" << endl;
	std::cout << "p - print items of a list" << endl;
	std::cout << "c - clone a list" << endl;
	std::cout << "d - delete a to do item " << endl;
	std::cout << "m - merge two existing lists" << endl;
	std::cout << "s - sort a list" << endl;
	std::cout << "o - output a list to a text file" << endl;
	std::cout << "r - read a text file with a list" << endl;
	std::cout << "z - to exit" << endl;

}
void copyTwoD(ToDo** arr, ToDoList items, int listSize) {
	for (int i = 0; i <= 5; i++) {//num Rows
		for (int j = 0; j < listSize; j++) {//num Columns is listSize
			if (items.list[j].getType() == i) {
				arr[j][i] = items.list[j];
			}
		}
	}
}
void copythreeD(ToDo*** arr, ToDoList items, int listSize) {
	for (int i = 0; i <= 5; i++) {//Type Rows
		for (int j = 0; j < listSize; j++) {//num Columns is listSize
			if (items.list[j].getType() == i) {
				for (int k = 0; k <= 4; k++) {
					if (items.list[j].getPriority() == (k + 1)) {
						arr[j][i][k] = items.list[j];
					}
				}
			}
		}
	}
}

