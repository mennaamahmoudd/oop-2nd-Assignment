#include <iostream>
#include <cmath>
using namespace std;
string pattern(string fractal,int n,int i){
    int pwr= int(log(n)/log(2));//2^pwr=n
    //pwr presents the power of 2 to equal n.
    if (pwr==0){//base case
        for (int j = 0; j < i; ++j) {
            fractal+=' ';
            // i represents the begining of columns to print spaces.
        }
        for (int j = 0; j < n; ++j) {
            //n represents 2^ pwr which is equal to 1 in the base case.
            fractal+="* ";
        }
        return fractal+='\n';

    }
    else
    {
       fractal= pattern(fractal,int (::pow(2.0,pwr-1)),i);
       //saving the new pattern according to the new n which represents 2^pwr-1 using recursion
        for (int j = 0; j < i; ++j) {
            fractal+=' ';
        }
        for (int j = 0; j < n; ++j) {
            fractal+="* ";
            //printing the number of starts in each line according to n
        }
        fractal+='\n';
        i+=(pwr*2);
        // increasing the value of i to print spaces
        return pattern(fractal,int (::pow(2.0,pwr-1)),i);
        //recurse the function to reach the base case


    }

}
int main(){
    int n;  //the number of stars at the middle of pattern
    int i; // the start to print spaces
    string shape;// shape that save the pattern
    cin>>n>>i;
  cout<<  pattern(shape,n,i)<<endl;

}