#include "HeavyHitter.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

namespace junayed_naushad
{
  Entry::Entry(string word, int heapIndex)
  {
    this->word = word;
    this->heapIndex = heapIndex;
  }

  int getHash(string word, int tableSize)
  {
    int hashCode = 0;
    int word_length = word.length();
    char *arr = new char[word_length];
    for(int i = 0; i < word_length; i++)
    {
      arr[i] = word.at(i);
      hashCode += ((int)arr[i]) * (i+1);
    }
    delete [] arr;
    return hashCode % tableSize;
  }

  Table::Table(int tableSize)
  {
    this->tableSize = tableSize;
    values = new vector<Entry>[tableSize];
  }

  bool Table::found(string word)
  {
    int index = getHash(word, tableSize);
    for(int i = 0; i < values[index].size(); i++)
    {
      if(word.compare(values[index].at(i).getWord()) == 0)
        return true;
    }
    return false;
  }

  void Table::add(Entry e)
  {
    int index = getHash(e.getWord(), tableSize);
    values[index].push_back(e);
  }

  void Table::remove(int heapIndex)
  {
    for(int i = 0; i < tableSize; i++)
    {
      for(int j = 0; j < values[i].size(); j++)
      {
        if(values[i].at(j).getHeapIndex() == heapIndex)
          values[i].erase(values[i].begin() + j);
      }
    }
  }
  void Table::printTable()
  {
    cout << "Printing the hash table\n";
    for(int i = 0; i < tableSize; i++)
    {
      for(int j = 0; j < values[i].size(); j++)
      {
        cout << values[i].at(j).getWord() << "\t\t\t" << values[i].at(j).getHeapIndex() << endl;
      }
    }
  }

}
