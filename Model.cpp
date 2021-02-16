/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 2
*/

#include <cctype>
#include <string>
#include "Model.h"

using namespace std;

Model::Model()
{
    
}

Model::~Model()
{

}

// Takes a single character as input and return a string representing its encoding in Tutnese, Capitalization Preserved
string Model::translateSingleCharacter(char character)
{
    string translation;
    translation = convertSingleCharacter(character);
    translation = determineCapitalization(translation, character);
    return translation;
}

// Takes a single character as input and returns a string representing its encoding in Tutnese, Capitalization preserved
string Model::translateDoubleCharacter(char character)
{
    string translation;
    translation = convertDoubleCharacter(character);
    translation = determineCapitalization(translation, character);
    return translation;
}

// Takes a character and returns the appropriate conversion for a letter
string Model::convertSingleCharacter(char character)
{
    string conversion;

    switch (tolower(character))
    {
        case 'b':
            conversion = "bub";
            break;
        
        case 'c':
            conversion = "cash";
            break;

        case 'd':
            conversion = "dud";
            break;

        case 'f':
            conversion = "fuf";
            break;
        
        case 'g':
            conversion = "gug";
            break;
        
        case 'h':
            conversion = "hash";
            break;

        case 'j':
            conversion = "jay";
            break;

        case 'k':
            conversion = "kuck";
            break;

        case 'l':
            conversion = "lul";
            break;

        case 'm':
            conversion = "mum";
            break;
        
        case 'n':
            conversion = "nun";
            break;

        case 'p':
            conversion = "pub";
            break;

        case 'q':
            conversion = "quack";
            break;

        case 'r':
            conversion = "rug";
            break;

        case 's':
            conversion = "sus";
            break;
        
        case 't':
            conversion = "tut";
            break;
        
        case 'v':
            conversion = "vuv";
            break;

        case 'w':
            conversion = "wack";
            break;

        case 'x':
            conversion = "ex";
            break;

        case 'y':
            conversion = "yub";
            break;

        case 'z':
            conversion = "zub";
            break;

        default:
            conversion = tolower(character);
            break;
    }

    return conversion;
}

// Takes a character and returns the appropriate conversion for a repeated letter
string Model::convertDoubleCharacter(char character)
{
    string conversion;

    if (isVowel(character))
    {
        conversion = "squat";
    }
    else if (isalpha(character))
    {
        conversion = "squa";
    }
    
    conversion = conversion + convertSingleCharacter(character);

    return conversion;
}

/* Takes the lowercase translated string and original character, and either capitalizes the first character in the 
    string or not based on the original character */
string Model::determineCapitalization(string translation, char originalCharacter)
{
    if (isupper(originalCharacter))
    {
        translation.at(0) = toupper(translation.at(0));
        return translation;
    }
    else
    {
        return translation;
    }
}

// Returns true if the letter is a vowel and false if not
bool Model::isVowel(char letter)
{
    switch (tolower(letter))
    {
        case 'a':
            return true;
        
        case 'e':
            return true;

        case 'i':
            return true;

        case 'o':
            return true;

        case 'u':
            return true;

        default:
            return false;
    }
}

// Returns the English character for a Tutnese Syllable
string Model::translateSyllable(string syllable)
{
    tutneseSyllableLength = 0;
    string originalString = syllable;
    string translation = "";

    syllable[0] = tolower(syllable.at(0));

    if (isDoubled(syllable))
    {
        translation = convertSyllable(getTutneseStem(syllable));
        translation = translation + translation;
        translation = determineCapitalization(translation, originalString);
        return translation;
    }
    else
    {
        translation = convertSyllable(syllable);
        translation = determineCapitalization(translation, originalString);
        return translation;
    }
}

// Returns true if the Syllable contains "Squa" or "Squat", and false if not
bool Model::isDoubled(string syllable)
{
    if ((syllable.size() >= 5) && (syllable.substr(0, 5) == "squat"))
    {
        return true;
    }
    else if ((syllable.size() >= 4) && (syllable.substr(0, 4) == "squa"))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Returns the stem of the Tutnese syllable for double characters
string Model::getTutneseStem(string syllable)
{
    if ((syllable.substr(0, 5) == "squat") && (syllable.substr(0, 7) != "squatut"))
    {
        tutneseSyllableLength += 5;
        return syllable.substr(5, syllable.size() - 5);
    }
    else if (syllable.substr(0, 4) == "squa")
    {
        tutneseSyllableLength += 4;
        return syllable.substr(4, syllable.size() - 4);
    }
    else
    {
        return "!error";
    }
}

// Determines the capitallization of a translation based on the first character of a string
string Model::determineCapitalization(string translation, string originalString)
{
    if (isupper(originalString.at(0)))
    {
        translation.at(0) = toupper(translation.at(0));
        return translation;
    }
    else
    {
        return translation;
    }
}

// Returns the length of syllable
int Model::getTutneseSyllableLength()
{
    return tutneseSyllableLength;
}

// Returns the English character based on the Tutnese syllable
char Model::convertSyllable(string syllable)
{
    char conversion;

    switch (syllable.at(0))
    {
        case 'b':
            conversion = 'b';
            tutneseSyllableLength += 3;
            break;

        case 'c':
            conversion = 'c';
            tutneseSyllableLength += 4;
            break;

        case 'd':
            conversion = 'd';
            tutneseSyllableLength += 3;
            break;

        case 'f':
            conversion = 'f';
            tutneseSyllableLength += 3;
            break;

        case 'g':
            conversion = 'g';
            tutneseSyllableLength += 3;
            break;

        case 'h':
            conversion = 'h';
            tutneseSyllableLength += 4;
            break;

        case 'j':
            conversion = 'j';
            tutneseSyllableLength += 3;
            break;

        case 'k':
            conversion = 'k';
            tutneseSyllableLength += 4;
            break;

        case 'l':
            conversion = 'l';
            tutneseSyllableLength += 3;
            break;

        case 'm':
            conversion = 'm';
            tutneseSyllableLength += 3;
            break;

        case 'n':
            conversion = 'n';
            tutneseSyllableLength += 3;
            break;

        case 'p':
            conversion = 'p';
            tutneseSyllableLength += 3;
            break;

        case 'q':
            conversion = 'q';
            tutneseSyllableLength += 5;
            break;

        case 'r':
            conversion = 'r';
            tutneseSyllableLength += 3;
            break;

        case 's':
            conversion = 's';
            tutneseSyllableLength += 3;
            break;

        case 't':
            conversion = 't';
            tutneseSyllableLength += 3;
            break;

        case 'v':
            conversion = 'v';
            tutneseSyllableLength += 3;
            break;

        case 'w':
            conversion = 'w';
            tutneseSyllableLength += 4;
            break;

        case 'e':
            if ((syllable.size() > 1) && (tolower(syllable.at(1) == 'x')))
            {
                conversion = 'x';
                tutneseSyllableLength += 2;
            }
            else
            {
                conversion = 'e';
                tutneseSyllableLength += 1;
            }
            break;

        case 'y':
            conversion = 'y';
            tutneseSyllableLength += 3;
            break;

        case 'z':
            conversion = 'z';
            tutneseSyllableLength += 3;
            break;

        default:
            conversion = syllable.at(0);
            tutneseSyllableLength += 1;
            break;
    }

    return conversion;
}
