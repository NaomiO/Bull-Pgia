#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <string>
#include <list>
#include <bits/stdc++.h> 
using std::string;

namespace bullpgia
{
class SmartGuesser : public bullpgia::Guesser
{
	std::list<string> perms; 
	std::list<int> digits; 
	int pos; 
	bool shouldSwap(char str[], int start, int curr);
	void findPermutations( char str[], int index, int n);

  public:
	string guess() override;
	void startNewGame(uint length) override;
	void learn(string reply) override;
};
} 
