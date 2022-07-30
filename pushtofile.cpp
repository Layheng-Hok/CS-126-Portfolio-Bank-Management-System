#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    string inputUSN, inputPW;

    getline(cin, inputUSN);
    getline(cin, inputPW);

    vector<string> username;
    username.push_back(inputUSN);

    vector<string> password;
    password.push_back(inputPW);

    ofstream CregInfo("Customer_Account.txt", ios::app);

    if (CregInfo.is_open())
    {
        ostream_iterator<string> out_iterator1(CregInfo, " ");
        copy(username.begin(), username.end(), out_iterator1);
        ostream_iterator<string> out_iterator2(CregInfo);
        copy(password.begin(), password.end(), out_iterator2);
    }

    CregInfo.close();

    ifstream CregInfo1("Customer_Account.txt", ios::in);
    string line;
    vector<string> info;

    while (getline(CregInfo1, line))
    {
        info.push_back(line);
    }
    CregInfo.close();

    for (int i = 0; i < info.size(); i++)
    {
        cout << info[i] << " ";
    }

    return 0;
}