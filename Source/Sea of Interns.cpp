// Sea of Interns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <functional>
#include <fstream>
#include <thread>   
#include <chrono>       


using namespace std;

string top = "";
string stub = "SoI: ";
string name = "";

int strStat = 0;
int dexStat = 0;
int conStat = 0;
int intelStat = 0;
int wisStat = 0;
int chaStat = 0;

int strMod = 0;
int dexMod = 0;
int conMod = 0;
int intelMod = 0;
int wisMod = 0;
int chaMod = 0;

void StatMod()
{

	if (strStat > 18)
	{
		strMod = 4;
	}
	else if (strMod > 16 && strMod <= 18)
	{
		strMod = 3;
	}
	else if (strMod > 14 && strMod <= 16)
	{
		strMod = 2;
	}
	else if (strMod > 12 && strMod <= 14)
	{
		strMod = 1;
	}
	else if (strMod > 10 && strMod <= 12)
	{
		strMod = 0;
	}
	else if (strMod > 8 && strMod <= 10)
	{
		strMod = -1;
	}
	else if (strMod > 6 && strMod <= 8)
	{
		strMod = -2;
	}
	
	if (dexStat > 18)
	{
		dexMod = 4;
	}
	else if (dexStat > 16 && dexStat <= 18)
	{
		dexMod = 3;
	}
	else if (dexStat > 14 && dexStat <= 16)
	{
		dexMod = 2;
	}
	else if (dexStat > 12 && dexStat <= 14)
	{
		dexMod = 1;
	}
	else if (dexStat > 10 && dexStat <= 12)
	{
		dexMod = 0;
	}
	else if (dexStat > 8 && dexStat <= 10)
	{
		dexMod = -1;
	}
	else if (dexStat > 6 && dexStat <= 8)
	{
		dexMod = -2;
	}
	
	if (conStat > 18)
	{
		conMod = 4;
	}
	else if (conStat > 16 && conStat <= 18)
	{
		conMod = 3;
	}
	else if (conStat > 14 && conStat <= 16)
	{
		conMod = 2;
	}
	else if (conStat > 12 && conStat <= 14)
	{
		conMod = 1;
	}
	else if (conStat > 10 && conStat <= 12)
	{
		conMod = 0;
	}
	else if (conStat > 8 && conStat <= 10)
	{
		conMod = -1;
	}
	else if (conStat > 6 && conStat <= 8)
	{
		conMod = -2;
	}
	
	if (intelStat > 18)
	{
		intelMod = 4;
	}
	else if (intelStat > 16 && intelStat <= 18)
	{
		intelMod = 3;
	}
	else if (intelStat > 14 && intelStat <= 16)
	{
		intelMod = 2;
	}
	else if (intelStat > 12 && intelStat <= 14)
	{
		intelMod = 1;
	}
	else if (intelStat > 10 && intelStat <= 12)
	{
		intelMod = 0;
	}
	else if (intelStat > 8 && intelStat <= 10)
	{
		intelMod = -1;
	}
	else if (intelStat > 6 && intelStat <= 8)
	{
		intelMod = -2;
	}
	
	if (wisStat > 18)
	{
		wisMod = 4;
	}
	else if (wisStat > 16 && wisStat <= 18)
	{
		wisMod = 3;
	}
	else if (wisStat > 14 && wisStat <= 16)
	{
		wisMod = 2;
	}
	else if (wisStat > 12 && wisStat <= 14)
	{
		wisMod = 1;
	}
	else if (wisStat > 10 && wisStat <= 12)
	{
		wisMod = 0;
	}
	else if (wisStat > 8 && wisStat <= 10)
	{
		wisMod = -1;
	}
	else if (wisStat > 6 && wisStat <= 8)
	{
		wisMod = -2;
	}
	
	if (chaStat > 18)
	{
		chaMod = 4;
	}
	else if (chaStat > 16 && chaStat <= 18)
	{
		chaMod = 3;
	}
	else if (chaStat > 14 && chaStat <= 16)
	{
		chaMod = 2;
	}
	else if (chaStat > 12 && chaStat <= 14)
	{
		chaMod = 1;
	}
	else if (chaStat > 10 && chaStat <= 12)
	{
		chaMod = 0;
	}
	else if (chaStat > 8 && chaStat <= 10)
	{
		chaMod = -1;
	}
	else if (chaStat > 6 && chaStat <= 8)
	{
		chaMod = -2;
	}
	
}

int RollSkillCheck(string stat)
{

	if (stat == "Str")
	{
		return (rand() % 20 + 1) + strMod;
	}
	else if (stat == "Dex")
	{
		return (rand() % 20 + 1) + dexMod;
	}
	else if (stat == "Con")
	{
		return (rand() % 20 + 1) + conMod;
	}
	else if (stat == "Int")
	{
		return (rand() % 20 + 1) + intelMod;
	}
	else if (stat == "Wis")
	{
		return (rand() % 20 + 1) + wisMod;
	}
	else if (stat == "Cha")
	{
		return (rand() % 20 + 1) + chaMod;
	}
	return 0;
}

string GetPirateTitle(std::ifstream& File)
{
	string Lines = "";        //All lines
	string titleName = "";
	if (File)                      //Check if everything is good
	{
		int title = rand() % 10 + 1;
		int count = 1;
		while (File.good())
		{
			string titleName;
			getline(File, titleName);
			
			if (count == title)
			{
				Lines += titleName;
			}
			titleName = "";
			count++;
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}

string GetFileContents(std::ifstream& File)
{
	std::string Lines = "";        //All lines

	if (File)                      //Check if everything is good
	{
		while (File.good())
		{
			std::string TempLine;                  //Temp line
			std::getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}

void Chapter1()
{
	string command = ""; 
	cout << "------------------ Chapter 1: Set Sail ------------------" << endl;
	cout << "As your new pirate mentor takes you onboard his ship you see a young man." << endl;
	cout << "Do you introduce yourself to this new recruit? [Charism Roll] Y/N" << endl;
	bool valid = false;
	
	while (valid != true)
	{
		getline(cin, command);
		if (command == "y" || command == "Y")
		{
			int roll = RollSkillCheck("Cha");
			if (roll > 10)
			{
				cout << "Roll : " << roll << " Success! You approach the young pirate and introduce yourself as " + name << endl;
				cout << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "The young pirate introduces himself as Ben Bywater, an up and coming pirate." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You share small talk with Ben and find that hes incredibly jovial!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Ben comes off as confident in this new environment. " << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Even though you have just met him Ben comes off as very friendly!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			else
			{
				cout << "Roll : " << roll << " Failure! As you approach this new new recruit you slip on a bottle of grog!" << endl;
				cout << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You feel incredible embaressed! You feel as if this new recruit will mock you for sure." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "To your suprise the new recruit helps you up and aids you to get on your feet." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "The young pirate introduces himself as Ben Bywater, an up and coming pirate." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You share small talk with Ben and find that hes incredibly jovial!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Ben comes off as confident in this new environment. " << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Even though you have just met him Ben comes off as very friendly!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			valid = true;

		}
		else if (command == "n" || command == "N")
		{
			cout << "You think to yourself that you should stay quiet. He probably doesnt want to talk to you anyway." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "To your suprise he introduces himself to you with a hand shake and smile." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "The young pirate introduces himself as Ben Bywater, an up and coming pirate." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "You share small talk with Ben and find that hes incredibly jovial!" << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "Ben comes off as confident in this new environment. " << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "Even though you have just met him Ben comes off as very friendly!" << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			valid = true;
		}
		else
		{
			cout << "Please enter a valid command!" << endl;
		}
	}

	cout << endl;
	cout << "You and Ben set sail with Rare as they take you to the open sea." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Rare put you to work doing jobs around the boat." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "You find that even though the work is hard and new to you Ben is more than happy to help." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Ben seems to be comfortable asking advice from the pirates at Rare." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Ben also tells you that he has undertaken a 12 month placement at another pirate gang." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "You think that Ben probably has valuable experience when working within pirate gangs." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
}

void Chapter2()
{
	string command = "";
	cout << endl;
	cout << "------------------- Chapter 2: Thar be Treasure -------------------" << endl;

	ifstream ReaderShip("ship.txt");
	string Art = GetFileContents(ReaderShip);
	this_thread::sleep_for(std::chrono::seconds(3));
	cout << Art << endl;

	cout << "Rare takes yourself and Ben to a remote island to find treasure!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Your new pirate gang gives you and Ben a map." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "You have been given a criptic treasure map to prove your worth." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Do you try to investigate the map and discover where the treasure lies? [Intelligence Roll] Y/N" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	bool valid = false;

	while (valid != true)
	{
		getline(cin, command);
		if (command == "y" || command == "Y")
		{
			int roll = RollSkillCheck("Int");
			if (roll > 10)
			{
				cout << "Roll : " << roll << " Success! You start to unravel the crude markings layed on your map." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You feel as if you are starting lead yourself and Ben in the right direction." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "After entering the thick jungle located on the island you start to feel less and less confident with your surroudnings" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Once Ben notices that you might need help he kindly asks if he could suggest his input on how to find the trasure." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Yourself and Ben go back and fourth on what to do." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You find yourself thinking that Ben seems calm and level headed when confronted with a problem." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Together you figure out where to go next to find the treasure!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You realise that Ben is a proficient and creative problem solver." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << endl;
			}
			else
			{
				cout << "Roll : " << roll << " Failure! You find yourself dumbfounded by this blasted map!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You try your best and end up circling the island beach for hours." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You become irritated for not acheiving anything and decide to head into the island jungle in search for the treasure." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "After entering the thick jungle you start to feel less and less confident with your surroudnings" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Once Ben notices that you might need help he kindly asks if he could suggest his input on how to find the trasure." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Yourself and Ben go back and fourth on what to do." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You find yourself thinking that Ben seems calm and level headed when confronted with a problem." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Together you figure out where to go next to find the treasure!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You realise that Ben is a proficient and creative problem solver." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << endl;
			}
			valid = true;

		}
		else if (command == "n" || command == "N")
		{
			cout << "You suggest that Ben should hold on to the map as you dont feel like holding it today." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "Ben looks at the map with a puzzled expression and suggests that you both look at it together to find the treasure." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "Yourself and Ben go back and fourth on what to do." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "You find yourself thinking that Ben seems calm and level headed when confronted with a problem." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "Together you figure out where to go next to find the treasure!" << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << "You realise that Ben is a proficient and creative problem solver." << endl;
			this_thread::sleep_for(std::chrono::seconds(1));
			cout << endl;
			valid = true;
		}
		else
		{
			cout << "Please enter a valid command!" << endl;
		}
	}

	cout << "After several hours of following the maps directions and clues you both stumble upon the treasure!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "You both haul the valuable loot back to the ship." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "The Rare gang all cheer after seeing the youve found the treasure." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "They celebrate by opening a barrel of grog and distributing the treasure amoung all the crew." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Pirate: THREE CHEERS FOR " + name + " AND BEN!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
}

void Chapter3()
{
	string command = "";
	cout << endl;
	cout << "------------- Chapter 3: Thats a Killer Kraken  -------------" << endl;

	ifstream ReaderKraken("Kraken.txt");
	string Art = GetFileContents(ReaderKraken);
	
	

	cout << "You and everyone on board celebrate all night by drinking lots and lots of grog." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "You start to fall asleep, but as you do you notice the treasure you got from the island starts to glow!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "You freeze in place as you feel the boat starts to sway side to side!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "You look up in horror as you stare at a humongous Kraken toppling over the ship! " << endl;
	this_thread::sleep_for(std::chrono::seconds(3));
	cout << Art << endl;
	cout << "Pirate: THE TREASURE BE CURSED! ALL HANDS ON DECK YA SEA DOGS!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "To your left you see a sharp cutlass. To your right you see a loaded handgun." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Which do you choose to fight the kraken? [Strength or Dexterity Roll] C/H" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));

	bool valid = false;

	while (valid != true)
	{
		getline(cin, command);
		if (command == "c" || command == "C")
		{
			int roll = RollSkillCheck("Str");
			if (roll > 10)
			{
				cout << "Roll : " << roll << " Success! You pick up your cutlass and charge at the closest Kraken tentacles" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				int damageD1 = rand() % 6 + 1;
				int damageD2 = rand() % 6 + 1;
				int damageD3 = rand() % 6 + 1;
				int damageD4 = rand() % 6 + 1;
				int damageSum = damageD1 + damageD2 + damageD3 + damageD4 + strStat;
				cout << "You deal " << damageSum << " slashing damage to the Kraken and slice its tentacle in half!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You scan the deck of the boat to see that the kraken has many more tentacles" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Ben rushes to your side and suggests that it would be more efficient to charge at the Krakens body" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You consider what Ben has to say and consider it to be the logical option" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You come to the conclusion that Ben must understand how to tackle a logical problem effectivly and efficiently." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				
				damageD1 = rand() % 6 + 1;
				damageD2 = rand() % 6 + 1;
				damageD3 = rand() % 6 + 1;
				damageD4 = rand() % 6 + 1;
				damageSum = damageD1 + damageD2 + damageD3 + damageD4 + strStat;
				cout << "You charge at the Krakens blobby body and deal " << damageSum << " slashing damage!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));

			}
			else
			{
				cout << "Roll : " << roll << " Failure! You pick up your cutlass and charge at the closest Kraken tentacles." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You swing with all your might but the Krakens skin is too thick! The tentacle swings and throws you across the deck" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You scan the deck of the boat to see that the kraken has many more tentacles" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Ben rushes to your side and suggests that it would be more effective to charge at the Krakens body rather than its tentacles" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You consider what Ben has to say and consider it to be the logical option" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You come to the conclusion that Ben must understand how to tackle a logical problem effectivly and efficiently." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));

				int damageD1 = rand() % 6 + 1;
				int damageD2 = rand() % 6 + 1;
				int damageD3 = rand() % 6 + 1;
				int damageD4 = rand() % 6 + 1;
				int damageSum = damageD1 + damageD2 + damageD3 + damageD4 + strStat;
				cout << "You charge at the Krakens blobby body and deal " << damageSum << " slashing damage!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			valid = true;

		}
		else if (command == "h" || command == "H")
		{
			int roll = RollSkillCheck("Dex");
			if (roll > 10)
			{
				cout << "Roll : " << roll << " Success! You pick up the loaded handgun and aim it toward the Krakens head." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				int damageD1 = rand() % 6 + 1;
				int damageD2 = rand() % 6 + 1;
				int damageD3 = rand() % 6 + 1;
				int damageD4 = rand() % 6 + 1;
				int damageSum = damageD1 + damageD2 + damageD3 + damageD4 + strStat;
				cout << "You deal " << damageSum << " piercing damage to the Kraken!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You observe how the Kraken shakes off the bullet acting as if nothing happened." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Ben rushes to your side and suggests that it would be more efficient to aim at\nthe Krakens eyes to cause more damage." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You consider what Ben has to say and consider it to be the logical option." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You come to the conclusion that Ben must understand how to tackle a logical problem effectivly and efficiently." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));

				damageD1 = rand() % 6 + 1;
				damageD2 = rand() % 6 + 1;
				damageD3 = rand() % 6 + 1;
				damageD4 = rand() % 6 + 1;
				damageSum = damageD1 + damageD2 + damageD3 + damageD4 + strStat;
				cout << "You aim at the Krakens eye and deal " << damageSum << " piercing damage!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			else
			{
				cout << "Roll : " << roll << " Failure! You pick up the loaded handgun and aim it toward the Krakens head." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You steady your hand to aim but the boat is swaying too much! You shoot and miss!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "Ben rushes to your side and suggests that it would be more effective slow down\nand to aim at the Krakens eyes to cause critical damage." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You consider what Ben has to say and consider it to be the logical option." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
				cout << "You come to the conclusion that Ben must understand how to tackle a logical problem effectivly and efficiently." << endl;
				this_thread::sleep_for(std::chrono::seconds(1));

				int damageD1 = rand() % 6 + 1;
				int damageD2 = rand() % 6 + 1;
				int damageD3 = rand() % 6 + 1;
				int damageD4 = rand() % 6 + 1;
				int damageSum = damageD1 + damageD2 + damageD3 + damageD4 + strStat;
				cout << "You aim at the Krakens eye and deal " << damageSum << " piercing damage!" << endl;
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			valid = true;
		}
		else
		{
			cout << "Please enter a valid command!" << endl;
		}
	}
	cout << endl;
	cout << "As you strike your fierce blow to the Kraken it lets out a pained screech." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Its body and tentacles escape into the ocean and your pirate pals cheer with victory!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Pirate: THE NEW RECRUITS HAVE DONE IT. THEY BEAT THE KRAKEN!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "All of the pirates in Rare were glad to have " + name + " and Ben at their side this night." << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "But did they prove they were ready to join Rare?" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "To be continued...." << endl;
}

int main()
{
	// lamda function to generate stat rolls
	srand(time(NULL));
	auto Stats =[](vector<int> &s) {generate(s.begin(), s.end(), []() { return rand() % 6 + 1; }); };
	
	// stats
	vector<int> str(4);
	vector<int> dex(4);
	vector<int> con(4);
	vector<int> intel(4);
	vector<int> wis(4);
	vector<int> cha(4);

	Stats(str);
	Stats(dex);
	Stats(con);
	Stats(intel);
	Stats(wis);
	Stats(cha);
	
	vector<vector<int>*> characterSheet = { &str, &dex, &con, &intel, &wis, &cha };
	// sort 4d6 stats in greater order
	for (auto &item : characterSheet)
	{
		sort(item->begin(), item->end(), greater<int>());
	}

	// add higest 3d6 stats
	strStat = accumulate(str.begin(), str.end() - 1, 0);
	dexStat = accumulate(dex.begin(), dex.end() - 1, 0);
	conStat = accumulate(con.begin(), con.end() - 1, 0);
	intelStat = accumulate(intel.begin(), intel.end() - 1, 0);
	wisStat = accumulate(wis.begin(), wis.end() - 1, 0);
	chaStat = accumulate(cha.begin(), cha.end() - 1, 0);
	StatMod();
	// create top string window 
	top = "========================================== Sea of Interns ==========================================\n====== Strenght: " + to_string(strStat) + " Dexterity: " + to_string(dexStat) + " Constitution: " + to_string(conStat) + " Intelligence: " + to_string(intelStat) + " Wisdom: " + to_string(wisStat) + " Charisma: " + to_string(chaStat) + " ========\n";
	cout << top << endl;
	cout << "You find yourself ready to set sail on the high seas! You have awoken early and invigorated. " << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "You are ready to join one of the most talented pirate gangs on all the seven seas, Rare!" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));
	cout << "Lucky for you they are accepting new recruits!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "As you step closer to Rares ship located on the harbour a pirate approaches you.\n" << endl;
	this_thread::sleep_for(std::chrono::seconds(2));


	ifstream ReaderPirate("pirate.txt");
	string Art = GetFileContents(ReaderPirate);
	this_thread::sleep_for(std::chrono::seconds(3));
	cout << Art << endl;

	cout << "Pirate: YAR YOU VAST LAND LUBBER, WHAT BE YAR NAME?" << endl;
	
	getline(cin, name);
	ifstream ReaderPirateNames("PirateNames.txt");
	string title = GetPirateTitle(ReaderPirateNames);
	name += " the " + title;

	cout << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Pirate: That be a good name for a pirate!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Pirate: I'll call you " << name << "!"  << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << "Pirate: Ill take you to where we keep the other new recruits!" << endl;
	this_thread::sleep_for(std::chrono::seconds(1));
	cout << endl;
	
	string command = "";
	cout << top << endl;
	Chapter1();
	cout << endl;
	cout << "Press Enter to continue to Chapter 2" << endl;
	getline(cin, command);
	cout << top << endl;
	Chapter2();
	cout << endl;
	cout << "Press Enter to continue to Chapter 3" << endl;
	getline(cin, command);
	cout << top << endl;
	Chapter3();
	cout << endl;
	cout << "----------------- Thank you for taking the time to play Sea of Interns and considering my application! -----------------" << endl;
	
	int x = 0;
	cin >> x;
	

    return 0;
}

