// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <iostream>
#include <string>
#include <vector>

Word::Word(const string& word): _word{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	
		
	bool containsSpaces = false;
	string testSpaces = "";
	char spaceChar;
	for (int i = 0; i < _word.length(); i++) 
	{
		spaceChar = _word[i];
		testSpaces += spaceChar;
	}
	
	for (int i = 0; i < testSpaces.length(); i++)
	{
		if (testSpaces[i] == ' ')
		{
			containsSpaces = true;
		}
	}
	
	string checkAlpha = "";
	char ch;
	
	for(int i = 0; i < _word.length(); i++)
	{
		if(isalpha(_word[i]))
		{
			ch = _word[i];
			checkAlpha += ch;
		}	
	}		
	

	
	if (containsSpaces) throw WordContainsSpace();
	
	if (checkAlpha.length() == 0 ) throw WordContainsNoLetters();
	
	if (_word.empty()) throw WordContainsNoLetters();

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	bool isSame = true;
	
	if (_word == rhs._word)
		return true;
	else if (_word.length() == rhs._word.length())
	{
		for (int i = 0; i < _word.length(); i++)
		{
			if ( tolower(_word[i]) == tolower(rhs._word[i]) )
			{
				isSame = true;
			}
			else 
			{
				return false;
			}
		}
		
	} 
	else 
	{
		string word1 = "";
		char ch1;
		
		
		
		
		string word2 = "";
		char ch2;
		

		for(int i = 0; i < _word.length(); i++)
		{
			if(isalpha(_word[i]))
			{
				ch1 = _word[i];
				word1 += tolower(ch1);
			}	
		}		
		
		for (int i = 0; i < rhs._word.length(); i++)
		{
			if(isalpha(rhs._word[i]))
			{
				ch2 = rhs._word[i];
				word2 += tolower(ch2);
			}	
		}
		
				
		if (word1 == word2)
		{
			return true;
		}
		else
		{
			return false;
		}
	
	}
	
	if (isSame)
		return true;
		
	return false;
}

bool Word::isQueryable() const
{
	
	if (_word.length() >= 3)
	{
		return true;
	}
	else 
	{
		return false;
	}
	return false;
}
