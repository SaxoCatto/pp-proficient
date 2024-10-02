#include <thread>
#include <iostream>
#include <mutex>
using namespace std;

// Global lock. Any thread that gets the lock is active.
std::mutex mtx;

void print_fn(int id){
  // Actual locking
  mtx.lock();
  std::cout<<"Came from thread: "<< id <<endl;
  // Remember to unlock. Thread that is queued first will get the lock next.
  mtx.unlock();
}

int main(){
  // make 4 threads, call print function upon receiving it
  std::thread t0(printfn, 0);
  std::thread t1(printfn, 1);
  std::thread t2(printfn, 2);
  std::thread t3(printfn, 3);
  // How to choose which thread starts first?
}
