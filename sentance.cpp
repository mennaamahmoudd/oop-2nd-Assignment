#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main (){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int i=0,j=0;
    char sentence[100],result[100];
    cout<<"Please enter the sentence: ";
    cin.getline(sentence,100);//cin the sentence from the usre
    while( sentence[i] !='.'){//while loop will end if reach the end of the sentence (.)
        if(!(sentence[i]==' ' && sentence[i+1]==' ')){//if there is no multiple spaces it will
            // store it in the result string
            result[j]=sentence[i];
            j++;
        }
        i++;
    }
    for(i=1;result[i]!='.';i++){
        if(int (result[i])>=65&& int(result[i])<=90){//here to make all letters small alphabets
            result[i]=char(int(result[i])+32);
        }
        if(int(result[0])>=97&&int(result[0])<=122){//check if the first letter is small or not
            result[0]=char(int(result[0])-32);//if it small make it capital
        }
    }
    result[j]='.';//add(.)to the sentence because it is expresses the end of the sentence
    cout<<"The sentence after editing is : "<<result;
}
