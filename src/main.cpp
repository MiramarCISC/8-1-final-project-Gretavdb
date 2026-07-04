#include "project.hpp"
#include <iostream>

using namespace std;

int main() {
    int choice = -1;

    cout << "CISC 192 Final Project Sample" << endl;
    cout << "Sample code is provided only as an example." << endl;
    cout << "Delete or replace the sample code before final submission." << endl;

    do {
        printMenu();
        cin >> choice;

        while (!isValidMenuChoice(choice)) {
            cout << "Invalid choice. Enter 0-4: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                Student student("A123", "Alex");
                student.getScoreList().addScore(90.0);
                student.getScoreList().addScore(80.0);
                student.getScoreList().addScore(100.0);
                student.getScoreList().sortAscending();

                printStudent(student);
                cout << "Score 100 found at index "
                     << student.getScoreList().findScore(100.0)
                     << endl;

                break;
            }

            case 2: {
                TaskList tasks;
                tasks.insertFront(Task("study", 5));
                tasks.insertFront(Task("project", 4));
                tasks.markTaskComplete("study");

                cout << "Task count: " << tasks.countTasks() << endl;
                cout << "Removed completed tasks: "
                     << tasks.removeCompletedTasks()
                     << endl;
                cout << "Remaining task count: " << tasks.countTasks() << endl;

                break;
            }

            case 3: {
                InventoryItem items[MAX_INVENTORY_ITEMS];
                int count = InventoryReport::readInventoryFile(
                    "data/inventory.txt",
                    items,
                    MAX_INVENTORY_ITEMS
                );

                cout << "Read " << count << " inventory item(s)." << endl;
                cout << "Total inventory value: "
                     << InventoryReport::calculateTotalInventoryValue(items, count)
                     << endl;

                if (InventoryReport::writeInventoryReport(
                        "inventory_report.txt",
                        items,
                        count
                    )) {
                    cout << "Report written to inventory_report.txt" << endl;
                }

                break;
            }

            case 4:
                cout << "Use this sample only as an example. "
                     << "Delete or replace sample code before submission."
                     << endl;
                break;

            case 0:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Unexpected choice." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
