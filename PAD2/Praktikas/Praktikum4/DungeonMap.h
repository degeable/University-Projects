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
#include <stdio.h>
#include <stdlib.h>
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
    DungeonMap(int height, int width);
    DungeonMap(int height, int width, const vector<string>&data,const vector<string>& data_s);
    virtual ~DungeonMap();
    
    void place(Position pos, Character* c);
    Position findTile(Tile* t)const;
    Tile* findTile(Position pos)const;
    Tile* findTile(int Reihe,int Spalte)const;
    Position findCharacter(Character *c)const;
    void print(Position pos)const;
    bool hasLineofSight(Position pStart, Position pDest)const;
    Character* Parse(vector<string>data_s,int i);
private:
    Tile*** m_map;
     int m_height;
     int m_width;
};

#endif /* DUNGEONMAP_H */

