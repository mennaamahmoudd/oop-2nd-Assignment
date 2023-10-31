#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
void compare_chbych(ifstream& file1,ifstream& file2){
    // function to compare the 2 files character by character;
    string lines_of_file1,lines_of_file2;
    int num_of_lines= 1;
    bool identical = true;
    while (getline(file1,lines_of_file1)&& getline(file2,lines_of_file2)){
        // getting file lines using while loop to compare these lines
        if (lines_of_file1!=lines_of_file2){
            identical= false;
            cout<<" The two files are not identical, "<<"They are not identical at line no."<<num_of_lines
            <<"where \n";
            cout<<" At file1 : "<<lines_of_file1<<endl;
            cout<<" At file2 : "<<lines_of_file2<<endl;
            break;
            // in this condition, we test if the two lines of the different functions are the same or not

        }
        num_of_lines++;
        // incrementing the lines number to revise the whole file

    }
    if (identical){
        cout<<"The two files are identical"<<endl;
        // in condition the all two files are identical
    }
}
void compare_wordbyword(ifstream& file1,ifstream& file2){
    //comparing the two files word by word
    string lines_of_file1,lines_of_file2;

    int num_of_lines= 1;

    bool identical = true;
    string words;
    int word_index=0;
    while (getline(file1,lines_of_file1)&& getline(file2,lines_of_file2)){
        // getting file lines using while loop to compare these lines
        istringstream s1(lines_of_file1);
        istringstream s2(lines_of_file2);
        // using istringstream to same the words at each line in vector to compare them without spaces
        vector<string >words_of_file1,words_of_file2;
        while (s1>>words){
            words_of_file1.push_back(words);
            word_index++;
            //incrementing the word index at the first vector
        }
        while (s2>>words) {
            words_of_file2.push_back(words);

            if (word_index >= words_of_file1.size() || words != words_of_file1[word_index]) {
                //comparing the words at each fie using the word index at the first file

                cout << " The two files are not identical, " << "They are not identical at line no." << num_of_lines
                     << "where \n";
                cout << " At file1 : " << lines_of_file1 << endl;
                cout << " At file2 : " << lines_of_file2 << endl;
                cout << "The first different word" << words << endl;
                //printing the different word
                identical = false;
                break;

            }
            word_index++;
        }
        if (!identical)
            //if it is not identical it will break
            break;

    if (word_index < words_of_file1.size()) {
        //in case that the word index is within the vector size

        cout << " The two files are not identical, " << "They are not identical at line no." << num_of_lines
             << "where \n";
        cout << " At file1 : " << lines_of_file1 << endl;
        cout << " At file2 : " << lines_of_file2 << endl;
        cout << "The first different word" << words_of_file1[word_index] << endl;
        //printing the word of that index at the first file
        identical = false;
        break;

    }

num_of_lines++;
    // incrementing the number of file lines
}
    if (identical){
        cout<<"The two files are identical"<<endl;
        // in condition the all two files are identical
    }

}

int main(){

    int com_type;
    string file_name1,file_name2;

    cout<<"Please, Enter the first file name :";
    getline(cin,file_name1);
    cout<<"Please, Enter the second file name :";
    getline(cin,file_name2);
    cout<<"what is the compression type ?"<<endl;
    cout<<"1 - compression character by character."<<endl;
    cout<<"2 - compression word by word."<<endl;
    cout<<" choose a number(1/2) : ";
    cin>>com_type;
    ifstream file1(file_name1),file2(file_name2);
    if (com_type==1){
        //applying the first compression method
        compare_chbych(file1,file2);
    } else if (com_type==2){
        //applying compression  word br word
        compare_wordbyword(file1,file2);
    }
    else
        cout<<"please, choose 1 or 2";
    //close the two files
    file1.close();
    file2.close();





}