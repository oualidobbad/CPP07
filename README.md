# CPP07

C++ Module 07: function and class templates — generic `swap`/`min`/`max`, a templated `iter` function, and a bounds-checked `Array<T>` container.

## Project Overview
- What it does: introduces C++ templates from simple function templates to a full generic container class.
- Core themes: template instantiation, type deduction, operator requirements, exception-safe bounds checking.

## Architecture & Design
- **ex00 (whatever)**: `swap(T&, T&)`, `min(T&, T&)`, `max(T&, T&)` — work with any type supporting `<` and `=`.
- **ex01 (iter)**: `iter(T*, size_t, void(*f)(T&))` — applies a function to each element of an array. Templated on both array type and function type.
- **ex02 (Array)**: `Array<T>` class template with:
  - Default constructor (empty), `Array(unsigned int n)` (n elements, value-initialized).
  - Copy constructor and assignment (deep copy).
  - `operator[]` with bounds checking (throws `std::exception`).
  - `size()` method.
  - Implementation in `Array.tpp` (included from header).

## Core Concepts (with code)
- Bounds-checked template array:
```cpp
// Array.hpp
template <typename T>
class Array {
    T* arr;
    size_t _size;
public:
    Array();                     // empty
    Array(unsigned int n);       // n default-constructed elements
    Array(const Array& other);   // deep copy
    Array& operator=(const Array& other);
    ~Array();
    T& operator[](unsigned int index);  // throws on OOB
    size_t size() const;
};
#include "Array.tpp"
```

## Code Walkthrough
1) ex00: three standalone function templates; tested with int, float, string.
2) ex01: `iter` applies a callback to each array element; works with any callable matching the signature.
3) ex02: `Array<T>` manages a heap-allocated `T*`; `operator[]` checks `index < _size`, throws otherwise.

## Installation & Setup
- `make` per exercise (C++98).

## Technical Deep Dive
- `.tpp` file pattern: template implementation must be visible at instantiation — included from header.
- `operator[]` throws `std::exception` (not `std::out_of_range`) per subject requirements.
- Deep copy in Array: allocates new `T[_size]`, copies element-by-element.

## Improvements & Future Work
- Add `const` overload for `operator[]`.
- Add iterator support for STL algorithm compatibility.

## Author
Oualid Obbad (@oualidobbad)