#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
The Flyweight Pattern is a structural design pattern used to minimize memory usage by sharing common state 
across many similar objects, rather than storing the same data in each one.
*/

// 1. Flyweight
class Character {
    char symbol;  // intrinsic state
public:
    Character(char sym) : symbol(sym) {}

    void display(int row, int col, string color) {
        // extrinsic state passed in
        cout << "Char: '" << symbol << "' at (" << row << "," << col << ")"
             << " with color: " << color << endl;
    }
};

// 2. Flyweight Factory
class CharacterFactory {
    unordered_map<char, Character*> characters;
public:
    ~CharacterFactory() {
        for (auto& p : characters)
            delete p.second;
    }

    Character* getCharacter(char symbol) {
        if (characters.find(symbol) == characters.end()) {
            characters[symbol] = new Character(symbol);
        }
        return characters[symbol];
    }
};

// 3. Client
int main() {
    CharacterFactory factory;

    Character* c1 = factory.getCharacter('A');
    Character* c2 = factory.getCharacter('B');
    Character* c3 = factory.getCharacter('A');  // same object as c1

    c1->display(1, 1, "Red");
    c2->display(2, 2, "Blue");
    c3->display(3, 3, "Green");  // reused 'A' object

    return 0;
}
