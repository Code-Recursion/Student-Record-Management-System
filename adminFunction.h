#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
#include <string>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

void addData(void);
void viewData(void);
void mainMenu(void);
//void updateData(void);
void deleteData(void);
void adminVerification(void);
void studentFunction(void);

void adminFunction()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t | Logged In as Admin |\n";
    cout << "\n\n\t\t\t\t\t 1. Add Students Detail";
    cout << "\n\n\t\t\t\t\t 2. Delete Students";
    //cout << "\n\n\t\t\t\t\t 3. update Record";
    cout << "\n\n\t\t\t\t\t 4. View Table ";
    cout << "\n\n\t\t\t\t\t 5. Main Menu ";
    cout << "\n\n\t\t\t\t\t 6. Exit";

    int option;
    cout << "\n\n\t\t\t\t\tEnter choice : ";
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
                cout << "this option is not available"; //updateData();
                break;

            case 4:
                viewData();
                break;

            case 5:
                mainMenu();
                break;

            case 6:
                system("cls");
                cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

                for (int i = 0; i < 4; i++)
                {

                    Sleep(1000);
                    cout << ".";
                }
                exit(0);
                break;

            default:
                system("cls");
                cout << "\n\n\t\t\t\t\t Logged In as Admin";
                cout << "\n\n\t\t\t\t\t 1. Add Students Record";
                cout << "\n\n\t\t\t\t\t 2. Delete Record";
                //  cout << "\n\n\t\t\t\t\t 3. update Record";
                cout << "\n\n\t\t\t\t\t 4. View Table ";
                cout << "\n\n\t\t\t\t\t 5. Main Menu ";
                cout << "\n\n\t\t\t\t\t 6. Exit";

                cout << "\n\n\t\t\t\t\t invalid input!";

                cout << "\n\n\t\t\t\t\t Enter choice : ";
            }
        }

    } while (option != '6');
}

void mainMenu()
{
    system("cls");

    cout << "\n\n\n\n\t\t\t\t\t Login As : ";
    cout << "\n\n\n\t\t\t\t\t 1. Admin ";
    cout << "\n\n\t\t\t\t\t 2. Student";
    cout << "\n\n\t\t\t\t\t 3. Exit";
    cout << "\n\n\n\t\t\t\t\t Enter your choice : ";

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        adminVerification();
        break;

    case 2:
        system("cls");

        cout << "Welcom as Student";
        studentFunction();
        break;

    case 3:
        system("cls");
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

        for (int i = 0; i < 4; i++)
        {

            Sleep(1000);
            cout << ".";
        }

        exit(0);
        break;

    default:
        cout << "invalid input";
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
    cout << "Enter the roll number "
         << "of the record to be deleted: ";
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
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";

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

/*
void updateData()
{
    system("cls");
    cout << "in update function\n";
        // File pointer
        fstream fin, fout;

        // Open an existing record
        fin.open("data.csv", ios::in);

        // Create a new file to store updated data
        fout.open("datanew.csv", ios::out);

        int rollnum, roll1, marks, count = 0, i;
        char sub;
        int index;
        string new_marks;
        string line, word;
        vector<string> row;

        // Get the roll number from the user
        cout << "Enter the roll number "
             << "of the record to be updated: ";
        cin >> rollnum;

        // Get the data to be updated
        cout << "Enter the first letter fo the Fields (Eg. b for branch & G for college)"
             << "to be updated(N/G/B/A/P/C/M): ";
        cin >> sub;

        // Determine the index of the subject
        // where Maths has index 7,
        // Physics has index 6, and so on

        if (sub == 'n' || 'N')
            index = 1;

        else if (sub == 'g' || sub == 'G')
            index = 2;

        else if (sub == 'b' || sub == 'B')
            index = 3;

        else if (sub == 'a' || sub == 'A')
            index = 4;

        else if (sub == 'p' || sub == 'P')
            index = 5;

        else if (sub == 'c' || sub == 'C')
            index = 6;

        else if (sub == 'm' || sub == 'M')
            index = 7;

        else
        {
            cout << "Wrong choice.Enter again\n";
            updateData();
        }

        // Get the new marks
        cout << "Enter new Detail: ";
        cin >> new_marks;

        // Traverse the file
        while (!fin.eof())
        {

            row.clear();

            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            roll1 = stoi(row[0]);
            int row_size = row.size();

            if (roll1 == rollnum)
            {
                count = 1;
                stringstream convert;

                // sending a number as a stream into output string
                convert << new_marks;

                // the str() converts number into string
                row[index] = convert.str();

                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        // write the updated data
                        // into a new file 'reportcardnew.csv'
                        // using fout
                        fout << row[i] << ", ";
                    }

                    fout << row[row_size - 1] << "\n";
                }
            }
            else
            {
                if (!fin.eof())
                {
                    for (i = 0; i < row_size - 1; i++)
                    {

                        // writing other existing records
                        // into the new file using fout.
                        fout << row[i] << ", ";
                    }

                    // the last column data ends with a '\n'
                    fout << row[row_size - 1] << "\n";
                }
            }
            if (fin.eof())
                break;
        }
        if (count == 0)
            cout << "Record not found\n";

        fin.close();
        fout.close();

        // removing the existing file
        remove("data.csv");

        // renaming the updated file with the existing file name
        rename("datadnew.csv", "data.csv");
    
}

*/
void addData()
{
    system("cls");
    fstream file("data.csv", ios::out | ios::app);
    if (!file)
    {
        cout << "\nFailed to open data.csv / data.csv file not found!";
    }

    else
        cout << "\t|Enter Data|" << endl
             << endl;

    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    string moreData;

    cout << "\nEnter Student's roll Number : ";
    cin >> rollNumber;
    file << "\n"
         << rollNumber << ", ";

    cout << "\nEnter Studnet's Name : ";
    cin >> name;
    file << name << ", ";

    cout << "\nEnter College : ";
    cin >> college;
    file << college << ", ";

    cout << "\nEnter Branch : ";
    cin >> branch;
    file << branch << ", ";

    cout << "\nEnter Attendance : ";
    cin >> attendance;
    file << attendance << ", ";

    cout << "\nEnter Physic's Marks : ";
    cin >> physics;
    file << physics << ", ";

    cout << "\nEnter Chemistry Marks : ";
    cin >> chemistry;
    file << chemistry << ", ";

    cout << "\nEnter Maths Marks : ";
    cin >> maths;
    file << maths;

    file.close();

    cout << "\nAdd more Record? (Y / N) : ";

    cin >> moreData;
    if (moreData == "y" || moreData == "Y" || moreData == "yes" || moreData == "Yes")
    {
        addData();
    }
    else if (moreData == "n" || moreData == "N" || moreData == "no" || moreData == "No")
        adminFunction();

    else
        cout << "\nEnter a valid option";

    adminFunction();
}

void viewData()
{
    system("cls");

    fstream file("data.csv");

    if (!file)
    {
        cout << "fail in opening the file";
    }
    cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
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

    cout << "\n\n 1. Add Record\n";
    cout << " 2. Delete Record\n";
    cout << " 3. Update Record\n";
    cout << " 5. Main Menu\n";
    cout << " 6. Exit\n";
    cout << "\nEnter choice : ";
    // adminFunction();
}

void adminVerification()
{
    system("cls");

    string password;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tEnter Password : ";

    do
    {
        cin >> password;

        if (password != "password")
        {
            system("cls");
            cout << "\n\n\n\n\n\t\t"
                 << "wrong password!, try again or type 'menu' to Navigate to Main Menu";
            cout << "\n\n\n\t\t\t\t\tEnter Password : ";
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
        cout << "fail in opening the file";
    }
    cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
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
    mainMenu();
}
