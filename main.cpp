#include "Clients.h"
#include "Users.h"

vector<stUser> vUsers;

vector<stClient> vClient;

stUser CurrentUser;


void DrawHeader(string Title)
{
    cout << setw(30) << "=====================================\n";
    cout << setw(25) << Title << endl;
    cout << setw(30) << "=====================================\n";
}

void TransactionMenu()
{
    system("cls");
    DrawHeader("Transaction Menu");
    cout << "[1] Deposit.\n";
    cout << "[2] Withdraw.\n";
    cout << "[3] Total Balances.\n";
    cout << "[4] Main Menu.\n";
    cout << "=====================================\n";

    short choice;
    cout << "Choose what do you want to do? [1 to 4]\n";
    cin >> choice;

    switch(choice)
        {
        case 1:
            Deposit(vClient);
            break;
        case 2:
            WithDraw(vClient);
            break;
        case 3:
            Balances(vClient);
            break;
        case 4:
            system("cls");
            return;
        }
}



void mainMenu()
{
    system("cls");
    short choice;
    vector<string> menuOptions = {"Show Client List", "Add New Client", "Delete Client", "Update Client info", "Find Client", "Transactions", "Manage Users", "Logout"};
    DrawHeader("Main Menu");

    for (int i = 0; i < menuOptions.size(); i++)
        {
            cout << "[" << i + 1 << "] " << menuOptions[i] << "." << endl;
        }
    cout << "=====================================\n";
    cout << "Choose what do you want to do? [1 to 8]\n";
    cin >> choice;

    switch (choice)
        {
        case 1:
            if (CheckAccessPermission(enMainMenuePermissions::pListClients))
                Show_Clients_List(vClient);
            else
                ShowAccessDeniedMessage();
            break;

        case 2:
            if (CheckAccessPermission(enMainMenuePermissions::pAddNewClient))
                Add_New_Client(vClient);
            else
                ShowAccessDeniedMessage();
            break;

        case 3:
            if (CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
                Delete_Client(vClient);
            else
                ShowAccessDeniedMessage();
            break;

        case 4:
            if (CheckAccessPermission(enMainMenuePermissions::pUpdateClients))
                Update_Client_info(vClient);
            else
                ShowAccessDeniedMessage();
            break;

        case 5:
            if (CheckAccessPermission(enMainMenuePermissions::pFindClient))
                Find_Client(vClient);
            else
                ShowAccessDeniedMessage();
            break;

        case 6:
            if (CheckAccessPermission(enMainMenuePermissions::pTransactions))
              TransactionMenu();
            else
                ShowAccessDeniedMessage();
            break;

        case 7:
            if (CheckAccessPermission(enMainMenuePermissions::pManageUsers))
                ManageUsersMenu();
            else
                ShowAccessDeniedMessage();
            break;

        case 8:
            login();
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            GoBackToMainMenu();
        }
}

void ManageUsersMenu()
{
    system("cls");
    short choice;
    vector<string> menuOptions = {"List Users", "Add User","Delete User","Update User","Find User","Main Menu"};
    DrawHeader("Manage Users Screen");
    for(int i = 0 ; i < menuOptions.size(); i++)
        {
            cout<<"["<<i + 1<<"] "<<menuOptions[i]<<"."<<endl;
        }
    cout<<"=====================================\n";
    cout<<"Choose what do you want to do? [1 to 6]\n";
    cin>>choice;
    switch(choice)
        {
        case 1:
            Show_List_Users(vUsers);
            break;
        case 2:
            Add_New_User(vUsers);
            break;
        case 3:
            Delete_User(vUsers);
            break;
        case 4:
            Update_User_info(vUsers);
            break;
        case 5:
            Find_User(vUsers);
            break;
        case 6:
            return;
        default:
            cout<<"Invalid choice! Please try again.\n";
        }
}




int main()
{
    vUsers =  LoadUsersDataFromFile("user.txt");
    system("cls");
    login();
    while (true)
        {
            mainMenu();
        }
}
