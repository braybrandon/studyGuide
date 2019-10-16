#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Test.h"

using namespace std;
void setTest(ifstream& in_file, Test& test);
void studyLoop(Test& test);

int main(int argc, char** argv) 
{
	Test test;

	//checks to see if the user passed in a filename when they started the program
	if (argc < 2) 
	{
		//informs the user they did not input a file when they started the program
		cout << "Warning you need to input a file to run this program!" << endl;

		//tells the user how to accurately start the program
		cout << "Usage: " << argv[1] << " <file_name>" << endl;

		//exits the program
		return 1;
	}

	//creates a new input filestream
	ifstream in_file;

	//opens the filestream with the passed in file name
	in_file.open(argv[1]);

	//checks to see if the filename is an accurate filename
	if (!in_file.good())
	{
		cout << "Not the correct file type" << endl;
		return 2;
	}

	//calls the function setTest to transfer lines from the file to the Test object
	setTest(in_file, test);

	//closes the input stream file because it is no longer needed
	in_file.close();

	studyLoop(test);

	return 0;
}

//Funtion that takes in two parameters, Input file stram and a Test object. The function
//takes in lines from the input file and inserts them into a string which is then added to the
//Question object. Then we get another line form the input file and add it to the answer
//member of the question object. The question object is then added to the Test object.
void setTest(ifstream& in_file, Test& test)
{

	string textline;
	
	//loop that continues until all lines from the input file are read
	while (getline(in_file, textline, '\t'))
	{
		//new question object
		Question newQuestion;

		//adds the question to the question string member
		newQuestion.setQuestion(textline);
		
		//gets the answer of the question from the file
		getline(in_file, textline);

		transform(textline.begin(), textline.end(), textline.begin(), ::tolower);

		//adds the answer to the question string member answer
		newQuestion.setAnswer(textline);

		//adds the question object to the test object
		test.addQuestion(newQuestion);
	}	

}

//function that loops until the user inputs No or no
void studyLoop(Test& test) 
{
	string playAgain;

	do 
	{
				
		//calls the study member of the Test object
		test.study();
		cout << "Would you like to study again?" << endl;
		getline(cin, playAgain);
		transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower);
	} while(playAgain != "no");

}
