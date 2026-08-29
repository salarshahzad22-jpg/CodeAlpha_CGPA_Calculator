#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct Course {
    string name;
    double creditHours;
    char grade;
    double gradePoint;
};

double getGradePoint(char grade) {
    grade = toupper(grade);

    switch (grade) {
        case 'A': return 4.00;
        case 'B': return 3.00;
        case 'C': return 2.00;
        case 'D': return 1.00;
        case 'F': return 0.00;
        default:  return -1.00;
    }
}

char getGrade() {
    char grade;

    while (true) {
        cout << "Enter grade (A/B/C/D/F): ";
        cin >> grade;
        grade = toupper(grade);

        if (grade == 'A' || grade == 'B' ||
            grade == 'C' || grade == 'D' ||
            grade == 'F') {
            return grade;
        }

        cout << "Invalid grade! Please try again.\n";
    }
}

double getCreditHours() {
    double credits;

    while (true) {
        cout << "Enter credit hours: ";
        cin >> credits;

        if (credits > 0 && credits <= 10) {
            return credits;
        }

        cout << "Invalid credit hours! Enter a value between 1 and 10.\n";
    }
}

int main() {

    cout << "=============================================\n";
    cout << "          CGPA CALCULATOR SYSTEM\n";
    cout << "=============================================\n\n";

    int numberOfCourses;

    // Number of courses
    while (true) {
        cout << "Enter number of courses: ";
        cin >> numberOfCourses;

        if (numberOfCourses > 0 && numberOfCourses <= 20) {
            break;
        }

        cout << "Please enter a valid number between 1 and 20.\n";
    }

    vector<Course> courses;

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    // Input course information
    for (int i = 0; i < numberOfCourses; i++) {

        Course course;

        cout << "\n---------------------------------------------\n";
        cout << "Course " << i + 1 << "\n";
        cout << "---------------------------------------------\n";

        cout << "Enter course name: ";
        cin >> ws;
        getline(cin, course.name);

        course.creditHours = getCreditHours();

        course.grade = getGrade();

        course.gradePoint = getGradePoint(course.grade);

        totalCredits += course.creditHours;
        totalGradePoints += course.creditHours * course.gradePoint;

        courses.push_back(course);
    }

    // Semester CGPA
    double semesterCGPA = totalGradePoints / totalCredits;

    // Previous academic record
    cout << "\n=============================================\n";
    cout << "       PREVIOUS ACADEMIC RECORD\n";
    cout << "=============================================\n";

    char previousChoice;

    cout << "Do you want to enter previous semester record? (Y/N): ";
    cin >> previousChoice;
    previousChoice = toupper(previousChoice);

    double previousCredits = 0.0;
    double previousGradePoints = 0.0;

    if (previousChoice == 'Y') {

        int previousSemesters;

        cout << "Enter number of previous semesters: ";
        cin >> previousSemesters;

        while (previousSemesters <= 0) {
            cout << "Enter a valid number of semesters: ";
            cin >> previousSemesters;
        }

        for (int i = 0; i < previousSemesters; i++) {

            double credits, cgpa;

            cout << "\nPrevious Semester " << i + 1 << "\n";

            cout << "Enter total credit hours: ";
            cin >> credits;

            cout << "Enter CGPA/GPA: ";
            cin >> cgpa;

            while (credits <= 0 || cgpa < 0 || cgpa > 4) {
                cout << "Invalid data. Please enter again.\n";

                cout << "Credit hours: ";
                cin >> credits;

                cout << "CGPA/GPA (0-4): ";
                cin >> cgpa;
            }

            previousCredits += credits;
            previousGradePoints += credits * cgpa;
        }
    }

    // Overall CGPA
    double overallCGPA;

    if (previousCredits > 0) {
        overallCGPA =
            (previousGradePoints + totalGradePoints) /
            (previousCredits + totalCredits);
    } 
    else {
        overallCGPA = semesterCGPA;
    }

    // Display course results
    cout << "\n\n=============================================\n";
    cout << "             COURSE RESULTS\n";
    cout << "=============================================\n";

    cout << left
         << setw(25) << "Course"
         << setw(15) << "Credits"
         << setw(10) << "Grade"
         << setw(15) << "Grade Point"
         << "\n";

    cout << "---------------------------------------------"
         << "----------------\n";

    for (const Course &course : courses) {

        cout << left
             << setw(25) << course.name
             << setw(15) << course.creditHours
             << setw(10) << course.grade
             << setw(15) << fixed << setprecision(2)
             << course.gradePoint
             << "\n";
    }

    cout << "\n=============================================\n";
    cout << "             FINAL RESULT\n";
    cout << "=============================================\n";

    cout << fixed << setprecision(2);

    cout << "Total Credit Hours : " << totalCredits << "\n";
    cout << "Total Grade Points : " << totalGradePoints << "\n";
    cout << "Semester CGPA     : " << semesterCGPA << "\n";
    cout << "Overall CGPA      : " << overallCGPA << "\n";

    cout << "=============================================\n";

    if (overallCGPA >= 3.50) {
        cout << "Performance: Excellent!\n";
    }
    else if (overallCGPA >= 3.00) {
        cout << "Performance: Very Good!\n";
    }
    else if (overallCGPA >= 2.50) {
        cout << "Performance: Good!\n";
    }
    else if (overallCGPA >= 2.00) {
        cout << "Performance: Satisfactory.\n";
    }
    else {
        cout << "Performance: Needs Improvement.\n";
    }

    cout << "=============================================\n";
    cout << "       Thank you for using CGPA Calculator!\n";
    cout << "=============================================\n";

    return 0;
}
