#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    cout << "=====================================" << endl;
    cout << "           CGPA CALCULATOR           " << endl;
    cout << "=====================================" << endl;

    int semesters;
    cout << "\nEnter Number of Semesters: ";
    cin >> semesters;

    if (semesters <= 0)
    {
        cout << "Invalid number of semesters!" << endl;
        return 0;
    }

    float grand_total_points = 0;
    float grand_total_credits = 0;

    for (int s = 0; s < semesters; s++)
    {
        cout << "\n---------- Semester " << s + 1 << " ----------" << endl;

        int no_of_courses;
        cout << "\nEnter Number of Courses: ";
        cin >> no_of_courses;

        if (no_of_courses <= 0)
        {
            cout << "Invalid number of courses!" << endl;
            s--;
            continue;
        }

        string* grade = new string[no_of_courses];
        float* gradePoints = new float[no_of_courses];
        float* creditHours = new float[no_of_courses];

        for (int i = 0; i < no_of_courses; i++)
        {
            cout << "\nCourse " << i + 1 << ":" << endl;

            // Grade input + validation
            do
            {
                cout << "   Enter Grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
                cin >> grade[i];

                if (!(grade[i] == "A+" || grade[i] == "A" || grade[i] == "A-" ||
                    grade[i] == "B+" || grade[i] == "B" || grade[i] == "B-" ||
                    grade[i] == "C+" || grade[i] == "C" || grade[i] == "C-" ||
                    grade[i] == "D+" || grade[i] == "D" || grade[i] == "F"))
                {
                    cout << "Invalid grade! Try again." << endl;
                }

            } while (!(grade[i] == "A+" || grade[i] == "A" || grade[i] == "A-" ||
                grade[i] == "B+" || grade[i] == "B" || grade[i] == "B-" ||
                grade[i] == "C+" || grade[i] == "C" || grade[i] == "C-" ||
                grade[i] == "D+" || grade[i] == "D" || grade[i] == "F"));

            // Conversion
            if (grade[i] == "A+" || grade[i] == "A")
                gradePoints[i] = 4.00;
            else if (grade[i] == "A-")
                gradePoints[i] = 3.67;
            else if (grade[i] == "B+")
                gradePoints[i] = 3.33;
            else if (grade[i] == "B")
                gradePoints[i] = 3.00;
            else if (grade[i] == "B-")
                gradePoints[i] = 2.67;
            else if (grade[i] == "C+")
                gradePoints[i] = 2.33;
            else if (grade[i] == "C")
                gradePoints[i] = 2.00;
            else if (grade[i] == "C-")
                gradePoints[i] = 1.67;
            else if (grade[i] == "D+")
                gradePoints[i] = 1.33;
            else if (grade[i] == "D")
                gradePoints[i] = 1.00;
            else gradePoints[i] = 0.00;

            // Credit hours
            do
            {
                cout << "   Enter Credit Hours: ";
                cin >> creditHours[i];

                if (creditHours[i] <= 0)
                    cout << "Invalid credit hours!" << endl;

            } while (creditHours[i] <= 0);
        }

        float total_points = 0;
        int total_credits = 0;

        for (int i = 0; i < no_of_courses; i++)
        {
            total_points += gradePoints[i] * creditHours[i];
            total_credits += creditHours[i];
        }

        float semester_gpa = total_points / total_credits;

        cout << "\n=====================================" << endl;
        cout << "             Course Details             " << endl;
        cout << "=====================================" << endl;
        cout << left << setw(10) << "Course" << setw(10) << "Grade" << setw(15) << "Credits" << endl;

        cout << "-------------------------------------" << endl;

        for (int i = 0; i < no_of_courses; i++)
        {
            cout << left << setw(10) << i + 1 << setw(10) << grade[i] << setw(15) << creditHours[i] << endl;
        }

        cout << "-------------------------------------" << endl;
        cout << "Semester GPA: " << fixed << setprecision(2) << semester_gpa << endl;

        grand_total_points += total_points;
        grand_total_credits += total_credits;

        delete[] grade;
        delete[] gradePoints;
        delete[] creditHours;
    }

    float cgpa = grand_total_points / grand_total_credits;

    cout << "\n---------- Final Result ----------" << endl;

    cout << "Total Credits: " << grand_total_credits << endl;
    cout << "Overall CGPA: " << fixed << setprecision(2) << cgpa << endl;

    cout << "\nThank you for using the calculator." << endl;

    system("pause");
    return 0;
}