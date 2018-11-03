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

  void Table::setHeapIndex(string word, int index)
  {
    int table_index = getHash(word, tableSize);
    for(int i = 0; i < values[table_index].size(); i++)
    {
      if(word.compare(values[table_index].at(i).getWord()) == 0)
      {
        values[table_index].at(i).setValue(index);
        i = values[table_index].size();
      }
    }
  }

  void Table::printTable() const
  {
    for(int i = 0; i < tableSize; i++)
    {
      for(int j = 0; j < values[i].size(); j++)
      {
        cout << "Word: " << values[i].at(j).getWord() << "\t\t\t\tHeap Index: " << values[i].at(j).getValue() << endl;
      }
    }
  }

  MinHeap::MinHeap(int heapSize)
  {
    frequencies = new Entry[heapSize];
    this->heapSize = heapSize;
    numElements = 0;
  }

  string MinHeap::getWordAtIndex(int index) const
  {
    string word = frequencies[index].getWord();
    return word;
  }

  int MinHeap::getFrequencyAtIndex(int index) const
  {
    int frequency = frequencies[index].getValue();
    return frequency;
  }

  void MinHeap::setEntry(int index, string word, int frequency)
  {
    frequencies[index].setWord(word);
    frequencies[index].setValue(frequency);
  }

  void MinHeap::swap(int index1, int index2)
  {
    string word1 = frequencies[index1].getWord();
    int freq1 = frequencies[index1].getValue();
    string word2 = frequencies[index2].getWord();
    int freq2 = frequencies[index2].getValue();
    frequencies[index2].setWord(word1);
    frequencies[index2].setValue(freq1);
    frequencies[index1].setWord(word2);
    frequencies[index1].setValue(freq2);
  }

  void MinHeap::printHeap() const
  {
    for(int i = 1; i <= numElements; i++)
      cout << "Word: " << frequencies[i].getWord() << "\t\t\t\tFrequency: " << frequencies[i].getValue() << endl;
  }

  int MinHeap::insert(string word)
  {
    numElements++;
    int index = numElements;
    frequencies[index].setWord(word);
    frequencies[index].setValue(1);

    while(index > 1 && frequencies[index].getValue() < frequencies[index/2].getValue())
    {
      swap(index, (index/2));
      index = index/2;
    }
    return index;
  }

  void MinHeap::increment(int index)
  {
    int frequency = frequencies[index].getValue() + 1;
    frequencies[index].setValue(frequency);
    //check invariant
    int left;
    int right;
    while(2*index <= numElements)
    {
      if(2*index + 1 > numElements) //has only one child
      {
        if(frequencies[index].getValue() > frequencies[2*index].getValue())
        {
          swap(index, (2*index));
          return;
        }
        else
          return;
      }
      else //has two children
      {
        left = frequencies[2*index].getValue();
        right = frequencies[2*index+1].getValue();
        if(frequencies[index].getValue() > left || frequencies[index].getValue() > right)
        {
          if(left <= right)
          {
            swap(index, (2*index));
            index = 2*index;
          }
          else
          {
            swap(index, (2*index+1));
            index = 2*index+1;
          }
        }
        else
          return;
      }
    }
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
        updateTable();
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
      updateTable();
    }
  }

  void HeavyHitter::replaceMin(string word)
  {
    string old_min = minHeap.getWordAtIndex(1);
    int min_frequency = minHeap.getFrequencyAtIndex(1);
    hashTable.remove(old_min);
    Entry e1 = Entry(word, 1);
    hashTable.add(e1);
    minHeap.setEntry(1, word, min_frequency);
  }

  void HeavyHitter::updateTable()
  {
    string word;
    for(int i = 1; i <= minHeap.getNumElements(); i++)
    {
      word = minHeap.getWordAtIndex(i);
      if(hashTable.getHeapIndex(word) != i)
      {
        hashTable.setHeapIndex(word,i);
      }
    }
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
