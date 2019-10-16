
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Question {
	public:
		
		//constructor
		Question();

		//returns the value of the question member
		string getQuestion();

		//sets the value of the question member
		void setQuestion(string original);

		//returns the value of the answer member
		string getAnswer();

		string getUserAnswer();

		//sets the value of the answer member
		void setAnswer(string original);

		//sets the value of the usrAnswer member to a user input string
		void setUserAnswer(string original);


		bool checkAnswer();

	private:
		string question;
		string answer;
		string user_answer;
		bool correct;


};
