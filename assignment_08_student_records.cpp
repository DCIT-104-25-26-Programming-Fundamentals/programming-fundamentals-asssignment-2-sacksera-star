// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    double total = 0;
    for (double score : scores) {
        total += score;
    }
    return total / scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;

    cin.ignore();
    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << string(55, '-') << endl;
    cout << left << setw(15) << "Name" << setw(12) << "ID"
         << setw(18) << "Scores" << setw(10) << "Average" << endl;
    cout << string(55, '-') << endl;

    for (const Student& s : students) {
        string scoresStr;
        for (size_t i = 0; i < s.scores.size(); i++) {
            if (i > 0) scoresStr += ", ";
            ostringstream oss;
            oss << s.scores[i];
            scoresStr += oss.str();
        }

        double avg = calculateAverage(s.scores);

        cout << left << setw(15) << s.name << setw(12) << s.id
             << setw(18) << scoresStr
             << fixed << setprecision(2) << avg << endl;
    }
    cout << string(55, '-') << endl;
}

void findStudentAverage(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (const Student& s : students) {
        if (s.id == id) {
            double avg = calculateAverage(s.scores);
            cout << s.name << "'s average score: "
                 << fixed << setprecision(2) << avg << endl;
            return;
        }
    }

    cout << "Error: No student found with that ID." << endl;
}

void printMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<Student> students;

    while (true) {
        printMenu();
        cout << "Enter your choice (1-4): ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
            continue;
        }

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayStudents(students);
        } else if (choice == 3) {
            findStudentAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}

