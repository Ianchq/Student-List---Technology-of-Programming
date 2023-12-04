
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void printSentencesWithNumber(const std::string &text)
{
    std::istringstream iss(text);
    std::string sentence;

    while (std::getline(iss, sentence, '.'))
    {
        size_t pos = sentence.find_first_of("0123456789");

        while (pos != std::string::npos)
        {
            if (sentence[pos] >= '1' && sentence[pos] <= '9' && pos + 1 < sentence.size() && isdigit(sentence[pos + 1]))
            {
                std::cout << sentence << '.' << std::endl;
            }
            pos = sentence.find_first_of("0123456789", pos + 1);
        }
    }
}

int main()
{
    std::ifstream file("Test.txt");

    if (!file.is_open())
    {
        std::cout << "Error open file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string fileContent = buffer.str();
    file.close();

    printSentencesWithNumber(fileContent);

    return 0;
}
