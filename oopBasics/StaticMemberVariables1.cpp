#include <iostream>
/* 
static methods of a class are namespace scoped with the class name, but other than that just like functions 
outside the class can be used without being bound to an instance of a class.  
Not being bound to the object a static member variable for example can store a count of objects.
Some other programming languages refer to them as class methods. 
A Class Method(Static Member function) can be used to create a specific type of object. 

A Car factory, a method that generates a specific type of a car using a static method.
 */
class  Car {

public:
  int doors;
  static int carCount; //can store a count of Car objects.
  
  static Car make4DoorCar() {
    return Car(4);
  }

  Car() : doors(1) {
    carCount++;
  }

  Car(int doors) : doors(doors) {
    carCount++;
  }

};

int main() {

    Car c = Car::make4DoorCar();
    std::cout << Car::carCount << '\n';

    Car c1,c2;

    std::cout << Car::carCount << '\n';

}

