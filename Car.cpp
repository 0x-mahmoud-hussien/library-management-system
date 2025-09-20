/*#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string maker;
    int model;
    int price;
    string color;

public:
    // Constructor افتراضي
    Car()
    {
        maker = "Unknown";
        model = 0;
        price = 0;
        color = "Unspecified";
    }

    // Constructor مع باراميترات
    Car(string m, int mo, int pr, string c)
    {
        maker = m;
        model = mo;
        price = pr;
        color = c;
    }

    string get_maker()
    {
        return maker;
    }
    int get_model()
    {
        return model;
    }
    int get_price()
    {
        return price;
    }
    string get_color()
    {
        return color;
    }
};

int main()
{
    // باستخدام constructor الافتراضي
    Car c1;
    cout << "Car 1 (Default):" << endl;
    cout << "Maker: " << c1.get_maker() << endl;
    cout << "Model: " << c1.get_model() << endl;
    cout << "Price: " << c1.get_price() << endl;
    cout << "Color: " << c1.get_color() << endl;

    cout << endl;

    // باستخدام constructor مع باراميترات
    Car c2("Honda", 2023, 10000, "Yellow");
    cout << "Car 2 (Parameterized):" << endl;
    cout << "Maker: " << c2.get_maker() << endl;
    cout << "Model: " << c2.get_model() << endl;
    cout << "Price: " << c2.get_price() << endl;
    cout << "Color: " << c2.get_color() << endl;
}*/


#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string maker;
    int model;
    int price;
    string color;

public:
    Car(string m, int mo, int pr, string c) : maker(m), model(mo), price(pr), color(c)  
    {

    }

    string get_maker()
    {
        return maker; 
    }
    int get_model() 
    { 
        return model; 
    }
    int get_price() 
    { 
        return price; 
    }
    string get_color() 
    { 
        return color; 
    }
    
};

int main()
{
    string maker, color;
    int model, price;

    cout << "Enter Maker: ";
    getline(cin, maker);

    cout << "Enter Model: ";
    cin >> model;

    cout << "Enter Price: ";
    cin >> price;

    cin.ignore(); // عشان نمسح \n قبل string جديد
    cout << "Enter Color: ";
    getline(cin, color);

    // ندّي القيم للـ constructor
    Car c1(maker, model, price, color);

    cout << "\nCar Details:\n";
    cout << "Maker: " << c1.get_maker() << endl;
    cout << "Model: " << c1.get_model() << endl;
    cout << "Price: " << c1.get_price() << endl;
    cout << "Color: " << c1.get_color() << endl;
}