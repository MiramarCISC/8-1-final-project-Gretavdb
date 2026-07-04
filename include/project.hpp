#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>

const double A_MINIMUM = 90.0;
const double B_MINIMUM = 80.0;
const double C_MINIMUM = 70.0;
const double D_MINIMUM = 60.0;
const int MAX_INVENTORY_ITEMS = 100;

// SAMPLE CODE ONLY:
// These classes demonstrate course concepts using sample project nouns.
// Delete or replace these sample classes before final submission.

class ScoreList {
private:
    double scores[10];
    int count;

public:
    ScoreList();

    bool addScore(double score);
    int getCount() const;
    double getScoreAt(int index) const;

    double getTotal() const;
    double getAverage() const;
    int findScore(double target) const;
    void sortAscending();

    static bool isValidScore(double score);
};

class Student {
private:
    std::string id;
    std::string name;
    ScoreList scoreList;

public:
    Student();
    Student(std::string studentId, std::string studentName);

    std::string getId() const;
    std::string getName() const;
    ScoreList& getScoreList();
    const ScoreList& getScoreList() const;

    double getAverage() const;
    char getLetterGrade() const;

    static bool isValidId(std::string id);
    static char determineLetterGrade(double average);
};

class Task {
private:
    std::string description;
    int priority;
    bool completed;

public:
    Task();
    Task(std::string taskDescription, int taskPriority);

    std::string getDescription() const;
    int getPriority() const;
    bool isCompleted() const;
    void markComplete();

    static bool isValidPriority(int priority);
};

class TaskNode {
public:
    Task data;
    TaskNode* next;

    TaskNode(Task task);
};

class TaskList {
private:
    TaskNode* head;

public:
    TaskList();
    TaskList(const TaskList& other) = delete;
    TaskList& operator=(const TaskList& other) = delete;
    ~TaskList();

    void insertFront(Task task);
    int countTasks() const;
    TaskNode* findTask(std::string description);
    const TaskNode* findTask(std::string description) const;
    bool markTaskComplete(std::string description);
    int removeCompletedTasks();
    void clear();
    bool isEmpty() const;
};

struct InventoryItem {
    std::string sku;
    std::string name;
    int quantity;
    double price;
};

class InventoryReport {
public:
    static bool isValidQuantity(int quantity);
    static bool isValidPrice(double price);
    static double calculateItemValue(const InventoryItem& item);

    static int readInventoryFile(std::string filename, InventoryItem items[], int maxItems);
    static bool writeInventoryReport(std::string filename, const InventoryItem items[], int count);

    static double calculateTotalInventoryValue(const InventoryItem items[], int count);
    static int findItemBySku(const InventoryItem items[], int count, std::string sku);
    static int findHighestValueItemIndex(const InventoryItem items[], int count);
};

bool isValidMenuChoice(int choice);
void printMenu();
void printStudent(const Student& student);

#endif
