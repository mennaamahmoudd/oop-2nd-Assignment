//
// Created by Makka Lap on 11/5/2023.
//

#ifndef INC_32_BIGREAL_H
#define INC_32_BIGREAL_H
#include <iostream>
#include <string>
#include <regex>

using namespace std;

class BigReal {
private:
    char sign = '+';
    string integer = "", fraction = "";
public:

    BigReal(string real);


    friend ostream& operator<< (ostream& os, const BigReal& real);
    bool operator==(const BigReal& b);
    friend bool operator >(const BigReal& a, const BigReal& b);
    friend bool operator <(const BigReal& a, const BigReal& b);
    bool compare (string int1 , string int2 , string frac1 , string frac2);

    BigReal a_plus_b(string int1, string int2, string frac1, string frac2); // A+B
    BigReal a_minus_b(string int1, string int2, string frac1, string frac2); // (A-B)
    BigReal neg_a_plus_b(string int1, string int2, string frac1, string frac2); // -(A+B)

    BigReal operator +(BigReal& b);
    BigReal operator -(BigReal& b);





};


#endif //INC_32_BIGREAL_H
