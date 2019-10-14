/* 
 * File:   penis.h
 * Author: fs
 *
 * Created on 6. Februar 2017, 13:09
 */

#ifndef PENIS_H
#define	PENIS_H

class penis {
public:
    penis();
    penis(int laenge, int umfang);
    virtual ~penis();
private:
    int m_laenge;
    int m_umfang;
};

#endif	/* PENIS_H */

