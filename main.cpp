//Programming Project
//Golf Score Card
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int a;

int main() {

cout<<"|Name|     "<<"|Handicap|    Hole:"<<"| 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18 | Total  | Par 72"<<endl;//Print top info/ui.

while (a<120){
    cout<<"-";
    a++;
}
cout<<endl<<endl;
 ifstream NamesFile("names.txt");//open each file for the names, scores and handicaps of the players.
 ifstream ScoresFile("Scores.txt");
 ifstream HandicapFile("Handicap.txt");


    // Check if the file is open
    if (!NamesFile) {
        cout << "Error opening names file!" << endl;//checking if the file is not open and printing an error if its not opening.
        return 0;

        if (!ScoresFile)
        cout << "Error opening scores file!" << endl;
        return 0;
        if (!HandicapFile)
        cout << "Error opening handicap file!" << endl;
        return 0;
    }
    string name;
    string scoresLine;
    int handicap;
    const int par = 72;

    while (getline(NamesFile, name) && getline(ScoresFile, scoresLine) && HandicapFile >> handicap) {


        cout <<" "<< name<<"          ";
        cout<< handicap<<"              |";

    istringstream scoresStream(scoresLine);
    int score;
    int total = 0;
        while (scoresStream >> score) {
            cout <<" "<< score << "  ";
            if(handicap>0){
            total = total + (score-handicap);


            }
        }


        cout << "|  "<<total<<"    |  ";
        if (par<total){
            cout<<"Over";
        }
            else{
                cout<<"Under";
        }
        cout<<endl<<endl;
    }


    NamesFile.close();
    ScoresFile.close();




    return 0;


    }
