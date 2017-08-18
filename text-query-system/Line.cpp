// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include "Word.h"
#include <iostream>
#include <vector>

Line::Line(const string& line) : _line{line}
{
	stringToWordVector();
	// Why is there no private variable for this variable?	
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
}

bool Line::contains(const Word& search_word) const
{
	
		if (_line == "")
		{
			return false;
		}
		
		if (!search_word.isQueryable())
		{
			return false;
		}
	
		for (int i = 0; i < _wordVec.size(); i++)
		{
			if (_wordVec.at(i) == search_word)
			{
				return true;
			}
		}
		
		return false;
}


void Line::stringToWordVector()
{
	
	string singleWord = "";
	char ch;
	bool isEndOfLine = false;
	
	if (_line == "") return;			
			
	while (!isEndOfLine)
	{
		for (int i = 0; i <= _line.length(); i++)
		{
			if (_line[i] == '\0' || _line[i] == ' ') 
			{
				isEndOfLine = true;
				Word temp(singleWord);
				_wordVec.push_back(temp);
				singleWord = "";
				
				if (_line[i] == '\0')
				{
					isEndOfLine = true;
				}
		
			}
			else
			{
				ch = _line[i];
				singleWord += ch;
			}		
				
		}
				
	}
}



