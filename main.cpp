#include <cstdlib>
#include <iostream>

using namespace std;
/*User defined header file*/
#include "acurrent.h"
#include "config.h"

/*Function prototype*/
int menu();

int main(int argc, char *argv[])
{
ACcurrent cur1, cur2;
int operation;
double r;

cin >> cur1 >> cur2;
do{
operation = menu();
switch(operation){
case 1:
//system("cls");
cout << "\n\t" << cur1 << " + "<< cur2 << " = " << (cur1 + cur2)
<< endl << endl;
system("pause");
break;
case 2:
cout << "\n\t" << cur1 << " - "<< cur2 << " = " << (cur1 - cur2)
<< endl << endl;
system("pause");
break;
case 3:
cout << "\nEnter resistance: ";
cin >> r;
cout << "\n\t" << cur1 << " * " << r << ((unsigned char)234) << " = " 
<< (cur1 * r) << endl << endl;
system("pause");
break;
case 4:
cout << "\nExiting Program Now . . .\n\n";
break;
}
}while(operation != 4);

system("PAUSE");
return EXIT_SUCCESS;
}

int menu(){
int selection;

do{
CLS; //system("cls");
cout << "\n\n\tSelect operation:\n"
<< "\t\t 1) Add currents\n"
<< "\t\t 2) Substract currents\n"
<< "\t\t 3) Multiple current by resistance\n"
<< "\t\t 4) Exit Program\n"
<< "\t\tEnter selection [1-4]: ";
cin >> selection;
}while(selection < 1 || selection > 4);
return selection;
}
