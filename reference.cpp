#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main();

// global variables
char choice, choiceA, choiceU;
string validation;

class a
{
    // declare variables for using within class a
    int seat_ava, numseat, totalseat;
    int i, j, a, b;        // for loop processing
    int cost, sum;         // for total ticket cost
    string Ssum, Snumseat; // use to convert from sum int to sum string
    int t, r;              // for input temporary data into array processing
    int notFound;
    bool stageAdmin, stageCustomer, rightbus;
    string tempdata[20];              // store 20 tickets for temporarily
    string lookforbus, customerLname; // find bus for customer

public:
    // log in functions
    void Admin_login_menu(); // log in system for admin
    void Admin_login();
    void Admin_registr();
    void Customer_login_menu(); // log in system for customer
    void Customer_login();
    void Customer_registr();

    // bus functions
    void AddNewBus();        // add a new bus with its details
    void CheckDataByID();    // find bus data by inputting bus id
    void CheckDataByDest();  // find bus data by inputting travel destination
    string CheckForDelete(); // for returning a string value to DeleteData and UpdateData functions
    void DeleteData();       // delete existing data
    void UpdateData();       // update existing data
    void view_ticket();      // display booked ticket
    void booking_bus_des();  // booking function
    void AdminSystem();      // a system for admins
    void CustomerSystem();   // a system for customers (customers)
};

// declare class object
a aobject;

struct bus // structure to group data types for a new bus
{
    string busid;
    string driver;
    string arrival;
    string departure;
    string to;
    string busid_found;

} busdata;

void a::Admin_login_menu()
{

    cout << "[1] Log In As An Admin" << endl
         << "[2] Register As An Admin" << endl
         << "[B] Back" << endl;
    cout << "Your Choice: ";
    getline(cin, validation); // accept entered input as validation variable
    system("cls");

    if (validation.size() == 1) // accept validation with only 1 character
    {
        choiceA = validation[0]; // let role equal to the inputted validation

        switch (choiceA)
        {
        case '1':
            Admin_login();
            break;

        case '2':
            Admin_registr();
            cout << "Please Log In" << endl;
            Admin_login();
            break;
        case 'B':
        case 'b':
            system("cls");
            main();
            break;
        default:
        {
            cout << "\nSorry, Invalid Input.\n\n";
            system("pause");
            system("cls");
            cin.clear();
            Admin_login_menu();
            break;
        }
        }
    } // if condition
    else
    {
        cout << "\nSorry, Invalid Input\n\n";
        system("pause");
        system("cls");
        Admin_login_menu();
    }
}

// Admin Log in and Registration
void a::Admin_login()
{
    int count;
    char choiceL;
    bool stageAdmin = false;
    string Acustomer, Apass, Au, Ap;
    // system("cls");
    cout << "\n\nPlease Enter The Following Details" << endl;
    cout << "\nUSERNAME: ";
    cin >> Acustomer;
    cout << "\nPASSWORD: ";
    cin >> Apass;

    ifstream inputA("Admin_registration_account.txt");
    while (inputA >> Au >> Ap)
    {
        if (Au == Acustomer && Ap == Apass)
        {
            count = 1;
            stageAdmin = true;
            system("cls");
        }
    }
    inputA.close();
    if (stageAdmin == true)
    {
        cout << "\nLogged In Successfully...";
        cout << "\nGreeting " << Acustomer << endl
             << "\n\n======== Welcome To Bus System For Admin ========" << endl;
        cin.get();
        AdminSystem();
    } // if condition
    else
    {
        cout << "\nLogin Error.\nPlease Check Your Username and Password Again!\n"
             << endl;
        cout << "\nEnter 'Y' To Log in Again, 'N' To Go Back To Main Menu" << endl;
        ;
        cin >> choiceL;
        switch (choiceL)
        {
        case 'Y':
        case 'y':

            system("cls");
            Admin_login();
            break;

        case 'N':
        case 'n':

            system("cls");

            cin.clear();
            cin.ignore(10000, '\n');
            Admin_login_menu();
            break;

        default:
        {
            cout << "Wrong Input";
            break;
        }
        } // end of switch
    }     // else condition
} // end of function

void a::Admin_registr()
{

    string Aregcustomer, Aregpass, Aru, Arp;
    system("cls");
    cout << "Enter Your New Admin Username: ";
    cin >> Aregcustomer;
    cout << "\nEnter Your New Admin Password: ";
    cin >> Aregpass;

    ofstream Areg("Admin_registration_account.txt", ios::app);
    Areg << Aregcustomer << ' ' << Aregpass << endl;
    system("cls");
    cout << "\nRegistered Sucessfully\n";
}

void a::Customer_login_menu()
{

    cout << "[1] Log In As A Customer" << endl
         << "[2] Register As A Customer" << endl
         << "[B] Back" << endl;
    cout << "Your Choice: ";

    getline(cin, validation); // accept entered input as validation variable
    system("cls");

    if (validation.size() == 1) // accept validation with only 1 character
    {
        choiceU = validation[0]; // let role equal to the inputted validation

        switch (choiceU)
        {
        case '1':
            Customer_login();
            break;

        case '2':
            Customer_registr();
            cout << "Please Log In" << endl;
            Customer_login();
            break;
        case 'B':
        case 'b':
            system("cls");
            main();
            break;

        default:
        {
            cout << "\nSorry, Invalid Input\n\n";
            system("pause");
            system("cls");
            break;
        }
        }
    } // if condition
    else
    {
        cout << "\nSorry, Invalid Input\n\n";
        system("pause");
        system("cls");
        Customer_login_menu();
    }
}

// Customer Log in and Registration
void a::Customer_login()
{
    int count;
    bool stageCustomer = false;
    string Ucustomer, Upass, Uu, Up;
    // system("cls");
    cout << "Please Enter The Following Details" << endl;
    cout << "USERNAME : ";
    cin >> Ucustomer;
    cout << "PASSWORD : ";
    cin >> Upass;

    ifstream input("Customer_registration.txt");
    while (input >> Uu >> Up)
    {
        if (Uu == Ucustomer && Up == Upass)
        {
            count = 1;
            stageCustomer = true;
            system("cls");
        }
    }
    input.close();
    if (stageCustomer == true)
    {
        cout << "\nLOGGED IN SUCCESSFULLY..." << endl;
        cout << "\nGreeting " << Ucustomer << endl
             << "\n\n======== Welcome To Bus System For Customer ========" << endl;
        cin.get();
        CustomerSystem();
    }
    else
    {
        cout << "\nLog In Error.\n\nPlease Check Your Username And Password Again!\n";
        cout << "\nEnter 'Y' To Log In Again, 'N' To Go Back To Main Menu" << endl;
        ;
        cin >> choice;
        switch (choice)
        {
        case 'Y':
        case 'y':

            system("cls");
            Customer_login();
            break;

        case 'N':
        case 'n':
            // system("cls");
            system("cls");
            cin.clear();
            cin.ignore(10000, '\n');
            Customer_login_menu();

            break;

        default:
        {
            cout << "Wrong Input";
            break;
        }
        } // end of switch
    }     // else statement
}

void a::Customer_registr()
{

    string Uregcustomer, Uregpass, Uru, Urp;
    system("cls");
    cout << "Enter Your New Username :";
    cin >> Uregcustomer;
    cout << "\nEnter Your New Password :";
    cin >> Uregpass;

    ofstream Ureg("Customer_registration.txt", ios::app);
    Ureg << Uregcustomer << ' ' << Uregpass << endl;
    system("cls");
    cout << "\nRegisterd Successfully\n";
    // main();
}

void a::AddNewBus()
{
    ofstream f1("bus.txt", ios::app); // f1 for write

    for (i = 0; choiceA != 'n' && choiceA != 'N'; i++)
    {
        if ((choiceA == 'y') || (choiceA == 'Y') || (choiceA == '1'))
        {
            cout << "\nEnter The Following Information\n";
            cin.ignore();
            cout << "\tBus ID: ";
            getline(cin, busdata.busid);

            cout << "\tDriver's Name: ";
            getline(cin, busdata.driver);
            cout << "\tArrival Time: ";
            getline(cin, busdata.arrival);
            cout << "\tDeparture Time: ";
            getline(cin, busdata.departure);
            cout << "\tFrom: Phnom Penh" << endl;
            cout << "\tTo: ";
            getline(cin, busdata.to);

            f1 << busdata.busid << endl
               << busdata.driver << endl
               << busdata.arrival << endl
               << busdata.departure << endl
               << busdata.to << endl;

            cout << "Do You Want Enter More Bus's Data?\n";
            cout << "Press 'Y' To Continue Or 'N' To Finish: ";
            choiceA = getchar();
            cin.clear();
        }
    }
    f1.close();

    cin.clear();
    cin.ignore(100, '\n');
}

void a::CheckDataByID()
{
    string find;
    notFound = 0;
    ifstream f2("bus.txt"); // f2 for read

    cout << "Enter A Bus's ID: ";
    getline(cin, find);
    cout << endl;

    for (j = 0; (j < i) || (!f2.eof()); j++)
    {

        getline(f2, busdata.busid);

        if (busdata.busid == find)
        {
            notFound = 1;
            cout << "Bus ID: " << busdata.busid << endl;

            getline(f2, busdata.driver);
            cout << "Driver's Name: " << busdata.driver << endl;
            getline(f2, busdata.arrival);
            cout << "Arrival Time: " << busdata.arrival << endl;
            getline(f2, busdata.departure);
            cout << "Departure Time: " << busdata.departure << endl;
            cout << "From: Phnom Penh" << endl;
            getline(f2, busdata.to);
            cout << "To: " << busdata.to << endl
                 << endl;
        }
    }

    if (notFound == 0)
    {
        cout << "No Record Found" << endl;
    }
    f2.close();

    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");
}

void a::CheckDataByDest()
{
    notFound = 0;
    string find;
    ifstream f2("bus.txt"); // f2 for read

    cout << "\nEnter Your Travel Destination: ";
    getline(cin, find);
    cout << endl;

    for (j = 0; (j < i) || (!f2.eof());)
    {
        getline(f2, busdata.busid);
        getline(f2, busdata.driver);
        getline(f2, busdata.arrival);
        getline(f2, busdata.departure);
        getline(f2, busdata.to);

        if (busdata.to == find)
        {
            notFound = 1;

            cout << "Bus ID: " << busdata.busid << endl;
            cout << "Driver's Name: " << busdata.driver << endl;
            cout << "Arrival Time: " << busdata.arrival << endl;
            cout << "Departure Time: " << busdata.departure << endl;
            cout << "From: Phnom Penh" << endl;
            cout << "To: " << busdata.to << endl
                 << endl;
            j++;
        }
    }

    if (notFound == 0)
    {
        cout << "No Record Found\n"
             << endl;
        CheckDataByDest();
    }
    f2.close();
    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");
}

string a::CheckForDelete()
{
    string find;
    ifstream f2("bus.txt"); // f2 for read

    cout << "Enter A Bus's ID: ";
    getline(cin, find);
    cout << endl;

    for (j = 0; (j < i) || (!f2.eof()); j++)
    {

        getline(f2, busdata.busid);

        if (busdata.busid == find)
        {
            notFound = 1;
            cout << "Bus ID: " << busdata.busid << endl;

            getline(f2, busdata.driver);
            cout << "Driver's Name: " << busdata.driver << endl;
            getline(f2, busdata.arrival);
            cout << "Arrival Time: " << busdata.arrival << endl;
            getline(f2, busdata.departure);
            cout << "Departure Time: " << busdata.departure << endl;
            cout << "From: Phnom Penh" << endl;
            getline(f2, busdata.to);
            cout << "To: " << busdata.to << endl;

            return find;
        }
    }

    if (notFound == 0)
    {
        cout << "No Record Found" << endl;
    }
    f2.close();

    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");

    return 0;
}

void a::DeleteData()
{
    string find = CheckForDelete();
    cout << "\nDo You Want To Delete This Record?\n";
    cout << "Press 'Y' To Confirm Or 'N' To Cancel: ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        ofstream tempFile("temp.txt", ios::app);
        ifstream f2("bus.txt");

        while (!f2.eof())
        {
            getline(f2, busdata.busid);
            getline(f2, busdata.driver);
            getline(f2, busdata.arrival);
            getline(f2, busdata.departure);
            getline(f2, busdata.to);

            if (busdata.busid != find)
            {
                tempFile << busdata.busid << endl;
                tempFile << busdata.driver << endl;
                tempFile << busdata.arrival << endl;
                tempFile << busdata.departure << endl;
                tempFile << busdata.to << endl;
            }
        }

        f2.close();
        tempFile.close();
        remove("bus.txt");
        rename("temp.txt", "bus.txt");
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

    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");
}

void a::UpdateData()
{
    string getfind = CheckForDelete();
    cout << "\nDo You Want To Update This Record?\n";
    cout << "Press 'Y' To Confirm Or 'N' To Cancel: ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        bus newdata; // new variable
        cin.ignore();
        cout << "\nEnter The Following Information\n";
        cout << "\tDriver's Name: ";
        getline(cin, newdata.driver);
        cout << "\tArrival Time: ";
        getline(cin, newdata.arrival);
        cout << "\tDeparture Time: ";
        getline(cin, newdata.departure);
        cout << "\tFrom: Phnom Penh" << endl;
        cout << "\tTo: ";
        getline(cin, newdata.to);

        bus busdata;
        ofstream tempFile("temp.txt", ios::app);
        ifstream f2("bus.txt");

        while (!f2.eof())
        {
            getline(f2, busdata.busid);
            getline(f2, busdata.driver);
            getline(f2, busdata.arrival);
            getline(f2, busdata.departure);
            getline(f2, busdata.to);

            if (busdata.busid != getfind)
            {
                tempFile << busdata.busid << endl;
                tempFile << busdata.driver << endl;
                tempFile << busdata.arrival << endl;
                tempFile << busdata.departure << endl;
                tempFile << busdata.to << endl;
            }

            else
            {
                tempFile << busdata.busid << endl;
                tempFile << newdata.driver << endl;
                tempFile << newdata.arrival << endl;
                tempFile << newdata.departure << endl;
                tempFile << newdata.to << endl;
            }
        }

        f2.close();
        tempFile.close();
        remove("bus.txt");
        rename("temp.txt", "bus.txt");
        cout << "\nData Updated Successfully\n\n";
    }

    else if (choice == 'n' || choice == 'N')
    {
        cout << "\nRecord Not Updated\n\n";
    }

    else
    {
        cout << "\nSorry, invalid input.\n\n";
    }

    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");
}

void a::booking_bus_des()
{
    string find;
    notFound = 0;

    ifstream f2("bus.txt");
    cout << "\n\t\t\t==================== Booking ====================" << endl;
    cout << "\n\t\t\tEnter Your Travel Destination: ";
    getline(cin, find);

    // show avaible bus(s)

    for (j = 0; (j < i) || (!f2.eof());)
    {
        getline(f2, busdata.busid);
        getline(f2, busdata.driver);
        getline(f2, busdata.arrival);
        getline(f2, busdata.departure);
        getline(f2, busdata.to);

        if (busdata.to == find)
        {
            notFound = 1;
            cout << "\n --> " << busdata.busid;
            j++;
            tempdata[t] = busdata.busid;
            t++;
        }
    } // end of for loop

    if (notFound == 0)
    {
        cout << "Sorry, Invalid Input\n";
    }
    cout << endl;
    // book a bus
    // create an array, take all bus that all that location store in array, compare look for bus to busid found in that array

    ofstream b1("booking.txt", ios::app); // ofstream: to create and write file
    do
    {
        cout << "\nChoose A Bus You Want To Book: ";
        cin >> lookforbus;
        for (r = 0; r < t; r++)
        {
            if (tempdata[r] == lookforbus)
            {
                rightbus = true;
                break;
            }
            else
            {
                rightbus = false;
            }
        }

        if (rightbus == true)
        {

            int seat;
            totalseat = (seat = 32 * j);
            cout << "\nYour Chose A Correct Bus." << endl;

        seatava:
            cout << "\nNumber Of Seats Available: " << totalseat << endl;
            cout << "\nPlease Choose Number Of Seat You Want To Book: ";
            cin >> numseat;

            if (numseat > totalseat)
            {
                cout << "Sorry, No More Seat Is Available." << endl;
            }

            else
            {
                cout << "Enter Your First Name: ";
                cin >> customerLname;
                b1 << customerLname << endl;

                b1 << lookforbus << endl;
                Snumseat = to_string(numseat);
                b1 << Snumseat << endl;
                sum = numseat * 12;
                Ssum = to_string(sum); // converting from integer into string to store in file
                b1 << Ssum << endl;
                totalseat -= numseat;
                cout << "\nBooked Successfully.\n\n"
                     << endl;
                cout << "\nChoose 'Y' to Continue Booking, Choose 'N' To Return To Customer Menu" << endl;
                cin >> choice;
                switch (choice)
                {
                case 'Y':
                case 'y':
                    goto seatava;
                    break;
                case 'N':
                case 'n':
                    cin.clear();
                    cin.ignore(100, '\n');
                    CustomerSystem();
                    break;
                default:
                    cout << "Sorry, Invalid Input\n";
                    break;
                } // end switch
            }     // end sub else statment
        }         // end main if statement

        else
        {
            cout << "You Chose An Unavailable Bus." << endl;
        }
        cin.clear();
    } // end while loop
    while (true);

    b1.close(); // close booking.txt file

    f2.close(); // close bus.txt file

    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");
}

void a::view_ticket()
{
    string find;

    ifstream b2("booking.txt"); //

    cout << "Enter Your First Name: ";
    getline(cin, find);
    cout << endl;
    for (a = 0; (a < i) || (!b2.eof()); a++)
    {
        getline(b2, customerLname);
        getline(b2, lookforbus);
        getline(b2, Snumseat);
        getline(b2, Ssum);
        if (customerLname == find)
        {

            ifstream f2("bus.txt");
            for (j = 0; (j < i) || (!f2.eof()); j++)
            {
                getline(f2, busdata.busid);
                getline(f2, busdata.driver);
                getline(f2, busdata.arrival);
                getline(f2, busdata.departure);
                getline(f2, busdata.to);

                if (lookforbus == busdata.busid)
                {
                    notFound = 1;

                    cout << "Bus ID: " << busdata.busid << endl;
                    cout << "Driver's Name: " << busdata.driver << endl;
                    cout << "Arrival Time: " << busdata.arrival << endl;
                    cout << "Departure Time: " << busdata.departure << endl;
                    cout << "From: Phnom Penh" << endl;
                    cout << "To: " << busdata.to << endl
                         << endl;
                }
            }
            cout << "\n=====================================\n";
            cout << "\nYour Name: " << customerLname;
            cout << "\n\n=====================================\n";
            cout << "\nNumber Of Booked Seat(s): " << Snumseat;
            cout << "\n\n=====================================\n";
            cout << "\nTotal Price Of Ticket(s): $" << Ssum << "";
            cout << "\n\n=====================================\n";
            f2.close();

            system("pause");
            CustomerSystem();
        }
    }

    if (notFound == 0)
    {
        cout << "Wrong Name" << endl;
        view_ticket();
    }

    b2.close();
    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");
}

void a::AdminSystem()
{
    do
    {
        cout << "\nAdmin System:\n\n"
                "\t[1] Add A New Bus's Data\n"
                "\t[2] Check Database\n"
                "\t[3] Update Database\n"
                "\t[4] Delete Database\n"
                "\t[B] Back To The MAIN MENU\n"
                "\nYour Choice: ";
        getline(cin, validation); // accept entered input as validation variable
        system("cls");

        if (validation.size() == 1) // accept validation with only 1 character
        {
            choiceA = validation[0]; // let role equal to the inputted validation

            switch (choiceA)
            {
            case '1':
                AddNewBus();
                break;

            case '2':
                CheckDataByID();
                continue;

            case '3':
                UpdateData();
                continue;

            case '4':

                DeleteData();
                continue;

            case 'B':
            case 'b':
                main();
                break;

            default:
                cout << "\nSorry, Invalid Input\n\n";
                system("pause");
                system("cls");
                break;
            }
        }

        else
        {
            cout << "\nSorry, Invalid Input\n\n";
            system("pause");
            system("cls");
        }

    } while (true);
}

void a::CustomerSystem()
{
    cin.clear();

    system("cls");
    do
    {

        cout << "\nCustomer System:\n\n"
                "\t[1] Search For Available Buses\n"
                "\t[2] Book A Bus\n"
                "\t[3] View Ticket\n"
                "\t[B] Back To The MAIN MENU\n"
                "\nYour Choice: ";
        getline(cin, validation); // accept entered input as validation variable
        system("cls");

        if (validation.size() == 1) // accept validation with only 1 character
        {
            choiceU = validation[0]; // let role equal to the inputted validation

            switch (choiceU)
            {
            case '1':
            {
                while (true)
                {
                    cin.clear();

                    cout << "\nSelect Your Searching Method:\n"
                            "\t[1] By Bus ID\n"
                            "\t[2] By Your Destination\n"
                            "\t[B] Back to Customer System\n"
                            "\nYour Choice: ";
                    getline(cin, validation); // accept entered input as validation variable
                    system("cls");

                    if (validation.size() == 1) // accept validation with only 1 character
                    {
                        choiceU = validation[0]; // let role equal to the inputted validation

                        switch (choiceU)
                        {
                        case '1':
                            aobject.CheckDataByID();
                            continue;

                        case '2':
                            aobject.CheckDataByDest();
                            continue;

                        case 'B':
                        case 'b':
                            cin.clear();
                            CustomerSystem();
                            break;

                        default:
                            cout << "\nSorry, invalid input.\n\n";
                            system("pause");
                            system("cls");
                            break;
                        }
                    }

                    else
                    {
                        cout << "\nSorry, invalid input.\n\n";
                        system("pause");
                        system("cls");
                    }
                }
                cin.clear();
                cin.ignore(100, '\n');
                system("pause");
                break;
            }
                continue;

            case '2':
                booking_bus_des();
                cin.clear();
                cin.ignore(100, '\n');
                system("pause");
                break;

            case '3':
            {
                aobject.view_ticket();
            }
                continue;

            case 'b':
            case 'B':
                main();
                break;

            default:
                cout << "\nSorry, Invalid Input\n\n";
                system("pause");
                system("cls");
                break;
            }
        }

        else
        {
            std::cout << "\nSorry, Invalid Input\n\n";
            system("pause");
            system("cls");
        }
    } while (true);

} // end of customer system function

int main()
{
    system("cls");

    do
    {
        cout << "\t\t\t=======================================================\n"
                "\t\t\t================ Welcome To Phnom Penh Bus =======    ==\n"
                "\t\t\t===================================================    ==\n"
                "\t\t\t===================================================      ==\n"
                "\t\t\t======================== MAIN MENU =========================\n"
                "\t\t\t============================================================\n"
                "\t\t\t    ====                                            ====\n"
                "\t\t\t  ==    ==                                        ==    ==\n"
                "\t\t\t    ====                                            ====\n"
                "\n\t\t\tPlease Select Your Role\n\n"
                "\t\t\t[1] Admin\n"
                "\t\t\t[2] Customer\n"
                "\t\t\t[E] Exit\n"
                "\n\t\t\tYour Choice: ";

        getline(cin, validation); // accept entered input as validation variable
        system("cls");

        if (validation.size() == 1) // accept validation with only 1 character
        {
            choice = validation[0]; // let role equal to the inputted validation

            switch (choice)
            {
            case '1':

                aobject.Admin_login_menu();
                break;

            case '2':
                aobject.Customer_login_menu();
                break;

            case 'E':
            case 'e':
                cout << "< You Have Successfully Logged Out Of The System >\n"
                     << "< Thank You And Please Visit Us Again! >\n";
                exit(0); // exit the system

            default:
                cout << "\nSorry, Invalid Input\n\n";
                system("pause");
                system("cls");
                break;
            }
        }

        else
        {
            cout << "\nSorry, Invalid Input\n\n";
            system("pause");
            system("cls");
        }

    } while (true);

    return 0;
}