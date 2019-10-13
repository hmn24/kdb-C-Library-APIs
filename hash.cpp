#include <unordered_map>
#include <functional> // for hash<class template> class 
#include "kdbToStr.hpp"

typedef std::unordered_map<std::string,std::string> stringmap;
stringmap mymap;

extern "C" {

// C++ UnorderedMap Hash Function from http://www.cplusplus.com/reference/unordered_map/unordered_map/hash_function/
K cppMapHash(K input) {
        
    P(!(input->t == -KS || input->t == KC), krr((S) "type")); // Check the types

    try {return kj((J) mymap.hash_function()(kdb2str(input)));} 
    catch (std::exception &e) {return krr((S) e.what());}
 }

// Check that the hashes from unordered_map are equivalent 
K cppMapHashEquals(K expr_one, K expr_two) {
        
    P(!(expr_one->t == -KS || expr_one->t == KC), krr((S) "type")); // Check the types
    P(!(expr_two->t == -KS || expr_two->t == KC), krr((S) "type")); // Check the types

    try {return kb((I) mymap.key_eq()(kdb2str(expr_one), kdb2str(expr_two)));} 
    catch (std::exception &e) {return krr((S) e.what());}
 }

// C++ fast Standard Functional Hash Function from https://www.geeksforgeeks.org/stdhash-class-in-c-stl/
K cppStdHash(K input) {
        
    P(!(input->t == -KS || input->t == KC), krr((S) "type")); // Check the types

    std::hash<std::string> stdHash;

    try {return kj((J) stdHash(kdb2str(input)));} 
    catch (std::exception &e) {return krr((S) e.what());}
 }

}



