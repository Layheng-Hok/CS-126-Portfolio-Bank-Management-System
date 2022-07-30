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

                break;

            case '2':

                break;

            case '3':

                break;

            case '4':

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
                "\t\t\t\t     (2)   Register As Customer\n\n"
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
        ostream_iterator<string> out_iterator2(CregInfo);
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
                "\t\t\t\t                            : :  A D M I N _ S Y S T E M   : :                           \n"
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

            case '4':

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