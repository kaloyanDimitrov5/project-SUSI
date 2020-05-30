#ifndef SUSIPREDAVANE_DISCIPLINI_H
#define SUSIPREDAVANE_DISCIPLINI_H
#include"Student.h"
class Disciplini {
private:
    std::string name;
    std::string type;
    int grade;
public:
    void setGrade(int grade){this->grade=grade;}
    void setDisciplineName(std::string name){this->name=name;}
    void setType(std::string type){this->type=type;}
    std::string getDisciplineName(){return this->name;}
    std::string getDisciplineType(){return this->type;}
    int getGrade(){return this->grade;}
    Disciplini();
    Disciplini(std::string,std::string);
};
Disciplini::Disciplini()
{
    this->name="***";
    this->type="***";
    this->grade=0;
}
Disciplini::Disciplini(std::string name,std::string type)
{
    this->name=name;
    this->type=type;
}
#endif //SUSIPREDAVANE_DISCIPLINI_H
