#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Question.h"


class Test
{

	public:
		Test();

		int getSize();

		int getScore();

		void addQuestion(Question question);

		void removeQuestion();

		void study();

	private:
		vector<Question> problems;
		int score;
};
