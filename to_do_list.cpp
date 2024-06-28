#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Task {
private:
    string name;      
    string description; 
        bool completed;     

public:
   
    Task(const string& name, const string& description)
        : name(name), description(description), completed(false) {}

   
    string getName() const { return name; }


    string getDescription() const { return description; }

  
    bool isCompleted() const { return completed; }

   
    void markCompleted() { completed = true; }

  
    void displayTask() const {
        cout << name << " (" << (completed ? "Completed" : "Pending") << ")\n";
        cout << "Description: " << description << "\n\n";
    }
};

int main() {
    vector<Task> tasks; 

    while (true) {
        cout << "To-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting the program. Have a great day!\n";
            break;
        }

        switch (choice) {
            case 1: {
                // Add Task
                string name, description;
                cout << "Enter task name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter task description: ";
                getline(cin, description);
                tasks.push_back(Task(name, description));
                cout << "Task added successfully!\n";
                break;
            }
            case 2: {
                // View Tasks
                if (tasks.empty()) {
                    cout << "No tasks found.\n";
                } else {
                    cout << "Tasks:\n";
                    for (const auto& task : tasks) {
                        task.displayTask();
                    }
                }
                break;
            }
            case 3: {
                // Mark Task as Completed
                if (tasks.empty()) {
                    cout << "No tasks found.\n";
                } else {
                    cout << "Enter the index of the task to mark as completed: ";
                    int index;
                    cin >> index;
                    if (index >= 0 && index < tasks.size()) {
                        tasks[index].markCompleted();
                        cout << "Task marked as completed!\n";
                    } else {
                        cout << "Invalid index. Please try again.\n";
                    }
                }
                break;
            }
            case 4: {
                // Remove Task
                if (tasks.empty()) {
                    cout << "No tasks found.\n";
                } else {
                    cout << "Enter the index of the task to remove: ";
                    int index;
                    cin >> index;
                    if (index >= 0 && index < tasks.size()) {
                        tasks.erase(tasks.begin() + index);
                        cout << "Task removed successfully!\n";
                    } else {
                        cout << "Invalid index. Please try again.\n";
                    }
                }
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
