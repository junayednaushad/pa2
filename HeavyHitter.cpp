#include "HeavyHitter.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

namespace junayed_naushad
{
  Entry::Entry()
  {
    this->word = "";
    this->value = 0;
  }
  Entry::Entry(string word, int value)
  {
    this->word = word;
    this->value = value;
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

  bool Table::found(string word) const
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

  void Table::remove(string word)
  {
    int index = getHash(word, tableSize);
    for(int i = 0; i < values[index].size(); i++)
    {
      if(word.compare(values[index].at(i).getWord()) == 0)
      {
        values[index].erase(values[index].begin() + i);
        i = values[index].size();
      }
    }
  }

  int Table::getHeapIndex(string word) const
  {
    int heapIndex = 0;
    int index = getHash(word, tableSize);
    for(int i = 0; i < values[index].size(); i++)
    {
      if(word.compare(values[index].at(i).getWord()) == 0)
      {
        heapIndex += values[index].at(i).getValue();
        i = values[index].size();
      }
    }
    return heapIndex;
  }

  void Table::printTable() const
  {
    for(int i = 0; i < tableSize; i++)
    {
      for(int j = 0; j < values[i].size(); j++)
      {
        cout << values[i].at(j).getWord() << "\t\t\t" << values[i].at(j).getValue() << endl;
      }
    }
  }

  /*
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

  string Table::getWord(int heapIndex) const
  {
    string word = "";
    for(int i = 0; i < tableSize; i++)
    {
      for(int j = 0; j < values[i].size(); j++)
      {
        if(values[i].at(j).getHeapIndex() == heapIndex)
          word += values[i].at(j).getWord();
      }
    }
    return word;
  }
  */

  MinHeap::MinHeap(int heapSize)
  {
    frequencies = new Entry[heapSize];
    this->heapSize = heapSize;
    numElements = 0;
  }

  void MinHeap::printHeap() const
  {
    for(int i = 1; i < heapSize; i++)
      cout << frequencies[i].getWord() << "\t\t\t" << frequencies[i].getValue() << endl;
  }

  int MinHeap::insert(string word)
  {
    numElements++;
    int index = numElements;
    frequencies[index].setWord(word);
    frequencies[index].setValue(1);
    //check invariant
    return index;
  }

  void MinHeap::increment(int index)
  {
    int frequency = frequencies[index].getValue() + 1;
    frequencies[index].setValue(frequency);
    //check invariant
  }

  void HeavyHitter::insert(string word)
  {
    if(hashTable.found(word) == false) // word not in hash table
    {
      if(minHeap.getNumElements() != (minHeap.getHeapSize() - 1)) // min heap not full
      {
        int index = minHeap.insert(word);
        Entry e1 = Entry(word, index);
        hashTable.add(e1);
      }
      else // min heap full
      {
        replaceMin(word);
      }
    }
    else // word already in hash table
    {
      int index = hashTable.getHeapIndex(word);
      minHeap.increment(index);
    }
  }
  void HeavyHitter::replaceMin(string word)
  {
    //hashTable.remove(1);
    Entry e1 = Entry(word, 1);
    hashTable.add(e1);
  }
  void HeavyHitter::printHeap() const
  {
    minHeap.printHeap();
  }
  void HeavyHitter::printTable() const
  {
    hashTable.printTable();
  }

}
