

/* 
 * File:   Galaxis.cpp
 * Author: stud
 * 
 * Created on 9. Juli 2017, 17:10
 */

#include <vector>

#include "Galaxis.h"

Galaxis::Galaxis(const std::string& datei)
{
    std::ifstream file(datei.c_str());

    if (!file.good())
        throw std::invalid_argument("File " + datei + " could not be opened!");
    Stern s;
    
    
    while (!file.eof())
    {
        file>>s;
    
        sterneID.push_back(s);

 
//           
//           int x;
//         std::  cin>>x;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout<<sterneID.at(i)<<std::endl;

    }

}


Galaxis::Galaxis(const Galaxis& orig)
{
}

Galaxis::~Galaxis()
{
}

Stern& Galaxis::find(int ID)
{
    	Stern tmp;
	tmp.SetID(ID);
	return std::binary_search(sterneID.begin(), sterneID.end(), tmp, Stern::sortbyID());

}

Stern& Galaxis::find(const std::string& name)
{

	Stern tmp;
	tmp.SetName(name);
	return std::binary_search(sterneName.begin(), sterneName.end(), tmp, Stern::sortbyName());
}

bool Galaxis::sorter::operator()(const SternEntfernung& lhs, const SternEntfernung& rhs)
{
    return lhs.s_dist < rhs.s_dist;
}

void Galaxis::Entfernung()
{

        for (auto elem : sterneName)
        {
            SternEntfernung s;
            s.s= elem;
            s.s_dist=std::sqrt(elem.GetX()* elem.GetX()+ elem.GetY()*elem.GetY()+elem.GetZ()*elem.GetZ());
            sternDist.push_back(s);
        }
        sternDist.sort(sorter());
        
        for (auto elem : sternDist)
        {
            std::cout<<elem.s.GetName()<<": "<<elem.s_dist<<" pc"<<std::endl;
        }


}

void Galaxis::trinity()
{
	std::list<Stern> trinary;

	for (auto s : sterneID)
	{
		if (s.getIndex() == 3)
			trinary.push_back(s);
	}


	//	for (auto s : trinary)
	//		std::cout << s << std::endl;

	std::cout << trinary.size() << std::endl;


	for (auto t : trinary)
	{
		for (auto s : m_stars)
		{
			if (t.GetPrim() == s.GetPrim())
				std::cout << s.getID() << " ";
		}
		std::cout << std::endl;
	}

}



