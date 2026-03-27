#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<cstdlib>

using namespace std;

struct stClient
{
    string Account_Number;
    string Pin_Code;
    string Client_Name;
    string Phone;
    double Balance;
};

vector <stClient> vClient;

void GoBackToMainMenu()
{
    cout<<"press any key to go back to Main Menu\n";
    system("pause > 0");
    system("cls");
}

void Show_Clients_List(vector<stClient> & vClient)
{
    if(vClient.size() == 0)
        {
            cout << "----------------------- No Clients to show -----------------------\n";
            GoBackToMainMenu();
        }
    else
        {
            cout << "\n\t\t\tClient List (" << vClient.size() << ") Client(s).\n";
            cout << "__________________\n\n";

            cout << "| " << left << setw(15) << "Account Number"
                 << "| " << left << setw(10) << "Pin Code"
                 << "| " << left << setw(20) << "Client Name"
                 << "| " << left << setw(12) << "Phone"
                 << "| " << left << setw(12) << "Balance" << endl;

            cout << "__________________\n\n";


            for(int i = 0 ; i < vClient.size(); i++)
                {
                    cout << "| " << left << setw(15) << vClient[i].Account_Number
                         << "| " << left << setw(10) << vClient[i].Pin_Code
                         << "| " << left << setw(20) << vClient[i].Client_Name
                         << "| " << left << setw(12) << vClient[i].Phone
                         << "| " << left << setw(12) << vClient[i].Balance << endl;
                }
            cout << "__________________\n";
            GoBackToMainMenu();
        }
}

void Add_New_Client(vector<stClient>& vClient)
{
    stClient tempClient;
    bool exist = false;
    cout<<"Adding new client:\n";
    do
        {
            exist = false;
            cout<<"Enter Account Number ? ";
            cin>>tempClient.Account_Number;
            for(int i = 0; i < vClient.size(); i++)
                {
                    if(vClient[i].Account_Number == tempClient.Account_Number)
                        {
                            cout<<"Client with ["<<tempClient.Account_Number<<"] already exist\n";
                            exist = true;
                            break;

                        }
                }
        }
    while(exist == true);
    cout<<"Enter Pin Code? ";
    cin>>tempClient.Pin_Code;
    cout<<"Enter Name? ";
    cin.ignore();
    getline(cin,tempClient.Client_Name);
    cout<<"Enter Phone? ";
    cin>>tempClient.Phone;
    cout<<"Enter Balance? ";
    cin>>tempClient.Balance;
    vClient.push_back(tempClient);
    cout<<"Client added successfully!\n";
    GoBackToMainMenu();
}


void Delete_Client(vector<stClient> & vClient)
{
    string Account_Number;
    cout << "Enter Account number to delete it: ";
    cin >> Account_Number;

    bool found = false;
    int index = -1;


    for(int i = 0 ; i < vClient.size(); i++)
        {
            if(vClient[i].Account_Number == Account_Number)
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

            cout << "| " << left << setw(15) << "Account Number"
                 << "| " << left << setw(10) << "Pin Code"
                 << "| " << left << setw(20) << "Client Name"
                 << "| " << left << setw(12) << "Phone"
                 << "| " << left << setw(12) << "Balance" << endl;


            cout << "| " << left << setw(15) << vClient[index].Account_Number
                 << "| " << left << setw(10) << vClient[index].Pin_Code
                 << "| " << left << setw(20) << vClient[index].Client_Name
                 << "| " << left << setw(12) << vClient[index].Phone
                 << "| " << left << setw(12) << vClient[index].Balance << endl;


            cout << "__________________\n";

            cout << "Are you sure you want to delete? [y/n]: ";
            char confirm;
            cin >> confirm;

            if(confirm == 'y' || confirm == 'Y')
                {
                    vector<stClient> tempClient;
                    for(int i = 0; i < vClient.size(); i++)
                        {
                            if(i != index)
                                tempClient.push_back(vClient[i]);
                        }
                    vClient = tempClient;
                    cout << "Deleted successfully!\n";
                }
        }
    else
        {
            cout << "Account not found!\n";
        }
    GoBackToMainMenu();
}

void Update_Client_info(vector<stClient> & vClient)
{
    string Account_Number;
    cout << "Enter Account number to update it: ";
    cin >> Account_Number;

    bool found = false;
    int index = -1;

    for(int i = 0 ; i < vClient.size(); i++)
        {
            if(vClient[i].Account_Number == Account_Number)
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

            cout << "| " << left << setw(15) << "Account Number"
                 << "| " << left << setw(10) << "Pin Code"
                 << "| " << left << setw(20) << "Client Name"
                 << "| " << left << setw(12) << "Phone"
                 << "| " << left << setw(12) << "Balance" << endl;

            cout << "| " << left << setw(15) << vClient[index].Account_Number
                 << "| " << left << setw(10) << vClient[index].Pin_Code
                 << "| " << left << setw(20) << vClient[index].Client_Name
                 << "| " << left << setw(12) << vClient[index].Phone
                 << "| " << left << setw(12) << vClient[index].Balance << endl;

            cout << "__________________\n";

            cout << "Are you sure you want to Update? [y/n]: ";
            char confirm;
            cin >> confirm;

            if(confirm == 'y' || confirm == 'Y')
                {
                    cout<<"Enter Pin Code? ";
                    cin>>vClient[index].Pin_Code;
                    cout<<"Enter Name? ";
                    cin.ignore();
                    getline(cin,vClient[index].Client_Name);
                    cout<<"Enter Phone? ";
                    cin>>vClient[index].Phone;
                    cout<<"Enter Balance? ";
                    cin>>vClient[index].Balance;
                    cout << "Updated successfully!\n";
                }
        }
    else
        {
            cout << "Account not found!\n";
        }
    GoBackToMainMenu();
}

void Find_Client(vector<stClient> & vClient )
{
    string Account_Number;
    cout << "Enter Account number to Find it: ";
    cin >> Account_Number;
    bool found = false;
    for(int i = 0; i < vClient.size(); i++)
        {
            if(vClient[i].Account_Number == Account_Number)
                {
                    cout << "__________________\n\n";
                    cout << "Account Details:\n";

                    cout << "| " << left << setw(15) << "Account Number"
                         << "| " << left << setw(10) << "Pin Code"
                         << "| " << left << setw(20) << "Client Name"
                         << "| " << left << setw(12) << "Phone"
                         << "| " << left << setw(12) << "Balance" << endl;

                    cout << "| " << left << setw(15) << vClient[i].Account_Number
                         << "| " << left << setw(10) << vClient[i].Pin_Code
                         << "| " << left << setw(20) << vClient[i].Client_Name
                         << "| " << left << setw(12) << vClient[i].Phone
                         << "| " << left << setw(12) << vClient[i].Balance << endl;

                    cout << "__________________\n";
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

void Deposit(vector<stClient> & vClient)
{
    string Account_Number;
    double deposit_Amount;
    char confirm;
    bool found = false;
    cout << "\n-------------------------------------- \n";
    cout <<setw(25) <<"Deposit Screen ";
    cout << "\n-------------------------------------- \n";
    do
        {
            cout << "Enter Account number to Find it: ";
            cin >> Account_Number;
            for(int i = 0; i < vClient.size(); i++)
                {
                    if(vClient[i].Account_Number == Account_Number)
                        {
                            cout << "__________________\n\n";
                            cout << "Account Details:\n";

                            cout << "| " << left << setw(15) << "Account Number"
                                 << "| " << left << setw(10) << "Pin Code"
                                 << "| " << left << setw(20) << "Client Name"
                                 << "| " << left << setw(12) << "Phone"
                                 << "| " << left << setw(12) << "Balance" << endl;

                            cout << "| " << left << setw(15) << vClient[i].Account_Number
                                 << "| " << left << setw(10) << vClient[i].Pin_Code
                                 << "| " << left << setw(20) << vClient[i].Client_Name
                                 << "| " << left << setw(12) << vClient[i].Phone
                                 << "| " << left << setw(12) << vClient[i].Balance << endl;

                            cout << "__________________\n";

                            cout<<"please enter the deposit amount: ";
                            cin>> deposit_Amount;
                            cout<<"Are you sure you want to perform this transaction?[y/n]\n";
                            cin>>confirm;
                            if(confirm == 'y' || confirm == 'Y')
                                {
                                    vClient[i].Balance += deposit_Amount;
                                }


                            found = true;
                            break;
                        }
                }
            if(!found)
                {
                    cout << "Account not found!\n";
                }

        }
    while(found == false);
    GoBackToMainMenu();
}

void Balances(vector<stClient> & vClient)
{
    if(vClient.size() == 0)
        {
            cout << "----------------------- No Clients to show -----------------------\n";
            GoBackToMainMenu();
        }
    else
        {
            cout << "\n\t\t\tClient List (" << vClient.size() << ") Client(s).\n";
            cout << "_______________________________________________________\n\n";


            cout << "| " << left << setw(15) << "Account Number"
                 << "| " << left << setw(20) << "Client Name"
                 << "| " << left << setw(12) << "Balance" << endl;

            cout << "_______________________________________________________\n\n";


            for(int i = 0 ; i < vClient.size(); i++)
                {
                    cout << "| " << left << setw(15) << vClient[i].Account_Number
                         << "| " << left << setw(20) << vClient[i].Client_Name
                         << "| " << left << setw(12) << vClient[i].Balance << endl;
                }
            cout << "_______________________________________________________\n";

            double total = 0;
            for(int i = 0; i < vClient.size(); i++) total += vClient[i].Balance;
            cout << "Total Balances = " << total << endl;

            GoBackToMainMenu();
        }
}


void WithDraw(vector<stClient> & vClient)
{
    string Account_Number;
    double withdraw_Amount;
    char confirm;
    bool found = false;
    cout << "\n-------------------------------------- \n";
    cout <<setw(25) <<"Withdraw Screen ";
    cout << "\n-------------------------------------- \n";
    do
        {
            cout << "Enter Account number to Find it: ";
            cin >> Account_Number;
            for(int i = 0; i < vClient.size(); i++)
                {
                    if(vClient[i].Account_Number == Account_Number)
                        {
                            cout << "__________________\n\n";
                            cout << "Account Details:\n";

                            cout << "| " << left << setw(15) << "Account Number"
                                 << "| " << left << setw(10) << "Pin Code"
                                 << "| " << left << setw(20) << "Client Name"
                                 << "| " << left << setw(12) << "Phone"
                                 << "| " << left << setw(12) << "Balance" << endl;

                            cout << "| " << left << setw(15) << vClient[i].Account_Number
                                 << "| " << left << setw(10) << vClient[i].Pin_Code
                                 << "| " << left << setw(20) << vClient[i].Client_Name
                                 << "| " << left << setw(12) << vClient[i].Phone
                                 << "| " << left << setw(12) << vClient[i].Balance << endl;

                            cout << "__________________\n";

                            cout<<"please enter the withdraw amount: ";
                            cin>> withdraw_Amount;
                            cout<<"Are you sure you want to perform this transaction?[y/n]\n";
                            cin>>confirm;
                            if(confirm == 'y' || confirm == 'Y')
                                {
                                    while(withdraw_Amount > vClient[i].Balance)
                                        {
                                            cout<<"Amount Exceeds the balance, you can withdarw up to: "<< vClient[i].Balance<<endl;
                                            cout<<"please enter the withdraw amount: ";
                                            cin>> withdraw_Amount;
                                        };
                                    vClient[i].Balance -= withdraw_Amount;
                                }
                            found = true;
                            break;
                        }
                }
        }

    while(found == false);
    if(!found)
        {
            cout << "Account not found!\n";
        }
    GoBackToMainMenu();
}


void TransactionMenu()
{
    system("cls");
    cout << "=====================================\n";
    cout << setw(24) << "Transaction Menu\n";
    cout << "=====================================\n";
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
    short choice;
    vector<string> menuOptions = {"Show Client List","Add New Client","Delete Client","Update Client info","Find Client","Transactions","Exit"};
    cout<<"=====================================\n";
    cout<<setw(24)<<"Main Menu\n";
    cout<<"=====================================\n";
    for(int i = 0 ; i < menuOptions.size(); i++)
        {
            cout<<"["<<i + 1<<"] "<<menuOptions[i]<<"."<<endl;
        }
    cout<<"=====================================\n";
    cout<<"Choose what do you want to do? [1 to 7]\n";
    cin>>choice;
    switch(choice)
        {
        case 1:
            Show_Clients_List(vClient);
            break;
        case 2:
            Add_New_Client(vClient);
            break;
        case 3:
            Delete_Client(vClient);
            break;
        case 4:
            Update_Client_info(vClient);
            break;
        case 5:
            Find_Client(vClient);
            break;
        case 6:
            TransactionMenu();
            break;
        case 7:
            cout<<"\n==========================================\n";
            cout<<"\n\tEnd of the program!\n";
            cout<<"\n==========================================\n";
            exit(0);
        default:
            cout<<"Invalid choice! Please try again.\n";
        }
}


int main()
{
    while (true)
        {
            mainMenu();
        }
}
