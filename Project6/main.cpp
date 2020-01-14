//
//  main.cpp
//  Project6
//
//  Created by Sadhana Vadrevu on 11/23/18.
//  Copyright © 2018 Sadhana Vadrevu. All rights reserved.
//

// return true if two C strings are equal

#include <iostream>
using namespace std;

int main()
{
    int arr[3] = { 5, 10, 15 };
    int* ptr = arr;
    
    *ptr = 30;          // set arr[0] to 30
    *(ptr + 1) = 20;      // set arr[1] to 20
    ptr += 2;
    ptr[0] = 10;        // set arr[2] to 10
    
    ptr = arr;
    while (ptr < arr + 3)
    {
        cout << *ptr << endl; // print values
        ptr++;
    }
}


