#include "xkcd.h"
#include "json.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Declare a function to be defined in xkcd.cpp that takes a vector of xkcd
// structs,
// along with the search query as a struct, and returns a vector of xkcd structs
// that match
// the query.
xkcdVec MakeQueryMatch(xkcdVec newVec, query searchQuery) {
  xkcdVec v1;
  transform(searchQuery.field.begin(), searchQuery.field.end(), searchQuery.field.begin(), ::tolower);
  transform(searchQuery.keyword.begin(), searchQuery.keyword.end(), searchQuery.keyword.begin(), ::tolower);

    string newStr = " ";
    size_t result;

    for (unsigned int i = 0; i < newVec.size(); ++i) {
        if (searchQuery.field.compare("transcript") == 0) {
            newStr = newVec.at(i).transcript;
        } else if (searchQuery.field.compare("alt") == 0) {
            newStr = newVec.at(i).alt; 
        } else if (searchQuery.field.compare("title") == 0) {
            newStr = newVec.at(i).title;
        } else if (searchQuery.field.compare("month") == 0) {
            newStr = newVec.at(i).month;
            } else if (searchQuery.field.compare("link") == 0) {
            newStr = newVec.at(i).link;
            } else if (searchQuery.field.compare("year") == 0) {
            newStr = newVec.at(i).year;
            } else if (searchQuery.field.compare("news") == 0) {
            newStr = newVec.at(i).news;
            } else if (searchQuery.field.compare("safe_title") == 0) {
            newStr = newVec.at(i).safe_title;
            } else if (searchQuery.field.compare("img") == 0) {
            newStr = newVec.at(i).img;
            } else if (searchQuery.field.compare("day") == 0) {
            newStr = newVec.at(i).day;
            } else if (searchQuery.field.compare("num") == 0) {
            newStr = newVec.at(i).num;
            } else {
            newStr = newVec.at(i).transcript;
        }
        transform(newStr.begin(), newStr.end(), newStr.begin(), ::tolower);
        result = newStr.find(searchQuery.keyword);

        if (result != string::npos) {
            v1.push_back(newVec.at(i));
        }   
    }

    return v1;
}

// Declare a function that prints an xkcd struct in the format “Title: Comic
// URL”.

void PrintStruct(xkcdVec v2) {
  for (unsigned int i = 0; i < v2.size(); ++i) {
    xkcd structToTitle = v2[i];
    string title = structToTitle.title;
    int num = structToTitle.num;
    cout << "Title: " << title << " URL: https://xkcd.com/" << num << "/" << endl;
  }
}
