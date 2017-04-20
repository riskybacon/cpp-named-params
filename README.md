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
git@github.com:riskybacon/cpp-named-params.git
cd cpp-named-params
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

These are some simple examples I wrote so that I could understand the
[tutorial](http://www.boost.org/doc/libs/1_64_0/libs/parameter/doc/html/index.html#tutorial).

# Findings

Only 8 parameters are allowed. When I was considering this library, I was
working on a machine learning project and needed upwards of 10 parameters.

I decided not to use the Boost Parameter library and instead used a
configuration structure and method chaining.

# Links

[Bring named parameters in modern C++](https://marcoarena.wordpress.com/2014/12/16/bring-named-parameters-in-modern-cpp/)

[Named Parameter Idiom using Method Chaining](https://web-beta.archive.org/web/20140106052713/http://www.parashift.com/c++-faq-lite/named-parameter-idiom.html)

[More C++ Idioms/Named Parameter](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Named_Parameter)
