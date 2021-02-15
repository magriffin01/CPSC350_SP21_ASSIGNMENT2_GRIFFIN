/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 2
*/

#include <iostream>
#include "FileProcessor.h"

using namespace std;

int main(int argc, char **argv)
{
    FileProcessor fileProcessor;
    fileProcessor.processFile(argv[1], argv[2]);

    return 0;
}