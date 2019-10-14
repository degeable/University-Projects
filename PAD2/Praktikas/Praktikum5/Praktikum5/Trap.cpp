/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trap.cpp
 * Author: stud
 * 
 * Created on 19. Mai 2017, 17:48
 */

#include "Trap.h"

Trap::Trap(Character* c): Tile(c), t_active(true){
    
}



Trap::~Trap()
{
}

void Trap::onLeave(Tile* toTile)
{
    if(!toTile->hasCharacter()){
        Character* c=this->GetFigur();
      this->SetFigur(nullptr);
         toTile->onEnter(c,this);
           
         }
    
}

void Trap::print() 
{
    	if(hasCharacter()){
		 cout<<this->GetFigur()->getFigur();
	}
	
        else if(t_active){
		cout<<".";
        
        }else cout<<"T";
}

void Trap::onEnter(Character* c, Tile* fromTile)
{
    if(t_active){
    c->setHitpoints(20);
    }// sollte nicht mit maxHp gearbeitet werde?...
    this->SetFigur(c);
     t_active=false;
}

bool Trap::istBetretbar() const
{
    return true;
}

