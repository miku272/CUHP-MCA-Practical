#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filePath = "/c:/Practicals/CUHP_MCA_Practicals/534_OOPS_Practicals/file_practice.txt";

    // Writing to a file
    std::ofstream outputFile(filePath);
    if (outputFile.is_open())
    {
        outputFile << "Hello, World!\n";
        outputFile << "This is a sample text file.\n";
        outputFile.close();
        std::cout << "File written successfully.\n";
    }
    else
    {
        std::cout << "Unable to open file for writing.\n";
    }

    // Appending to a file
    std::ofstream appendFile(filePath, std::ios::app);
    if (appendFile.is_open())
    {
        appendFile << "This line is appended.\n";
        appendFile.close();
        std::cout << "File appended successfully.\n";
    }
    else
    {
        std::cout << "Unable to open file for appending.\n";
    }

    // Reading from a file
    std::ifstream inputFile(filePath);
    if (inputFile.is_open())
    {
        std::string line;
        std::cout << "File contents:\n";
        while (std::getline(inputFile, line))
        {
            std::cout << line << "\n";
        }
        inputFile.close();
    }
    else
    {
        std::cout << "Unable to open file for reading.\n";
    }

    // Deleting a file
    if (std::remove(filePath.c_str()) == 0)
    {
        std::cout << "File deleted successfully.\n";
    }
    else
    {
        std::cout << "Unable to delete file.\n";
    }

    return 0;
}
