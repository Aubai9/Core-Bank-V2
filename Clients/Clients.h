#ifndef CLIENTS_H
#define CLIENTS_H

#include "Global.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

void Show_Clients_List(vector<stClient> & vClient);
void Add_New_Client(vector<stClient>& vClient);
void Delete_Client(vector<stClient> & vClient);
void Update_Client_info(vector<stClient> & vClient);
void Find_Client(vector<stClient> & vClient);
void Deposit(vector<stClient> & vClient);
void WithDraw(vector<stClient> & vClient);
void Balances(vector<stClient> & vClient);
void GoBackToMainMenu();

#endif
