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

    /*
    // code for recording time
    auto start = chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
     */

    return 0;
}
