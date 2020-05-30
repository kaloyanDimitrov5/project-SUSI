#ifndef SUSIPREDAVANE_STUDENT_H
#define SUSIPREDAVANE_STUDENT_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Disciplini.h"
class Student {
private:
    int numberOfStudents;
    std::string name;
    int facNum;
    int group;
    std::string specialnost;
    int course;
    std::string status;
    double averageGrade;



    static int numOfStudents;
public:
    bool flag=false;
    void plusStudent(){this->numberOfStudents++;}
    int getNumStudents(){return this->numberOfStudents;}
    std::vector<Disciplini>tekushtoZapisani;
    std::vector<Disciplini>polojeniIzpitiDisciplini;
    void addPolojeniDisciplini(Disciplini);
    void addTekushtaDisciplina(Disciplini newD){tekushtoZapisani.push_back(newD);}
    void setFlag(bool flag){this->flag=flag;}
    void setName(std::string name) { this->name = name; }
    void setFacNum(int facNum) { this->facNum = facNum; }
    void setGroup(int group) { this->group=group ; }
    void setSpecialnost(std::string specialnost) { this->specialnost = specialnost; }
    void setCourse(int course) { this->course = course; }
    void setStatus(std::string status) { this->status = status; }
    void setAverageGrade(double averageGrade) { this->averageGrade = averageGrade; }
    std::string getName() { return this->name; }
    void getListTekushtiDisciplini();
    void getListPolojeniIzpiti();
    bool getFlag(){return this->flag;}
    int getFacNum() { return this->facNum; }
    int getGroup() { return this->group; }
    std::string getSpecialnost() { return this->specialnost; }
    int getCourse() { return this->course; }
    std::string getStatus() { return this->status; }
    int getAverageGrade() { return this->averageGrade; }
    Disciplini getDisciplina(int current){return tekushtoZapisani[current-1]; }
    void setAll(std::string, int, int, std::string, int, std::string, double);
    Student(std::string, int, int, std::string, int, std::string);
    Student();
    static int getNumOfStudents() { return numOfStudents; }

};

int Student::numOfStudents = 0;
void Student::setAll(std::string name, int facNum, int group, std::string specialnost, int course, std::string status, double averageGrade)
{
    this->name = name;
    this->facNum = facNum;
    this->group = group;
    this->specialnost = specialnost;
    this->course = course;
    this->status = status;
    this->averageGrade = averageGrade;
    Student::numOfStudents++;
}
Student::Student(std::string name, int facNum, int group, std::string specialnost, int course, std::string status)
{
    this->numberOfStudents++;
    this->flag= false;
    this->name = name;
    this->facNum = facNum;
    this->group = group;
    this->specialnost = specialnost;
    this->course = course;
    this->status = status;
    this->averageGrade=2;
    Student::numOfStudents++;
}
Student::Student()
{
    this->flag=false;
    this->name=name;
    this->facNum = 99999;
    this->group = 0;
    this->specialnost = "***";
    this->course = NULL;
    this->status = "***";
    this->averageGrade = 2;
    Student::numOfStudents++;
}
void Student::getListTekushtiDisciplini()
{
    std::vector<Disciplini>::iterator it;
    int counter=0;
    for(it=tekushtoZapisani.begin();it!=tekushtoZapisani.end();it++)
    {
        std::string disciplina,tip;
        disciplina=tekushtoZapisani[counter].getDisciplineName();
        tip=tekushtoZapisani[counter].getDisciplineType();
        std::cout<<counter+1<<"."<<disciplina<<"-"<<tip<<std::endl;
        counter++;
    }
}
void Student::addPolojeniDisciplini(Disciplini newD)
{
    polojeniIzpitiDisciplini.push_back(newD);
}
void Student::getListPolojeniIzpiti()
{
    std::vector<Disciplini>::iterator it;
    int counter=0;
    for(it=polojeniIzpitiDisciplini.begin();it!=polojeniIzpitiDisciplini.end();it++)
    {
        std::string name,tip;
        int grade;
        name=polojeniIzpitiDisciplini[counter].getDisciplineName();
        tip=polojeniIzpitiDisciplini[counter].getDisciplineType();
        grade=polojeniIzpitiDisciplini[counter].getGrade();
        if (grade>=3) {
            std::cout << counter + 1 << "." << name << "-" << tip << "[" << grade << "]" << std::endl;
            counter++;
        }
    }
}
#endif //SUSIPREDAVANE_STUDENT_H
