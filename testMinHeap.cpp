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
  m1.insert("hello");
  m1.insert("world");
  m1.insert("abc");
  m1.increment(2);
  m1.increment(2);
  m1.increment(3);
  m1.increment(3);
  m1.increment(3);
  m1.printHeap();
  return 0;
}
