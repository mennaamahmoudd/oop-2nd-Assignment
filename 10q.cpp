#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<string, string>> alternative {{u8"فلسطين",  u8"ف.ل.س.ط.ي.ن الح.ب.ي.به"},
                                              {u8"غزة",u8"غ.ز.ة"},{u8"اسرائيل", u8"اس.رائ.ي.ل"},
                                              {u8"قتل",     u8"ق.ت.ل"},{u8"الصهاينة", u8"الص.ه.اي.نة"}};
    //in this vector the words and their alternatives
    string filename, line;
    cout << "enter the file name:";//the user enter the file name
    cin >> filename;
    ifstream file;
    file.open(filename);
    if (file.fail()) {//if there is an error to open the file
        cout << "failed to open file";
        return 1;
    }
    ofstream output;
    output.open("output.txt");//the file that has the result after change the words
    string text;
    if (file.is_open()) {
        while (getline(file, text)) {  // Read from file, not cin
            for (const auto &pair: alternative) {//for loop to loop with every word
                string Banned_words = pair.first;//the original word
                string New_word = pair.second;//the alternative of the original word
                size_t pos = 0;
                while ((pos = text.find(Banned_words, pos)) != string::npos) {//if it finds any word from
                    // the words that we want to change it
                    text.replace(pos, Banned_words.length(), New_word);//make a replacement between them
                    pos += New_word.length();//and add to the pos the length of the word to move to the next word
                }
            }
        }
            output << text;//add the words after replacement to the output.txt file

    }
    cout<<"the result in output.txt file .";
        file.close();
        output.close();
    }

