#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
// #include <chrono>
#include <algorithm>
#include <limits>
using namespace std;
// using namespace chrono;

// Function to display the main menu
void displayMenu() {
    cout << "\n==== Severe Car Accident Query System ====" << endl;
    cout << "1. Perform Search" << endl;
    cout << "2. Load Dataset" << endl;
    cout << "3. End Program" << endl;
    cout << "Enter your choice:";
}

// Helper function
// string getValidatedInput(const string &prompt) {
//     string input;
//     cout << prompt;
//     cin.ignore();
//     getline(cin, input);
//     return input.empty() ? "All" : input; // Default to "All" if no input is provided
// }
// Helper function to get validated user input
string getValidatedInput(const string &prompt) {
    string input;
    cout << prompt;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    getline(cin, input);
    return input.empty() ? "all" : input; // Default to "All" if no input is provided
}

// Function to perform a search based on user input
void performSearch(vector<pair<string, string>> &edge_list, unordered_map<string, vector<string>> &adjacency_list) {

    // Gather search inputs
    string state = getValidatedInput("Enter State (or 'All' for all states):");
    string city = getValidatedInput("Enter City (or 'All' for all cities):");
    string timeOfDay = getValidatedInput("Enter Time of Day (Day, Night, or 'All'):");
    string weather = getValidatedInput("Enter Weather Condition (see README for list, or choose 'All'):");

    /* Query Edge List
    auto startGraph = high_resolution_clock::now();
    int graphResult = graph.query(state, city, timeOfDay, weather);
    auto endGraph = high_resolution_clock::now();
    auto graphQueryTime = duration_cast<milliseconds>(endGraph - startGraph).count();
     */

    /* Query Adjacency List
    auto startBTree = high_resolution_clock::now();
    int bTreeResult = bTree.query(state, city, timeOfDay, weather);
    auto endBTree = high_resolution_clock::now();
    auto bTreeQueryTime = duration_cast<milliseconds>(endBTree - startBTree).count();
     */

    // Display results!
    cout << "\n==== Search Results ====" << endl;
    cout << "Conditions: State - " << state << ", City - " << city
         << ", Time of Day - " << timeOfDay << ", Weather - " << weather << endl;
    cout << "Graph Result: " << 0 << " accidents, Time: " << 0 << "ms" << endl;
    cout << "BTree Result: " << 0 << " accidents, Time: " << 0 << "ms" << endl;
    cout << "\nReturning to main menu..." << endl;

}

// Function to load the dataset into both edge list and adjacency list
void loadDataset(vector<pair<string, string>> &edge_list, unordered_map<string, vector<string>> &adjacency_list) {
    try {

        // start message
        cout << "Loading dataset..." << endl;

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
        int choice;
        cin >> choice;

        switch (choice) {
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
