#include <iostream>
#include <string>

class Animal
{
public:
    Animal(const std::string &name) : name(name) {}
    virtual void Identify()
    {
        std::cout << "I am an animal: " << name << std::endl;
    }

protected:
    std::string name;
};

class Cat : public Animal
{
public:
    Cat(const std::string &name) : Animal(name) {}
    void Identify() override
    {
        std::cout << "I am a cat: " << name << std::endl;
    }
};

class Dog : public Animal
{
public:
    Dog(const std::string &name) : Animal(name) {}
    void Identify() override
    {
        std::cout << "I am a dog: " << name << std::endl;
    }
};

class Tiger : public Cat
{
public:
    Tiger(const std::string &name) : Cat(name) {}
    void Identify() override
    {
        std::cout << "I am a tiger: " << name << std::endl;
    }
};

class Zoo
{
public:
    Zoo(int max) : max_animals(max), num_animals(0)
    {
        residents = new Animal *[max];
    }
    ~Zoo() { delete[] residents; }
    void Accept(Animal *d)
    {
        if (num_animals < max_animals)
        {
            residents[num_animals++] = d;
        }
    }
    void ListAnimals()
    {
        for (int i = 0; i < num_animals; ++i)
        {
            residents[i]->Identify();
        }
    }

private:
    int max_animals;
    int num_animals;
    Animal **residents;
};

int main()
{
    Cat cat("汤姆猫");
    Dog dog("汪汪狗");
    Tiger tiger("贝乐虎");

    cat.Identify();
    dog.Identify();
    tiger.Identify();

    Zoo shanghai(3);
    shanghai.Accept(&cat);
    shanghai.Accept(&dog);
    shanghai.Accept(&tiger);

    shanghai.ListAnimals();

    return 0;
}
