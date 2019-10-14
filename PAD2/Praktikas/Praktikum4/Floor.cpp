/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.cpp
 * Author: stud
 * 
 * Created on 3. Mai 2017, 21:00
 */

#include "Floor.h"
#include "Item.h"

Floor::Floor(Character* c):Tile(c)
{
  
}

Floor::~Floor()
{
}

void Floor::onEnter(Character* c, Tile* fromTile)
{
    this->SetFigur(c);
    if(this->GetItem()!=nullptr){
        c->addItem(this->GetItem());       
    this->GetItem()->print();
    this->setItem(nullptr);
    }
}

void Floor::onLeave(Tile* toTile)
{
    if(!toTile->hasCharacter()){
        Character* c=this->GetFigur();
      this->SetFigur(nullptr);
      
         toTile->onEnter(c,this);
           
         }
    
}

    void Floor::print()
    {
    	if(hasCharacter()){
		 cout<<this->GetFigur()->getFigur();
	}	else if(hasItem()){
            cout<<"*";
            
        }
else{
		cout<<".";
        }
	
    }

    void Floor::setItem(Item* i)
    {
        Tile::setItem(i);
    }
bool Floor::hasItem()
{
    if(GetItem()!=nullptr){
        return true;
    }
    return false;
}


    

