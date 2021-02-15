/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 2
*/

#ifndef MODEL_H
#define MODEL_H

#include <string>

using namespace std;

class Model
{
    public:
        Model();
        ~Model();
        string translateSingleCharacter(char character);
        string translateDoubleCharacter(char character);

    private:
        string convertSingleCharacter(char character);
        string convertDoubleCharacter(char character);
        string determineCapitalization(string translation, char originalCharacter);
        bool isVowel(char letter);
        
};

#endif