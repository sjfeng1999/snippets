#include "registry.h"

ObjectBase::ObjectBase(const std::string& name) : name(name) {}

ObjectBase::~ObjectBase() {}

RegistryManager* RegistryManager::Global() {
    static RegistryManager* singleton = new RegistryManager();
    return singleton;
}

template<typename DataType>
Object<DataType>::Object(const std::string& name, const DataType& value) : ObjectBase(name), value(value) {}

template<typename DataType>
Object<DataType>& Object<DataType>::Register(const std::string& name, const DataType& value) {
    Object<DataType>* obj = new Object<DataType>(name, value);
    RegistryManager::Global()->obj_map.emplace(name, static_cast<ObjectBase*>(obj));
    return *obj;
}