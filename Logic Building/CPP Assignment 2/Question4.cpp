#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


int level = 1;

class Entity {
private:
    string name;
    int health;
    int level;
    string type;

public:
    Entity& setName(const string& n) {
        this->name = n;
        return *this;
    }
    Entity& setHealth(int h) {
        this->health = h;
        return *this;
    }
    Entity& setLevel(int l) {
        this->level = l;
        return *this;
    }
    Entity& setType(const string& t) {
        this->type = t;
        return *this;
    }

    string getName() const { return name; }
    int getHealth() const { return health; }
    int getLevel() const { return level; }
    string getType() const { return type; }

    void displayInfo() const {
        cout << "Entity: " << name << endl;
        cout << "Type: " << type << endl ;
        cout  << " Health: " << health << endl ;
        cout  << " Level: " << level << endl;
    }
};

// ----------------------------
namespace Physics {
    double clamp(double val, double min, double max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }
    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}

namespace GameMath {
    int clamp(int val, int min, int max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }
    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}

// ----------------------------------
namespace Engine {
    namespace Audio {
        void playSound(const string& name) {
            cout << "Playing: " << name << endl;
        }
    }
}

//----------------------------------
int main() {
    srand(time(0));


    Entity player, enemy, item;
    player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
    enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

    cout << "--- Entities ---"<< endl;
    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();

  cout << "-----------------------"<< endl ;
    cout << "--- Namespaces ---";
    cout << "Physics clamp(12.5, 0, 10): " << Physics::clamp(12.5, 0, 10) << endl;
    cout << "GameMath clamp(15, 0, 10): " << GameMath::clamp(15, 0, 10) << endl;
    cout << "Physics lerp(0, 100, 0.3): " << Physics::lerp(0, 100, 0.3) << endl;
    cout << "GameMath lerp(10, 20, 0.5): " << GameMath::lerp(10, 20, 0.5) << endl;


    int R, C;
    cout << "\nEnter rows and columns for game map: ";
    cin >> R >> C;

    int** map = new int*[R];
    for (int i = 0; i < R; i++) {
        map[i] = new int[C];
    }

    int counts[5] = {0};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] = rand() % 5; // tile type
            counts[map[i][j]]++;
        }
    }
    cout << "-----------------------"<< endl ;

    cout << "----- GAME MAP (" << R << " x " << C << ") =====\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLegend: 0=Grass  1=Water  2=Mountain  3=Forest  4=Dungeon\n";
    cout << "\nTile Count:\n";
    cout << "  Grass   : " << counts[0] << endl;
    cout << "  Water   : " << counts[1] << endl;
    cout << "  Mountain: " << counts[2] << endl;
    cout << "  Forest  : " << counts[3] << endl;
    cout << "  Dungeon : " << counts[4] << endl;

    for (int i = 0; i < R; i++) {
        delete[] map[i];
    }
    delete[] map;


    cout << "-----------------------"<< endl ;
    int level = 10;
    cout << "\n--- Scope Resolution ---\n";
    cout << "Global level (difficulty): " << ::level << endl;
    cout << "Local level (player): " << level << endl;

    Engine::Audio::playSound("sword_clash");
    Engine::Audio::playSound("victory_theme");

    return 0;
}
