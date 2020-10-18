#pragma once
#pragma once
#include <string>
#include <iostream>
#include "Date.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;
#ifndef TODO_H
#define TODO_H
enum Type {UNASSIGNED = 0, SHOPPING = 1, CHORES, WORK, SCHOOL};
enum Status {UNKNOWN = 0, DONE = 100, INCOMPLETE = 50, PLANNED = 10};

class ToDo {
private:
	int ID{};
	std::string title{};
	int priority{};
	Type type{};
	string description{};
	Status status{};
	Date due{};
	Date creation{};
	Date lastMod{};
public:
	ToDo() {
		ID = 0;
	}; //default constructor
	~ToDo() { //reset
		ID = 0;
		setTitle(" ");
		setDescript(" ");
		setType(UNASSIGNED);
		setStatus(UNKNOWN);
		setDue(Date(0, 0, 0));
		setCreation(Date(0, 0, 0));
		setLastMod(Date(0, 0, 0));
		setPriority(0);
	};//when item is deleted, the ToDo item's ID defaults back to 0
	ToDo(string title, Type type, int priority, Date due) {
		setTitle(title);
		setType(type);
		setPriority(priority);
		setDue(due);
		setID();
	}
	ToDo(string title, Type type, int priority) {
		setTitle(title);
		setType(type);
		setPriority(priority);
		setID();
	}
	ToDo(string title, string descript, Type type) {
		setTitle(title);
		setDescript(descript);
		setType(type);
		setID();
	}
	int getID() { return ID; }
	void setID();
	void copyID(int num);
	string getTitle() { return title; }
	void setTitle(string title);
	string getDescript() { return description; }
	void setDescript(string d);
	Type getType() { return type; }
	void setType(Type cat);
	int getPriority() { return priority; }
	void setPriority(int p);
	Status getStatus() { return status; }
	void setStatus(Status s);
	Date getCreation() { return creation; }
	void setCreation(Date c);
	Date getDueDate() { return due; }
	void setDue(Date d);
	Date getLastMod() { return lastMod; }
	void setLastMod(Date l);
};

#endif



