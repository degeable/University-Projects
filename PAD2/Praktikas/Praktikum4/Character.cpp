/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.cpp
 * Author: stud
 * 
 * Created on 29. April 2017, 09:15
 */

#include "Character.h"
#include "Item.h"

Character::Character(char f, Controller* c, int stamina, int strength) : m_figur(f),m_con(c), m_stamina(stamina), m_strength(strength)
{
    c->setC_figur(this);
    m_hitpoints=getmaxHP();
}


char Character::getFigur() const
{
    return m_figur;
}

int Character::move()
{
    
    return m_con->move();

}

int Character::getmaxHP() const
{
    return 20+(getStamina()*5); 
}

void Character::showInfo() const
{
    cout<<"Symbol: "<<getFigur()<<endl<<"Stamina: "<<getStamina()<<endl<<"Strength: "<<getStrength()<<endl<<"Hp: "<<m_hitpoints<<endl<<endl;
}

void Character::addItem(Item* it)
{
    int t_hp=getmaxHP();
    m_inventory.push_back(it);
    int n_hp=getmaxHP();
    int r_hp=m_hitpoints;
    int diff=t_hp-r_hp;
   m_hitpoints=n_hp-diff;
}

int Character::getStrength() const
{
 int sum;
 for (int i = 0; i < m_inventory.size(); i++)
    {
     sum += m_inventory.at(i)->modifyStrenght(m_strength);

    }
    return m_strength+sum;
}
int Character::getStamina() const
{
int sum=0;
 for (int i = 0; i < m_inventory.size(); i++)
    {
     sum += m_inventory.at(i)->modifyStamina(m_stamina);

    }
    return m_stamina+sum;
    
}

void Character::setHitpoints(int hitpoints)
{
    m_hitpoints -= hitpoints;
}

int Character::getHitpoints() const
{
    return m_hitpoints;
}
