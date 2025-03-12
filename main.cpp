#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;


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

int main(int argc, char* argv[]) {

	vector<string> taskList;

	// Add Task
	if (argc > 1 && strcmp(argv[1], "add") == 0) {
		addTask(argc, argv, &taskList);
	}

	if (argc > 1 && strcmp(argv[1], "delete") == 0) {
		deleteTask(atoi(argv[2]), &taskList);
	}

	for (string task: taskList) {
		cout << task;
	}

	deleteTask(0, &taskList);

	return 0;
}
