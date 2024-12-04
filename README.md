Project_3_COP3530
Hello! Welcome to our Project 3 repository: **Factors of Severe Car Accidents**! This project analyzes factors contributing to severe car accidents using a graph-based data structures in two different representations: an edge list and an adjacency list. 

## Getting Started
To run our code, clone the repository or download it as a `.zip` file through GitHub, then navigate to `main.cpp` (through the command prompt or through an IDE like CLion) and compile/run it!

**Important Note**: Make sure that you download the entire repository, including `CMakeLists.txt` and `Severe_Accident_Database.csv`, as `main.cpp` depends on these files to function correctly.

## The subcategories for Weather_Condition:
Blowing Dust / Windy, Blowing Snow, Blowing Snow / Windy, Clear, Cloudy, Cloudy / Windy, Drifting Snow / Windy, Drizzle, Drizzle and Fog,
Fair, Fair / Windy, Fog, Fog / Windy, Freezing Rain, Freezing Rain / Windy, Funnel Cloud, Hail, Haze, Haze / Windy, Heavy Drizzle, Heavy, Rain, Heavy Rain / Windy, Heavy Snow, Heavy Snow / Windy, Heavy Snow with Thunder, Heavy Thunderstorms and Rain, Heavy Thunderstorms and Snow, Heavy T-Storm, Heavy T-Storm / Windy, Ice Pellets, Light Blowing Snow, Light Drizzle, Light Drizzle / Windy, Light Freezing Drizzle, Light Freezing Fog, Light Freezing Rain, Light Freezing Rain / Windy, Light Ice Pellets, Light Rain, Light Rain / Windy, Light Rain Shower, Light Rain Showers, Light Rain with Thunder, Light Sleet, Light Snow, Light Snow / Windy, Light Snow and Sleet, Light Snow Shower, Light Snow Showers, Light Snow with Thunder, Light Thunderstorms and Rain, Light Thunderstorms and Snow, Mist, Mostly Cloudy, Mostly Cloudy / Windy, N/A, Precipitation, Overcast, Partial Fog, Partly Cloudy, Partly Cloudy / Windy, Patches of Fog, Patches of Fog / Windy, Rain, Rain / Windy, Rain Shower, Rain Showers, Sand / Dust Whirlwinds, Scattered Clouds, Shallow Fog, Showers in the Vicinity, Sleet, Small Hail, Smoke, Smoke / Windy, Snow, Snow / Windy, Snow and Sleet, Squalls, Squalls / Windy, Thunder, Thunder / Windy, Thunder / Wintry Mix, Thunder in the Vicinity, Thunderstorm, Thunderstorms and Rain, Tornado, T-Storm, T-Storm / Windy, Widespread Dust, Wintry Mix, Wintry Mix / Windy

## How to Use the Program
1. **Clone or Download**:
   - Clone the repository:
     ```bash
     git clone https://github.com/jcffarelli/Project_3_COP3530.git
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
     ./Project_3_COP3530
     ```

4. **Follow the Menu**:
   - After running the program, you will be presented with a menu:
     - **1. Perform Search**: Input specific search parameters (state, city, time of day, weather) or choose "All" to view general results. The program will return accident counts and processing times for both graph implementations.
     - **2. Load Dataset**: Load the provided `Severe_Accident_Database.csv` into the program. This step is necessary for searches.
     - **3. End Program**: Safely exit the program.

## Dataset
The program uses a `.csv` file named `Severe_Accident_Database.csv`. This file contains accident data in the following format:
ID,State,City,Sunrise_Sunset,Weather_Condition
For example:
A-3581482,FL,Alachua,Day,Clear

Ensure this file is located in the root directory of the project before running the program.

## Features
- **Menu Interface**:
  - Intuitive and easy-to-follow menu for performing searches, loading the dataset, or exiting the program.
- **Data Structure**:
  - Graph-based data structure with two different implementations for querying accident data.
- **Input Validation**:
  - Accepts user input for state, city, time, and weather conditions. Input is case-insensitive and defaults to "All" if no input is provided.



## Contributors
This project was developed by:
- **Alexander Langner**
- **Joseph Ciffarelli**
- **Khizar Khan**

Thank you for checking out our project! If you encounter any issues or have suggestions for improvement, feel free to reach out.
