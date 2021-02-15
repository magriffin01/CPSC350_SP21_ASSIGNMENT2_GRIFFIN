/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 2
*/

#include <iostream>
// #include "FileProcessor.h"
#include "Model.h"

using namespace std;

int main(int argc, char **argv)
{
    // FileProcessor fileProcessor;
    // fileProcessor.processFile(argv[1], argv[2]);

    Model model;
    cout << model.translateSyllable("Bub") << endl;
    cout << model.translateSyllable("Cash") << endl;
    cout << model.translateSyllable("Dud") << endl;
    cout << model.translateSyllable("Fuf") << endl;
    cout << model.translateSyllable("Gug") << endl;
    cout << model.translateSyllable("Hash") << endl;
    cout << model.translateSyllable("Jay") << endl;
    cout << model.translateSyllable("kuck") << endl;
    cout << model.translateSyllable("lul") << endl;
    cout << model.translateSyllable("mum") << endl;
    cout << model.translateSyllable("nun") << endl;
    cout << model.translateSyllable("pub") << endl;
    cout << model.translateSyllable("quack") << endl;
    cout << model.translateSyllable("rug") << endl;
    cout << model.translateSyllable("squasus") << endl;
    cout << model.translateSyllable("squatut") << endl;
    cout << model.translateSyllable("squavuv") << endl;
    cout << model.translateSyllable("squawack") << endl;
    cout << model.translateSyllable("squaex") << endl;
    cout << model.translateSyllable("Squayub") << endl;
    cout << model.translateSyllable("Squazub") << endl;
    cout << model.translateSyllable("a") << endl;
    cout << model.translateSyllable("e") << endl;
    cout << model.translateSyllable("Squati") << endl;
    cout << model.translateSyllable("squato") << endl;
    cout << model.translateSyllable("u") << endl;

    return 0;
}