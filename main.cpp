#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

struct Course {
    string courseName;
    char grade;
    double creditHours;
    double gradePoint;
};

double getGradePoint(char grade) {
    char g = toupper(grade);
    double point;

     if (g == 'A') point = 4.0;
    else if (g == 'B') point = 3.0;
    else if (g == 'C') point = 2.0;
    else if (g == 'D') point = 1.0;
    else if (g == 'F') point = 0.0;
    else point = -1.0;

    if (point != -1.0) {
        cout << "Grade Point: " << point << endl;
    }

    return point;
}


int main() {
    int numCourses;

    cout << "=========================================\n";
    cout << "             CGPA CALCULATOR             \n";
    cout << "=========================================\n";

    cout << "Enter the number of courses: ";
    cin >> numCourses;


    while (numCourses <= 0) {
        cout << "Please enter a valid number of courses (greater than 0): ";
        cin >> numCourses;
    }

    vector<Course> courses(numCourses);
    double totalCreditHours = 0.0;
    double totalGradePoints = 0.0;


    for (int i = 0; i < numCourses; ++i) {
        cout << "\n--- Course " << (i + 1) << " ---" << endl;
        courses[i].courseName = "Course " + to_string(i + 1);


        cout << "Enter Grade (A, B, C, D, F): ";
        cin >> courses[i].grade;

        courses[i].gradePoint = getGradePoint(courses[i].grade);
        while (courses[i].gradePoint == -1.0) {
            cout << "Invalid grade! Enter again (A, B, C, D, F): ";
            cin >> courses[i].grade;
            courses[i].gradePoint = getGradePoint(courses[i].grade);
        }


        cout << "Enter Credit Hours: ";
        cin >> courses[i].creditHours;
        while (courses[i].creditHours <= 0) {
            cout << "Credit hours must be greater than 0. Re-enter: ";
            cin >> courses[i].creditHours;
        }


        totalCreditHours += courses[i].creditHours;
        totalGradePoints += (courses[i].gradePoint * courses[i].creditHours);
    }


    cout << "\n================ RESULTS ================\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < numCourses; ++i) {
        cout << courses[i].courseName
             << " | Grade: " << (char)toupper(courses[i].grade)
             << " | Credits: " << courses[i].creditHours
             << " | Quality Points: " << (courses[i].gradePoint * courses[i].creditHours)
             << endl;
    }


    if (totalCreditHours > 0) {
        double cgpa = totalGradePoints / totalCreditHours;
        cout << "=========================================\n";
        cout << "Total Credit Hours : " << totalCreditHours << endl;
        cout << "Total Grade Points  : " << totalGradePoints << endl;
        cout << "Final CGPA          : " << cgpa << endl;
        cout << "=========================================\n";
    }

    return 0;
}
