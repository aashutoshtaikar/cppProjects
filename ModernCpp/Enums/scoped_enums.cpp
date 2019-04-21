#include <iostream>
using namespace std;


//enum use restricted range of values, undefined integral types
enum class Color{Red, Green, Blue};   //global DS/BSS

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

//enum TrafficLight{Red, Green, Blue};  //global DS/BSS
/* 
    Problem: Above line has compilation errors because of (name clashes)same enum objects Red, Green, Blue declared globally in BSS
    Solution: Scoped enum 
    Advantages: No name clashes, enum class Not implicitly convertable to int
*/
enum class TrafficLight{Red, Green, Blue}; 

void fillTrafficColor(TrafficLight color){
    switch (color)
    {
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
    fillColor(static_cast<Color>(2));
    fillTrafficColor(TrafficLight::Red);
    
    //enum to int
    int x = static_cast<int>(TrafficLight::Red);

    //int to enum
    Color c = static_cast<Color>(2);

  
    return 0;
}