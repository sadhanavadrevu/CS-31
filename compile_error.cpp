//
//  compile_error.cpp
//  Project 1
//  change code so that it is unable to produce poll results

//  Created by Sadhana Vadrevu on 10/5/18.
//  Copyright © 2018 Sadhana Vadrevu. All rights reserved.
//

#include <iostream>
//did not include namespace std

int main  //no parantheses next to main function
{
    int numberSurveyed;
    int forNewsom;
    int forCox  //omitted a semicolon
    
    cout << "How many registered voters were surveyed? ";
    cin >> numberSurveyed;
    cout << "How many of them say they will vote for Newsom? ";
    cin >> forNewsom;
    cout << "How many of them say they will vote for Cox? ";
    cin >> forCox
    
    double pctNewsom = 100.0 * forNewsom / numberSurveyed;
    double pctCox = 100.0 * forCox / numberSurveyed;
    
    cout.precision(1);
    
    cout endl;
    cout << pctNewsom << "% say they will vote for Newsom." << endl;
    cout << pctCox << "% say they will vote for Cox." << endl;
    
    if (forNewsom > forCox)
        cout << "Newsom is predicted to win the election." << endl;
    else
        cout << "Cox is predicted to win the election." << endl;
}
