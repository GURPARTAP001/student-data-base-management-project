#include <iostream>
#include "loading.h"
#include <string>
#include <Windows.h>
#include "adminFunction.h"

using namespace std;

void passwordVerification();
void mainMenu();
void addData();
void viewData();


void deleteData();
void adminVerification();
void studentFunction();

//Auth Before opening the main program

void passwordVerification()
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
                 << "WRONG PASSWORD!, TRY AGAIN OR TYPE 'quit' / 'exit' TO QUIT THE PROGRAM.";
            cout << "\n\n\n\t\t\t\t\tEnter Password : ";
        }

        if (password == "Quit" || password == "quit" || password == "exit" || password == "Exit" || password == "QUIT" || password == "EXIT")
        {
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tLEAVING THE PROGRAM";

            for (int i = 0; i < 4; i++)
            {

                Sleep(1000); // 1 second pause;
                cout << ".";
            }

            exit(0);
        }

    }

    while (password != "password");
    mainMenu(); // main menu function is in the Header File adminFunction.h
}

int main()
{

    loadingBar(); // loadingBar() is in the loading.h header for loading animation.
   system("color 9F");

    passwordVerification();
    return 0;
}