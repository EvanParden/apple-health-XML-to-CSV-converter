#include <iostream>
#include <fstream>
#include "../includes/tinyxml2/tinyxml2.cpp"


int parseXmlFile(const char *filePath, const char *outputPath)
{
    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(filePath) != tinyxml2::XML_SUCCESS)
    {
        std::cerr << "Failed to load XML file." << std::endl;
        return 1; // Exit with an error code
    }

    std::ofstream csvFile(outputPath);

    if (!csvFile.is_open())
    {
        std::cerr << "Failed to open CSV file." << std::endl;
        return 1;
    }

    // Write CSV header
    csvFile << "Type,SourceName,SourceVersion,Unit,CreationDate,StartDate,EndDate,Value,FoodType\n";

    // Iterate through <Record> elements
    tinyxml2::XMLElement *record = doc.FirstChildElement("HealthData")->FirstChildElement("Record");

    while (record)
    {
        const char *type = record->Attribute("type");
        const char *sourceName = record->Attribute("sourceName");
        const char *sourceVersion = record->Attribute("sourceVersion");
        const char *unit = record->Attribute("unit");
        const char *creationDate = record->Attribute("creationDate");
        const char *startDate = record->Attribute("startDate");
        const char *endDate = record->Attribute("endDate");
        const char *value = record->Attribute("value");

        tinyxml2::XMLElement *metadataEntry = record->FirstChildElement("MetadataEntry");
        const char *foodType = "";

        if (metadataEntry)
        {
            foodType = metadataEntry->Attribute("value");
        }

        csvFile << type << "," << sourceName << "," << sourceVersion << "," << unit << "," << creationDate << ","
                << startDate << "," << endDate << "," << value << "," << foodType << "\n";

        record = record->NextSiblingElement("Record");
    }

    csvFile.close();
    std::cout << "CSV file created successfully." << std::endl;

    return 0;
}
