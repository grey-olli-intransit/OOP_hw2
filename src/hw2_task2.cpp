#include <iostream>
#include <string>

// Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
//  У Fruit есть две переменные-члена: name (имя) и color (цвет). 
//  Добавить новый класс GrannySmith, который наследует класс Apple.
class Fruit {
  protected: 
      std::string name;
      std::string color;
  public:
      Fruit(std::string n, std::string c): name(n), color(c) {}
      std::string getName() const {return name;}
      void setName(std::string n) {name=n;}
      std::string getColor() const {return color;}
      void setColor(std::string c) {color=c;}
};

class Apple: public Fruit {
    public:
        Apple(std::string color): Fruit("apple", color) {}
        Apple(std::string name,std::string color): Fruit(name + " apple", color) {}
};

class Banana: public Fruit {
    public:
	Banana(): Fruit("banana", "yellow") {}
};

class GrannySmith : public Apple {
    public:
	    GrannySmith():Apple("Granny Smith","green"){}
};

int main(int argc, char ** argv) {

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;

}
