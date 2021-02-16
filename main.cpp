/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 2
*/

#include <iostream>
#include <string>
#include "FileProcessor.h"

using namespace std;

int main(int argc, char **argv)
{
    FileProcessor fileProcessor;
    string conversionType = argv[3];

    if (conversionType == "E2T")
    {
        fileProcessor.processFile(argv[1], argv[2]);
    }
    else if (conversionType == "T2E")
    {
        fileProcessor.processTutneseFile(argv[1], argv[2]);
    }
    else
    {
        cout << "Invalid command line arguments" << endl;
    }
    

    return 0;
}