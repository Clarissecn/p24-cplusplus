#include <iostream>
#include <vector>

class Shape {
    int abscisse;
    int ordonnee;
    int color;
    shape(int x, int y, int color) : abscisse(x), ordonnee(y), color(color){}
    void move(){}
    void area(){}
    
}

class Circle : public shape {
    int radius;
    public :
        Circle(int x, int y, int color, int radius) : abscisse()
        void area(){
            area = 3.14*(r**2);
    }
}

class Rectangle : public shape {
    int longueur;
    int largeur;
}

int main(){
    Circle c (0.5, 4,);
    Rectangle r();
    std::vector<?>v;
    v.pushback(&c);
    v.pushback(&r);
    
}

#include <iostream>
#include <vector>

class Form {
    int abscisse;
    int ordonnee;
    public:
        Form(int x, int y) : abscisse(x), ordonnee(y)
        {
        };

        void move(int new_x, int new_y)
        {
            abscisse = new_x;
            ordonnee = new_y;
        };
};

class Square : public Form
{
    int side;

public:
    Square(int x, int y, int n) : side(n), Form(x, y)
    {
    };

    float surface()
    {
        return side * side;
    };
};

class Rectangle : public Form
{
    int width;
    int height;

public:
    Rectangle(int x, int y, int a, int b) : width(a), height(b), Form(x, y)
    {
    };

    float surface()
    {
        return width * height;
    };
};

class Circle : public Form
{
    int radius;

public:
    Circle(int x, int y, int r) : radius(r), Form(x, y)
    {
    };

    float surface()
    {
        return 3.14 * radius * radius;
    };
};

int main()
{
    Circle c(10, 20, 4);
    Rectangle r(20, 30, 30, 60);
    std::vector<Form>v;
    v.push_back(c);
    v.push_back(r);
    //s = find_at_position(2,3,v); //renvoie la première forme qu'elle voit à la position (2,3)
    //s.surface();
    v[0].move(4,6);
    v[1].move(2,8);
    std::cout<<v[0]->surface()<<std::endl;
    std::cout<<v[1]->surface()<<std::endl;
    return 0;

}