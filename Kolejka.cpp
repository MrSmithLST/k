#include <iostream>
#include <stdexcept>
#include "Kolejka.h"
using namespace std;

Queue::Queue()
{
    number = 0;
    data = nullptr;
}

Queue::Queue(const Queue &Q)
{
    number = Q.number;
    int* x = new int [Q.number];
    for (int i=0; i<Q.number; i++)
        x[i]=Q.data[i];
    data = x;
}

Queue::~Queue()
{
    if(number>0)
    {
        number = 0;
        delete [] data;
    }
}

void Queue::Enqueue(int a)
{
    int* x = new int [number+1];
    for (int i=0; i<number; i++)
        x[i] = data[i];
    x[number] = a;
    delete [] data;
    data = x;
    number++;
}

int Queue::Delete()
{
    if(number==0)
        throw logic_error("Error:\n");
    int a = data[number];
    number--;
    int* x = new int [number];
    for (int i=0; i<(number); i++)
        x[i] = data[i];
    delete [] data;
    data = x;
    return a;
}

void Queue::Show()
{
    if (data==nullptr)
    {
        cout << "Kolejka jest pusta;" << endl;
    }
    else
    {
        cout << "Kolejka ma postac: " << endl;
        for (int i=0; i<number; i++)
        {
            cout << i+1 << " element kolejki: " << data[i] << ";";
            if (i==0)
                cout << " (ten element zostanie pobrany przy najblizszej aktywacji kolejki)";
            cout << endl;
        }
    }
}

void Queue::Devour()
{
    number = 0;
    delete [] data;
    data = nullptr;
}

int Queue::ShowSize()
{
    return number;
}

int Queue::Activate()
{
    if (number==0)
        throw logic_error("Error:\n");
    return data[0];
}

int Queue::Cheat()
{
    if (number==0)
        throw logic_error("Error:/n");
    return data[number-1];
}

Queue& Queue::operator =(const Queue& Q)
{
    if(data!=Q.data)
    {
        number = Q.number;
        delete [] data;
        if(Q.number==0)
            data=nullptr;
        else
        {
            data = new int[Q.number];
            for (int i=0; i<number; i++)
                data[i]=Q.data[i];
        }
    }
    return *this;
}

bool Queue::operator ==(const Queue& Q)const
{
    if (data==Q.data)return true;
    if (number!=Q.number)return false;
    for (int i=0; i<number; i++)
    {
        if (data[i]!=Q.data[i])
            return false;
    }
    return true;

}

