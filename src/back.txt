// Includes
#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <time.h>
#include "modules.h"
#include "fast.h"
//Namespaces
using namespace std;

//Main



int main(void)
{

//Test things
int argc; 
char** argv;
int y;

// .h access


    //Get Modules
Modules mod;

    // Fast
cleans clean;


//File extension
string gg = ".gg";

//Strings, ints, just some things i need

    int offset;
    string line;
    string runner = argv[1];
    bool lowmem = false;
    bool isloudest = false;

//Big things:

    string space = " ";

//Big things;

// Read File:

    ofstream the_file;

// Read File;

//Keyowrds
    string print = "say";
    string done = "done";
    string use = "use";
    string wait = "wait";
    string ret = "ret 0";
    string enl = "endline";
    string func = "func";
    string mem = "clsmem";
    string main_ = "main";
    string dev = "dev";
    string nt = "not";
    string mkfile = "makefile"; 
    string mkfiletxt = "makefiletxt"; 
    string printvar = "sayvar";
    string cmd = "cmd";
    string orf = "or";
    string execstn = "./";
    string pause = "pause"; 
    string lin1 = "line";


    
//Memory access

    //Find Window
    string fnwin = "findwin";
    string fnwintitle = "gg.exe";

    //GetAccess

//OS:

    string defi = "defi";
    string find = "find"; 
    string linux = "linux";
    string windows = "windows";
    string mac = "mac"; 

//OS;

//Booleans:

    bool main_func = false;
    bool no = false;
    bool fileopen = false;
    bool var_made = true;

//Booleans;


//Variable Keywords
    string var = "var";
    string normi1 = "x";
    string normi2 = "y";


//ErrorWords
    string pr = "SAY";
    string VAR = "VAR";


//Line Sub:



//Line Sub;         

//Token-Words (i don't like this.)
    
    string min = "-";
    string plu = "+";
    string div = ":";
    string multi = "*";
    string smaller = "<";
    string bigger = ">";

    string is = "=";
    string semi = ";";
    string hash = "#";


    string bra1 = "(";
    string bra2 = ")";
    string brac1 = "[";
    string brac2 ="]";
    string brack1 = "{";
    string brack2 = "}";

    string slash = "/";
    string annd = "&";
    string percent = "%";
    string by = ",";
    string loud = "!";
    string dot = ".";
    string tab = "    ";

    

//Run file


    cout << "Enter file name to run  (without .gg): ";
    cin >> runner;
    cout << "\n";

    ifstream Myfile;

    Myfile.open(runner + gg);
    
    //Main Process

    if (Myfile.is_open())
    {
        while (!Myfile.eof())
        {
            //Get the lines
            getline(Myfile, line);


//Print statements:

            if ((offset = line.find(print, 0)) != string::npos)
            {
                cout << line.substr(offset + 4) << "\n" << endl;
            }

//Error statements:
            else if((offset = line.find(pr, 0)) != string::npos)
            {
                cout << "We don't write 'SAY', we write 'say', error 02 can not compile.\n";
            }


            else if((offset = line.find(VAR, 0)) != string::npos)
            {
                cout << "We don't write 'VAR', we write 'var', error can not compile. \n";
            }
//Error statements;

//1.1 Staff:

            else if((offset = line.find(loud, 0)) != string::npos)
            {
                isloudest = true;
            }

//1.1 Staff;


//Cmd commands:

            else if((offset = line.find(cmd, 0)) != string::npos)
            {
                string exec = line.substr(offset + 3);
                system(("" + exec).c_str());
            }

            else if((offset = line.find(pause + space + lin1, 0)) != string::npos)
            {
                system("pause");
            }

//Cmd commands;


//Read File:

            else if((offset = line.find(mkfile, 0)) != string::npos)
            {
                fileopen = true;
                string fi = line.substr(offset + 8);

                the_file.open(fi);

            }

            else if((offset = line.find(mkfiletxt, 0)) != string::npos && fileopen == true)
            {
                string filine = line.substr(offset + 11);
                the_file << filine;
                the_file.close();
            }               

//Read File;


//Functions(wichtig):
            else if((offset = line.find(func + bra1 + main_ + bra2 + div, 0)) != string::npos)
            {
                cout << bra1 << "main func" << bra2 << "\n";
                main_func = true;

                getline(Myfile, line);

                // Hier kannst du weitere Bedingungen für diese spezielle Funktion hinzufügen
                if ((offset = line.find("    gg.serv;", 0)) != string::npos)
                {
                    class m {
                        public:
                            void ma() {
                                cout << "executed\n";
                            }
                    };

                    m M;
                    M.ma();
                }
                else {
                    cout << "gcoulderr: Couldn't execute func.\n";
                }
            }

            else if(main_func == true)
            {
                string fistring = line.substr(offset + 12);
            }

            
            else if((offset = line.find(hash + nt, 0)) != string::npos)
            {

                if(no == true)
                {
                    line.clear();
                    return 0;
                }
            }

//Functions(wichtig);


//Variables:
            else if((offset = line.find(var, 0)) != string::npos && var_made == false)
            {
                var_made == true;
                int fi = stoi(line.substr(offset + 8));
                int num = fi;

                string fistring = line.substr(offset + 5);

                if((offset = line.find(printvar + fistring, 0)) != string::npos && var_made == true)
                {
                    cout << fistring << "=" << fi << "\n";
                }

                else if((offset = line.find(printvar + fistring, 0)) != string::npos && var_made == false)
                {
                    cout << "Error: 05, var not found\n";
                }
            }
//Variables;

//FindWindow:

//FindWindow;

//Waiting:
            else if((offset = line.find(wait, 0)) != string::npos)
            {
                int fi = stoi(line.substr(offset + 4));
                sleep(fi);
            }
//Waiting;

//OS:

            else if((offset = line.find(hash + linux, 0)) != string::npos)
            {
                #define LINUX
                ofstream linux_;
                linux_.open("linux.gg");
                linux_ << "#defi linux, #defi not windows, defi not mac, fun(main)";
                linux_.close();
            }

            else if((offset = line.find(hash + windows, 0)) != string::npos)
            {
                #define WINDOWS
                ofstream windows_;
                windows_.open("windows.gg");
                windows_ << "#defi windows, #defi not linux, defi not mac, fun(main)";
                windows_.close();
            }

            else if((offset = line.find(hash + mac, 0)) != string::npos)
            {
                #define MAC
                ofstream mac_;
                mac_.open("mac.gg");
                mac_ << "#defi mac, #defi not linux, defi not windows, fun(main)";
                mac_.close();
            }

//OS;


//Returning, closing and ending:
            else if((offset = line.find(ret, 0)) != string::npos)
            {
                int fi = stoi(line.substr(offset + 3));
                return fi;
            }

            else if((offset = line.find(done, 0)) != string::npos)
            {                
                cout << "done" << "\n" << endl;
                int fi = stoi(line.substr(offset + 4));
                return fi;
                Myfile.close();
            }

            else if((offset = line.find(enl, 0)) != string::npos)
            {
                line.end();
            }

//Returning, closing and adding;

//Other staff:

            else if((offset = line.find(mem, 0)) != string::npos)
            {
                lowmem = true;
            }


            else if((line.empty()) != string::npos) 
            {
                cout << "";
            }

            else if((offset = line.find(dev, 0)) != string::npos)
            {
                ofstream file_;
                file_.open("dev.txt");
                file_ << "This was made by FSI in C++ in 2023-2024 and it was an 3 am project";
                file_.close();
            }

            
//Other staff;


//Errors:
            else if((offset = line.find(func + space + main_ + bra1 + bra2, 0)) != string::npos)
            {
                cout << "error 04 nothing is in the func\n";
            }

            else if((offset = line.find(nt, 0)) != string::npos)
            {
                cout << "Can't compile: error 05, not statement is not compitable (not is not standalone)";
            }

            else
            {
                cout << "File cannot compile\n";
            }
//Errors            

            if(lowmem == true)
            {
                clean.clearmem();
            }


        }
        Myfile.close();
    }


    else
        cout << "Error 01: File opening error" << endl;
    system("pause");
    return 0;
}