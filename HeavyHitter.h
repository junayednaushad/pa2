#ifndef HEAVYHITTER_H
#define HEAVYHITTER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

namespace junayed_naushad
{
  class Entry
  {
  public:
    //constructor
    Entry(std::string word, int heapIndex);

    //getters
    std::string getWord() const {return word;}
    int getHeapIndex() const {return heapIndex;}

    //setters
    void setWord(std::string word) {this->word = word;}
    void setHeapIndex(int heapIndex) {this->heapIndex = heapIndex;}

  private:
    std::string word;
    int heapIndex;
  };

  class Table
  {
  public:
    //constructor
    Table(int tableSize);

    int getTableSize() const {return tableSize;}
    bool found(std::string word); // returns true if word is in table
    void add(Entry e); // adds new entry to the table
    void remove(int heapIndex); // removes word associated with given heapIndex
    void printTable();

  private:
    std::vector<Entry> *values;
    int tableSize;
  };
  int getHash(std::string word, int tableSize); // returns address in table

  class MinHeap
  {
  public:

  private:

  };

  class HeavyHitter
  {
  public:

  private:
  };
}
#endif
