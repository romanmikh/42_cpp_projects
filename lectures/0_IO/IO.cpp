#include <iostream>

int main()
{
    char buffer[256];

    std::cout << "Hello World" << std::endl; //← last part is \n
    std::cout << "Input a word: ";
    std::cin >> buffer;
    std::cout << "You entered: [" << buffer << "] you dignified hunk you" << std::endl;

    return (0);
}
