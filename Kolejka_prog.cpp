#include <iostream>
#include "Kolejka.h"
#include <stdexcept>
using namespace std;

int main()
{
Queue q;
q.Enqueue(8);
q.Enqueue(7);
q.Enqueue(69);
q.Show();
q.Delete();
q.Show();
q.Devour();
try
{
    q.Delete();
    q.Activate();
    q.Cheat();
}
catch(exception &e)
{cout << e.what();}
q.Show();
cout << "Ilosc oczekujacych: " << q.ShowSize() << endl;;
q.Enqueue(8);
q.Enqueue(7);
q.Enqueue(69);
cout << "Ilosc oczekujacych: " << q.ShowSize() << endl;
cout << "Aktywacja kolejki: " << endl;
cout << q.Activate() << endl;
q.Show();
cout << "Ilosc oczekujacych: " << q.ShowSize() << endl;;
cout << "Ostatni element: " << q.Cheat() << endl;
Queue p(q);
p.Show();
if (p==q)
    cout << "nice\n";
p.Devour();
p=q;
if (p==q)
    cout << "nice x2\n";

return 0;
}
