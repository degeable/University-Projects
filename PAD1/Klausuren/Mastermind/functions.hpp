/* 
 * File:   functions.hpp
 * Author: Michael Roth
 *
 * Created on 13. November 2017, 14:23
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <algorithm>

template <typename T>
bool isValidInput(const vector<T>& guess, int length, T min, T max)
{
	if (guess.size() != length)
		return false;


	set<T> tmp;
        
        
        
	for (auto t : guess)
	{
		if (t < min || t > max)
			return false;
		tmp.insert(t);
	}

	if (tmp.size() != guess.size())
		return false;

	return true;
}

template <typename T>
int white(const vector<T>& solution, const vector<T>& guess)
{
	if (solution.size() != guess.size())
		return -1;
	
	int count = 0;
	
	for(int outer = 0; outer < guess.size(); outer++)
	{
		for(int inner = 0; inner < solution.size(); inner++)
		{
			if(outer == inner)
				continue;
			if(guess[outer] == solution[inner])
				count++;
		}
	}
	
	return count;
	
}

template <typename T>
int black(const vector<T>& solution, const vector<T>& guess)
{
	if (solution.size() != guess.size())
		return -1;

	int count = 0;

	for (int i = 0; i < solution.size(); i++)
	{
		if (solution[i] == guess[i])
			count++;
	}
	return count;
}



#endif /* FUNCTIONS_HPP */
