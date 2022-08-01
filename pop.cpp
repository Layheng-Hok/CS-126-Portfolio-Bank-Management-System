#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string Info_acc;
    vector<string> v;
    string line;
    string user1,pass1;

// read file and cout 
    ifstream account("Customer_Account.txt");
    if (account.is_open())
    {
        while(getline(account,line))
        {
            v.push_back(line);
            v.push_back("\n");
        }
    }
    account.close();
    for (int i=0; i<v.size(); i++){
        cout << v[i];
    }

    ofstream tempFile("temp.txt", ios::app);
    ifstream f2("Customer_Account.txt");

    vector<string> s;
    string find;
    cout << "Enter Username to delete account: "; cin >> find;

    while (getline(f2, Info_acc))
    {
        string::size_type pos;
        pos = Info_acc.find(' ', 0);
        user1 = Info_acc.substr(0, pos);
        pass1 = Info_acc.substr(pos + 1);
        s.push_back(Info_acc);
        if (user1 == find)
        {
            s.pop_back();
        }
        if (user1 != find){
            s.push_back("\n");
        }
    }
    for (int i=0; i<s.size(); i++)
    {
        tempFile << s[i];
    }
    f2.close();
    tempFile.close();
    remove("Customer_Account.txt");
    rename("temp.txt", "Customer_Account.txt");
    cout << "\nData Deleted Successfully\n\n";
}