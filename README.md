Project_3_COP3530
Hello! Welcome to our Project 3 repository: **Factors of Severe Car Accidents**! This project analyzes factors contributing to severe car accidents using graph-based and tree-based data structures. 

## Getting Started
To run our code, clone the repository or download it as a `.zip` file through GitHub, then navigate to `main.cpp` (through the command prompt or through an IDE like CLion) and compile/run it!

**Important Note**: Make sure that you download the entire repository, including `CMakeLists.txt` and `Severe_Accident_Database.csv`, as `main.cpp` depends on these files to function correctly.

## How to Use the Program
1. **Clone or Download**:
   - Clone the repository:
     ```bash
     git clone https://github.com/your-repo-url
     ```
   - Or download the repository as a `.zip` file and extract it.

2. **Compile the Program**:
   - If using the command line, navigate to the project folder and run:
     ```bash
     mkdir build
     cd build
     cmake ..
     cmake --build .
     ```
   - If using an IDE like CLion, open the project, ensure `CMakeLists.txt` is detected, and click "Build".

3. **Run the Program**:
   - Execute the compiled binary:
     ```bash
     ./Project3_COP3530
     ```

4. **Follow the Menu**:
   - After running the program, you will be presented with a menu:
     - **1. Perform Search**: Input specific search parameters (state, city, time of day, weather) or choose "all" to view general results. The program will return accident counts and processing times for both graph and tree-based queries.
     - **2. Load Dataset**: Load the provided `Severe_Accident_Database.csv` into the program. This step is necessary for searches.
     - **3. End Program**: Safely exit the program.

## Dataset
The program uses a CSV file named `Severe_Accident_Database.csv`. This file contains accident data in the following format:
State,City,TimeOfDay,Weather,AccidentCount
For example:
Florida,Miami,Morning,Sunny,10 California,Los Angeles,Night,Rainy,7

Ensure this file is located in the root directory of the project before running the program.

## Features
- **Menu Interface**:
  - Intuitive and easy-to-follow menu for performing searches, loading the dataset, or exiting the program.
- **Data Structures**:
  - Graph-based and tree-based data structures implemented for querying accident data.
- **Input Validation**:
  - Accepts user input for state, city, time, and weather conditions. Input is case-insensitive and defaults to "all" if no input is provided.

## Examples of Use

### Example 1: Perform a Search
- Input: State: Florida City: Miami Time of Day: All Weather: Sunny
- Output:==== Search Results ==== Conditions: State - florida, City - miami, Time of Day - all, Weather - sunny Graph Result: 10 accidents, Time: 5ms BTree Result: 10 accidents, Time: 7ms

### Example 2: Load Dataset
- Output: Loading dataset... Dataset loaded!

### Example 3: Invalid Input
- Input: `4` at the menu.
- Output: Invalid choice. Please try again.

## File Structure
Project_3_COP3530/ ├── main.cpp # Main program ├── Graph.h / Graph.cpp # Graph implementation ├── BTree.h / BTree.cpp # Tree implementation ├── Severe_Accident_Database.csv # Dataset file ├── CMakeLists.txt # Build configuration └── README.md # This file



## Contributors
This project was developed by:
- **Alexander Langner**
- **Joseph Ciffarelli**
- **Khizar Khan**

Thank you for checking out our project! If you encounter any issues or have suggestions for improvement, feel free to reach out.
"""

# Saving to a file
file_path = "/mnt/data/README.md"
with open(file_path, "w") as f:
    f.write(readme_content)

file_path


