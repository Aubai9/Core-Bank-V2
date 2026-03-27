#include "Users.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<cstdlib>
#include<fstream>

extern stUser CurrentUser;

const string UsersFileName = "user.txt";

void GoBackToMainMenu();

void DrawHeader(string name);

string Read_User_Name()
{
    string username;
    cout<<"Enter User Name: ";
    cin>>username;
    return username;
}

string Read_Password()
{
    string password;
    cout<<"Enter Password: ";
    cin>> password;
    return password;
}



vector<string> SplitString(string s, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    while((pos = s.find(Delim)) != std::string::npos)
        {
            sWord = s.substr(0,pos);
            if(sWord != "")
                {
                    vString.push_back(sWord);
                }
            s.erase(0, pos + Delim.length());
        }


    if(s != "")
        {
            vString.push_back(s);
        }

    return vString;
}

vector<stUser> LoadUsersDataFromFile(string fileName)
{
    vector<stUser> vUser;
    fstream myFile;
    myFile.open(fileName, ios::in);
    if(myFile.is_open())
        {
            string line;
            stUser user;
            while(getline(myFile,line))
                {
                    if(line.empty())
                        continue;
                    stUser user = ConvertLineToUser(line, "#//#");
                    vUser.push_back(user);
                }
            myFile.close();
        }
    return vUser;
}


bool FindUserAndPassword(string Username, string Password, stUser &User)
{
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    for (stUser &u : vUsers)
        {
            if (u.UserName == Username && u.Password == Password)
                {
                    User = u;
                    return true;
                }
        }
    return false;
}

void login()
{
    bool LoginFailed = false;
    string Username, Password;

    do
        {
            system("cls");
            DrawHeader("Login Screen");

            if (LoginFailed)
                {
                    cout << "Invalid Username/Password!\n";
                }

            cout << "Enter Username? ";
            cin >> Username;
            cout << "Enter Password? ";
            cin >> Password;

            LoginFailed = !FindUserAndPassword(Username, Password, CurrentUser);

        }
    while (LoginFailed);

}

void Show_List_Users(vector<stUser> & vUsers)
{
    system("cls");
    if(vUsers.size() == 0)
        {
            cout << "----------------------- No Clients to show -----------------------\n";
            GoBackToMainMenu();
        }
    else
        {
            cout << "\n\t\t\tClient List (" << vUsers.size() << ") Client(s).\n";
            cout << "_________________________________________________________________\n\n";


            cout << "| " << left << setw(15) << "User Name"
                 << "| " << left << setw(10) << "Password"
                 << "| " << left << setw(20) << "Permissions" << endl;

            cout << "_________________________________________________________________\n\n";

            for(int i = 0 ; i < vUsers.size(); i++)
                {

                    cout << "| " << left << setw(15) << vUsers[i].UserName
                         << "| " << left << setw(10) << vUsers[i].Password
                         << "| " << left << setw(20) << vUsers[i].Permissions << endl;
                }
            cout << "_________________________________________________________________\n";
        }
    GoBackToMainMenu();
}


void Add_New_User(vector<stUser>& vUsers)
{
    stUser tempUser;
    bool exist = false;

    DrawHeader("Add new User Screen");
    cout << "Adding new user:\n";

    do
        {
            exist = false;
            cout << "Enter User Name ? ";
            cin >> tempUser.UserName;

            for(int i = 0; i < vUsers.size(); i++)
                {
                    if(vUsers[i].UserName == tempUser.UserName)
                        {
                            cout << "User with [" << tempUser.UserName << "] already exist\n";
                            exist = true;
                            break;
                        }
                }
        }
    while(exist == true);

    cout << "Enter Password? ";
    cin >> tempUser.Password;

    tempUser.Permissions = ReadPermissionsToSet();

    vUsers.push_back(tempUser);


    SaveUsersDataToFile(UsersFileName,  vUsers);

    cout << "User added successfully!\n";
    GoBackToMainMenu();
}

int ReadPermissionsToSet()
{
    int permissions = 0;
    char answer = 'n';

    cout << "\nDo you want to give full access? y/n? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
        return -1;

    cout << "\nDo you want to give access to :\n\n";

    cout << "Show Client List? y/n ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y') permissions += 1;

    cout << "Add New Client? y/n ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y') permissions += 2;

    cout << "Delete Client? y/n ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y') permissions += 4;

    cout << "Update Client? y/n ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y') permissions += 8;

    cout << "Find Client? y/n ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y') permissions += 16;

    cout << "Transactions? y/n ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y') permissions += 32;

    cout << "Manage Users? y/n ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y') permissions += 64;

    return permissions;
}

stUser ConvertLineToUser(string line, string separator = "#//#")
{
    stUser user;
    vector<string> vUserData = SplitString(line, separator);
    if (vUserData.size() >= 3)
        {
            user.UserName = vUserData[0];
            user.Password = vUserData[1];
            user.Permissions = stoi(vUserData[2]);
        }
    return user;
}


string ConvertUserToLine(stUser User, string separator)
{
    string stUserRecord = "";
    stUserRecord += User.UserName + separator;
    stUserRecord += User.Password + separator;
    stUserRecord += to_string(User.Permissions);
    return stUserRecord;
}

void SaveUsersDataToFile(string FileName, vector<stUser>  &vUsers)
{
    fstream myFile;
    myFile.open(FileName, ios::out);

    if(myFile.is_open())
        {
            string DataLine;
            for(stUser & user : vUsers)
                {
                    DataLine = ConvertUserToLine(user, "#//#");
                    myFile << DataLine << endl;
                }
            myFile.close();
        }
}


void Find_User(vector<stUser> & vUsers )
{
    string User_Name;
    cout << "Enter User Name to Find it: ";
    cin >> User_Name;
    bool found = false;
    for(int i = 0; i < vUsers.size(); i++)
        {
            if(vUsers[i].UserName == User_Name)
                {
                    cout << "__________________\n\n";
                    cout << "Account Details:\n";

                    cout << "_________________________________________________________________\n\n";


                    cout << "| " << left << setw(15) << "User Name"
                         << "| " << left << setw(10) << "Password"
                         << "| " << left << setw(20) << "Permissions" << endl;

                    cout << "_________________________________________________________________\n\n";




                    cout << "| " << left << setw(15) << vUsers[i].UserName
                         << "| " << left << setw(10) << vUsers[i].Password
                         << "| " << left << setw(20) << vUsers[i].Permissions << endl;

                    cout << "_________________________________________________________________\n";
                    found = true;
                    break;
                }

        }

    if(!found)
        {
            cout << "Account not found!\n";
        }
    GoBackToMainMenu();
}

void Delete_User(vector<stUser> & vUsers)
{
    string User_Name;
    cout << "Enter User Name to delete it: ";
    cin >> User_Name;

    bool found = false;
    int index = -1;


    for(int i = 0 ; i < vUsers.size(); i++)
        {
            if(vUsers[i].UserName == User_Name)
                {
                    found = true;
                    index = i;
                    break;
                }
        }


    if(found)
        {
            cout << "__________________\n\n";
            cout << "Account Details:\n";

            cout << "| " << left << setw(15) << "User Name"
                 << "| " << left << setw(10) << "Password"
                 << "| " << left << setw(20) << "Permissions" << endl;


            cout << "| " << left << setw(15) << vUsers[index].UserName
                 << "| " << left << setw(10) << vUsers[index].Password
                 << "| " << left << setw(20) << vUsers[index].Permissions << endl;

            cout << "__________________\n";

            cout << "Are you sure you want to delete? [y/n]: ";
            char confirm;
            cin >> confirm;

            if(confirm == 'y' || confirm == 'Y')
                {
                    vector<stUser> tempUser;
                    for(int i = 0; i < vUsers.size(); i++)
                        {
                            if(i != index)
                                tempUser.push_back(vUsers[i]);
                        }
                    vUsers = tempUser;
                    cout << "Deleted successfully!\n";
                }
        }
    else
        {
            cout << "Account not found!\n";
        }
    SaveUsersDataToFile(UsersFileName,vUsers);
    GoBackToMainMenu();
}



void Update_User_info(vector<stUser> & vUsers)
{
    string User_Name;
    cout << "Enter User Name to update it: ";
    cin >> User_Name;

    bool found = false;
    int index = -1;

    for(int i = 0 ; i < vUsers.size(); i++)
        {
            if(vUsers[i].UserName == User_Name)
                {
                    found = true;
                    index = i;
                    break;
                }
        }


    if(found)
        {
            cout << "__________________\n\n";
            cout << "Account Details:\n";

            cout << "| " << left << setw(15) << "User Name"
                 << "| " << left << setw(10) << "Password"
                 << "| " << left << setw(20) << "Permissions" << endl;


            cout << "| " << left << setw(15) << vUsers[index].UserName
                 << "| " << left << setw(10) << vUsers[index].Password
                 << "| " << left << setw(20) << vUsers[index].Permissions << endl;

            cout << "__________________\n";

            cout << "Are you sure you want to Update? [y/n]: ";
            char confirm;
            cin >> confirm;

            if(confirm == 'y' || confirm == 'Y')
                {
                    cout<<"Enter user name? ";
                    cin.ignore();
                    getline(cin,vUsers[index].UserName);
                    cout<<"Enter user Password? ";
                    cin>>vUsers[index].Password;
                    SaveUsersDataToFile(UsersFileName,vUsers);
                    cout << "Updated successfully!\n";
                }
        }
    else
        {
            cout << "Account not found!\n";
        }

    GoBackToMainMenu();
}

bool CheckAccessPermission(enMainMenuePermissions Permission)
{
    if (CurrentUser.Permissions == enMainMenuePermissions::eAll)
        return true;

    return ((Permission & CurrentUser.Permissions) == Permission);
}

void ShowAccessDeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou don't Have Permission To Do this,\nPlease Contact Your Admin.";
    cout << "\n------------------------------------\n";
    GoBackToMainMenu();
}

