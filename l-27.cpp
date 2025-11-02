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

// Milestone 2: Done
// Currently, the std::map in that code contains a key (here, a string representing the villager's name)
// and a value (here, a string vector representing their three favorite colors).
// Change the data we're storing to friendship level (0-10), the villager's species (string), and the villager's catchphrase (string).
// Change the data structure held in the std::map's value from a vector to a std::tuple.
// Convert the rest of the code to support the new std::tuple.
// Demo this code's success with short driver code.

// Milestone 3:
// Make a program menu-driven that will support this menu:
// 1. Increase Friendship
// 2. Decrease Friendship
// 3. Search for Villager
// 4. Exit
// The increase/decrease friendship can just add a point each time, 
// making sure that the level is never negative.
// After each operation is complete, output the std::map's contents of 
// villager data in this format (you can improve on the format if you wish).

// Function Prototype
int main_menu (); // Main menu function that loops in main.
void display_villagers(); // Displays list of villagers.
int select_villager(); // Allows user to select a villager.
void increase_friendship(map<string, tuple<int, string, string>> &villagerData); // Increases friendship by 1, Choice 1.
void decrease_friendship(map<string, tuple<int, string, string>> &villagerData); // Decreases friendship by 1, Choice 2.
void search_villager(map<string, tuple<int, string, string>> villagerData); // Searches for villager, Choice 3.

int main(){
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

    /*

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
        cout << "\nFound " << searchKey << " in villager data: " << endl;

        for (auto data : villagerData) {
        cout 
            << get<0>(data.second) << ", "
            << get<1>(data.second) << ", "
            << get<2>(data.second) << endl;
        }
    } else
        cout << endl << searchKey << " not found." << endl;

     // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl << endl;

    */

    while (true){
        int choice = main_menu();

        switch(choice){
            case 1: cout << "You chose to increase friendship." << endl; increase_friendship(villagerData);
                    break;
            case 2: cout << "You chose to decrease friendship." << endl; decrease_friendship(villagerData);
                    break;
            case 3: cout << "You chose to search for Villager." << endl;
                    break;
            case 4: cout << "You chose to exit, you have left the program. Goodbye!" << endl << endl;
                    return 0;
        }
    }

    return 0;
}

// main_menu outputs a menu allowing the user to choose from four options.
// arguments: none.
// returns: user choice from number input.
int main_menu (){
    cout << endl << "** Main Menu **" << endl; 
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;

    int choice;
    cout << "Enter choice -> ";
    cin >> choice;
    while (choice < 1 || choice > 4){
        cout << "Invalid choice. Please enter 1, 2, 3, or 4: ";
        cin >> choice;
    }
    return choice;
}

// display_villagers displays a list of villagers.
// arguments: map of villager data.
// returns: nothing.
void display_villagers(map<string, tuple<int, string, string>> villagerData){
    if (villagerData.empty()){
        cout << "There are no villagers.\n";
        return;
    }
    int i = 1;
    for (auto pair : villagerData) {
        cout << pair.first << ": "
            << get<0>(pair.second) << ", "
            << get<1>(pair.second) << ", "
            << get<2>(pair.second) << endl;
    }
}

// select_villager allows user to select a villager.
// arguments: map of villager data.
// returns: user int choice.
int select_villager(map<string, tuple<int, string, string>> villagerData){
    int choice;
    cout << "Select a villager:\n";
    display_villagers(villagerData);
    cout << "Choice -> ";
    cin >> choice;
    while (choice < 1 || choice > villagerData.size()){
        cout << "Invalid choice. Please enter the number of a villager from the display: ";
        cin >> choice;
    }
    return choice;
}

// increase_friendship allows the user to increase friendship of a villager by one point.
// arguments: map of villager data.
// returns: nothing.
void increase_friendship(map<string, tuple<int, string, string>> &villagerData){
    string name;
    int friendshipLvl;
    cout << endl << "Select a villager to increase friendship by 1 (Enter a villager name):" << endl;
    cout << "-------------------------------------" << endl;
    display_villagers(villagerData);
    cout << "Name -> ";
    cin >> name;
    cin.ignore(1000, 10);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        friendshipLvl = get<0>(it->second);

        if (friendshipLvl < 10){
            friendshipLvl++;
            cout << "Friendship with " << name << " increased to " << friendshipLvl << "." << endl;
        }
        else{
            cout << name << " is already at max friendship (10).";
        }
    } else
        cout << endl << name << " not found." << endl;
}

// decrease_friendship allows the user to decrease friendship level of a villager by one point.
// arguments: map of villager data.
// returns: nothing.
void decrease_friendship(map<string, tuple<int, string, string>> &villagerData){
    string name;
    int friendshipLvl;
    cout << endl << "Select a villager to decrease friendship by 1 (Enter a villager name):\n";
    cout << "-------------------------------------" << endl;
    display_villagers(villagerData);
    cout << "Name -> ";
    cin >> name;
    cin.ignore(1000, 10);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        friendshipLvl = get<0>(it->second);

        if (friendshipLvl < 10){
            friendshipLvl--;
            cout << "Friendship with " << name << " decreased to " << friendshipLvl << "." << endl;
        }
        else{
            cout << name << " is already at minimum friendship (0)." << endl;
        }
    } else{
        cout << name << " not found." << endl;
    }    
}

// search_villager allows the user to search for a villager.
// argument: map of vilager data.
// returns: nothing.
void search_villager(map<string, tuple<int, string, string>> villagerData){
    string name;
    cout << endl << "Select a villager to search for (Enter a villager name):\n";
    cout << "-------------------------------------" << endl;
    display_villagers(villagerData);
    cout << "Name -> ";
    cin >> name;
    cin.ignore(1000, 10);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << name << " in villager data: " << endl;

        for (auto data : villagerData) {
        cout 
            << get<0>(data.second) << ", "
            << get<1>(data.second) << ", "
            << get<2>(data.second) << endl;
        }
    } else
        cout << endl << name << " not found." << endl;
}
