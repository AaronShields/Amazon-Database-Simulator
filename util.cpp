#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<string>words; 
    unsigned int start = 0; 
    //assign an unsinged int begin 
    //sorting through the given words
    for (unsigned int i = 0; i < rawWords.size(); i++){
        if(i == rawWords.size()-1){
            words.insert(rawWord.substr(start)); 
        }
        //check to see if there are any spaces or punctuation 
        else if(rawWords[i] == ' ' || ispunct(rawWords[i])){
            if(rawWrods.subtr(start, i-start).size()) >= 2)
            {
                words.insert(rawWords.substr(start, i-start)); 
            }
            start = i+1; 
        }
    }
    return words; 
        
    }










}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
