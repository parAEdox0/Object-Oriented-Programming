/*Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, contact address, Telephone number, Driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.*/

#include <iostream>
#include <string>

using namespace std;

class Student;

class StudentDatabase
{
public:
    void displayStudentInfo(const Student &student);
};

class Student
{
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    static int count;

public:
    // Default constructor
    Student() : rollNumber(0), division('\0')
    {
        count++;
    }

    // Parameterized constructor
    Student(string n, int roll, string cls, char div,
            string dateOfBirth, string blood,
            string contact, string phone)
        : rollNumber(roll), division(div), name(n), className(cls),
          dob(dateOfBirth), bloodGroup(blood), contactAddress(contact),
          telephoneNumber(phone)
    {
        count++;
    }

    // Copy constructor
    Student(const Student &other)
        : rollNumber(other.rollNumber), division(other.division),
          name(other.name), className(other.className),
          dob(other.dob), bloodGroup(other.bloodGroup),
          contactAddress(other.contactAddress),
          telephoneNumber(other.telephoneNumber)
    {
        count++;
    }

    // Destructor
    ~Student()
    {
        count--;
    }

    // Static member function (marked as inline)
    inline static int getCount()
    {
        return count;
    }

    // Friend class declaration
    friend class StudentDatabase;

    // Member function to display student information
    void displayStudentInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << endl;
    }
};

// Initializing static member
int Student::count = 0;

void StudentDatabase::displayStudentInfo(const Student &student)
{
    student.displayStudentInfo();
}

int main()
{
    int numStudents;

    cout << "Enter the number of students you want to enter: ";
    cin >> numStudents;

    // Dynamically allocate an array of Student objects
    Student *students = new Student[numStudents];

    StudentDatabase db;

    // Input student information
    for (int i = 0; i < numStudents; ++i)
    {
        string name, className, dob, blood, contact, phone;
        int rollNumber;
        char division;

        cout << "\nEnter details for Student " << i + 1 << ":" << endl;

        cout << "Name: ";
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, name);

        cout << "Roll Number: ";
        cin >> rollNumber;

        cout << "Class: ";
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, className);

        cout << "Division: ";
        cin >> division;

        cout << "Date of Birth: ";
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, dob);

        cout << "Blood Group: ";
        cin >> blood;

        cout << "Contact Address: ";
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, contact);

        cout << "Telephone Number: ";
        cin >> phone;

        students[i] = Student(name, rollNumber, className, division, dob, blood, contact, phone);
    }

    // Display student information using member function
    for (int i = 0; i < numStudents; ++i)
    {
        students[i].displayStudentInfo();
    }

    // Display total number of students using static member function
    cout << "Total Students: " << Student::getCount() << endl;

    // Deallocate the dynamically allocated array
    delete[] students;

    return 0;
}
