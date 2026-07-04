#include "project.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
    return fabs(actual - expected) <= tolerance;
}

void createTestInventoryFile(string filename) {
    ofstream out(filename);

    out << "A100 Apples 10 1.50" << endl;
    out << "B200 Bread 5 3.25" << endl;
    out << "C300 Cereal 8 4.75" << endl;

    out.close();
}

// Week 1: Program Basics
void testWeek1ProgramBasics() {
    ScoreList scores;
    scores.addScore(80.0);
    scores.addScore(90.0);

    double average = scores.getAverage();

    assert(nearlyEqual(average, 85.0));
    assert(Student::determineLetterGrade(95.0) == 'A');
    assert(Student::determineLetterGrade(65.0) == 'D');
}

// Week 2: Decisions and Loops
void testWeek2DecisionsAndLoops() {
    assert(ScoreList::isValidScore(0.0));
    assert(ScoreList::isValidScore(100.0));
    assert(!ScoreList::isValidScore(-1.0));
    assert(!ScoreList::isValidScore(101.0));

    assert(Task::isValidPriority(1));
    assert(Task::isValidPriority(5));
    assert(!Task::isValidPriority(0));
    assert(!Task::isValidPriority(6));

    assert(isValidMenuChoice(0));
    assert(isValidMenuChoice(4));
    assert(!isValidMenuChoice(5));
}

// Week 3: Functions and Program Design
void testWeek3FunctionsAndProgramDesign() {
    ScoreList scores;
    scores.addScore(70.0);
    scores.addScore(80.0);
    scores.addScore(90.0);

    assert(nearlyEqual(scores.getTotal(), 240.0));
    assert(nearlyEqual(scores.getAverage(), 80.0));

    Student student("A123", "Alex");
    assert(student.getId() == "A123");
    assert(student.getName() == "Alex");
}

// Week 4: Arrays, Searching, and Sorting
void testWeek4ArraysSearchingSorting() {
    ScoreList scores;
    scores.addScore(88.0);
    scores.addScore(72.5);
    scores.addScore(100.0);
    scores.addScore(91.0);

    assert(scores.findScore(100.0) == 2);
    assert(scores.findScore(50.0) == -1);

    scores.sortAscending();

    assert(nearlyEqual(scores.getScoreAt(0), 72.5));
    assert(nearlyEqual(scores.getScoreAt(1), 88.0));
    assert(nearlyEqual(scores.getScoreAt(2), 91.0));
    assert(nearlyEqual(scores.getScoreAt(3), 100.0));
}

// Week 5: Strings and Structures
void testWeek5StringsAndStructures() {
    Student student("A123", "Alex");

    assert(Student::isValidId("A123"));
    assert(!Student::isValidId("a123"));
    assert(student.getId() == "A123");
    assert(student.getName() == "Alex");

    InventoryItem item = {"B200", "Bread", 5, 3.25};
    assert(item.sku == "B200");
    assert(item.name == "Bread");
    assert(item.quantity == 5);
}

// Week 6: Simple Linked Task List
void testWeek6SimpleLinkedTaskList() {
    TaskList tasks;

    tasks.insertFront(Task("homework", 3));
    tasks.insertFront(Task("study", 5));
    tasks.insertFront(Task("project", 4));

    assert(tasks.countTasks() == 3);
    assert(tasks.findTask("study") != nullptr);
    assert(tasks.findTask("missing") == nullptr);

    assert(tasks.markTaskComplete("homework"));
    assert(tasks.markTaskComplete("project"));

    int removed = tasks.removeCompletedTasks();

    assert(removed == 2);
    assert(tasks.countTasks() == 1);
    assert(tasks.findTask("study") != nullptr);
    assert(tasks.findTask("homework") == nullptr);

    tasks.clear();
    assert(tasks.isEmpty());
}

// Week 7: File-Based Inventory Report
void testWeek7FileBasedInventoryReport() {
    string inputFilename = "tests/resources/test_inventory_input.txt";
    string outputFilename = "tests/resources/test_inventory_report_output.txt";

    createTestInventoryFile(inputFilename);

    InventoryItem items[10];
    int count = InventoryReport::readInventoryFile(inputFilename, items, 10);

    assert(count == 3);
    assert(items[0].sku == "A100");
    assert(items[2].name == "Cereal");

    assert(nearlyEqual(InventoryReport::calculateItemValue(items[0]), 15.0));
    assert(nearlyEqual(InventoryReport::calculateTotalInventoryValue(items, count), 69.25));

    assert(InventoryReport::findItemBySku(items, count, "B200") == 1);
    assert(InventoryReport::findItemBySku(items, count, "Z999") == -1);
    assert(InventoryReport::findHighestValueItemIndex(items, count) == 2);

    bool wroteReport = InventoryReport::writeInventoryReport(outputFilename, items, count);
    assert(wroteReport);

    ifstream in(outputFilename);
    assert(in.is_open());

    string contents;
    string line;

    while (getline(in, line)) {
        contents += line + "\n";
    }

    assert(contents.find("Inventory Report") != string::npos);
    assert(contents.find("A100") != string::npos);
    assert(contents.find("Total inventory value") != string::npos);
}

int main() {
    testWeek1ProgramBasics();
    testWeek2DecisionsAndLoops();
    testWeek3FunctionsAndProgramDesign();
    testWeek4ArraysSearchingSorting();
    testWeek5StringsAndStructures();
    testWeek6SimpleLinkedTaskList();
    testWeek7FileBasedInventoryReport();

    cout << "All corrected final project template tests passed!" << endl;
    return 0;
}
