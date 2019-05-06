#include <cstdio>
#include <string>
#include <iostream>
#include <math.h>
#include "calculate.hpp"
// used Bar Genish and Lioz elmalem the idia Which is in the algorithm
namespace bullpgia{

  string calculateBullAndPgia(string choice, string guess){
	if( choice == "" || guess == "" ) throw std::invalid_argument( "The string is empty" );
		
	int bull = 0;
	int pgiot = 0;
  int arrguess [10]= {0,0,0,0,0,0,0,0,0,0};
	int arrcohice [10]= {0,0,0,0,0,0,0,0,0,0};

    for(int i=0;i<choice.length();i++){
    if(choice[i]==guess[i])
      bull++;
  }	
    for (int i=0;i<guess.length();i++){
    int temp=(guess[i])-'0';
    arrguess[temp]++;
  }
  	  for(int i=0;i<choice.length();i++){
    int temp=(choice[i])-'0';
    arrcohice[temp]++;
  }

  for (int i=0;i<10;i++){
    int temp= std::min(arrcohice[i],arrguess[i]);
    pgiot=pgiot+temp;
  }
  pgiot=pgiot-bull;

		
	string bull_str = std::to_string(bull);
        string pgiot_str = std::to_string(pgiot);
        string result = bull_str + "," + pgiot_str;
        return result;
	}
}