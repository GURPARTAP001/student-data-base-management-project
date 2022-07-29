#include<iostream>
#include<windows.h>

using namespace std;

void loadingBar()
{
	system("cls");
	system("color 9F");
	
	char a = 177, b = 219;
	cout<<"\n\n\n\n\n\t\t\t\t\tSTUDENT DATA BASE MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t\tDEVELOPED BY ACE OF CODING";
	cout<<"\n\n\n\t\t\t\t\tLOADING...\n";
	cout<<endl;
	cout<<"\t\t\t\t\t";
	
	for(int i = 0;i<26;i++)

	cout<<a;

	cout<<"\r";
	cout<<"\t\t\t\t\t";
	for(int i = 0; i < 26 ; i++)
	{
		cout<<b;
		Sleep(200);
	}
	
}
