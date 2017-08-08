#include "animal.h"
#include "cat.h"
#include "dog.h"
#include <iostream>

void report(Animal &animal){
    std::cout<<animal.getName() << " says " << animal.speak() << std::endl;
}

int main(){
    Cat cat("Fred");
    Dog dog("Gardo");
    report(cat);
    report(dog);

    Cat fred("Fred"), misty("Misty"), zeke("Zeke");
    Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");

    Animal *animals[] = {&fred, &misty, &zeke, &garbo, &pooky, &truffle};
    for(int i = 0; i < 6; i++){
        report(*(animals[i]));
    }
}
