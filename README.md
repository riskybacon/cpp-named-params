# cpp-named-params

Examples of how to use named parameters in C++

Examples using the
[Boost Parameter](http://www.boost.org/doc/libs/1_64_0/libs/parameter/) library

* Named parameters for a constructor
* Named template parameters, using types
* Named template parameters, using integer values

# Implementation

The implementation is in the ```cpp_named_params/``` directory. Usage is in
the ```tests/``` directory.

Start by looking at the ```tests/``` directory to get an idea of what the
resulting APIs will look like. Then start looking at the implementation.

The intended order:

* tests/function_named_values.cpp (todo)
* tests/constructor_named_values.cpp
* tests/template_named_types.cpp (todo)
* tests/template_named_values.cpp

# Building and Running

These examples rely on [Boost](http://www.boost.org) and
[CMake](https://cmake.org). You will need to install both of these before
building and running. Once those are installed, build and run the tests with:

```
mkdir build
cd build
cmake ..
make
cd tests
ctest
```
