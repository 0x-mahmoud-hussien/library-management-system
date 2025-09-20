#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ===================== Student Class =====================
class School
{
private:
    string name;
    int age;
    int numID;
    float GBA;
    int gradeLevel;
public:
    School(string n, int a, int ni, float G, int gl)
    {
        name = n;
        age = a;
        numID = ni;
        GBA = G;
        gradeLevel = gl;
    }

string getName() { return name; }
int getAge() { return age; }
int getNumID() { return numID; }
float getGBA() { return GBA; }
int getGradeLevel() { return gradeLevel; }

void displayStudentInfo()
{
    cout << "Student Name = " << name << "\n";
    cout << "Student Age = " << age << "\n";
    cout << "Student Number ID = " << numID << "\n";
    cout << "Student GBA = " << GBA << "\n";
    cout << "Student Grade Level = " << gradeLevel << "\n";
    cout << "=================================\n";
}

void ubdateInteractive()
{
    char choice;
    cout << "Do You Want Update The Name? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New Name: ";
        cin >> name;
    }
    cout << "Do You Want Update The Age? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New Age: ";
        cin >> age;
    }
    cout << "Do You Want Update The ID? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New ID: ";
        cin >> numID;
    }
    cout << "Do You Want Update The GBA? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New GBA: ";
        cin >> GBA;
    }
    cout << "Do You Want Update The Grade Level? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New Grade Level: ";
        cin >> gradeLevel;
    }

    cout << "Student Information Updated Successfully✅" << "\n";
}
};

// ===================== Teacher Class =====================
class Teacher
{
private:
    string name;
    int age;
    int teacherID;
    string subject;
    int yearsOfExperience;
public:
    Teacher(string n, int a, int t, string s, int ye)
    {
        name = n;
        age = a;
        teacherID = t;
        subject = s; 
        yearsOfExperience = ye;
    }

string getName() { return name; }
int getAge() { return age; }
int getTeacherID() { return teacherID; }
string getSubject() { return subject; }
int getyearsOfExperience() { return yearsOfExperience; }

void deiplayTeacherInfo()
{
    cout << "Teacher Name = " << name << "\n";
    cout << "Teacher Age = " << age << "\n";
    cout << "Teacher ID = " << teacherID << "\n";
    cout << "Teacher Subject = " << subject << "\n";
    cout << "Teacher Years Of Experience = " << yearsOfExperience << "\n";
    cout << "=================================\n";
}

void ubdateInteractive()
{
    char choice;
    cout << "Do You Want Update The Name? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New Name: ";
        cin >> name;
    }
    cout << "Do You Want Update The Age? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New Age: ";
        cin >> age;
    }
    cout << "Do You Want Update The ID? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New ID: ";
        cin >> teacherID;
    }
    cout << "Do You Want Update The Subject? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New Subject: ";
        cin >> subject;
    }
    cout << "Do You Want Update The Years Of Experiance? (y/n)";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter New Years Of Experiance: ";
        cin >> yearsOfExperience;
    }

    cout << "Teacher Information Updated Successfully✅" << "\n";
}
};

// ===================== Course Class =====================
class Course
{
private:
    string courseName;
    int courseCode;
    string teacherName;
public:
    Course(string cn, int cc, string tn)
    {
        courseName = cn;
        courseCode = cc;
        teacherName = tn;
    }

string getCourseName() { return courseName; }
int getCourseCode() { return courseCode; }
string getTeacherName() { return teacherName; }

void displayStudentInfo()
{
    cout << "Course Name = " << courseName << "\n";
    cout << "Course Code = " << courseCode << "\n";
    cout << "Teacher Name = " << teacherName << "\n";
    cout << "=================================\n";
}
};

// ===================== SchoolSystem Class =====================
class School
{
private:
    /* data */
public:
    School(/* args */);
};

