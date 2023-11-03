//A2_s19_20221234_Problem 9.cpp
//purpose: Teddy Bear Picnic: Build a game with teddy bears.
//Author: Menna Allah Mahmoud Abbas Mahmoud
// Section: S19
// ID: 20221234
// TA: eng.Mohammed Talaat
// Date: 26 Oct 2023

#include <bits/stdc++.h>
using namespace std;

bool bear(long long n){
    //calculates the product of the last digit and the second-to-last digit of n
    // and stores it in the variable ltd.
    long long ltd = (n % 10) * ((n % 100) / 10);
    //first if statement checks n is less than 42. function returns false (0)
    if(n < 42){
        // to indicate that the number is not a valid "bear number
        return 0;
    }
    if(n == 42){
        cout << "valid\n";
        return 1;
    }
    // third if statemnet cheks if n is even and dividing it by 2 results in a valid bear number
    // (determined by recursively calling the bear function).
    // If both conditions are true, the function prints the calculation and returns true.

    if( n % 2 == 0 && bear(n/2) ){
        cout << "x / 2 = " << n << " / " << 2  << " = " << n/2 << '\n';
        return 1;
    }

    // forth if statement checks if ltd is greater than 0, and if n is divisible by either 3 or 4
    // if subtracting ltd from n results in a valid bear number
    //  If all conditions are true, the function prints the calculation and returns true.
    if( ltd > 0 && ( n % 4 == 0 || n % 3 == 0 ) && bear(n - ltd) ){
        cout << "x - ltd of last two digits = " <<  n << " - " << ltd  << " = " << n - ltd << '\n';
        return 1;
    }
    //last if statement checks n is divisible by 5, if subtracting 42 from n results in a valid bear number
    //prints the calculation and returns true.
    if(n % 5 == 0 && bear(n-42)){
        cout << "x - 42 = " <<  n << " - " << 42  << " = " << n - 42 << '\n';
        return 1;
    }
    return 0;
}

int main(){
    //Clears the console screen using the system("cls") command.
    system("cls");
    cout << "enter a number : ";
    long long n;   cin >> n;
    if(!bear(n))
        cout << "not valid";
}
