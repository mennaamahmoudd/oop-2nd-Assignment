//A2_s19_20221234_Problem 6.cpp
//purpose: write 2 printing functions: 1. Decimal to binary  2. Binary modifying
//Author: Menna Allah Mahmoud Abbas Mahmoud
// Section: S19
// ID: 20221234
// TA: eng.Mohammed Talaat
// Date: 25 Oct 2023


#include <bits/stdc++.h>
using namespace std;
//function print_set takes a prefix string, an array of integers (set), and the size of the array (n).
// It prints the prefix string followed by the elements of the set array,
// separated by spaces, and then adds a newline character.
void print_set(const string& prefix, int set[], int n)
{
    cout << prefix;
    //loop to print the individual elements of the set array, which represents a combination of 0s and 1s
    for (int i = 0; i < n; i++) {
        cout << set[i] << "";
    }
    cout << endl;
}

//function decimal_to_binary takes a decimal number (num) as input
// recursively converts it to binary.
int decimal_to_binary(int num){
    if( num == 0){
        return 0;
    }
    else
        //It uses the modulo operator % to determine the remainder when dividing num by 2.
        // The function recursively calls itself with num/2 and multiplies the result by 10
        // to shift the digits to the left.
        // Finally, it adds the remainder to the result.
        // The recursion stops when num becomes 0.
        return ((num % 2) + (10 * decimal_to_binary(num/2)));

}

//generates all possible combinations of 0s and 1s of length n using a backtracking algorithm.
//takes a prefix string, the length of the combination (n),
// an array of integers (arr), and the current index (i) as input.
void print_probabilities(string prefix,int n, int arr[], int i)
{
    if (i == n) {
        //i reaches n, it calls the print_set function to print the generated combination.
        print_set(prefix,arr, n);
        return;
    }
    //starts with setting arr[i] to 0, recursively calls itself with i+1
    arr[i] = 0;
    print_probabilities(prefix,n, arr, i + 1);
    // sets arr[i] to 1 and recursively calls itself again with i+1.
    arr[i] = 1;
    print_probabilities(prefix,n, arr, i + 1);
}

int main() {
    while (true) {
        int option;
        cout << "1- Decimal to binary" << endl
             << "2- Binary modifying" << endl
             << "3- Exit" << endl;
        cin >> option;
        cout << "-----------------------------------------------" << endl;
        if (option == 1) {
            int num;
            cout << "Enter number in decimal" << endl;
            cin >> num;
            cout << "number in binary = "
                 << decimal_to_binary(num) << endl
                 << "-----------------------------------------------" << endl;
        }
        else if (option == 2){
            int num;
            string prefix;
            cout << "Enter the binary num : " << endl;
            cin >> prefix;
            cout << "Enter number : " << endl;
            cin >> num;
            int set[num];
            print_probabilities(prefix,num, set, 0);
            cout << "-----------------------------------------------" << endl;
        }
        else if (option == 3){
            cout << "Program end" << endl
                 << "-----------------------------------------------" << endl;
            break;
        }
        else{
            cout << "Enter 1 or 2 or 3 only" << endl;
            cout << "-----------------------------------------------" << endl;
        }
    }
    return 0;
}