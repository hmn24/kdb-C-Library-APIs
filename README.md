# kdb+ Regex + Hashing API
## Regex Boost API

__1) Tutorials for learning how to use Regex Boost Library__

`https://medium.com/factory-mind/regex-tutorial-a-simple-cheatsheet-by-examples-649dc1c3f285`
  
  
_Discussions on issues with strdup:_

`https://stackoverflow.com/questions/12984948/why-is-strdup-considered-to-be-evil`
  
  
_Portability is an issue, with the following defined if compiled in VSC++ with Windows OS_

`// String copy, allows portability between Visual Studio C++ and UNIX compilers`
```#if defined(WIN32) || defined(_WIN32)
#define strdup _strdup
#endif```
  
  
  
__2) Installation Instructions__

`sudo apt-get install libboost-regex-dev`

`g++ -shared -fPIC regex.cpp -lboost_regex -o $QHOME/l64/regex.so`

&nbsp;
&nbsp;
&nbsp;
## Hashing API

__1) Tutorials for learning how to use Regex Boost Library__

It can only accept strings/symbols. There are two flavours provided here in the repo, i.e. cppStdHash and cppMapHash. The former is part of the functional lib (i.e. faster though less collision-proof), while the latter unordered_map library for purposes of building hash tables (i.e. likely to be more collision-proof). 
  
  
  
__2) Installation Instructions__

`g++ -shared -fPIC hash.cpp -o $QHOME/l64/hash.so`

&nbsp;
&nbsp;
&nbsp;
## Identify Functions Under Shared Objects

Run the following example command:

`nm -D --defined-only regex.so | grep -v _`
