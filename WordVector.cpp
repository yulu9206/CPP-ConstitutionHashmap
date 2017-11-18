#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

WordVector::WordVector(){}

WordVector::~WordVector(){}

Word *WordVector::insert(const string text)
{
        Word *it = search(text);
        if (it != nullptr)
        {
        		it->increase_count();
        		return it;
        }
	vector<Word>::iterator begin = data.begin();
	vector<Word>::iterator end = data.end();
	vector<Word>::iterator it2;
	Word new_word(text);
	if(data.size() == 0)
	{
		it2 = data.insert(begin, new_word);
		return &(*it2);
	}
	it2 = upper_bound(begin, end, new_word);
	it2 = data.insert(it2, new_word);
	return &(*it);
}

Word *WordVector::search(const string text)
{
        if (data.size() == 0) return nullptr;
        Word search_word(text);
	vector<Word>::iterator begin = data.begin();
	vector<Word>::iterator end = data.end();
	while(begin + 1 < end)
	{
		vector<Word>::iterator mid = begin + (end - begin)/2;
		if(*mid == search_word) return &(*mid);
		else if(*mid < search_word) begin = mid;
		else end = mid;
	}
	if (*begin == search_word) return &(*begin);
	else if(*end == search_word) return &(*end);
	else return nullptr;
}

long WordVector::get_size(){return data.size();}

vector<Word> WordVector::get_data(){return data;}
