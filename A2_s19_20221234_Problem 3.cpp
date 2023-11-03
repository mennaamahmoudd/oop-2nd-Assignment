//A2_s19_20221234_Problem 3.cpp
//purpose: Teddy Bear Picnic: Build a game with teddy bears.
//Author: Menna Allah Mahmoud Abbas Mahmoud
// Section: S19
// ID: 20221234
// TA: eng.Mohammed Talaat
// Date: 26 Oct 2023


//PROBLEM 3

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string word , const string& delimiter) {
    vector<string> v;
    string s;
    int count = 0; //counter to be used to allow the delimiter to be a word instead of splitting just a character
    while (count <= word.size()) {
        if (word.substr(count, delimiter.size()) == delimiter) {
            v.push_back(s);
            s.clear();
            count += delimiter.size();
        } else {
            s += word[count];
            count++;
        }
    }

    v.push_back(s);
    return v;
}

int main() {
    string wordd,delim;
    cout<< " enter a word to be splitted";
    getline(cin, wordd);
    cout << "enter a delmiter";
    // getline is used to allow accepting the input if it is a space
    getline(cin, delim);
    //calling the split function
    vector<string>result1 = split(wordd,delim);

    for (const auto & i : result1) {
        cout<<i<<' '<<endl;
        //cout<<'"'<<i<<'"'<<',';
    }
}

// this code succes in splitting but it had a problem that it does not remove the delimiter if it is a word
// it just splits the first character of the input delimiter


/*
    vector<string> split(string word , const string& delimiter){
    vector<string> result ;

    int messageSize = word.size();
    int delimiterSize = delimiter.size();
    string temp ;
    for (int i = 0; i < messageSize; ++i) {
        if(i+delimiterSize<=messageSize){
            if(word.substr(i,delimiterSize)==delimiter)
            {
                // push current word into the vector
                result.push_back(temp);
                // clear temp variable to store next word
                temp.clear();
                continue;
            }
        }
        // adding character to the current word until we find delimiter
        temp+=word[i];

    }
    // if there is a word at the end with no delimiter after it eg: (10,20,30) -> 30 isn't followed by delimiter
    if(!temp.empty())
        result.push_back(temp);
    return result;
}

*/
