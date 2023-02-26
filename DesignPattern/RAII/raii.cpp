#include <iostream>

class RAII_Class {
private:
  int *resource_ptr;

public:
  RAII_Class(int size) {
    std::cout << "RAII: alloc memory in ctor\n";
    resource_ptr = static_cast<int *>(malloc(size));
  }

  ~RAII_Class() {
    free(resource_ptr);
    std::cout << "RAII: memory free in dtor\n";
  }
};

int main() {
  {
    std::cout << "alloc memory\n";
    RAII_Class handle(100);
  }
  std::cout << "memory is released when leaving block scope\n";
  return 0;
}