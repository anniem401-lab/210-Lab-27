// COMSC-210 | Lab 27 | Annie Morales
// IDE used: Visual Studio Code

// Milestone 1: Done
// Bring the demo code for std::map that's posted in module 27 
// into a new Github repository project.

#include <iostream> // for std::cout, std::endl
#include <map> // for std::map
#include <vector> // for std::vector
#include <string> // for string
#include <tuple> // for std::tuple
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
    map<string, tuple<int, string, string>> villagerData; // map of villager data storing friendship level, species, and catchphrase

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements

    // assigning values to tuple using make_tuple()
    villagerData["Audie"] = make_tuple( 5, "Wolf", "foxtrot");
    villagerData["Raymond"] = make_tuple( 8, "Cat", "crisp");
    villagerData.insert({"Marshal", {3, "Squirrel", "sulky"}});

    // access the map using a range-based for loop
    cout << endl << "Villager Data (range-based for loop):" << endl;
    cout << "-------------------------------------" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": "
            << get<0>(pair.second) << ", "
            << get<1>(pair.second) << ", "
            << get<2>(pair.second) << endl;
    }

    // access the map using iterators
    cout << "\nVillagers Data (iterators):" << endl;
    cout << "-------------------------------------" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin(); 
                                               it != villagerData.end(); ++it) {
        cout << it->first << ": "
            << get<0>(it->second) << ", "
            << get<1>(it->second) << ", "
            << get<2>(it->second) << endl;
    }

    // delete an element
    villagerData.erase("Raymond");
    cout << "\nRaymond has been removed from the villager data." << endl;

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s villager data: " << endl;

    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl << endl;

    return 0;
}