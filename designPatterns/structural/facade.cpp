#include <iostream>
using namespace std;

/*The Facade Pattern is a structural design pattern that provides a simplified interface to a 
larger system of classes, libraries, or complex subsystems.*/

// Subsystems
class DVDPlayer {
public:
    void on() { cout << "DVD Player ON\n"; }
    void play(string movie) { cout << "Playing movie: " << movie << endl; }
    void off() { cout << "DVD Player OFF\n"; }
};

class Projector {
public:
    void on() { cout << "Projector ON\n"; }
    void setWideScreenMode() { cout << "Set to widescreen mode\n"; }
    void off() { cout << "Projector OFF\n"; }
};

class Amplifier {
public:
    void on() { cout << "Amplifier ON\n"; }
    void setVolume(int level) { cout << "Volume set to " << level << endl; }
    void off() { cout << "Amplifier OFF\n"; }
};

class Lights {
public:
    void dim() { cout << "Lights dimmed\n"; }
    void on() { cout << "Lights ON\n"; }
};

// Facade
class HomeTheaterFacade {
    DVDPlayer* dvd;
    Projector* projector;
    Amplifier* amp;
    Lights* lights;
public:
    HomeTheaterFacade(DVDPlayer* d, Projector* p, Amplifier* a, Lights* l)
        : dvd(d), projector(p), amp(a), lights(l) {}

    void watchMovie(string movie) {
        cout << "\nGet ready to watch a movie...\n";
        lights->dim();
        projector->on();
        projector->setWideScreenMode();
        amp->on();
        amp->setVolume(7);
        dvd->on();
        dvd->play(movie);
    }

    void endMovie() {
        cout << "\nShutting movie theater down...\n";
        dvd->off();
        amp->off();
        projector->off();
        lights->on();
    }
};

// Client
int main() {
    DVDPlayer dvd;
    Projector projector;
    Amplifier amp;
    Lights lights;

    HomeTheaterFacade theater(&dvd, &projector, &amp, &lights);

    theater.watchMovie("Inception");
    theater.endMovie();

    return 0;
}
