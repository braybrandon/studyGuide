#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Question.h"

using namespace std;
void setTest(ifstream& in_file, vector<Question>& test);

void askQuestion(vector<Question>& test);

int main(int argc, char** argv) 
{
	vector<Question> test;
	if (argc < 2) 
	{
		cout << "Warning you need to input a file to run this program!" << endl;
		cout << "Usage: " << argv[1] << " <file_name>" << endl;
		return 1;
	}

	ifstream in_file;
	in_file.open(argv[1]);
	if (!in_file.good())
	{
		cout << "Not the correct file type" << endl;
		return 2;
	}

	setTest(in_file, test);
	askQuestion(test);
	in_file.close();
	return 0;
}


void setTest(ifstream& in_file, vector<Question>& test)
{
	string textline;
	int i = 0;
	
	while (getline(in_file, textline, '\t'))
	{
		Question newQuestion;
		newQuestion.setQuestion(textline);
		test.push_back(newQuestion);
		
		getline(in_file, textline);
		test[i].setAnswer(textline);
		
		cout << test[i].getQuestion() << endl;
		cout << test[i].getAnswer() << endl;

		i++;
			
	}	

}


void askQuestion(vector<Question>& test)
{
	string user_answer;
	cout << test[0].getQuestion() << endl;
	getline(cin, user_answer);
	test[0].setUserAnswer(user_answer);

	cout << test[0].getAnswer() << endl;
	cout << test[0].getUserAnswer() << endl;
	if (test[0].checkAnswer())
		cout << "Correct!" << endl;
	else
		cout << "You Suck!!" << endl;

}
