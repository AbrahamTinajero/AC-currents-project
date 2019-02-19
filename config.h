#ifndef CONFIG_H
#define CONFIG_H

using namespace std;

#include <iostream>
void pause(){
cout << "Press any key to continue . . .";
cin.get(); 
}
#ifdef WIN32
#define CLS system("cls")
#define HLD system("pause")
#else
#define CLS system("clear")
#define HLD pause()
#endif

#endif
