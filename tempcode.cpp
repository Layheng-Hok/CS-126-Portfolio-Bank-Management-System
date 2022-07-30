#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <sstream>

using namespace std;

int main()
{
    bool stageAdmin = false;
    string AdminUSN, AdminPW, existedInfo, existedUSN, existedPW;

    cout << "\t\t\t\t     Username: ";
    getline(cin, AdminUSN);
    cout << AdminUSN << endl;
    cout << "\t\t\t\t     Password: ";
    getline(cin, AdminPW);
    cout << AdminPW << endl;

    ifstream AdminInfo("Admin_Account.txt");

    if (AdminInfo.is_open())
    {
        while (getline(AdminInfo, existedInfo))
        {
            cout << existedInfo << endl;
            // split username from password
            string::size_type pos;
            pos = existedInfo.find(' ', 0);
            existedPW = existedInfo.substr(pos + 1);
            existedUSN = existedInfo.substr(0, pos);

            cout << existedUSN << endl;
            cout << existedPW << endl;
            if (AdminUSN == existedUSN && AdminPW == existedPW)
            {
                stageAdmin = true;
            }
        }
    }

    AdminInfo.close();

    if (stageAdmin)
    {
        cout << "It's working" << endl;
    }

    return 0;
}