#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

// written by... Alexander Langner, Joseph Ciffarelli, & Khizar Khan... for COP3530!
int main()
{
    // initialize the edge list & adjacency list
    vector<pair<string, string>> edge_list;
    unordered_map<string, vector<string>> adjacency_list;

    // load data from .csv file & organize into a graph (use both edge list & adjacency list)
    // first, initialize variables & prepare to read the file
    ifstream csv("Severe_Accident_Database.csv");
    string line;
    getline(csv, line);
    stringstream stream(line);
    string element;

    // then store the categories (state, city, time, & weather, NOT ID) into the edge list & adjacency list
    vector<string> categories;
    adjacency_list["Categories"];
    getline(stream, element, ',');
    while (getline(stream, element, ','))
    {
        categories.push_back(element);
        edge_list.emplace_back("Categories", element);
        adjacency_list["Categories"].push_back(element);
        adjacency_list[element];
    }

    // finally, go through the database and construct the edge list & adjacency list!
    while (getline(csv, line))
    {
        int column = 0;
        stringstream substream(line);
        string ID, subelement;
        getline(substream, ID, ',');
        while (getline(substream, subelement, ','))
        {
            if (adjacency_list.find(subelement) == adjacency_list.end())
            {
                edge_list.emplace_back(categories[column], subelement);
                adjacency_list[categories[column]].push_back(subelement);
            }
            edge_list.emplace_back(subelement, ID);
            edge_list.emplace_back(ID, subelement);
            adjacency_list[subelement].push_back(ID);
            adjacency_list[ID].push_back(subelement);
            column++;
        }
    }

    /*
    // code for recording time
    auto start = chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
     */

    return 0;
}