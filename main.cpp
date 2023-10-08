#include <fstream>
#include <iostream>
#include <string>
#include "src/parser.cpp"
#include "src/cdaParser.cpp"


const char *version = "1.0";
const char *OutFileName = "apple_health_export.csv";
const char *CdaOutFileName = "apple_health_export_cda.csv";

int main(int argc, char *argv[])
{
    // Create a vector to store command-line arguments
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];

        if (arg == "-v" || arg == "--version")
        {
            std::cout << "Version: " << version << std::endl;
            return 0;
        }
        else if (arg == "exPath")
        {

            if (i + 1 < argc)
            {
                std::cout << "Converting file: " << argv[i + 1] << std::endl;

                parseXmlFile(argv[i + 1], OutFileName);
                ++i;
            }
            else
            {
                std::cerr << "Error: Missing file path" << arg << std::endl;
                return 1;
            }
        }
        else if (arg == "exCdaPath")
        {

            if (i + 1 < argc)
            {
                std::cout << "Converting file: " << argv[i + 1] << std::endl;

                parseCdaXmlFile(argv[i + 1], CdaOutFileName);
                ++i;
            }
            else
            {
                std::cerr << "Error: Missing file path" << arg << std::endl;
                return 1;
            }
        }
        else
        {
            std::cerr << "Error: Unknown option: " << arg << std::endl;
            return 1;
        }
    }

    return 0;
}
