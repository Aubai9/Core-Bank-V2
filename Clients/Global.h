#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <vector>

using namespace std;

struct stClient {
    string Account_Number, Pin_Code, Client_Name, Phone;
    double Balance;
};

struct stUser {
    string UserName, Password;
    int Permissions;
};

#endif
