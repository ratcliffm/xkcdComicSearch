#ifndef XKCD_H
#define XKCD_H

#include <string> 
#include <vector>

// type defs will go here 
// Define struct xkcd that matches all of the fields in the XKCD JSON API. 
struct xkcd { 
    std::string month; 
    std::string link; 
    std::string year; 
    std::string news; 
    std::string safe_title;
    std::string transcript; 
    std::string alt;
    std::string img;
    std::string title;
    std::string day; 
    int num; 
};

typedef std::vector<xkcd> xkcdVec; 

// Define struct query that contains a pair of strings field and keyword. 
// This represents the query to perform over the dataset.
struct query { 
    std::string field;
    std::string keyword; 
};

// function declarations go here 

// Declare a function to be defined in xkcd.cpp that takes a vector of xkcd structs, 
// along with the search query as a struct, and returns a vector of xkcd structs that match 
// the query.
xkcdVec MakeQueryMatch(xkcdVec newVec, query searchQuery);

// Declare a function that prints an xkcd struct in the format “Title: Comic URL”.
void PrintStruct(xkcdVec xkcdstruct);

#endif
