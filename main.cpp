#include <iostream>
using namespace std;

struct Course {
    double grade;
    double creditHours;
};

int main() {
    int numberofCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;


    if (numberofCourses <= 0 || numberofCourses > 100) {
        cout << "Please enter a valid number of courses between 1 and 100." << endl;
        return 1;
    }


    Course courses[100];

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;


    for (int i = 0; i < numCourses; ++i) {
        cout << "\n--- Course " << (i + 1) << " ---" << endl;
        cout << "Enter grade point (e.g., 4.0, 3.5, 3.0): ";
        cin >> courses[i].grade;

        cout << "Enter credit hours: ";
        cin >> courses[i].creditHours;

        totalCredits += courses[i].creditHours;
        totalGradePoints += (courses[i].grade * courses[i].creditHours);
    }


    cout << "\n===================================" << endl;
    cout << "          COURSE SUMMARY           " << endl;
    cout << "===================================" << endl;
    for (int i = 0; i < numberofCourses; ++i) {
        cout << "Course " << (i + 1)
             << " | Grade: " << courses[i].grade
             << " | Credits: " << courses[i].creditHours << endl;
    }


    if (totalCredits > 0) {
        double cgpa = totalGradePoints / totalCredits;

        cout << "-----------------------------------" << endl;
        cout << "Total Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << totalGradePoints << endl;
        cout << "Final CGPA: " << cgpa << endl;
        cout << "===================================" << endl;
    }
    else {
        cout << "\nInvalid credit total. Unable to calculate CGPA." << endl;
    }


    return 0;
}
