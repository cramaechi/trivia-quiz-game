/*--------------------------------------------------------------------
This is the interface for the class Trivia. Values of this type 
represent information related to a trivia quiz game. This includes 
the question, the answer to the question, and the monetary worth of
the question.

Author: Chibuikem Amaechi
Email:  cramaechi@me.com
--------------------------------------------------------------------*/
#include <string>
using std::string;

class Trivia
{
public:
    Trivia(string& theQ, string& theA, double theQValue);
    //Initializes the question, monetary worth of the question, and 
    //answer to the arguments.

    Trivia(); 
    //Initializes the question and answer to empty strings. 
    //Initiaizes the monetary worth of the question to $0.00.

    const string getQuestion() const {return question;}

    const string getAnswer() const {return answer;}

    double getQuestionWorth() const {return questionWorth;}
    //Returns the monetary value of the question in dollars
private:
    string question;
    string answer;
    double questionWorth;
};
