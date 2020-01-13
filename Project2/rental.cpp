//
//  rental.cpp
//  Project2
//
//  Created by Sadhana Vadrevu on 10/10/18.
//  Copyright © 2018 Sadhana Vadrevu. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;

void printHyphens () { // function prints line of three hyphens without any spaces
    cout << "---" << endl;
}

int main () {
    
    // establishing all major variables
    int startingMiles;
    int endingMiles;
    int rentalDays;
    string customerName;
    string luxuryStatus;
    int month;
    double rentalCharge;
    
    // gather starting odometer reading
    cout << "Odometer at start: ";
    cin >> startingMiles;
    // if user inputs negative starting reading, program will print error line
    if (startingMiles < 0) {
        printHyphens();
        cout << "The starting odometer reading must be nonnegative." << endl;
        return 1; // exit the program
    }
    
    // gather ending odometer reading
    cout << "Odometer at end: ";
    cin >> endingMiles;
    // if ending odometer reading is less than the starting reading, program will print error line
    if (endingMiles < startingMiles) {
        printHyphens();
        cout << "The final odometer reading must be at least as large as the starting reading." << endl;
        return 1;
    }
    
    // gather number of rental days
    cout << "Rental Days: ";
    cin >> rentalDays;
    cin.ignore(10000, '\n'); // clears
    // if number of rental days is not positive, program will print error line
    if (rentalDays <= 0) {
        printHyphens();
        cout << "The number of rental days must be positive." << endl;
        return 1;
    }
    
    // gather costumer's name
    cout << "Customer name: ";
    getline(cin, customerName);\
    // if customer does not enter a name, program will print error line
    if (customerName.length() == 0) {
        printHyphens();
        cout << "You must enter a customer name." << endl;
        return 1;
    }
    
    // gather luxury status
    cout << "Luxury car? (y/n): ";
    getline(cin, luxuryStatus);
    // if luxury status is not y or n, program will print error line
    if (!(luxuryStatus == "y" || luxuryStatus == "n")) {
        printHyphens();
        cout << "You must enter y or n." << endl;
        return 1;
    }
    
    // gather month the rental started
    cout << "Month (1=Jan, 2=Feb, etc.): ";
    cin >> month;
    // if month is not an integer between 1 and 12 inclusive, program will print error line
    if (month < 1 || month > 12) {
        printHyphens();
        cout << "The month number must be in the range 1 through 12." << endl;
        return 1;
    }
    
    // calculates rental rate
    int milesDriven = endingMiles - startingMiles;
    double additionalCharge; // charge based on miles driven
    double baseCharge; // base line charge based on luxury status of the car
    
    // calculating baseCharge
    if (luxuryStatus == "y") // if car has luxury status
        baseCharge = 61 * rentalDays;
    else // if car does not have luxury status
        baseCharge = 33 * rentalDays;
    
    // calculating additionalCharge
    if (month == 12 || month <= 4) { // if rental starts in a winter month
        if (milesDriven <= 400)
            additionalCharge = milesDriven * 0.27; // rate per mile driven is $0.27 for every mile under 400 miles
        else
            additionalCharge = (0.27*400) + (0.19 * (milesDriven - 400)); // first 400 miles have a rate of $0.27/mile and every mile after has a rate of $0.19/mile
    }
    else { // if rental does not start in a winter month
        if (milesDriven <= 100)
            additionalCharge =  milesDriven * 0.27; // rate per mile for the first 100 miles is $0.27/mile
        else if (milesDriven > 100 && milesDriven <= 400)
            additionalCharge = (100 * 0.27) + (0.21 * (milesDriven - 100)); // rate for first 100 miles is $0.27/mile and the next 300 miles have a rate of $0.21/mile
        else
            additionalCharge = (100 * 0.27) + (0.21 * 300) + (0.19 * (milesDriven - 400)); // every mile driven beyond 400 miles has a rate of $0.19/mile
    }
    
    rentalCharge = baseCharge + additionalCharge;
    cout.setf(ios::fixed);
    cout.precision(2);
    printHyphens();
    cout << "The rental charge for " << customerName << " is $" << rentalCharge << endl;

}
