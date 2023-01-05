#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <stdio.h>

// Macro definitions
#define PAGELENGTH 73

using namespace std;

// An enumeration is a user-defined data type that consists of integral constants.
enum Position { LEFT, CENTER, RIGHT };

struct bStruct{
    vector<string> bulletPoints;
    int numBulletPoints;
};

string pageCentering(Position, string);
int randomizer();
void formater(string);
string printTopBorder(int);
string printBottomBorder(int);
int decider();
void menu(int);
vector<string> worldHistory();
vector<string> bulletPoints();
vector<string> items();
vector<string> npcs();



int main()
{
    SetConsoleOutputCP(CP_UTF8);
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

        int decision = decider();
        switch (decision)
        {
        case 1:
        {
            vector<string> finHistVec = worldHistory();
            string histTitle = finHistVec.at(0);
            string histDesc = finHistVec.at(1);
            break;
        }
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

        /* Under this is what formats the .doc file*/

        // write them to the file, each on a separate line
        file << setfill('=') << setw(PAGELENGTH) << "=" << endl;
        file << pageCentering(CENTER, date) << endl;

        file << desc << endl;
        file.close();
    }
    return 0;
}

vector<string> npcs()
{

}
vector<string> items()
{

}
vector<string> bulletPoints()
{
    vector<string> bVec;
    string topBorder = ("◤━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◥");
    bVec.push_back(topBorder);

    int numBullet;
    cout << "How many bullet points do you want to make?: ";
    cin >> numBullet;
    cin.ignore();

    for (int i = 1; i <= numBullet; i++)
    {
        string bulletDesc;
        cout << "Please enter bullet point #" << i << ": ";
        getline(cin, bulletDesc);
        bVec.push_back("▷ " + bulletDesc);
    }

    string bottomBorder = ("◣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◢");
    bVec.push_back(bottomBorder);

    numBullet++;
    for (int i = 0; i <= numBullet; i++)
    {
        bStruct.bulletPoints.push_back(bVec.at(i));
    }

    return bVec;
}
vector<string> worldHistory()
{
    vector<string> hVec;
    string wordTitle = ("»»———-World History———-««");
    string centeredTitle = pageCentering(CENTER, wordTitle);
    hVec.push_back(centeredTitle);

    string worldDesc;
    cout << "Please enter notes about the world history:" << endl;
    getline(cin, worldDesc);
    hVec.push_back(worldDesc);

    cout << "printing tests:\n";
    cout << hVec.at(0) << endl;
    cout << hVec.at(1) << endl;

    return hVec;
}

/*void menu(int choice)
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
}*/

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
string pageCentering(Position pos, string s)
{
    string dateCentered = s;
    int spaces = 0;
    switch (pos)
    {
        case CENTER: spaces = (PAGELENGTH - s.size()) / 2; break;
        case RIGHT: spaces = (PAGELENGTH - s.size()); break;
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
