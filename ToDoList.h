#pragma once
#ifndef TODOLIST_H
#define TODOLIST_H
#include "ToDo.h"
#include <fstream>
#include <iostream>
#define MAX_SIZE 100
class ToDoList
{public:
	ToDoList() { 
		listID = numLists; 
		numLists++;
	}//default constructor
	ToDoList(const ToDoList& existing){//copies all items into new to do list 
		for (int i = 0; i < MAX_SIZE; i++) {
			list[i] = existing.list[i]; //copy list items to both 
		}
	}
	ToDo list[MAX_SIZE];
	static int numLists; 
	int listID;
	int addItem(ToDo add);
	void editType(int ID, Type t);
	void editTitle(int ID, string t);
	void editDescript(int ID, string d);
	void editPriority(int ID, int p);
	void editStatus(int ID, Status s);
	void editDue(int ID, Date d);
	void deleteItem(int ID);
	void deleteByType(Type type);
	void deleteByStatus(Status s);
	void reSort();
	void outputToFile(string fileName);
	void readInFile(string fileName);
	void sortByPriority();
	void sortByDue();
	void sortByCreation();
	void sortByType();
	void printAll();
	void printByType(Type type);
	void printByPriority(int priority);
	void printByID(int ID);
	void mergeList(ToDoList addItems);
	void cloneList(ToDoList clone);


	








};
#endif

