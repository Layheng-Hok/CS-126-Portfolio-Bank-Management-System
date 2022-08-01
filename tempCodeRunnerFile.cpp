// ***************************************************************
//                      Bank Management System
// ***************************************************************

/*
   Bank Management System is a program intended for two types of user,
   which are the admins and the customers of a bank company.

   Admins and customers have different privileges, and they have to
   register or log in before using the program.

   Created by Layheng Hok & Lyyou Heng from Paragon International University
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iterator>

using namespace std;

class a{
    protected : 
        string name;
        string dob;
        string gender;
        string account_number, phone_number;
        string occupation;
        int i;
    public :
        void Add_Account();
        void Delete_Account();
        void Edit_Account();
}obj;

// function declaration
void Admin_Login_Menu();                            // function to display options for an admin to log in or register
void Admin_Login_System();                          // function for an admin to log in if they have already had an account
void Admin_Register_System();                       // function for an admin to create a new account
bool Admin_Username_Validation(string inputUSN);    // function to check if the new admin's username is repeated
void Admin_System();                                // function to display all the privileges that an admin has on the program
void Customer_Login_Menu();                         // function display options for a customer to log in or register
void Customer_Login_System();                       // function for a customer to log in if they have already had an account
void Customer_Register_System();                    // function for a customer to create a new account
bool Customer_Username_Validation(string inputUSN); // function to check if the new customer's username is repeated
void Customer_System();                             // function to display all the privileges that a customer has on the program

// global variables
char choice;       // for accepting a user's selection
string validation; // for validating a user's input

// main function to display the main menu for both admins and customers
int main()
{
    system("cls");

    do
    {
        cout << "\t\t\t\t  =======================================================================================\n"
                "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
                "\t\t\t\t  =======================================================================================\n"
                "\n"
                "\t\t\t\t                               : :  M A I N _ M E N U  : :                               \n"
                "\n"
                "\n\t\t\t\t  Please Select Your Role:\n\n"
                "\t\t\t\t     (1)  Admin\n\n"
                "\t\t\t\t     (2)  Customer\n\n"
                "\t\t\t\t     (E)  Exit\n"
                "\n\t\t\t\t  Your Selection: ";

        getline(cin, validation);
        system("cls");

        if (validation.length() == 1)
        {
            choice = validation[0];

            switch (choice)
            {
            case '1':
                Admin_Login_Menu();
                break;

            case '2':
                Customer_Login_Menu();
                break;

            case 'E':
            case 'e':
                cout << "\t\t\t\t  =======================================================================================\n"
                        "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
                        "\t\t\t\t  =======================================================================================\n\n"

                        "\t\t\t\t  <<                  You Have Successfully Logged Out Of The System.                  >>\n\n"
                        "\t\t\t\t  <<                              Please Visit Us Again!                               >>\n\n"
                        "\t\t\t\t  <<     Created By Layheng Hok & Lyyou Heng From Paragon International University     >>\n\n"
                        "\t\t\t\t  =======================================================================================\n\n";
                exit(0);

            default:
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
                break;
            }
        }
        else
        {
            cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
            system("pause");
            system("cls");
        }

    } while (true);

    return 0;
}

// ***************************************************************
//                         Admin Functions
// ***************************************************************

// function to display options for an admin to log in or register
void Admin_Login_Menu()
{
    system("cls");

    do
    {
        cout << "\t\t\t\t  =======================================================================================\n"
                "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
                "\t\t\t\t  =======================================================================================\n"
                "\n"
                "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
                "\n"
                "\t\t\t\t     (1)   Log In As An Admin\n\n"
                "\t\t\t\t     (2)   Register As An Admin\n\n"
                "\t\t\t\t     (B)   Back\n"
                "\n\t\t\t\t  Your Selection: ";

        getline(cin, validation);
        system("cls");

        if (validation.length() == 1)
        {
            choice = validation[0];

            switch (choice)
            {
            case '1':
                Admin_Login_System();
                break;

            case '2':
                Admin_Register_System();
                break;

            case 'B':
            case 'b':
                system("cls");
                main();
                break;

            default:
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
                break;
            }
        }
        else
        {
            cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
            system("pause");
            system("cls");
        }

    } while (true);
}

// function for an admin to log in if they have already had an account
void Admin_Login_System()
{
    system("cls");

    bool stageAdmin = false;
    string inputUSN, inputPW, existedInfo, existedUSN, existedPW;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Please Enter The Following Details:\n\n";
    cout << "\t\t\t\t     Username: ";
    getline(cin, inputUSN);

    // check if there is a space in the inputted username
    for (char c : inputUSN)
    {
        if (isspace(c))
        {
            system("cls");
            cout << "\nError Message: Username Must Not Contain Space(s).\n\n";
            cout << "\nPlease Try Again.\n\n";
            cout << "\nPress any key to continue . . . ";
            cin.clear();
            cin.ignore(10000, '\n');
            Admin_Login_System();
        }
    }
    cout << "\t\t\t\t     Password: ";
    getline(cin, inputPW);

    ifstream AdminInfo("Admin_Account.txt");

    if (AdminInfo.is_open())
    {
        while (getline(AdminInfo, existedInfo))
        {
            // split username from password
            string::size_type pos;
            pos = existedInfo.find(' ', 0);
            existedPW = existedInfo.substr(pos + 1);
            existedUSN = existedInfo.substr(0, pos);

            // check if the inputted username and password match with the existed username and password
            if (inputUSN == existedUSN && inputPW == existedPW)
            {
                stageAdmin = true;
                system("cls");
            }
        }
    }

    AdminInfo.close();

    if (stageAdmin)
    {
        cout << "\t\t\t\t  =======================================================================================\n\n";
        cout << "\t\t\t\t   Logged In Successfully.\n";
        cout << "\t\t\t\t   Greeting, " << inputUSN << ".\n\n";
        Admin_System();
    }
    else
    {
        cout << "\nError Message: Username And Password Do Not Match.\n\n";
        cout << "\nPlease Try Again.\n\n";

        do
        {
            cout << "\nEnter 'Y' To Log In Again, 'N' To Go Back To Login Menu.\n";
            cout << "Your Selection: ";
            getline(cin, validation);
            system("cls");

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                    Admin_Login_System();
                    break;

                case 'N':
                case 'n':
                    Admin_Login_Menu();
                    break;

                default:
                    cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                    system("pause");
                    system("cls");
                    break;
                }
            }
            else
            {
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
            }

        } while (true);
    }
}

// function for an admin to create a new account
void Admin_Register_System()
{
    system("cls");

    string inputUSN, inputPW;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Registering As An Admin\n\n";

    cout << "\t\t\t\t     Enter Your New Username: ";
    getline(cin, inputUSN);

    // check if there is a space in the inputted username
    for (char c : inputUSN)
    {
        if (isspace(c))
        {
            system("cls");
            cout << "\nError Message: Username Must Not Contain Space(s).\n\n";
            cout << "\nPlease Try Again.\n\n";
            cout << "\nPress any key to continue . . . ";
            cin.clear();
            cin.ignore(10000, '\n');
            Admin_Register_System();
        }
    }

    // check if there is a repeated username
    if (!(Admin_Username_Validation(inputUSN)))
    {
        system("cls");
        cout << "\nError Message: Username Already Exists.\n\n";
        cout << "\nPlease Try A Different One.\n\n";
        cout << "\nPress any key to continue . . . ";
        cin.clear();
        cin.ignore(10000, '\n');
        Admin_Register_System();
    }

    cout << "\t\t\t\t     Enter Your New Password: ";
    getline(cin, inputPW);

    // write username and password into a text file
    vector<string> AregUSN;
    AregUSN.push_back(inputUSN);

    vector<string> AregPW;
    AregPW.push_back(inputPW);

    ofstream AregInfo("Admin_Account.txt", ios::app);

    if (AregInfo.is_open())
    {
        ostream_iterator<string> out_iterator1(AregInfo, " ");
        copy(AregUSN.begin(), AregUSN.end(), out_iterator1);
        ostream_iterator<string> out_iterator2(AregInfo, "\n");
        copy(AregPW.begin(), AregPW.end(), out_iterator2);
    }

    AregInfo.close();

    system("cls");

    cout << "\nRegistered Successfully.\n\n";
    cout << "\nNow Please Log In.\n\n\n";
    system("pause");
    Admin_Login_System();
}

// function to check if the new admin's username is repeated
bool Admin_Username_Validation(string inputUSN)
{
    bool newUSN = true;
    string existedInfo, existedUSN, existedPW;

    ifstream AdminInfo("Admin_Account.txt");

    if (AdminInfo.is_open())
    {
        while (getline(AdminInfo, existedInfo))
        {
            // split username from password
            string::size_type pos;
            pos = existedInfo.find(' ', 0);
            existedPW = existedInfo.substr(pos + 1);
            existedUSN = existedInfo.substr(0, pos);

            if ((inputUSN == existedUSN && inputUSN == existedPW) || (inputUSN == existedUSN && inputUSN != existedPW))
            {
                newUSN = false;
                system("cls");
            }
        }
    }

    AdminInfo.close();

    return newUSN;
}

// function to display all the privileges that an admin has on the program
void Admin_System()
{
    do
    {
        cout << "\t\t\t\t  =======================================================================================\n"
                "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
                "\t\t\t\t  =======================================================================================\n"
                "\n"
                "\t\t\t\t                            : :  A D M I N _ S Y S T E M   : :                           \n"
                "\n"
                "\n\t\t\t\t  Here Are Your Privileges:\n\n"
                "\t\t\t\t     (1)  Add A New Account\n\n"
                "\t\t\t\t     (2)  Edit An Account\n\n"
                "\t\t\t\t     (3)  Delete An Account\n\n"
                "\t\t\t\t     (4)  Display All Accounts\n\n"
                "\t\t\t\t     (5)  Check Password\n\n"
                "\t\t\t\t     (B)  Back To The Main Menu\n"
                "\n\t\t\t\t  Your Selection: ";
        getline(cin, validation);
        system("cls");

        if (validation.length() == 1)
        {
            choice = validation[0];

            switch (choice)
            {
            case '1':
                obj.Add_Account();
                break;

            case '2':
                obj.Edit_Account();
                break;
            case '3':
                obj.Delete_Account();
                break;
            case '4':

                break;

            case '5':

                break;

            case 'B':
            case 'b':
                main();
                break;

            default:
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
                break;
            }
        }
        else
        {
            cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
            system("pause");
            system("cls");
        }

    } while (true);
}

// function to add account
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

    ofstream Bank_Info("Bank_Account.txt", ios::app);

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

    Bank_Info.close();
    cout << "\n";
    system("pause");
    system("cls");
}

void a::Edit_Account(){

}

void a::Delete_Account(){
    string aName,aDOB, aGender, aNumber, aPhone, aOccupation;
    vector<string> a,b,c,d,e,f,g;
    string find;
    bool flag;

    ofstream tempFile("temp.txt", ios::app);
    ifstream Bank_Info1("Bank_Account.txt");
    int size;

    cout << "Enter Name to delete account: ";cin >> find;

    while (!Bank_Info1.eof())
    {
        getline(Bank_Info1, aName);
        getline(Bank_Info1, aDOB);
        getline(Bank_Info1, aGender);
        getline(Bank_Info1, aNumber);
        getline(Bank_Info1, aPhone);
        getline(Bank_Info1, aOccupation);

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
        }
        ostream_iterator<string> aBank(tempFile);
        copy(a.begin(), a.end(), aBank);
        ostream_iterator<string> bBank(tempFile);
        copy(b.begin(), b.end(), bBank);
        ostream_iterator<string> cBank(tempFile);
        copy(c.begin(), c.end(), cBank);
        ostream_iterator<string> dBank(tempFile);
        copy(d.begin(), d.end(), dBank);
        ostream_iterator<string> eBank(tempFile);
        copy(e.begin(), e.end(), eBank);
        ostream_iterator<string> fBank(tempFile);
        copy(f.begin(), f.end(), fBank);
        a.pop_back();
        b.pop_back();
        c.pop_back();
        d.pop_back();
        e.pop_back();
        f.pop_back();
    }
    tempFile.close();
    Bank_Info1.close();
    remove("Bank_Account.txt");
    rename("temp.txt", "Bank_Account.txt");
    if (flag){
        cout << "\nData Deleted Successfully\n\n";
    }
    else {
        cout << "\nData Not Fount\n\n";

    }
}
// ***************************************************************
//                       Customer Functions
// ***************************************************************

// function to display options for a customer to log in or register
void Customer_Login_Menu()
{
    system("cls");

    do
    {
        cout << "\t\t\t\t  =======================================================================================\n"
                "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
                "\t\t\t\t  =======================================================================================\n"
                "\n"
                "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
                "\n"
                "\t\t\t\t     (1)   Log In As A Customer\n\n"
                "\t\t\t\t     (2)   Register As A Customer\n\n"
                "\t\t\t\t     (B)   Back\n"
                "\n\t\t\t\t  Your Selection: ";

        getline(cin, validation);
        system("cls");

        if (validation.length() == 1)
        {
            choice = validation[0];

            switch (choice)
            {
            case '1':
                Customer_Login_System();
                break;

            case '2':
                Customer_Register_System();
                break;

            case 'B':
            case 'b':
                system("cls");
                main();
                break;

            default:
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
                break;
            }
        }
        else
        {
            cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
            system("pause");
            system("cls");
        }

    } while (true);
}

// function for a customer to log in if they have already had an account
void Customer_Login_System()
{
    system("cls");

    bool stageCustomer = false;
    string inputUSN, inputPW, existedInfo, existedUSN, existedPW;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Please Enter The Following Details:\n\n";
    cout << "\t\t\t\t     Username: ";
    getline(cin, inputUSN);

    // check if there is a space in the inputted username
    for (char c : inputUSN)
    {
        if (isspace(c))
        {
            system("cls");
            cout << "\nError Message: Username Must Not Contain Space(s).\n\n";
            cout << "\nPlease Try Again.\n\n";
            cout << "\nPress any key to continue . . . ";
            cin.clear();
            cin.ignore(10000, '\n');
            Customer_Login_System();
        }
    }
    cout << "\t\t\t\t     Password: ";
    getline(cin, inputPW);

    ifstream CustomerInfo("Customer_Account.txt");

    if (CustomerInfo.is_open())
    {
        while (getline(CustomerInfo, existedInfo))
        {
            // split username from password
            string::size_type pos;
            pos = existedInfo.find(' ', 0);
            existedPW = existedInfo.substr(pos + 1);
            existedUSN = existedInfo.substr(0, pos);

            // check if the inputted username and password match with the existed username and password
            if (inputUSN == existedUSN && inputPW == existedPW)
            {
                stageCustomer = true;
                system("cls");
            }
        }
    }

    CustomerInfo.close();

    if (stageCustomer)
    {
        cout << "\t\t\t\t  =======================================================================================\n\n";
        cout << "\t\t\t\t   Logged In Successfully.\n";
        cout << "\t\t\t\t   Greeting, " << inputUSN << ".\n\n";
        Customer_System();
    }
    else
    {
        cout << "\nError Message: Username And Password Do Not Match.\n\n";
        cout << "\nPlease Try Again.\n\n";

        do
        {
            cout << "\nEnter 'Y' To Log In Again, 'N' To Go Back To Login Menu.\n";
            cout << "Your Selection: ";
            getline(cin, validation);
            system("cls");

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                    Customer_Login_System();
                    break;

                case 'N':
                case 'n':
                    Customer_Login_Menu();
                    break;

                default:
                    cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                    system("pause");
                    system("cls");
                    break;
                }
            }
            else
            {
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
            }

        } while (true);
    }
}

// function for an admin to create a new account
void Customer_Register_System()
{
    system("cls");

    string inputUSN, inputPW;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Registering As A Customer\n\n";

    cout << "\t\t\t\t     Enter Your New Username: ";
    getline(cin, inputUSN);

    // check if there is a space in the inputted username
    for (char c : inputUSN)
    {
        if (isspace(c))
        {
            system("cls");
            cout << "\nError Message: Username Must Not Contain Space(s).\n\n";
            cout << "\nPlease Try Again.\n\n";
            cout << "\nPress any key to continue . . . ";
            cin.clear();
            cin.ignore(10000, '\n');
            Customer_Register_System();
        }
    }

    // check if there is a repeated username
    if (!(Customer_Username_Validation(inputUSN)))
    {
        system("cls");
        cout << "\nError Message: Username Already Exists.\n\n";
        cout << "\nPlease Try A Different One.\n\n";
        cout << "\nPress any key to continue . . . ";
        cin.clear();
        cin.ignore(10000, '\n');
        Customer_Register_System();
    }

    cout << "\t\t\t\t     Enter Your New Password: ";
    getline(cin, inputPW);

    // write username and password into a text file
    vector<string> CregUSN;
    CregUSN.push_back(inputUSN);

    vector<string> CregPW;
    CregPW.push_back(inputPW);

    ofstream CregInfo("Customer_Account.txt", ios::app);

    if (CregInfo.is_open())
    {
        ostream_iterator<string> out_iterator1(CregInfo, " ");
        copy(CregUSN.begin(), CregUSN.end(), out_iterator1);
        ostream_iterator<string> out_iterator2(CregInfo, "\n");
        copy(CregPW.begin(), CregPW.end(), out_iterator2);
    }

    CregInfo.close();

    system("cls");

    cout << "\nRegistered Successfully.\n\n";
    cout << "\nNow Please Log In.\n\n\n";
    system("pause");
    Customer_Login_System();
}

// function to check if the new customer's username is repeated
bool Customer_Username_Validation(string inputUSN)
{
    bool newUSN = true;
    string existedInfo, existedUSN, existedPW;

    ifstream CustomerInfo("Customer_Account.txt");

    if (CustomerInfo.is_open())
    {
        while (getline(CustomerInfo, existedInfo))
        {
            // split username from password
            string::size_type pos;
            pos = existedInfo.find(' ', 0);
            existedPW = existedInfo.substr(pos + 1);
            existedUSN = existedInfo.substr(0, pos);

            if ((inputUSN == existedUSN && inputUSN == existedPW) || (inputUSN == existedUSN && inputUSN != existedPW))
            {
                newUSN = false;
                system("cls");
            }
        }
    }

    CustomerInfo.close();

    return newUSN;
}

// function to display all the privileges that a customer has on the program
void Customer_System()
{
    do
    {
        cout << "\t\t\t\t  =======================================================================================\n"
                "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
                "\t\t\t\t  =======================================================================================\n"
                "\n"
                "\t\t\t\t                          : :  C U S T O M E R _ S Y S T E M   : :                       \n"
                "\n"
                "\n\t\t\t\t  Here Are Your Privileges:\n\n"
                "\t\t\t\t     (1)  See Account Details\n\n"
                "\t\t\t\t     (2)  Make A Transfer\n\n"
                "\t\t\t\t     (3)  Show Transaction History\n\n"
                "\t\t\t\t     (B)  Back To The Main Menu\n"
                "\n\t\t\t\t  Your Selection: ";
        getline(cin, validation);
        system("cls");

        if (validation.length() == 1)
        {
            choice = validation[0];

            switch (choice)
            {
            case '1':

                break;

            case '2':

                break;

            case '3':

                break;

            case 'B':
            case 'b':
                main();
                break;

            default:
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
                break;
            }
        }
        else
        {
            cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
            system("pause");
            system("cls");
        }

    } while (true);
}
