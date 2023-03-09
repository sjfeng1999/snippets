#include <iostream>
#include <map>
#include <string>

class ObjectBase {
  public:
    ObjectBase(const std::string& name);
    virtual ~ObjectBase();

  private:
    std::string name;
};

template<typename DataType>
class Object : public ObjectBase {
  public:
    Object(const std::string& name, const DataType& value);

    static Object& Register(const std::string& name, const DataType& value);

    //   private:
    DataType value;
};

class RegistryManager {
  public:
    static RegistryManager* Global();

    template<typename DataType>
    void getValue(const std::string& name, DataType& value) {
        if (obj_map.find(name) == obj_map.end()) {
            std::cout << "key is unregistered\n";
        }
        Object<DataType>* obj_ptr = dynamic_cast<Object<DataType>*>(obj_map[name]);
        if (obj_ptr != nullptr) {
            value = obj_ptr->value;
        } else {
            std::cout << "mismatch" << std::endl;
        }
    }

    std::map<const std::string, ObjectBase*> obj_map;
};

#define CONCAT_(prefix, counter) prefix##counter
#define CONCAT(prefix, counter)  CONCAT_(prefix, counter)

#define REGISTER(type, name, value)                                                                                    \
    static Object<type> CONCAT(_obj_, __COUNTER__) = Object<type>::Register(name, value);

REGISTER(int, "int_1", 10);
REGISTER(int, "int_2", 100);
REGISTER(float, "pi", 3.1415926f);