/*
 * Question3.cpp
 *
 *  Created on: 02-Sept-2026
 *      Author: user
 */

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Texture {
private:
    string name;
    int width, height;

public:
    Texture(const string& n, int w, int h) : name(n), width(w), height(h) {
        cout  << name << endl;
    }

    ~Texture() {
        cout  << name << endl;
    }

    void display() const {
        cout << "Texture: " << name << " (" << width << "x" << height << ")" << endl;
    }
};

int main3() {

    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);
    tex1->display();


    // unique_ptr<Texture> tex2 = tex1;
    // ❌ Error: unique_ptr cannot be copied, only moved.


    unique_ptr<Texture> tex2 = move(tex1);
    cout << "tex1 is null: " << (tex1 == nullptr ? "YES" : "NO") << endl;


    tex2->display();


    return 0;
}



