// Winter'24
// Instructor: Diba Mirza
// Student name: Jingyang Liu
// 2026.5.23
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the movies

    string line, movieName;
    double movieRating;
    map<string, double> MovieMap;
    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        construct_map(MovieMap, movieName, movieRating);
            // Use std::string movieName and double movieRating
            // to construct your Movie objects
            // cout << movieName << " has rating " << movieRating << endl;
            // insert elements into your data structure
    }

    movieFile.close();

    if (argc == 2){
        for (auto const& pair : MovieMap) {
            cout << pair.first << ", " << pair.second << endl;
        }
            //print all the movies in ascending alphabetical order of movie names
            return 0;
    }

    ifstream prefixFile (argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> prefixes;
    while (getline (prefixFile, line)) {
        if (!line.empty()) {
            prefixes.push_back(line);
        }
    }

    vector<vector<Movie>> movie_v;
    for (int i = 0; i < prefixes.size(); i++) {
        vector<Movie> prefix;
        store_prefix(prefix, MovieMap, prefixes[i]);
        order_m(prefix);
        movie_v.push_back(prefix);
    }

    for (int i = 0; i < movie_v.size(); i++) {
        if (movie_v[i].size() == 0) {
            cout << "No movies found with prefix "<< prefixes[i] << endl;
        }
        else {
            for (int j = 0; j < movie_v[i].size(); j++) {
                cout << movie_v[i][j].name << ", " << std::fixed << std::setprecision(1) << movie_v[i][j].rating << endl;
            }
            cout << endl;
        }
    }
    //  For each prefix,
    //  Find all movies that have that prefix and store them in an appropriate data structure
    //  If no movie with that prefix exists print the following message

    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.
    for (int i = 0; i < movie_v.size(); i++) {
        if (movie_v[i].size() == 0) continue;
        Movie best = movie_v[i][0];
        cout << "Best movie with prefix " << prefixes[i] << " is: " << best.name << " with rating " << std::fixed << std::setprecision(1) << best.rating << endl;
    }
    
    return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}