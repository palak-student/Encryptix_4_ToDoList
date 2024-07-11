#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void displayTasks(string taskArray[], int totalTasks) {
    cout << "Current To-Do List:" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < totalTasks; i++) {
        cout << "Task " << (i + 1) << ": " << taskArray[i] << endl;
    }
    cout << "----------------------------------------------" << endl;
}

int main() {
    string taskArray[10] = {""};
    int totalTasks = 0;
    int choice = -1;

    while (choice != 0) {
        cout << "--- TO-DO LIST MENU ---\n"
             << "1 - Add a New Task\n"
             << "2 - View All Tasks\n"
             << "3 - Remove a Task\n"
             << "0 - Exit Program\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (totalTasks >= 10) {
                    cout << "The task list is full!" << endl;
                } else {
                    cout << "Enter the new task: ";
                    cin.ignore();  // clear the input buffer
                    getline(cin, taskArray[totalTasks]);
                    totalTasks++;
                    cout << "Task added successfully." << endl;
                }
                break;
            }
            case 2:
                displayTasks(taskArray, totalTasks);
                break;
            case 3: {
                int taskToDelete;
                cout << "Enter the task number to delete: ";
                cin >> taskToDelete;

                if (taskToDelete < 1 || taskToDelete > totalTasks) {
                    cout << "Invalid task number entered." << endl;
                } else {
                    for (int i = taskToDelete - 1; i < totalTasks - 1; i++) {
                        taskArray[i] = taskArray[i + 1];
                    }
                    totalTasks--;
                    cout << "Task " << taskToDelete << " has been removed." << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }

    return 0;
}
