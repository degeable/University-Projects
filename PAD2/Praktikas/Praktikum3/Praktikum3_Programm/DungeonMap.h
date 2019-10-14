/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DungeonMap.h
 * Author: stud
 *
 * Created on 25. April 2017, 13:20
 */

#ifndef DUNGEONMAP_H
#define DUNGEONMAP_H
#include <string>
#include <vector>
#include "Tile.h"
#include "Floor.h"
#include "Wall.h"

using namespace std;

     struct Position{
        int Reihe;
        int Spalte;
    };
class DungeonMap
{
public:
    DungeonMap(int height, int width, Position pos);
    DungeonMap(int height, int width, const vector<string>&data,const vector<string>& data_s, Position pos);
    virtual ~DungeonMap();
    
    void place(Position pos, Character* c);
    Position findTile(Tile* t)const;
    Tile* findTile(Position pos)const;
    Position findCharacter(Character *c)const;
    void print()const;
    
private:
    Tile*** m_map;
     int m_height;
     int m_width;
};

#endif /* DUNGEONMAP_H */

