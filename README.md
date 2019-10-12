# kdb+ Regex + Hashing API
Regex Boost API

__1) Tutorials for learning how to use regex__

`https://medium.com/factory-mind/regex-tutorial-a-simple-cheatsheet-by-examples-649dc1c3f285`

_Discussions on issues with strdup:_

`https://stackoverflow.com/questions/12984948/why-is-strdup-considered-to-be-evil`

Portability is an issue, with the following defined if compiled in VSC++ with Windows OS

`// String copy, allows portability between Visual Studio C++ and UNIX compilers
#if defined(WIN32) || defined(_WIN32)
#define strdup _strdup
#endif`


__2) Installation Instructions__

`sudo apt-get install libboost-regex-dev`

`g++ -shared -fPIC regex.cpp -lboost_regex -o $QHOME/l64/regex.so`


__3) To identify what functions is under .so object defined within regex.so__

Run the following commands:

`nm -D --defined-only regex.so | grep -v _`
