#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age;
    string species;
    int weight;
    string color;
    string diet;
    int legs;
public:
    Animal(string n, int ag, string sp, int wh, string co, string di, int le)
    {
        name = n;
        age = ag;
        species = sp;
        weight = wh;
        color = co;
        diet = di;
        legs = le;
    }
    virtual void sound() = 0;
    virtual string get_Eat() = 0;
    virtual string get_Move() = 0;
    virtual void print()
    {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "Species = " << species << endl;
        cout << "Weight = " << weight << endl;
        cout << "Color = " << color << endl;
        cout << "Diet = " << diet << endl;
        cout << "Legs = " << legs << endl;
    }
};

class Dog : public Animal
{
private:
    string breed;
    string bark_Volume;
    bool is_Trained;
public:
    Dog(string n, int ag, string sp, int wh, string co, string di, int le,
        string br, string bv, bool iT) : Animal(n, ag, sp, wh, co, di, le)
    {
        breed = br;
        bark_Volume = bv;
        is_Trained = iT;
    }
    void sound()
    {
        cout << "WOOF" << endl;
    }
    string get_Eat()
    {
        return "Meat";
    }
    string get_Move()
    {
        return "Running On 4 Legs";
    }
    void print()
    {
        Animal::print();
        cout << "Breed = " << breed << endl;
        cout << "Bark Volume = " << bark_Volume << endl;
        cout << "Is Trained = " << (is_Trained ? "Yes" : "No") << endl;
        cout << "==================================" << endl;
    }
};

class Cat : public Animal
{
private:
    string breed;
    string favorite_Toy;
    bool is_InDoor;
public:
    Cat(string n, int ag, string sp, int wh, string co, string di, int le,
        string br, string ft, bool id) : Animal(n, ag, sp, wh, co, di, le)
    {
        breed = br;
        favorite_Toy = ft;
        is_InDoor = id;
    }
    void sound()
    {
        cout << "Meow" << endl;
    }
    string get_Eat()
    {
        return "Meat";
    }
    string get_Move()
    {
        return "Jump And Climb";
    }
    void print()
    {
        Animal::print();
        cout << "Breed = " << breed << endl;
        cout << "Favorite Toy = " << favorite_Toy << endl; 
        cout << "Is Indoor = " << (is_InDoor ? "Yes" : "No") << endl;
        cout << "==================================" << endl;
    }
};

int main()
{
    Animal *ani_ptr;
    Dog d1("Dog", 5, "Canine", 15, "Black", "Omnivore", 4, "Husky", "Loud", true);
    Cat c1("Cat", 2, "Feline", 5, "White", "Carnivore", 4, "Persian", "Ball", true);

    ani_ptr = &d1;
    ani_ptr->sound();
    cout << "Eat: " << ani_ptr->get_Eat() << endl;
    cout << "Move: " << ani_ptr->get_Move() << endl;
    ani_ptr->print();
 
    ani_ptr = &c1;
    ani_ptr->sound();
    cout << "Eat: " << ani_ptr->get_Eat() << endl;
    cout << "Move: " << ani_ptr->get_Move() << endl;
    ani_ptr->print();

    return 0;
}




class Animal
{
protected:
    string name;
    int age;
    string species;
    int weight;
    string color;
    string diet;
    int legs;

public:
    Animal(string n, int ag, string sp, int wh, string co, string di, int le)
        : name(n), age(ag), species(sp), weight(wh), color(co), diet(di), legs(le) {}

    virtual void sound() const = 0;
    virtual string get_Eat() const = 0;
    virtual string get_Move() const = 0;

    virtual void print() const
    {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "Species = " << species << endl;
        cout << "Weight = " << weight << endl;
        cout << "Color = " << color << endl;
        cout << "Diet = " << diet << endl;
        cout << "Legs = " << legs << endl;
    }

    virtual ~Animal() = default; // destructor افتراضي
};

class Dog : public Animal
{
private:
    string breed;
    int bark_Volume;  // خليته int زي ما حطيت في الـ constructor
    bool is_Trained;

public:
    Dog(string n, int ag, string sp, int wh, string co, string di, int le,
        string br, int bv, bool iT)
        : Animal(n, ag, sp, wh, co, di, le), breed(br), bark_Volume(bv), is_Trained(iT) {}

    void sound() const override
    {
        cout << "WOOF" << endl;
    }

    string get_Eat() const override
    {
        return "Meat";
    }

    string get_Move() const override
    {
        return "Running on 4 Legs";
    }

    void print() const override
    {
        Animal::print();
        cout << "Breed = " << breed << endl;
        cout << "Bark Volume = " << bark_Volume << endl;
        cout << "Is Trained = " << (is_Trained ? "Yes" : "No") << endl;
        cout << "==================================" << endl;
    }
};

class Cat : public Animal
{
private:
    string breed;
    string favorite_Toy;
    bool is_InDoor;

public:
    Cat(string n, int ag, string sp, int wh, string co, string di, int le,
        string br, string ft, bool id)
        : Animal(n, ag, sp, wh, co, di, le), breed(br), favorite_Toy(ft), is_InDoor(id) {}

    void sound() const override
    {
        cout << "Meow" << endl;
    }

    string get_Eat() const override
    {
        return "Meat";
    }

    string get_Move() const override
    {
        return "Jump and Climb";
    }

    void print() const override
    {
        Animal::print();
        cout << "Breed = " << breed << endl;
        cout << "Favorite Toy = " << favorite_Toy << endl;
        cout << "Is Indoor = " << (is_InDoor ? "Yes" : "No") << endl;
        cout << "==================================" << endl;
    }
};

int main()
{
    Animal *ani_ptr;

    Dog d1("Dog", 5, "Canine", 15, "Black", "Omnivore", 4, "Husky", 8, true);
    Cat c1("Cat", 2, "Feline", 5, "White", "Carnivore", 4, "Persian", "Ball", true);

    ani_ptr = &d1;
    ani_ptr->sound();
    cout << "Eats: " << ani_ptr->get_Eat() << endl;
    cout << "Moves: " << ani_ptr->get_Move() << endl;
    ani_ptr->print();

    ani_ptr = &c1;
    ani_ptr->sound();
    cout << "Eats: " << ani_ptr->get_Eat() << endl;
    cout << "Moves: " << ani_ptr->get_Move() << endl;
    ani_ptr->print();

    return 0;
}