/*
 * Question4.cpp
 *
 *  Created on: 02-Sept-2026
 *      Author: user
 */

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Shader {
private:
    string name;
    string type;

public:
    Shader(const string& n, const string& t) : name(n), type(t) {
        cout << "[Shader Compiled] " << name << " (" << type << ")" << endl;
    }

    ~Shader() {
        cout << "[Shader Destroyed] " << name << endl;
    }

    void display() const {
        cout << "Shader: " << name << " (" << type << ")" << endl;
    }
};

int main4() {

    auto shader = make_shared<Shader>("main_vert", "vertex");
    cout << "Ref count: " << shader.use_count() << endl;

    {
        auto rendererRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;

        auto editorRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;
    }

    cout << "Ref count: " << shader.use_count() << endl;

    return 0;
}



