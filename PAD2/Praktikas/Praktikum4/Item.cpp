/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: stud
 * 
 * Created on 19. Mai 2017, 13:02
 */

#include "Item.h"

Item::Item()
{
}

Item::Item(const Item& orig)
{
}

Item::~Item()
{
}

void Item::print()
{
    
}


int GreatSword::modifyStamina(int strength) const
{
    return -1;
}

int ArmingSword::modifyStamina(int strength) const
{
    return 0;
}

int FullPlateArmour::modifyStamina(int strength) const
{
    return 6;
}

int Club::modifyStamina(int strength) const
{
    return 0;
}

int Gambeson::modifyStamina(int strength) const
{
    return 1;
}

int RapierAndDagger::modifyStamina(int strength) const
{
    return 1;
}

int Shield::modifyStamina(int strength) const
{
    return strength * 1.0;
}

int MailArmour::modifyStamina(int strength) const
{
    return 3;
}

int GreatSword::modifyStrenght(int strength) const
{
    return 5;
}

int ArmingSword::modifyStrenght(int strength) const
{
    return 3;
}

int FullPlateArmour::modifyStrenght(int strength) const
{
    return -2;
}

int Club::modifyStrenght(int strength) const
{
    return strength * 0.5;
}

int Gambeson::modifyStrenght(int strength) const
{
    return 0;
}

int RapierAndDagger::modifyStrenght(int strength) const
{
    return 2;
}

int Shield::modifyStrenght(int strength) const
{
    return -1;
}

int MailArmour::modifyStrenght(int strength) const
{
    return 0;
}
