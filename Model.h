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
        // From Assignment1
        Model();
        ~Model();
        string translateSingleCharacter(char character);
        string translateDoubleCharacter(char character);

        // From Assignment2
        string translateSyllable(string syllable);
        int getTutneseSyllableLength();

    private:
        // From Assignment1
        string convertSingleCharacter(char character);
        string convertDoubleCharacter(char character);
        string determineCapitalization(string translation, char originalCharacter);
        bool isVowel(char letter);

        // From Assignment2
        bool isDoubled(string syllable);
        char convertSyllable(string syllable);
        string getTutneseStem(string syllable);
        string determineCapitalization(string translation, string originalString);
        int tutneseSyllableLength;
        
};

#endif