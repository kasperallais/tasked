#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

class Task {
	public:
		string description;
		int id;
};

void listTaskList(ifstream* inputFile) {
	string task;

	while (getline (*inputFile, task)) {
		cout << task << endl;
	}
}

void writeTaskToFile(ofstream* file, string task) {
	*file << task << endl;
}

Task createTask(int argc, char* argv[]) {
	Task task; 

	// Create task description
	string taskDescription;

	for (int i = 2; i < argc; i++) {
		taskDescription += argv[i];
		if (i < argc - 1) {
			taskDescription += " ";
		}
	}

	task.description = taskDescription;

	return task;
}

void deleteTask(int element, vector<string>* taskList) {
	taskList->erase(taskList->begin() + element);
}

int main(int argc, char* argv[]) {

	string fileName = "list.txt";
	vector<string> taskList;

	// Create ofstream and ifstream instances
	ofstream outputFile(fileName, ios::app);
	ifstream inputFile(fileName);

	// Add a Task
	if (argc > 1 && strcmp(argv[1], "add") == 0) {
		Task task = createTask(argc, argv);
		writeTaskToFile(&outputFile, task.description);
	}

	// Delete a Task
	if (argc > 1 && strcmp(argv[1], "delete") == 0) {
		deleteTask(atoi(argv[2]), &taskList);
	}

	// Print Task List
	if (argc > 1 && strcmp(argv[1], "list") == 0) {
		listTaskList(&inputFile);
	} 

	return 0;
}
