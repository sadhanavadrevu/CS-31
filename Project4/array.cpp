//
//  array.cpp
//  Project4
//
//  Created by Sadhana Vadrevu on 10/31/18.
//  Copyright © 2018 Sadhana Vadrevu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);
bool isNonNegative(int n);

int main() {
    
    // appendToAll tests
    string h[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
    assert(appendToAll(h, 5, "hi") == 5 && h[2] == "edhi" && h[4] == "hi" && h[6] == "fiona");
    assert (appendToAll(h, -3, "**") == -1 && h[4] == "hi");
    assert (appendToAll(h, 0, "**") == 0 && h[5] == "eleni");
    
    //lookup tests
    string j[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
    assert(lookup(j, 7, "eleni") == 5);
    assert(lookup(j, 7, "ed") == 2);
    assert(lookup(j, 2, "ed") == -1);
    assert(lookup(j, -4, "ed") == -1);
    assert(lookup(j, 0, "ed") == -1);
    
    //positionOfMax tests
    string p[4] = { "ed" , "ed" , "ed"};
    assert(positionOfMax(j, 7) == 3);
    assert(positionOfMax(p, 2) == -1);
    assert(positionOfMax(j, -4) == -1);
    assert(positionOfMax(j, 0) == -1);
    
    //rotateLeft tests
    string g[4] = { "greg", "gavin", "fiona", "kevin" };
    assert(rotateLeft(g, 3, 1) == 1 && g[2] == "gavin" && g[1] == "fiona");
    assert(rotateLeft(g, -3, 1) == -1);
    assert (rotateLeft(g, 3, -1) == -1);
    assert(rotateLeft(g, 0, 1) == -1);
    assert(rotateLeft(g, 0, 0) == -1);
    assert (rotateLeft(g, 2, 2) == -1);
    assert(differ(j, 4, g, 4) == 1);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "greg?" && g[3] == "kevin?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "gavin?" && g[3] == "fiona?");
    
    //countRuns tests
    string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
    assert(countRuns(d, 5) == 2);
    assert(countRuns(d, 2) == 1);
    assert(countRuns(d, 0) == 1);
    assert(countRuns(d, -4) == -1);
    assert(countRuns(d, 0) == 1);
    
    //flip tests
    assert(flip(d, 4) == 4 && d[0] == "xavier" && d[3] == "gavin" && d[4] == "xavier");
    assert(flip(d, 0) == 0 && d[0] == "xavier");
    assert(flip(d, -3) == -1 && d[3] == "gavin");
    string f[3] = { "fiona", "ed", "john" };
    assert(lookupAny(j, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "john" && f[2] == "fiona");
    
    //differ tests
    string folks[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
    string group[5] = { "betty", "john", "dianne", "", "xavier" };
    assert(differ(folks, 6, group, 5) == 2);
    assert(differ(folks, 2, group, 1) == 1);
    assert(differ(folks, -1, group, 3) == -1);
    assert(differ(folks, 1, group, -3) == -1);
    assert(differ(folks, 0, group, 4) == 0);
    assert(differ(folks, 3, group, 0) == 0);
    
    //subsequence tests
    string e[4] = { "ed", "xavier", "", "eleni" };
    assert(subsequence(j, 7, e, 4) == 2);
    assert(subsequence(j, 4, e, 2) == 2);
    assert(subsequence(j, -1, e, 2) == -1);
    assert(subsequence(j, 4, e, -1) == -1);
    assert(subsequence(j, 0, e, 1) == -1);
    assert(subsequence(j, 4, e, 0) == 0);
    
    //lookUpAny tests
    assert(lookupAny(folks, 6, e, 4) == 2);
    assert(lookupAny(folks, 0, e, 3) == -1);
    assert(lookupAny(folks, 3, e, 0) == -1); 
    assert(lookupAny(folks, -1, e, 3) == -1);
    assert(lookupAny(folks, 4, e, -3) == -1);
    
    //divide tests
    assert(divide(j, 7, "fiona") == 3);
    assert(divide(e, 4, "sally") == 3 && e[3] == "xavier");
    string b[5] = { "sue", "sue", "adam", "", "xavier"};
    assert(divide(b, 5, "sue") == 2 && b[4] == "xavier" && b[3] == "sue");
    assert(divide(b, -3, "") == -1);
    
    cout << "All tests succeeded" << endl;
}


bool isNonNegative(int n) {
    if (n < 0)
        return false;
    return true;
}

int appendToAll(string a[], int n, string value) {
    if (!isNonNegative(n))
        return -1;
    else {
        for (int k = 0; k < n; k++) {
            a[k] += value; // append value to end of term
        }
        return n;
    }
}

int lookup(const string a[], int n, string target) {
    if (!isNonNegative(n))
        return -1;
    else {
        for (int k = 0; k < n; k++) {
            if (a[k] == target)
                return k; // return position of match
        }
        return -1;
    }
}

int positionOfMax (const string a[], int n) {
    if (!isNonNegative(n)) {
        return -1;
    }
    else {
        int counter = 0;
        for (int i = 0; i < n; i++) {
            bool greaterThan = true;
            for (int k = 0; k < n; k++) { // check every term against the specified term
                if (a[i] < a[k]) { // if its ever not greater than the specified term
                    greaterThan = false;
                    break;
                }
                else if (a[i] == a[k]) {
                    counter++;
                }
            }
            if (counter == n)
                return -1;
            if (greaterThan) {
                return i;
            }
        }
        return -1;
    }
}

int rotateLeft (string a[], int n, int pos) {
    if (!isNonNegative(n) || !isNonNegative(pos) || pos >= n)
        return -1;
    else {
        string temp;
        string atPos = a[pos];
        for (int i = pos; i < n-1; i++) {
            temp = a[i];
            a[i]= a[i+1];
        }
        a[n-1] = atPos;
        return pos;
    }
}

int countRuns (const string a[], int n) {
    if (!isNonNegative(n))
        return -1;
    else {
        int count = 1;
        for (int i = 0; i < n-1; i++) {
            if (a[i] != a[i+1]) // every time there is a change in consequtive terms, number of runs go up
                count++;
        }
        return count;
    }
}

int flip (string a[], int n) {
    if (!isNonNegative(n))
        return -1;
    else {
        string temp;
        for (int i = 0; i < n/2; i++) { // swap terms on opposite ends of array
            temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
        return n;
    }
}

int differ (const string a1[], int n1, const string a2[], int n2) {
    if (!isNonNegative(n1) || !isNonNegative(n2))
        return -1;
    else {
        for (int i = 0; i < n1 && i < n2; i++) {
            if (a1[i] != a2[i])
                return i; // return position where arrays are not equal
        }
        // if arrays are equal throughout, return smaller array
        if (n1 <= n2)
            return n1;
        else
            return n2;
    }
}

int subsequence (const string a1[], int n1, const string a2[], int n2) {
    if (!isNonNegative(n1) || !isNonNegative(n2) || n1 < n2)
        return -1;
    else if (n1 == 0 || n2 == 0) {
        return 0;
    }
    else {
        int pos = -1;
        int i = 0;
        while (i < n1) {
            if (a1[i] == a2[0]) { //check where first term of second array is equal to term in first array
                pos = i;
                for (int j = 0; j < n2; j++) {
                    if (a1[i + j] == a2[j]) // checking if terms after first one are also equivalent
                        ;
                    else {
                        pos = -1;
                        break;
                    }
                }
            }
            i++;
        }
        return pos;
    }
}

int lookupAny (const string a1[], int n1, const string a2[], int n2) {
    if (!isNonNegative(n1) || !isNonNegative(n2))
        return -1;
    else {
        for (int i = 0; i < n1; i++) {
            for (int k = 0; k < n2; k++) {
                if (a1[i] == a2[k]) // check each term of each array against each other
                    return i; // return position where they much
            }
        }
        return -1; // if there are no matches, return -1
    }
}

int divide(string a[], int n, string divider) {
    int originalN = n; // saves original n
    if (!isNonNegative(n))
        return -1;
    else {
        int returnValue = 0; //counts number of terms smaller than the divider (also what function returns)
        int greaterThanCounter = 0; // counts number of terms bigger than the divider
        int equalsCounter = 0; // counts number of terms equal to the divider
        for (int i = 0; i < n; i++) {
            if (a[i] < divider) {
                returnValue++;
            }
            else if (a[i] > divider) {
                greaterThanCounter++;
            }
            else if (a[i] == divider) {
                equalsCounter++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] < divider) { // do nothing if terms are less than the divider
                continue;
            }
            else if (a[i] > divider) { // if term is bigger than the divider, push to the end of array
                rotateLeft(a, n, i);
                i--; // re-check what moved into i
                n--; // do not touch this term anymore
            }
            else if (a[i] == divider && (i < returnValue || i > originalN - 1 - greaterThanCounter)) { // if term is equal to divider and terms are not already in position
                if (equalsCounter > 0) { // swap term at i with term at returnValue (where terms equal to divider should be placed)
                    string temp = a[returnValue + equalsCounter - 1];
                    a[returnValue + equalsCounter - 1] = a[i];
                    a[i] = temp;
                    equalsCounter--;
                }
                i--; // re-check what was swapped into i
            }
        }
        return returnValue;
    }
}
