#ifndef SUSIPREDAVANE_MENUTERMINAL_H
#define SUSIPREDAVANE_MENUTERMINAL_H
#include "Student.h"
#include "Specialnosti.h"
std::vector<Specialnosti> specialnosti;
std::vector<Student> allStudents;
std::vector<Student> protocols;
void terminalMenu();
void displayTerminal();
void enroll(const int,std::string,int,std::string);
void advance(const int);
void change(const int,int);
void graduate(const int);
void interrupt(const int);
void resume(const int);
void print(const int );
void printall(std::string,int);
void enrollin(const int);
void addgrade(const int);
void protocol(std::string);
void report(const int);
void writeToFile();
void runMenu();
void addDisciplineToSpecialnost();
void listSpec();
void listSpec()
{
    std::vector<Specialnosti>::iterator it;
    int counter=0;
    for(it=specialnosti.begin();it!=specialnosti.end();it++)
    {
        std::string spec;
        spec=specialnosti[counter].getSpecialnostName();
        std::cout<<counter+1<<"."<<spec<<std::endl;
        counter++;
    }

}
void addDisciplineToSpecialnost()
{
    listSpec();
    Disciplini newDisciplina;
    std::cout<<"Enter number of specialnost :";
    int number;
    std::cin>>number;
    std::cout<<"Enter the number of disciplines you want to add :";
    int numOfDisciplines;
    std::cin>>numOfDisciplines;
    std::cout<<std::endl;
    for (int i=0;i<numOfDisciplines;i++)
    {
        std::string name,tip;
        std::cout<<"Enter name of disciplina:";
        std::cin>>name;
        newDisciplina.setDisciplineName(name);
        std::cout<<std::endl;
        std::cout<<"Enter type of disciplina(zaduljitelna/izbiraema) :";
        std::cin>>tip;
        newDisciplina.setType(tip);
        int course;
        std::cout<<"Enter a course number to add the discipline:";
        std::cin>>number;
        specialnosti[number-1].addDiscipline(newDisciplina,number);
    }
}
void writeToFile()
{
    
    std::ofstream out ("SUSI3.bin",std::ios::binary|std::ios::trunc);
    out.seekp(0);
    for (int i=0;i<allStudents.size();i++)
    {
        out.write((char*)&allStudents[i],sizeof(Student));
    }
    out.close();
}
void runMenu()
{

    Student s;
    int numberStudents;
    std::ifstream input("SUSI3.bin");
    input >> numberStudents;
    input.close();
    std::cout<<numberStudents;
    std::ifstream in ("SUSI3.bin",std::ios::binary|std::ios::in);

    in.seekg(0*sizeof(Student));
    for(int i=0;i<2;i++) {
        in.read((char*)&s, sizeof(Student));
        allStudents.push_back(s);
        std::cout << s.getName() << std::endl;
    }


    terminalMenu();
//    in.close();
//    std::string comand;
//    do {
//        std::cout<<"Would you like to save changes(yes/no)"<<std::endl;
//        std::cin>>comand;
         writeToFile();
//    }while (comand=="yes"||comand=="no");
}
void enroll(const int facNum,std::string specialnost,int group,std::string name)
{
    Student newStudent;
    newStudent.setFacNum(facNum);
    newStudent.setName(name);
    newStudent.setSpecialnost(specialnost);
    newStudent.setGroup(group);
    newStudent.setCourse(1);
    newStudent.setStatus("enrolled");
    allStudents.push_back(newStudent);
    for(int i=0;i<allStudents.size();i++)
    {
        allStudents[i].plusStudent();
    }
}
void advance(const int facNum)
{
    bool flag=false;
    int facNumCheck=facNum;
    int counter=0;
    std::vector<Student>::iterator it;
    for (it = allStudents.begin(); it != allStudents.end(); it++) {
        int facNum = allStudents[counter].getFacNum();

        if (facNum == facNumCheck && allStudents[counter].getStatus()!="prekusnal" && flag==allStudents[counter].getFlag())
        {
            int kursCheck=allStudents[counter].getCourse();
            std::vector<Disciplini>::iterator it;
            int broqch=0;
            int zaduljitelni=0;
            int zadNad3ka=0;
            for (it=allStudents[counter].polojeniIzpitiDisciplini.begin();it!=allStudents[counter].polojeniIzpitiDisciplini.end();it++)
            {
                if (allStudents[counter].polojeniIzpitiDisciplini[broqch].getDisciplineType()=="zad")
                {
                    zaduljitelni++;
                }
                if (allStudents[counter].polojeniIzpitiDisciplini[broqch].getGrade()>=3 && allStudents[counter].polojeniIzpitiDisciplini[broqch].getDisciplineType()=="zad")
                {
                    zadNad3ka++;
                }
                broqch++;
            }
            if (zadNad3ka==zaduljitelni-2|| zadNad3ka==zaduljitelni-1|| zadNad3ka==zaduljitelni)
            {
                kursCheck++;
                allStudents[counter].setCourse(kursCheck);
            }else
            {
                std::cout<<"Grades are not eligible"<<std::endl;
            }
        }
        counter++;
    }
}
int checkStudentAlegibilityOfChangingSpecialnost(int facNumCheck)
{
    std::vector<Student>::iterator it;
    int counter=0;
    int broqch=0;
    int check = 0;
    int flag = 0;
    for (it = allStudents.begin(); it != allStudents.end(); it++)
    {
        int facNum = allStudents[counter].getFacNum();

        if (facNum == facNumCheck)
        {
            std::vector<Disciplini>::iterator hit;
            std::vector<Disciplini>::iterator mit;
            for (hit = allStudents[counter].polojeniIzpitiDisciplini.begin(); hit != allStudents[counter].polojeniIzpitiDisciplini.end(); hit++)
            {
                int broqch1 = 0;
                for (mit = ZaduljitelniIzpiti.begin(); mit !=ZaduljitelniIzpiti.end();mit++)
                {
                    if (allStudents[counter].polojeniIzpitiDisciplini[broqch].getDisciplineName() == ZaduljitelniIzpiti[broqch1].getDisciplineName()
                        && (allStudents[counter].polojeniIzpitiDisciplini[broqch].getGrade()>=3))
                    {
                        check++;
                    }
                    broqch1++;
                }
                broqch++;
            }
        }
        counter++;
    }
    if (check == ZaduljitelniIzpiti.size())
    {
        flag = 1;
    }

    return flag;
}
void change(const int facNum,int value)
{
    std::vector<Student>::iterator it;
    int  facNumCheck = facNum;
    bool flag=false;
    switch (value)
    {
        case 1:
        {
            int counter = 0, temp;
            for (it = allStudents.begin(); it != allStudents.end(); it++)
            {
                int facNum = allStudents[counter].getFacNum();
                if (facNum == facNumCheck && flag==allStudents[counter].getFlag()) {
                    temp=counter;
                    int broqch = 0;
                    std::string name;
                    std::cout << "Enter name of speciality:";
                    std::cin >> name;
                    std::cout << std::endl;
                    std::vector<Specialnosti>::iterator hit;
                    for (hit = specialnosti.begin(); hit != specialnosti.end(); hit++) {
                        if (name == specialnosti[broqch].getSpecialnostName()) {
                            int kursNomer;
                            std::cout << "Enter a course number(for current speciality):";
                            std::cin >> kursNomer;
                            switch (kursNomer) {
                                case 1: {
                                    specialnosti[broqch].getZaduljitelniDisciplini(1);
                                    if (checkStudentAlegibilityOfChangingSpecialnost(facNumCheck) == 1) {
                                        allStudents[counter].setSpecialnost(name);
                                    } else {
                                        for (int i = 0; i < allStudents[temp].polojeniIzpitiDisciplini.size(); i++) {
                                            for (int j = 0; j < ZaduljitelniIzpiti.size(); j++) {
                                                if (allStudents[temp].polojeniIzpitiDisciplini[i].getDisciplineName() !=
                                                    ZaduljitelniIzpiti[j].getDisciplineName()) {
                                                    allStudents[temp].tekushtoZapisani.push_back(ZaduljitelniIzpiti[j]);
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }


                                case 2: {
                                    specialnosti[broqch].getZaduljitelniDisciplini(2);
                                    if (checkStudentAlegibilityOfChangingSpecialnost(facNumCheck) == 1) {
                                        allStudents[counter].setSpecialnost(name);
                                    } else {
                                        for (int i = 0; i < allStudents[temp].polojeniIzpitiDisciplini.size(); i++) {
                                            for (int j = 0; j < ZaduljitelniIzpiti.size(); j++) {
                                                if (allStudents[temp].polojeniIzpitiDisciplini[i].getDisciplineName() !=
                                                    ZaduljitelniIzpiti[j].getDisciplineName()) {
                                                    allStudents[temp].tekushtoZapisani.push_back(ZaduljitelniIzpiti[j]);
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }

                                case 3: {
                                    specialnosti[broqch].getZaduljitelniDisciplini(3);
                                    if (checkStudentAlegibilityOfChangingSpecialnost(facNumCheck) == 1) {
                                        allStudents[counter].setSpecialnost(name);
                                    } else {
                                        for (int i = 0; i < allStudents[temp].polojeniIzpitiDisciplini.size(); i++) {
                                            for (int j = 0; j < ZaduljitelniIzpiti.size(); j++) {
                                                if (allStudents[temp].polojeniIzpitiDisciplini[i].getDisciplineName() !=
                                                    ZaduljitelniIzpiti[j].getDisciplineName()) {
                                                    allStudents[temp].tekushtoZapisani.push_back(ZaduljitelniIzpiti[j]);
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }

                                case 4: {
                                    specialnosti[broqch].getZaduljitelniDisciplini(4);
                                    if (checkStudentAlegibilityOfChangingSpecialnost(facNumCheck) == 1) {
                                        allStudents[counter].setSpecialnost(name);
                                    } else {
                                        for (int i = 0;
                                             i < allStudents[temp].polojeniIzpitiDisciplini.size(); i++) {
                                            for (int j = 0; j < ZaduljitelniIzpiti.size(); j++) {
                                                if (allStudents[temp].polojeniIzpitiDisciplini[i].getDisciplineName() !=
                                                    ZaduljitelniIzpiti[j].getDisciplineName()) {
                                                    allStudents[temp].tekushtoZapisani.push_back(
                                                            ZaduljitelniIzpiti[j]);
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                default:{
                                    std::cout<<"Enter number between 1 and 4"<<std::endl;
                                    break;
                                }

                            }
                        }
                        broqch++;
                    }
                }


                break;
            }
        }
        case 2:
        {
            int counter = 0;
            int group;
            for (it = allStudents.begin(); it != allStudents.end(); it++) {
                int facNum = allStudents[counter].getFacNum();
                if (facNumCheck = facNum) {
                    std::cout<<"Enter group number:"<<std::endl;
                    std::cin>>group;
                    allStudents[counter].setGroup(group);
                    break;
                }
                counter++;
            }
            break;
        }
        case 3:
        {
            advance(facNum);
            break;
        }
    }

}
void graduate(const int facNum)
{
    int numberOfDisciplines;
    int facNumChek=facNum;
    int counter=0,temp;
    int lastCourse=4;

    for (int i=0;i<allStudents.size();i++)
    {
        int facNum=allStudents[i].getFacNum();
        int course=allStudents[i].getCourse();
        bool flag=false;

        if(facNumChek==facNum && lastCourse==course && flag==allStudents[i].getFlag())
        {
            temp=i;
            numberOfDisciplines=allStudents[i].tekushtoZapisani.size();

            for (int j=0;j<allStudents[i].tekushtoZapisani.size();j++)
            {
                for (int k=0;k<allStudents[i].polojeniIzpitiDisciplini.size();j++)
                {
                    if(allStudents[i].tekushtoZapisani[j].getDisciplineName()==allStudents[i].polojeniIzpitiDisciplini[k].getDisciplineName())
                    {
                        counter++;
                    }else
                    {
                        std::cout<<allStudents[i].tekushtoZapisani[j].getDisciplineName()<<"doesn't have grade";
                        std::cout<<std::endl<<"Graduation is not possible"<<std::endl;
                        j=numberOfDisciplines;
                        k=allStudents[i].polojeniIzpitiDisciplini.size();
                    }
                }

            }
        }
    }
    if (counter==numberOfDisciplines) allStudents[temp].setStatus("graduated");
}
void interrupt(const int facNum)
{

    std::vector<Student>::iterator it;
    int counter=0;
    int facNumCheck=facNum;
    bool flag=false;

    for (it = allStudents.begin(); it != allStudents.end(); it++) {
        int facNum = allStudents[counter].getFacNum();

        if (facNum == facNumCheck)
        {
            std::string status ="prekusnal";
            allStudents[counter].setStatus(status);
            allStudents[counter].setFlag(flag);
        }
        counter++;
    }
}
void resume(const int facNum)
{
    std::vector<Student>::iterator it;
    int counter=0;
    int facNumCheck=facNum;
    bool flag=false;

    for (it = allStudents.begin(); it != allStudents.end(); it++) {
        int facNum = allStudents[counter].getFacNum();

        if (facNum == facNumCheck)
        {
            std::string status ="enrolled";
            allStudents[counter].setStatus(status);
            allStudents[counter].setFlag(flag);
        }
        counter++;
    }
}
void print(const int facNum)
{
    std::vector<Student>::iterator it;
    int counter=0;
    int facNumCheck=facNum;


    for (it = allStudents.begin(); it != allStudents.end(); it++)
    {
        std::string name = allStudents[counter].getName();
        int facNum = allStudents[counter].getFacNum();
        int group=allStudents[counter].getGroup();
        std::string specialnost=allStudents[counter].getSpecialnost();
        int kurs=allStudents[counter].getCourse();
        std::string status=allStudents[counter].getStatus();
        double averageGrade=allStudents[counter].getAverageGrade();

        if(facNum == facNumCheck)
        {
            std::cout<<"Name: "<<name<<std::endl;
            std::cout<<"Facultet number: "<<facNum<<std::endl;
            std::cout<<"Group: "<<group<<std::endl;
            std::cout<<"Specialnost: "<<specialnost<<std::endl;
            std::cout<<"Kurs: "<<kurs<<std::endl;
            std::cout<<"Status: "<<status<<std::endl;
            std::cout<<"Average grade: "<<averageGrade<<std::endl;
            break;
        }
        counter++;
    }
}
void printall(std::string specialnost,int course)
{
    int counter=0,temp=0;
    bool trueSpec=false;
    std::vector<Specialnosti>::iterator git;
    for(git=specialnosti.begin();git!=specialnosti.end();git++)
    {
        if (specialnost==specialnosti[counter].getSpecialnostName())
        {
            temp=counter;
            trueSpec=true;
        }
        counter++;
    }
    counter=0;
    int broqch=1;
    if (trueSpec==true)
    {
        std::vector<Student>::iterator it;
        for (it = allStudents.begin(); it != allStudents.end(); it++) {
            if (allStudents[counter].getSpecialnost() == specialnosti[temp].getSpecialnostName() && allStudents[counter].getCourse() == course) {
                std::string name = allStudents[counter].getName();
                int facNum = allStudents[counter].getFacNum();
                int group = allStudents[counter].getGroup();
                std::string status = allStudents[counter].getStatus();
                std::cout << "---" << broqch << "---" << std::endl;
                std::cout << "Name: " << name << std::endl;
                std::cout << "Facultet number: " << facNum << std::endl;
                std::cout << "Group: " << group << std::endl;
                std::cout << "Status: " << status << std::endl;
                broqch++;
            }
            counter++;
        }
    }else std::cout<<"Speciality name incorrect"<<std::endl;
}
void enrollin(const int facNum)
{
    std::vector<Student>::iterator it;
    int counter=0;
    int facNumCheck=facNum;
    bool flag=false;


    for (it = allStudents.begin(); it != allStudents.end(); it++)
    {

        int facNum = allStudents[counter].getFacNum();
        if(facNum == facNumCheck && allStudents[counter].getStatus()!="prekusnal"&& flag==allStudents[counter].getFlag())
        {
            std::vector<Specialnosti>::iterator itt;
            int broqch=0;
            std::string specCheck=allStudents[counter].getSpecialnost();
            for(itt=specialnosti.begin();itt!=specialnosti.end();itt++)
            {
                if(specCheck==specialnosti[broqch].getSpecialnostName())
                {
                    specialnosti[broqch].getListDisciplini(allStudents[counter].getCourse());
                    std::cout<<"Choose discipline:";
                    int dNumber;
                    std::cin>>dNumber;
                    switch (allStudents[counter].getCourse())
                    {
                        case 1:
                            allStudents[counter].addTekushtaDisciplina(specialnosti[broqch].getCurrentDiscipline1(dNumber));
                            break;
                        case 2:
                            allStudents[counter].addTekushtaDisciplina(specialnosti[broqch].getCurrentDiscipline2(dNumber));
                            break;
                        case 3:
                            allStudents[counter].addTekushtaDisciplina(specialnosti[broqch].getCurrentDiscipline3(dNumber));
                            break;
                        case 4:
                            allStudents[counter].addTekushtaDisciplina(specialnosti[broqch].getCurrentDiscipline4(dNumber));
                            break;
                    }
                }
                broqch++;
            }
        }
        counter++;
    }
}
void addgrade(const int facNum)
{
    std::vector<Student>::iterator it;
    int counter=0;
    int facNumCheck=facNum;


    for (it = allStudents.begin(); it != allStudents.end(); it++)
    {
        int facNum = allStudents[counter].getFacNum();

        if(facNum == facNumCheck && allStudents[counter].getStatus()=="enrroled") {
            allStudents[counter].getListTekushtiDisciplini();
            std::cout << "Choose discipline to add grade:";
            int number, grade;
            std::cin >> number;
            std::cout << "Enter grade:";
            std::cin >> grade;
            Disciplini newD = allStudents[counter].getDisciplina(number);
            newD.setGrade(grade);
            allStudents[counter].addPolojeniDisciplini(newD);

        }
        counter++;
    }
}
void protocolsSort()
{
    std::vector<Student>::iterator it;
    int counter=0;
    for (int i=0;i<protocols.size()-1;i++)
    {
        for (int j=i+1;j<protocols.size();j++)
        {
            if (protocols[i].getFacNum()>protocols[j].getFacNum())
            {
                std::swap(protocols[i],protocols[j]);
            }
        }
    }
    for (it=protocols.begin();it!=protocols.end();it++)
    {
        std::cout   <<"----"<<counter+1<<"----"<<std::endl
                    <<"Name:"<<protocols[counter].getName()<<std::endl
                    <<"Facultet number:"<<protocols[counter].getFacNum()<<std::endl;
        counter++;
    }
    protocols.clear();
}
void protocol(std::string disciplineName)
{
    for (int i=0;i<allStudents.size();i++)
    {
        for(int j=0;j<allStudents[i].tekushtoZapisani.size();j++)
        {
            if (allStudents[i].tekushtoZapisani[j].getDisciplineName()==disciplineName)
            {
                protocols.push_back(allStudents[i]);
            }
        }
    }
    protocolsSort();
}
void report(const int facNum)
{
    std::vector<int> grades;
    std::vector<Student>::iterator it;
    int counter=0,broqch=0,broqch2=0,broqch3=0,counter2=0,temp;
    double avGrade=0,avGrade2=0;
    int facNumCheck=facNum;


    for (it = allStudents.begin(); it != allStudents.end(); it++)
    {
        int facNum=allStudents[counter].getFacNum();
        if (facNumCheck==facNum)
        {
            std::cout<<"List with passed disciplines:"<<std::endl;
            allStudents[counter].getListPolojeniIzpiti();
            std::vector<Disciplini>::iterator hit;
            for(hit=allStudents[counter].polojeniIzpitiDisciplini.begin();hit!=allStudents[counter].polojeniIzpitiDisciplini.end();hit++)
            {
                if(allStudents[counter].polojeniIzpitiDisciplini[broqch].getGrade()>=3) {
                    grades.push_back(allStudents[counter].polojeniIzpitiDisciplini[broqch].getGrade());
                }
                broqch++;
            }
            break;
        }
        counter++;
    }
    for (int i=0;i<grades.size();i++)
    {
        avGrade=avGrade+grades[broqch2];
        broqch2++;
    }
    avGrade=avGrade/grades.size();
    std::cout<<"Average grade for passed disciplines:"<<avGrade<<std::endl;
    for (it=allStudents.begin();it!=allStudents.end();it++)
    {
        int facNum=allStudents[counter2].getFacNum();
        if (facNumCheck==facNum)
        {
            temp=counter2;
            std::cout<<"List with not passed disciplines:"<<std::endl;
            allStudents[counter2].getListTekushtiDisciplini();
            broqch3=allStudents[counter2].tekushtoZapisani.size();
            break;
        }
        counter2++;
    }
    if(broqch3==0) avGrade2=avGrade;
    else  avGrade2 = avGrade +broqch3*2/ broqch3+allStudents[temp].polojeniIzpitiDisciplini.size();
    std::cout<<"Average grade (not passed disciplines included):"<<avGrade2<<std::endl;
}

void displayTerminal()
{
    std::cout<<"====Comand Menu===="<<std::endl;
    std::cout<<"1.enroll <facNum> <speciality> <group> <name>"<<std::endl;
    std::cout<<"2.advance <facNum>"<<std::endl;
    std::cout<<"3.change <option> <value>"<<std::endl;
    std::cout<<"4.graduate <facNum>"<<std::endl;
    std::cout<<"5.iterrupt <facNum>"<<std::endl;
    std::cout<<"6.resume <facNum>"<<std::endl;
    std::cout<<"7.print <facNum>"<<std::endl;
    std::cout<<"8.printAll <speciality> <course>"<<std::endl;
    std::cout<<"9.enrollIn <facNum>"<<std::endl;
    std::cout<<"10.addGrade <facNum>"<<std::endl;
    std::cout<<"11.protocol <disciplineName>"<<std::endl;
    std::cout<<"12.report <facNum>"<<std::endl;
    std::cout<<"13.adddiscipline"<<std::endl;
    std::cout<<"Enter comand:";
}
void terminalMenu()
{
    std::string comand;
    while (comand!="Exit"||comand!="exit")
    {
        displayTerminal();
        std::cin>>comand;
        if (comand=="enroll")
        {
            int group,facNum;
            std::string specialnost;
            std::string name;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            std::cout<<"<";std::cin>>specialnost;std::cout<<">";
            std::cout<<"<";std::cin>>group;std::cout<<">";
            std::cout<<"<";std::getline(std::cin>>std::ws,name);;std::cout<<">";
            std::cout<<std::endl;
            enroll(facNum,specialnost,group,name);
            std::cout<<std::endl;
        }
        else if (comand=="advance")
        {
            int facNum;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            advance(facNum);
            std::cout<<std::endl;
        }
        else if (comand=="change")
        {
            int facNum,value;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            std::cout<<"==You have 3 options=="<<std::endl;
            std::cout<<"1. Program"<<std::endl;
            std::cout<<"2. Group"<<std::endl;
            std::cout<<"3. Year"<<std::endl;
            std::cout<<"Choose number:";
            std::cin>>value;

            change(facNum,value);
            std::cout<<std::endl;
        }
        else if(comand=="graduate")
        {
            int facNum;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            graduate(facNum);
            std::cout<<std::endl;
        }
        else if (comand=="interrupt")
        {
            int facNum;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            std::cout<<std::endl;
            interrupt(facNum);
            std::cout<<std::endl;
        }
        else if(comand=="resume")
        {
            int facNum;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            resume(facNum);
            std::cout<<std::endl;
        }
        else if(comand=="print")
        {
            int facNum;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            print(facNum);
            std::cout<<std::endl;
        }
        else if(comand=="printall")
        {
            std::string specialnost;
            int course;
            std::cout<<"<";std::cin>>specialnost;std::cout<<">";std::cout<<"<";std::cin>>course;std::cout<<">";
            printall(specialnost,course);
            std::cout<<std::endl;
        }
        else if (comand=="enrollin")
        {
            int facNum;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            enrollin(facNum);
            std::cout<<std::endl;
        }
        else if(comand=="addgrade")
        {
            int facNum;
            std::cout<<"<";std::cin>>facNum;std::cout<<">";
            addgrade(facNum);
            std::cout<<std::endl;
        }
        else if(comand=="protocol")
        {
            std::string disciplineName;
            std::cout<<"<";std::cin>>disciplineName;std::cout<<">";
            protocol(disciplineName);
        }
        else if(comand=="report") {
            int facNum;
            std::cout << "<";
            std::cin >> facNum;
            std::cout << ">";
            report(facNum);
        }else if(comand=="adddiscipline")
        {
            addDisciplineToSpecialnost();
        }
        else if(comand=="exit") break;
    }
}





#endif //SUSIPREDAVANE_MENUTERMINAL_H
