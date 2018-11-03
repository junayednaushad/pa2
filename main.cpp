#include "HeavyHitter.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using namespace junayed_naushad;

int main()
{
  HeavyHitter h1 = HeavyHitter(16,17);
  int operation = 0;
  string fileName;
  string word;
  cout << "\nWelcome to the heavy hitter application\n";
  while(operation != 5)
  {
    cout << "\nPlease enter the number corresponding to the operation you would like to use:\n";
    cout << "1) Find the 15 most frequent words in a text file\n";
    cout << "2) Print the min heap\n";
    cout << "3) Print the hash table\n";
    cout << "4) Insert a word\n";
    cout << "5) Quit\n";
    cin >> operation;

    if(operation == 1)
    {
      cout << "Please enter the name of the text file\n";
      cin >> fileName;
      ifstream myfile(fileName);
      string word;
      if (myfile.is_open())
      {
        while (getline(myfile, word, ' '))
        {
          h1.insert(word);
        }
      myfile.close();
      }
      else 
        cout << "Unable to open file\n"; 
    }

    else if(operation == 2)
    {
      cout << "Printing the min heap\n";
      h1.printHeap();
    }

    else if(operation == 3)
    {
      cout << "Printing the hash table\n";
      h1.printTable();
    }

    else if(operation == 4)
    {
      cout << "Please enter the word you would like to insert\n";
      cin >> word;
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      h1.insert(word);
    }

    else
    {
      cout << "Thank you for using this application\n";
    }
  }
  return 0;
  
}
