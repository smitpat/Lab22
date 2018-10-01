#include <iostream>

#include <iomanip>

#include <string>


using namespace std;

int sumVotes(int list[], int size);
int winnerIndex(int list[], int size);

int main()
{
    int numberOfCandidates;
    string *candidates;
    int *votes;
    int totalVotes;
    int i;

    cout << "Enter number of candidates: ";
    cin >> numberOfCandidates;
    cout << endl;

    candidates = new string[numberOfCandidates];
    votes = new int[numberOfCandidates];

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "Enter candidate's name and the votes " 
         << " received by the candidate." << endl;

    for (i = 0; i < numberOfCandidates; i++)
        cin >> candidates[i] >> votes[i];

    totalVotes = sumVotes(votes, numberOfCandidates);

    cout << "Candidate    Votes Received   % of Total Votes" << endl;
    for (i = 0; i < numberOfCandidates; i++)
        cout << left << setw(10) << candidates[i]
             << right << " " << setw(10) << votes[i] << "   " << setw(15)
             << (static_cast<double>(votes[i]) / static_cast<double>(totalVotes)) * 100 << endl;

    cout << "Total            " << totalVotes << endl;

    cout << "Winner:     " << candidates[winnerIndex(votes, numberOfCandidates)]
         << endl;

    return 0;
}

int sumVotes(int list[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum = sum + list[i];

    return sum;
}

int winnerIndex(int list[], int size)
{
    int winInd = 0;

    for (int i = 0; i < size; i++)
        if (list[i] > list[winInd])
            winInd = i;

    return winInd;
}



