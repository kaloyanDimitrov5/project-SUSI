#ifndef SUSIPREDAVANE_SPECIALNOSTI_H
#define SUSIPREDAVANE_SPECIALNOSTI_H
#include "Disciplini.h"
std::vector<Disciplini> ZaduljitelniIzpiti;

class Specialnosti
{
private:

    std::string specialnost;

    std::vector<Disciplini> listDisciplini1;
    std::vector<Disciplini> listDisciplini2;
    std::vector<Disciplini> listDisciplini3;
    std::vector<Disciplini> listDisciplini4;
public:
    void addDiscipline(Disciplini&,int);
    void setSpecialnostName(std::string name){this->specialnost=name;}
    std::string getSpecialnostName(){return this->specialnost;}
    void getListDisciplini(int);
    void getZaduljitelniDisciplini(int);
    Disciplini getCurrentDiscipline1(int);
    Disciplini getCurrentDiscipline2(int);
    Disciplini getCurrentDiscipline3(int);
    Disciplini getCurrentDiscipline4(int);
    Specialnosti();
    Specialnosti(std::string);
};

Specialnosti ::Specialnosti()
{
    this->specialnost="***";
}

Specialnosti :: Specialnosti(std::string specialnost)
{

    this->specialnost=specialnost;


}

void Specialnosti::getListDisciplini(int kurs)
{
    int counter=0;
    std::vector<Disciplini>::iterator it;
    switch (kurs)
    {
        case 1:
            counter=0;
            for(it=listDisciplini1.begin();it!=listDisciplini1.end();it++)
            {
                std::string name,tip;
                name=listDisciplini1[counter].getDisciplineName();
                tip=listDisciplini1[counter].getDisciplineType();
                std::cout<<counter+1<<"."<<name<<"-"<<tip<<std::endl;
                counter++;
            }

            break;
        case 2:
            counter=0;
            for(it=listDisciplini2.begin();it!=listDisciplini2.end();it++)
            {
                std::string name,tip;
                name=listDisciplini2[counter].getDisciplineName();
                tip=listDisciplini2[counter].getDisciplineType();
                std::cout<<counter+1<<"."<<name<<"-"<<tip<<std::endl;
                counter++;
            }
            break;
        case 3:
            counter=0;
            for(it=listDisciplini3.begin();it!=listDisciplini3.end();it++)
            {
                std::string name,tip;
                name=listDisciplini3[counter].getDisciplineName();
                tip=listDisciplini3[counter].getDisciplineType();
                std::cout<<counter+1<<"."<<name<<"-"<<tip<<std::endl;
                counter++;
            }
            break;
        case 4:
            counter=0;
            for(it=listDisciplini4.begin();it!=listDisciplini4.end();it++)
            {
                std::string name,tip;
                name=listDisciplini4[counter].getDisciplineName();
                tip=listDisciplini4[counter].getDisciplineType();
                std::cout<<counter+1<<"."<<name<<"-"<<tip<<std::endl;
                counter++;
            }
            break;
        default:
            std::cout<<"number must be between 1 and 4";
            break;
    }
}
void Specialnosti::getZaduljitelniDisciplini(int kurs)
{
    ZaduljitelniIzpiti.clear();
    int counter = 0;
    std::vector<Disciplini>::iterator it;
    switch (kurs)
    {
        case 1:
        {
            for (it = listDisciplini1.begin();it!=listDisciplini1.end();it++)
            {
                if (listDisciplini1[counter].getDisciplineType() == "zad" || listDisciplini1[counter].getDisciplineType() == "zaduljitelna")
                {
                    ZaduljitelniIzpiti.push_back(listDisciplini1[counter]);
                }
                counter++;
            }
            break;
        }
        case 2:
        {
            for (it = listDisciplini2.begin();it!=listDisciplini2.end();it++)
            {
                if (listDisciplini2[counter].getDisciplineType() == "zad" || listDisciplini2[counter].getDisciplineType() == "zaduljitelna")
                {
                    ZaduljitelniIzpiti.push_back(listDisciplini2[counter]);
                }
                counter++;
            }
            break;
        }
        case 3:
        {
            for (it = listDisciplini3.begin();it!=listDisciplini3.end();it++)
            {
                if (listDisciplini3[counter].getDisciplineType() == "zad" || listDisciplini3[counter].getDisciplineType() == "zaduljitelna")
                {
                    ZaduljitelniIzpiti.push_back(listDisciplini3[counter]);
                }
                counter++;
            }
            break;
        }
        case 4:
        {
            for (it = listDisciplini4.begin();it!=listDisciplini4.end();it++)
            {
                if (listDisciplini4[counter].getDisciplineType() == "zad" || listDisciplini4[counter].getDisciplineType() == "zaduljitelna")
                {
                    ZaduljitelniIzpiti.push_back(listDisciplini4[counter]);
                }
                counter++;
            }
            break;
        }


    }
}
void Specialnosti::addDiscipline(Disciplini &newDiscipline,int course)
{
    switch (course)
    {
        case 1:
            listDisciplini1.push_back(newDiscipline);
            break;
        case 2:
            listDisciplini2.push_back(newDiscipline);
            break;
        case 3:
            listDisciplini3.push_back(newDiscipline);
            break;
        case 4:
            listDisciplini4.push_back(newDiscipline);
            break;
        default:
            std::cout<<"number must be between 1 and 4"<<std::endl;
    }
}


Disciplini Specialnosti::getCurrentDiscipline1(int current)
{
    return listDisciplini1[current-1];
}
Disciplini Specialnosti::getCurrentDiscipline2(int current)
{
    return listDisciplini2[current-1];
}
Disciplini Specialnosti::getCurrentDiscipline3(int current)
{
    return listDisciplini3[current-1];
}
Disciplini Specialnosti::getCurrentDiscipline4(int current)
{
    return listDisciplini4[current-1];
}
#endif //SUSIPREDAVANE_SPECIALNOSTI_H
