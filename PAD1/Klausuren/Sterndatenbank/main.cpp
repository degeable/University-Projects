/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 5. Februar 2017, 18:01
 */

#include <cstdlib>
#include <iostream>
#include "Star.h"
#include "Universe.h"
#include "Vec3D.h"
#include <vector>
#include <string>


using std::cout;
using std::cin;
using std::endl;

int main()
{
	{
		Vec3D a;
		cout << "Soll: (0, 0, 0), Ist: ";
		a.print();

		Vec3D b(2);
		cout << "Soll: (2, 2, 2), Ist: ";
		b.print();

//		Vec3D c(2, 3);
//		cout << "Soll: (2, 3, 0), Ist: ";
//		c.print();

		Vec3D d(2, 3, 4);
		cout << "Soll: (2, 3, 4), Ist: ";
		d.print();

		cout << "\nSoll: 5.38516, Ist: ";
		cout << d.length() << "\n" << endl;
	}

	{
		Star a;
		cout << "Soll: \"Unbekannt\" (X) @ (0, 0, 0) Ist: ";
		a.print();

		Star b("Altair", Vec3D(11.04, 12.33, -2.728), 'A');
		cout << "Soll: \"Altair\" (A) @ (11.04, 12.33, -2.728) Ist: ";
		b.print();
	}

	Universe u;
	u.addStar(Star("Sol", Vec3D(0), 'G'));
	u.addStar(Star("Barnards Stern", Vec3D(4.936, 3.001, 1.388), 'M'));
	u.addStar(Star("Sirius", Vec3D(-5.745, -6.725, -1.262), 'A'));
	u.addStar(Star("Epsilon Eridani", Vec3D(-6.82, -1.966, -7.733), 'K'));
	u.addStar(Star("Tau Ceti", Vec3D(-3.49, 0.373, -11.37), 'G'));
	u.addStar(Star("Alpha Centauri", Vec3D(3.165, -3.048, -0.0818), 'G'));

	cout << endl;
	
	cout << endl << endl;

	cout << "Soll: 4.39479 Ist: " << u.getDistance("Sol", "Alpha Centauri") << endl << endl;

	cout << "Barnards Stern:" << endl;
	u.findNearestStar(Vec3D(10, 10, 10)).print();
        

	cout << "\nEpsilon Eridani:" << endl;
	u.findNearestStar(Vec3D(5, 3, 0), 'K').print();

	cout << std::flush;
	return 0;
}

