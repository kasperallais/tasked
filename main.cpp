#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;


void readTaskList(string fileName) {
	ofstream file(fileName);


}

void writeToTaskList(string fileName) {
	ofstream file(fileName);

	file << "Hello World";

	file.close();
}

void addTask(int argc, char* argv[], vector<string>* taskList) {
	string task;
	for (int i = 2; i < argc; i++) {
		task += argv[i];
		task += " ";
	}

	taskList->push_back(task);
}

void deleteTask(int element, vector<string>* taskList) {
	taskList->erase(taskList->begin() + element);
}

void printTaskList(vector<string> taskList) {
	for (string task : taskList) {
		cout << task << endl;
	}
}

int main(int argc, char* argv[]) {

	writeToTaskList("test.txt");

	vector<string> taskList;

	// Add a Task
	if (argc > 1 && strcmp(argv[1], "add") == 0) {
		addTask(argc, argv, &taskList);
	}

	// Delete a Task
	if (argc > 1 && strcmp(argv[1], "delete") == 0) {
		deleteTask(atoi(argv[2]), &taskList);
	}

	// Print Task List
	if (argc > 1 && strcmp(argv[1], "list") == 0) {
		printTaskList(taskList);
	} 

	return 0;
}
