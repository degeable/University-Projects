/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.h
 * Author: stud
 *
 * Created on 5. Mai 2017, 08:16
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Character;
class Controller
{
public:
    Controller();
    Controller(const Controller& orig);
    virtual ~Controller();
    virtual int move()=0;
    virtual void setC_figur(Character* c_figur);
    Character* getC_figur() const;
   
private:
    Character* c_figur;

};

#endif /* CONTROLLER_H */

