#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
The Observer Pattern is a behavioral design pattern where an object (Subject) maintains a list of dependents (Observers) and 
notifies them automatically of any state changes, usually by calling one of their methods.
*/

// 1. Observer interface
class Observer {
public:
    virtual void update(float temperature) = 0;
    virtual ~Observer() {}
};

// 2. Subject interface
class Subject {
public:
    virtual void addObserver(Observer* obs) = 0;
    virtual void removeObserver(Observer* obs) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

// 3. Concrete Subject
class WeatherStation : public Subject {
    float temperature;
    vector<Observer*> observers;

public:
    void addObserver(Observer* obs) override {
        observers.push_back(obs);
    }

    void removeObserver(Observer* obs) override {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void setTemperature(float temp) {
        temperature = temp;
        notifyObservers();  // Notify on change
    }

    void notifyObservers() override {
        for (Observer* obs : observers) {
            obs->update(temperature);
        }
    }
};

// 4. Concrete Observers
class PhoneDisplay : public Observer {
public:
    void update(float temperature) override {
        cout << "[PhoneDisplay] Temperature updated: " << temperature << "°C" << endl;
    }
};

class WindowDisplay : public Observer {
public:
    void update(float temperature) override {
        cout << "[WindowDisplay] Temperature now: " << temperature << "°C" << endl;
    }
};

// 5. Client
int main() {
    WeatherStation station;

    PhoneDisplay phone;
    WindowDisplay window;

    station.addObserver(&phone);
    station.addObserver(&window);

    station.setTemperature(25.5);
    station.setTemperature(30.0);

    station.removeObserver(&phone);
    station.setTemperature(20.0);

    return 0;
}


