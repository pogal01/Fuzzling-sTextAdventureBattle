#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <ctype.h>
using namespace std;
string yourName = "You";  //Players name
string yourDisplayName = yourName+":"; //Simplely your name with a : at the end so you can tell its you who is speaking and I don't have to hard code a : evey time.
string nameOfIntroductionGuy = "???:"; //Variable for the guy who speaks at the start
string nameOfNPC = "???:"; // Variable for first other guys you meet I just have to simply reset it to ??? if they are going to speak to someone new
string nameOfFirstFuzzling = "Fuzz"; //Name of your fuzzling will be used in the battle  and story
string ReusableeAnswer = "N/A"; // Saves me from making millions of variables
char Reusableechar = '?'; // saves me from making many char variables (mainly for switch statements)
bool ReusableBool = false;
int AmountOfFuzzlings = 0; // This might or might not be used later if the player can have multaple fuzzlings. the idea is to allow them to use the Nameing function to name each one I will probably need a dynamic array for this.
string location = "Lab"; //This just displays the current location useful for which creatures will pop up
int SituationalInt = 1; //Used in random generator can be changed depending on what I want
int SituationalInt2 = 6; //Used in random generator can be changed depending on what I want
string SpecialFuzzling; // This is to determine which enemy will be faced it will depend on the location
string Enemy; // just a variable to determine what the enemy is


int RandomGenAnswer; // Where I store the Answer from the random generator


//Player's fuzzlings stats. they can all change
int PlayerHealth = 10;
int PlayerSpeed = 10;
int PlayerDamage = 3;
int PFuzzlingsLevel = 5;
int EXP = 0 ; //The amount of exp the fuzzling currently has evey 500 the fuzzling will level up 
int PlayersSP = 10;
string Playertype = "basic";

//Money
int coins = 100;

//enemy stats
int EnemyHealth = 10;
int EnemySpeed = 10;
int EnemyDamage = 3;
int EnemysFuzzlingsLevel = 5;
int EnemySP = 10;
string Type = Enemy;

void RandomGenerator()  //where the code for the random generator is. 
{
	mt19937 generator;
	generator.seed(time(0));

	uniform_int_distribution<uint32_t> dice(SituationalInt, SituationalInt2);  //This is so I can change the numbers if I need to on other scripts

	int random = dice(generator);

	RandomGenAnswer = random;

}

void ResetVariablesToDefault() //This is a function I use to reset the reusable variables back to default
{
	ReusableeAnswer = "N/A";
	Reusableechar = '?';
	ReusableBool = false;


}


//Function to name your fuzzling Basicaly just exists so I can collapse the code and read it easier
void NameingFuzzling()
{
	bool ReusableBool = false;
	char Reusableechar;
	
	while (ReusableBool == true)

	{ 
		ResetVariablesToDefault();
		cout << "would you like to name your Fuzzling?" << endl;
		cout << "Press Y for yes and N for no" << endl;
		cin >> Reusableechar;
		Reusableechar = getchar();
		putchar(Reusableechar);
		switch (tolower(Reusableechar))
		{
		case ('y'):
			cout << "Please enter your fuzzlings name" << endl;
			cin >> nameOfFirstFuzzling;
			cout << "So you want to name your fuzzling " << nameOfFirstFuzzling << " Correct ? (please still enter either y or n)"<<endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y"|| ReusableeAnswer == "y")
			{
				
				break;

			}
			else if (ReusableeAnswer == "N"|| ReusableeAnswer == "n")
			{
				//Should just loop
				ReusableBool = true;

			}
			else
			{
				cout << "Please enter either y or n" << endl;
				ReusableBool = true;
				break;
			}
		case ('n'): //I could have put this next part in its own function but I chose not to since it was easy to just copy and paste it twice
			cout << "Are you sure ? Your fuzzling will just be called Fuzz by default" << endl;
			cout << "Please enter Y if you are sure that you don't want to name your fuzzling or N if you actually do" << endl;
			cin >> Reusableechar;

			if (tolower(Reusableechar) == 'n')
			{
				//Should just loop
				ReusableBool = true;
				
			}
			else if (tolower(Reusableechar) == 'y')
			{
				cout << "Ok your fuzzling is called Fuzz" << endl;
				nameOfFirstFuzzling = "Fuzz";
				break;
			}
			else
			{
				cout << "Please enter either y or n" << endl;
				ReusableBool = true;
				break;
			}

		default:
			cout << "Please only enter either Y or N" << endl;
			ReusableBool = true;
			break;
		}
	
	}
	
}


void ChangeingLocation()
{


	bool LocationPicked = false;
	
	
	while (LocationPicked == false) 
	{
		cout << "Where would you like to go from here ?" << endl;
		cout << "The options are the Forest (F), Cave (C), Volcanic lands(V), SnowyMountins(M), Junkyard(Y), Jungle(J) or the Swamp(S)" << endl;
		cout << "Please make sure to capitalize your Answer" << endl;
		cin >> Reusableechar;
		switch (Reusableechar)
		{
		case 'F':
			location = "Forest";
			cout << "So you would like to go to the " << location <<"? "<< endl;
			cout << "Y for yes or N for no"<<endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y") 
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Hedgeling";
				break;
			}
			else if (ReusableeAnswer == "y")
			{
			LocationPicked = true;
			cout << "You are now at the " << location << endl;
			SpecialFuzzling = "Hedgeling";
			break;
			}
			else
			{
				break;
			}

		case 'C':
			location = "Cave";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Shadowling";
				break;
			}
			else if (ReusableeAnswer == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Shadowling";
				break;
			}
			else
			{
				break;
			}

		case 'V':
			location = "Volcanic Lands";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Volcanicling";
				break;
			}
			else if (ReusableeAnswer == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Volcanicling";
				break;
			}
			else
			{
				break;
			}
		

		case 'M':
			location = "SnowyMountins";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Frostling";
				break;
			}
			else if (ReusableeAnswer == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Frostling";
				break;
			}
			else
			{
				break;
			}
		

		case 'Y':
			location = "Junkyard";
			cout << "So you would like to go to the " << location << "? " << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Spikeling";
				break;
			}
			else if (ReusableeAnswer == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Spikeling";
				break;
			}
			else
			{
				break;
			}
		
		
		case 'J':
			location = "Jungle";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Climeling";
				break;
			}
			else if (ReusableeAnswer == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Climeling";
				break;
			}
			else
			{
				break;
			}
		

		case 'S':
			location = "Swamp";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Swampling";
				break;
			}
			else if (ReusableeAnswer == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				SpecialFuzzling = "Swampling";
				break;
			}
			else
			{
				break;
			}


		default:
			cout << "Answer invalid please enter one of the letters in the brackets" << endl;
		}

	}

}


void GeneratePlayerFuzzlingsBaseStats()
{
	//Player's health
	SituationalInt = PFuzzlingsLevel - 1;
	SituationalInt2 = PFuzzlingsLevel + 2;
	RandomGenerator();
	PlayerHealth = PFuzzlingsLevel + RandomGenAnswer * 7;
	//now damage
	SituationalInt = 2;
	SituationalInt2 = 5;
	RandomGenerator();
	PlayerDamage = PFuzzlingsLevel + RandomGenAnswer;
	//Now speed
	SituationalInt = 2;
	SituationalInt2 = 4;
	RandomGenerator();
	PlayerSpeed = PFuzzlingsLevel + RandomGenAnswer;
	//SP
	PlayersSP = PFuzzlingsLevel * 2;

	
}


void FuzzlingStats()
{
	cout << nameOfFirstFuzzling << "'s " << "Stats are as follows" << endl;
	cout << "Health = " << PlayerHealth << endl;
	cout << "Speed = " << PlayerSpeed << endl;
	cout << "Damage = " << PlayerDamage << endl;
	cout << "SP = " << PlayersSP << endl;
	cout << "Fuzzlings Type:" << Playertype << endl;
	cout << "level = " << PFuzzlingsLevel << endl;
	
	cout << endl;


}


void EnemyStatsdecideing()
{
	// This part calculates the level (in the begining zones the levels can be within the range of the level that belongs to the fuzzling
	SituationalInt = PFuzzlingsLevel - 2;
	SituationalInt2 = PFuzzlingsLevel + 2;
	RandomGenerator();
	EnemysFuzzlingsLevel = RandomGenAnswer;
	// This next part is for health
	SituationalInt = 1;
	SituationalInt2 = 2;
	RandomGenerator();
	EnemyHealth = EnemysFuzzlingsLevel + RandomGenAnswer * 7;
	// This next part is the base damage it can do more or less later
	SituationalInt = 2;
	SituationalInt2 = 5;
	RandomGenerator();
	EnemyDamage = EnemysFuzzlingsLevel + RandomGenAnswer; 
	//This next part is speed
	SituationalInt = 2;
	SituationalInt2 = 4;
	RandomGenerator();
	EnemySpeed = EnemysFuzzlingsLevel + RandomGenAnswer;
	//This is its sp it will always be 2x the level so if its level 5 it will be 10
	EnemySP = EnemysFuzzlingsLevel * 2;
}

void EnemyStats() // This will change depending on the enemy
{
	cout << "The stats of the"<< Enemy << "Stats are as follows" << endl;
	cout << "Health = " << PlayerHealth << endl;
	cout << "Speed = " << PlayerSpeed << endl;
	cout << "Damage = " << PlayerDamage << endl;
	cout << "level = " << PFuzzlingsLevel << endl;
	cout << "SP = " << PlayersSP << endl;
	cout << "Fuzzlings Type:" << Playertype << endl;
	cout << endl;

}


void RandomEncounter() //The code for random encounters
{


	SituationalInt = 1;
	SituationalInt2 = 6;
	RandomGenerator();


	if (RandomGenAnswer <= 3) 
	{
		cout << "you have encountered a basic Fuzzling" << endl;
		Enemy = "Basic Fuzzling";

	}
	else
	{
		cout << "You have encountered a " << SpecialFuzzling << endl;
		Enemy = SpecialFuzzling;

	}
	cout << "Do you chose to Fight(F) or Run(R) ? (default is Fight)" << endl;
	Reusableechar = 'F';
	cin >> Reusableechar;
	switch (Reusableechar)
	{
	case'F':
		cout << "You have chosen to fight the " << Enemy << endl;
		ResetVariablesToDefault();
		break;
		//The same thing but with a lowercase f
	case'f':
		cout << "You have chosen to fight the " << Enemy << endl;
		ResetVariablesToDefault();
		break;
	case'R':
		cout << "You have chosen to try and run from the " << Enemy <<" The speed of your fuzzlings will now be compared and you will have a chance to escape"<< endl;
		ResetVariablesToDefault();
		break;
		//The same thing but with a lowercase r
	case'r':
		cout << "You have chosen to try and run from the " << Enemy << " The speed of your fuzzlings will now be compared and you will have a chance to escape" << endl;
		ResetVariablesToDefault();
		break;
	default:
	break;
	}

	



}




	//Some old unused code 
    /*
	if (Reusableechar == 'Y')
	{
		cout << "Please enter your fuzzlings name";
		cin >> nameOfFirstFuzzling;
	}
	else if (Reusableechar == 'N')
	{
		cout << "Are you sure ? Your fuzzling will just be called Fuzz by default" << endl;
		cout << "Please enter Y or n" << endl;
		cin >> Reusableechar;
		if (Reusableechar == 'y')
		{
			cin >> nameOfFirstFuzzling;
		}
		else if (Reusableechar == 'n')
		{
			cout << "Ok your fuzzling is called Fuzz" << endl;
			nameOfFirstFuzzling = "Fuzz";
		}
		else
		{
			cout << "Please enter either y or n" << endl;
			NameingFuzzling();
		}
	}
	else
	{
		cout << "Please enter either y or n" << endl;
		NameingFuzzling();
	}
	
}
*/
int main()
{
	ResetVariablesToDefault();
	cout << nameOfIntroductionGuy << " Hello Welcome to the Fuzzling battle  simulator." << endl << "Fuzzlings are mythical creatures that all have diffrent elements. You will be useing them to battle" << endl;
	cout << nameOfIntroductionGuy << " So Sorry I forgot to tell you my name. My name is Professor Pogal and I will introduce you into this world" << endl;
	nameOfIntroductionGuy = "ProfessorPogal:";
	cout << nameOfIntroductionGuy << " May I ask what your name is ?" << endl;
	cout << "Please enter your name" << endl;
	cin >> yourName;

	yourDisplayName = yourName + ":"; // This is when it adds the : to your name so it can be displayed at the beginning to show you are talking but if a character references you they will use yourname instead since you don't need a colon after names mid sentance
	cout << nameOfIntroductionGuy << " Ah your name is " << yourName << " Its nice to meet you and I wish you luck on your adventure" << endl << endl;
	if (yourName == "ProfessorPogal")
	{
		cout << "Wait a second we have the same name. Wow never thought I would meet another ProfessorPogal I will call you profesor pogal 2" << endl<<endl;
		yourDisplayName = yourName +"2" + ":";
	}
	cout << yourDisplayName << " Wait! What is a Fuzzling and how do I get one ?" << endl;
	cout << nameOfIntroductionGuy << " Oh right, I forgot thanks for reminding me" << endl;
	cout << nameOfIntroductionGuy << " I was supposed to give you a basic Fuzzling" << endl;
	cout << yourDisplayName << "Basic Fuzzling? You mean to tell me there is more ?" << endl;
	cout << nameOfIntroductionGuy << " Yes Fuzzlings come with many different types which have unique abilities."<<endl<<"They can also have strengths and weaknesses against other types." << endl<<"Your fuzzling is also able to evolve into different types and has no strengths or weaknesses because its basic so hasen't evolved yet" << endl;
	cout << nameOfIntroductionGuy << " Anyway, here is your fuzzling" << endl;
	NameingFuzzling();
	cout << "Your Fuzzling is officaly called " << nameOfFirstFuzzling << endl;
	cout << nameOfIntroductionGuy <<""<< yourName << " Congratulations you did it you and " << nameOfFirstFuzzling << " are officaly ready for your first adventure" << endl;
	GeneratePlayerFuzzlingsBaseStats();
	cout << "Would you like to know the stats of your fuzzling ?"<<endl;
	while (ReusableBool == false)
	{
		cout << "Y for yes N for no" << endl;
		cin >> Reusableechar;
		switch (Reusableechar)
		{
		case'Y':
			ReusableBool = true;
			FuzzlingStats();
			break;
			//The same thing but with a lowercase y
		case'y':
			ReusableBool = true;
			FuzzlingStats();
			break;

		case'N':
			cout << "you have chosen not to view your fuzzings stats" << endl;
			ReusableBool = true;
			break;
			//The same thing but with a lowercase n
		case'n':
			cout << "you have chosen not to view your fuzzings stats" << endl;
			ReusableBool = true;
			break;
		default:
			cout << "Please enter a valid Answer" << endl;
			break;
		}




	}
	ResetVariablesToDefault();
	ChangeingLocation();
	RandomEncounter();



	system("PAUSE");
}


//This function is what is used to name the first fuzzling


