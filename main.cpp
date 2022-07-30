#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>

using namespace std;

// function declaration
void Admin_Login_Menu();
void Admin_Login_System();
void Admin_Register_System();
bool Admin_Username_Validation(string AregUSN);
void Admin_System();

void Customer_Login_Menu();
void Customer_Login_System();
void Customer_Register_System();
bool Customer_Username_Validation(string CregUSN);
void Customer_System();

void printTable();

// global variables
char choice;
string validation;

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
                cout << "< You Have Successfully Logged Out Of The System. >\n"
                     << "< Thank You And Please Visit Us Again! >\n"
                     << "< Program Was Created by Layheng Hok & Lyyou Heng from Paragon International University. >\n";

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
                cout << "Please Log In" << endl;
                Admin_Login_System();
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

void Admin_Login_System()
{
    system("cls");

    bool stageAdmin = false;
    string AdminUSN, AdminPW, existedInfo, existedUSN, existedPW;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Please Enter The Following Details:\n\n";
    cout << "\t\t\t\t     Username: ";
    getline(cin, AdminUSN);
    for (char c : AdminUSN)
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
    getline(cin, AdminPW);

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

            if (AdminUSN == existedUSN && AdminPW == existedPW)
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
        cout << "\t\t\t\t   Greeting, " << AdminUSN << ".\n\n";
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

void Admin_Register_System()
{
    system("cls");

    string AregUSN, AregPW;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Registering As An Admin\n\n";

    cout << "\t\t\t\t     Enter Your New Username: ";
    getline(cin, AregUSN);
    for (char c : AregUSN)
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
    if (!(Admin_Username_Validation(AregUSN)))
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
    getline(cin, AregPW);

    ofstream AregInfo("Admin_Account.txt", ios::app);

    if (AregInfo.is_open())
    {
        AregInfo << AregUSN << ' ' << AregPW << endl;
    }

    AregInfo.close();

    system("cls");

    cout << "\nRegistered Successfully.\n\n";
    system("pause");
    Admin_Login_Menu();
}

bool Admin_Username_Validation(string AregUSN)
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

            if ((AregUSN == existedUSN && AregUSN == existedPW) || (AregUSN == existedUSN && AregUSN != existedPW))
            {
                newUSN = false;
                system("cls");
            }
        }
    }

    AdminInfo.close();

    return newUSN;
}

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
                "\t\t\t\t     (2)   Register A Customer\n\n"
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
                cout << "Please Log In" << endl;
                Customer_Login_System();
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

void Customer_Login_System()
{
    system("cls");

    bool stageCustomer = false;
    string CustomerUSN, CustomerPW, existedInfo, existedUSN, existedPW;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Please Enter The Following Details:\n\n";
    cout << "\t\t\t\t     Username: ";
    getline(cin, CustomerUSN);
    for (char c : CustomerUSN)
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
    getline(cin, CustomerPW);

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

            if (CustomerUSN == existedUSN && CustomerPW == existedPW)
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
        cout << "\t\t\t\t   Greeting, " << CustomerUSN << ".\n\n";
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

void Customer_Register_System()
{
    system("cls");

    string CregUSN, CregPW;

    cout << "\t\t\t\t  =======================================================================================\n"
            "\t\t\t\t  ||                    B A N K _ M A N A G E M E N T _ S Y S T E M                    ||\n"
            "\t\t\t\t  =======================================================================================\n"
            "\n"
            "\t\t\t\t                            : :  L O G I N _ S Y S T E M  : :                            \n"
            "\n"
            "\t\t\t\t     Registering As A Customer\n\n";

    cout << "\t\t\t\t     Enter Your New Username: ";
    getline(cin, CregUSN);
    for (char c : CregUSN)
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
    if (!(Customer_Username_Validation(CregUSN)))
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
    getline(cin, CregPW);

    ofstream CregInfo("Customer_Account.txt", ios::app);

    if (CregInfo.is_open())
    {
        CregInfo << CregUSN << ' ' << CregPW << endl;
    }

    CregInfo.close();

    system("cls");

    cout << "\nRegistered Successfully.\n\n";
    system("pause");
    Customer_Login_Menu();
}

bool Customer_Username_Validation(string CregUSN)
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

            if ((CregUSN == existedUSN && CregUSN == existedPW) || (CregUSN == existedUSN && CregUSN != existedPW))
            {
                newUSN = false;
                system("cls");
            }
        }
    }

    CustomerInfo.close();

    return newUSN;
}

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