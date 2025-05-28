#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class figure 
{
public:
    virtual double area() const = 0;
    virtual double perim() const = 0;
    virtual void output() const = 0;
    virtual ~figure() {}
};

class rectangle : public figure
{
    private:
    float width,height;

    public:
    rectangle(float w, float h)
    {
        width = w;
        height = h;
    }

    double area() const override
    {
        return width*height;
    }

    double perim() const override
    {
        return 2*(width+height);
    }

    void output() const override
    {
        cout<<"Rectangle: "<<endl<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Height "<<height<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perim()<<endl<<endl;
    }
};

class triangle : public figure
{
    private:
        float side1, side2, side3;
    
    public:
        triangle(float s1, float s2, float s3)
        {
            side1 = s1;
            side2 = s2;
            side3 = s3;
        }

    double area() const override
    {
        double p = perim()/2;
        return sqrt(p*(p-side1)*(p-side2)*(p-side3));
    }
    double perim() const override
    {
        return side1+side2+side3;
    }

    void output() const override{
        cout<<"Triangle: "<<endl<<endl;
        cout<<"Sides: "<<side1<<" "<<side2<<" "<<side3<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perim()<<endl<<endl;
    }
};

class circle : public figure
{
    private:
    double radius;

    public:
    circle(float r)
    {
        radius = r;
    }
    double area() const override
    {
        return 3.14 * radius * radius;
    }
    double perim() const override
    {
        return 2 * 3.14 * radius; 
    }

    void output() const override
    {
        cout<<"Circle: "<<endl<<endl;
        cout<<"Radius: "<<radius<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perim()<<endl<<endl;

    }
};

int main()
{
    vector<figure*> figures;

    figures.push_back(new rectangle(8,20));
    figures.push_back(new triangle(3,4,5));
    figures.push_back(new circle(8));

    for(int i=0;i<figures.size();i++){
        figures[i]->output();
    }

    return 0;
}