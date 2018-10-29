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
    //constructors
    Entry();
    Entry(std::string word, int value);

    //getters
    std::string getWord() const {return word;}
    int getValue() const {return value;}

    //setters
    void setWord(std::string word) {this->word = word;}
    void setValue(int value) {this->value = value;}

  private:
    std::string word;
    int value;
  };

  class Table
  {
  public:
    //constructor
    Table(int tableSize);

    int getTableSize() const {return tableSize;}
    bool found(std::string word) const; // returns true if word is in table
    void add(Entry e); // adds new entry to the table
    void remove(std::string word); // removes word from hashtable
    int getHeapIndex(std::string word) const; // returns min heap index of given word
    void printTable() const;
    /*
    void remove(int heapIndex); // removes word associated with given heapIndex
    std::string getWord(int heapIndex) const; // returns word associated with given heapIndex
    */
  private:
    std::vector<Entry> *values;
    int tableSize;
  };
  int getHash(std::string word, int tableSize); // returns address in table

  class MinHeap
  {
  public:
    MinHeap(int heapSize);
    void printHeap() const; // print 15 most frequent words with corresponding frequencies
    int insert(std::string word); // inserts new word into min heap and returns index
    void increment(int index); // increments frequency at given index and adjusts heap
    int getNumElements() const {return numElements;}
    int getHeapSize() const {return heapSize;}
  private:
    Entry *frequencies;
    int heapSize;
    int numElements;
  };


  class HeavyHitter
  {
  public:
    HeavyHitter(int heapSize, int tableSize) : minHeap(heapSize), hashTable(tableSize) {}
    void insert(std::string word);
    void replaceMin(std::string word);
    void printHeap() const;
    void printTable() const;

  private:
    MinHeap minHeap;
    Table hashTable;
  };

}
#endif
