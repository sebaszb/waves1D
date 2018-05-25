#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>//mas importantes
#include <string>//mas importantes
using namespace std;

int main()
{
    int a;
    cout<<"set yrange[-1:1]"<<endl;
    cout<<"set terminal png"<<endl;                                             //para que los escriba como imagenes
    for(a=1;a<2000;a++)
    {
                      //cout<<"plot "<<"'"<<a<<"L.dat"<<"'"<<" w l"<<endl;
                      //cout<<"plot "<<"'"<<a<<"DFTesp.dat"<<"'"<<" w i"<<endl;
                      cout<<"set output"<<"'"<<a<<"cx.png"<<"'"<<endl;          //para que lo escriba como imagenes
                      cout<<"plot "<<"'"<<a<<"cx.dat"<<"'"<<" w l"<<endl; 
    }
}
