#ifndef PLANT_LOG_HPP
#define PLANT_LOG_HPP

#include <string>

using namespace std;

// Constants
const int WATER_THRESHOLD = 7;
const int DEFAULT_DAYS = 0;

// Structures

struct Plant {
    string name;
    string species; 
    int daysSinceWatered;
    int wateringFrequency;
    bool needsWater;
};

 struct PlantNode {
    Plant data;
    PlantNode* next;
 };

 bool isValidDays(int days);
 bool isValidFrequency(int frequency);
 
 // Plant Functions
 Plant createPlant(string name,
                   string species,
                   int days,
                   int frequency);

void printPlant(const Plant& plant);

bool plantNeedsWater(const Plant& plant);

// Linked List Functions
void insertPlant(PlantNode*& head, Plant plant);
PlantNode* findPlant(PlantNode* head, string name);
void waterPlant(PlantNode* plant);
void removePlant(PlantNode*& head, string name);
int countPlants(PlantNode* head);
int countPlantsNeedingWater(PlantNode* head);
PlantNode* findMostOverduePlant(PlantNode* head);
void printPlants(PlantNode* head);
void clearPlants(PlantNode*& head);

// File Functions
bool loadPlants(string filename, PlantNode*& head);
bool savePlants(string filename, PlantNode* head);

#endif