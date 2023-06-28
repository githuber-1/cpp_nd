#include <cassert>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class Student {
    public:
        // constructor
        Student(string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa) {}
        // accessors
        string GetName() const {
            return name_;
        }
        int GetGrade() const {
            return grade_;
        }

        float GetGPA() const {
            return gpa_;
        }
        // mutators  
        void SetName(string name) {
            name_ = name;
        }
        void SetGrade(int grade) {
            if (grade < 0 || grade > 12) {
                throw std::invalid_argument("Grade must be from 0 to 12");
            }
            grade_ = grade;
        }
        void SetGPA(float gpa) {
            if (gpa < 0.0 || gpa > 4.0) {
                throw std::invalid_argument("GPA must be 0.0 to 4.0");
            }
            gpa_ = gpa;
        }


 private:
  string name_;
  int grade_;
  float gpa_;

};

int main() {
    // valid
    
    bool exception = false;
    string error = "";
    // valid
    try {
        Student s("Henerly", 11, 2.3);
    }
    catch(...) {
        exception = true;
        error += "exception in valid test";
    }
    // invalid
    try {
        Student s2("bibble", 14, 8.9);
        cout << s2.GetName() << " ";
        cout << s2.GetGrade() << " ";
        cout << s2.GetGPA() << " ";
    }
    catch(...) {
        exception = true;
        error += "exception in invalid test";
    }


    cout << error;

    assert(exception);
}