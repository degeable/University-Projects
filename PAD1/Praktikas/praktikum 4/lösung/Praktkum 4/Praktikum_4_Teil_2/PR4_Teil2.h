/* 
 * File:   PR4_Teil2.h
 * Author: fs
 *
 * Created on 15. November 2016, 21:06
 */


class Dot_2D
{
    private:
        float x;
        float y;
    public:
        void create(const float& a,const float& b);
        float getX();
        float getY();
};


class Kreis
{
    private:
        Dot_2D mid;
        float ratio;
        
    public:
        void create(const Dot_2D& point, float& r);
        Dot_2D getMid();
        float getRatio();
};


class Dreieck
{
    private:
        Dot_2D tri_1;
        Dot_2D tri_2;
        Dot_2D tri_3;
        
    public:
        void create(const Dot_2D& point1, const Dot_2D& point2, const Dot_2D& point3);
        float edges();
        float getEdge_1to2();
        float getEdge_1to3();
        float getEdge_2to3();
};

class Rechteck
{
    private:
        Dot_2D point;
        float length;
        float width;
        
    public:
        Dot_2D getPoint();
        float getLength();
        float getWidth();
        void create(const Dot_2D& dot,const float& len,const float& wid);
};


float umfang(Dreieck& triangle);
float umfang(Kreis& circle);
float umfang(Rechteck& rectangle);

float flaeche(Dreieck& triangle);
float flaeche(Kreis& circle);
float flaeche(Rechteck& rectangle);