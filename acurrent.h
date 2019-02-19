#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*Global Declaration and Value Assignment*/
const double D2R = (2*3.141592)/360;
const double R2D = 360/(2*3.141592);

class ACcurrent{
/*1. friend member function is neither private or public
2. can be anywhere in the class declaration
3. allows external functions to access the private 
members of a class i.e., the insertion and extraction operators*/
friend istream &operator>>(istream &inst, ACcurrent &c); 
friend ostream &operator<<(ostream &outst, const ACcurrent &c); 
private:
double mag, phase;
double real, imag;
void setRect();
void setPolar();
public:
ACcurrent(double m=0, double p=0);
ACcurrent operator-(const ACcurrent & c) const;
ACcurrent operator+(const ACcurrent & c) const;
ACcurrent operator*(double) const;
int getCoord();
};
