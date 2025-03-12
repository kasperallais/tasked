#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class Task {
public:
    	string description;
    	int id;
    
	// Static variable for unique IDs
    	static int current_id; 

    	// Constructor to initialize task with a description
    	Task(string desc) : description(desc), id(current_id++) {}
};

// Initialize static variable
int Task::current_id = 0;

// Store tasks in memory
vector<Task> taskList;

void loadTasksFromFile(const string& fileName) {
    	ifstream inputFile(fileName);
    	string line;
    	int id;
    
	// Clear task list before loading
    	taskList.clear();
	// Reset ID counter
    	Task::current_id = 0;

    	while (inputFile >> id) {
		// Ignore the space after ID
        	inputFile.ignore();
		// Read task description
        	getline(inputFile, line);
        	taskList.emplace_back(line);
		// Set correct ID
        	taskList.back().id = id;
		// Increment ID
        	Task::current_id = id + 1;
    }
    inputFile.close();
}

void saveTasksToFile(const string& fileName) {
	// Overwrite File
    	ofstream outputFile(fileName, ios::trunc);
	
	// Cycle through tasks in list and add them to the file
	for (const Task& task : taskList) {
        	outputFile << task.id << " " << task.description << endl;
    	}
}


void listTasks() {
    	for (const Task& task : taskList) {
        	cout << task.id << ": " << task.description << endl;
    	}
}

void addTask(int argc, char* argv[]) {
	// Go through argv to get description
    	string taskDescription;
    	for (int i = 2; i < argc; i++) {
		taskDescription += argv[i];
		if (i < argc - 1) {
	    	taskDescription += " ";
		}
    	}

    	taskList.emplace_back(taskDescription);

	saveTasksToFile("list.txt");
}

void editTask(int argc, char* argv[]) {
	int id = atoi(argv[2]);

	// Go through argv to get description
    	string taskDescription;
    	for (int i = 2; i < argc; i++) {
		taskDescription += argv[i];
		if (i < argc - 1) {
	    	taskDescription += " ";
		}
    	}

}

void deleteTask(int argc, char* argv[]) {
	int id = atoi(argv[2]);

	taskList.erase(taskList.begin() + id);

	saveTasksToFile("list.txt");
}

int main(int argc, char* argv[]) {
	string fileName = "list.txt";

	// Load existing tasks
	loadTasksFromFile(fileName);

	// Grab command from argv
	if (argc > 1) {
		string command = argv[1];

		if (command == "add") {
			addTask(argc, argv);
		}
		else if (command == "delete") {
			deleteTask(argc, argv);
		}
		else if (command == "list") {
			listTasks();
		}
	} 
	else {
		cout << "Usage: ./task [add|list]\n";
	}

	return 0;
}

