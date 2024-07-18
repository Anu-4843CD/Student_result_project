//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

void LoadingBar();
void MainMenu();
void SelfExit();
void AdminMenu();
void UserMenu();
void Registration();
void Forgot();
void DataEntry();
void Calculate();
void AdminOptions();
void UserOption();
void SearchResult();
void PrintAllResult();
void Stats();
void ReportGenerate();
void ReportGenerateS();
double gradePoint(double marks);
string GradeLetter(double marks);

int main() {
    system("CLS");
    system("color f1");
    LoadingBar();
    MainMenu();
    return 0;
}
void LoadingBar() {
    char a = 219;
    system("CLS");
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\n\n";
    cout << "\n\n\n\n\t\t\tLoading.....\n";
    cout << "\t\t\t====================\n\n";
    for (int i = 0; i < 100; i+=2) {
        int progress = ((i * 100) / 99);
        int pos = (i * 50) / 99;
        for (int j = 0; j < 50; j++) {
            if (j < pos)
                cout << a;
            else
                cout << " ";
        }
        cout << " " << progress << "%" << "\r";
        cout << "\t\t\t";
        Sleep(2);
    }
    cout << endl;

}
void SavingBar() {
    char a = 219;
    system("CLS");
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\n\n";
    cout << "\n\n\n\n\t\t\t Saving Informations.....\n";
    cout << "\t\t\t======================\n\n";
    for (int i = 0; i < 100; i+=2) {
        int progress = (i * 100) / 99;
        int pos = (i * 50) / 99;
        for (int j = 0; j < 50; j++) {
            if (j < pos)
                cout << a;
            else
                cout << " ";
        }
        cout << " " << progress << "%" << "\r";
        cout << "\t\t\t";
        Sleep(1);
    }
    cout << endl;

}
void MainMenu() {
    system("CLS");
    string cc;
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\t\t\t\t\t\tWelcome To The Login Page                       \n\n";
    cout << "\t\t\t Press 1 to Admin Login                 " << endl;
    cout << "\t\t\t Press 2 to User Login                  " << endl;
    cout << "\t\t\t Press 3 to User Registration           " << endl;
    cout << "\t\t\t Press 4 to Forgot Password             " << endl;
    cout << "\t\t\t Press 5 to Exit                        " << endl;
    cout << "\n\t\t\t Please Enter Your Choice :  ";
    cin >> cc;
    cout << endl;
    int choice;
    if (cc != "1" and cc != "2" and cc != "3" and cc != "4" and cc != "5")
        choice = 6;
    else
        choice = stoi(cc); // string to integer
    switch (choice) {
    case 1:
        AdminMenu();
        break;
    case 2:
        UserMenu();
        break;
    case 3:
        Registration();
        break;
    case 4:
        Forgot();
        break;
    case 5:
        SelfExit();
        break;
    default:
        cout << "\n\t\t\t";
        cout<<"\n\t\t\tWrong Choice";
        cout << "\n\t\t\tPress Any Key To Continue... ";
        getch();
        MainMenu();
    }
}

void Registration() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\n\n";
    cout << "\t\t\tRegistration Page                           \n";

    string ruserId, rPassword, rid, rpass;
    cout << "\t\t\tEnter The Username : ";
    cin >> ruserId;
    cout << "\t\t\tEnter The Password : ";
    cin >> rPassword;

    ofstream f1("login.dat", ios::app); // opening file in append mode
    f1 << ruserId << ' ' << rPassword << endl;
    SavingBar();
    system("CLS");
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\t\t\tRegistration Successfully!                  \n\n\n";
    cout << "\t\t\tPress any key to continue...";
    getch();
    MainMenu();
}

void UserMenu() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\n\n";
    int counts = 0;
    string userId, uPassword, id, pass;
    cout << "\t\t\tPlease Enter The Username and Password : " << endl;

    cout << "\t\t\tUsername: ";
    cin >> userId;
    cout << "\t\t\tPassword: ";
    cin >> uPassword;

    ifstream input("login.dat"); // by default ifstream opens file in read mode.

    while (input >> id >> pass) {
        if (id == userId && pass == uPassword) {
            counts = 1;
            break;
        }
    }
    input.close();
    LoadingBar();
    if (counts == 1) {
        cout << "\t\t\tLogin Successfully \n\n";
        if (counts == 1) {
            UserOption();
        }
    } else {
        system("CLS");
        cout << "\t\t\t_____________________________________________________________\n";
        cout << "\t\t\t\t\t\tResult Management System\n";
        cout << "\t\t\t______________________________________________________________\n\n";
        cout << "\n\t\t\tWrong Username or Password\n";
        cout << "\t\t\tPress any key to continue...";
        getch();
        UserMenu();
    }
}
void AdminMenu() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\n\n";
    cout << "\t\t\tPlease Enter Username and Password : " << endl;
    int counts = 0;
    string userId, uPassword, id, pass;
    cout << "\t\t\tUsername: ";
    cin >> userId;
    cout << "\t\t\tPassword: ";
    cin >> uPassword;

    ifstream input("admin.dat");

    while (input >> id >> pass) {
        if (id == userId && pass == uPassword) {
            counts = 1;
            break;
        }
    }
    input.close();
    LoadingBar();
    if (counts == 1) {
        cout << "\t\t\tLogin Successfully                     \n\n";
        if (counts == 1) {
            AdminOptions();
        }
    } else {
        system("CLS");
        cout << "\t\t\t_____________________________________________________________\n";
        cout << "\t\t\t\t\t\tResult Management System\n";
        cout << "\t\t\t______________________________________________________________\n\n";
        cout << "\n\t\t\tWrong Username or Password\n";
        cout << "\t\t\tPress any key to continue...";
        getch();
        AdminMenu();
    }
}
void Forgot() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\n\n";
    cout << "\t\t\tForgot Password?                 \n\n";

    cout << "\t\t\tPress 1 To Search By Username    \n";
    cout << "\t\t\tPress 2 To The Main Menu         \n";
    string soption;
    cout << "\t\t\tEnter Your Choice :";
    cin >> soption;
    int option;
    if (soption != "1" && soption != "2")
        option = 3;
    else
        option = soption[0] - '0';
    switch (option) {
    case 1: {
        int counts = 0;
        string suserId, sId, spass;
        cout << "\n\t\t\tEnter The Username Which You Remembered :";
        cin >> suserId;

        ifstream f2("login.dat");
        while (f2 >> sId >> spass) {
            if (sId == suserId) {
                counts = 1;
                break;
            }
        }
        f2.close();
        system("CLS");
        cout << "\t\t\t______________________________________________________________\n";
        cout << "\t\t\t\t\t\tResult Management System\n";
        cout << "\t\t\t______________________________________________________________\n\n";
        if (counts == 1) {
            cout << "\n\n\t\t\tYour account is found! \n";
            cout << "\n\t\t\tYour Password is :" << spass << endl;
            cout << "\n\t\t\tPress any key to continue...";
            getch();
            MainMenu();
        } else {
            cout << "\n\n\t\t\tYour account is not found! Please try again \n";
            getch();
            Forgot();
        }
        break;
    }
    case 2: {
        MainMenu();
    }
    default:
        cout << "\t\t\t Wrong choice !";
        cout << "\n\t\t\tPress any key to continue...";
        getch();
        Forgot();
    }
}

void AdminOptions() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    cout << "\n\n";
    cout << "\t\t\t Press 1 to Data Entry                 " << endl;
    cout << "\t\t\t Press 2 to Result Calculation         " << endl;
    cout << "\t\t\t Press 3 to Show All Result            " << endl;
    cout << "\t\t\t Press 4 to Show Statistics            " << endl;
    cout << "\t\t\t Press 5 to Generate Report            " << endl;
    cout << "\t\t\t Press 6 to Logout                     " << endl;
    cout << "\n\t\t\tEnter Your Choice :  ";
    string cc;
    cin >> cc;
    cout << endl;
    int choice;
    if (cc != "1" and cc != "2" and cc != "3" and cc != "4" and cc != "5" and cc != "6")
        choice = 7;
    else
        choice = stoi(cc); // string to integer

    switch (choice) {
    case 1:
        DataEntry();
        break;
    case 2:
        Calculate();
        break;
    case 3:
        PrintAllResult();
        break;
    case 4:
        Stats();
        break;
    case 5:
        ReportGenerate();
        break;
    case 6:  // logout
        MainMenu();
        break;
    default:
        cout << "\n\t\t\tWrong Choice";
        cout << "\n\t\t\tPress Any Key To Continue... ";
        getch();
        AdminOptions();
    }
}
void UserOption() {
    system("CLS");
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";

    cout << "\n\n";
    cout << "\t\t\t Press 1 to Search Your Result                   " << endl;
    cout << "\t\t\t Press 2 to Generate Report                      " << endl;
    cout << "\t\t\t Press 3 to Logout                               " << endl;
    cout << "\n\t\t\t Please Enter Your Choice :  ";
    string cc;
    cin >> cc;
    cout << endl;
    int choice;
    if (cc != "1" and cc != "2" and cc != "3")
        choice = 4;
    else
        choice = stoi(cc);

    switch (choice) {
    case 1:
        SearchResult();
        break;
    case 2:
        ReportGenerateS();
        break;
    case 3:  // logout
        MainMenu();
        break;
    default:
        cout << "\n\t\t\tWrong Choice";
        cout << "\n\t\t\tPress Any Key To Continue... ";
        getch();
        UserOption();
    }
}

double gradePoint(double marks) {
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
string GradeLetter(double marks) {
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

void DataEntry() {
    system("CLS");
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t_____________________________________________________________\n\n";
    cout << "\t\t\tEnter Number Of Student: ";
    int numberOfStudent, numberOfCourse;
    cin >> numberOfStudent;

    // Opening Files in write mode
    ofstream myFile("data.dat", ios::out);
    ofstream cFile("coursedata.dat", ios::out);
    cin.ignore();
    bool flag = false;
    for (int i = 1; i <= numberOfStudent; i++) {
        cout << "\n\t\t\tEnter Name Of The Student " << i << " : ";
        string name;
        string id;
        getline(cin, name);
        cout << "\n\t\t\tEnter ID Of The Student " << i << " : ";
        getline(cin, id);
        cout << "\n\t\t\tEnter Number Of Course : ";
        cin >> numberOfCourse;
        cin.ignore();
        if(!flag) {
            ofstream file("noc.dat", ios::out);
            file<<numberOfCourse;
            flag = true;
            file.close();
        }
        myFile << name << " " << id << endl;
        for (int j = 1; j <= numberOfCourse; j++) {
            string courseName;
            double creditHour, marks;
            cout << "\n\t\t\tEnter Course Name " << j << " : ";
            getline(cin, courseName);
            cout << "\n\t\t\tEnter Credit Hours " << j << " : ";
            cin >> creditHour;
            cout << "\n\t\t\tEnter Obtained Mark " << j << " : ";
            cin >> marks;
            cin.ignore();
            myFile << creditHour << " " << marks << endl;
            cFile << courseName << endl;
        }
    }
    // closing file
    myFile.close();
    cFile.close();
    cout << "\t\t\tPress Any Key To Continue... ";
    getch();
    AdminOptions();
}

void Calculate() {
    system("CLS");
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t_____________________________________________________________\n\n";
    cout << "\n\n";
    cout << "\t\t\tCalculation Done\n";
    int numberOfCourse;
    ifstream file("noc.txt");
    file>>numberOfCourse;
    file.close();
    ofstream myFile("result.dat", ios::out); //Opening file in write mode

    ifstream din("data.dat");
    string name;

    int counter = 0;
    double totalGradePoints = 0, totalCredits = 0, c = 0, g = 0;
    bool flag = false;
    while (getline(din, name)) {
        if (counter == 0) {
            string n, id;
            int i = 0;
            for (i = 0; i < (int)name.size(); i++) {
                if (isdigit(name[i])) {
                    break;
                } else
                    n.push_back(name[i]);
            }
            id = name.substr(i, (int)name.size());
            myFile << n << endl;
            myFile << id << endl;
            counter = 1;
        } else {
            flag = false;
            stringstream ss(name);
            string out;
            ss >> out;
            c = stod(out); // string to double
            totalCredits += c;
            ss >> out;
            g = gradePoint(stod(out)); // string to double
            if (g == (double)0.0) {
                flag = true;
            }
            totalGradePoints += (g * c);
            for (int i = 1; i < numberOfCourse; i++) {
                getline(din, name);
                stringstream ss(name);
                string out;
                ss >> out;
                c = stod(out);
                totalCredits += c;
                ss >> out;
                g = gradePoint(stod(out));
                if (g == (double)0.0) {
                    flag = true;
                }
                totalGradePoints += (g * c);
            }
            counter = 0;
            double cgpa = totalGradePoints / totalCredits;
            if (flag)
                myFile << "0.0" << endl;
            else
                myFile << fixed << setprecision(2) << cgpa << endl;
        }
        totalGradePoints = 0, totalCredits = 0, c = 0, g = 0;
    }
    // closing file
    din.close();
    myFile.close();
    cout << "\t\t\tPress Any Key To Continue... ";
    getch();
    AdminOptions();
}

void SearchResult() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    vector<string> names;
    vector<string> ids;
    vector<string> cgpas;
    string s, id;
    cout << "\t\t\tEnter Your Student ID: ";
    cin >> id;
    ifstream rin("result.dat");
    while (getline(rin, s)) {
        names.push_back(s);
        getline(rin, s);
        ids.push_back(s);
        getline(rin, s);
        cgpas.push_back(s);
    }
    int idx = -1;
    for (int i = 0; i < (int)ids.size(); i++) {
        if (ids[i] == id) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "\t\t\tResult Not Found" << endl;
        cout << "\t\t\tPress Any Key To Continue... ";
        getch();
        SearchResult();
    } else {
        cout << "\n\t\t\tName: " << names[idx] << endl;
        cout << "\t\t\tID: " << ids[idx] << endl;
        cout << "\t\t\tCGPA: " << cgpas[idx] << endl;
        cout << "\n\n";
        cout << "\t\t\tPress Any Key To Continue...";
        getch();
        UserOption();
    }
    rin.close();
}
void ReportGenerate() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    vector<string> names;
    vector<string> ids;
    vector<string> cgpas;

    ifstream rin("result.dat");
    string s;
    while (getline(rin, s)) {
        getline(rin, s);
        ids.push_back(s);
        getline(rin, s);
        cgpas.push_back(s);
    }
    rin.close();

    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";

    string x;
    ifstream fin("data.dat");
    ifstream fin2("coursedata.dat");
    int pos = 0;
    while(getline(fin, x)) {
        string n, id;
        int i = 0;
        for (i = 0; i < (int)x.size(); i++) {
            if (isdigit(x[i])) {
                break;
            } else
                n.push_back(x[i]);
        }
        id = x.substr(i, (int)x.size());

        cout << "\t\t\tName: " <<n<<"\n";
        cout << "\t\t\tID: "<<id<<"\n\n";
        cout << "\t\t\tCourse Title:\t\tObtained Marks:\t\tObtained Grade\n";
        cout << "\t\t\t------------------------------------------------------------------------------\n";
        string temp, title;
        for(int i = 0; i < 8; i++) {
            getline(fin, temp);
            getline(fin2, title);
            string mk;
            for(int i = temp.size()-1; i >= 0; i--) {
                if(temp[i] == ' ') break;
                else mk += temp[i];
            }
            reverse(mk.begin(), mk.end());
            double mark = stod(mk);
            string grade = GradeLetter(mark);
            if(i == 1) {
                cout << "\t\t\t"<<title<<"\t\t"<<mark<<"\t\t\t"<<grade<<"\n";
            } else if(i == 5) {
                cout << "\t\t\t"<<title<<"\t\t\t\t"<<mark<<"\t\t\t"<<grade<<"\n";
            } else if(i == 6) {
                cout << "\t\t\t"<<title<<"\t\t"<<mark<<"\t\t\t"<<grade<<"\n";
            } else
                cout << "\t\t\t"<<title<<"\t\t\t"<<mark<<"\t\t\t"<<grade<<"\n";
        }
        cout << "\t\t\t------------------------------------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t\tCGPA = "<<cgpas[pos++]<<"\n\n";
    }
    fin.close();
    getch();
    AdminOptions();
}
void ReportGenerateS() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    vector<string> cgpas;
    vector<string> ids;
    string name, s, id;
    cout << "\t\t\tEnter Your Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\t\tEnter Your Student ID: ";
    cin >> id;
    ifstream rin("result.dat");

    string sname, sid;
    double cg;

    while (getline(rin, s)) {
        getline(rin, s);
        ids.push_back(s);
        getline(rin, s);
        cgpas.push_back(s);
    }
    rin.close();
    int idx = -1;
    for (int i = 0; i < (int)ids.size(); i++) {
        if (ids[i] == id) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "\t\t\tID Not Found" << endl;
        cout << "\t\t\tPress Any Key To Continue... ";
        getch();
        ReportGenerate();
    } else {
        sname = name +" "+ id;
        cg = stod(cgpas[idx]);
        system("CLS");
        cout << "\t\t\t______________________________________________________________\n";
        cout << "\t\t\t\t\t\tResult Management System\n";
        cout << "\t\t\t______________________________________________________________\n\n";
        cout << "\t\t\tName: " <<name<<"\n";
        cout << "\t\t\tID: "<<id<<"\n\n";
        cout << "\t\t\tCourse Title:\t\tObtained Marks:\t\tObtained Grade\n";
        cout << "\t\t\t------------------------------------------------------------------------------\n";
        string x;
        ifstream fin("data.dat");
        ifstream fin2("coursedata.dat");
        while(getline(fin, x)) {

            string temp, title;
            if(x == sname) {
                for(int i = 0; i < 8; i++) {
                    getline(fin, temp);
                    getline(fin2, title);
                    string mk;
                    for(int i = temp.size()-1; i >= 0; i--) {
                        if(temp[i] == ' ') break;
                        else mk += temp[i];
                    }
                    reverse(mk.begin(), mk.end());
                    double mark = stod(mk);
                    string grade = GradeLetter(mark);
                    if(i == 1) {
                        cout<<"\t\t\t"<<title<<"\t\t"<<mark<<"\t\t\t"<<grade<<"\n";
                    } else if(i == 5) {
                        cout<<"\t\t\t"<<title<<"\t\t\t\t"<<mark<<"\t\t\t"<<grade<<"\n";
                    } else if(i == 6) {
                        cout<<"\t\t\t"<<title<<"\t\t"<<mark<<"\t\t\t"<<grade<<"\n";
                    } else cout<<"\t\t\t"<<title<<"\t\t\t"<<mark<<"\t\t\t"<<grade<<"\n";
                }
            }
        }
        cout<<"\t\t\t------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\tCGPA = "<<cg<<endl;
        fin.close();
        cout << "\t\t\tPress Any Key To Continue...";
        getch();
        UserOption();
    }
}
void PrintAllResult() {
    system("CLS");
    cout << "\t\t\t______________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";
    vector<string> names;
    vector<string> ids;
    vector<string> cgpas;
    string s, id;
    ifstream cin("result.dat");
    while (getline(cin, s)) {
        names.push_back(s);
        getline(cin, s);
        ids.push_back(s);
        getline(cin, s);
        cgpas.push_back(s);
    }
    for (int i = 0; i < (int)names.size(); i++) {
        cout << "\n\t\t\tName: " << names[i] << endl;
        cout << "\t\t\tID: " << ids[i] << endl;
        cout << "\t\t\tCGPA: " << cgpas[i] << endl;
        cout << "\n" << endl;
    }
    cout << "\t\t\tPress Any Key To Continue...";
    getch();
    AdminOptions();
}
void Stats() {
    system("CLS");
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t______________________________________________________________\n\n";

    vector<string> names;
    vector<string> ids;
    vector<string> cgpas;
    string s, id;
    ifstream rin("result.dat");
    int cnt4 = 0, cnt3 = 0, totalpassed = 0, totalfailed = 0, totalstudents = 0;
    while (getline(rin, s)) {
        names.push_back(s);
        getline(rin, s);
        ids.push_back(s);
        getline(rin, s);
        cgpas.push_back(s);
    }
    rin.close();
    for (int i = 0; i < (int)cgpas.size(); i++) {
        if (stod(cgpas[i]) == 4.0) cnt4++;
        if (stod(cgpas[i]) >= 3.5) cnt3++;
        if (stod(cgpas[i]) == 0.0) totalfailed++;
    }
    totalstudents = (int)names.size();
    totalpassed = totalstudents - totalfailed;
    double passingRate = (totalpassed / (double)totalstudents) * 100.0;
    cout << "\t\t\tPassing Rate = " << passingRate << " %" << endl;
    cout << "\t\t\tNumber of Students Got A+ = " << cnt4 << endl;
    cout << "\t\t\tNumber of Students above A- = " << cnt3 << endl;
    cout << "\t\t\tNumber of Students failed = " << totalfailed << endl;
    cout << "\n\n\n\t\t\tPress Any Key To Continue...";
    getch();
    AdminOptions();
}

void SelfExit() {
    system("CLS");
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t\tResult Management System\n";
    cout << "\t\t\t_____________________________________________________________\n\n";
    cout << "\t\t\t\t\t\tThank You For Using\n\n\n\n\n" << endl;
    exit(0);
}