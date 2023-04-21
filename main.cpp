#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

class Welcome
{
public:
    int output()
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
        return 0;
    }
};

int main()
{

    Welcome node;
    node.output();
}
