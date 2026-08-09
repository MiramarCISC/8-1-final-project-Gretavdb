#include "project.hpp"
#include <fstream>
#include <iostream>

using namespace std;

// Returns true when days are 0 or greater.
bool isValidDays(int days) {
    return days >= 0;
}

// Returns true when the watering frequency is greater than 0
bool isValidFrequency(int frequency) {
    return frequency > 0;
}

// Creates and returns a Plant structure.
Plant createPlant(string name, 
                  string species, 
                  int days, 
                  int frequency) {
    Plant plant;

    plant.name = name;
    plant.species = species;

    // Validate number of days.
    if (isValidDays(days)) { 
       plant.daysSinceWatered = days;
    }

    else {
      plant.daysSinceWatered = DEFAULT_DAYS;
    }

    // Validate watering frequency. 
    if (isValidFrequency(frequency)) {
      plant.wateringFrequency = frequency;
    }

    else {
      plant.wateringFrequency = WATER_THRESHOLD;
    }

    // Determine whether the plant needs water.
    plant.needsWater = plantNeedsWater(plant);

    return plant;
}

// Prints information about one plant.
void printPlant(const Plant& plant) {
    cout << "Name: " << plant.name << endl;
    cout << "Species: " << plant.species << endl;
    cout << "Days Since Watered: "
         << plant.daysSinceWatered << endl;
    cout << "Watering Frequency: "
         << plant.wateringFrequency << " days" << endl;

    if (plant.needsWater) {
       cout << "Status: Needs Water" << endl;
    }
    else {
       cout << "Status: Does Not Need Water" << endl;
    }
}

// Returns true if the plant needs to be watered.
bool plantNeedsWater(const Plant& plant) {
    return plant.daysSinceWatered >= plant.wateringFrequency;
}

// Inserts a new plant at the beginning of the linked list.
void insertPlant(PlantNode*& head, Plant plant) {
    PlantNode* newNode = new PlantNode;

    newNode->data = plant;
    newNode->next = head;

    head = newNode;
}

// Searches the linked list for a plant by name.
PlantNode* findPlant(PlantNode* head, string name) {
    PlantNode* current = head;

    while (current != nullptr) {
        if (current->data.name == name) {
            return current;
        }
        
        current = current->next;
    }

    return nullptr;
}

// Waters a plant and reste its watering information.
void waterPlant(PlantNode* plant) {
    if (plant == nullptr) {
        return;
    }

        plant->data.daysSinceWatered = 0;
        plant->data.needsWater = false;
}

// Removes a plant from the linked list.
void removePlant(PlantNode*& head, string name) {
    if (head == nullptr) {
        return;
    }

    if (head->data.name == name) {
        PlantNode* oldNode = head;
        head = head->next;

        delete oldNode;
        return;
    }

    PlantNode* current = head;

    while (current->next != nullptr) {

        if (current->next->data.name == name) {

            PlantNode* oldNode = current->next;

            current->next = oldNode->next;

            delete oldNode;
            return;
        }

        current = current->next;
    }
}

// Counts the number of plants in the linked list.
int countPlants(PlantNode* head) {
    int count = 0;

    PlantNode* current = head;

    while (current != nullptr) {
        count ++;
        current = current->next;
    }

    return count;
}

// Counts plants that currently need water.
int countPlantsNeedingWater(PlantNode* head) {
    int count = 0;

    PlantNode* current = head;

    while (current != nullptr) {
        if (plantNeedsWater(current->data)) {
            count++;
        }

            current = current->next;
    }

    return count;
}

// Finds the plant that has gone the longest without being watered.
PlantNode* findMostOverduePlant(PlantNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    PlantNode* mostOverdue = head;
    PlantNode* current = head->next;

    while (current != nullptr) {
        if (current->data.daysSinceWatered > mostOverdue->data.daysSinceWatered) {
                mostOverdue = current;
            }

        current = current->next;
    }

    return mostOverdue;
}

// Prints every plant in the linked list
void printPlants(PlantNode* head) {
    if (head == nullptr) {
        cout << "No plants in the log." << endl;
        return;
    }
    
    PlantNode* current = head;

    while (current != nullptr) {
        printPlant(current->data);
        cout << " " << endl;

        current = current->next;
    }
}

// Deletes every node and resets the head pointer.
void clearPlants(PlantNode*& head) {
    PlantNode* current = head;

    while (current != nullptr) {
        PlantNode* nextNode = current->next;

        delete current;
        current = nextNode;
    }

    head = nullptr;
}

// Loads plants from a file into the linked list.
bool loadPlants(string filename, PlantNode*& head) {
    ifstream input(filename);

    if (!input.is_open()) {
        return false;
    }

    clearPlants(head);

    string name;
    string species;
    int days;
    int frequency;

    while (input >> name
                 >> species
                 >> days
                 >> frequency) {

        Plant plant = createPlant(name, species, days, frequency);

        insertPlant(head, plant);
    }

    input.close();

    return true; 
}

// Saves the linked list to a file.
bool savePlants(string filename, PlantNode* head) {
    ofstream output(filename);

    if (!output.is_open()) {
        return false;
    }

    PlantNode* current = head;

    while (current != nullptr) {

        output << current->data.name << " "
               << current->data.species << " "
               << current->data.daysSinceWatered << " "
               << current->data.wateringFrequency
               << endl;
        
        current = current->next;
    }

    output.close();

    return true;
}