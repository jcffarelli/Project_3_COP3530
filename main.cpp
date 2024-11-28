//#include <unordered_map>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <string>
//#include <chrono>
//using namespace std;
//
//// written by... Alexander Langner, Joseph Ciffarelli, & Khizar Khan... for COP3530!
//int main()
//{
//    unordered_map<string, string> adjacency_list;
//    cout << "done" << "\n";
//
//    // load data from .csv file & organize into graph (adjacency list & adjacency matrix)
//    ifstream csv("Severe_Accident_Database.csv");
//    if (csv.is_open())
//    {
//        cout << "true" << "\n";
//    }
//    string current_line;
//    cout << "done" << "\n";
//
//    if (csv.good())
//    {
//        cout << "true" << "\n";
//    }
//
//    while (getline(csv, current_line))
//    {
//        cout << current_line << "\n";
//    }
//
//    if (csv.is_open())
//    {
//        cout << "true" << "\n";
//    }
//
//    /*
//    vector<string> current_row;
//    stringstream stream(current_line);
//    string current_cell;
//    while (getline(stream, current_cell, ','))
//    {
//        current_row.push_back(current_cell);
//        cout << "done" << "\n";
//    }
//
//    for (const auto & i : current_row)
//    {
//        cout << i << " ";
//        cout << "done" << "\n";
//    }
//
//    while (getline(csv, current_line))
//    {
//        vector<string> current_row;
//        stringstream stream(current_line);
//        string current_cell;
//
//        while (getline(stream, current_cell, ','))
//        {
//            current_row.push_back(current_cell);
//        }
//    }
//
//    // code for recording time
//    auto start = chrono::high_resolution_clock::now();
//    auto stop = chrono::high_resolution_clock::now();
//    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//     */
//
//    return 0;
//}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "Graph.h"
#include "BTree.h"

using namespace std;
using namespace chrono;


void displayMenu();
bool loadDataset(Graph &graph, BTree &bTree);
void performSearch(Graph &graph, BTree &bTree, bool dataLoaded);
string getValidatedInput(const string &prompt);

int main() {
    Graph graph;
    BTree bTree;
    bool dataLoaded = false; // Flag to check if the dataset has been loaded

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: // Perform Search
                performSearch(graph, bTree, dataLoaded);
                break;
            case 2: // Load Dataset
                dataLoaded = loadDataset(graph, bTree);
                break;
            case 3: // End Program
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    cout << "\n==== Severe Car Accident Query System ====" << endl;
    cout << "1. Perform Search" << endl;
    cout << "2. Load Dataset" << endl;
    cout << "3. End Program" << endl;
    cout << "Enter your choice: ";
}

// Function to load the dataset into both Graph and BTree
bool loadDataset(Graph &graph, BTree &bTree) {
    string filePath = "Severe_Accident_Database.csv"; // Adjust the file path as needed
    try {
        cout << "Loading dataset..." << endl;

        // Load dataset into Graph
        auto startGraph = high_resolution_clock::now();
        graph.load(filePath);
        auto endGraph = high_resolution_clock::now();
        auto graphLoadTime = duration_cast<milliseconds>(endGraph - startGraph).count();

        // Load dataset into BTree
        auto startBTree = high_resolution_clock::now();
        bTree.load(filePath);
        auto endBTree = high_resolution_clock::now();
        auto bTreeLoadTime = duration_cast<milliseconds>(endBTree - startBTree).count();

        // Display loading times
        cout << "\n==== Dataset Loaded Successfully ====" << endl;
        cout << "Graph Load Time: " << graphLoadTime << "ms" << endl;
        cout << "BTree Load Time: " << bTreeLoadTime << "ms" << endl;
        return true;

    } catch (const exception &e) {
        cerr << "Error loading dataset: " << e.what() << endl;
        return false;
    }
}

// Function to perform a search based on user input
void performSearch(Graph &graph, BTree &bTree, bool dataLoaded) {
    if (!dataLoaded) {
        cout << "Dataset not loaded. Please load the dataset first." << endl;
        return;
    }

    // Gather search inputs
    string state = getValidatedInput("Enter State (or 'All' for all states): ");
    string city = getValidatedInput("Enter City (or 'All' for all cities): ");
    string timeOfDay = getValidatedInput("Enter Time of Day (Morning, Night, or 'All'): ");
    string weather = getValidatedInput("Enter Weather Condition (Rainy, Sunny, or 'All'): ");

    // Query Graph
    auto startGraph = high_resolution_clock::now();
    int graphResult = graph.query(state, city, timeOfDay, weather);
    auto endGraph = high_resolution_clock::now();
    auto graphQueryTime = duration_cast<milliseconds>(endGraph - startGraph).count();

    // Query BTree
    auto startBTree = high_resolution_clock::now();
    int bTreeResult = bTree.query(state, city, timeOfDay, weather);
    auto endBTree = high_resolution_clock::now();
    auto bTreeQueryTime = duration_cast<milliseconds>(endBTree - startBTree).count();

    // Display results
    cout << "\n==== Search Results ====" << endl;
    cout << "Conditions: State - " << state << ", City - " << city
         << ", Time of Day - " << timeOfDay << ", Weather - " << weather << endl;
    cout << "Graph Result: " << graphResult << " accidents, Time: " << graphQueryTime << "ms" << endl;
    cout << "BTree Result: " << bTreeResult << " accidents, Time: " << bTreeQueryTime << "ms" << endl;

    cout << "\nReturning to main menu..." << endl;
}

// Helper function
string getValidatedInput(const string &prompt) {
    string input;
    cout << prompt;
    cin.ignore();
    getline(cin, input);
    return input.empty() ? "All" : input; // Default to "All" if no input is provided
}
