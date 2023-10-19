#ifndef MYCLASS_H
#define MYCLASS_H

template <typename T>
class MyClass {
 public:
  MyClass(T value);
  void printValue();

 private:
  T m_value;
};

#endif  // MYCLASS_H
