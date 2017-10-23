#include <iostream>
#include <vector>
#include "FileReader.h"
#include "Line.h"
#include "Paragraph.h"
#include "Word.h"

using namespace std;

int main() 
{
	string fileName;
	string inputWord;
	
	cout << "Please enter file name: ";
	cin >> fileName;
	FileReader filereader(fileName);
	Paragraph paragraph;
	filereader.readFileInto(paragraph);
	
	while (true)
	{
		cout << "Please enter a word to search for or \".\" to quit: ";
		cin >> inputWord;
		
		if (inputWord == ".")
		{
			break;
		}
		
		Word search_word(inputWord);
		vector<int> line_numbers;
		
		if (paragraph.contains(search_word, line_numbers))
		{
			cout << "Word found: " << endl;
			for (int i = 0; i < line_numbers.size(); i++)
			{
				cout << "line " << line_numbers.at(i) << endl;
			}
		}
		else
		{
			cout << "Word not found" << endl;
		}

		cout << endl;
		
	}
	
		
	cout << "......End Of Program ......." << endl;
	
	return 0;
    
    // The implementation of our code will not pick up reappering words on the same line.
    // The main part of the design will remain largely unchanged. A simple counter can be implented in the Line.cpp file to account for this scenario.
}
