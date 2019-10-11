#include "Test.h"


Test::Test()
{


}

int Test::getSize()
{

	return problems.size();
}

int Test::getScore()
{
	return score;

}

void Test::addQuestion(Question question)
{
	problems.push_back(question);
}

void Test::removeQuestion()
{
	problems.pop_back();
}

void Test::study()
{
	for (int i = 0; i < getSize(); i++)
	{
		srand(time(NULL));
		string userAnswer;
		cout << "Question #" << i + 1 << endl;
		int questionNumber = rand() % (getSize() - i);
		cout << problems[questionNumber].getQuestion() << endl;
		getline(cin, userAnswer);
		problems[questionNumber].setUserAnswer(userAnswer);

		if(problems[questionNumber].checkAnswer())
		{
			cout << "Correct!" << endl;
			score++;
		}
		else
		{
			cout << "You SUCK!" << endl;
		}

		Question temporary;
		temporary = problems[questionNumber];
		problems[questionNumber] = problems[getSize() - i - 1];
		problems[getSize() - i - 1] = temporary;

		
	}

}
