#include <iostream>
using namespace std;

enum class Color:int{Red=4, Green, Blue}; //Stores 4,5,6 respectively

void fillColor(Color color){
    switch (color){
        case Color::Red:
            cout << "paint with Red\n"; 
            break;
        case Color::Green:
            cout << "paint with Green\n"; 
            break;
        case Color::Blue:
            cout << "paint with Blue\n";
            break;
    }   
}

enum class TrafficLight:char{Red = 'c', Green, Blue}; //Note: stores ASCII values 'c' = 99,100,101 respectively

void fillTrafficColor(TrafficLight color){
    switch (color){
        case TrafficLight::Red:
            cout << "Turn ON Red\n"; 
            break;
        case TrafficLight::Green:
            cout << "Turn ON Green\n"; 
            break;
        case TrafficLight::Blue:
            cout << "Turn ON Blue\n";
            break;
    }   
}

int main() {
    Color c = Color::Red;
    fillColor(c);
    fillColor(Color::Green);
    fillColor(static_cast<Color>(5));

    fillTrafficColor(TrafficLight::Red);
    char x = static_cast<char>(TrafficLight::Red);


    return 0;
}