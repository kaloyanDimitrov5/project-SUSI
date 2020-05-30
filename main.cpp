#include <iostream>
#include "menuTerminal.h"

int main() {
    Student gosho("Gosho Ivanov",123,1,"KN",1,"enrolled");
    Student gosho2("Gosho Ivanov2",1234,1,"KN",1,"enrolled");
    Specialnosti kn ("KN");
    Specialnosti si ("SI");
    Disciplini nova("OOP","ZAD");
    specialnosti.push_back(kn);
    specialnosti.push_back(si);
    allStudents.push_back(gosho);
    allStudents.push_back(gosho2);
    kn.addDiscipline(nova,1);
    runMenu();


    return 0;
}
