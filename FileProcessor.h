/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 2
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include "Translator.h"

using namespace std;

class FileProcessor
{
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(string inputFile, string outputFile);
        
    private:
        void openInputFile(string inputFile);
        void readInputFile();
        void closeInputFile(string inputFile);
        void openOutputFile(string outputFile);
        void writeOutputFile();
        void closeOutputFile(string outputFile);
        Translator translator;
        ifstream inputStream;
        ofstream outputStream;
        string englishText;
        string tutneseText;
};

#endif