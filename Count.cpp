// b sl o
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iterator>
using namespace std;
class count
{
public:
    int count = 0;
    int num;
    void Account();
    void Test();
};
void count::Account()
{
    string line;
    ifstream Number_Of_Account("Bank_Account.txt", ios::in);
    while (!Number_Of_Account.eof())
    {
        getline(Number_Of_Account, line);
        count++;
    }
    num = count / 6;
}
void count::Test()
{
    Account();
    cout << num;
}
int main()
{
    count obj;
    obj.Test();
    return 0;
}