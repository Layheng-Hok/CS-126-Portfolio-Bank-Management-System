#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <sstream>

using namespace std;

int main()
{
    string str1, str2;
    ifstream AdminInfo("Admin_Account.txt", ios::in);
    AdminInfo >> str1;
    getline(AdminInfo, str2);

    cout << str1 << endl;
    cout << str2 << endl;

    AdminInfo.close();

    string str = "one two three";
    str.erase(remove(str.begin(), str.end(), ' '));
    cout << str;

    /*   string S, T;       // declare string variables
       getline(cin, S);   // use getline() function to read a line of string and store into S variable.
       stringstream X(S); // X is an object of stringstream that references the S string
                          // use while loop to check the getline() function condition
       getline(X, T, ' ');
       cout << T << endl;*/

    string first;
    getline(cin, first);
    string second;
    string::size_type pos;
    pos = first.find(' ', 0);
    second = first.substr(pos + 1);
    first = first.substr(0, pos);

    cout << first << endl;
    cout << second << endl;
}