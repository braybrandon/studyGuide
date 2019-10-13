#include "Test.h"

//constructor member function
Test::Test()
{


}

//returns the number of question the test holds.
int Test::getSize()
{

	return problems.size();
}

//returns the users score for the test
int Test::getScore()
{
	return score;

}

//adds a question to the problems vector
void Test::addQuestion(Question question)
{
	problems.push_back(question);
}

//removes the last question from the problems vector
void Test::removeQuestion()
{
	problems.pop_back();
}

//member function that picks a random number between 0 and the size of the problems vector. Then from that it outputs the question to the 
//user. waits for the users response. If the user gives the correct responce outputs correct and increases the users score by 1. Else
//the user they are wrong.
void Test::study()
{

	//loop that loops through the total number of questions
	for (int i = 0; i < getSize(); i++)
	{
		//seeds the random number generator based on time
		srand(time(NULL));

		string userAnswer;
		//creates an integer and assigns a random number from 0 to the size of the test minus the question number the user is on.
		int questionNumber = rand() % (getSize() - i);

		//outputs to the user the question number along with the question
		cout << "Question #" << i + 1 << endl;
		cout << problems[questionNumber].getQuestion() << endl;

		//gets the user input answer
		getline(cin, userAnswer);
		//sets the user answer for the current question object
		problems[questionNumber].setUserAnswer(userAnswer);
		
		//if the user got the question correct outputs correct and increments their score by 1 else outputs wrong
		if(problems[questionNumber].checkAnswer())
		{
			cout << "Correct!" << endl;
			score++;
		}
		else
		{
			cout << "You SUCK!" << endl;
		}

		//creates a temporary question object
		Question temporary;

		//copies the current question to the temporary question object
		temporary = problems[questionNumber];

		//sets the current question to the question at the end minus the question they are currently on
		problems[questionNumber] = problems[getSize() - i - 1];
		//sets the question at the end to the temporary question
		problems[getSize() - i - 1] = temporary;

		
	}

}
