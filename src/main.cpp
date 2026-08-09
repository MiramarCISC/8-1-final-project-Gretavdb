#include "project.hpp"
#include <iostream>

using namespace std;

int main() {
    
    PlantNode* head = nullptr;
    int choice;

    loadPlants("data/plants.txt", head);

    do {

        cout << "PLANT WATERING LOG" << endl;
        cout << "1. View All Plants" << endl;
        cout << "2. Add Plant" << endl;
        cout << "3. Search for Plant" << endl;
        cout << "4. Water Plant" << endl;
        cout << "5. Remove Plants" << endl;
        cout << "6. Count Plants" << endl;
        cout << "7. Show Plants Needing Water" << endl;
        cout << "8. Show Most Overdue Plant" << endl;
        cout << "9. Save Plant Log" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {

            // View All Plants
            case 1:
                printPlants(head);
                break;

            case 2: {
                string name;
                string species;
                int days;
                int frequency;

                cout << "Plant name: ";
                cin >> name;

                cout << "Species: ";
                cin >> species;

                cout << "Days since watered: ";
                cin >> days;

                cout << "Watering frequency: ";
                cin >> frequency;

                if (isValidDays(days) && isValidFrequency(frequency)) {
                    Plant plant = createPlant(name, species, days, frequency);

                    insertPlant(head, plant);

                    cout << "Plant added!" << endl;
                }
                
                else {
                    cout << "Invalid plant information." << endl;
                }

                break;
            }

            case 3: {
                string name;

                cout << "Plant name: ";
                cin >> name;

                PlantNode* plant = findPlant(head, name);

                if (plant != nullptr)
                    printPlant(plant->data);
                else 
                    cout << "Plant not found." << endl;

                break;
            }

            case 4: {
                string name;

                cout << "Plant name: ";
                cin >> name;

                PlantNode* plant = findPlant(head, name);

                if (plant != nullptr) {
                    waterPlant(plant);
                    cout << "Plant watered!" << endl;
                }
                else {
                    cout << "Plant not found." << endl;
                }

                break;
            }

            case 5: {
                string name;

                cout << "Plant name: ";
                cin>> name;

                if (findPlant(head, name) != nullptr) {
                    removePlant(head, name);
                    cout << "Plant removed!" << endl;
                }
                else {
                    cout << "Plant not found." << endl;
                }

                break;
            }

            case 6: 
                cout << "Total plants: "
                     << countPlants(head) << endl;
                break;

            case 7: {
                PlantNode* current = head;
                bool found = false;

                while (current != nullptr) {
                    if (plantNeedsWater(current->data)) {
                        printPlant(current->data);
                        cout << endl;
                        found = true;
                        }
                        
                    current = current->next;
                }

                if (!found) {
                    cout << "No plants need water." << endl;
                }

                break;
            }

            case 8: {

                PlantNode* plant = findMostOverduePlant(head);

                if (plant != nullptr) {
                    printPlant(plant->data);
                }
                else {
                    cout << "No plants in the log." << endl;
                }

                break;
            }

            case 9:
                if (savePlants("data/plants.txt", head)) {
                    cout << "Plant log saved!" << endl;
                }
                else {
                    cout << "Could not save file." << endl;
                }

                break;

            case 0:
                cout << "Saving and exiting..." << endl;
                savePlants("data/plants.txt", head);
                break;
            
            default:
                cout << "Invalid choice." << endl;
        }
    }
    while (choice != 0);
    
    clearPlants(head);

    return 0;
}