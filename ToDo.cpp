#include "ToDo.h"
#include "ToDoList.h"

void ToDo::setID() {
	ToDo::ID = rand() + 1; //can never be 0
}
void ToDo::copyID(int num) {
	ToDo::ID = num;
}
void ToDo::setDue(Date d) {
	ToDo::due.copyDate(d); //Todo member due accesses method copyDate with parameter Date d
}
void ToDo::setCreation(Date c) {
	ToDo::creation.copyDate(c);
}
void ToDo::setLastMod(Date l) {
	ToDo::lastMod.copyDate(l);
}
void ToDo::setTitle(string title) {
	ToDo::title = title;
}
void ToDo::setDescript(string d) {
	ToDo::description = d;
}
void ToDo::setType(Type cat) {
	ToDo::type = cat; 
}
void ToDo::setPriority(int p) {
	ToDo::priority = p;
}
void ToDo::setStatus(Status s) {
	ToDo::status = s;
}
