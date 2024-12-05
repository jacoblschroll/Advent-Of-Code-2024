#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

bool isSafePart1(vector<int> report){
    bool increased = false;
    bool decreased = false;

    for (int i = 0; i < report.size() - 1; i++){
        if (report[i+1] > report[i]){
            increased = true;
        }
        else if(report[i+1] < report[i]){
            decreased = true;
        }

        int delta = abs(report[i+1] - report[i]);

        // Changes not from 1 to 3
        if(delta < 1 || delta > 3){return false;}

        // Case that is not constantly increasing or decreasing
        if (increased && decreased){return false;}
    }

    return true;
}

bool isSafePart2(vector<int> report){
    if (isSafePart1(report)){
        return true;
    }

    for (int i = 0; i < report.size(); i++){
        vector<int> temp = report;
        temp.erase(temp.begin() + i);
        
        if(isSafePart1(temp)){
            return true;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> reports;

    ifstream myInput("myInput.txt");
    string line;

    // Get all reports
    while (getline(myInput, line)){
        // Create a string stream to break up a ' ' delimiter
        stringstream ss(line);

        string temp;

        vector<int> tempLevel;

        // Break each report into values
        while (getline(ss, temp, ' ')){
            tempLevel.push_back(stoi(temp));
        }

        reports.push_back(tempLevel);
    }

    int safeReportsP1 = 0;
    int safeReportsP2 = 0;

    for (const vector<int> &report : reports){
        safeReportsP1 += isSafePart1(report);
        safeReportsP2 += isSafePart2(report);
    }

    cout << "Initially " << safeReportsP1 << " / 1000 reports are safe\n" << endl;

    cout << "With Damping " << safeReportsP2 << " / 1000 reports are safe" << endl;

    return 0;
}