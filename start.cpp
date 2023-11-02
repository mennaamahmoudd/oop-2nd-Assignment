#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void is_prime(int n){
    int prime[n+1];
    for(int i=0;i<=n;i++){
        prime[i]=1;//make all array=1;
    }
    prime[0]=0;
    prime[1]=0;
    //make the first and the second element=0 because they are not prime numbers(0,1)
    int m= sqrt(n);
    for(int i=2;i<=m;i++){
        if(prime[i]==1){//that mean it's prime
            for(int j=i*i;j<=n;j+=i)//here i make j starts from the factors of i because the factors
                // are not primes because they dividable by them and i;
                prime[j]=0;//delete all factors of i (make them =0)
        }
    }
    for(int i=0;i<=n;i++){
        if(prime[i]==1){
            cout<<i<<',';//print all prime numbers (with content 1)
        }
    }
    cout<<endl;
}
int main()
{
    int n;//it is the limit of the last number
    cout<<"please enter the limit :";
    cin>>n;
    cout<<"the prime numbers are: ";
    is_prime(n);
}