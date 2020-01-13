//
//  logic_error.cpp
//  Project 1
//  report poll results inaccurately

//  Created by Sadhana Vadrevu on 10/5/18.
//  Copyright © 2018 Sadhana Vadrevu. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int numberSurveyed;
    int forNewsom;
    int forCox;
    
    cout << "How many registered voters were surveyed? ";
    cin >> numberSurveyed;
    cout << "How many of them say they will vote for Newsom? ";
    cin >> forNewsom;
    cout << "How many of them say they will vote for Cox? ";
    cin >> forCox;
    
    double pctNewsom = 100.0 * forNewsom / numberSurveyed;
    double pctCox = 100.0 * forCox / numberSurveyed;
    
    cout.setf(ios::fixed);
    cout.precision(1);
    
    cout << endl;
    cout << forNewsom << "% say they will vote for Newsom." << endl; //shows number of voters for Newsom rather than the accurate percentage of voters
    cout << pctCox << "% say they will vote for Cox." << endl;
    
    if (forNewsom < forCox) //switched inequality so that result would be wrong, smaller number wins
        cout << "Newsom is predicted to win the election." << endl;
    else
        cout << "Cox is predicted to win the election." << endl;
}

