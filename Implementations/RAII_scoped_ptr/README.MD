## custom unique pointer  

issue: this must not be allowed for compilation
int x = 10;
unique_ptr<int> y = &x; 