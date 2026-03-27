#ifndef USERS_H
#define USERS_H

#include "Global.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include<vector>

enum enMainMenuePermissions
{
    eAll = -1,
    pListClients = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClients = 8,
    pFindClient = 16,
    pTransactions = 32,
    pManageUsers = 64
};


string Read_User_Name();
string Read_Password();


vector<string> SplitString(string s,string Delim);
vector<stUser> LoadUsersDataFromFile(string fileName);

void Find_User(vector<stUser> & vUsers );
void Delete_User(vector<stUser> & vUsers);
void Show_List_Users(vector<stUser> & vClient);
void login();
void Add_New_User(vector<stUser>& vUsers);
void SaveUsersDataToFile(string fileName, vector<stUser> & vUsers);
void Update_User_info(vector<stUser> & vUsers);
void ManageUsersMenu();
void GoBackToMainMenu();
void ShowAccessDeniedMessage();

bool Check_User_Name_And_Password(vector<stUser> & vUser);
bool CheckAccessPermission(enMainMenuePermissions Permission);

int ReadPermissionsToSet();
stUser ConvertLineToUser(string line, string separator);


#endif
