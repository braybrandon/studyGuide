#include "Question.h"

Question::Question() 
{
	correct = false;
}

string Question::getQuestion() 
{
	return question;
}

string Question::getAnswer()
{
	return answer;
}

string Question::getUserAnswer()
{
	return user_answer;
}

void Question::setQuestion(string original)
{
	question = original;

}

void Question::setAnswer(string original)
{
	answer = original;
}

void Question::setUserAnswer(string original)
{
	user_answer = original;
	
	//calls transform function to convert all characters in user_answer to lower case letters
	transform(user_answer.begin(), user_answer.end(), user_answer.begin(), ::tolower);
}

bool Question::checkAnswer()
{
	if (user_answer == answer)
		correct = true;
	return correct;
}
