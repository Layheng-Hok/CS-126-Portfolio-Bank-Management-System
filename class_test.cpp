#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;
class a{
    protected : 
        vector<string> Name;
        vector<string> DOB;
        vector<string> Gender;
        vector<string> Acocunt_Number;
        vector<string> Phone_Number;
        vector<string> Occupation;
        string name;
        string dob;
        string gender;
        string account_number, phone_number;
        string occupation;
        int i;
    public :
        void Add_Account();
        void Delete_Account();
};
int main(){
    a obj;
    // obj.Add_Account();
    // obj.Add_Account();
    obj.Delete_Account();
    return 0;
}
void a::Add_Account(){
    again:
    system("cls");
    cout << "\n\nEnter The Following Information" << endl;
    cout << "\n\tName: "; getline(cin,name);
    for (i=0; i<name.length(); i++){
        if (isspace(name[i])){
            break;
        }
        if (!isalnum(name[i])){
            system("cls");
            cout << "\nName must not contain special character\n";
            system("pause");
            goto again;
        }
    }
    cout << "\n\tDate of birth(DD/MM/YY): "; getline(cin,dob);
    cout << "\n\tGender: "; getline(cin,gender);
    cout << "\n\tAccount Number: "; getline(cin,account_number);
    cout << "\n\tPhone Number: "; getline(cin,phone_number);
    cout << "\n\tOccupation: "; getline(cin,occupation);

    vector<string> Name;
    Name.push_back(name);

    vector<string> DOB;
    DOB.push_back(dob);

    vector<string> Gender;
    Gender.push_back(gender);

    vector<string> Acocunt_Number;
    Acocunt_Number.push_back(account_number);

    vector<string> Phone_Number;
    Phone_Number.push_back(phone_number);

    vector<string> Occupation;
    Occupation.push_back(occupation);

    ofstream Bank_Info("Customer_Account.txt", ios::app);

    if (Bank_Info.is_open())
    {
        ostream_iterator<string> Acc_Name(Bank_Info,"\n");
        copy(Name.begin(), Name.end(), Acc_Name);

        ostream_iterator<string> Acc_DOB(Bank_Info,"\n");
        copy(DOB.begin(), DOB.end(), Acc_DOB);

        ostream_iterator<string> Acc_Gender(Bank_Info,"\n");
        copy(Gender.begin(), Gender.end(), Acc_Gender);

        ostream_iterator<string> Acc_Num(Bank_Info,"\n");
        copy(Acocunt_Number.begin(), Acocunt_Number.end(), Acc_Num);

        ostream_iterator<string> Acc_pNum(Bank_Info,"\n");
        copy(Phone_Number.begin(), Phone_Number.end(), Acc_pNum);

        ostream_iterator<string> Acc_Occuation(Bank_Info,"\n");
        copy(Occupation.begin(), Occupation.end(), Acc_Occuation);
    }
    i++;
    Bank_Info.close();
    cout << "\n";
    system("pause");
    system("cls");
}
void a::Delete_Account(){
    ofstream tempFile("temp.txt", ios::app);
    ifstream Bank_Info("Customer_Account.txt");

    string aName,aDOB, aGender, aNumber, aPhone, aOccupation;
    vector<string> a,b,c,d,e,f;
    string find;
    cout << "Enter Username to delete account: "; cin >> find;

    for (int j = 0; (j < i) || (!Bank_Info.eof());)
    {
        getline(Bank_Info, aName);
        getline(Bank_Info, aDOB);
        getline(Bank_Info, aGender);
        getline(Bank_Info, aNumber);
        getline(Bank_Info, aPhone);
        getline(Bank_Info, aOccupation);
        a.push_back(aName);
        b.push_back(aDOB);
        c.push_back(aGender);
        d.push_back(aNumber);
        e.push_back(aPhone);
        f.push_back(aOccupation);
        if (aName == find)
        {
            a.pop_back();
            b.pop_back();
            c.pop_back();
            d.pop_back();
            e.pop_back();
            f.pop_back();
            continue;
        }
    }
    for (int i=0; i<a.size(); i++)
    {
        tempFile << a[i];
    }
    Bank_Info.close();
    tempFile.close();
    remove("Customer_Account.txt");
    rename("temp.txt", "Customer_Account.txt");
    cout << "\nData Deleted Successfully\n\n";
}



// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <iterator>

// using namespace std;
// class a{
//     protected : 
//         vector<string> Name;
//         vector<string> DOB;
//         vector<string> Gender;
//         vector<string> Acocunt_Number;
//         vector<string> Phone_Number;
//         vector<string> Occupation;
//         string name;
//         string dob;
//         string gender;
//         string account_number, phone_number;
//         string occupation;
//         int i;
//     public :
//         void Add_Account();
//         void Delete_Account();
// };
// int main(){
//     a obj;
//     obj.Delete_Account();
//     return 0;
// }
// void a::Add_Account(){
//     again:
//     system("cls");
//     cout << "\n\nEnter The Following Information" << endl;
//     cout << "\n\tName: "; getline(cin,name);
//     for (i=0; i<name.length(); i++){
//         if (isspace(name[i])){
//             break;
//         }
//         if (!isalnum(name[i])){
//             system("cls");
//             cout << "\nName must not contain special character\n";
//             system("pause");
//             goto again;
//         }
//     }
//     cout << "\n\tDate of birth(DD/MM/YY): "; getline(cin,dob);
//     cout << "\n\tGender: "; getline(cin,gender);
//     cout << "\n\tAccount Number: "; getline(cin,account_number);
//     cout << "\n\tPhone Number: "; getline(cin,phone_number);
//     cout << "\n\tOccupation: "; getline(cin,occupation);

//     vector<string> Name;
//     Name.push_back(name);

//     vector<string> DOB;
//     DOB.push_back(dob);

//     vector<string> Gender;
//     Gender.push_back(gender);

//     vector<string> Acocunt_Number;
//     Acocunt_Number.push_back(account_number);

//     vector<string> Phone_Number;
//     Phone_Number.push_back(phone_number);

//     vector<string> Occupation;
//     Occupation.push_back(occupation);

//     ofstream Bank_Info("Customer_Account.txt", ios::app);

//     if (Bank_Info.is_open())
//     {
//         ostream_iterator<string> Acc_Name(Bank_Info,"\n");
//         copy(Name.begin(), Name.end(), Acc_Name);

//         ostream_iterator<string> Acc_DOB(Bank_Info,"\n");
//         copy(DOB.begin(), DOB.end(), Acc_DOB);

//         ostream_iterator<string> Acc_Gender(Bank_Info,"\n");
//         copy(Gender.begin(), Gender.end(), Acc_Gender);

//         ostream_iterator<string> Acc_Num(Bank_Info,"\n");
//         copy(Acocunt_Number.begin(), Acocunt_Number.end(), Acc_Num);

//         ostream_iterator<string> Acc_pNum(Bank_Info,"\n");
//         copy(Phone_Number.begin(), Phone_Number.end(), Acc_pNum);

//         ostream_iterator<string> Acc_Occuation(Bank_Info,"\n");
//         copy(Occupation.begin(), Occupation.end(), Acc_Occuation);
//     }

//     Bank_Info.close();
//     cout << "\n";
//     system("pause");
//     system("cls");
// }
// void a::Delete_Account(){
//     string aName,aDOB, aGender, aNumber, aPhone, aOccupation;
//     vector<string> s;
//     string find;
//     bool flag = false;
//     ofstream tempFile("temp.txt", ios::app);
//     ifstream Bank_Info1("Customer_Account.txt");

//     cout << "Enter Name to delete account: ";cin >> find;

//     while (!Bank_Info1.eof())
//     {
//         getline(Bank_Info1, aName);
//         getline(Bank_Info1, aDOB);
//         getline(Bank_Info1, aGender);
//         getline(Bank_Info1, aNumber); 
//         getline(Bank_Info1, aPhone);
//         getline(Bank_Info1, aOccupation);

//         s.push_back(aName);
//         if (aName == find){s.pop_back(); flag=true;}
//         if (aName != find){s.push_back("\n");}
        
//         s.push_back(aDOB);
//         if (aName == find){s.pop_back();}
//         if (aName != find){s.push_back("\n");}

//         s.push_back(aGender);
//         if (aName == find){s.pop_back();}
//         if (aName != find){s.push_back("\n");}

//         s.push_back(aNumber);
//         if (aName == find){s.pop_back();}
//         if (aName != find){s.push_back("\n");}

//         s.push_back(aPhone);
//         if (aPhone == find){s.pop_back();}
//         if (aName != find){s.push_back("\n");}

//         s.push_back(aOccupation);
//         if (aOccupation == find){s.pop_back();}
//         if (aOccupation != find){s.push_back("\n");}
//     }

//     for (int i=0; i<s.size(); i++)
//     {
//         tempFile << s[i];
//     }
//     Bank_Info1.close();
//     tempFile.close();
//     remove("Customer_Account.txt");
//     rename("temp.txt", "Customer_Account.txt");
//     if (flag){
//         cout << "\nData Deleted Successfully\n\n";
//     }
//     else {
//         cout << "\nData Not Fount\n\n";
//     }
// }