#include "acurrent.h"

ACcurrent::ACcurrent(double m, double p)
{
mag = m; phase = p; setRect();
}

int ACcurrent::getCoord(){
int selection;
do{
cout << "\nSelect:\n\t1) AC current in polar coordinates ";
cout << "\n\t2) AC current in rectanglar coordinates ";
cout << "\n\tEnter Selection: ";
cin >> selection;
}while(selection != 1 && selection != 2);
return selection;
}

void ACcurrent::setRect(){
real = mag*cos(phase*D2R);
imag = mag*sin(phase*D2R);
}

void ACcurrent::setPolar(){
mag = sqrt(real*real+imag*imag);
if((real == 0) && (imag == 0))
phase = 0;
else
phase = atan(imag/real)*R2D;
}

ACcurrent ACcurrent::operator-(const ACcurrent & c)const{
ACcurrent temp;
double treal, timag;

treal = mag*cos(phase*D2R) - c.mag*cos(c.phase*D2R);
timag = mag*sin(phase*D2R) - c.mag*sin(c.phase*D2R);

temp.mag = sqrt(treal*treal+timag*timag); 
if((treal == 0) && (timag == 0))
temp.phase = 0;
else
temp.phase = atan(timag/treal)*R2D;
return temp;
}

ACcurrent ACcurrent::operator+(const ACcurrent & c)const{
ACcurrent temp;
double treal, timag;

treal = mag*cos(phase*D2R) + c.mag*cos(c.phase*D2R);
timag = mag*sin(phase*D2R) + c.mag*sin(c.phase*D2R);

temp.mag = sqrt(treal*treal+timag*timag); 
if((treal == 0) && (timag == 0))
temp.phase = 0;
else
temp.phase = atan(timag/treal)*R2D;
return temp;
}

ACcurrent ACcurrent::operator*(double r) const{
ACcurrent temp;

temp.mag = mag*r;
temp.phase = phase;
temp.setRect();
return temp;
}

istream &operator>>(istream &inst, ACcurrent &c){
int choice = c.getCoord(); /* call top menu level and return selection */

if(choice == 1)
{
cout <<"\nEnter magnitude: ";
inst >> c.mag;
cout <<"\nEnter phase shift: ";
inst >> c.phase;
c.setRect();
}
else if (choice == 2)
{
cout <<"\nEnter real part: ";
inst >> c.real;
cout <<"\nEnter imaginary part: ";
inst >> c.imag;
c.setPolar();
}
return inst; 
}

ostream &operator<<(ostream &outst, const ACcurrent &c){
outst << fixed << setprecision(2)
<< "(" << setw(6) << c.mag
<< ", " << setw(6) << c.phase
<< ((unsigned char)248) << ")[A]";
return outst;
}
