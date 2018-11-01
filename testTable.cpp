#include "HeavyHitter.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
using namespace junayed_naushad;

int main()
{
  cout << getHash("junayed",17) << endl;
  Table t1 = Table(17);
  Entry e1 = Entry("hello",1);
  Entry e2 = Entry("world",2);
  Entry e3 = Entry("anon",3);
  t1.add(e1);
  t1.add(e2);
  t1.add(e3);
  t1.printTable();
  cout << t1.found("junayed") << endl;
  cout << t1.found("hello") << endl;
  int index = t1.getHeapIndex("anon");
  cout << "index: " << index << endl;
  t1.remove("hello");
  t1.printTable();
  return 0;
}
