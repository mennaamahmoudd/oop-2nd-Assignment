
//Names                     ID           Emails
//Shahd Mohammed Mahmoud  20221086     moh861368@gmail.com
//Hasnaa Ahmed Eltahlawy   20221232    hasnaa02ahmed@gmail.com
//Menna Mahmoud Abass      20221234    mennaalmoazamy10@gmail.com
//section 20,19
#include <iostream>
#include "BigReal.h"

using namespace std;
int main() {
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << n3<<endl;
    BigReal n4("0.9");
    n3=n3+n4;
    cout << n3;
    return 0;
}