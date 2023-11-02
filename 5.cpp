#include<iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct player{
    //defining  a new struct containing the player name and score
    string name;
    int score;

};
bool top_one(const player& player1,const player& player2){
    //function to determine the highest score between two players
    return player1.score> player2.score;
}

void enter_new_player(vector<player>&p1){
    //adding new player to the programme
    string name;
    int score;
    player p2;

    std::cout << "Enter player name: ";
    std::cin >> name;

    std::cout << "Enter player score: ";
    std::cin >> score;

    p2.name = name;
    p2.score = score;
    //defining inputs as struct inputs

    if (p1.size() < 10) {
        p1.push_back(p2);
        //pushing the element if the list has smaller than 10 players
    } else {
        // Find the player with the smallest score
        auto minScorePlayer = min_element(p1.begin(), p1.end(), top_one);

        if (p2.score > minScorePlayer->score) {
            *minScorePlayer = p2;
            //replacing the new member in the minmum score of a member
        }
    }

}

void top10_list(const vector<player>&p1){
    // for printing the top list of the highest scores
vector<player>sorter =p1;
    sort(sorter.begin(),sorter.end(), top_one);
    //sorting the 10 players according t o top_one function
   cout<<"\nTOP 10 LIST: "<<endl;
    for (const player& p2:sorter) {
        //using a pointer to print all top 10 list members that sorted according to the highest score
        cout<<p2.name<<" "<<p2.score<<endl;

    }

}
void player_highest_score(const vector<player>&p1){
    //printing the highest score of a member who may be played more than once
    string name;
   player p2 ;
   p2.name=name;
    cout<<"Enter the player name: ";
    cin>>name;


    bool fnd= false;
    int highest_score = std::numeric_limits<int>::min();
    //using limits library to get the smallest number

    for (const player& player : p1) {
        if (player.name == name && player.score > highest_score) {
            //comparing the name and scores with the saved list and get the highest score
            highest_score = player.score;
            fnd = true;
        }
    }

    if (fnd){
        cout<<"The player highest score is: "<<highest_score<<endl;
    } else{
        cout<<"The player name does not exist in the TOP 10 list."<<endl;
    }

}
void menu(){
    // menu function to choose which order the use want
    cout<<"\n Menu "<<endl;
    cout<<"1- Add a new player name and score."<<endl;
    cout<<"2- show the TOP 10 LIST "<<endl;
    cout<<"3- Print a player's highest score."<<endl;
    cout<<" 4- EXIT "<<endl;

    cout<<"please choose a number: "<<endl;
}

int main(){
    vector<player> players;

    int num;
    do {
        menu();
cin >> num;
//using switch case to apply the function according to the user order
        switch (num) {
            case 1:
                enter_new_player(players);
                break;
            case 2:
                top10_list(players);
                break;
            case 3:
                player_highest_score(players);
                break;
            case 4:
                cout << "The program has been finished" << endl;
                cout << "Good Bye" << endl;
                break;
            default:
                cout << "Choose a number from the menu, please" << endl;
        }
    } while (num != 4);


}
