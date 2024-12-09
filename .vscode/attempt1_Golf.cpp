#include <iostream>
#include <vector>

struct Hole {
    int par;     // Par for the hole
    int strokes; // Strokes taken by the player
};

// Function to calculate points based on score-to-par using if statements
int calculatePoints(int scoreToPar) {
    if (scoreToPar == -3) {
        return 5; // Albatross or double eagle
    } else if (scoreToPar == -2) {
        return 4; // Eagle
    } else if (scoreToPar == -1) {
        return 3; // Birdie
    } else if (scoreToPar == 0) {
        return 2; // Par
    } else if (scoreToPar == 1) {
        return 1; // Bogey
    } else {
        return 0; // Double bogey or worse
    }
}

int main() {
    int handicap;
    std::cout << "Enter player handicap (0-54): ";
    std::cin >> handicap;

    // Input holes
    std::vector<Hole> holes(18);
    std::cout << "Enter the par and strokes for each hole:\n";
    for (int i = 0; i < 18; ++i) {
        std::cout << "Hole " << (i + 1) << " (par strokes): ";
        std::cin >> holes[i].par >> holes[i].strokes;
    }

    // Calculate free strokes
    int baseFreeStrokes = handicap / 18;
    int extraHoles = handicap % 18;

    // Total score
    int totalPoints = 0;

    // Process each hole
    for (int i = 0; i < 18; ++i) {
        int freeStrokes = baseFreeStrokes + (i < extraHoles ? 1 : 0);
        int netStrokes = holes[i].strokes - freeStrokes;
        int scoreToPar = netStrokes - holes[i].par;

        // Calculate points using if statements
        int points = calculatePoints(scoreToPar);

        // Display results for this hole
        std::cout << "Hole " << (i + 1) << ": Net strokes = " << netStrokes
                  << ", Score to par = " << scoreToPar
                  << ", Points = " << points << "\n";

        totalPoints += points;
    }

    // Output total points
    std::cout << "Total Points: " << totalPoints << "\n";
    return 0;
}
