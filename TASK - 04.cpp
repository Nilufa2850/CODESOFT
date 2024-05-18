/*                      TASK 4
                    TO-DO LIST
Build a simple console-based to-do list manager that allows users to add, view, and delete tasks

Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or
pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.*/

#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 10; 
string tasks[MAX_TASKS];   
bool completed[MAX_TASKS] = {false}; 
int taskCount = 0; 

void addTask() {
    if (taskCount < MAX_TASKS) {
        cout << "Enter task description: ";
        string description;
        getline(cin, description);
        tasks[taskCount] = description;
        taskCount++;
        cout << "Task added!" << endl;
    } else {
        cout << "Task list is full!" << endl;
    }
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks yet!" << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". [" << (completed[i] ? "X" : " ") << "] " << tasks[i] << endl;
        }
    }
}

void markTaskCompleted() {
    if (taskCount == 0) {
        cout << "No tasks to mark as completed!" << endl;
        return;
    }
    cout << "Enter the task number to mark as completed (1-" << taskCount << "): ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskCount) {
        completed[taskNumber - 1] = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask() {
    if (taskCount == 0) {
        cout << "No tasks to remove!" << endl;
        return;
    }
    cout << "Enter the task number to remove (1-" << taskCount << "): ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskCount) {
        for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
            completed[i] = completed[i + 1];
        }
        taskCount--;
        cout << "Task removed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void showMenu() {
    cout<<endl ;
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout<<endl ;
}

int main() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl ;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice :( Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
