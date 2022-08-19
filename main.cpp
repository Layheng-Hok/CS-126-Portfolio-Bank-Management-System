// ***************************************************************
//                      Bank Management System
// ***************************************************************

/*
   Bank Management System is a program intended for two types of users,
   which are the admins and the customers of a bank company.

   Admins and customers have different privileges, and they have to
   register or log in before using the program.

   Created by Layheng Hok & Lyyou Heng from Paragon International University
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <vector>
#include <iterator>
#include <iomanip>
#include <ctime>

using namespace std;

// login system by implementing STL
void Admin_Login_Menu();                            // function to display options for an admin to log in or register
void Admin_Login_System();                          // function for an admin to log in if they have already had an account
void Admin_Register_System();                       // function for an admin to create a new account
bool Admin_Username_Validation(string inputUSN);    // function to check if the inputted admin's username exists
void Admin_Delete();                                // function to delete an admin's registered username and password
void Admin_Verification(string targetedInfo);       // function to verify an admin's identity before deleting their account
void Admin_System();                                // function to display all the privileges that an admin has on the program
void Customer_Login_Menu();                         // function display options for a customer to log in or register
void Customer_Login_System();                       // function for a customer to log in if they have already had an account
void Customer_Register_System();                    // function for a customer to create a new account
bool Customer_Username_Validation(string inputUSN); // function to check if the inputted customer's username exists
void Customer_Delete();                             // function to delete a customer's registered username and password
void Customer_Verification(string targetedInfo);    // function to verify a customer's identity before deleting their account
void Customer_System();                             // function to display all the privileges that a customer has on the program

// class to store information and all operations on customers
class a
{
protected:
    string fname, lname, name, DOB, gender, occupation;
    int account, age, birthDate, birthMonth, birthYear, pin;
    float balance, deposit;
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i = 0;

public:
    int age_conversion(int bd, int bm, int by); // function to convert birthday into age

    // admin functions
    void Admin_Add_Account();          // function for an admin to log in if they have already had an account
    void Admin_Delete_Account();       // function to delete a customer's account
    void Admin_Edit_Account();         // function to edit a customer's account
    void Admin_Display_All_Accounts(); // function to display all of customer accounts
    void Admin_Search_Account();       // function to search for a customer account

    // customer functions
    void Customer_View_Details();                                        // function for a customer to display their own account details
    void Customer_Make_Transaction();                                    // function for a customer to transfer money to a different account
    bool Customer_Account_Validation(int targetedAcc);                   // function to check if an account exists
    bool Customer_Balance_Validation(int fromAcc, float amountTransfer); // function to check a user's balance before making a transaction
    void Customer_PIN_Verification(int fromAcc);                         // function to check customer's PIN code before making a transaction
    void Customer_Transaction_History();                                 // function for a customer to view their transaction history
} obj;

// function to convert birthday into age
int a::age_conversion(int bd, int bm, int by)
{
    int age;

    struct tm date = {0};
    date.tm_year = by - 1900;
    date.tm_mon = bm - 1;
    date.tm_mday = bd;

    time_t normal = mktime(&date);
    time_t current;
    time(&current);
    age = (difftime(current, normal) + 86400L / 2) / 86400L;
    age = age / 365;

    return age;
}

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
                "\t\t\t\t     (3)   Delete Your Registered Username And Password\n\n"
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

            case '3':
                Admin_Delete();
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
            cout << "\nError Message: Username Must Not Contain Space(s).";
            cout << "\nPlease Try Again.\n\n";
            system("pause");
            Admin_Login_System();
        }
    }

    cout << "\t\t\t\t     Password: ";
    getline(cin, inputPW);

    ifstream AdminInfo("Admin_Account.txt", ios::in);

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
        cout << endl;
        cout << "\t\t\t\t     Error Message: Username And Password Do Not Match.\n";
        cout << "\t\t\t\t     Please Try Again.\n\n";

        do
        {
            cout << "\t\t\t\t     Enter 'Y' To Log In Again, 'N' To Go Back To Login Menu.\n";
            cout << "\t\t\t\t     Your Selection: ";
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
            cout << "\nError Message: Username Must Not Contain Space(s).";
            cout << "\nPlease Try Again.\n\n";
            system("pause");
            Admin_Register_System();
        }
    }

    // check if there is a repeated username
    if (!(Admin_Username_Validation(inputUSN)))
    {
        system("cls");
        cout << "\nError Message: Username Already Exists.";
        cout << "\nPlease Try A Different One.\n\n";
        system("pause");
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

// function to check if the inputted admin's username exists
bool Admin_Username_Validation(string inputUSN)
{
    bool newUSN = true;
    string existedInfo, existedUSN, existedPW;

    ifstream AdminInfo("Admin_Account.txt", ios::in);

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

// function to delete an admin's registered username and password
void Admin_Delete()
{
    system("cls");

    string targetedInfo;
    string existedInfo, existedUSN, existedPW;
    vector<string> newInfo;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Deleting Your Account\n\n";

    cout << "\t\t\t\t     Enter Your Username To Delete Your Account: ";
    getline(cin, targetedInfo);

    // check if there is a space in the inputted username
    for (char c : targetedInfo)
    {
        if (isspace(c))
        {
            system("cls");
            cout << "\nError Message: Username Must Not Contain Space(s).";
            cout << "\nPlease Try Again.\n\n";
            system("pause");
            Admin_Delete();
        }
    }

    if (!(Admin_Username_Validation(targetedInfo)))
    {
        do
        {
            cout << endl;
            cout << "\t\t\t\t     Do You Want To Delete The Account With The Username '" << targetedInfo << "'?\n\n";
            cout << "\t\t\t\t     Enter 'Y' To Confirm, 'N' To Cancel.\n";
            cout << "\t\t\t\t     Your Selection: ";

            getline(cin, validation);

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                {
                    // ask the user to reverify themself
                    Admin_Verification(targetedInfo);

                    ifstream AdminInfo("Admin_Account.txt", ios::in); // for reading all existed information
                    ofstream tempFile("temp.txt", ios::app);          // for writing needed information

                    while (getline(AdminInfo, existedInfo))
                    {
                        // write all the existed information in file into the vector
                        newInfo.push_back(existedInfo);

                        // split username from password
                        string::size_type pos;
                        pos = existedInfo.find(' ', 0);
                        existedUSN = existedInfo.substr(0, pos);
                        existedPW = existedInfo.substr(pos + 1);

                        if (targetedInfo == existedUSN)
                        {
                            // deleted information that is not needed
                            newInfo.pop_back();
                        }
                        else if (targetedInfo != existedUSN)
                        {
                            // keep the existed information inside the vector and add an endline after each vector's element
                            newInfo.push_back("\n");
                        }
                    }

                    // write the needed information into a temporary file
                    for (int i = 0; i < newInfo.size(); i++)
                    {
                        tempFile << newInfo[i];
                    }

                    AdminInfo.close();
                    tempFile.close();

                    remove("Admin_Account.txt");
                    rename("temp.txt", "Admin_Account.txt");

                    cout << endl;
                    cout << "\t\t\t\t     Account Is Deleted Successfully.\n\n";
                    system("pause");
                    Admin_Login_Menu();
                }

                case 'N':
                case 'n':
                    cout << endl;
                    cout << "\t\t\t\t     Account Is Not Deleted.\n\n";
                    system("pause");
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
    else if (Admin_Username_Validation(targetedInfo))
    {
        system("cls");

        cout << "\t\t\t\t     Error Message: Account Is Not Found.\n";
        cout << "\t\t\t\t     Please Check Your Username And Try Again.\n\n";

        do
        {
            cout << "\t\t\t\t     Enter 'Y' To Try Again, 'N' To Go Back To Login Menu.\n";
            cout << "\t\t\t\t     Your Selection: ";
            getline(cin, validation);
            system("cls");

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                    Admin_Delete();
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

// function to verify an admin's identity before deleting their account
void Admin_Verification(string targetedInfo)
{
reverify:

    bool verification = false;
    string inputUSN, inputPW, existedInfo, existedUSN, existedPW;

    cout << endl;
    cout << "\t\t\t\t  =======================================================================================\n\n";
    cout << "\t\t\t\t     For Security Purpose, Please Retype Your Username And Enter Your Password.\n\n";
    cout << "\t\t\t\t     Username: ";
    getline(cin, inputUSN);

    // check if there is a space in the inputted username
    for (char c : inputUSN)
    {
        if (isspace(c))
        {
            system("cls");
            cout << "\nError Message: Username Must Not Contain Space(s).";
            cout << "\nPlease Try Again.\n\n";
            system("pause");
            system("cls");
            goto reverify;
        }
    }

    // conditions to check if the reentered username matches
    if (inputUSN == targetedInfo)
    {
        cout << "\t\t\t\t     Password: ";
        getline(cin, inputPW);

        ifstream AdminInfo("Admin_Account.txt", ios::in);

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
                    verification = true;
                    system("cls");
                }
            }
        }

        AdminInfo.close();

        if (verification)
        {
            cout << "\t\t\t\t  =======================================================================================\n";
            // return back to the delete function
        }
        else
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";
            cout << "\t\t\t\t     Error Message: Username And Password Do Not Match.\n";
            cout << "\t\t\t\t     Please Try Again.\n\n";
            cout << "\t\t\t\t  =======================================================================================\n";

            do
            {
                cout << endl;
                cout << "\t\t\t\t     Enter 'Y' To Reverify, 'N' To Go Back To Login Menu.\n";
                cout << "\t\t\t\t     Your Selection: ";
                getline(cin, validation);
                system("cls");

                if (validation.length() == 1)
                {
                    choice = validation[0];

                    switch (choice)
                    {
                    case 'Y':
                    case 'y':
                        goto reverify;
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

    else
    {
        system("cls");
        cout << "\nError Message: Your Reentered Username Is Not Correct.";
        cout << "\nMake Sure Your Reentered Username Is The Same As The Confirmed Username You Want To Delete.";
        cout << "\nPlease Try Again.\n";

        do
        {
            cout << "\nEnter 'Y' To Reverify, 'N' To Go Back To Login Menu.";
            cout << "\nYour Selection: ";
            getline(cin, validation);
            system("cls");

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                    goto reverify;
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
                "\t\t\t\t     (2)  Delete An Account\n\n"
                "\t\t\t\t     (3)  Edit An Account\n\n"
                "\t\t\t\t     (4)  Display All Accounts\n\n"
                "\t\t\t\t     (5)  Search Account\n\n"
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
                obj.Admin_Add_Account();
                break;

            case '2':
                obj.Admin_Delete_Account();
                break;

            case '3':
                obj.Admin_Edit_Account();
                break;

            case '4':
                obj.Admin_Display_All_Accounts();
                break;

            case '5':
                obj.Admin_Search_Account();
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

// function to add a new customer's account
void a::Admin_Add_Account()
{
    string acc;
    string Pin;
    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  A D M I N _ S Y S T E M   : :                           \n"
            "\n";
    cout << "\t\t\t\t  Enter The Following Information\n";
    cout << "\n\t\t\t\t     Account Number (9 Digits): ";
    cin >> account;
    acc = to_string(account);

    // check if the inputted account number is a positive integer
    if (account < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Be A 9-digit Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Admin_Add_Account();
    }
    // check if the inputted account number is not an integer
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Admin_Add_Account();
    }

    // check if the account number already exists
    if (Customer_Account_Validation(account))
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number ALready Exists. \n\n"
                "\t\t\t\t   Please Try Another One.                                \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Admin_Add_Account();
    }

    // check if the inputted account number is 9-digit
    if (acc.length() != 9)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Contain 9 digits. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Admin_Add_Account();
    }

fname:
    cout << "\n\t\t\t\t     First Name: ";
    getline(cin, fname);

    // convert the first letter of the first name to uppercase
    fname[0] = toupper(fname[0]);

    for (char c : fname)
    {
        // check if there is any space
        if (isspace(c))
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Error Message: First Name Must Not Contain Space(s). \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            system("pause");
            system("cls");
            goto fname;
        }
        // check if it is not a character
        if (!isalpha(c))
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Error Message: First Name Must Be Characters. \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            system("pause");
            system("cls");
            goto fname;
        }
    }

lname:
    cout << "\n\t\t\t\t     Last Name: ";
    getline(cin, lname);

    // convert the first letter of last name to uppercase
    lname[0] = toupper(lname[0]);

    for (char c : lname)
    {
        // check if there is any space
        if (isspace(c))
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Error Message: Last Name Must Not Contain Space(s). \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            system("pause");
            system("cls");
            goto lname;
        }
        // check if it is not a character
        if (!isalpha(c))
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Error Message: Last Name Must Be Characters. \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            system("pause");
            system("cls");
            goto lname;
        }
    }

gender:
    cout << "\n\t\t\t\t     Gender (M or F): ";
    cin >> gender;
    //  check if the gender is not one character
    if (gender.length() != 1)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Gender Must Be Either M or F. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        goto gender;
    }
    // check if the inputted gender is neither M nor F
    if (!(gender[0] == 'F' || gender[0] == 'f' || gender[0] == 'M' || gender[0] == 'm'))
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Gender Must Be Either M or F.  \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        goto gender;
    }
    // convert gender to uppercase
    gender[0] = toupper(gender[0]);

DOB:
    cout << "\n\t\t\t\t     Date of Birth (DD MM YYYY): ";
    cin.ignore();
    getline(cin, DOB);

    // check if the inputted date of birth is not a number
    for (char c : DOB)
    {
        if (isalpha(c))
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            system("pause");
            system("cls");
            goto DOB;
        }
    }
    // check if the inputted date of birth is more than ten characters
    if (DOB.length() > 10)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Please Follow The Given Format. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        goto DOB;
    }

occupation:
    cout << "\n\t\t\t\t     Occupation: ";
    getline(cin, occupation);
    occupation[0] = toupper(occupation[0]);

    // check if the inputted occupation is alphabetic
    for (char c : occupation)
    {
        if (!isalpha(c) || !isspace(c))
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            system("pause");
            system("cls");
            goto occupation;
        }
    }

deposit:
    cout << "\n\t\t\t\t     Deposit($) : ";
    cin >> deposit;

    // check if the inputted deposit is a positive integer
    if (deposit < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Deposit Must Be A Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        goto deposit;
    }

    // check if the inputted deposit is number
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        goto deposit;
    }
    // check if the inputted deposit is more than 10 dollar
    if (deposit < 10)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: The Deposit Amount Must Not Be Less Than 10 Dollar. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        goto deposit;
    }

pin:
    cout << "\n\t\t\t\t     Pin (4 digits): ";
    cin >> pin;
    Pin = to_string(pin);

    // check if the inputted pin is a positive integer
    if (pin < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Pin Must Be A 4-digit Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        goto pin;
    }

    // check if the inputted are all numbers
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        goto pin;
    }
    // check if the inputted pin is a 4-digit number
    if (Pin.length() != 4)
    {

        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Pin Must Contain 4 digits. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        goto pin;
    }

    // divide string
    birthDate = stoi(DOB.substr(0, 2));
    birthMonth = stoi(DOB.substr(3, 2));
    birthYear = stoi(DOB.substr(6, 4));

    // write to information to Bank_Account.txt
    ofstream bank1("Bank_Account.txt", ios::app);
    bank1 << acc << endl;
    bank1 << fname << " " << lname << endl;
    bank1 << gender << endl;
    bank1 << birthDate << endl;
    bank1 << birthMonth << endl;
    bank1 << birthYear << endl;
    bank1 << occupation << endl;
    bank1 << deposit << endl;
    bank1 << pin << endl;
    bank1.close();
    cout << endl;
    cout << "\t\t\t\t     Account Is Added Successfully.\n\n";
    system("pause");
    cin.clear();
    cin.ignore(10000, '\n');
    system("cls");
    Admin_System();
}

// function to delete a customer's account
void a::Admin_Delete_Account()
{
    bool notFound = true;
    int find;
    string Find;
    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  A D M I N _ S Y S T E M   : :                           \n"
            "\n";
    cout << "\t\t\t\t  Enter Account Number You Want To Delete : ";
    cin >> find;
    Find = to_string(find);

    // check if the inputted find is a negative number
    if (find < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Be A 9-digit Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Delete_Account();
    }

    // check if the inputted find is a number
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Delete_Account();
    }

    // check if the inputted find is 9-digit
    if (Find.length() != 9)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Contain 9 digits. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Delete_Account();
    }

    ifstream bank2("Bank_Account.txt", ios::in);
    ofstream tempFile("temp.txt", ios::app);
    bank2 >> account;
    bank2.ignore();
    getline(bank2, name);
    bank2 >> gender;
    bank2 >> birthDate;
    bank2 >> birthMonth;
    bank2 >> birthYear;
    bank2.ignore();
    getline(bank2, occupation);
    bank2 >> balance;
    bank2 >> pin;

    while (!bank2.eof())
    {
        if (account != find)
        {
            tempFile << account << endl;
            tempFile << name << endl;
            tempFile << gender << endl;
            tempFile << birthDate << endl;
            tempFile << birthMonth << endl;
            tempFile << birthYear << endl;
            tempFile << occupation << endl;
            tempFile << balance << endl;
            tempFile << pin << endl;
        }
        else
        {
            notFound = false;
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Information Found: \n\n";
            cout << "\t\t\t\t   Account Number: " << account << "\n";
            cout << "\t\t\t\t   Card Holder:    " << name << "\n";
            cout << "\t\t\t\t   Gender:         " << gender << "\n";
            cout << "\t\t\t\t   Date Of Birth:  " << birthDate << " / " << month[birthMonth - 1] << " / " << birthYear << "\n";
            cout << "\t\t\t\t   Age:            " << age_conversion(birthDate, birthMonth, birthYear) << "\n ";
            cout << "\t\t\t\t   Occupation:     " << occupation << "\n";
            cout << "\t\t\t\t   Balance:        $" << balance << "\n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            cout << endl;
            cin.ignore();
        again:
            cin.clear();
            cout << "\t\t\t\t     Do You Want To Delete This Account Number '" << account << "'?\n\n";

            cout << "\t\t\t\t     Enter 'Y' To Confirm, 'N' To Cancel.\n";
            cout << "\t\t\t\t     Your Selection: ";
            // cin.ignore();
            getline(cin, validation);
            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                {
                    cout << endl;
                    cout << "\t\t\t\t     Account Is Deleted Successfully.\n\n";
                    break;
                }

                case 'N':
                case 'n':
                    tempFile << account << endl;
                    tempFile << name << endl;
                    tempFile << gender << endl;
                    tempFile << birthDate << endl;
                    tempFile << birthMonth << endl;
                    tempFile << birthYear << endl;
                    tempFile << occupation << endl;
                    tempFile << balance << endl;
                    tempFile << pin << endl;
                    cout << endl;
                    cout << "\t\t\t\t     Account Is Not Deleted.\n\n";
                    break;

                default:
                    cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                    system("pause");
                    system("cls");
                    goto again;
                    break;
                }
            }
            else
            {
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
                goto again;
                break;
            }
        }

        bank2 >> account;
        bank2.ignore();
        getline(bank2, name);
        bank2 >> gender;
        bank2 >> birthDate;
        bank2 >> birthMonth;
        bank2 >> birthYear;
        bank2.ignore();
        getline(bank2, occupation);
        bank2 >> balance;
        bank2 >> pin;
    }
    tempFile.close();
    bank2.close();
    remove("Bank_Account.txt");
    rename("temp.txt", "Bank_Account.txt");
    if (notFound)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   No Record Found. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
    }
    system("pause");
    // cin.clear();
    // cin.ignore(10000, '\n');
    system("cls");
    Admin_System();
}

// function to edit a customer's account
void a::Admin_Edit_Account()
{
    string newFname, newLname, newName, newDOB, newGender, newOccupation;
    int newBalance, newBirthDate, newBirthMonth, newBirthYear, newPin;
    bool notFound = true;

    int find;
    string Find;
    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  A D M I N _ S Y S T E M   : :                           \n"
            "\n";
    cout << "\t\t\t\t  Enter Account Number You Want To Edit: ";
    cin >> find;
    Find = to_string(find);

    // check if the inputted find is a positive integer
    if (find < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Be A 9-digit Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Edit_Account();
    }

    // check if the inputted find is a number
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Edit_Account();
    }
    // check if the inputted find is 9-digit
    if (Find.length() != 9)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Contain 9 Digits. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Edit_Account();
    }

    ifstream bank2("Bank_Account.txt", ios::in);
    ofstream tempFile("temp.txt", ios::app);
    bank2 >> account;
    bank2.ignore();
    getline(bank2, name);
    bank2 >> gender;
    bank2 >> birthDate;
    bank2 >> birthMonth;
    bank2 >> birthYear;
    bank2.ignore();
    getline(bank2, occupation);
    bank2 >> balance;
    bank2 >> pin;

    while (!bank2.eof())
    {
        // if account is not equal to find, write data in Bank_Account.txt
        if (account != find)
        {
            tempFile << account << endl;
            tempFile << name << endl;
            tempFile << gender << endl;
            tempFile << birthDate << endl;
            tempFile << birthMonth << endl;
            tempFile << birthYear << endl;
            tempFile << occupation << endl;
            tempFile << balance << endl;
            tempFile << pin << endl;
        }
        // if account is equal to find, display the info and allow user to enter new info
        else
        {
            notFound = false;
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Information Found: \n\n";
            cout << "\t\t\t\t   Account Number: " << account << "\n";
            cout << "\t\t\t\t   Card Holder:    " << name << "\n";
            cout << "\t\t\t\t   Gender:         " << gender << "\n";
            cout << "\t\t\t\t   Date Of Birth:  " << birthDate << " / " << month[birthMonth - 1] << " / " << birthYear << "\n";
            cout << "\t\t\t\t   Age:            " << age_conversion(birthDate, birthMonth, birthYear) << "\n ";
            cout << "\t\t\t\t   Occupation:     " << occupation << "\n";
            cout << "\t\t\t\t   Balance:        $" << balance << "\n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            cout << endl;
            cin.ignore();
        again:
            cin.clear();
            cout << "\t\t\t\t     Do You Want To Edit The Account Number '" << account << "'?\n\n";

            cout << "\t\t\t\t     Enter 'Y' To Confirm, 'N' To Cancel.\n";
            cout << "\t\t\t\t     Your Selection: ";
            getline(cin, validation);
            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                {
                    string Pin;
                    system("cls");
                    cout << "\t\t\t\t  =======================================================================================\n"
                            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
                            "\t\t\t\t  =======================================================================================\n"
                            "\n"
                            "\t\t\t\t                            : :  A D M I N _ S Y S T E M   : :                           \n"
                            "\n";
                    cout << "\t\t\t\t  Edit The Following Information\n";
                newFname:
                    cout << "\n\t\t\t\t     New First Name : ";
                    getline(cin, newFname);
                    // convert the first letter of the first name to uppercase
                    fname[0] = toupper(fname[0]);

                    for (char c : fname)
                    {
                        // check if there is any space
                        if (isspace(c))
                        {
                            cout << endl;
                            cout << "\t\t\t\t  =======================================================================================\n\n";

                            cout << "\t\t\t\t   Error Message: First Name Must Not Contain Space(s). \n\n";

                            cout << "\t\t\t\t  =======================================================================================\n\n";
                            system("pause");
                            system("cls");
                            goto newFname;
                        }
                        // check if it is not a character
                        if (!isalpha(c))
                        {
                            cout << endl;
                            cout << "\t\t\t\t  =======================================================================================\n\n";

                            cout << "\t\t\t\t   Error Message: First Name Must Be Characters. \n\n";

                            cout << "\t\t\t\t  =======================================================================================\n\n";
                            system("pause");
                            system("cls");
                            goto newFname;
                        }
                    }
                newLname:
                    cout << "\n\t\t\t\t     New Last Name : ";
                    getline(cin, newLname);
                    // Covert the first letter of last name to uppercase
                    newLname[0] = toupper(newLname[0]);

                    for (char c : newLname)
                    {
                        // check if there is any space
                        if (isspace(c))
                        {
                            cout << endl;
                            cout << "\t\t\t\t  =======================================================================================\n\n";

                            cout << "\t\t\t\t   Error Message: Last Name Must Not Contain Space. \n\n";

                            cout << "\t\t\t\t  =======================================================================================\n\n";
                            system("pause");
                            system("cls");
                            goto newLname;
                        }
                        // check if it's not a character
                        if (!isalpha(c))
                        {
                            cout << endl;
                            cout << "\t\t\t\t  =======================================================================================\n\n";

                            cout << "\t\t\t\t   Error Message: Last Name Must Be Characters. \n\n";

                            cout << "\t\t\t\t  =======================================================================================\n\n";
                            system("pause");
                            system("cls");
                            goto newLname;
                        }
                    }
                newGender:
                    cout << "\n\t\t\t\t     New Gender(M or F) : ";
                    cin >> newGender;
                    //  check if the gender is not 1 character
                    if (newGender.length() != 1)
                    {
                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Only M and F are accepted. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        cin.clear();
                        cin.ignore(10000, '\n');
                        system("cls");
                        goto newGender;
                    }
                    // check if the gender entered is not F or M then display the erro message
                    if (!(newGender[0] == 'F' || newGender[0] == 'f' || newGender[0] == 'M' || newGender[0] == 'm'))
                    {
                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Only M and F are accepted. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        cin.clear();
                        cin.ignore(10000, '\n');
                        system("cls");
                        goto newGender;
                    }
                    // Convert Gender to Uppercase
                    newGender[0] = toupper(newGender[0]);

                newDOB:
                    cout << "\n\t\t\t\t     Date of Birth(DD MM YYYY) : ";
                    cin.ignore();
                    getline(cin, newDOB);
                    // check if the date of birth entered is not digits
                    for (char c : newDOB)
                    {
                        if (isalpha(c))
                        {
                            cout << endl;
                            cout << "\t\t\t\t  =======================================================================================\n\n";

                            cout << "\t\t\t\t   Error Message: Must Contain Only Digits. \n\n";

                            cout << "\t\t\t\t  =======================================================================================\n\n";
                            system("pause");
                            system("cls");
                            goto newDOB;
                        }
                    }
                    // check if the date of birth entered is more than 10 numbers
                    if (newDOB.length() > 10)
                    {
                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Please Follow The Given Format. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        system("cls");
                        goto newDOB;
                    }

                newOccupation:
                    cout << "\n\t\t\t\t     Occupation : ";
                    getline(cin, newOccupation);
                    newOccupation[0] = toupper(newOccupation[0]);
                    // check if the occupation entered is characters
                    for (char c : newOccupation)
                    {
                        if (!isalpha(c))
                        {
                            cout << endl;
                            cout << "\t\t\t\t  =======================================================================================\n\n";

                            cout << "\t\t\t\t   Error Message: Must Contain Only Characters. \n\n";

                            cout << "\t\t\t\t  =======================================================================================\n\n";
                            system("pause");
                            system("cls");
                            goto newOccupation;
                        }
                    }

                newBalance:
                    cout << "\n\t\t\t\t     Deposit($) : ";
                    cin >> newBalance;
                    // check if the deposit entered is positive integer
                    if (newBalance < 0)
                    {
                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Pin Must Be A Positive Integer. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        cin.clear();
                        cin.ignore(10000, '\n');
                        system("cls");
                        goto newBalance;
                    }
                    // check if the deposit entered is number
                    if (cin.fail())
                    {
                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        cin.clear();
                        cin.ignore(10000, '\n');
                        system("cls");
                        goto newBalance;
                    }
                    // check if the deposit entered is more than 10 dollar
                    if (newBalance < 10)
                    {
                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Accept Only 10 Dollar or more. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        cin.clear();
                        cin.ignore(10000, '\n');
                        system("cls");
                        goto newBalance;
                    }
                newPin:
                    cout << "\n\t\t\t\t     Pin(4-digits) : ";
                    cin >> newPin;
                    Pin = to_string(newPin);
                    // check if the pin entered is positive integer
                    if (newPin < 0)
                    {
                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Pin Must Be A 4-digits Positive Integer. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        cin.clear();
                        cin.ignore(10000, '\n');
                        system("cls");
                        goto newPin;
                    }

                    // check if the pin entered if all digits
                    if (cin.fail())
                    {
                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        cin.clear();
                        cin.ignore(10000, '\n');
                        system("cls");
                        goto newPin;
                    }
                    // check if the pin entered is a 4-digits number
                    if (Pin.length() != 4)
                    {

                        cout << endl;
                        cout << "\t\t\t\t  =======================================================================================\n\n";

                        cout << "\t\t\t\t   Error Message: Pin Must Contain 4-digits. \n\n";

                        cout << "\t\t\t\t  =======================================================================================\n\n";
                        system("pause");
                        cin.clear();
                        cin.ignore(10000, '\n');
                        system("cls");
                        goto newPin;
                    }
                    // divide string
                    newBirthDate = stoi(newDOB.substr(0, 2));
                    newBirthMonth = stoi(newDOB.substr(3, 2));
                    newBirthYear = stoi(newDOB.substr(6, 4));

                    newName = newFname + " " + newLname;

                    tempFile << account << endl;
                    tempFile << newName << endl;
                    tempFile << newGender << endl;
                    tempFile << newBirthDate << endl;
                    tempFile << newBirthMonth << endl;
                    tempFile << newBirthYear << endl;
                    tempFile << newOccupation << endl;
                    tempFile << newBalance << endl;
                    tempFile << newPin << endl;
                    cout << endl;
                    cout << "\t\t\t\t     Account Is Edited Successfully.\n\n";
                    fflush(stdin);
                    break;
                }

                case 'N':
                case 'n':
                {
                    tempFile << account << endl;
                    tempFile << name << endl;
                    tempFile << gender << endl;
                    tempFile << birthDate << endl;
                    tempFile << birthMonth << endl;
                    tempFile << birthYear << endl;
                    tempFile << occupation << endl;
                    tempFile << balance << endl;
                    tempFile << pin << endl;
                    cout << endl;
                    cout << "\t\t\t\t     Account Is Not Edited.\n\n";
                    break;
                }

                default:
                {
                    cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                    system("pause");
                    system("cls");
                    goto again;
                    break;
                }
                }
            }
            else
            {
                cout << "\nError Message: Please Enter One Of The Available Options.\n\n";
                system("pause");
                system("cls");
                goto again;
                break;
            }
        }
        bank2 >> account;
        bank2.ignore();
        getline(bank2, name);
        bank2 >> gender;
        bank2 >> birthDate;
        bank2 >> birthMonth;
        bank2 >> birthYear;
        bank2.ignore();
        getline(bank2, occupation);
        bank2 >> balance;
        bank2 >> pin;
    }
    tempFile.close();
    bank2.close();
    remove("Bank_Account.txt");
    rename("temp.txt", "Bank_Account.txt");
    if (notFound)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   No Record Found. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
    }
    system("pause");
    system("cls");
    Admin_System();
}

// function to display all of customer accounts
void a::Admin_Display_All_Accounts()
{
    string Account, Balance, BirthDate, BirthYear, Pin;
    i = 0;
    ifstream bank2("Bank_Account.txt", ios::in);
    bank2 >> account;
    bank2.ignore();
    getline(bank2, name);
    bank2 >> gender;
    bank2 >> birthDate;
    bank2 >> birthMonth;
    bank2 >> birthYear;
    bank2.ignore();
    getline(bank2, occupation);
    bank2 >> balance;
    bank2 >> pin;

    cout << setw(90) << setfill(' ') << "+  Customer Accounts  +" << setw(75) << endl
         << endl;
    cout << setw(175) << setfill('-') << "" << endl;
    cout << "|" << setw(5) << setfill(' ') << "No." << setw(3) << setfill(' ');
    cout << "|" << setw(19) << setfill(' ') << "Account Number" << setw(5);
    cout << "|" << setw(19) << setfill(' ') << "Card Holder" << setw(8);
    cout << "|" << setw(9) << setfill(' ') << "Gender" << setw(3);
    cout << "|" << setw(17) << setfill(' ') << "Date Of Birth" << setw(5);
    cout << "|" << setw(8) << setfill(' ') << "Age" << setw(5);
    cout << "|" << setw(20) << setfill(' ') << "Occupation" << setw(12);
    cout << "|" << setw(16) << setfill(' ') << "Balance" << setw(9);
    cout << "|" << setw(6) << setfill(' ') << "Pin" << setw(5) << "|" << endl;

    while (!bank2.eof())
    {
        Account = to_string(account);
        Balance = to_string(balance);
        Pin = to_string(pin);
        BirthDate = to_string(birthDate);
        BirthYear = to_string(birthYear);
        string dob = BirthDate + " " + month[birthMonth - 1] + " " + BirthYear;
        int space_account = 23 - Account.length();
        int internal_account = space_account / 2;

        int space_fullname = 27 - name.length();
        int internal_fullname = space_fullname / 2;

        int space_dob = 22 - dob.length();
        int internal_dob = space_dob / 2;

        int space_occupation = 32 - occupation.length();
        int internal_occupation = space_occupation / 2;

        int space_balance = 25 - Balance.length();
        int internal_balance = space_balance / 2;

        cout << setw(175) << setfill('-') << "" << endl;
        cout << "|" << setw(4) << setfill(' ') << i + 1 << setw(4) << setfill(' ') << "|";
        cout << setw(internal_account + Account.length()) << account << setw(24 - (internal_account + Account.length())) << "|";
        cout << setw(internal_fullname + name.length()) << name << setw(27 - (internal_fullname + name.length())) << "|";
        cout << setw(6) << gender << setw(6) << "|";
        cout << setw(internal_dob + dob.length()) << dob << setw(22 - (internal_dob + dob.length())) << "|";
        cout << setw(7) << age_conversion(birthDate, birthMonth, birthYear) << setw(6) << "|";
        cout << setw(internal_occupation + occupation.length()) << occupation << setw(32 - (internal_occupation + occupation.length())) << "|";
        cout << setw(internal_balance + Balance.length() - 2) << fixed << setprecision(2) << balance << setw(27 - (internal_balance + Balance.length())) << "|";
        cout << setw(7) << pin << setw(4) << "|";
        cout << endl;
        i++;

        bank2 >> account;
        bank2.ignore();
        getline(bank2, name);
        bank2 >> gender;
        bank2 >> birthDate;
        bank2 >> birthMonth;
        bank2 >> birthYear;
        bank2.ignore();
        getline(bank2, occupation);
        bank2 >> balance;
        bank2 >> pin;
    }
    cout << setw(175) << setfill('-') << "" << endl;
    bank2.close();
    system("pause");
    system("cls");
    Admin_System();
}

// function to search for a customer account
void a::Admin_Search_Account()
{
    int targettedAcc;
    bool notFound = true;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  A D M I N _ S Y S T E M   : :                           \n"
            "\n"
            "\n\t\t\t\t  Enter Account Number You Want To Search: ";
    cin >> targettedAcc;
    string find = to_string(targettedAcc);

    // check if the inputted find is a negative number
    if (targettedAcc < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Be A 9-digit Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Search_Account();
    }

    // check if the inputted find is a number
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Search_Account();
    }

    // check if the inputted find is 9-digit
    if (find.length() != 9)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Contain 9 digits. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        system("pause");
        system("cls");
        Admin_Search_Account();
    }

    ifstream bank2("Bank_Account.txt", ios::in);

    while (!bank2.eof())
    {
        bank2 >> account;
        bank2.ignore();
        getline(bank2, name);
        bank2 >> gender;
        bank2 >> birthDate;
        bank2 >> birthMonth;
        bank2 >> birthYear;
        bank2.ignore();
        getline(bank2, occupation);
        bank2 >> balance;
        bank2 >> pin;

        if (targettedAcc == account)
        {
            notFound = false;

            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Information Found: \n\n";
            cout << "\t\t\t\t   Account Number: " << account << "\n";
            cout << "\t\t\t\t   Card Holder:    " << name << "\n";
            cout << "\t\t\t\t   Gender:         " << gender << "\n";
            cout << "\t\t\t\t   Date Of Birth:  " << birthDate << " / " << month[birthMonth - 1] << " / " << birthYear << "\n";
            cout << "\t\t\t\t   Age:            " << age_conversion(birthDate, birthMonth, birthYear) << "\n ";
            cout << "\t\t\t\t   Occupation:     " << occupation << "\n";
            cout << "\t\t\t\t   Balance:        $" << balance << "\n";
            cout << "\t\t\t\t   Pin:            " << pin << "\n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";

            break;
        }
    }

    if (notFound)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   No Record Found. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
    }

    bank2.close();

    system("pause");
    cin.clear();
    cin.ignore(10000, '\n');
    Customer_System();
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
                "\t\t\t\t     (3)   Delete Your Registered Username And Password\n\n"
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

            case '3':
                Customer_Delete();
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
            cout << "\nError Message: Username Must Not Contain Space(s).";
            cout << "\nPlease Try Again.\n\n";
            system("pause");
            Customer_Login_System();
        }
    }

    cout << "\t\t\t\t     Password: ";
    getline(cin, inputPW);

    ifstream CustomerInfo("Customer_Account.txt", ios::in);

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
        cout << "\nError Message: Username And Password Do Not Match.";
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
            cout << "\nError Message: Username Must Not Contain Space(s).";
            cout << "\nPlease Try Again.\n\n";
            system("pause");
            Customer_Register_System();
        }
    }

    // check if there is a repeated username
    if (!(Customer_Username_Validation(inputUSN)))
    {
        system("cls");
        cout << "\nError Message: Username Already Exists.";
        cout << "\nPlease Try A Different One.\n\n";
        system("pause");
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

// function to check if the inputted customer's username exists
bool Customer_Username_Validation(string inputUSN)
{
    bool newUSN = true;
    string existedInfo, existedUSN, existedPW;

    ifstream CustomerInfo("Customer_Account.txt", ios::in);

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

// function to delete a customer's registered username and password
void Customer_Delete()
{
    system("cls");

    string targetedInfo;
    string existedInfo, existedUSN, existedPW;
    vector<string> newInfo;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Deleting Your Account\n\n";

    cout << "\t\t\t\t     Enter Your Username To Delete Your Account: ";
    getline(cin, targetedInfo);

    // check if there is a space in the inputted username
    for (char c : targetedInfo)
    {
        if (isspace(c))
        {
            system("cls");
            cout << "\nError Message: Username Must Not Contain Space(s).";
            cout << "\nPlease Try Again.\n\n";
            system("pause");
            Customer_Delete();
        }
    }

    if (!(Customer_Username_Validation(targetedInfo)))
    {
        do
        {
            cout << endl;
            cout << "\t\t\t\t     Do You Want To Delete The Account With The Username '" << targetedInfo << "'?\n\n";
            cout << "\t\t\t\t     Enter 'Y' To Confirm, 'N' To Cancel.\n";
            cout << "\t\t\t\t     Your Selection: ";

            getline(cin, validation);

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                {
                    // ask the user to reverify themself
                    Customer_Verification(targetedInfo);

                    ifstream CustomerInfo("Customer_Account.txt", ios::in); // for reading all existed information
                    ofstream tempFile("temp.txt", ios::app);                // for writing needed information

                    while (getline(CustomerInfo, existedInfo))
                    {
                        // write all the existed information in file into the vector
                        newInfo.push_back(existedInfo);

                        // split username from password
                        string::size_type pos;
                        pos = existedInfo.find(' ', 0);
                        existedUSN = existedInfo.substr(0, pos);
                        existedPW = existedInfo.substr(pos + 1);

                        if (targetedInfo == existedUSN)
                        {
                            // deleted information that is not needed
                            newInfo.pop_back();
                        }
                        else if (targetedInfo != existedUSN)
                        {
                            // keep the existed information inside the vector and add an endline after each vector's element
                            newInfo.push_back("\n");
                        }
                    }

                    // write the needed information into a temporary file
                    for (int i = 0; i < newInfo.size(); i++)
                    {
                        tempFile << newInfo[i];
                    }

                    CustomerInfo.close();
                    tempFile.close();

                    remove("Customer_Account.txt");
                    rename("temp.txt", "Customer_Account.txt");

                    cout << endl;
                    cout << "\t\t\t\t     Account Is Deleted Successfully.\n\n";
                    system("pause");
                    Customer_Login_Menu();
                }

                case 'N':
                case 'n':
                    cout << endl;
                    cout << "\t\t\t\t     Account Is Not Deleted.\n\n";
                    system("pause");
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
    else if (Customer_Username_Validation(targetedInfo))
    {
        system("cls");

        cout << "\t\t\t\t     Error Message: Account Is Not Found.\n";
        cout << "\t\t\t\t     Please Check Your Username And Try Again.\n\n";

        do
        {
            cout << "\t\t\t\t     Enter 'Y' To Try Again, 'N' To Go Back To Login Menu.\n";
            cout << "\t\t\t\t     Your Selection: ";
            getline(cin, validation);
            system("cls");

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                    Customer_Delete();
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

// function to verify a customer's identity before deleting their account
void Customer_Verification(string targetedInfo)
{
reverify:

    bool verification = false;
    string inputUSN, inputPW, existedInfo, existedUSN, existedPW;

    cout << endl;
    cout << "\t\t\t\t  =======================================================================================\n\n";
    cout << "\t\t\t\t     For Security Purpose, Please Retype Your Username And Enter Your Password.\n\n";
    cout << "\t\t\t\t     Username: ";
    getline(cin, inputUSN);

    // check if there is a space in the inputted username
    for (char c : inputUSN)
    {
        if (isspace(c))
        {
            system("cls");
            cout << "\nError Message: Username Must Not Contain Space(s).";
            cout << "\nPlease Try Again.\n\n";
            system("pause");
            system("cls");
            goto reverify;
        }
    }

    // conditions to check if the reentered username matches
    if (inputUSN == targetedInfo)
    {
        cout << "\t\t\t\t     Password: ";
        getline(cin, inputPW);

        ifstream CustomerInfo("Customer_Account.txt", ios::in);

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
                    verification = true;
                    system("cls");
                }
            }
        }

        CustomerInfo.close();

        if (verification)
        {
            cout << "\t\t\t\t  =======================================================================================\n";
            // return back to the delete function
        }
        else
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";
            cout << "\t\t\t\t     Error Message: Username And Password Do Not Match.\n";
            cout << "\t\t\t\t     Please Try Again.\n\n";
            cout << "\t\t\t\t  =======================================================================================\n";

            do
            {
                cout << endl;
                cout << "\t\t\t\t     Enter 'Y' To Reverify, 'N' To Go Back To Login Menu.\n";
                cout << "\t\t\t\t     Your Selection: ";
                getline(cin, validation);
                system("cls");

                if (validation.length() == 1)
                {
                    choice = validation[0];

                    switch (choice)
                    {
                    case 'Y':
                    case 'y':
                        goto reverify;
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

    else
    {
        system("cls");
        cout << "\nError Message: Your Reentered Username Is Not Correct.";
        cout << "\nMake Sure Your Reentered Username Is The Same As The Confirmed Username You Want To Delete.";
        cout << "\nPlease Try Again.\n";

        do
        {
            cout << "\nEnter 'Y' To Reverify, 'N' To Go Back To Login Menu.";
            cout << "\nYour Selection: ";
            getline(cin, validation);
            system("cls");

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                    goto reverify;
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

// function to display all the privileges that a customer has on the program
void Customer_System()
{
    system("cls");

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
                "\t\t\t\t     (2)  Make A Transaction\n\n"
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
                obj.Customer_View_Details();
                break;

            case '2':
                obj.Customer_Make_Transaction();
                break;

            case '3':
                obj.Customer_Transaction_History();
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

// function for a customer to display their own account details
void a::Customer_View_Details()
{
    int targetedAcc;
    bool notFound = true;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                          : :  C U S T O M E R _ S Y S T E M   : :                       \n"
            "\n"
            "\n\t\t\t\t  Enter Your Account Number: ";
    cin >> targetedAcc;

    // check if the account number entered is positive integer
    if (targetedAcc < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Be A 9-digits Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Admin_Add_Account();
    }
    // check if the account number entered is not digits
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Admin_Add_Account();
    }

    string acc = to_string(targetedAcc);

    // check if the account number entered is 9-digits
    if (acc.length() != 9)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Contain 9-digits. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Admin_Add_Account();
    }

    ifstream bank1("Bank_Account.txt", ios::in);

    while (!bank1.eof())
    {
        bank1 >> account;
        bank1.ignore();
        getline(bank1, name);
        bank1 >> gender;
        bank1 >> birthDate;
        bank1 >> birthMonth;
        bank1 >> birthYear;
        bank1.ignore();
        getline(bank1, occupation);
        bank1 >> balance;
        bank1 >> pin;

        if (targetedAcc == account)
        {
            notFound = false;

            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Your Account Information: \n\n";
            cout << "\t\t\t\t   Account Number: " << account << "\n";
            cout << "\t\t\t\t   Card Holder:    " << name << "\n";
            cout << "\t\t\t\t   Gender:         " << gender << "\n";
            cout << "\t\t\t\t   Date Of Birth:  " << birthDate << " / " << month[birthMonth - 1] << " / " << birthYear << "\n";
            cout << "\t\t\t\t   Age:            " << age_conversion(birthDate, birthMonth, birthYear) << "\n ";
            cout << "\t\t\t\t   Occupation:     " << occupation << "\n";
            cout << "\t\t\t\t   Balance:        $" << balance << "\n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";

            break;
        }
    }

    if (notFound)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   No Record Found. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
    }

    bank1.close();

    system("pause");
    cin.clear();
    cin.ignore(10000, '\n');
    Customer_System();
}

// function for a customer to transfer money to a different account
void a::Customer_Make_Transaction()
{
    int fromAcc, toAcc;
    float amountTransfer, fromAmount, toAmount;
    string fromName, toName;

    cout
        << "\t\t\t\t  =======================================================================================\n"
           "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
           "\t\t\t\t  =======================================================================================\n"
           "\n"
           "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
           "\n"
           "\t\t\t\t     Making A Transaction\n\n";
    cout << "\t\t\t\t     Enter Your Account Number: ";
    cin >> fromAcc;

    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";

        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        Customer_Make_Transaction();
    }

    if (Customer_Account_Validation(fromAcc))
    {
    back1:
        cout << "\t\t\t\t     Transfer To (Account Number): ";
        cin >> toAcc;
        if (cin.fail())
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";

            system("pause");
            cin.clear();
            cin.ignore(10000, '\n');
            system("cls");
            goto back1;
        }

        if (Customer_Account_Validation(toAcc))
        {
        back2:
            cout << "\t\t\t\t     Enter The Amount You Want To Transfer ($): ";
            cin >> amountTransfer;

            if (cin.fail())
            {
                cout << endl;
                cout << "\t\t\t\t  =======================================================================================\n\n";

                cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

                cout << "\t\t\t\t  =======================================================================================\n\n";

                system("pause");
                cin.clear();
                cin.ignore(10000, '\n');
                system("cls");
                goto back2;
            }

            if (Customer_Balance_Validation(fromAcc, amountTransfer))
            {
                ifstream bank2("Bank_Account.txt", ios::in);

                if (bank2.is_open())
                {
                    bank2 >> account;
                    bank2.ignore();
                    getline(bank2, name);
                    bank2 >> gender;
                    bank2 >> birthDate;
                    bank2 >> birthMonth;
                    bank2 >> birthYear;
                    bank2.ignore();
                    getline(bank2, occupation);
                    bank2 >> balance;
                    bank2 >> pin;

                    while (!bank2.eof())
                    {
                        if (fromAcc == account)
                        {
                            fromName = name;
                        }

                        if (toAcc == account)
                        {
                            toName = name;
                        }

                        bank2 >> account;
                        bank2.ignore();
                        getline(bank2, name);
                        bank2 >> gender;
                        bank2 >> birthDate;
                        bank2 >> birthMonth;
                        bank2 >> birthYear;
                        bank2.ignore();
                        getline(bank2, occupation);
                        bank2 >> balance;
                        bank2 >> pin;
                    }
                }

                bank2.close();

                do
                {
                    cout << "\n\t\t\t\t  Confirming Your Transaction:\n";
                    cout << "\n\t\t\t\t  " << fromName << " (" << fromAcc << ") Is About To Transfer $" << amountTransfer << " To " << toName << " (" << toAcc << ").";
                    cout << "\n\t\t\t\t  Enter 'Y' To Confirm, 'N' To Cancel Your Transaction.";
                    cout << "\n\t\t\t\t  Your Selection: ";
                    getline(cin, validation);

                    if (validation.length() == 1)
                    {
                        choice = validation[0];

                        switch (choice)
                        {
                        case 'Y':
                        case 'y':
                            system("cls");
                            Customer_PIN_Verification(fromAcc);
                            goto proceed;
                            break;

                        case 'N':
                        case 'n':
                            cout << "\n\t\t\t\t  Transaction Cancelled.\n\n";
                            system("pause");
                            system("cls");
                            Customer_System();
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

            proceed:

                ifstream bank3("Bank_Account.txt", ios::in);
                ofstream tempFile("temp.txt", ios::app);

                if (bank3.is_open())
                {
                    bank3 >> account;
                    bank3.ignore();
                    getline(bank3, name);
                    bank3 >> gender;
                    bank3 >> birthDate;
                    bank3 >> birthMonth;
                    bank3 >> birthYear;
                    bank3.ignore();
                    getline(bank3, occupation);
                    bank3 >> balance;
                    bank3 >> pin;

                    while (!bank3.eof())
                    {
                        if (fromAcc == account)
                        {
                            fromAmount = balance - amountTransfer;
                            tempFile << account << endl;
                            tempFile << name << endl;
                            tempFile << gender << endl;
                            tempFile << birthDate << endl;
                            tempFile << birthMonth << endl;
                            tempFile << birthYear << endl;
                            tempFile << occupation << endl;
                            tempFile << fromAmount << endl;
                            tempFile << pin << endl;
                        }

                        if (toAcc == account)
                        {
                            toAmount = balance + amountTransfer;
                            tempFile << account << endl;
                            tempFile << name << endl;
                            tempFile << gender << endl;
                            tempFile << birthDate << endl;
                            tempFile << birthMonth << endl;
                            tempFile << birthYear << endl;
                            tempFile << occupation << endl;
                            tempFile << toAmount << endl;
                            tempFile << pin << endl;
                        }

                        if (toAcc != account && fromAcc != account)
                        {
                            tempFile << account << endl;
                            tempFile << name << endl;
                            tempFile << gender << endl;
                            tempFile << birthDate << endl;
                            tempFile << birthMonth << endl;
                            tempFile << birthYear << endl;
                            tempFile << occupation << endl;
                            tempFile << balance << endl;
                            tempFile << pin << endl;
                        }

                        bank3 >> account;
                        bank3.ignore();
                        getline(bank3, name);
                        bank3 >> gender;
                        bank3 >> birthDate;
                        bank3 >> birthMonth;
                        bank3 >> birthYear;
                        bank3.ignore();
                        getline(bank3, occupation);
                        bank3 >> balance;
                        bank3 >> pin;
                    }
                }

                tempFile.close();
                bank3.close();

                remove("Bank_Account.txt");
                rename("temp.txt", "Bank_Account.txt");

                // current date/time based on current system
                time_t now = time(0);

                // convert now to string form
                char *dt = ctime(&now);

                ofstream transactionFile("Transaction.txt", ios::app);
                transactionFile << fromAcc << endl;
                transactionFile << fromName << endl;
                transactionFile << toAcc << endl;
                transactionFile << toName << endl;
                transactionFile << amountTransfer << endl;
                transactionFile << dt;
                transactionFile.close();

                cout << endl;
                cout << "\t\t\t\t  =======================================================================================\n\n";

                cout << "\t\t\t\t   Transaction Is Completed. \n\n";

                cout << "\t\t\t\t  =======================================================================================\n\n";
                system("pause");
                cin.clear();
                cin.ignore(10000, '\n');
                system("cls");
            }

            else
            {
                cout << endl;
                cout << "\t\t\t\t  =======================================================================================\n\n";

                cout << "\t\t\t\t   You Do Not Have Enough Balance To Make This Transaction. \n\n";
                cout << "\t\t\t\t   Please Reenter The Amount. \n\n";

                cout << "\t\t\t\t  =======================================================================================\n\n";

                do
                {
                    cout << "\n\t\t\t\t  Enter 'Y' To Try Again, 'N' To Go Back To Customer Menu.";
                    cout << "\n\t\t\t\t  Your Selection: ";
                    getline(cin, validation);
                    system("cls");

                    if (validation.length() == 1)
                    {
                        choice = validation[0];

                        switch (choice)
                        {
                        case 'Y':
                        case 'y':
                            goto back2;
                            break;

                        case 'N':
                        case 'n':
                            Customer_System();
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
        else
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Account Does Not Exist. \n\n";
            cout << "\t\t\t\t   Please Try Again. \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";

            do
            {
                cout << "\n\t\t\t\t  Enter 'Y' To Try Again, 'N' To Go Back To Customer Menu.";
                cout << "\n\t\t\t\t  Your Selection: ";
                getline(cin, validation);
                system("cls");

                if (validation.length() == 1)
                {
                    choice = validation[0];

                    switch (choice)
                    {
                    case 'Y':
                    case 'y':
                        goto back1;
                        break;

                    case 'N':
                    case 'n':
                        Customer_System();
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
    else
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Account Does Not Exist. \n\n";
        cout << "\t\t\t\t   Please Try Again. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";

        do
        {
            cout << "\n\t\t\t\t  Enter 'Y' To Try Again, 'N' To Go Back To Customer Menu.";
            cout << "\n\t\t\t\t  Your Selection: ";
            getline(cin, validation);
            system("cls");

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                    Customer_Make_Transaction();
                    break;

                case 'N':
                case 'n':
                    Customer_System();
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

// function to check if an account exists
bool a::Customer_Account_Validation(int targetedAcc)
{
    bool found = false;

    ifstream bank2("Bank_Account.txt", ios::in);

    if (bank2.is_open())
    {
        while (!bank2.eof())
        {
            bank2 >> account;
            bank2.ignore();
            getline(bank2, name);
            bank2 >> gender;
            bank2 >> birthDate;
            bank2 >> birthMonth;
            bank2 >> birthYear;
            bank2.ignore();
            getline(bank2, occupation);
            bank2 >> balance;
            bank2 >> pin;

            if (targetedAcc == account)
            {
                found = true;
            }
        }
    }

    bank2.close();

    cin.clear();
    cin.ignore(10000, '\n');

    return found;
}

// function to check a user's balance before making a transaction
bool a::Customer_Balance_Validation(int fromAcc, float amountTransfer)
{
    bool validBalance = false;

    ifstream bank2("Bank_Account.txt", ios::in);

    if (bank2.is_open())
    {
        while (!bank2.eof())
        {
            bank2 >> account;
            bank2.ignore();
            getline(bank2, name);
            bank2 >> gender;
            bank2 >> birthDate;
            bank2 >> birthMonth;
            bank2 >> birthYear;
            bank2.ignore();
            getline(bank2, occupation);
            bank2 >> balance;
            bank2 >> pin;

            if (fromAcc == account)
            {
                if (amountTransfer <= balance)
                {
                    validBalance = true;
                }
            }
        }
    }

    bank2.close();

    cin.clear();
    cin.ignore(10000, '\n');

    return validBalance;
}

// function to check customer's PIN code before making a transaction
void a::Customer_PIN_Verification(int fromAcc)
{
    int existedPIN, inputPIN;
    int i = 0;

pin:
    cout << "\n\t\t\t\t  Please Enter Your PIN Code: ";
    cin >> inputPIN;

    // check if the pin entered is positive integer
    if (inputPIN < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Pin Must Be A 4-digits Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        goto pin;
    }

    // check if the pin entered if all digits
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        goto pin;
    }

    string Pin = to_string(inputPIN);

    // check if the pin entered is a 4-digits number
    if (Pin.length() != 4)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Pin Must Contain 4-digits. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");
        goto pin;
    }

    ifstream bank2("Bank_Account.txt", ios::in);

    if (bank2.is_open())
    {
        bank2 >> account;
        bank2.ignore();
        getline(bank2, name);
        bank2 >> gender;
        bank2 >> birthDate;
        bank2 >> birthMonth;
        bank2 >> birthYear;
        bank2.ignore();
        getline(bank2, occupation);
        bank2 >> balance;
        bank2 >> pin;

        while (!bank2.eof())
        {
            if (fromAcc == account)
            {
                existedPIN = pin;
            }

            bank2 >> account;
            bank2.ignore();
            getline(bank2, name);
            bank2 >> gender;
            bank2 >> birthDate;
            bank2 >> birthMonth;
            bank2 >> birthYear;
            bank2.ignore();
            getline(bank2, occupation);
            bank2 >> balance;
            bank2 >> pin;
        }
    }

    bank2.close();

    if (inputPIN != existedPIN)
    {
        i++;
        cout << i << endl;
        if (i == 3)
        {
            cout << endl;
            cout << "\t\t\t\t  =======================================================================================\n\n";

            cout << "\t\t\t\t   Error Message: Your Transaction Failed. \n\n";

            cout << "\t\t\t\t  =======================================================================================\n\n";
            system("pause");
            fflush(stdin);
            system("cls");
            Customer_System();
        }

        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Your Pin Code Is Incorrect. \n";
        cout << "\t\t\t\t   Please Try Again. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";

        system("pause");
        cin.clear();
        cin.ignore(10000, '\n');
        system("cls");

        do
        {
            cout << "\n\t\t\t\t  Enter 'Y' To Try Again, 'N' To Go Back To Customer Menu.";
            cout << "\n\t\t\t\t  Your Selection: ";
            getline(cin, validation);
            system("cls");

            if (validation.length() == 1)
            {
                choice = validation[0];

                switch (choice)
                {
                case 'Y':
                case 'y':
                    goto pin;
                    break;

                case 'N':
                case 'n':
                    Customer_System();
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

// function for a customer to view their transaction history
void a::Customer_Transaction_History()
{
    int targetedAcc;
    bool notFound = true;
    int accTransferred, accReceived;
    float amountTransferred;
    string fromAcc, fromName, AmountTransferred, toAcc, toName, date;
    int i = 0;

    cout
        << "\t\t\t\t  =======================================================================================\n"
           "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
           "\t\t\t\t  =======================================================================================\n"
           "\n"
           "\t\t\t\t                          : :  C U S T O M E R _ S Y S T E M   : :                       \n"
           "\n"
           "\n\t\t\t\t  Enter Your Account Number: ";
    cin >> targetedAcc;

    // check if the account number entered is positive integer
    if (targetedAcc < 0)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Be A 9-digits Positive Integer. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Customer_Transaction_History();
    }
    // check if the account number entered is not digits
    if (cin.fail())
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Invalid Input. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Customer_Transaction_History();
    }

    string acc = to_string(targetedAcc);

    // check if the account number entered is 9-digits
    if (acc.length() != 9)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   Error Message: Account Number Must Contain 9-digits. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
        system("pause");
        system("cls");
        Customer_Transaction_History();
    }

    ifstream bank1("Transaction.txt", ios::in);

    bank1 >> accTransferred;
    bank1.ignore();
    getline(bank1, fromName);
    bank1 >> accReceived;
    bank1.ignore();
    getline(bank1, toName);
    bank1 >> amountTransferred;
    bank1.ignore();
    getline(bank1, date);

    cout << endl;
    cout << setw(95) << right << "+  Your Transaction History  +" << setw(80) << endl
         << endl;
    cout << setw(171) << setfill('-') << "" << endl;
    cout << "|" << setw(5) << setfill(' ') << "No." << setw(3) << setfill(' ');
    cout << "|" << setw(33) << setfill(' ') << "Account Transferred" << setw(14);
    cout << "|" << setw(33) << setfill(' ') << "Account Received" << setw(17);
    cout << "|" << setw(28) << setfill(' ') << "Date & Time" << setw(17);
    cout << "|" << setw(13) << setfill(' ') << "Amount" << setw(7) << "|" << endl;

    while (!bank1.eof())
    {
        fromName = '(' + fromName + ')';
        toName = '(' + toName + ')';
        fromAcc = to_string(accTransferred) + ' ' + fromName;
        toAcc = to_string(accReceived) + ' ' + toName;

        int space_fromAcc = 47 - fromAcc.length();
        int internal_fromAcc = space_fromAcc / 2;

        int space_toAcc = 50 - toAcc.length();
        int internal_toAcc = space_toAcc / 2;

        int space_date = 45 - date.length();
        int internal_date = space_date / 2;

        int space_amount = 20 - AmountTransferred.length();
        int internal_amount = space_amount / 2;

        if (targetedAcc == accTransferred || targetedAcc == accReceived)
        {
            notFound = false;

            cout << setw(171) << setfill('-') << "" << endl;
            cout << "|" << setw(4) << setfill(' ') << i + 1 << setw(4) << setfill(' ') << "|";
            cout << setw(internal_fromAcc + fromAcc.length()) << fromAcc << setw(47 - (internal_fromAcc + fromAcc.length())) << "|";
            cout << setw(internal_toAcc + toAcc.length()) << toAcc << setw(50 - (internal_toAcc + toAcc.length())) << "|";
            cout << setw(internal_date + date.length()) << date << setw(45 - (internal_date + date.length())) << "|";
            cout << setw(internal_amount + AmountTransferred.length() + 3) << fixed << setprecision(2) << amountTransferred << setw(17 - (internal_amount + AmountTransferred.length())) << "|";
            cout << endl;
            i++;
        }

        bank1 >> accTransferred;
        bank1.ignore();
        getline(bank1, fromName);
        bank1 >> accReceived;
        bank1.ignore();
        getline(bank1, toName);
        bank1 >> amountTransferred;
        bank1.ignore();
        getline(bank1, date);
    }
    cout << setw(171) << setfill('-') << "" << endl;
    if (notFound)
    {
        cout << endl;
        cout << "\t\t\t\t  =======================================================================================\n\n";

        cout << "\t\t\t\t   No Record Found. \n\n";

        cout << "\t\t\t\t  =======================================================================================\n\n";
    }

    bank1.close();

    cout << endl
         << endl;
    system("pause");
    cin.clear();
    cin.ignore(10000, '\n');
    Customer_System();
}
