//
// Created by Makka Lap on 11/5/2023.
//

#include "BigReal.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;


void trimNonSignificantZeros(string& fraction, string& integer) {
    string allZeros(integer.size(), '0');
    // find the first non-zero number in the integer
    int firstNonZero = integer.find_first_not_of('0');
    if (firstNonZero != string::npos) {
        // re-assign the integer excluding the leading zeros
        integer = integer.substr(firstNonZero, integer.size());
    }
    else if (integer == allZeros)
    {
        integer = "0";
    }

    // find the last non-zero number in the fraction
    int lastNonZero = fraction.find_last_not_of('0');
    if (lastNonZero != string::npos) {
        // re-assign the fraction excluding the trailing zeros
        fraction = fraction.substr(0, lastNonZero+1);
    }
}
BigReal::BigReal(string real) {
if (regex_match(real, regex("[+-]?\\d*.?\\d+")))
{
if (real[0] == '-')
{
sign = '-';
if (real[1] == '.')
{
real[0] = '0';
}
else
{
real.erase(real.begin());
}
    
}
    
else if (real[0] == '+')
{
sign = '+';
if (real[1] == '.')
{

    
real[0] = '0';
}
else
{


    
real.erase(real.begin());
}
}
else if (real[0] == '.')
{
real.insert(0, "0");
}

int index = real.find('.');
if (index != string::npos)
{
integer = real.substr(0, index);
fraction = real.substr(integer.size() + 1, real.size() - 1);
}
else
{
integer = real;
}

}
else
{
sign = '+';
integer = "0";
fraction = "0";
}

/*if (integer.size() == 0)
{
    cout << integer.size() << endl;
    integer = "0";
}*/
if (fraction.size() == 0)
{
fraction = "0";
}

trimNonSignificantZeros(fraction, integer);
}
ostream& operator<<(ostream& os, const BigReal& real)
{
    os << real.sign << real.integer << "." << real.fraction << endl;
    return os;
}

bool BigReal :: operator ==(const BigReal& b) {
    if (this->sign == b.sign)
    {
        return (this->integer == b.integer && this->fraction == b.fraction);
    }
    return false;
}

bool operator <(const BigReal& a, const BigReal& b) {

    if (a.sign == '-' && b.sign == '+')
    {
        return true;
    }
    else if (a.sign == '+' && b.sign == '-')
    {
        return false;
    }

    int n = a.integer.size();
    int m = a.fraction.size();

    if (a.sign == '+' && b.sign == '+')
    {
        if (a.integer.size() != b.integer.size())
        {
            return a.integer.size() < b.integer.size();
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (a.integer[i] != b.integer[i])
                {
                    return a.integer[i] < b.integer[i];
                }
            }
        }

        if (a.fraction.size() != b.fraction.size())
        {
            return a.fraction.size() < b.fraction.size();
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                if (a.fraction[i] != b.fraction[i])
                {
                    return a.fraction[i] < b.fraction[i];
                }
            }
        }
    }
    else
    {
        if (a.integer.size() != b.integer.size())
        {
            return b.integer.size() < a.integer.size();
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (a.integer[i] != b.integer[i])
                {
                    return b.integer[i] < a.integer[i];
                }
            }
        }

        if (a.fraction.size() != b.fraction.size())
        {
            return b.fraction.size() < a.fraction.size();
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                if (a.fraction[i] != b.fraction[i])
                {
                    return  b.fraction[i] < a.fraction[i];
                }
            }
        }
    }

    return false;
}
bool BigReal :: compare (string int1 , string int2 , string frac1 , string frac2)
{
    if (int1.size() != int2.size())
    {
        return int1.size() > int2.size();
    }
    else
    {
        for (int i = 0; i < int1.size(); i++)
        {
            if (int1[i] != int2[i])
            {
                return int1[i] > int2[i];
            }
        }
    }
    if (frac1.size() != frac2.size())
    {
        return frac1.size() > frac2.size();
    }
    else
    {
        for (int i = 0; i < frac1.size(); i++)
        {
            if (frac1[i] != frac2[i])
            {
                return frac1[i] > frac2[i];
            }
        }
    }



    return false;
}
bool operator >(const BigReal& a, const BigReal& b) {

    return b < a;
}
//******************************************

BigReal BigReal:: a_plus_b(string int1, string int2, string frac1, string frac2) {

    // plus operation on fraction part

    int carry = 0;
    string result = "";
    for (int i = frac1.size() - 1; i >= 0; i--)
    {

        char temp = carry + frac1[i] + frac2[i]-'0';

        if (temp > '9') {
            carry = 1;
            temp -=10; // get only the last digit
        }
        else
        {
            carry = 0;
        }

        result = temp + result;
    }
    result = '.' + result;

    // plus operation on integer part

    int carry2 = carry;


    for (int i = int1.size() - 1; i >= 0; i--)
    {
        char temp = carry2 + int1[i] +int2[i]-'0';

        if (temp > '9') {
            carry2 = 1;
            temp -= 10; // get only the last digit
        }
        else
        {
            carry2 = 0;
        }

        result = temp + result;
    }

    if (carry2 != 0) result = '1' + result;

    // return the result of sum

    return BigReal(result);
}
BigReal BigReal:: a_minus_b(string int1, string int2, string frac1, string frac2) {

    string result = "";
    for (int i = frac1.size()-1; i >=0 ; i--)
    {
        char temp;
        if (frac1[i] >= frac2[i])
        {
            temp = frac1[i]-frac2[i]+'0';
            result = temp +result;
        }
        else
        {
            if (i == 0)
            {
                if (int1[int1.size()-1] >'0')
                {
                    temp = (frac1[i]+10)-frac2[i]+'0';
                    int1[int1.size()-1]-=1;
                    result = temp +result;
                }
                else
                {
                    int non_zero = i-1;
                    while (int1[non_zero] == '0')
                    {
                        int1[non_zero] += 9;
                        non_zero--;
                    }
                    int1[non_zero]-=1;
                    temp = frac1[i]+10 - frac2[i]+'0';
                    result = temp +result;
                }


            }

            else if (frac1[i-1] > '0' && i != 0)
            {
                temp = frac2[i]-frac1[i]+'0';
                frac1[i-1] -=1;
                result = temp +result;
            }
            else
            {

                int non_zero = i-1;
                while (frac1[non_zero] == '0' && non_zero != 0)
                {
                    frac1[non_zero] += 9;
                    non_zero--;
                }
                frac1[non_zero]-=1;
                temp = (frac1[i]+10) - frac2[i]+'0';
                result = temp +result;
            }

        }


    }
    result = "."+result;
    for (int i = int1.size()-1; i >= 0; i--)
    {
        char temp;
        if (int1[i] >= int2[i])
        {
            temp = int1[i]-int2[i]+'0';
            result = temp +result;
        }
        else
        {

            if (int1[i-1] > '0' && i != 0)
            {
                temp = int2[i]-int1[i]+'0';
                int1[i-1] -=1;
                result = temp +result;
            }
            else
            {

                int non_zero = i-1;
                while (int1[non_zero] == '0' && non_zero != 0)
                {
                    int1[non_zero] += 9;
                    non_zero--;
                }
                int1[non_zero]-=1;
                temp = (int1[i]+10) - int2[i]+'0';
                result = temp +result;
            }
        }

    }

    return BigReal(result);
}

BigReal BigReal:: neg_a_plus_b(string int1, string int2, string frac1, string frac2) {

    BigReal result = a_plus_b(int1, int2, frac1, frac2);
    result.sign = '-';

    return result;
}

BigReal BigReal:: operator +( BigReal& b) {

    string int1 = this->integer;
    string int2 = b.integer;
    string frac1 = this->fraction;
    string frac2 = b.fraction;

    // add any additional zeros to ease the plus operation

    if (int1.size() > int2.size())
    {
        // make a string contains the needed additional '0'
        string zeros(int1.size() - int2.size(), '0');
        // insert these zeros at the beginning of integer
        int2.insert(0, zeros);
    }
    else if (int1.size() < int2.size())
    {
        string zeros(int2.size() - int1.size(), '0');
        int1.insert(0, zeros);
    }

    if (frac1.size() > frac2.size())
    {
        // append from the end the needed zeros
        frac2.append(frac1.size() - frac2.size(), '0');
    }
    else if (frac1.size() < frac2.size())
    {
        frac1.append(frac2.size() - frac1.size(), '0');
    }

    // check the signs of the operands and call the suitable function

    if (this->sign == b.sign && this->sign == '+')  // (+A) + (+B) ==> A + B
    {
        return a_plus_b(int1, int2, frac1, frac2);
    }
    else if (this->sign == '+' && b.sign == '-') // (+A) + (-B) ==> A - B
    {

        if (compare(int1,int2,frac1,frac2))
        {
            return a_minus_b(int1,int2,frac1,frac2);
        }
        else
        {
            BigReal r = a_minus_b(int2,int1,frac2,frac1);
            r.sign = '-';
            return r;
        }


    }

    else if (this->sign == b.sign && this->sign == '-') // (-A) + (-B) ==> -(A+B)
    {
        return neg_a_plus_b(int1, int2, frac1, frac2);
    }

}

BigReal BigReal:: operator -(BigReal& b) {

    string int1 = this->integer;
    string int2 = b.integer;
    string frac1 = this->fraction;
    string frac2 = b.fraction;

    // add any additional zeros to ease the minus operation

    if (int1.size() > int2.size())
    {
        // make a string contains the needed additional '0'
        string zeros(int1.size() - int2.size(), '0');
        // insert these zeros at the beginning of integer
        int2.insert(0, zeros);
    }
    else if (int1.size() < int2.size())
    {
        string zeros(int2.size() - int1.size(), '0');
        int1.insert(0, zeros);
    }

    if (frac1.size() > frac2.size())
    {
        // append from the end the needed zeros
        frac2.append(frac1.size() - frac2.size(), '0');
    }
    else if (frac1.size() < frac2.size())
    {
        frac1.append(frac2.size() - frac1.size(), '0');
    }

    // check the signs of the operands and call the suitable function

    if (this->sign == b.sign && this->sign == '+')  // (+A) - (+B) ==> A - B
    {
        if (compare(int1,int2,frac1,frac2))
        {
            return a_minus_b(int1,int2,frac1,frac2);
        }
        else
        {
            BigReal r = a_minus_b(int2,int1,frac2,frac1);
            r.sign = '-';
            return r;
        }
    }
    else if (this->sign == '+' && b.sign == '-') // (+A) - (-B) ==> A + B
    {
        return a_plus_b(int1, int2, frac1, frac2);
    }
    else if (this->sign == '-' && b.sign == '+') // (-A) - (+B) ==> - (A+B)
    {
        return neg_a_plus_b(int1, int2, frac1, frac2);
    }
    else if (this->sign == b.sign && this->sign == '-') // (-A) - (-B) ==> B - A
    {
        if (compare(int2,int1,frac2,frac1))
        {
            return a_minus_b(int2,int1,frac2,frac1);
        }
        else
        {
            BigReal r = a_minus_b(int1,int2,frac1,frac2);
            r.sign = '-';
            return r;
        }
    }

}

