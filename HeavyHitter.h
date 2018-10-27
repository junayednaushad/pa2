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
    Entry(std::string word, int heapIndex)
    {
      this->word = word;
      this->heapIndex = heapIndex;
    }

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

  private:
  };

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
