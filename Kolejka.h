#ifndef ZNAM_KOLEJKA
#define ZNAM_KOLEJKA
#include <iostream>
#include <cmath>
using namespace std;

struct Queue
{
private:
int* data; //wskaznik pokazujacy na tablice
int number; //obecny rozmiar

public:
//------------konstruktor--------------
Queue();
~Queue();
Queue(const Queue &Q);
//-------------metody------------------
void Enqueue(int a);//funkcjcja wkladajaca liczbe do kolejki
void Show();//funkcja wypisujaca zawartosc kolejki
int Delete();//funkcja usuwajaca ostatni element z kolejki i zwracajaca go
void Devour();//funkcja czyszczaca kolejke
int ShowSize();//funkcja zwracajaca obecny rozmiar kolejki
int Activate();//funkcja zwracajaca z kolejki pierwsza wartosc bez usuwania jej
int Cheat();//funkcja zwracajaca ostatni element w kolejce
Queue& operator =(const Queue& Q);
bool operator ==(const Queue& Q)const;
};
#endif // ZNAM_KOLEJKA
