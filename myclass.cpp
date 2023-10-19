#include <iostream>
#include "myclass.h"

template <typename T>
MyClass<T>::MyClass(T value) : m_value(value) {}

template <typename T>
void MyClass<T>::printValue() {
  std::cout << "Value: " << m_value << std::endl;
}

// 可选：显式实例化模板类的特定类型
template class MyClass<int>;
template class MyClass<double>;
