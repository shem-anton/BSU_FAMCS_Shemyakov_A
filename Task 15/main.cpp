#include <cstdlib>
#include <iostream>
#include "Unit1.h"

using namespace std;

int main(int argc, char *argv[])
{
    Transport minsk;
    string a[4]={"Stop1","Stop2", "Stop3", "Stop4"};
    minsk.AddRoute(35, 2, a, a+2);
    minsk.AddRoute(38, 2, a, a+2);
    minsk.AddRoute(16, 1, a+1, a+4);
    minsk.AddRoute(18, 0, a+3, a+4);
    minsk.AddRoute(16, 1, a, a+4);
    minsk.AddStop("Stop5");
    minsk.Show();
    cout<<"There are "<<minsk.Stops()<<" stops and "<<minsk.Routes()<<" routes.";
    cout<<endl<<"Maximum routes through a stop:\n"<<minsk.MaxRouts()<<":"<<endl;
	for(auto it = minsk.GetRoutes(minsk.MaxRouts()).first; it != minsk.GetRoutes(minsk.MaxRouts()).second; ++it)
    {
           string temp="";                    
           if((*it).type == 0)
           temp = "Tram";
           else if((*it).type == 1)
           temp = "Metro";
           else if((*it).type == 2)
           temp = "Bus";
           else cout<<(*it).type;
           cout<<temp<<"  "<<(*it).number<<endl;
    }
    cout<<endl;
    
    
    cout<<"Now delete stop4:\n";
    minsk.DeleteStop("Stop4");
    minsk.Show();
    cout<<"Now there are "<<minsk.Stops()<<" stops and "<<minsk.Routes()<<" routes.\n";
	cout<<"The list of Bus stops from the number 30 to 40:\n";
	auto b =  minsk.RoutesList(2 , 30, 40);
	for(auto it = b.first; it != b.second; ++it)
		cout<<(*it)<<endl;    
    
    cout<<"\nNow delete Bus 35:\n";
    minsk.DeleteRoute(35, 2);
    minsk.Show();
    cout<<"Now there are "<<minsk.Stops()<<" stops and "<<minsk.Routes()<<" routes.\n";
    
    cout<<"\nNow add some empty stops and show them all:\n";
    minsk.AddStop("Stop4");
    minsk.AddStop("Stop0");
    minsk.Show();
    cout<<endl<<"Empty stops are:\n";
    for(auto it = minsk.EmptyStops().first; it != minsk.EmptyStops().second; ++it)
    cout<<(*it)<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
