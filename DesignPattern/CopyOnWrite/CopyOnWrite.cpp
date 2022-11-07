#include <iostream>
#include <memory>
#include <string>

class Object {
  public:
    Object(const Object& obj) : str_(obj.str()) {}

    Object(const std::string& str) : str_(str) {
        std::cout << "Object Ctor\n";
    }

    Object(std::string&& str) : str_(std::move(str)) {
        std::cout << "Object Ctor rvalue\n";
    }

    ~Object() {
        std::cout << "Object Dtor\n";
    }

    std::string& str() {
        return str_;
    }

    const std::string& str() const {
        return str_;
    }

    void show() const {
        std::cout << "==========\nptr_ addr : " << &str_ << "\ncontent : " << str_ << std::endl;
    }

  private:
    std::string str_;
};

class CopyOnWriteObject {
  public:
    CopyOnWriteObject() {
        ptr_ = std::make_shared<Object>("Create string");
    }

    CopyOnWriteObject(const CopyOnWriteObject& object) : ptr_(object.ptr_) {}

    CopyOnWriteObject(CopyOnWriteObject&& object) : ptr_(std::move(object.ptr_)) {}

    const Object& operator*() const {
        return *ptr_;
    }

    Object& operator*() {
        copy();
        return *ptr_;
    }

    const Object* operator->() const {
        return ptr_.operator->();
    }

    Object* operator->() {
        copy();
        return ptr_.operator->();
    }

    void show() {
        ptr_->show();
    }

  public:
    std::shared_ptr<Object> ptr_;

  private:
    void copy() {
        Object* origin_data = ptr_.get();
        if (!ptr_.unique()) {
            ptr_ = std::make_shared<Object>(*origin_data);
        }
    }
};

int main() {
    CopyOnWriteObject o1;
    CopyOnWriteObject o2 = o1;
    o1.show();
    o2.show();
    *o2 = std::string("changed");
    o1.show();
    o2.show();
    return 0;
}