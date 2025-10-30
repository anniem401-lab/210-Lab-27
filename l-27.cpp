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
    villagerData["Audie"] = {"5", "Animal", "Sick!"};
    villagerData["Raymond"] = {"8", "Cat", "Cool beans"};
    villagerData.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}