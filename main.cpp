#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

// Function to display the main menu
void displayMenu() {
    cout << "\n==== Severe Car Accident Query System ====" << endl;
    cout << "1. Perform Search" << endl;
    cout << "2. Load Dataset" << endl;
    cout << "3. End Program" << endl;
    cout << "Enter your choice:";
}

// Helper function
string getValidatedInput(const string &prompt) {
    string input;
    cout << prompt;
    getline(cin, input, '\n');
    return input.empty() ? "All" : input; // Default to "All" if no input is provided
}

// returns index of min value in list
int min(vector<size_t> s){
    int min = 0;
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] < s[min]) {
            min = i;
        }
    }
    return min;
}

// returns bool of find condition
bool find(vector<string> s, string t) {
    for(auto it : s) {
        if (it == t) {
            return true;
        }
    }
    return false;
}


// Function to perform a search based on user input
void performSearch(vector<pair<string, string>> &edge_list, unordered_map<string, vector<string>> &adjacency_list) {

    // Gather search inputs
    string state = getValidatedInput("Enter State (or 'All' for all states):");
    string city = getValidatedInput("Enter City (or 'All' for all cities):");
    string timeOfDay = getValidatedInput("Enter Time of Day (Day, Night, or 'All'):");
    string weather = getValidatedInput("Enter Weather Condition (see README for list, or choose 'All'):");

    // Adjacency List Search
    // start timer
    auto startAdList = high_resolution_clock::now();
    // puts each category in a vector
    vector<string> categories = {state, city, timeOfDay, weather};
    vector<size_t> sizes;
    for(int i = 0; i < categories.size(); i++) {
        // if category is 'All', push_back total size
        if(categories[i] == "All") {
            sizes.push_back(204710);
        }
        // push_back out-degree of category
        else {
            sizes.push_back(adjacency_list[categories[i]].size());
        }
    }
    // IDs that match the search
    int ad_matched = 0;
    int minimum = min(sizes);
    if(categories[minimum] == "All") {
        for(auto it: adjacency_list["State"]) {
            ad_matched += adjacency_list[it].size();
        }
    }
    else {
        for(auto it: adjacency_list[categories[minimum]]) {
            // Checks State
            if(categories[0] != "All" && categories[0] != adjacency_list[it][0]) {
                continue;
            }
            // Checks City
            else if(categories[1] != "All" && categories[1] != adjacency_list[it][1]) {
                continue;
            }
            // Checks Time of Day
            else if(categories[2] != "All" && categories[2] != adjacency_list[it][2]) {
                continue;
            }
            // Checks Weather
            else if(categories[3] != "All" && categories[3] != adjacency_list[it][3]) {
                continue;
            }
            ad_matched += 1;
        }
    }
    // stop timer
    auto endAdList = high_resolution_clock::now();

    // timer count in microseconds
    auto AdListTime = duration_cast<microseconds>(endAdList - startAdList);


    // Edge List Search
    // start timer
    auto startEdgeList = high_resolution_clock::now();
    int edge_matched = 0;
    // if all categories are all, return total num
    if(categories[minimum] == "All") {
        for(auto it: adjacency_list["State"]) {
            edge_matched += adjacency_list[it].size();
        }
    }
    else {
        unordered_map<string, int> frequency;
        int count = 4;
        for(auto i: categories) {
            if(i == "All") {
                count--;
            }
        }
        for(auto i: edge_list) {
            if(frequency.find(i.first) == frequency.end()) {
                frequency[i.first] = 0;
            }
            if(i.second == state || i.second == city || i.second == timeOfDay || i.second == weather) {
                frequency[i.first] += 1;
            }
        }
        for(auto it = frequency.begin(); it != frequency.end(); it++) {
            if(it->second == count) {
                edge_matched++;
            }
        }
        if(count == 1 && edge_matched > 0) {
            edge_matched--;
        }
    }


    // end timer
    auto endEdgeList = high_resolution_clock::now();

    // timer count in microseconds
    auto edgeListTime = duration_cast<microseconds>(endEdgeList - startEdgeList);

    // Display results!
    cout << "\n==== Search Results ====" << endl;
    cout << "Conditions: State - " << state << ", City - " << city
         << ", Time of Day - " << timeOfDay << ", Weather - " << weather << endl;
    cout << "Adjacency List Result: " << ad_matched << " accidents, Time: " <<  AdListTime.count() << " microseconds" << endl;
    cout << "Edge List Result: " << edge_matched << " accidents, Time: " << edgeListTime.count() << " microseconds" << endl;
    cout << "\nReturning to main menu..." << endl;

}

// Function to load the dataset into both edge list and adjacency list
void loadDataset(vector<pair<string, string>> &edge_list, unordered_map<string, vector<string>> &adjacency_list) {
    try {

        // start message
        cout << "Loading dataset..." << endl;

        // load data from .csv file & organize into a graph (use both edge list & adjacency list)
        // first, initialize variables & prepare to read the file
        ifstream csv("../Severe_Accident_Database.csv");
        string line;
        getline(csv, line);
        stringstream stream(line);
        string element;

        // then store the categories (state, city, time, & weather, NOT ID) into the edge list & adjacency list
        vector<string> categories;
        adjacency_list["Categories"];
        getline(stream, element, ',');
        while (getline(stream, element, ',')) {
            categories.push_back(element);
            edge_list.emplace_back("Categories", element);
            adjacency_list["Categories"].push_back(element);
            adjacency_list[element];
        }

        // finally, go through the database and construct the edge list & adjacency list!
        while (getline(csv, line)) {
            int column = 0;
            stringstream substream(line);
            string ID, subelement;
            getline(substream, ID, ',');

            while (getline(substream, subelement, ',')) {
                if (adjacency_list.find(subelement) == adjacency_list.end()) {
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

        // end message
        cout << "Dataset loaded!" << endl;

    } catch (const exception &e) {

        // error message
        cerr << "Error loading dataset: " << e.what() << endl;

    }
}

// written by... Alexander Langner, Joseph Ciffarelli, & Khizar Khan... for COP3530!
int main()
{
    // initialize the edge list & adjacency list
    vector<pair<string, string>> edge_list;
    unordered_map<string, vector<string>> adjacency_list;

    // load menu and begin main program!
    while (true) {
        displayMenu();
        string choice;
        int option;
        // changed to help format and handle errors better
        getline(cin, choice, '\n');
        try {
            option = stoi(choice);
        }
        catch(invalid_argument){
            option = 4;
        }

        switch (option) {
            case 1: // Perform Search
                performSearch(edge_list, adjacency_list);
                break;
            case 2: // Load Dataset
                loadDataset(edge_list, adjacency_list);
                break;
            case 3: // End Program
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
