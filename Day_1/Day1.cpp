#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <map>

using namespace std;

// Templated implementation of bubble sort
template <typename T>
void bubbleSort(vector<T> &toSort){
    int elements = toSort.size();
    bool madeSwap;

    for (int i = 0; i < elements - 1; i++){
        madeSwap = false;
        for (int j = 0; j < elements - i - 1; j++){
            if (toSort[j] > toSort[j+1]){
                swap(toSort[j], toSort[j+1]);
                madeSwap = true;
            }
        }

        if (!madeSwap){
            break;
        }
    }
}

int main(){
    vector<int> leftSide;
    vector<int> rightSide;

    // Read in data (will likley be reused in other days)
    ifstream myInput("myInput.txt");
    string line;

    while(getline(myInput, line)){
        int leftValue = stoi(line.substr(0, 5));
        int rightValue = stoi(line.substr(8, 5));

        leftSide.push_back(leftValue);
        rightSide.push_back(rightValue);
    }

    // Part 1
    bubbleSort(leftSide);
    bubbleSort(rightSide);

    int sumOfDistances;

    // Assumes vectors are of same size
    for (int i = 0; i < leftSide.size(); i++){
        sumOfDistances += abs(leftSide[i] - rightSide[i]);
    }

    cout << "The sum of every distance is: " << sumOfDistances << endl;

    // Part 2

    // Key, occurences of each number
    map<int, int> occurences;

    for (int i = 0; i < rightSide.size(); i++){
        occurences[rightSide[i]]++;
    }

    int similarity;

    for (int i = 0; i < leftSide.size(); i++){
        similarity += leftSide[i] * occurences[leftSide[i]];
    }

    cout << "Similarity of: " << similarity << endl;

    return 0;
}