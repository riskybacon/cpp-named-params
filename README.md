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

* ```tests/function.cpp``` demonstrates named parameters for a function call
* ```tests/constructor.cpp``` demonstrates named parameters in a constructor
* ```tests/template_named_types.cpp``` named template parameters for a class
* ```tests/template_named_values.cpp``` named template values for a class

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

# Motivation

The goal is to improve the readability of function calls, constructors and
templated classes that take a large number of arguments. I have used named
parameters in Python and decided to try out the
[Boost Parameter](http://www.boost.org/doc/libs/1_64_0/libs/parameter/)
library.

These are some simple examples I created to get me started.

# Findings

Only 8 parameters are allowed. When I was looking at this library, I was
working on a machine learning project and needed upwards of 10 parameters
when calling a constructor.

I ended up not using the Boost Parameter library.

# Links

[Bring named parameters in modern C++]
(https://marcoarena.wordpress.com/2014/12/16/bring-named-parameters-in-modern-cpp/)
