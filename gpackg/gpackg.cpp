#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

// Funktion zum Installieren eines Pakets
void installPackage(const string& packageName) {
    if(packageName == "main") {
    cout << "Installed package: " << packageName << endl;
    system("cd C:/Program Files && mkdir gg-inst-main && cd gg-inst-main && git clone https://github.com/FSI211/gg.git && echo Installedpath: C:/Program Files/gg-inst-main/gg");
    }
    else if(packageName == "stdl") {
    cout << "Installed package: " << packageName << endl;  
    system("");
    }
    else {
        cout << "Package not found.\n";
    }

}



void makeenv(const string& envName) {
    cout << "Making env: " + envName;
    system(("mkdir " + envName).c_str());

    // Erstelle die Datei main.gg im neuen Ordner
    ofstream mainFile(envName + "\\main.gg");
    if (mainFile.is_open()) {
        // Füge einige Informationen zur Datei hinzu (kann nach Bedarf angepasst werden)
        mainFile << "// Main code for environment " << envName << "\n";
        mainFile << "// Add your code here\n";
        mainFile.close();
        cout << "Environment erstellt: " << envName << endl;
    } else {
        cout << "Fehler beim Erstellen der Datei main.gg\n" << endl;
    }
}

// Funktion für die Anzeige der Hilfe
void displayHelp() {
    cout << "\n";
    cout << "Verwendung:\n";
    cout << "  -install [Paketname]: Installes a package.\n";
    cout << "  -help: Shows this popup.\n";
    cout << "  -made: Shows Infos about gg\n";
    cout << "  -env [Envname]: makes an enviroment\n";
    cout << "  -clear: clears the terminal and clears the history of gpackg\n";
    cout << "  -pause: pauses the session\n";
    cout << "  -push0: pushes 0(returns 0)\n";
    cout << "  -push1: pushes 1(returns 1)\n";
    cout << "  -run: runs gg-main, (sys variables)\n";
    cout << "  .exit: exits gpackg.\n";
    cout << "\n";
}

void displaymade() {
    cout << "Infos: \n";
    cout << "   GG Lang and gpackg was created by FSI211 in the year 2023 and 2024\n";
    cout << "   It was an side project but is now a big language and could be used for some stuff\n";
}

int main(int argc, char* argv[]) {
    // Überprüfe, ob genügend Argumente übergeben wurden
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " [-install Paketname] [-help] [-made] [-env Envname] [-clear] [-push1] [-psuh0] [-pause] [-run] [.exit]\n";
        return 1;
    }

    // Überprüfe den Befehl
    string command = argv[1];
    if (command == "-install") {
        // Überprüfe, ob genügend Argumente für den Installationsbefehl vorhanden sind
        if (argc < 3) {
            cout << "Usage: " << argv[0] << " -install [Paketname]\n";
            return 1;
        }
        // Rufe die Installationsfunktion auf
        installPackage(argv[2]);
    } 
    
    else if (command == "-help") {
        // Rufe die Hilfe-Funktion auf
        displayHelp();
    }
    else if (command == "-clear") {
        system("cls");
    }

    else if (command == "-made") {
        // Rufe die Hilfe-Funktion auf
        displaymade();
    }

    else if(command == "-push1") {
        return 1;
    }

    else if(command == "-push0") {     
        return 0;
    }

    else if(command == ".exit") {
        system("exit");
    }

    else if(command == "-pause") {
        system("pause");
    }

    else if(command == "-run") {
        system("gg-main");
    }

    else if(command == "-env") {
        // Überprüfe, ob genügend Argumente für den Befehl -env vorhanden sind
        if (argc < 3) {
            cout << "Usage: " << argv[0] << " -env [Envname]\n";
            return 1;
        }
        // Rufe die Funktion makeenv auf
        makeenv(argv[2]);
    }
    
    else {
        cout << "Unbekannter Befehl: " << command << endl;
        return 1;
    }

    return 0;
}
