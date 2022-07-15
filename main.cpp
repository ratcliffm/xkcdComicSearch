#include "xkcd.h"
#include <iostream> 
#include <cstdlib> 
#include "json.hpp"
#include <fstream>
#include <vector> 

// for convenience
using json = nlohmann::json;
using namespace std;

int main(int argc, char *argv[]) { 
    //cout << argv[0] << endl; 
    //cout << argv[1] << endl; 
    //cout << argv[2] << endl; 
    // make lowercase 
    //for_each(*argv.begin(), *argv.end(), [](char & c){
     // c = ::tolower(c);

    query q;
    if (argc >= 4) {
        string searchField = argv[1];
        string searchKey = argv[2];
        q.field = searchField;
        q.keyword = searchKey;
    } else if (argc == 3) {
        string searchField = argv[1];
        string searchKey = argv[2];
        q.field = searchField;
        q.keyword = searchKey;
    } else if (argc == 2) {
        string searchField = "transcript"; 
        string searchKey = argv[1];
        q.field = searchField;
        q.keyword = searchKey;
        //If the user does not provide valid arguments on the command-line, 
    } else if (argc < 2) {
        cout << "Hello, and welcome to our comic search." << endl;
        cout << "Please enter your search request by entering the field of search, followed by any key words or flags." << endl;
        cout << "A valid search format would be 'field' or 'field keyword' or 'flag field keyword' or 'field keyword flag'." << endl;
        cout << "For example, if you wanted to search for cats, you would type 'transcript cats'." << endl; 
        cout << "If you wantd the image of a comic with cats your search would be 'cats --img'. " << endl;
        cout << "Enjoy your search!" << endl; 
    }

    ifstream inFS;
    // Read from standard input one line at a time. 
    inFS.open("xkcd.json");
    string data; 

    if (!inFS.is_open()) {
        cerr << "Error: file did not open" << endl; 
        return 1; 
    } 
     
    xkcd fieldStruct;
    xkcdVec newVec;
    while (getline(inFS, data) && !inFS.eof()) {
        auto j = json::parse(data); 
                // void to_json(json& parsed) {
                // Parse each incoming line into an XKCD struct. 
                fieldStruct.month = j["month"].get<string>(); 
                fieldStruct.link = j["link"].get<string>();
                fieldStruct.year = j["year"].get<string>(); 
                fieldStruct.news = j["news"].get<string>(); 
                fieldStruct.safe_title = j["safe_title"].get<string>();
                fieldStruct.transcript = j["transcript"].get<string>(); 
                fieldStruct.alt = j["alt"].get<string>();
                fieldStruct.img = j["img"].get<string>(); 
                fieldStruct.title = j["title"].get<string>(); 
                fieldStruct.day = j["day"].get<string>();  
                fieldStruct.num = j["num"].get<int>(); 


                // put each field into struct and create vector of each struct. 
                newVec.push_back(fieldStruct);
                //cout << fieldStruct << endl;
                //cout << newVec << endl;
                }

    // cout << fieldStruct.num << endl;
    xkcdVec vec = MakeQueryMatch(newVec, q);
    cout << "Comics that match your search: " << endl; 
        if (argv[3] == "--img" || argv[2] == "--img" || argv[1] == "--img") {
            for (unsigned int i = 0; i < vec.size(); ++i) { 
            xkcd structToTitle = vec[i];
            //string title = structToTitle.title;
            cout << "Image URL: " << structToTitle.img << endl; } 
            } else if (argv[3] == "--random" || argv[2] == "--random" || argv[1] == "--random") {
                cout << "Random Comic Title: " << vec[0].title << " URL: https://xkcd.com/" << vec[0].num << "/" << endl; 
            } else {
                PrintStruct(vec);
            }
    
    // close file 
    inFS.close(); 
    return 0;
}
