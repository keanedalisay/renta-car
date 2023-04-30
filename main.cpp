#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

void Welcome(void);
void Home(void);

class Vehicle
{
private:
    int fixed_week_rent = 0;
    int daily_rent = 0;
    std::string vhcle = "";

public:
    void setFixedRent(const int prc)
    {
        fixed_week_rent = prc;
    }
    void setDailyRent(const int prc)
    {
        daily_rent = prc;
    }
    void setVehicle(const std::string veh)
    {
        vhcle = veh;
    }
    void showDetails(void)
    {
        using std::cout;
        using std::setw;

        cout << "\n";
        cout << setw(70) << "------------ " << vhcle << " -------------\n\n";
        cout
            << setw(84) << "Starting rent for a week: " << fixed_week_rent << "\n";
        cout << setw(85) << "Daily rent after starting: " << daily_rent << "\n\n";
        cout << setw(90) << "----------------------------------\n";
    }
    void copyDetails(std::string &veh_var, int &fix_var, int &daily_var)
    {
        veh_var = vhcle;
        fix_var = fixed_week_rent;
        daily_var = daily_rent;
    }
};

class Sedan : public Vehicle
{
public:
    Sedan()
    {
        setFixedRent(100);
        setDailyRent(10);
        setVehicle("Sedan");
    }
};
class SUV : public Vehicle
{
public:
    SUV()
    {
        setFixedRent(200);
        setDailyRent(20);
        setVehicle("SUV");
    }
};
class Hatchback : public Vehicle
{
public:
    Hatchback()
    {
        setFixedRent(150);
        setDailyRent(15);
        setVehicle("Hatchback");
    }
};
class Pickup : public Vehicle
{
public:
    Pickup()
    {
        setFixedRent(210);
        setDailyRent(21);
        setVehicle("Pickup");
    }
};
class Micro : public Vehicle
{
public:
    Micro()
    {
        setFixedRent(70);
        setDailyRent(7);
        setVehicle("Micro");
    }
};

class CarRentalForm
{
private:
    std::string name;
    int age;
    int veh_rent_days;

    std::string veh_chsn;
    int veh_fixed_rent;
    int veh_daily_rent;

    int veh_ttl_rent;

    void hdng(std::string hdr_txt, int lft_mrgn)
    {
        std::cout << "\n"
                  << std::setw(lft_mrgn) << "           " << hdr_txt << "         \n";
        std::cout << std::setw(90) << "-----------------------------------\n";
        std::cout << "\n";
    }

    void profile(void)
    {
        using std::cout;
        using std::setw;

        hdng("CAR RENTAL FORM", 65);
        cout << setw(90) << "Kindly fill out the following details.";
        cout << "\n\n"
             << setw(60) << "Full Name: ";
        std::getline(std::cin, name);
        cout << "\n"
             << setw(55) << "Age: ";
        std::cin >> age;
        cout << "\n"
             << setw(75) << "Rental duration in days...";
        cout
            << "\n"
            << setw(53) << ": ";
        std::cin >> veh_rent_days;

        system("cls");
    }

    void vehicle(void)
    {
        using std::cout;
        using std::setw;

        int veh_chc;
        char has_chsn;

        do
        {
            system("cls");
            hdng("CAR RENTAL FORM", 65);
            cout << setw(82) << "Vehicle class to rent?";
            cout << "\n\n";

            cout << setw(78) << "Micro [1]\n";
            cout << setw(78) << "Sedan [2]\n";
            cout << setw(78) << "Hatchback [3]\n";
            cout << setw(78) << "Pickup [4]\n";
            cout << setw(79) << "SUV [5]\n\n";

            cout << setw(72) << ": ";
            std::cin >> veh_chc;
            std::cin.ignore(1000, '\n');

            switch (veh_chc)
            {
            case 1:
            {
                Micro micro;
                micro.showDetails();
                micro.copyDetails(veh_chsn, veh_fixed_rent, veh_daily_rent);
                break;
            }
            case 2:
            {
                Sedan sedan;
                sedan.showDetails();
                sedan.copyDetails(veh_chsn, veh_fixed_rent, veh_daily_rent);
                break;
            }
            case 3:
            {
                Hatchback htchbck;
                htchbck.showDetails();
                htchbck.copyDetails(veh_chsn, veh_fixed_rent, veh_daily_rent);
                break;
            }
            case 4:
            {
                Pickup pickup;
                pickup.showDetails();
                pickup.copyDetails(veh_chsn, veh_fixed_rent, veh_daily_rent);
                break;
            }
            case 5:
            {
                SUV suv;
                suv.showDetails();
                suv.copyDetails(veh_chsn, veh_fixed_rent, veh_daily_rent);
                break;
            }
            }

            cout << "\n";
            cout << setw(85) << "Will that be your choice?\n";
            cout << setw(88) << "Enter [Y] for yes, [N] if no...\n";
            cout << "\n";
            cout << setw(72) << ": ";
            std::cin >> has_chsn;
            has_chsn = toupper(has_chsn);
            std::cin.ignore(1000, '\n');
        } while (has_chsn != 'Y');
        system("cls");
    }
    void total(void)
    {
        using std::cout;
        using std::setw;

        char has_cnfrm;

        hdng("PROCESSING", 67);
        sleep(2);
        cout << setw(80) << "Your vehicle class >> " << veh_chsn << "\n\n";
        sleep(1);
        cout << setw(82) << "Your total days of rent >> " << veh_rent_days << "\n\n";
        veh_ttl_rent = veh_fixed_rent + (veh_daily_rent * (veh_rent_days - 7));
        sleep(1);
        cout
            << setw(80) << "Your total payment >> " << veh_ttl_rent << "\n\n";
        std::cout << std::setw(91) << "-----------------------------------\n\n";
        sleep(1);
        cout << setw(80) << "Confirm payment?"
             << "\n";
        cout << setw(66) << ": ";
        std::cin >> has_cnfrm;
        std::cin.ignore(1000, '\n');
    }

public:
    void show(void)
    {

        profile();
        vehicle();
        total();
    }
};

int main()
{

    // Welcome();
    // Home();
    CarRentalForm form;
    form.show();
}

void Welcome(void)
{
    std::ifstream in("renta-car.txt");

    if (!in)
    {
        std::cout << "Cannot open input file.\n";
    }
    char str[1000];
    while (in)
    {
        in.getline(str, 1000);
        if (in)
            std::cout << str << "\n";
    }
    in.close();

    sleep(1);
    std::cout << "\nStarting the program please wait..."
              << "\n";
    sleep(1);
    std::cout << "\nLoading up files..."
              << "\n";
    sleep(1);
    system("cls");
}

void Home(void)
{
    using std::cout;
    using std::setw;

    char choice;

    cout << setw(86) << "++================++++===============++ \n";
    cout << setw(86) << "||                                   || \n";
    cout << setw(86) << "||   CAR RENTAL SERVICES  by         || \n";
    cout << setw(86) << "||                      RentA-Car    || \n";
    cout << setw(86) << "||                                   || \n";
    cout << setw(86) << "++================++++===============++ \n";
    cout << "\n";
    cout << setw(92) << "Proceed to our Car Rental Form by entering [Y]... \n";
    cout << setw(85) << "Otherwise, enter [N] to exit program...";
    cout << "\n\n";
    cout << setw(65) << ": ";
    std::cin >> choice;
    choice = toupper(choice);
    std::cin.ignore(1000, '\n');

    if (choice == 'Y')
    {
        cout << "\n"
             << setw(78) << "Great, Let's get started!\n";
        sleep(2);
        system("cls");
    }
    else if (choice == 'N')
    {
        cout << "\n\n"
             << setw(85) << "** Thank you for your consideration. **";
        exit(0);
    }
    else
    {
        cout << "\n"
             << setw(82) << "Invalid Choice. Please Try Again.";
        sleep(1);
        cout << "\n"
             << setw(76) << "Restarting Program...";
        sleep(2);
        system("cls");
        Home();
    }
    return;
}