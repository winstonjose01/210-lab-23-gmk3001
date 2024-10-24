#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

// Constant values for the size of names and colors arrays, and age range for goats
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20, MIN = 5, MAX = 20;

// F
int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip, int i);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;
    int choice;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list <Goat> goat_gang;
    for (int i = 0; i < (MIN + rand() % (MAX-MIN + 1)); i++){
        goat_gang.push_back(Goat(names[rand() % SZ_NAMES], rand() % (MAX_AGE+1), colors[rand() % SZ_COLORS]));
    }

    while (true){
        choice = main_menu();
        switch (choice){
            case 1: add_goat(goat_gang, names, colors);
                    display_trip (goat_gang);
                break;
            case 2: {
                    if (goat_gang.size() == 0){
                         cout << "There are no goats on the trip. Pls add a goat" << endl;
                         cout << endl;
                         break;
                    }
                    int selection = select_goat(goat_gang);
                    int i = 1;
                    for (auto goat : goat_gang){
                        if (i == selection){
                            cout << "\t---Removing goat " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << " from the trip---" << endl;
                            break;
                        }
                        i++;
                    }
                    delete_goat(goat_gang, selection);
                    display_trip (goat_gang);
            }
                break;
            case 3: display_trip(goat_gang);
                break;
            case 4: cout << endl;
                return 0;
            default: cout << "Invalid input\n";
                break;
            
        }
    }

    return 0;
}

int main_menu(){
    int choice = 0;
    cout << "\n*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";


    cin >> choice;
    return choice;
    }

void add_goat(list<Goat> &trip, string n[], string c[]){
    trip.push_back(Goat(n[rand() % SZ_NAMES], rand() % (MAX_AGE+1), c[rand() % SZ_COLORS]));
}

void display_trip (list<Goat> trip){
    cout << "\tThere are " << trip.size() << " goats on this trip:" << endl;
    int i = 1;
    for (auto goat : trip){
        cout << setw(15) << "[" << i++ << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
    }
}

void delete_goat (list<Goat> &trip, int selection){
    int size_trip = trip.size();
    if (selection == 1)
        trip.pop_front();
    else if (selection == size_trip)
        trip.pop_back();
    else{
        int k = 1;
        for (auto it = trip.begin(); it != trip.end(); ++it){
            if (k == selection){
                trip.erase(it);
                break;
            }
            k++;
        }
    }

}

int select_goat (list <Goat> trip){ 
    int selection;
    display_trip(trip);
    cout << "\tWhich goat is staying behind ? --> ";
    while (true) {
        cin >> selection;
        if (cin.fail() || selection > trip.size() || selection < 1){
            cin.clear();
            cin.ignore();
            cout << "Invalid input: Choose another goat -->";
        }
        else{
            break;
            }
    }
    return selection;
}