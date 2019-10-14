/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: stud
 *
 * Created on 19. Mai 2017, 13:02
 */

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item
{
public:
    virtual int modifyStrenght(int strength)const = 0;
    virtual int modifyStamina(int strength)const = 0; //strength typo... todo
    Item();
    Item(const Item& orig);
    virtual ~Item();
    virtual void print();
private:
    
};

class ArmingSword : public Item
{
public:
    int modifyStamina(int strength) const override;
    int modifyStrenght(int strength) const override;
    void print() override
    {
        std::cout<<s;
    }


    virtual ~ArmingSword() //richtig so?
    {
        delete this;
    }


private:
    std::string s = "Arming Sword aufgehoben!\n";
};

class GreatSword : public Item
{
public:
    int modifyStamina(int strength) const override;
    int modifyStrenght(int strength) const override;
    void print() override
    {
        std::cout<<s;
    }


    virtual ~GreatSword() //richtig so?
    {
        delete this;
    }


private:
    std::string s = "Great Sword aufgehoben!\n";

};

class Club : public Item
{
public:
    int modifyStamina(int strength) const override;
    int modifyStrenght(int strength) const override;


};

class RapierAndDagger : public Item
{
public:
    int modifyStamina(int strength) const override;
    int modifyStrenght(int strength) const override;

};

class Gambeson : public Item
{
public:
    int modifyStamina(int strength) const override;
    int modifyStrenght(int strength) const override;


};

class MailArmour : public Item
{
public:
    int modifyStamina(int strength) const override;
    int modifyStrenght(int strength) const override;


};

class Shield : public Item
{
public:
    int modifyStamina(int strength) const override;
    int modifyStrenght(int strength) const override;


};

class FullPlateArmour : public Item
{
public:
    int modifyStamina(int strength) const override;
    int modifyStrenght(int strength) const override;


};

#endif /* ITEM_H */

