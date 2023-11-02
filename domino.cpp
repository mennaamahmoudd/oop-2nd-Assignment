#include <iostream>
#include <bits/stdc++.h>
//#define leftDots first
//#define rightDots second
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};
bool flag=1;//this i made it to know if the chain will be made by the domino or not
bool FormsDominoChain(vector<dominoT>dominos, int index = 0, string chain = "") {//this function take the all
    // domino and index 0 and empty string
    if (index == dominos.size()) {//that mean i take all domino
        cout<< "true" ;
        cout<<endl;
        cout<< chain;
        flag=0;
    }
    for (int i = index; i < dominos.size(); i++) {//i start from the index that i stopped on it
        swap(dominos[index], dominos[i]);
        if (index == 0 || dominos[index].leftDots == dominos[index - 1].rightDots) {//check if the domino
            // left dots = the previous domino right dot and if it, i will make a recursion by passing to the
            // recursive function the (index+1)and the new domino set and the chain string but not empty i will
            //add the domino that the left dot of it = the previous domino right dot
            if (FormsDominoChain(dominos, index + 1, chain + to_string(dominos[index].leftDots) + "|" +
                                                     to_string(dominos[index].rightDots) + " - ")) {

            }
            swap(dominos[index], dominos[i]);
        }
    }

}
int main() {
    int numDominos,i;
    cout << "Enter the number of dominos: ";
    cin >> numDominos;
    vector<dominoT> dominoSet(numDominos);//make a pair from domino by struct
    for (int i = 0; i < numDominos; i++) {
        cout << "Enter the left and right dots for domino " << i + 1 << ": "<<'\n';
        cin >> dominoSet[i].leftDots >> dominoSet[i].rightDots;//take the left and right dots for every domino
    }
    FormsDominoChain(dominoSet);
if(flag==1){
    cout<<"can't make a chain from this dominos";
}
}