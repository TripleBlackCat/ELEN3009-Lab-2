// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
	_paragraph.push_back(line);
}

bool Paragraph::contains(const Word& search_word, vector<int>& line_numbers) const
{
	if (_paragraph.size() == 0) return false;
	
	for (int i = 0; i < _paragraph.size(); i++)
	{
		if ( _paragraph.at(i).contains(search_word) )
		{
			line_numbers.push_back(i + 1);
		}
	}
	
	if (line_numbers.size() > 0)
	{
		return true;
	}
	
	return false;
}