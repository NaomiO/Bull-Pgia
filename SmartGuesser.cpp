#include "Guesser.hpp"
#include <string>
using std::string;

/**
 * this method guess the string base of the data from learn method
 */
string bullpgia::SmartGuesser::guess()
{
  string ans = "";
  if (digits.size() < length)
  {
    for (size_t i = 0; i < length; i++)
    {
      char c = '0' + pos;
      ans += c;
    }

    myString = ans;
    pos++;

    return myString;
  }

  ans = perms.front(); 
  perms.pop_front();   

  myString = ans;
  return myString;
}

void bullpgia::SmartGuesser::startNewGame(uint length)
{

  this->length = length;
  pos = 0;
  perms.clear();
  digits.clear();
}

void bullpgia::SmartGuesser::learn(string reply)
{
  bool foundAllDigit = false;
  size_t i = reply.find(',');
  int b = stoi(reply.substr(0, i));                   // bull
  int p = stoi(reply.substr(i + 1, reply.length())); //pgia

  if (digits.size() < length)
  {

    for (size_t j = 0; j < b; j++)
    {
      digits.push_front(pos - 1);
    }

    if (digits.size() == length)
      foundAllDigit = true;
    else
    {
      return;
    }
  }

  if (foundAllDigit)
  {

    string ans = "";
    for (std::list<int>::iterator it = digits.begin(); it != digits.end(); ++it)
    {
      char c = '0' + *it;
      ans += c;
    }
    char *chr = strdup(ans.c_str()); // convert from strin to char*

    findPermutations(chr, 0, length); // find the Permutations and add them to perm list

    foundAllDigit = false;
  }
}

/**
 * this algoritim from this site 
 * https://www.geeksforgeeks.org/print-all-permutations-with-repetition-of-characters/ 
 */
bool bullpgia::SmartGuesser::shouldSwap(char str[], int start, int curr)
{
  for (int i = start; i < curr; i++)
    if (str[i] == str[curr])
      return 0;
  return 1;
}

void bullpgia::SmartGuesser::findPermutations(char str[], int index, int n)
{
  if (index >= n)
  {
    perms.push_front(str);
    return;
  }

  for (int i = index; i < n; i++)
  {
    bool check = shouldSwap(str, index, i);
    if (check)
    {
      std::swap(str[index], str[i]);
      findPermutations(str, index + 1, n);
      std::swap(str[index], str[i]);
    }
  }
}
