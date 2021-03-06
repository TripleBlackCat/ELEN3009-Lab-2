#ifndef LINE_H
#define LINE_H

#include "Word.h"
#include <string>
#include <vector>
using namespace std;

class Line
{
public:
	// DO NOT MODIFY THE PUBLIC INTERFACE OF THIS CLASS

	// accepts a line of text (which FileReader will provide in production code)	
	Line(const string& line);
	// returns true if the search word is found in the line; false otherwise
	bool contains(const Word& search_word) const;

private:	
	
	void stringToWordVector();
	string _line;
	vector<Word> _wordVec;		
	

};

#endif

