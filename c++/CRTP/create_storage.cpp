#include <iostream>

template <typename Algorithm>
struct Policy;

template <typename T>
struct Reduce;

template <typename T>
struct Policy<Reduce<T>> {
    struct Storage {
        int x;
    };
};

template <typename Algorithm>
struct AllocStorage {
    using Storage = typename Policy<Algorithm>::Storage;

    static Storage& Get() {
        static Storage storage;
        return storage;
    }
};

template <typename T>
struct Reduce : public Policy<Reduce<T>>, AllocStorage<Reduce<T>> {
  public:
    using AllocStorageT = AllocStorage<Reduce>;
    using Storage = typename Policy<Reduce>::Storage;

  private:
    Storage& storage_;

  public:
    Reduce() : storage_(AllocStorageT::Get()) {}

    void set(T x) { storage_.x = x; }

    void print() { std::cout << "Storage value is " << storage_.x << std::endl; }
};

int main() {
    Reduce<int> r;
    r.print();
    r.set(10);
    r.print();
    return 0;
};