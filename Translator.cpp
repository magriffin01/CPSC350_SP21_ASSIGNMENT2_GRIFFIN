/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 2
*/

// DELETE AFTER
#include <iostream>

#include <string>
#include "Translator.h"

using namespace std;

Translator::Translator()
{
    
}

Translator::~Translator()
{
    
}

// Takes a single string representing a single English word and returns a string representing the Tutnese translation
string Translator::translateEnglishWord(string englishWord)
{
    // Take in word. check for double characters, convert each character, and return the word
    string translatedCharacter;
    string translatedWord;

    for (int i = 0; i < englishWord.size(); ++i)
    {
        if (isDoubleCharacter(i, englishWord)) // If double character, convert, and increment index to avoid doubling
        {
            translatedCharacter = model.translateDoubleCharacter(englishWord.at(i));
            ++i;
        }
        else
        {
            translatedCharacter = model.translateSingleCharacter(englishWord.at(i));
        }

        translatedWord = translatedWord + translatedCharacter;
    }

    return translatedWord;
}

// Takes a single string representing a single English sentence and returns a string representing Tutnese translation
string Translator::translateEnglishSentence(string englishSentence)
{
    /* Take in sentence, isolate word by checking for whitespace, translate word, append whitespace,
        add to sentence, repeat until done with sentence, return word with newline character */
    string translatedSentence;
    string substringOfSentence;
    int indexOfNextWhitespace = englishSentence.find(' ');
    int indexOfPreviousWhitespace = 0;
    
    /* Get the substring of the sentence from the first letter to the first space, translate that word, add it to the sentence
        update the indices to the next instance of a space and check to see if there are no more spaces, if so end translation */
    do {
        substringOfSentence = englishSentence.substr(indexOfPreviousWhitespace, indexOfNextWhitespace - indexOfPreviousWhitespace);

        translatedSentence = translatedSentence + translateEnglishWord(substringOfSentence);
        
        updateWhitespaceIndices(indexOfPreviousWhitespace, indexOfNextWhitespace, englishSentence);
        
        if (hasNoMoreSpaces(indexOfNextWhitespace))
        {
            translatedSentence.append(" ");
            substringOfSentence = englishSentence.substr(indexOfPreviousWhitespace, englishSentence.size() - indexOfPreviousWhitespace);
            translatedSentence = translatedSentence + translateEnglishWord(substringOfSentence);
            translatedSentence.append("\n");
        }
        else
        {
            translatedSentence.append(" ");
        }
    } while (indexOfNextWhitespace != string::npos);

    return translatedSentence;    
}

// Takes in two indices and a sentence and updates them for spaces
void Translator::updateWhitespaceIndices(int& indexOfPreviousWhitespace, int& indexOfNextWhitespace, string sentence)
{
    indexOfPreviousWhitespace = indexOfNextWhitespace + 1;
    indexOfNextWhitespace = sentence.find(' ', indexOfPreviousWhitespace);
}

// Takes in an index and returns true of false if the index is npos, indicating no spaces
bool Translator::hasNoMoreSpaces(int index)
{
    if (index == string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Takes an index, and the original word and returns true if consecutive characters are the same, otherwise false
bool Translator::isDoubleCharacter(int index, string word)
{
    // Check to see if out of range, if yes return false, if no check characters and return appropriate value
    int nextIndex = index + 1;

    if (word.size() - 1 < nextIndex)
    {
        return false;
    }

    if (tolower(word.at(index)) == tolower(word.at(nextIndex)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Take in a Tutnese word and translate it into English
string Translator::translateTutneseWord(string tutneseWord)
{
    string translatedCharacter;
    string translatedWord;

    for (int i = 0; i < tutneseWord.size(); ++i)
    {
        translatedCharacter = model.translateSyllable(tutneseWord.substr(i, tutneseWord.size() - i));
        i = i + model.getTutneseSyllableLength() - 1;
        translatedWord = translatedWord + translatedCharacter;
        // DELETE AFTER
        cout << translatedWord << endl;
    }

    return translatedWord;
}

// Take in a Tutnese sentence and returns it in English
string Translator::translateTutneseSentence(string tutneseSentence)
{
    string translatedSentence;
    translatedSentence = translateTutneseWord(tutneseSentence) + "\n"; // Add newline at the end for the file
    return translatedSentence;
}

