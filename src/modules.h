// Includes
#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <string>

//Namespaces
using namespace std;



//Modules
class Modules
{
    public:
        //Game module
        string game = "game module";
        bool game_activ = false;

        void pack()
        {
            cout << game;
        }
};
