#include "bits/stdc++.h"
using namespace std;
map<string,int> val; // Declare a map to store string-value pairs

void initializeValues() {
    val["User"] = 1;
    val["re-activate"] = 1;
    val["Outlook"] = 1;
    val["Sign"] = 1;
    val["in"] = 1;

    val["Hotmail"] = 2;
    val["link"] = 2;
    val["Account"] = 2;
    val["Your"] = 2;
    val["new"] = 2;

    val["to"] = 3;
    val["dear"] = 3;
    val["follow"] = 3;
    val["Thanks"] = 3;
    val["active"] = 3;
    val["urgently"] = 3;
    val["com"] = 3;
    val["the"] = 3;
    val["customers"] = 3;
    val["services"] = 3;
}

int main() {
    int value = 0; // Initialize a variable to store the total spam score
    initializeValues(); // Call the function to initialize the values in the map
    char line[100]; // Declare a character array to store each line of the input file
    map<string, int> counting; // Declare a map to store the count of each word

    ifstream Myfile; // Declare an input file stream object
    Myfile.open("Email.txt"); // Open the file named "Email.txt"

    while (!Myfile.eof()) { // Iterate until the end of the file is reached
        Myfile.getline(line, 100); // Read a line from the file and store it in the character array 'line'
        string s; // Declare a string variable

        Myfile >> s; // Read a word from the file and store it in the string variable 's'

        for (int i = 0; i < strlen(line); ++i) { // Iterate through each character in the line
            if (line[i] == ' ') { // If a space is encountered, it indicates the end of a word
                if (val[s] != 0) { // If the word is present in the map (has a non-zero value)
                    counting[s]++; // Increment the count of the word in the 'counting' map
                    value += val[s]; // Add the corresponding value of the word to the total spam score
                }
                s.clear(); // Clear the string variable to prepare for the next word
            }
            else {
                s += tolower(line[i]); // Append the lowercase version of the character to the string variable 's'
            }
        }

        if (val[s] != 0) { // If the last word of the line is present in the map (has a non-zero value)
            counting[s]++; // Increment the count of the word in the 'counting' map
            value += val[s]; // Add the corresponding value of the word to the total spam score
        }
    }

    Myfile.close(); // Close the input file```cpp
    for (auto &it: counting) { // Iterate through each key-value pair in the 'counting' map
        cout << it.first << " Repeated " << it.second << " time(S) , spamscore -> " << it.second * val[it.first] << '\n';
        // Print the word, its count, and the spam score (count * value) associated with it
    }

    cout << endl;
    cout << "Total Score: " << value; // Print the total spam score

    return 0;
}