#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        // File input mode
        std::string filename(argv[1]);

        if (filename == "-")
        {
            // Read from standard input
            std::string myline;
            while (std::getline(std::cin, myline))
            {
                std::cout << myline << '\n';
            }
        }
        else
        {
            // Open the specified file
            std::ifstream myfile(filename);

            if (!myfile.is_open())
            {
                std::cerr << "Error opening file: " << filename << std::endl;
                return 1;
            }

            std::string myline;
            while (std::getline(myfile, myline))
            {
                std::cout << myline << '\n';
            }
        }
    }
    else
    {
        // Standard input mode
        std::string myline;
        while (std::getline(std::cin, myline))
        {
            std::cout << myline << '\n';
        }
    }

    return 0;
}
