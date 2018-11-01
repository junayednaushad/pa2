#include "HeavyHitter.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
using namespace junayed_naushad;

int main()
{
  MinHeap m1 = MinHeap(16);
  int one = m1.insert("a");
  int two = m1.insert("b");
  int three = m1.insert("c");
  m1.printHeap();
  cout << endl;
  
  m1.increment(1);
  m1.printHeap();
  cout << endl;

  m1.increment(1);
  m1.printHeap();
  cout << endl;

  m1.increment(1);
  m1.printHeap();
  cout << endl;

  m1.increment(3);
  m1.printHeap();
  cout << endl;

  m1.insert("d");
  m1.printHeap();
  cout << endl;

  m1.increment(3);
  m1.printHeap();
  cout << endl;

  m1.increment(2);
  m1.printHeap();
  cout << endl;

  m1.increment(1);
  m1.printHeap();
  cout << endl;

  m1.increment(1);
  m1.printHeap();
  cout << endl;

  m1.increment(2);
  m1.printHeap();
  cout << endl;
  /*
  m1.increment(1);
  m1.increment(1);

  m1.increment(2);
  m1.increment(2);
  m1.increment(2);
  m1.increment(2);
  m1.increment(2);
  m1.increment(2);

  m1.increment(3);
  m1.increment(3);
  m1.increment(3);
  m1.increment(3);
  m1.increment(3);
  m1.increment(3);
  m1.increment(3);

  int four = m1.insert("j");
  cout << "should be one: " << four << endl;
  int five = m1.insert("k");
  cout << "shoudl be 2: " << five << endl;
  m1.printHeap();
  */
  return 0;
}
