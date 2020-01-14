//
//  rate.cpp
//  Project5
//
//  Created by Sadhana Vadrevu on 11/7/18.
//  Copyright © 2018 Sadhana Vadrevu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cassert>
#include <cctype>
using namespace std;

const int MAX_WORD_LENGTH = 20;

int makeProper(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns);
int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns);
void removePattern(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns, int pos);

int main () {
    const int TEST1_NRULES = 9;
    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "mad", "deranged", "hello", "NEFARIOUS", "half-witted", "robot", "plot", "", "NeFaRiOus"
    };
    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "mad", "robot", "there", "PLOT", "as4istant", "deranged", "Nefarious", "mad", "pLoT"
    };
    int test1dist[TEST1_NRULES] = {
        1, 3, -7, 0, 2, 6, 4, 12, 0
    };

    assert (makeProper(test1w1, test1w2, test1dist, TEST1_NRULES) == 3);
    for (int i = 0; i < 3; i++) {
        cout << test1w1[i] << "      " << test1w2[i] << "      " << test1dist[i] << endl;
    }
    assert(strcmp(test1w1[0], "mad") == 0);
    assert(strcmp(test1w2[1], "deranged") == 0);
    assert(test1dist[1] == 6);
    assert (makeProper(test1w1, test1w2, test1dist, 0) == 0);
    assert (makeProper(test1w1, test1w2, test1dist, -5) == 0);
    const int TEST2_NRULES = 4;
    char test2w1[TEST2_NRULES][MAX_WORD_LENGTH+1] = {
        "mad",       "deranged", "nefarious", "have"
    };
    char test2w2[TEST2_NRULES][MAX_WORD_LENGTH+1] = {
        "scientist", "robot",    "plot",      "mad"
    };
    int test2dist[TEST2_NRULES] = {
        1,           3,          0,           12
    };
    assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot       ",
                test2w1, test2w2, test2dist, TEST2_NRULES) == 2);
    assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.", test2w1, test2w2, test2dist, 0) == 0); //rate handles 0 patterns correctly
    assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.", test2w1, test2w2, test2dist, -3) == 0); //rate handles a negative number of patterns correctly
    assert(rate("The mad UCLA scientist unleashed    a deranged robot.",
                test2w1, test2w2, test2dist, TEST2_NRULES) == 2);
    assert(rate("**** 2018 ****",
                test2w1, test2w2, test2dist, TEST2_NRULES) == 0);
    assert(rate("  That plot: NEFARIOUS!",
                test2w1, test2w2, test2dist, TEST2_NRULES) == 1);
    assert(rate("deranged deranged robot deranged robot robot",
                test2w1, test2w2, test2dist, TEST2_NRULES) == 1);
    assert(rate("That scientist said two mad scientists suffer from deranged-robot fever.",
                test2w1, test2w2, test2dist, TEST2_NRULES) == 0);
    
    cout << "All tests succeeded" << endl;
}

bool isAllLetters(char word[]) { //checks that a c-string is all letters
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

void removePattern(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns, int pos) { //removes pattern at position pos from array
    
    char tempword1[MAX_WORD_LENGTH + 1];
    strcpy(tempword1, word1[pos]);
    char tempword2[MAX_WORD_LENGTH + 1];
    strcpy(tempword2, word2[pos]);
    int tempseparation = separation[pos];
    for (int k = pos; k < nPatterns - 1; k++) {
        strcpy(word1[k], word1[k+1]);
        strcpy(word2[k], word2[k+1]);
        separation[k] = separation[k+1];
    }
    strcpy(word1[nPatterns - 1], tempword1);
    strcpy(word2[nPatterns - 1], tempword2);
    separation[nPatterns - 1] = tempseparation;
}

int makeProper(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns) {
    
    if (nPatterns < 0)
        nPatterns = 0;
    
    for (int i = 0; i < nPatterns; i++) {
        for (int k = 0; k <= MAX_WORD_LENGTH; k++) {
            word1[i][k] = tolower(word1[i][k]);
            word2[i][k] = tolower(word2[i][k]);
        }
    }
    
    for (int i = 0; i < nPatterns; i++) {
        
        if (strlen(word1[i]) == 0 || strlen(word2[i]) == 0) {
            removePattern(word1, word2, separation, nPatterns, i);
            nPatterns--;
            i--;
        }
        
        else if (!isAllLetters(word1[i]) || !isAllLetters(word2[i])) { //remove pattern if either word contains a character that isn't a letter
            removePattern(word1, word2, separation, nPatterns, i);
            nPatterns--;
            i--;
        }
            
        else if (separation[i] < 0) { //remove pattern if separation is negative
            removePattern(word1, word2, separation, nPatterns, i);
            nPatterns--;
            i--;
        }
        
        else {
            int pos = i;
            char w1[MAX_WORD_LENGTH+1];
            strcpy(w1, word1[i]);
            char w2[MAX_WORD_LENGTH+1];
            strcpy(w2, word2[i]);
            int sep = separation[i];
            
            //check if there are any repeats in the pattern array
            for (int k = i + 1; k < nPatterns; k++) {
                if (strcmp(w1, word1[k]) == 0 && strcmp(w2, word2[k]) == 0) {
                    if (sep >= separation[k]) { //remove pattern with smaller separation
                        removePattern(word1, word2, separation, nPatterns, k);
                        nPatterns--;
                    }
                    else {
                        removePattern(word1, word2, separation, nPatterns, i);
                        nPatterns--;
                        pos = i - 1; //if pattern at i gets removed, have to check what is at that position now
                    }
                }
                else if (strcmp(w1, word2[k]) == 0 && strcmp(w2, word1[k]) == 0) {
                    if (sep >= separation[k]) { //remove pattern with smaller separation
                        removePattern(word1, word2, separation, nPatterns, k);
                        nPatterns--;
                    }
                    else {
                        removePattern(word1, word2, separation, nPatterns, i);
                        nPatterns--;
                        pos = i - 1; //if pattern at i gets removed, have to check what is at that position now
                    }
                }
            }
            i = pos;
        }
    }
    return nPatterns;
}

int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns) {
    
    const int MAX_DOCUMENT_LENGTH = 250;
    char editedDocument[MAX_DOCUMENT_LENGTH+1] = "";
    int pos = 0;
    
    //remove all non-letters and non-spaces from document
    for (int i = 0; document[i] != '\0'; i++) {
        if (isalpha(document[i]) || document[i] == ' ') {
            editedDocument[pos] = tolower(document[i]);
            pos++;
        }
    }
    editedDocument[pos] = '\0'; //all c-strings end with null character
    
    char wordList[MAX_DOCUMENT_LENGTH+1][MAX_DOCUMENT_LENGTH+1];
    char word[MAX_DOCUMENT_LENGTH+1];
    int wordNum = 0; //number of words in document
    int j = 0;
    //create a 2-D array that contains a list of words in the document
    for (int i = 0; editedDocument[i] != '\0'; i++) {
        if (isalpha(editedDocument[i])) {
            word[j] = editedDocument[i];
            j++;
        }
        else {
            word[j] = '\0';
            if (strlen(word) == 0) //to ensure double spaces are dealt with correctly
                ;
            else {
                strcpy(wordList[wordNum], word);
                wordNum++;
                strcpy(word, "");
                j = 0;
            }
        }
    }
    //adding last word to array in case there is no space following it
    word[j] = '\0';
    strcpy(wordList[wordNum], word);
    wordNum++;
    
    
    int matches = 0;
    for (int p = 0; p < nPatterns; p++) { // run through patterns
        for (int i = 0; i < wordNum; i++) { // check each word in wordList
            int ogMatches = matches;
            if (strcmp(wordList[i], word1[p]) == 0) { //if word in wordList matches a word in pattern array
                for (int k = 0; k <= separation[p]; k++) {
                    if (i - k - 1 >= 0) { // make sure index is within the bounds
                        if (strcmp(wordList[i - k - 1], word2[p]) == 0) { // check if words "separation" or less positions before word at i are equal to the next word in the pattern
                            matches++;
                            break; //only need to find one match per pattern
                        }
                    }
                    if (i + k + 1 < wordNum) { // make sure index is within the bounds
                        if (strcmp(wordList[i + k + 1], word2[p]) == 0) { // check if words "separation" or less positions after word at i are equal to the next word in the pattern
                            matches++;
                            break; //only need to find one match per pattern
                        }
                    }
                }
            }
            else if (strcmp(wordList[i], word2[p]) == 0) { //if word in wordList matches word2 in pattern array
                for (int k = 0; k <= separation[p]; k++) {
                    if (i - k - 1 >= 0) {
                        if (strcmp(wordList[i - k - 1], word1[p]) == 0) { // check if words "separation" or less positions before word at i are equal to the next word in the pattern
                            matches++;
                            break; //only need to find one match per pattern
                        }
                    }
                    if (i + k + 1 < wordNum) {
                        if (strcmp(wordList[i + k + 1], word2[p]) == 0) { // check if words "separation" or less positions after word at i are equal to the next word in the pattern
                            matches++;
                            break; //only need to find one match per pattern
                        }
                    }
                }
            }
            if (matches != ogMatches) { // if a match is found, move on (don't keep checking through wordList)
                break;
            }
        }
    }
    return matches;
}
