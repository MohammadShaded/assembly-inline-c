// reduce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <stdio.h>

int reduce(int num, int denom) {

    if (num * denom == 0) {
        return 0;
        cout << "fraction error";
    }
    else {
        int gcd;
        _asm {
            mov eax, num
            mov ebx, denom
            start :
            cmp eax, ebx
                je gcd_found
                jb swapp
                sub eax, ebx
                jmp start
                swapp :
            xchg eax, ebx
                jmp start

                gcd_found :
            mov gcd, eax
        }

        num /= gcd;
        denom /= gcd;
        
        cout << num << "/" << denom;


    }
    return 1;
}

int main()
{

    int num1, num2;
    cout << "Enter first integer: "<<endl;
    cin >> num1;
    cout << "Enter second integer: " << endl;
    cin >> num2;

    reduce(num1, num2);
    return 0;
}
