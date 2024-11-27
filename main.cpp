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
    unordered_map<string, string> adjacency_list;
    cout << "done" << "\n";

    // load data from .csv file & organize into graph (adjacency list & adjacency matrix)
    ifstream csv("New_Severe_Accident_Database.csv");
    if (csv.is_open())
    {
        cout << "true" << "\n";
    }
    string current_line;
    cout << "done" << "\n";

    while(getline(csv, current_line))
    {
        cout << current_line << "\n";
    }

    /*
    vector<string> current_row;
    stringstream stream(current_line);
    string current_cell;
    while (getline(stream, current_cell, ','))
    {
        current_row.push_back(current_cell);
        cout << "done" << "\n";
    }

    for (const auto & i : current_row)
    {
        cout << i << " ";
        cout << "done" << "\n";
    }

    while (getline(csv, current_line))
    {
        vector<string> current_row;
        stringstream stream(current_line);
        string current_cell;

        while (getline(stream, current_cell, ','))
        {
            current_row.push_back(current_cell);
        }
    }

    // code for recording time
    auto start = chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
     */

    return 0;
}