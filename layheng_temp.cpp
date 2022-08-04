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

//
class a
{
protected:
    string name;
    string dob;
    string gender;
    string account_number, phone_number;
    string occupation;
    int i;
    int count = 0;
    int Num_Acc = 0;
    int num;

public:
    // admin functions
    void Add_Account();
    string CheckForDelete();
    void Delete_Account();
    void Edit_Account();

    // customer functions
    void View_Details(); // function for a customer to check their own account details
} obj;

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
void a::Add_Account()
{
    system("cls");
    cout << "\n\nEnter The Following Information" << endl;
    cout << "\n\tName: ";
    getline(cin, name);
    for (i = 0; i < name.length(); i++)
    {
        if (isspace(name[i]))
        {
            continue;
        }
        if (!isalpha(name[i]))
        {
            system("cls");
            cout << "\nName must not contain special character\n";
            system("pause");
        }
    }
    cout << "\n\tDate of birth(DD/MM/YY): ";
    getline(cin, dob);
    cout << "\n\tGender: ";
    getline(cin, gender);
    cout << "\n\tAccount Number: ";
    getline(cin, account_number);
    cout << "\n\tPhone Number: ";
    getline(cin, phone_number);
    cout << "\n\tOccupation: ";
    getline(cin, occupation);

    ofstream Bank_Info("Bank_Account.txt", ios::app);
    Bank_Info << name << endl;
    Bank_Info << dob << endl;
    Bank_Info << gender << endl;
    Bank_Info << account_number << endl;
    Bank_Info << phone_number << endl;
    Bank_Info << occupation << endl;
    Bank_Info.close();
    cout << "\n";
    system("pause");
    system("cls");
}
void a::Edit_Account()
{
}

string a::CheckForDelete()
{
    string str;
    string find;
    bool notFound = true;

    ifstream Bank_Info("Bank_Account.txt", ios::in);
    while (!Bank_Info.eof())
    {
        getline(Bank_Info, str);
        count++;
    }

    ofstream tempFile("temp.txt", ios::app);
    ifstream Bank_Info1("Bank_Account.txt", ios::in);

    cout << "Enter Account Number to delete account: ";
    getline(cin, find);

    for (int j = 0; (j < Num_Acc) || (!Bank_Info1.eof()); j++)
    {
        getline(Bank_Info1, name);
        getline(Bank_Info1, dob);
        getline(Bank_Info1, gender);
        getline(Bank_Info1, account_number);
        getline(Bank_Info1, phone_number);
        getline(Bank_Info1, occupation);

        if (account_number == find)
        {
            cout << name << endl;
            cout << dob << endl;
            cout << gender << endl;
            cout << account_number << endl;
            cout << phone_number << endl;
            cout << occupation << endl;
            notFound = false;
            return find;
        }
    }
    if (notFound == false)
    {
        cout << "\nData Not Fount\n\n";
    }
    tempFile.close();
    Bank_Info1.close();
    remove("Bank_Account.txt");
    rename("temp.txt", "Bank_Account.txt");
    system("pause");
    system("cls");
    return 0;
}

void a::Delete_Account()
{
    string find = CheckForDelete();
    cout << "\nDo You Want To Delete This Record?\n";
    cout << "Press 'Y' To Confirm Or 'N' To Cancel: ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        ofstream tempFile("temp.txt", ios::app);
        ifstream Bank_Info1("Bank_Account.txt", ios::in);

        for (int j = 0; (j < Num_Acc) || (!Bank_Info1.eof()); j++)
        {
            getline(Bank_Info1, name);
            getline(Bank_Info1, dob);
            getline(Bank_Info1, gender);
            getline(Bank_Info1, account_number);
            getline(Bank_Info1, phone_number);
            getline(Bank_Info1, occupation);

            if (account_number != find)
            {
                tempFile << name << endl;
                tempFile << dob << endl;
                tempFile << gender << endl;
                tempFile << account_number << endl;
                tempFile << phone_number << endl;
                tempFile << occupation << endl;
            }
        }
        tempFile.close();
        Bank_Info1.close();
        remove("Bank_Account.txt");
        rename("temp.txt", "Bank_Account.txt");
        cout << "\nData Deleted Successfully\n\n";
    }
    else if (choice == 'n' || choice == 'N')
    {
        cout << "\nRecord Not Deleted\n\n";
    }

    else
    {
        cout << "\nSorry, invalid input.\n\n";
    }
    system("pause");
    system("cls");
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
                obj.View_Details();
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

// function for a customer to check their own account details
void a::View_Details()
{
}