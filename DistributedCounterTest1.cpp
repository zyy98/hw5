#include"DistributedCounter1.h"
#include<thread>
#include<iostream>
#include<chrono>
#include<vector>
#include<algorithm>
#include<iterator>
#include "../jthread-master/source/jthread.hpp"

using namespace mpcs;
using namespace std;
size_t const reps{100'000'000};
size_t const threadCount{10};
DistributedCounter c;

void countALot()
{
  for (size_t s = 0; s < reps; s++)
    c++;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    {
        vector<jthread> threads;
        for (size_t s = 0; s < threadCount; s++)
            threads.push_back(jthread(countALot));
    };

  auto end = chrono::high_resolution_clock::now();
  cout << "Count is " << c.get() << endl;
  cout << "Elapsed time is " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
  return 0;
}