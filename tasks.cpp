#include <iostream>
#include <queue>
#include <thread>


using namespace std;

void addTask(queue<string>& tasks) {
    string newTask;
    cout << "Enter the desired task: ";
    cin >> newTask;
    cin.ignore();
    tasks.push(newTask);
}

void displayTasks(queue<string> tasks) {
    if (tasks.empty()) {
        cout << "There is no task in the list!\n";
    }
    while (!tasks.empty()) {
        cout << tasks.front() << endl;
        tasks.pop();
    }
}

void endTask(queue<string>& tasks) {
    if (!tasks.empty()) {
        tasks.pop();
    } else {
        cout << "There is no task!\n\n";
    }
}

void mainScreen(queue<string>& tasks) {
    int option;
    cout << "===================" << endl;
    cout << "  Task list v1.0   " << endl;
    cout << "===================" << "\n\n\n";
    cout << "Options:" << endl;
    cout << "[1] Add a task\n" << "[2] Finnish a task\n" << "[3] Show tasks\n" << "[4] Exit\n\n";
    cout << "What would you like to do? ";
    cin >> option;
    cin.ignore();
    cout << endl;
    cout << "\x1B[2J\x1B[H";
    switch (option)
    {
    case 1:
        addTask(tasks);
        cout << "\x1B[2J\x1B[H";
        break;
    case 2:
        endTask(tasks);
        cout << "\x1B[2J\x1B[H";
        break;
    case 3:
        displayTasks(tasks);
        this_thread::sleep_for(chrono::seconds(2));
        cout << "\x1B[2J\x1B[H";
        break;
    case 4:
        exit(1);
        break;
    default:
        "Please enter a valid option!\n";
        break;
    }
}

int main() {
    
    queue<string> tasks;
    while (true) {
        mainScreen(tasks);
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;

}