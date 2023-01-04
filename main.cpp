#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <vector>

using namespace std;

// An enumeration is a user-defined data type that consists of integral constants.
enum Position { LEFT, CENTER, RIGHT };
string pageCentering(Position, string, int&);
int randomizer();
void formater(string);
string printTopBorder(int);
string printBottomBorder(int);
int decider();
void menu(int);
void worldHistory();
bool bulletPoints();
bool items();
bool npcs();

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int pageLength = 73;
    // 'file' can be any name. in quotes " " " is the actual file name
    // ios:: executes all 3 at once.
    ofstream file("test.doc", ios::in | ios::out | ios::app);
    if (!file.is_open())
        cout << "Error opening file..." << endl;
    else
    {
        cout << "Journal opened successfully!" << endl;
        string date, desc;
        // get the numbers from the user
        cout << "Enter the date and a title the session (ex. 1/1/2022 - Test Entry): ";
        getline(cin, date);
        cout << "Enter the description for that session:" << endl;
        getline(cin, desc);

        menu(decider());

        // write them to the file, each on a separate line
        file << setfill('=') << setw(pageLength) << "=" << endl;
        //string datePrint =  print(CENTER, date, pageLength);
        file << pageCentering(CENTER, date, pageLength) << endl;
        //file << datePrint << endl;
        file << desc << endl;

        file.close();
    }
    return 0;
}
bool bulletPoints()
{

}
bool items()
{

}
bool npcs()
{

}
void worldHistory()
{
    string worldTitle = "»»———-World History———-««";
    string worldDesc;
    cout << "Please enter notes about the world history:" << endl;
    getline(cin, worldDesc);

}

void menu(int choice)
{
    switch (choice)
    {
    case 1:
        worldHistory();
        break;
    case 2:
        bulletPoints();
        break;
    case 3:
        items();
        break;
    case 4:
        npcs();
        break;
    default:
        break;
    }
}
int decider()
{
    char yesNo;
    int option;
    char retry = 'T';
    while (retry == 'T' || retry == 't')
    {
        cout << "Any additional notes (Y/N)?: ";
        cin >> yesNo;
        char Y, y, N, n;
        if (yesNo == 'Y' || yesNo == 'y')
        {
            while (option > 4 || option <= 0)
            {
                cout << "Please select an option: \n";
                cout << "1 - World History\n2 - Bullet Points\n3 - Items\n4 - NPCs\n";
                cin >> option;
                cin.ignore();
                if (option > 4 || option <= 0)
                    cout << "Invalid option.\n";
            }
            break;
        }
        else if ( yesNo == 'N' || yesNo == 'n')
        {
            cout << "Skipping notes.\n";
            break;
        }
        else
            cout << "Invalid input.\n";
            cout << "Enter a letter to skip or T to try again: ";
            cin >> retry;
    }
    return option;
}
string pageCentering(Position pos, string s, int &pageLength)
{
    string dateCentered = s;
    int spaces = 0;
    switch (pos)
    {
        case CENTER: spaces = (pageLength - s.size()) / 2; break;
        case RIGHT: spaces = (pageLength - s.size()); break;
    }
    return string(spaces, ' ') + dateCentered;
}

int randomizer()
{
    // Providing a seed value
	srand((unsigned) time(NULL));
    // Retrieve a random number between 1 and 12

    int random = 1 + (rand() % 12);

	return random;
}

string printTopBorder(int num)
{
    string borders;
    switch (num)
    {
        case 1:
            borders = "╔══════════════════════════════ ≪ °❈° ≫ ══════════════════════════════╗";
            break;
        case 2:
            borders = "╔════════════════════════════════════════════════════ ≪ °❈° ≫ ════════╗";
            break;
        case 3:
            borders = "╔════════ ≪ °❈° ≫ ════════════════════════════════════════════════════╗";
            break;
        case 4:
            borders = "┌──────────────────────────────── ∘°❉°∘ ────────────────────────────────┐";
            break;
        case 5:
            borders = "┌──────────────────── ∘°❉°∘ ────────────────────────────────────────────┐";
            break;
        case 6:
            borders = "┌────────────────────────────────────────────── ∘°❉°∘ ──────────────────┐";
            break;
        case 7:
            borders = "┌────────────────────────────── ❀*̥˚──❀*̥˚ ──────────────────────────────┐";
            break;
        case 8:
            borders = "┌───── ❀*̥˚──❀*̥˚ ───────────────────────────────────────────────────────┐";
            break;
        case 9:
            borders = "┌─────────────────────────────────────────────────── ❀*̥˚──❀*̥˚ ─────────┐";
            break;
        case 10:
            borders = "┌──────────────────────────────────────────────── ☄. *. ⋆ ─────────────┐";
            break;
        case 11:
            borders = "┌────────────────── ☄. *. ⋆ ───────────────────────────────────────────┐";
            break;
        case 12:
            borders = "┌──────────────────────────────────────────────── ☄. *. ⋆ ─────────────┐";
            break;
        default: break;
    }
    return borders;
}

string printBottomBorder(int num)
{
    string borders;
    switch (num)
    {
        case 1:
            borders = "╚══════════════════════════════════════════ ≪ °❈° ≫ ══════════════════╝";
            break;
        case 2:
            borders = "╚════ ≪ °❈° ≫ ════════════════════════════════════════════════════════╝";
            break;
        case 3:
            borders = "╚══════════════════════════════ ≪ °❈° ≫ ══════════════════════════════╝" ;
            break;
        case 4:
            borders = "└────────────────────────────────────────────────── ∘°❉°∘ ──────────────┘";
            break;
        case 5:
            borders = "└───────────────────────────────────────────────────────── ∘°❉°∘ ───────┘";
            break;

        case 6:
            borders = "└─── ∘°❉°∘ ─────────────────────────────────────────────────────────────┘";
            break;

        case 7:
            borders = "└──────────────────────────────────────────────────── ❀*̥˚──❀*̥˚ ────────┘";
            break;

        case 8:
            borders = "└────────────────────────── ❀*̥˚──❀*̥˚ ──────────────────────────────────┘";
            break;

        case 9:
            borders = "└──────────────── ❀*̥˚──❀*̥˚ ────────────────────────────────────────────┘";
            break;

        case 10:
            borders = "└─────────────────────────────────────────────────── ☄. *. ⋆  ─────────┘";
            break;

        case 11:
            borders = "└──────────── ☄. *. ⋆ ─────────────────────────────────────────────────┘";
            break;
        case 12:
            borders = "└───────────────────────────────────── ☄. *. ⋆  ───────────────────────┘";
            break;
        default: break;
    }
    return borders;
}
