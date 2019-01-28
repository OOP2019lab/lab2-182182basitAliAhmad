#include<iostream>
#include<fstream>
#include "githubusers.h"

void readDataFromFile(gitHubUser* &users, int &size, string filepath) // reading data from file
{
	 ifstream fin;
	 fin.open(filepath);
	 if(fin) // check if file is opened
	 {
		 fin >> size;
		 users = new gitHubUser[size];
		 for (int i = 0; i < size; i++)
		 {
			 fin >> users[i].firstName;
			 fin >> users[i].userName;
			 fin >> users[i].email;
			 fin >> users[i].folderCount;
			 users[i].gitHubFolders = new string[users[i].folderCount];
			 fin.ignore();
			 for (int j = 0; j < users[i].folderCount; j++)
				 getline(fin,users[i].gitHubFolders[j]);
		 }
		 fin.close();
	 }
	 else
		 cout << "File not found!" << endl;
}

void print(const gitHubUser var) // printing indivisual object
{
		cout << "Name :     " << var.firstName << endl;
		cout << "Username : " << var.userName << endl;
		cout << "Email :    " << var.email << endl;
		cout << "No. of folders : " << var.folderCount << endl;
		for (int j = 0; j < var.folderCount; j++)
			cout << var.gitHubFolders[j] << endl;
		cout << endl;
}

void printing(const gitHubUser* arr, const int size) // printing array of object
{
	for (int i = 0; i < size; i++)
	{
		cout << "USER # " << i + 1 << endl;
		print(arr[i]);
	}
}

void main()
{
	gitHubUser* arr = nullptr;
	int size = 0;

	readDataFromFile(arr,size,"input.txt");
	printing(arr,size);

	for (int i = 0; i < size; i++)
	{
		delete[]arr[i].gitHubFolders;
		arr[i].gitHubFolders = nullptr;
	}
	delete[]arr;
	arr = nullptr;
}

