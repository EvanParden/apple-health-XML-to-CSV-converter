#include <iostream>
#include <fstream>
// #include "../includes/tinyxml2/tinyxml2.cpp"

int parseCdaXmlFile(const char *filePath, const char *outputPath)
{
    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(filePath) != tinyxml2::XML_SUCCESS)
    {
        std::cerr << "Failed to load XML file." << std::endl;
        return 1;
    }

    std::ofstream csvFile(outputPath);

    if (!csvFile.is_open())
    {
        std::cerr << "Failed to open CSV file." << std::endl;
        return 1;
    }

    csvFile << "SourceName,SourceVersion,Value,Type,Unit\n";

    tinyxml2::XMLElement *firstComponent = doc.FirstChildElement("component");

    while (firstComponent)
    {
        tinyxml2::XMLElement *section = firstComponent->FirstChildElement("section");

        while (section)
        {
            tinyxml2::XMLElement *entry = section->FirstChildElement("entry");

            while (entry)
            {
                tinyxml2::XMLElement *organizer = entry->FirstChildElement("organizer");

                while (organizer)
                {
                    tinyxml2::XMLElement *component = organizer->FirstChildElement("component");

                    while (component)
                    {
                        tinyxml2::XMLElement *observation = component->FirstChildElement("observation");

                        while (observation)
                        {
                            tinyxml2::XMLElement *text = observation->FirstChildElement("text");

                            if (text)
                            {
                                const char *sourceName = text->FirstChildElement("sourceName")->GetText();
                                const char *sourceVersion = text->FirstChildElement("sourceVersion")->GetText();
                                const char *value = text->FirstChildElement("value")->GetText();
                                const char *type = text->FirstChildElement("type")->GetText();
                                const char *unit = text->FirstChildElement("unit")->GetText();

                                csvFile << sourceName << "," << sourceVersion << "," << value << "," << type << "," << unit << "\n";
                            }

                            observation = observation->NextSiblingElement("observation");
                        }

                        component = component->NextSiblingElement("component");
                    }

                    organizer = organizer->NextSiblingElement("organizer");
                }

                entry = entry->NextSiblingElement("entry");
            }

            section = section->NextSiblingElement("section");
        }

        firstComponent = firstComponent->NextSiblingElement("component");
    }

    csvFile.close();
    std::cout << "CSV file created successfully." << std::endl;

    return 0;
}
