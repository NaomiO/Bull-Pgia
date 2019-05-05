
#include <cstdio>
#include <string>
#include <iostream>
#include <math.h>
#include "calculate.hpp"

namespace bullpgia{

  string calculateBullAndPgia(string choice, string guess){

	//if any of the strings are empty, the game cannot be played
	if( choice == "" || guess == "" ) throw std::invalid_argument( "The string is empty" );
		
	int bull = 0;
	int pgiot = 0;
		
	//for the string selected by chooser
	for( int i = 0; i < choice.length(); i++ ){
		int runnerInt = choice[i];
			
		
		for( int j = 0; j < guess.length(); j++ ){
			int guessInt = guess[j];
				
				
			if( runnerInt == guessInt){
				if( i == j ){ //position match
					bulls++;
				}
				else{ //contains relation
					pgiot++;
				}
			}
		}
	}
		
	string b = to_string(bulls);
        string c = to_string(pgiot);
        string s = b + "," + c;
        return s;

	}


}
