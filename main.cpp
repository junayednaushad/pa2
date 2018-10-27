#include "HeavyHitter.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
using namespace junayed_naushad;

int main()
{
  Entry e1 = Entry("Hello", 5);
  cout << e1.getWord() << endl << e1.getHeapIndex() << endl;
  return 0;
}
