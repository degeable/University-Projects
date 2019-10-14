/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Country.cpp
 * Author: stud
 * 
 * Created on 8. Juli 2017, 15:54
 */

#include <vector>

#include "Country.h"

Country::Country(const std::string& datei)
{
    std::ifstream stream(datei.c_str());
    if(stream.good()){
   
    while(stream){
         Town t;
    stream>>t;
    if(stream){
    stadtname.push_back(t);
    bundesland.push_back(t);
    }
}
    }
    stadtname.sort(Town::sortbyName());
   bundesland.sort(Town::sortbyLand());
}



Country::~Country()
{
}

void Country::printLand() const
{
    for (const auto& elem : bundesland)
    {
        std::cout<<elem<<std::endl;
    }
    std::cout<<std::endl;

}

void Country::printTown() const
{
  for (const auto& elem : stadtname)
    {
        std::cout<<elem<<std::endl;
    }
    std::cout<<std::endl;
}

void Country::sucheStadt(std::string& stadt) const
{
    for (auto elem : stadtname)
    {
        if(elem.getStadt().substr(0,5)==stadt.substr(0,5)){
            std::cout<<elem<<std::endl;
        }
    }

}

void Country::doppelte() const
{
    std::vector<Town>obj;
     for (auto elem : stadtname)
    {
         obj.push_back(elem);
    }
    int j=0;
    for (int i = 0; i < obj.size(); i++)
    {
        j=i+1;
        if(obj[i].getStadt()==obj[j].getStadt()){
            std::cout<<obj[i]<<std::endl;
        while(obj[i].getStadt()==obj[j].getStadt()){
            std::cout<<obj[j]<<std::endl;
            j++;
        }

    }

 
}
}

void Country::gesamt() const
{

 using namespace std;
	auto it = bundesland.cbegin();
	auto itp1 = bundesland.cbegin();
	itp1++;

	while (itp1 != bundesland.end())
	{
		int count = it->getPop(true);
		while (it->sameState(*itp1))
		{
			count += itp1->getPop(true);
			itp1++;
			if (itp1 == bundesland.end())
				break;
		}
		cout << it->getBundesland() << ": " << count << endl;
		if (itp1 == bundesland.end())
			break;
		it = itp1;
		itp1++;

	}


}

void Country::letzte() 
{
using namespace std;
	std::list<Growth> growth;
	
	for(const auto& t : stadtname)
	{
		double g = ((t.getPop(true) - t.getPop(false)) / double(t.getPop(false))) * 100;
		growth.push_back(Growth(t, g));
	}
	
	growth.sort();
	
	for(const auto& t: growth)
	{
		cout << t.t << " :" << t.growth << endl;
	}
}
