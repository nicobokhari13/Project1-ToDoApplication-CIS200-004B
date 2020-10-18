#include "ToDoList.h"
int ToDoList::numLists = 0; 
int ToDoList::addItem(ToDo added) {
	reSort();
	int pos;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == 0) {
			list[i] = added; 
			pos = i;
			break;
		}
	}
	return pos; 
}
void ToDoList::editType(int ID, Type t) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == ID) {
			list[i].setType(t);
			break;
		}
	}
}
void ToDoList::editTitle(int ID, string t) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == ID) {
			list[i].setTitle(t);
			break;
		}
	}
}
void ToDoList::editDescript(int ID, string d) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == ID) {
			list[i].setDescript(d);
			break;
		}
	}
	
}
void ToDoList::editPriority(int ID, int p) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == ID) {
			list[i].setPriority(p);
			break;
		}
	}
	
}
void ToDoList::editStatus(int ID, Status s) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == ID) {
			list[i].setStatus(s);
			break;
		}
	}
	
}
void ToDoList::editDue(int ID, Date d) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == ID) {
			list[i].setDue(d);
			break;
		}
	}
	
}
void ToDoList::deleteItem(int ID) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == ID) {
			list[i].~ToDo();
		}
	}
	reSort();
}
void ToDoList::deleteByType(Type type) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getType() == type) {
			list[i].~ToDo();
		}
	}
	reSort();
}
void ToDoList::deleteByStatus(Status s) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getStatus() == s) {
			list[i].~ToDo();
		}
	}
	reSort();
}
void ToDoList::reSort() {
	int numItems = 0; 
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() != 0) {
			numItems++;
		}
	}
	ToDo* temp = new ToDo[numItems];
	int tempCount = 0;//only increments in if statement
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() != 0) {
			temp[tempCount] = list[i];
			tempCount++;
		}
	}
	for (int i = 0; i < numItems; i++) {
		list[i] = temp[i];//put list back to order
	}
}
void ToDoList::printAll() {
	cout << "ID, " << "Title, " << "Priority, " << "Type, " << "Description, " << "Status, " << "Due Date, " << "Creation, " << "Last Mod" << endl;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == 0) {
			continue;
		}
		cout << list[i].getID();
		cout << " , " << list[i].getTitle();
		cout << " , " << list[i].getPriority();
		cout << " , " << list[i].getType();
		cout << " , " << list[i].getDescript();
		cout << " , " << list[i].getStatus();
		cout << " , " << list[i].getDueDate().getMonth() << " " << list[i].getDueDate().getDay() << " " << list[i].getDueDate().getYear();
		cout << " , " << list[i].getCreation().getMonth() << " " << list[i].getCreation().getDay() << " " << list[i].getCreation().getYear();
		cout << " , " << list[i].getLastMod().getMonth() << " " << list[i].getLastMod().getDay() << " " << list[i].getLastMod().getYear();
		cout << endl;
	}
}
void ToDoList::sortByType() {
	ToDo* shop = new ToDo[MAX_SIZE];
	ToDo* chore = new ToDo[MAX_SIZE];
	ToDo* work = new ToDo[MAX_SIZE];
	ToDo* school = new ToDo[MAX_SIZE];
	ToDo* unA = new ToDo[MAX_SIZE];
	int sCount = 0;
	int cCount = 0;
	int wCount = 0;
	int scCount = 0;
	int unC = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getType() == 1) {
			shop[sCount] = list[i];
			sCount++;
		}
		else if (list[i].getType() == 2) {
			chore[cCount] = list[i];
			cCount++;
		}
		else if (list[i].getType() == 3) {
			work[wCount] = list[i];
			wCount++;
		}
		else if (list[i].getType() == 4) {
			school[scCount] = list[i];
			scCount++;
		}
		else {
			unA[unC] = list[i];
		}
	}
	for (int i = 0; i < sCount; i++) {
		list[i] = shop[i];
	}
	for (int i = 0; i < cCount; i++) {
		list[sCount + i] = chore[i];
	}
	for (int i = 0; i < wCount; i++) {
		list[sCount + cCount + wCount + i] = work[i];
	}
	for (int i = 0; i < scCount; i++) {
		list[sCount + cCount + wCount + i] = school[i];
	}
	for (int i = 0; i < unC; i++) {
		list[sCount + cCount + wCount + scCount + i] = unA[i];
	}
}
void ToDoList::sortByPriority() {
	ToDo* temp = new ToDo;
	for (int i = 1; i < MAX_SIZE; i++) {
		if (list[i].getPriority() > list[i - 1].getPriority()) {
			*temp = list[i - 1];
			list[i - 1] = list[i];
			list[i] = *temp;
		}
	}
}
void ToDoList::sortByDue() {
	ToDo* place = new ToDo();
	for (int i = 1; i < MAX_SIZE; i++) {
		if (list[i].getDueDate().getYear() < list[i - 1].getDueDate().getYear()) {
			*place = list[i - 1];
			list[i - 1] = list[i];
			list[i] = *place; 
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getDueDate().getMonth() < list[i - 1].getDueDate().getMonth()) {
			*place = list[i - 1];
			list[i - 1] = list[i];
			list[i] = *place;
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getDueDate().getDay() < list[i - 1].getDueDate().getDay()) {
			*place = list[i - 1];
			list[i - 1] = list[i];
			list[i] = *place;
		}
	}
}
void ToDoList::sortByCreation() {
	ToDo* temp = new ToDo();
	for (int i = 1; i < MAX_SIZE; i++) {
		if (list[i].getCreation().getYear() < list[i - 1].getCreation().getYear()) {
			*temp = list[i - 1];
			list[i - 1] = list[i];
			list[i] = *temp;
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getCreation().getMonth() < list[i - 1].getCreation().getMonth()) {
			*temp = list[i - 1];
			list[i - 1] = list[i];
			list[i] = *temp;
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getCreation().getDay() < list[i - 1].getCreation().getDay()) {
			*temp = list[i - 1];
			list[i - 1] = list[i];
			list[i] = *temp;
		}
	}
}

void ToDoList::outputToFile(string fileName) {
	ofstream fileOut;
	fileOut.open(fileName);
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == 0) {
			continue;
		}
		fileOut << list[i].getID();
		fileOut << "," << list[i].getTitle();
		fileOut << ", " << list[i].getPriority();
		fileOut << "," << list[i].getType();
		fileOut << "," << list[i].getDescript();
		fileOut << "," << list[i].getStatus();
		fileOut << "," << list[i].getDueDate().getMonth() << " " << list[i].getDueDate().getDay() << " " << list[i].getDueDate().getYear();
		fileOut << "," << list[i].getCreation().getMonth() << " " << list[i].getCreation().getDay() << " " << list[i].getCreation().getYear();
		fileOut << "," << list[i].getLastMod().getMonth() << " " << list[i].getLastMod().getDay() << " " << list[i].getLastMod().getYear();
		fileOut << endl;
	}
	fileOut.close();
}
void ToDoList::readInFile(string fileName) {
	ifstream file_obj;
	file_obj.open(fileName);
	string read;
	cout << "Contents of file: " << fileName << endl;
	while (getline(file_obj, read)) {
		cout << read << endl;
	}
}
void ToDoList::printByType(Type type) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == 0) {
			continue;
		}
		if (list[i].getType() == type) {
			cout << list[i].getID();
			cout << " , " << list[i].getTitle();
			cout << " , " << list[i].getPriority();
			cout << " , " << list[i].getType();
			cout << " , " << list[i].getDescript();
			cout << " , " << list[i].getStatus();
			cout << " , " << list[i].getDueDate().getMonth() << " " << list[i].getDueDate().getDay() << " " << list[i].getDueDate().getYear();
			cout << " , " << list[i].getCreation().getMonth() << " " << list[i].getCreation().getDay() << " " << list[i].getCreation().getYear();
			cout << " , " << list[i].getLastMod().getMonth() << " " << list[i].getLastMod().getDay() << " " << list[i].getLastMod().getYear();
			cout << endl;

		}



	}
}

void ToDoList::printByPriority(int p) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == 0) {
			continue;
		}
		if (list[i].getPriority() == p) {
			cout << list[i].getID();
			cout << " , " << list[i].getTitle();
			cout << " , " << list[i].getPriority();
			cout << " , " << list[i].getType();
			cout << " , " << list[i].getDescript();
			cout << " , " << list[i].getStatus();
			cout << " , " << list[i].getDueDate().getMonth() << " " << list[i].getDueDate().getDay() << " " << list[i].getDueDate().getYear();
			cout << " , " << list[i].getCreation().getMonth() << " " << list[i].getCreation().getDay() << " " << list[i].getCreation().getYear();
			cout << " , " << list[i].getLastMod().getMonth() << " " << list[i].getLastMod().getDay() << " " << list[i].getLastMod().getYear();
			cout << endl;

		}
	}
}
void ToDoList::printByID(int ID) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == ID) {
			cout << list[i].getID();
			cout << " , " << list[i].getTitle();
			cout << " , " << list[i].getPriority();
			cout << " , " << list[i].getType();
			cout << " , " << list[i].getDescript();
			cout << " , " << list[i].getStatus();
			cout << " , " << list[i].getDueDate().getMonth() << " " << list[i].getDueDate().getDay() << " " << list[i].getDueDate().getYear();
			cout << " , " << list[i].getCreation().getMonth() << " " << list[i].getCreation().getDay() << " " << list[i].getCreation().getYear();
			cout << " , " << list[i].getLastMod().getMonth() << " " << list[i].getLastMod().getDay() << " " << list[i].getLastMod().getYear();
			cout << endl;
			break;
		}
	}
}
void ToDoList::mergeList(ToDoList addItems) {
	reSort();
	int otherListCounter = 0; 
	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i].getID() == 0) {
			list[i] = addItems.list[otherListCounter];
			otherListCounter++;
		}
	}
}
void ToDoList::cloneList(ToDoList clone) { 
	for (int i = 0; i < MAX_SIZE; i++) {
		clone.list[i].~ToDo();
		clone.list[i].copyID(list[i].getID());
		clone.list[i].setCreation(list[i].getCreation());
		clone.list[i].setDescript(list[i].getDescript());
		clone.list[i].setDue(list[i].getDueDate());
		clone.list[i].setLastMod(list[i].getLastMod());
		clone.list[i].setPriority(list[i].getPriority());
		clone.list[i].setStatus(list[i].getStatus());
		clone.list[i].setTitle(list[i].getTitle());
		clone.list[i].setType(list[i].getType());
	} 
}
//void ToDoList::