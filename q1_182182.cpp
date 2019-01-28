#include<iostream>
#include "githubuser.h"

bool Comparison(gitHubUser var1, gitHubUser var2) // simply compares two gitHubUser object after taking inputs.
{
		cout << "USER # 1" << endl;
		cout << "First Name ---- > ";
		cin >> var1.firstName;

		cout << "Username ----> ";
		cin >> var1.userName;
		
		cout << "Password ---- >";
		cin >> var1.password;

		cout << "Email ----> ";
		cin >> var1.email;

		cout << "Enter number of folfers ----> ";
		cin >> var1.folderCount;

		cout << "USER # 2" << endl;
		cout << "First Name ---- > ";
		cin >> var2.firstName;

		cout << "Username ----> ";
		cin >> var2.userName;
		
		cout << "Password ---- >";
		cin >> var2.password;

		cout << "Email ----> ";
		cin >> var2.email;

		cout << "Enter number of folfers ----> ";
		cin >> var2.folderCount;

	if (var1.userName == var2.userName || var1.email == var2.email) // Only these two attributes needs to distinguih from each other. Other attributes may be same but they dont matter.
		return true;
	return false;
}

bool exists(gitHubUser* arr, const int size, const string userName) // Check if username already exists or not
{
	for (int i = 0; i < size; i++)
	{
		if(arr[i].userName == userName)
			return true;
	}
	return false;

}

void inputFromUser(gitHubUser* &arr, int &size) // creates a dynamic array of size input by user and then populating the array from user
{
	cout << "Enter number of users ---- > ";
	cin >> size;
	arr = new gitHubUser[size];

	for (int i = 0; i < size; i++)
	{
		cout << "USER # " << i + 1 << endl;
		cout << "First Name ---- > ";
		cin >> arr[i].firstName;

		cout << "Username ----> ";
		cin >> arr[i].userName;

		while (exists(arr,i,arr[i].userName)) // checking if username already exists
		{
			cout << "This userName already exists, enter another userName ----> ";
			cin >> arr[i].userName;
		}
		
		cout << "Password ---- >";
		cin >> arr[i].password;

		cout << "Email ----> ";
		cin >> arr[i].email;

		cout << "Enter number of folfers ----> ";
		cin >> arr[i].folderCount;
	}
}

void print(const gitHubUser var) // printing a single object
{
		cout << "Name :     " << var.firstName << endl;
		cout << "Username : " << var.userName << endl;
		cout << "Password : " << var.password << endl; 
		cout << "Email :    " << var.email << endl;
		cout << "No. of folders : " << var.folderCount << endl << endl;
}

void printing(const gitHubUser* arr, const int size) // printing whole array of objects
{
	for (int i = 0; i < size; i++)
	{
		cout << "USER # " << i + 1 << endl;
		print(arr[i]);
	}
}

gitHubUser*	searchUser(gitHubUser* users,const int size, const string userName) // searchs a user based on its username and returns the address of found object
{
	for (int i = 0; i < size; i++)
	{
		if (users[i].userName == userName)
			return (users+i);
	}
	return nullptr;
}

void main()
{
	bool flag = false;
	cout << "Enter 0 to run comparison program" << endl;
	cin >> flag;
	if (flag)
	{
		gitHubUser* ptr = nullptr;
		int size = 0;
		string username;
		inputFromUser(ptr,size);

		printing(ptr,size);

		cout << "Enter username to search ---- > ";
		cin >> username;

		gitHubUser* var = searchUser(ptr,size,username);
		if (var != nullptr) 
			print(*var);
		else
			cout << "User not found!" << endl;
		delete[]ptr;
		ptr = nullptr;
	}
	else // comparison program
	{
		gitHubUser user1, user2;
		if (Comparison(user1,user2))
			cout << "Users are same" << endl;
		else
			cout << "Users are different" << endl;
	}
}

