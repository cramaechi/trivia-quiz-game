/*-------------------------------------------------------------------
This is the implementation for the class Trivia. The interface is in
the file trivia.h.

Author: Chibuikem Amaechi
Email:  cramaechi@me.com
-------------------------------------------------------------------*/
#include <string>
#include <iostream>
#include <cstdlib>
#include "trivia.h"

using std::string;
using std::cout;
using std::exit;

Trivia::Trivia(string& theQ, string& theA, double theQValue)
    : question(theQ), answer(theA), questionWorth(theQValue)
{
    if (questionWorth < 0)
    {
        cout<<"Monetary value of the question cannot be negative!\n";
        exit(1);
    }
}

Trivia::Trivia() : question(""), answer(""), questionWorth(0.0) {}
