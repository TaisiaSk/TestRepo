#include <iostream>

class Triangle
{
private:
    struct Point
    {
        double x;
        double y;
   };
    Point _point1;
    Point _point2;
    Point _point3;
public:
    //Constructors
    Triangle()
    {
        _point1.x = 0;
        _point1.y = 1;
        _point2.x = sqrt(3)/2;
        _point2.y = -0.25;
        _point3.x = -sqrt(3)/2;
        _point3.y = -0.25;
    }
    Triangle(double coordinates[6])
    {
        _point1.x = coordinates[0];
        _point1.y = coordinates[1];
        _point2.x = coordinates[2];
        _point2.y = coordinates[3];
        _point3.x = coordinates[4];
        _point3.y = coordinates[5];
    }

     //Methods   
    double Square() const
    {
        double square=0.0;
        square = 0.5 * ((_point2.x - _point1.x)*(_point3.y - _point1.y) - 
                        (_point3.x - _point1.x)*(_point2.y - _point1.y));
        return square;
    }

    double Side(Point a, Point b) const
    {
        double side = sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
        return side;
    }

    double Perimeter() const
    {
        double side1 = Side(_point1, _point2);
        double side2 = Side(_point1, _point3);
        double side3 = Side(_point3, _point2);
        
        return side1 + side2 + side3;
    }

    void CheckEquilateral() const
    {
        double side1 = Side(_point1, _point2);
        double side2 = Side(_point1, _point3);
        double side3 = Side(_point3, _point2);
        if (side1 == side2 == side3)
            std::cout << "Ya ravnostoronniy!\n";
        else
            std::cout << "Ya ne idealen\n";
    }

    void Print() const
    {
        std::cout << "Pervaya vershina: ("<<_point1.x<<","<<_point1.y<<")\n";
        std::cout << "Vtoraya: ("<<_point2.x<<","<<_point2.y<<")\n";
        std::cout << "Tretia: (" << _point3.x << "," << _point3.y << ")\n";
    }

};

int main()
{
    Triangle tr;
    tr.Print();

    double coordinates[6];
    double t;
    std::cout << "Vvedite koordinati 3 tochek: ";
    for (size_t i = 0; i < 6; i++)
    {
        std::cin >> t;
        coordinates[i] = t;
    }
    Triangle tri(coordinates);
    tri.CheckEquilateral();
    std::cout << "Perimeter " << tri.Perimeter() << "\n";
    std::cout << "Square " << tri.Square() << "\n";
    tri.Print();
    
    system("pause");
    return 0;
}