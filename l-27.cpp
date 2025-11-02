// COMSC-210 | Lab 27 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream> // for std::cout, std::endl
#include <map> // for std::map
#include <vector> // for std::vector
#include <string> // for string
#include <tuple> // for std::tuple
using namespace std;

// Function Prototype
int main_menu (); // Main menu function that loops in main.
void display_villagers(map<string, tuple<int, string, string>> villagerData); // Displays list of villagers.
string select_villager(map<string, tuple<int, string, string>> villagerData); // Allows user to select a villager.
void add_villager(map<string, tuple<int, string, string>> &villagerData); // Allows usesr to add a villager. Choice 1.
void delete_villager(map<string, tuple<int, string, string>> &villagerData); // Allows user to delete a villager. Choice 2.
void increase_friendship(map<string, tuple<int, string, string>> &villagerData); // Increases friendship by 1, Choice 3.
void decrease_friendship(map<string, tuple<int, string, string>> &villagerData); // Decreases friendship by 1, Choice 4.
void search_villager(map<string, tuple<int, string, string>> villagerData); // Searches for villager, Choice 5.

int main(){
    // declarations
    map<string, tuple<int, string, string>> villagerData; // map of villager data storing friendship level, species, and catchphrase.

    // assigning values to tuple using make_tuple()
    villagerData["Audie"] = make_tuple( 5, "Wolf", "foxtrot");
    villagerData["Raymond"] = make_tuple( 8, "Cat", "crisp");
    villagerData.insert({"Marshal", {3, "Squirrel", "sulky"}});

    // access the map using a range-based for loop
    cout << endl << "Villager Data:" << endl;
    cout << "-------------------------------------" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": "
            << "[" << get<0>(pair.second) << ", "
            << get<1>(pair.second) << ", "
            << get<2>(pair.second) << "]" << endl;
    }

    while (true){
        int choice = main_menu();
        switch(choice){
            case 1: cout << "You chose to add a villager." << endl; add_villager(villagerData);
                    break;
            case 2: cout << "You chose to delete a villager." << endl; delete_villager(villagerData);
                    break;
            case 3: cout << "You chose to increase friendship." << endl; increase_friendship(villagerData);
                    break;
            case 4: cout << "You chose to decrease friendship." << endl; decrease_friendship(villagerData);
                    break;
            case 5: cout << "You chose to search for Villager." << endl; search_villager(villagerData);
                    break;
            case 6: cout << "You chose to exit, you have left the program. Goodbye!" << endl << endl;
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
    cout << "1. Add villager" << endl;
    cout << "2. Delete villager" << endl; 
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    int choice;
    cout << "Enter choice -> ";
    cin >> choice;
    while (choice < 1 || choice > 6){
        cout << "Invalid choice. Please enter 1-5: ";
        cin >> choice;
    }
    return choice;
}

// display_villagers displays a list of villagers.
// arguments: map of villager data.
// returns: nothing.
void display_villagers(map<string, tuple<int, string, string>> villagerData){
    if (villagerData.empty()){
        cout << "There are no villagers available to display.\n";
        return;
    }
    int i = 1;
    for (auto pair : villagerData) {
        cout << pair.first << ": "
            << "[" << get<0>(pair.second) << ", "
            << get<1>(pair.second) << ", "
            << get<2>(pair.second) << "]" << endl;
    }
}

// select_villager allows user to select a villager.
// arguments: map of villager data.
// returns: name of villager.
string select_villager(map<string, tuple<int, string, string>> villagerData){
    if (villagerData.empty()){
        cout << "There are no villagers to select.\n";
        return;
    }
    string name;
    cout << endl << "Select a villager:\n";
    cout << "-------------------------------------" << endl;
    display_villagers(villagerData);
    cout << "Name -> ";
    cin >> name;
    return name;
}

// add_villager allows user to add a villager after filling out the info.
// arguments: map of villager data.
// returns: nothing.
void add_villager(map<string, tuple<int, string, string>> &villagerData){
    string name, species, phrase;
    int friendshipLvl;
    cout << endl << "Enter the information of the villager you want to add:" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Villager name: "; cin >> name;
    cin.ignore(1000, 10);
    cout << "Friendship level: "; cin >> friendshipLvl;
    cin.ignore(1000, 10);
    cout << "Species: "; cin >> species;
    cin.ignore(1000, 10);
    cout << "Catchphrase: "; getline(cin, phrase);
    villagerData[name] = make_tuple(friendshipLvl, species, phrase);
    cout << name << " has been added." << endl;
}

// delete_villager deletes a villager.
// arguments: map of villager data.
// returns: nothing.
void delete_villager(map<string, tuple<int, string, string>> &villagerData){
    if (villagerData.empty()){
        cout << "There are no villagers to delete.\n";
        return;
    }
    string name = select_villager(villagerData);
    auto it = villagerData.find(name);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        villagerData.erase(name);
        cout << name << " has been deleted from the villager data." << endl;
    } else
        cout << endl << name << " not found." << endl;
}

// increase_friendship allows the user to increase friendship of a villager by one point.
// arguments: map of villager data.
// returns: nothing.
void increase_friendship(map<string, tuple<int, string, string>> &villagerData){
    if (villagerData.empty()){
        cout << "There are no villagers.\n";
        return;
    }
    string name;
    cout << endl << "Select a villager to increase friendship by 1 (Enter a villager name):" << endl;
    cout << "-------------------------------------" << endl;
    display_villagers(villagerData);
    cout << "Name -> "; cin >> name;
    cin.ignore(1000, 10);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        int &friendshipLvl = get<0>(it->second);

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
    if (villagerData.empty()){
        cout << "There are no villagers.\n";
        return;
    }
    string name;
    cout << endl << "Select a villager to decrease friendship by 1 (Enter a villager name):\n";
    cout << "-------------------------------------" << endl;
    display_villagers(villagerData);
    cout << "Name -> "; cin >> name;
    cin.ignore(1000, 10);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        int &friendshipLvl = get<0>(it->second);

        if (friendshipLvl > 0){
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
    if (villagerData.empty()){
        cout << "There are no villagers to search for.\n";
        return;
    }
    string name;
    cout << endl << "Select a villager to search for (Enter a villager name):\n";
    cout << "-------------------------------------" << endl;
    display_villagers(villagerData);
    cout << "Name -> "; cin >> name;
    cin.ignore(1000, 10);

    auto it = villagerData.find(name);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << name << " in villager data: "
            << "[" << get<0>(it->second) << ", "
            << get<1>(it->second) << ", "
            << get<2>(it->second) << "]" << endl;
        
    } else
        cout << endl << name << " not found." << endl;
}