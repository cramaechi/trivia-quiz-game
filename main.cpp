//A program that simulates a trivia quiz game.
#include <iostream>
#include <vector>
#include <cstring>
#include "trivia.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void stripSpacesAndPunct(string& s);
//Removes whitespaces and punctuations from string s.

void toLowerCase(string& s);
//Converts all characters in strings s to lowercase letters.

bool isEqual(string s1, string s2);
//Returns true if s1 and s2 are equal; otherwise, return false;

void setup(vector<Trivia>& trivia);
//Creates all the trivia questions, answers, and monetary values of the
//questions.

void play(const vector<Trivia>& trivia);
//Starts the trivia game.

int main()
{
    vector<Trivia> trivia;

    setup(trivia);
    play(trivia);

    return 0;
}

void play(const vector<Trivia>& trivia)
{
    double totalWinnings = 0;
    string ans;
    for (int i = 0; i < 5; i++)
    {
        cout<<trivia[i].getQuestion()<<" ";
        getline(cin, ans);

        if (isEqual(ans, trivia[i].getAnswer()))
        {
            cout<<"You are correct! ";
            cout<<"$"<<trivia[i].getQuestionWorth()<<" earned."<<endl;
            cout<<endl;

            totalWinnings += trivia[i].getQuestionWorth();
        }
        else
        {
            cout<<"WRONG! The answer was \""<<trivia[i].getAnswer()<<"\"\n\n";
        }
    }

    cout<<"You have earned a total of $"<<totalWinnings<<endl;
}

void setup(vector<Trivia>& trivia)
{
    string q[] = {
        "What was the name of the first war in the United States?",
        "How many days are in a leap year?",
        "How many planets are in our solar system?",
        "Who is the 44th presidient of the United States?",
        "Which amendment gave women the right to vote?"};
    string a[] = {
        "Revolutionary War",
        "366",
        "8",
        "Barack Obama",
        "19th Amendment"};

    double qMonetaryWorth[] = {1000.0, 500.0, 300.0, 1000.0, 2000.0};

    for (int i = 0; i < 5; i++)
        trivia.push_back(Trivia(q[i], a[i], qMonetaryWorth[i]));
}

void toLowerCase(string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
    }
}

void stripSpacesAndPunct(string& s)
{
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!isalnum(s[i]))
            s.erase(i, 1);
    }
}

bool isEqual(string s1, string s2)
{
    stripSpacesAndPunct(s1);
    stripSpacesAndPunct(s2);
    toLowerCase(s1);
    toLowerCase(s2);
    return s1 == s2;
}
