#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

void Welcome(void);
void Home(void);

class CarRentalForm
{
private:
    std::string name;
    int age;
    int car_rent_days;

    void hdng(void)
    {
        std::cout << "\n"
                  << std::setw(90) << "           CAR RENTAL FORM         \n";
        std::cout << std::setw(90) << "-----------------------------------\n";
        std::cout << "\n"
    };

public:
    void show(void)
    {
        using std::cout;
        using std::setw;

        hdng();

        << setw(90) << "Kindly fill out the following details.";
        cout << "\n\n"
             << setw(60) << "Full Name: ";
        std::getline(std::cin, name);
        cout << "\n"
             << setw(55) << "Age: ";
        std::cin >> age;
        cout << "\n"
             << setw(83) << "Duration of Car Rental [# of Days]: ";
        std::cin >> car_rent_days;

        system("cls");
    }
};

int main()
{

    Welcome();
    Home();
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