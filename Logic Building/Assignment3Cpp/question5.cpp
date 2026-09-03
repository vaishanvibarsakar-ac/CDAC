/*
 * question5.cpp
 *
 *  Created on: 02-Sept-2026
 *      Author: user
 */


#include <iostream>
#include <memory>
#include <string>
using namespace std;

class AudioClip {
private:
    string name;
    double duration;

public:
    AudioClip(const string& n, double d) : name(n), duration(d) {
        cout << "[AudioClip Loaded] " << name << endl;
    }

    ~AudioClip() {
        cout << "[AudioClip Released] " << name << endl;
    }

    string getName() const {
        return name;
    }

    void play() const {
        cout << "Playing clip: " << name << " (" << duration << "s)" << endl;
    }
};

int main5() {

    auto audio = make_shared<AudioClip>("explosion", 3.5);


    weak_ptr<AudioClip> observer = audio;


    if (auto clip = observer.lock()) {
        cout << "Clip alive: " << clip->getName() << endl;
        clip->play();
    }


    audio.reset();


    if (observer.expired()) {
        cout << "Clip already unloaded." << endl;
    }

    return 0;
}


