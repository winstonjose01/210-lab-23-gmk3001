#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20, MIN = 5, MAX = 20;

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
    for (int i = 0; i < (MIN + rand() % MAX-MIN + 1); i++){
        goat_gang.push_back(Goat(names[rand() % SZ_NAMES], rand() % (MAX_AGE+1), colors[rand() % SZ_COLORS]));
    }

    while (true){
        choice = main_menu();
        switch (choice){
            case 1: add_goat(goat_gang, names, colors);
                    display_trip (goat_gang);
                break;
            case 2: int selection = select_goat(goat_gang);
                    delete_goat(goat_gang, selection);
                    display_trip (goat_gang);
                break;
            case 3: display_trip(goat_gang);
                break;
            case 4:
                return 0;
            
        }
    }

    return 0;
}

int main_menu(){
    int choice = 0;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
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
    if i 
    for (auto goat : trip){
        int i = 1;
        cout << "\t[" << i++ << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
    }
}

void delete_goat (list<Goat> &trip, int selection){
    int i = 1;
    for (auto goat : trip){
        cout << "\t[" << i << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
    }

}

int select_goat (list <Goat> trip){ 
    int selection;
    display_trip(trip);
    cout << "Which goat is staying behind ? --> ";
    cin >> selection;
}