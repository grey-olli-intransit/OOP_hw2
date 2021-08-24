#include <iostream>
#include <string>
// Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
// Определить методы переназначения имени, изменения возраста и веса. 
// Создать производный класс Student (студент), имеющий поле года обучения. 
// Определить методы переназначения и увеличения этого значения. 
// Создать счетчик количества созданных студентов. 
// В функции main() создать несколько студентов. По запросу вывести определенного человека.
enum Gender{MALE,FEMALE};

class Person{
  std::string name;
  int age;
  Gender gender;
  double weight;
    public:
        Person(std::string n,int a,Gender g,double w):name(n),age(a),gender(g),weight(w) {}
	void setAge(int a) {age=a;}
        int getAge() const {return age;}
	void setName(std::string n) {name=n;}
	std::string getName() const {return name;}
	void setGender(Gender g) {gender=g;}
	Gender getGender() const {return gender;}
	void setWeight(double w) {weight=w;}
	double getWeight() const {return weight;}
};

class Student:public Person{
    int learningYear;
    public:
        static int studentNumber;
        Student(std::string n,int a,Gender g,double w,int ly): Person(n,a,g,w), learningYear(ly) {studentNumber++;}
	~Student() {studentNumber--;}
        void setLYear(int ly) {learningYear=ly;}  
        int getLYear() const {return learningYear;}
	int increaseLYear() {return ++learningYear;}
};

int Student::studentNumber=0;

int main(int argc, char ** argv) {
    std::string name;
    Student first("Alexey",18,MALE,70.5,1), 
	    second("Sergey",19,MALE,75.5,2),
	    third("Anna",20,FEMALE,60.0,3);
    std::cout << "Есть " << third.studentNumber <<  " студентов: \n" ;
    for(Person * pPerson : {&first,&second,&third}) {
      printf("%s\n", pPerson->getName().c_str());
    }
    std::cout << std::endl << "Введите имя студента о котором хотите узнать больше: ";
    std::cin >> name;
    for(Person * pPerson : {&first,&second,&third}) {
      if(pPerson->getName() == name) {
	 std::cout << pPerson->getName() << ":\n";
         std::cout << " Age: " << pPerson->getAge() << "\n" ;
         std::cout << " Gender: ";
	 printf("%s",pPerson->getGender() ? "Female" : "Male");
         std::cout << "\n" ;
         std::cout << " Weight: " << pPerson->getWeight()  << "\n" ;
         std::cout << " Years learning: " << ((Student *) pPerson)->getLYear() << "\n" ;
      }
    }

    return 0;	

}
