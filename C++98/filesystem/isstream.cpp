//
//  isstream.cpp
//  testcpp3
//
//  Created by hua fan on 2025-08-29.
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

std::pair<int,int> read_text_file(const std::string &filePath, bool &success)
{
    int mindata = INT_MAX;
    int maxdata = INT_MIN;
    success = false;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file:" << filePath << std::endl;
    }
    else {
        string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int num;
            if (iss >> num) {
                mindata = min(num, mindata);
                maxdata = max(num, maxdata);
            }
        }
        
        success = true;
    }
    
    return {mindata, maxdata};
}

void read_text_main()
{
    std::string filePath;
    std::cout << "Enter the path to the text file: ";
    std::getline(std::cin, filePath);
    
    bool success = false;
    std::pair<int,int> res = read_text_file(filePath, success);
    if(success)
    {
        cout << "Minumum of the data: " << res.first << endl;
        cout << "Maximum of the data: " << res.second << endl;
    }
    else
    {
        cout << "Failed to read the file : " << filePath << endl;
    }
}
