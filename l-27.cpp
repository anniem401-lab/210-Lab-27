// COMSC-210 | Lab 27 | Annie Morales
// IDE used: Visual Studio Code

// Milestone 1: Done
// Bring the demo code for std::map that's posted in module 27 
// into a new Github repository project.

#include <iostream> // for std::cout, std::endl
#include <map> // for std::map
#include <vector> // for std::vector
using namespace std;

// Milestone 2:
// Currently, the std::map in that code contains a key (here, a string representing the villager's name)
// and a value (here, a string vector representing their three favorite colors).

// Change the data we're storing to friendship level (0-10), the villager's species (string), and the villager's catchphrase (string).

// Change the data structure held in the std::map's value from a vector to a std::tuple.

// Convert the rest of the code to support the new std::tuple.

// Demo this code's success with short driver code.

int main() {
    // declarations
    map<string, vector<string>> villagerData; // map of villager data storing friendship level, species, and catchphrase

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerData["Audie"] = {"5,", "Wolf,", "foxtrot"};
    villagerData["Raymond"] = {"8,", "Cat,", "crisp"};
    villagerData.insert({"Marshal", {"3,", "Squirrel,", "sulky"}});

    // access the map using a range-based for loop
    cout << endl << "Villager Data (range-based for loop):" << endl;
    cout << "-------------------------------------" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers Data (iterators):" << endl;
    cout << "-------------------------------------" << endl;
    for (map<string, vector<string>>::iterator it = villagerData.begin(); 
                                               it != villagerData.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerData.erase("Raymond");
    cout << "\nRaymond has been removed from the villager data." << endl;

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s villager data: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl << endl;

    return 0;
}