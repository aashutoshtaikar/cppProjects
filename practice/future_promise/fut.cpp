#include <iostream>
#include <future>
using namespace std;

    int foo(int *x)
    {
        *x = 22;
        cout << std::this_thread::get_id() << *x << " child\n";
        return 0;
    }

class test
{
  public:
  int x {};

  test(){
      cout << "here\n";
  }
    int foo()
    {
        cout << std::this_thread::get_id() << " child\n";
        x = 22;
        return 0;
    }
};

int main(){
    test testobj;
    int y = 0;
    std::future<int> fu = std::async(std::launch::async, foo, &y);
    
    cout <<  std::this_thread::get_id() << "\n";
    int x = fu.get();
    cout << y;
}