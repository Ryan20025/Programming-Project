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

cout<<"|Name|     "<<"|Handicap|    Hole:"<<"| 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18 |"<<endl;

while (a<95){
    cout<<"-";
    a++;
}
cout<<endl;
 ifstream NamesFile("names.txt");
 ifstream ScoresFile("Scores.txt");
 ifstream HandicapFile("Handicap.txt");


    // Check if the file is open
    if (!NamesFile) {
        cerr << "Error opening names file!" << endl;
        return 0;
    }
     if (!ScoresFile) {
        cerr << "Error opening scores file!" << endl;
        return 0;
    }
    string name;
    string scoresLine;


    while (getline(NamesFile, name) && getline(ScoresFile, scoresLine)) {

        cout <<" "<< name<<"       |";


    istringstream scoresStream(scoresLine);
    int score;
        while (scoresStream >> score) {
            cout << score << " ";
        }

        cout << endl; // Move to the next line after printing scores

    }


    NamesFile.close();
    ScoresFile.close();


    return 0;


    }
