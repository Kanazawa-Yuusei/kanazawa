#include <iostream>
#include <stdlib.h>


int main()
{
    for(int i = 1;i <= 100;i++)
    {
        if(i % 3 == 0 && i % 5 == 0)
        {
            std::cout << "fizzbuzz";
            std::cout << "\n";
        }
        else if(i % 3 == 0)
        {
            std::cout << "fizz";
            std::cout << "\n";
        }
        else if(i % 5 == 0)
        {
            std::cout << "buzz";
            std::cout << "\n";
        }
    }
    std::cout << std::endl;

    return 0;
}