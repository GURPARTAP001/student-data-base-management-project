#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

void addData();
void viewData();
void mainMenu();

void deleteData();
void adminVerification();
void studentFunction();

void adminFunction()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t | LOGGED IN AS ADMIN |\n";
    cout << "\n\n\t\t\t\t\t 1. ADD STUDENT DETAILS";
    cout << "\n\n\t\t\t\t\t 2. DELETE STUDENTS";
    //cout << "\n\n\t\t\t\t\t 3. update Record";
    cout << "\n\n\t\t\t\t\t 4. VIEW TABLE ";
    cout << "\n\n\t\t\t\t\t 5. MAIN MENU ";
    cout << "\n\n\t\t\t\t\t 6. EXIT";

    int option;
    cout << "\n\n\t\t\t\t\tENTER CHOICE : ";
    do
    {
        cin >> option;

        {
            switch (option)
            {

            case 1:
                addData();
                break;

            case 2:
                deleteData();
                break;

            case 3:
                cout << "THIS OPTION NOT AVAILABLE"; //updateData();
                break;

            case 4:
                viewData();
                break;

            case 5:
                mainMenu();
                break;

            case 6:
                system("cls");
                cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQUITING THE PROGRAM";

                for (int i = 0; i < 4; i++)
                {

                    Sleep(1000);
                    cout << ".";
                }
                exit(0);
                break;

            default:
                system("cls");
                cout << "\n\n\t\t\t\t\t LOGGED IN AS ADMIN";
                cout << "\n\n\t\t\t\t\t 1. ADD STUDENTS RECORD";
                cout << "\n\n\t\t\t\t\t 2. DELETE RECORDS";
                //  cout << "\n\n\t\t\t\t\t 3. update Record";
                cout << "\n\n\t\t\t\t\t 4. VIEW TABLE ";
                cout << "\n\n\t\t\t\t\t 5. MAIN MENU ";
                cout << "\n\n\t\t\t\t\t 6. EXIT";

                cout << "\n\n\t\t\t\t\t INVALID INPUT!";

                cout << "\n\n\t\t\t\t\t ENTER CHOICE : ";
            }
        }

    } while (option != '6');
}

void mainMenu()
{
    system("cls");

    cout << "\n\n\n\n\t\t\t\t\t LOGIN AS : ";
    cout << "\n\n\n\t\t\t\t\t 1. ADMIN ";
    cout << "\n\n\t\t\t\t\t 2. STUDENT";
    cout << "\n\n\t\t\t\t\t 3. EXIT";
    cout << "\n\n\n\t\t\t\t\t ENTER YOUR CHOICE : ";

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        adminVerification();
        break;

    case 2:
        system("cls");

        cout << "WELCOME AS STUDENT";
        studentFunction();
        break;

    case 3:
        system("cls");
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQUITTING THE PROGRAM";

        for (int i = 0; i < 4; i++)
        {

            Sleep(1000);
            cout << ".";
        }

        exit(0);
        break;

    default:
        cout << "INVALID INPUT";
    }

    system("pause");
}

// all Functions for Admin below

void deleteData()
{
    system("cls");

    // Open FIle pointers
    fstream fin, fout;

    // Open the existing file
    fin.open("data.csv", ios::in);

    // Create a new file to store the non-deleted data
    fout.open("datanew.csv", ios::out);

    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    // Get the roll number
    // to decide the data to be deleted
    cout << "ENTER THE ROLL NUMBER "
         << "OF THE RECORD TO BE DELETED: ";
    cin >> rollnum;

    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        roll1 = stoi(row[0]);

        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (roll1 != rollnum)
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "RECORD DELETED\n";
    else
        cout << "RECORD NOT FOUND\n";

    // Close the pointers
    fin.close();
    fout.close();

    // removing the existing file
    remove("data.csv");

    // renaming the new file with the existing file name
    rename("datanew.csv", "data.csv");

    Sleep(2000);

    adminFunction();
}


void addData()
{
    system("cls");
    fstream file("data.csv", ios::out | ios::app);
    if (!file)
    {
        cout << "\nFAIL TO OPEN DATA.CSV FILE!";
    }

    else
        cout << "\t|ENTER DATA|" << endl
             << endl;

    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    string moreData;

    cout << "\nENTER STUDENTS ROLL NUMBER : ";
    cin >> rollNumber;
    file << "\n"
         << rollNumber << ", ";

    cout << "\nENTER STUDENTS NAME : ";
    cin >> name;
    file << name << ", ";

    cout << "\nENTER COLLEGE NAME : ";
    cin >> college;
    file << college << ", ";

    cout << "\nENTER BRANCH : ";
    cin >> branch;
    file << branch << ", ";

    cout << "\nEnter Attendance : ";
    cin >> attendance;
    file << attendance << ", ";

    cout << "\nENTER PHYSICS MARKS : ";
    cin >> physics;
    file << physics << ", ";

    cout << "\nENTER CHEMISTRY MARKS : ";
    cin >> chemistry;
    file << chemistry << ", ";

    cout << "\nENTER MATHS MARKS : ";
    cin >> maths;
    file << maths;

    file.close();

    cout << "\nADD MORE RECORDS? (Y / N) : ";

    cin >> moreData;
    if (moreData == "y" || moreData == "Y" || moreData == "yes" || moreData == "Yes")
    {
        addData();
    }
    else if (moreData == "n" || moreData == "N" || moreData == "no" || moreData == "No")
        adminFunction();

    else
        cout << "\nENTER A VALID OPTION";

    adminFunction();
}

void viewData()
{
    system("cls");

    fstream file("data.csv");

    if (!file)
    {
        cout << "FAIL IN OPENING THE FILE";
    }
    cout << "\n\t\t\t\t\t\t|STUDENTS RECORDS| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "ROLL \t NAME \t\t\t COLLEGE \t BRANCH \t ATTENDENCE \t PHYSICS \t CHEMISTRY \t MATHS" << endl
         << endl;
    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

    while (!file.eof()) // file.eof() = detects as how long the f
    {
        getline(file, rollNumber, ',');
        getline(file, name, ',');
        getline(file, college, ',');
        getline(file, branch, ',');
        getline(file, attendance, ',');
        getline(file, physics, ',');
        getline(file, chemistry, ',');
        getline(file, maths, '\n');

        cout << rollNumber << " \t " << name << "\t\t\t" << college << " \t\t" << branch << " \t\t" << attendance << " \t\t" << physics << " \t\t" << chemistry << " \t\t" << maths << endl;
        cout << endl;
    }

    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
    file.close();

    cout << "\n\n 1. ADD RECORD\n";
    cout << " 2. DELETE RECORD\n";
    cout << " 3. UPDATE RECORD\n";
    cout << " 5. MAIN MENU\n";
    cout << " 6. EXIT\n";
    cout << "\nENTER CHOICE : ";
    // adminFunction();
}

void adminVerification()
{
    system("cls");

    string password;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tENTER PASSWORD : ";

    do
    {
        cin >> password;

        if (password != "password")
        {
            system("cls");
            cout << "\n\n\n\n\n\t\t"
                 << "WRONG PASSWORD!, TRY AGAIN OR TYPE 'menu' TO GO TO THE MAIN MENU";
            cout << "\n\n\n\t\t\t\t\tENTER PASSWORD : ";
        }

        if (password == "Menu" || password == "menu" || password == "MENU")
        {
            mainMenu();
        }

    }

    while (password != "password");
    adminFunction(); // main menu function is in the Header File adminFunction.h
}

void studentFunction()
{


    system("cls");

    fstream file("data.csv");

    if (!file)
    {
        cout << "FAIL TO OPEN THE FILE";
    }
    cout << "\n\t\t\t\t\t\t|STUDENT RECORD| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "ROLL \t NAME \t\t\t COLLEGE \t BRANCH \t ATTENDENCE \t PHYSICS \t CHEMISTRY \t MATHS" << endl
         << endl;
    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

    while (!file.eof()) // file.eof() = detects as how long the f
    {
        getline(file, rollNumber, ',');
        getline(file, name, ',');
        getline(file, college, ',');
        getline(file, branch, ',');
        getline(file, attendance, ',');
        getline(file, physics, ',');
        getline(file, chemistry, ',');
        getline(file, maths, '\n');

        cout << rollNumber << " \t " << name << "\t\t\t" << college << " \t\t" << branch << " \t\t" << attendance << " \t\t" << physics << " \t\t" << chemistry << " \t\t" << maths << endl;
        cout << endl;
    }

    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
    file.close();
    system("pause");
    mainMenu();}