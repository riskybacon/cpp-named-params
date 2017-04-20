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

I would like to improve the readability of function calls and constructors that
take a large number of arguments. I have used named parameters in Python and
decided to try out the
[Boost Parameter](http://www.boost.org/doc/libs/1_64_0/libs/parameter/)
library. I find that I need simple, complete examples to get started, and did
not see this in the library's documentation.

After a bit of work, these are the examples I came up with. I hope they help
you get started with the Boost Parameter library.

# Findings

I decided not to use the Boost Parameter library. I found it to be limited to
a total of 8 parameters. I did not see this limitation documented. Perhaps I
did not look hard enough. Perhaps the compiler I was using (clang 3.9.0)
introduced the limitation. Regardless, I needed more than eight parameters and
decided to look for other ways to get the readability I was after.

# Links

I found some good ideas in the blog post [Bring named parameters in modern C++](https://marcoarena.wordpress.com/2014/12/16/bring-named-parameters-in-modern-cpp/)
