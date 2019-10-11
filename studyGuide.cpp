#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Test.h"

using namespace std;
void setTest(ifstream& in_file, Test& test);


int main(int argc, char** argv) 
{
	Test test;
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
	test.study();
	in_file.close();
	return 0;
}


void setTest(ifstream& in_file, Test& test)
{
	string textline;
	int i = 0;
	
	while (getline(in_file, textline, '\t'))
	{
		Question newQuestion;
		newQuestion.setQuestion(textline);
		
		getline(in_file, textline);
		newQuestion.setAnswer(textline);
		test.addQuestion(newQuestion);
	}	

}


