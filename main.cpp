/*
This program combines functions, vectors, structures, enumeration, loops, and cases to produce a program
meant for recording modular notes for Dungeons and Dragons.
*/
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
struct bStruct{ vector<string> bulletPoints; int numBulletPoints;};
struct iStruct{ vector<string> iNameAndDesc; vector<string> iUpdates; int numItems; int numIUpdates;};
struct nStruct{ vector<string> nNameAndDesc; int numNPCs;};

vector<string> worldHistory();
string pageCentering(Position, string);
string printTopBorder(int);
string printBottomBorder(int);
void menu(int);
void formater(string);
int decider(char);
int randomizer();
bStruct bulletPoints();
iStruct items();
nStruct npcs();

int main()
{
    bStruct b_struct;
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

        int randNum = randomizer();
        file << printTopBorder(randNum) << endl;
        file << pageCentering(CENTER, date) << endl;
        string dateBorder = "──────────────────";
        file << pageCentering(CENTER,dateBorder) << endl;
        file << "»»------► " << desc << endl;


        char yesNo;
        cout << "Any additional notes (Y/N)?: ";
        cin >> yesNo;
        char again = 'A';
        while (again == 'A' || again == 'a')
        {
            int decision = decider(yesNo);
            switch (decision)
            {
            case 1:
            {
                vector<string> finHistVec = worldHistory();
                file << finHistVec.at(0) << endl;
                file << finHistVec.at(1) << endl;
                break;
            }
            case 2:
            {
                bStruct mainPoint = bulletPoints();
                for (int i = 0; i <= mainPoint.numBulletPoints; i++)
                {
                    file << mainPoint.bulletPoints.at(i) << endl;
                }
                break;
            }
            case 3:
            {
                iStruct mainItems = items();
                for (int i = 0; i <= mainItems.numItems; i++)
                {
                    file << mainItems.iNameAndDesc.at(i) << endl;
                }
                if(mainItems.iUpdates.empty())
                    break;
                if(!mainItems.iUpdates.empty())
                {
                    for (int i = 0; i <= mainItems.numIUpdates; i++)
                    {
                        file << mainItems.iUpdates.at(i) << endl;
                    }
                }
                break;
            }
            case 4:
            {
                nStruct mainNPCs = npcs();
                for (int i = 0; i <= mainNPCs.numNPCs; i++)
                {
                    file << mainNPCs.nNameAndDesc.at(i) << endl;
                }
                break;
            }
            default:
                cout << "Error. Skipping notes.\n";
                break;
            }
            cout << "Press A to add more notes, or press a random key to continue.\n";
            cin >> again;
            cin.ignore();
            }
        file << printBottomBorder(randNum) << endl;
    }
    return 0;
}

nStruct npcs()
{
    vector<string> nVec;
    string bullPointSeparator = ("••●••");
    nVec.push_back(pageCentering(CENTER, bullPointSeparator));
    string npcTitle = ("NPCs");
    nVec.push_back(pageCentering(CENTER, npcTitle));
    string smallBorder = ("───────────");
    nVec.push_back(pageCentering(CENTER, smallBorder));

    int numOfNPCs;
    cout << "How many NPCs do you want to make?: ";
    cin >> numOfNPCs;
    cin.ignore();

    for (int i = 1; i <= numOfNPCs; i++)
    {
        string npcName, npcDesc;
        cout << "Please enter the name of NPC #" << i << ", press enter, followed with a description:\n";
        getline(cin, npcName);
        getline(cin, npcDesc);
        nVec.push_back("╰─▸ ❝ @[" + npcName + "]- " + npcDesc);
    }

    nStruct n_struct;
    int x = (numOfNPCs+2);
    n_struct.numNPCs = x;
    for (int i = 0; i <= x; i++)
    {
        n_struct.nNameAndDesc.push_back(nVec.at(i));
    }

    for (int i = 0; i <= x; i++)
    {
        cout << n_struct.nNameAndDesc.at(i) << endl;
    }
    cout << "current num of npcs: " << x << endl;
    return n_struct;
}

iStruct items()
{
    vector<string> iVec;
    string bullPointSeparator = ("••●••");
    iVec.push_back(pageCentering(CENTER, bullPointSeparator));
    string itemTitle = ("... [Items] ◌ೄ");
    iVec.push_back(pageCentering(CENTER, itemTitle));

    int numOfItems;
    cout << "How many items do you want to make?: ";
    cin >> numOfItems;
    cin.ignore();

    for (int i = 1; i <= numOfItems; i++)
    {
        string itemName;
        cout << "Please enter the name of item #" << i << ": ";
        getline(cin, itemName);
        iVec.push_back("• • •  " + itemName);

        string itemDesc;
        cout << "Please enter a short description for item #" << i << ": ";
        getline(cin, itemDesc);
        iVec.push_back("	○ " + itemDesc);
    }

    iStruct i_struct;
    int x = (numOfItems*2+1);
    i_struct.numItems = x;
    for (int i = 0; i <= x; i++)
    {
        i_struct.iNameAndDesc.push_back(iVec.at(i));
    }

    for (int i = 0; i <= x; i++)
    {
        cout << i_struct.iNameAndDesc.at(i) << endl;
    }
    cout << "current num of items: " << x << endl;

    char yesNo;
    int itemUpdateCount;
    vector<string> itemUpdateVec;

    char retry = 'T';
    while (retry == 'T' || retry == 't')
    {
        cout << "Are there any updates to include for the items? (Y/N): ";
        cin >> yesNo;
        char Y, y, N, n;
        if (yesNo == 'Y' || yesNo == 'y')
        {
            string itemUpdateTitle = ("⇘ : : @[Item Updates]");
            itemUpdateVec.push_back(itemUpdateTitle);
            cout << "How many updates do you wish to add?: ";
            cin >> itemUpdateCount;
            cin.ignore();
            for (int i = 1; i <= itemUpdateCount; i++)
            {
                string itemUpdate;
                cout << "Please enter the item name with the update for update #" << i << ": ";
                getline(cin, itemUpdate);
                itemUpdateVec.push_back("▷ " + itemUpdate);
            }

            int y = itemUpdateCount;
            i_struct.numIUpdates = y;
            for (int i = 0; i <= itemUpdateCount; i++)
                i_struct.iUpdates.push_back(itemUpdateVec.at(i));
            break;
        }
        else if ( yesNo == 'N' || yesNo == 'n')
        {
            cout << "Skipping item updates.\n";
            break;
        }
        else
            cout << "Invalid input.\n";
            cout << "Enter a random letter to skip or T to try again: ";
            cin >> retry;
    }

    return i_struct;
}

bStruct bulletPoints()
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

    bStruct b_struct;
    b_struct.numBulletPoints = ++numBullet;
    for (int i = 0; i <= numBullet; i++)
    {
        b_struct.bulletPoints.push_back(bVec.at(i));
    }

    for (int i = 0; i <= numBullet; i++)
    {
        cout << b_struct.bulletPoints.at(i) << endl;
    }
    cout << "current bullet point: " << numBullet << endl;

    return b_struct;
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

int decider(char answer)
{
    int option;
    char retry = 'T';
    while (retry == 'T' || retry == 't')
    {
        char Y, y, N, n;
        if (answer == 'Y' || answer == 'y')
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
        else if ( answer == 'N' || answer == 'n')
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
