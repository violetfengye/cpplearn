#include <bits/stdc++.h>
using namespace std;

class Building
{
protected:
    int floors;
    int rooms;
    float area;

public:
    Building(int floors, int rooms, float area)
    {
        this->floors = floors;
        this->rooms = rooms;
        this->area = area;
    }

    void display()
    {
        cout << "Floors: " << floors << endl;
        cout << "Rooms: " << rooms << endl;
        cout << "Area: " << area << " sq. ft." << endl;
    }
};

class Home_Arch : public Building
{
private:
    int bedrooms;
    int livingRooms;
    int bathrooms;
    int kitchens;

public:
    Home_Arch(int floors, int rooms, float area, int bedrooms, int livingRooms, int bathrooms, int kitchens)
        : Building(floors, rooms, area)
    {
        this->bedrooms = bedrooms;
        this->livingRooms = livingRooms;
        this->bathrooms = bathrooms;
        this->kitchens = kitchens;
    }

    void display()
    {
        Building::display();
        cout << "Bedrooms: " << bedrooms << endl;
        cout << "Living Rooms: " << livingRooms << endl;
        cout << "Bathrooms: " << bathrooms << endl;
        cout << "Kitchens: " << kitchens << endl;
    }
};

class Office_Building : public Building
{
private:
    int offices;
    int meetingRooms;

public:
    Office_Building(int floors, int rooms, float area, int offices, int meetingRooms)
        : Building(floors, rooms, area)
    {
        this->offices = offices;
        this->meetingRooms = meetingRooms;
    }

    void display()
    {
        Building::display();
        cout << "Offices: " << offices << endl;
        cout << "Meeting Rooms: " << meetingRooms << endl;
    }
};

int main(void)                                      
{
    Home_Arch home(5, 10, 3000.0, 3, 1, 4, 2);
    Office_Building office(10, 50, 10000.0, 20, 5);

    cout << "Home Architecture Details:" << endl;
    home.display();

    cout << "\nOffice Building Details:" << endl;
    office.display();

    return 0;
}