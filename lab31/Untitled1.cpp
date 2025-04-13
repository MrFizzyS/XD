#include <iostream>
using namespace std;
class flat
{  
private:
  string adresa1;
  int floor1;
  int room1;
  float area1;
public:
  flat(){}
  flat(string adr,int floor,int room=2,float area=55.0)
  {
    adresa1=adr;
    floor1=floor;
    room1=room;
    area1=area;
  }
  void display()
  {
    cout<<"adresa: "<<adresa1<<endl<<"floor: "<<floor1<<endl<<"room: "<<room1<<endl<<"area: "<<area1<<endl;
  }
  void cin_obg(string adr,int floor,int room=2,float area=55.0)
  {
    adresa1=adr;
    floor1=floor;
    room1=room;
    area1=area;
  }
  int floor2(){return floor1;}
  int room2(){return room1;}
  float area2(){return area1;}
};

int main()
{
  int n, floor, room, limit1, limit2, limitroom, limitarea;
  string adresa;
  float area;
  cout<<"Input n: ";
  cin>>n;
  flat* home=new flat[n];
  for(int i=0;i<n;i++)
  {
  cout<<"Input adresa, poverx, kimnata, ploscha: ";
  cin>>adresa>>floor>>room>>area;
  cout<<endl;
  home[i].cin_obg(adresa,floor,room,area);
}
  for(int i=0;i<n;i++)
  {
    home[i].display();
    cout<<endl;
  }
  cout<<"Input promizhok poverxy limit 1,2, room, area: ";
  cin>>limit1>>limit2>>limitroom>>limitarea;
  cout<<endl;
  for(int i=0;i<n;i++)
  {
  if(home[i].floor2()>=limit1 && home[i].floor2()<=limit2 && home[i].room2()==limitroom && home[i].area2()<=limitarea)
  {
    home[i].display();
  }
  else if(i==n-1)
  {
  	cout<<"Ne Znaideno";
  }
  }
  return 0;
}
