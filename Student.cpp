#include <iostream>
#include <vector>
using namespace std;

class Student
{
protected:
    string name;
    int age;
    int ID;
    float GPA;
    string major;
    vector<string> courses;
    bool is_Enrolled;
public:
    Student(string n, int ag, int I, float GP, string ma, bool iE)
    {
        name = n;
        age = ag;
        ID = I;
        GPA = GP;
        major = ma;
        is_Enrolled = iE;
    }

    void enrollCourse(string course)
    {
        courses.push_back(course);
    }

    virtual float get_finalgrade() = 0; // abstract method

    virtual void print()
    {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "GPA = " << GPA << endl;
        cout << "Major = " << major << endl;
        cout << "Is Enrolled = " << (is_Enrolled ? "Yes" : "No") << endl;
        cout << "Courses: ";
        for (auto &c : courses)
            cout << c << " ";
        cout << endl;
    }
};

class UndergraduateStudent : public Student
{
private:
    float bonus_marks;
    bool is_FullTime;
public:
    UndergraduateStudent(string n, int ag, int I, float GP, string ma, bool iE,
        float bm, bool FT) : Student(n, ag, I, GP, ma, iE)
    {
        bonus_marks = bm;
        is_FullTime = FT;
    }

    float get_finalgrade()
    {
        return GPA + bonus_marks;
    }

    void print()
    {
        Student::print();
        cout << "Bonus Marks = " << bonus_marks << endl;
        cout << "Is Full Time = " << (is_FullTime ? "Yes" : "No") << endl;
        cout << "Final Grade = " << get_finalgrade() << endl;
        cout << "==============================" << endl;
    }
};

class PostgraduateStudent : public Student
{
private:
    string research_area;
    string degree;
    float project_Grade;
    bool is_FullTime;
public:
    PostgraduateStudent(string n, int ag, int I, float GP, string ma, bool iE,
        string rsa, string dg, float pg, bool FT) : Student(n, ag, I, GP, ma, iE)
    {
        research_area = rsa;
        degree = dg;
        project_Grade = pg;
        is_FullTime = FT;
    }

    float get_finalgrade()
    {
        return GPA + project_Grade;
    }

    void print()
    {
        Student::print();
        cout << "Research Area = " << research_area << endl;
        cout << "Degree = " << degree << endl;
        cout << "Project Grade = " << project_Grade << endl;
        cout << "Is Full Time = " << (is_FullTime ? "Yes" : "No") << endl;
        cout << "Final Grade = " << get_finalgrade() << endl;
        cout << "==============================" << endl;
    }
};

int main()
{
    Student *st_ptr;

    UndergraduateStudent u1("Mahmoud", 23, 150, 3.2, "Computer Science", true, 0.3, true);
    u1.enrollCourse("Programming");
    u1.enrollCourse("Math");

    PostgraduateStudent p1("Ahmed", 25, 151, 3.8, "Engineering", true, "AI", "Master's", 0.5, true);
    p1.enrollCourse("Algorithms");
    p1.enrollCourse("Research Methods");

    st_ptr = &u1;
    st_ptr->print();

    st_ptr = &p1;
    st_ptr->print();

    return 0;
}