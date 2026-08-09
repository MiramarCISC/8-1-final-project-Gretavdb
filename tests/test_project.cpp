#include "project.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

// Week 1: Program Basics  
void testWeek1ProgramBasics() { 
    Plant plant = createPlant("Rose", "Flower", 3, 7); 

    assert(plant.name == "Rose"); 
    assert(plant.species == "Flower"); 
    assert(plant.daysSinceWatered == 3); 
    assert(plant.wateringFrequency == 7); 
} 

// Week 2: Decisions and Loops 
void testWeek2DecisionsAndLoops() { 
    assert(isValidDays(0)); 
    assert(isValidDays(5)); 
    assert(!isValidDays(-1)); 

    assert(isValidFrequency(1)); 
    assert(isValidFrequency(7)); 
    assert(!isValidFrequency(0)); 

    Plant plant = createPlant("Cactus", "Succulent", 10, 7); 
    
    assert(plant.needsWater); 
}
// Week 3: Functions 
void testWeek3Functions() { 
    Plant plant = createPlant("Fern", "Indoor", 2, 5); 
    
    assert(plant.name == "Fern"); 
    assert(plant.species == "Indoor"); 
    
    assert(plantNeedsWater(plant) == false); 
    
    plant.daysSinceWatered = 5; 
    
    assert(plantNeedsWater(plant) == true); 
} 

// Week 4: Searching 
void testWeek4Searching() { 
    PlantNode* head = nullptr; 
    
    insertPlant( 
        head, 
        createPlant("Rose", "Flower", 2, 7) 
    ); 

    insertPlant( 
        head, 
        createPlant("Cactus", "Succulent", 10, 14) 
    ); 
    
    PlantNode* found = findPlant(head, "Rose"); assert(found != nullptr); 
    
    assert(found->data.name == "Rose"); 
    assert(findPlant(head, "Sunflower") == nullptr); 
    
    clearPlants(head); 
} 

// Week 5: Strings and Structures 
void testWeek5StringsAndStructures() { 
    Plant plant = createPlant("Aloe", "Succulent", 4, 10); 
    
    assert(plant.name == "Aloe"); 
    assert(plant.species == "Succulent"); 
    assert(plant.daysSinceWatered == 4); 
    assert(plant.wateringFrequency == 10); 
} 

// Week 6: Pointers and Linked Lists 
void testWeek6LinkedList() { 
    PlantNode* head = nullptr; 
    
    Plant rose = createPlant("Rose", "Flower", 3, 7); 
    
    Plant cactus = createPlant("Cactus", "Succulent", 10, 14); 
    
    insertPlant(head, rose); 
    insertPlant(head, cactus); 
    
    assert(head != nullptr); 
    assert(countPlants(head) == 2); 
    
    PlantNode* found = findPlant(head, "Rose"); 
    
    assert(found != nullptr); 
    
    waterPlant(found); 
    
    assert(found->data.daysSinceWatered == 0); 
    assert(found->data.needsWater == false); 
    
    removePlant(head, "Rose"); 
    assert(countPlants(head) == 1); 
    assert(findPlant(head, "Rose") == nullptr); 
    
    clearPlants(head); 
    
    assert(head == nullptr); 
} 
// Week 7: File I/O  
void testWeek7FileIO() { 
    PlantNode* head = nullptr; 
    
    insertPlant( 
        head, 
        createPlant("Rose", "Flower", 3, 7) 
    ); 
    
    insertPlant( 
        head, 
        createPlant("Cactus", "Succulent", 10, 14) 
    ); 
    
    string filename = "test_plants.txt"; 
    
    assert(savePlants(filename, head)); 
    
    clearPlants(head); 
    
    assert(head == nullptr); 
    assert(loadPlants(filename, head)); 
    assert(countPlants(head) == 2); 
    
    PlantNode* rose = findPlant(head, "Rose"); 
    
    assert(rose != nullptr); 
    assert(rose->data.species == "Flower"); 
    
    PlantNode* cactus = findPlant(head, "Cactus"); 
    
    assert(cactus != nullptr); 
    assert(cactus->data.daysSinceWatered == 10); 
    
    clearPlants(head); 
    remove(filename.c_str()); 
} // Main Test Program  
int main() { 
    testWeek1ProgramBasics(); 
    cout << "Week 1 tests passed!" << endl; 
    
    testWeek2DecisionsAndLoops(); 
    cout << "Week 2 tests passed!" << endl; 
    
    testWeek3Functions(); 
    cout << "Week 3 tests passed!" << endl; 
    
    testWeek4Searching(); 
    cout << "Week 4 tests passed!" << endl; 
    
    testWeek5StringsAndStructures(); 
    cout << "Week 5 tests passed!" << endl; 
    
    testWeek6LinkedList(); 
    cout << "Week 6 tests passed!" << endl; 
    
    testWeek7FileIO(); 
    cout << "Week 7 tests passed!" << endl; 
    
    cout << "\nAll Plant Watering Log tests passed!" << endl; 
    
    return 0; 
}