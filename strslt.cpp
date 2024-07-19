#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;
    vector<float> grades;

public:
    Student(string name, int id, vector<float> grades) 
        : name(name), id(id), grades(grades) {}

    // Marked as const since it doesn't modify the object
    float calculateGPA() const {
        float sum = 0.0;
        for (float grade : grades) {
            sum += gradePoint(grade);
        }
        return grades.empty() ? 0.0 : sum / grades.size();
    }

    void display() const {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Grades: ";
        for (float grade : grades) {
            cout << grade << " (" << GradeLetter(grade) << ") ";
        }
        cout << endl;
        cout << "GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
    }

    int getId() const { return id; }
    string getName() const { return name; }

    string generateReport() const {
        stringstream report;
        report << "Student ID: " << id << "\n";
        report << "Name: " << name << "\n";
        report << "Grades: ";
        for (float grade : grades) {
            report << grade << " (" << GradeLetter(grade) << ") ";
        }
        report << "\n";
        report << "GPA: " << fixed << setprecision(2) << calculateGPA() << "\n";
        return report.str();
    }

    double gradePoint(double marks) const {
        if (marks >= 80 && marks <= 100)
            return 4.0;
        else if (marks >= 75 && marks < 80)
            return 3.75;
        else if (marks >= 70 && marks < 75)
            return 3.50;
        else if (marks >= 65 && marks < 70)
            return 3.25;
        else if (marks >= 60 && marks < 65)
            return 3.0;
        else if (marks >= 55 && marks < 60)
            return 2.75;
        else if (marks >= 50 && marks < 55)
            return 2.50;
        else if (marks >= 45 && marks < 50)
            return 2.25;
        else if (marks >= 40 && marks < 45)
            return 2.0;
        else
            return 0.0;
    }

    string GradeLetter(double marks) const {
        if (marks >= 80 && marks <= 100)
            return "A+";
        else if (marks >= 75 && marks < 80)
            return "A";
        else if (marks >= 70 && marks < 75)
            return "A-";
        else if (marks >= 65 && marks < 70)
            return "B+";
        else if (marks >= 60 && marks < 65)
            return "B";
        else if (marks >= 55 && marks < 60)
            return "B-";
        else if (marks >= 50 && marks < 55)
            return "C+";
        else if (marks >= 45 && marks < 50)
            return "C";
        else if (marks >= 40 && marks < 45)
            return "D";
        else
            return "F";
    }
};

class User {
private:
    string username;
    string password;
    bool isAdmin;

public:
    User(string username, string password, bool isAdmin = false) 
        : username(username), password(password), isAdmin(isAdmin) {}

    bool authenticate(string inputPassword) const {
        return password == inputPassword;
    }

    string getUsername() const { return username; }
    bool getIsAdmin() const { return isAdmin; }
};

class ResultManagementSystem {
private:
    vector<Student> students;
    vector<User> users;

    void addStudent() {
        string name;
        int id;
        int numGrades;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter student ID: ";
        cin >> id;
        cout << "Enter number of grades: ";
        cin >> numGrades;
        vector<float> grades(numGrades);
        cout << "Enter grades: ";
        for (int i = 0; i < numGrades; ++i) {
            cin >> grades[i];
        }
        students.push_back(Student(name, id, grades));
        cout << "Student added successfully." << endl;
    }

    void viewStudents() const {
        if (students.empty()) {
            cout << "No students to display." << endl;
            return;
        }
        for (const Student& student : students) {
            student.display();
            cout << "-------------------" << endl;
        }
    }

    void registerUser() {
        string username, password;
        bool isAdmin;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Is this user an admin? (1 for yes, 0 for no): ";
        cin >> isAdmin;
        users.push_back(User(username, password, isAdmin));
        cout << "User registered successfully." << endl;
    }

    void loginUser(User& loggedInUser) const {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (const User& user : users) {
            if (user.getUsername() == username && user.authenticate(password)) {
                loggedInUser = user;
                cout << "Login successful." << endl;
                return;
            }
        }
        cout << "Invalid username or password." << endl;
    }

    void generateReport() const {
        if (students.empty()) {
            cout << "No students to generate report for." << endl;
            return;
        }
        ofstream reportFile("student_report.txt");
        if (!reportFile) {
            cout << "Error creating report file." << endl;
            return;
        }
        for (const Student& student : students) {
            reportFile << student.generateReport() << endl;
            reportFile << "-------------------" << endl;
        }
        reportFile.close();
        cout << "Report generated successfully." << endl;
    }

public:
    void menu() {
        User loggedInUser("", "", false);
        int choice;

        do {
            if (!loggedInUser.getUsername().empty()) {
                cout << "Logged in as: " << loggedInUser.getUsername() << endl;
                cout << (loggedInUser.getIsAdmin() ? "Admin Menu" : "User Menu") << endl;
            } else {
                cout << "Welcome to Result Management System" << endl;
                cout << "1. Register User" << endl;
                cout << "2. Login User" << endl;
                cout << "3. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        registerUser();
                        break;
                    case 2:
                        loginUser(loggedInUser);
                        break;
                    case 3:
                        cout << "Exiting..." << endl;
                        return;
                    default:
                        cout << "Invalid choice. Try again." << endl;
                }
            }

            if (!loggedInUser.getUsername().empty()) {
                cout << "1. Add Student" << endl;
                cout << "2. View Students" << endl;
                cout << "3. Generate Report" << endl;
                cout << "4. Logout" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        if (loggedInUser.getIsAdmin()) {
                            addStudent();
                        } else {
                            cout << "Access denied. Admins only." << endl;
                        }
                        break;
                    case 2:
                        viewStudents();
                        break;
                    case 3:
                        if (loggedInUser.getIsAdmin()) {
                            generateReport();
                        } else {
                            cout << "Access denied. Admins only." << endl;
                        }
                        break;
                    case 4:
                        loggedInUser = User("", "", false);
                        cout << "Logged out successfully." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Try again." << endl;
                }
            }
        } while (choice != 3);
    }
};

int main() {
    ResultManagementSystem rms;
    rms.menu();
    return 0;
}
