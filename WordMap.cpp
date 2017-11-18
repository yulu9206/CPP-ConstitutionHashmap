#include <iostream>
#include <map>
#include "WordMap.h"
#include "Word.h"

/***** Complete this file. *****/

using namespace std;

WordMap::WordMap(){}

WordMap::~WordMap(){}

Word *WordMap::insert(const string text)
{
        Word new_word(text);
        pair<map<string,Word>::iterator,bool> it;
	it = data.insert(pair<string, Word>(text, new_word));
        if (it.second == false) it.first->second.increase_count();
        return &(it.first->second);
}

Word *WordMap::search(const string text)
{
        if (data.size() == 0) return nullptr;
        Word search_word(text);
        map<string, Word>::iterator it = data.begin();
        map<string, Word>::iterator end = data.end();
	while(it != end)
	{
		if(it->second == search_word) return &(it->second);
		else it++;
	}
	if(it->second == search_word) return &(it->second);
	else return nullptr;
}

long WordMap::get_size(){return data.size();}

map<string, Word> WordMap::get_data(){return data;}
