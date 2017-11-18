#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0) {}
Word::Word(string text) : text(text), count(1) {}

Word::~Word() {}
string Word::get_text(){return text;}
void Word::increase_count(){count++;}
int Word::get_count(){return count;}
bool Word::operator ==(const Word& other) const
{
	return text == other.text;
}
bool Word::operator !=(const Word& other) const
{
	return text != other.text;
}

    /**
     * Overloaded > operator.
     * @return true if the text of this Word is greater than
     *              the text of the other Word, else false.
     */
bool Word::operator  >(const Word& other) const
{
	return text > other.text;
}
bool Word::operator  <(const Word& other) const
{
	return text < other.text;
}
