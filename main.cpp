#include <iostream>
#include "Menu.h"
#include "Timer.h";



using namespace std;

Timer *Timer::instance = 0;

int main() {

    Menu *menu = new Menu();
    menu->mode_interface();

    return 0;
}
