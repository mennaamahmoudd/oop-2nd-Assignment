#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#include <bits/stdc++.h>
string converted_words(const string& word){
    //specializing the words that must be converted
    const string& converted_word = word;
    if(converted_word=="He")
        return "He or she";
    else if(converted_word=="he")
        return "he or she";
    else if(converted_word=="Him")
        return "Him or her";
    else if(converted_word=="him")
        return "him or her";
    else if(converted_word=="His")
        return "His or her";
    else if(converted_word=="his")
        return "his or her";

    return word;
}
string converted_sentence(const string& sentence){
    //defining a function to get the sentence and convert the words to pronouns
    istringstream iss(sentence);
    string word;
    vector<string>converted_sentence;
    while (iss>>word){
        //using iss to get each word from the sentence and save it in vector
        char last=word.back();
        string punctuation;
        if(ispunct(last)){
            //testing if the last letter of the word is a punctuation mark
            punctuation= string(1,last);
            word = word.substr(0,word.length()-1);
            //using substring to save the word without a punctuation

        }
        string converted_word = converted_words(word);
        // using the function to convert the word to pronouns

        converted_sentence.push_back(converted_word+punctuation);
        //adding the converted words in the vector

    }
    ostringstream oss;
    for (const string& converted_word:converted_sentence ){
        //using oss to output each word in the converted sentence
        oss<<converted_word<<" ";

    }
    return oss.str();

}

int main(){
string sentence;
cout<<"Please, Enter the sentence : "<<endl;
    getline(cin,sentence);
    string converted;
    converted= converted_sentence(sentence);
    //saving the converted sentence in a string 
    cout<<"The converted sentence : "<<endl;
    cout<<converted;

}
