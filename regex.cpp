#include <boost/regex.hpp>
#include "kdbToStr.hpp"

#define catchP catch(std::exception &e) {R krr(strdup(e.what()));} 

extern "C" {

// Regex match function
K regexMatch(K input, K expr) {
    
    P(!(input->t == -KS || input->t == KC), krr((S) "type")); // Check the types
    P(expr->t != KC, krr((S) "type"));     
    
    try {
        return kb((bool) boost::regex_match(kdb2str(input), boost::regex {kdb2str(expr)}));
    } catchP

 }

// Regex search function
K regexSearch(K input, K expr) {
    
    P(input->t != KC || expr->t != KC, krr((S) "type")); // Check the types
    
    // Regex tokens - Only first one represents complete match, the rest are subtokens 
    boost::smatch what;

    try {
        return boost::regex_search(std::string(kdb2str(input)), what, boost::regex{kdb2str(expr)}) ? kp((S) what.str().c_str()) : kp((S) "");
    } catchP

 }

// Regex replace function
K regexReplace(K input, K expr, K replace) {

    P(input->t != KC || expr->t != KC || replace->t != KC, krr((S) "type")); // Check the types

    try {
        std::string op = boost::regex_replace(std::string(kdb2str(input)), boost::regex{kdb2str(expr)}, std::string(kdb2str(replace)));
        return kp((S) op.c_str());
    } catchP

 }

}

