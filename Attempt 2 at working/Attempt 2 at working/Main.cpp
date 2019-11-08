#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <ctype.h>
#include <limits>
#include <chrono>
#include <thread>
//
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
//
string yourName = "You";  //Players name
string yourDisplayName = yourName+":"; //Simplely your name with a : at the end so you can tell its you who is speaking and I don't have to hard code a : evey time.
string nameOfIntroductionGuy = "???:"; //Variable for the guy who speaks at the start
string nameOfNPC = "???:"; // Variable for first other guys you meet I just have to simply reset it to ??? if they are going to speak to someone new
string nameOfFirstFuzzling = "Fuzz"; //Name of your fuzzling will be used in the battle  and story
string ReusableeAnswer = "N/A"; // Saves me from making millions of variables
char Reusablechar = '?'; // saves me from making many char variables (mainly for switch statements)
bool ReusableBool = false;
int AmountOfFuzzlings = 0; // This might or might not be used later if the player can have multaple fuzzlings. the idea is to allow them to use the Nameing function to name each one I will probably need a dynamic array for this.
string location = "Lab"; //This just displays the current location useful for which creatures will pop up
int RandomInt = 1; //Used in random generator can be changed depending on what I want
int RandomInt2 = 6; //Used in random generator can be changed depending on what I want
string SpecialFuzzling; // This is to determine which enemy will be faced it will depend on the location
string SpecialFuzzlingItem = "";
string Enemy; // just a variable to determine what the enemy is




int RandomGenAnswer; // Where I store the Answer from the random generator


//other
bool LocationPicked = false;
bool IsRechargeingSP = false;
int PHealingCount = 0;
int DamageDelt = 0;
int Damage = 1;
int MaxHealingAmount = 0;
int HealingAmount = 0;
int Runchance = 1;
int EnemyChaseChance = 1;
int EHealingCount = 0;
int PMaxSP = 0;
int EMaxSP = 0;
int SPRechargeAmount = 0;
int MaxSPReachageAmount= 0;
bool PlayerDodge = false;
bool EnemyDodge = false;
bool EnemyAction = false;
int Hitchance = 0;




//Player's fuzzlings stats. they can all change
int PMaxhealth = 0;  //P stands for player
int PlayerHealth = 10;
int PlayerSpeed = 10;
int PlayerDamage = 3;
int PFuzzlingsLevel = 5;
int EXP = 0 ; //The amount of exp the fuzzling currently has evey 500 the fuzzling will level up 
int PlayersSP = 10;
string Playertype = "basic";

//Money
int coins = 1000;

//enemy stats
int EMaxhealth = 0; //E stands for enemy
int EnemyHealth = 10;
int EnemySpeed = 10;
int EnemyDamage = 3;
int EnemysFuzzlingsLevel = 5;
int EnemySP = 10;
string EType = "";


//Combat
bool PlayerTurn = true;
bool EnemyTurn = false;
bool PlayerRechargeing = false; //These will both be used with the accuracy mechanic of attack
bool EnemyRechargeing = false;  //^

//calling a few functions so they work lower down
void Attack();
void Heal();
void EnemyStats();
void DebugCode();
void FuzzlingStats();
void RechargeSP();
void Dodge();
void SpecialAttack();
//



void ValidateChar() //I could only put the basic one which doen't do anything if the user enters that appart from loop as a function.
{
	if (std::cin.get() == '\n') {
		//Validation complete
	}
	else
	{
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

		std::cout << "multiple characters not allowed" << endl;
	}

}

void RandomGenerator()  //where the code for the random generator is. 
{
	mt19937 generator;
	generator.seed(time(0));

	uniform_int_distribution<uint32_t> dice(RandomInt, RandomInt2);  //This is so I can change the numbers if I need to on other scripts

	int random = dice(generator);

	RandomGenAnswer = random;

}


void ResetVariablesToDefault() //This is a function I use to reset the reusable variables back to default
{
	ReusableeAnswer = "N/A";
	Reusablechar = '?';
	ReusableBool = false;


}

//Function to name your fuzzling Basicaly just exists so I can collapse the code and read it easier
//This function is what is used to name the first fuzzling Plan is to allow it to name multaple fuzzlings later

void Levelup() 
{

	PlayerHealth = (PFuzzlingsLevel + 2) * 12;
	PMaxhealth = PlayerHealth;
	//now damage
	PlayerDamage = PFuzzlingsLevel + 3;
	//Now speed
	PlayerSpeed = PFuzzlingsLevel + 2;
	//SP
	PlayersSP = PFuzzlingsLevel * 2;

}

void NameingFuzzling()
{
	ReusableBool = false;
	
	while (ReusableBool == false)

	{ 
		

		ResetVariablesToDefault();
		cout << "would you like to name your Fuzzling?" << endl;
		cout << "Press Y for yes and N for no" << endl;
		cin >> Reusablechar;
		ValidateChar();
	
		switch (tolower(Reusablechar))
		{
			
		case ('y'):
			cout << "Please enter your fuzzlings name" << endl;
			cin >> nameOfFirstFuzzling;
			cout << "So you want to name your fuzzling " << nameOfFirstFuzzling << " Correct ? (please still enter either y or n)"<<endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y"|| ReusableeAnswer == "y")
			{
				if (std::cin.get() == '\n') {
					//Validation complete
					ReusableBool = true;
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;;
				}
				

			}
			else if (ReusableeAnswer == "N"|| ReusableeAnswer == "n")
			{
				if (std::cin.get() == '\n') {
					//Validation complete
					ReusableBool = true;
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;;
				}
				//Should just loop
				

			}
			else
			{
				if (std::cin.get() == '\n') {
					//Validation complete
					ReusableBool = true;
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;;
				}
				cout << "Please enter either y or n" << endl;
				break;
			}
		case ('n'): //I could have put this next part in its own function but I chose not to since it was easy to just copy and paste it twice
			cout << "Are you sure ? Your fuzzling will just be called Fuzz by default" << endl;
			cout << "Please enter Y if you are sure that you don't want to name your fuzzling or N if you actually do" << endl;
			cin >> Reusablechar;

			if (tolower(Reusablechar) == 'n')
			{
				ValidateChar();
				
			}
			else if (tolower(Reusablechar) == 'y')
			{
				if (std::cin.get() == '\n') {
					//Validation complete
					cout << "Ok your fuzzling is called Fuzz" << endl;
					nameOfFirstFuzzling = "Fuzz";
					ReusableBool = true;
					break;
					ReusableBool = true;
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;;
				}
				
			}
			else
			{
				ValidateChar();
			}

		default:
			cout << "Please only enter either Y or N" << endl;
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
		cout << "The options are the Forest (F), Cave (C), Volcanic lands(V), Snowy Mountins(M), Junkyard(Y), Jungle(J) or the Swamp(S)" << endl;
		cin >> Reusablechar;
		ValidateChar();
		switch (tolower(Reusablechar))
		{

		case 'f':
			location = "Forest";
			cout << "So you would like to go to the " << location <<"? "<< endl;
			cout << "Y for yes or N for no"<<endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y"|| ReusableeAnswer == "y")
			{
				if (std::cin.get() == '\n') {
					LocationPicked = true;
					cout << "You are now at the " << location << endl;
					SpecialFuzzling = "Hedgeling";
					SpecialFuzzlingItem = "Puffer Hedge";
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;
					break;
				}
				
			}
			else if (ReusableeAnswer == "N"|| ReusableeAnswer == "n")
			{
				ValidateChar();
				
			}
			else
			{
				break;
			}

		case 'c':
			location = "Cave";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y" || ReusableeAnswer == "y")
			{
				if (std::cin.get() == '\n') {
					LocationPicked = true;
					cout << "You are now at the " << location << endl;
					SpecialFuzzling = "Shadowling";
					SpecialFuzzlingItem = "Puffer Shadow";
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;
					break;
				}

			}
			else if (ReusableeAnswer == "N" || ReusableeAnswer == "n")
			{
				ValidateChar();
			}
			else
			{
				break;
			}

		case 'v':
			location = "Volcanic Lands";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y" || ReusableeAnswer == "y")
			{
				if (std::cin.get() == '\n') {
					LocationPicked = true;
					cout << "You are now at the " << location << endl;
					SpecialFuzzling = "Volcanicling";
					SpecialFuzzlingItem = "Puffer volcanic";
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;
					break;
				}

			}
			else if (ReusableeAnswer == "N" || ReusableeAnswer == "n")
			{
				ValidateChar();

			}
			else
			{
				break;
			}
		

		case 'm':
			location = "Snowy Mountins";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y" || ReusableeAnswer == "y")
			{
				if (std::cin.get() == '\n') {
					LocationPicked = true;
					cout << "You are now at the " << location << endl;
					SpecialFuzzling = "Frostling";
					SpecialFuzzlingItem = "Puffer Freeze";
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;
					break;
				}

			}
			else if (ReusableeAnswer == "N" || ReusableeAnswer == "n")
			{
				ValidateChar();

			}
			else
			{
				break;
			}
		

		case 'y':
			location = "Junkyard";
			cout << "So you would like to go to the " << location << "? " << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y" || ReusableeAnswer == "y")
			{
				if (std::cin.get() == '\n') {
					LocationPicked = true;
					cout << "You are now at the " << location << endl;
					SpecialFuzzling = "Spikeling";
					SpecialFuzzlingItem = "Puffer spike";
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;
					break;
				}

			}
			else if (ReusableeAnswer == "N" || ReusableeAnswer == "n")
			{
				ValidateChar();

			}
			else
			{
				break;
			}
		
		
		case 'j':
			location = "Jungle";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y" || ReusableeAnswer == "y")
			{
				if (std::cin.get() == '\n') {
					LocationPicked = true;
					cout << "You are now at the " << location << endl;
					SpecialFuzzling = "Climeling";
					SpecialFuzzlingItem = "Puffer Hands";
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;
					break;
				}

			}
			else if (ReusableeAnswer == "N" || ReusableeAnswer == "n")
			{
				ValidateChar();

			}
			else
			{
				break;
			}
		

		case 's':
			location = "Swamp";
			cout << "So you would like to go to the " << location << "? " << endl;
			cout << "Y for yes or N for no" << endl;
			cin >> ReusableeAnswer;
			if (ReusableeAnswer == "Y" || ReusableeAnswer == "y")
			{
				if (std::cin.get() == '\n') {
					LocationPicked = true;
					cout << "You are now at the " << location << endl;
					SpecialFuzzling = "Swamping";
					SpecialFuzzlingItem = "Puffer damp";
					break;
				}
				else
				{
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

					std::cout << "multiple characters not allowed" << endl;;
					break;
				}

			}
			else if (ReusableeAnswer == "N" || ReusableeAnswer == "n")
			{
				ValidateChar();
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

void PlayerWinsTheFight()
{
	cout << "Congratulations you won the fight" << endl;

	if (EXP == 500) 
	{
		PFuzzlingsLevel = PFuzzlingsLevel + 1;
		cout << "Congratulations you have leveled up" << endl;
		cout << "Your fuzzling is now level " << PFuzzlingsLevel;
		Levelup();
	}


	EXP = EXP + 250;
	cout << "You gained 250exp in that fight only " <<500 - EXP<<"Remains untill you level up" <<endl;
	cout << "You aslo gained 100 coins your total amout of coins is now " << coins << " You can't buy anything with them though as I haven't programed that part yet" << endl;
	RandomInt = 1;
	RandomInt2 = 5;
	RandomGenerator();
	if (RandomGenAnswer == 5) 
	{
		cout << "Wait what is this you also got a " << SpecialFuzzlingItem << endl;
		cout << "They can be used to evolve your fuzzling would you like to use it ?"<<endl;
		cin >> Reusablechar;
		switch (tolower(Reusablechar)) 
		{
			ValidateChar();
		
		case'y':
			Playertype = SpecialFuzzling;
			cout << "Congratulations your fuzzling is now a " << Playertype << endl;



		case'n':
			cout << "You chose not to evolve your fuzzling" << endl;




		}
	}
	if (PFuzzlingsLevel == 10) 
	{
		cout << "Congratulations you have won the game" << endl;


	}
	FuzzlingStats();
	ChangeingLocation();
}

void PlayerLoses() 
{
	cout << endl;
	cout << endl;
	cout << "You unfortunetly lost the battel and was forced to run back to the lab as fast as you could" << endl;
	cout << "The good news is that your fuzzling is ok and ready to battle again" << endl;
	ChangeingLocation();
}

void EndOfTurnChecks()
{
	//cout << "PlayersSP" << PlayersSP << endl;

	if (PlayerHealth > PMaxhealth) 
	{
		PlayerHealth = PMaxhealth;

	}
	else if(EnemyHealth > EMaxhealth)
	{
	
		EnemyHealth = EMaxhealth;
	
	}

	if (PlayerHealth <= 0) 
	{
		PlayerLoses();

	}
	else if (EnemyHealth <= 0) 
	{
		PlayerWinsTheFight();

	}
	


	//cout << "PlayersSP" << PlayersSP << endl;
}

void PlayerTurnF()
//F stands for function since I already have a Bool with that name
{
	if (PlayersSP != PMaxSP)
	{
		//cout << PlayersSP << endl;
		PlayersSP = PlayersSP + 1;
		//cout << PlayersSP << endl;
	}

	PlayerDodge = false;
	EndOfTurnChecks();
	PlayerTurn = true;
	EnemyTurn = false;

	cout << "its your turn chose a action" << endl << endl;
	cout << "Please chose one of these actions" << endl;
	cout << endl << endl << "Attack (A)deals damage" << endl << endl << "Heal(H)heals a small amount of health" << endl << "(can still chose another action but it will be weakned and you can only heal once evey 3 turns)" << endl << endl << "Recharge(R)RechargesSPfaster but makes you more vulnerable" << endl << endl << "SpecialAttack(S) Uses SP to do more damage "<<PlayersSP << endl << endl << "Dodge(D) The user has a chance to dodge the attack" << endl << endl << "Identify(I) This will tell you the enemys current stats(won't take a turn)" << endl << endl << "(V)View your health"<<endl;
	ResetVariablesToDefault();
	while (ReusableBool == false)
	{
		cin >> Reusablechar;
		ValidateChar();
		switch (tolower(Reusablechar))
		{
		case 'a':
			ReusableBool = true;
			Attack();
			//The attack function is used
			break;

		case 'h':
			if (PHealingCount == 0)
			{
				if (PMaxhealth > PlayerHealth)
				{
					PHealingCount = 3;
					//cout << "Healing count = " << PHealingCount << endl; Used for debugging
					Heal();
					break;
				}
				else if(PlayerHealth = PMaxhealth )
				{
					cout << "Your fuzzling is at full health" << endl;
					break;
				}
				else 
				{
					DebugCode();
				}

			}
			else
			{
				cout << "You need to wait " << PHealingCount << " More turns untill you can heal" << endl;
				break;
			}



		case 'r':
			ReusableBool = true;
			
			if (PlayersSP = PMaxSP)
			{
				cout << "Your fuzzling is at full SP" << endl;
				break;
			}
			else 
			{

				RechargeSP();

			}
			break;

		case 's':
			ReusableBool = true;
			SpecialAttack();
			break;

		case 'd':
			ReusableBool = true;
			Dodge();
			break;

		case 'i':
			EnemyStats();
			break;

		case 'v':
			cout <<"you currently have "<<PlayerHealth<<" out of "<<PMaxhealth<<" Health"<<endl;
			cout << "you currently have " << PlayersSP << " out of " << PMaxSP << " SP" << endl;
			break;
	

		default:
			cout << "Please enter a valid value" << endl;
			break;
		}
		if (PHealingCount != 0) 
		{
			PHealingCount = PHealingCount - 1;

		}

	}



}

void EnemyTurnF() // Just like before the F is for function
{
	if (EnemySP != EMaxSP)
	{
		//cout << EnemySP << endl;
		EnemySP = EnemySP + 1;
		//cout << EnemySP << endl;

	}
	EnemyDodge = false;
	EnemyAction = false;
	EndOfTurnChecks();
	//cout << "PlayersSP" << PlayersSP << endl;
	cout << "The enemy is thinking" << endl;
	sleep_for(nanoseconds(10));
	sleep_until(system_clock::now() + seconds(2));
	RandomInt = 10;
	RandomInt2 = 20;
	RandomGenerator();
	//cout << "This code is activated" << endl; That was me debugging it
	
	
	PlayerTurn = false;
	EnemyTurn = true;

	if (EHealingCount == 0)
	{
		if (EnemyHealth < EMaxhealth) 
		{
			EHealingCount = 3;
			cout << "Enemy is healing" << endl;
			EnemyAction = true;
			Heal();
			
		}
	}
	//cout << "PlayersSP" << PlayersSP << endl;
	if (EnemySP < EMaxSP)
	{
		cout << "Enemy is Rechargeing" << endl;
		EnemyAction = true;
		RechargeSP();
	}
	else if (EnemyHealth < EMaxhealth / 4) 
	{
		cout << "Enemy is Dodgeing" << endl;
		EnemyAction = true;
		Dodge();
	}
	else 
	{
		//loop
	}

	
	if(EnemyAction == false)
	{
		RandomInt = 1;
		RandomInt2 = 10;
		RandomGenerator();
		if (RandomGenAnswer < 7) 
		{
			cout << "Attack code ran" << endl;

			Attack();
		}
		else 
		{
			cout << "Special Attack code ran" << endl;
			SpecialAttack();
		}
		

	}
	//cout << "PlayersSP" << PlayersSP << endl;

}

void Attack()
{
	int DamageDelt = 0;
	int Damage = 1;
	if (PlayerTurn == true)
	{
		Damage = PlayerDamage;


	}
	else if (EnemyTurn == true)
	{
		Damage = EnemyDamage;

	}
	else
	{
		DebugCode();
	}

	//Attack
	RandomInt = 1;
	RandomInt2 = 10;
	RandomGenerator();
	Hitchance = RandomGenAnswer;
	if (EnemyTurn == true)
	{
		if (PlayerRechargeing == true)
		{
			RandomInt = 5;
			RandomInt2 = 10;
			RandomGenerator();
			Hitchance = RandomGenAnswer;
		}

	}
	else if (PlayerTurn == true)
	{
		if (EnemyRechargeing == true)
		{
			RandomInt = 5;
			RandomInt2 = 10;
			RandomGenerator();
			Hitchance = RandomGenAnswer;
		}

	}
	
	/*Debugging will remove soon
	cout << "This code is activated" << endl;
	
	cout << RandomGenAnswer << endl; 
	*/
	if (Hitchance <= 2)
	{
		cout << "The attack missed" << endl;
		if (PlayerTurn == true)
		{
			EnemyTurnF();

		}
		else if (EnemyTurn == true)
		{
			PlayerTurnF();
		}
		else
		{
			DebugCode();

		}
		
	}
	else if (Hitchance >= 8)
	{
		cout << "It was a critical hit" << endl;
		DamageDelt = Damage * 2;
		if (PlayerTurn == true) 
		{
			
			cout << "You did " << DamageDelt << " damage to the " <<Enemy<< endl;
			EnemyHealth = EnemyHealth - DamageDelt ;
			EnemyTurnF();

		}
		else if (EnemyTurn == true)
		{
			cout << "The enemy "<<Enemy <<" delt "<< DamageDelt << " damage to you" << endl;
			PlayerHealth =   PlayerHealth - DamageDelt;
			PlayerTurnF();

		}
		else
		{
			DebugCode();

		}

	}
	else 
	{
		DamageDelt = Damage;
		if (PlayerTurn == true)
		{
			
			cout << "You did " << DamageDelt << " damage" << endl;
			EnemyHealth = EnemyHealth - DamageDelt  ;
			EnemyTurnF();
		}
		else if(EnemyTurn)
		{
			cout << "The enemy " << Enemy << " delt " << DamageDelt << " damage to you" << endl;
			PlayerHealth = PlayerHealth - DamageDelt ;
			PlayerTurnF();

		}
		else
		{
			DebugCode();

		}
	}
	
}

void Heal() //Will be used to heal the player
{
	if (PlayerTurn == true)
	{
		MaxHealingAmount = PMaxhealth / 6;
	}
	else if (EnemyTurn == true) 
	{
		 MaxHealingAmount = EMaxhealth / 6;


	}
	else 
	{
		DebugCode();

	}
	//cout << "The healing maxamount is " << MaxHealingAmount << endl; Was used for debugging
	int HealingAmount = 0;
	if(PlayerTurn == true)
	{
		if (PlayerHealth >= MaxHealingAmount)
		{
			HealingAmount = MaxHealingAmount;

			PlayerHealth = PlayerHealth + HealingAmount;
			cout << "You healed " << HealingAmount << " health back" << endl;
			//cout << "Part 1" << endl; Was used for debugging
			//cout <<"Healing count is"<< PHealingCount <<endl;

		}
		else
		{

			HealingAmount = PMaxhealth - PlayerHealth;
			PlayerHealth = PlayerHealth + HealingAmount;
			cout << "You healed " << HealingAmount << " health back" << endl;
			//cout << "Part 2" << endl; Was used for debugging
		}
	
	}
	else if (EnemyTurn == true) 
	{
		if (EnemyHealth >= MaxHealingAmount)
		{
			HealingAmount = MaxHealingAmount;

			EnemyHealth = EnemyHealth + HealingAmount;
			cout << "The "<<Enemy<<" healed " << HealingAmount << " health back" << endl;
			//cout << "Part 1" << endl; 
			//cout <<"Healing count is"<< PHealingCount <<endl;

		}
		else
		{
			
			HealingAmount = EMaxhealth - EnemyHealth;
			cout << HealingAmount << endl;
			EnemyHealth =EnemyHealth + HealingAmount;
			cout << "The " << Enemy << " healed " << HealingAmount << " health back" << endl;
			//cout << "Part 2" << endl; 
		}


	}
	else 
	{
		DebugCode();

	}
	

	if (PlayerTurn == true) 
	{
		PlayerTurnF();

	}
	else if (EnemyTurn == true)
	{
		EnemyTurnF();
	}
	else 
	{
		DebugCode();
	}


}

void Dodge() 
{
	RandomInt = 1;
	RandomInt2 = 10;
	RandomGenerator();
	if (PlayerTurn == true) 
	{
		if (RandomGenAnswer <= 8)
		{
			PlayerDodge = true;
			cout << "you sucesfully dodged there next attack" << endl;

		}
		else if (RandomGenAnswer >= 8)
		{
			PlayerDodge = false;
			cout << "The "<<Enemy<<" dodged there next attack" << endl;
		}
		else
		{
			DebugCode();
		}


	}
	else if (EnemyTurn == true) 
	{
		if (RandomGenAnswer <= 8)
		{
			EnemyDodge = true;

		}
		else if (RandomGenAnswer >= 8)
		{
			EnemyDodge = false;

		}
		else
		{
			cout<<"Dodge line 1017" << endl;
			DebugCode();
		}
	}
	
	if (PlayerTurn == true)
	{
		EnemyTurnF();

	}
	else if (EnemyTurn == true)
	{
		PlayerTurnF();
	}
	else
	{
		DebugCode();

	}

}

void SpecialAttack() 
{
	
	if (PlayerTurn == true)
	{
		if (EnemyDodge == false)
		{
			cout <<"PlayersSP"<< PlayersSP << endl;
			PlayersSP = (PlayersSP - 6);
			//cout << "PlayersSP" << PlayersSP << endl;
			EnemyHealth = EnemyHealth - (PlayerDamage * 3);
			cout << "You did " << PlayerDamage * 3 << "damage with your special attack" << endl;
		}
		else 
		{
			cout<<"The enemy dodged the attack"<<endl;

		}
	}


	
	
	if (EnemyTurn == true)
	{
		if(PlayerDodge == false)
		{

			EnemySP = EnemySP - 6;
			PlayerHealth = PlayerHealth - (EnemyDamage * 3);
		 	cout << "The enemy is useing its special attack !!!" << endl << endl;
			cout << "The enemy delt " << EnemyDamage * 3 << " Damage to you" << endl << endl;
		}
		else 
		{
			cout << "You successfuly dodged the " << Enemy << "'s attack" << endl;

		}

	}


	

	if (PlayerTurn == true)
	{
		EnemyTurnF();

	}
	else if (EnemyTurn == true)
	{
		PlayerTurnF();
	}
	else
	{
		cout << "Debug3" << endl;
		DebugCode();

	}
	
}

void RechargeSP()
{
	

	if (PlayerTurn == true) 
	{

		MaxSPReachageAmount = PMaxSP / 4;
		if (PMaxSP > PlayersSP) 
		{
			if (PlayersSP <= MaxSPReachageAmount)
			{
				SPRechargeAmount = MaxSPReachageAmount;

				PlayersSP = PlayersSP + SPRechargeAmount;
				cout << "You recharged " << SPRechargeAmount << " SP back" << endl;
				//cout << "Part 1" << endl; Was used for debugging
				//cout <<"Healing count is"<< PHealingCount <<endl;
				
			}
			else
			{
				SPRechargeAmount = PMaxSP - PlayersSP;
				PlayersSP = PlayersSP + SPRechargeAmount;
				cout << "You recharged " << SPRechargeAmount << " SP back" << endl;
				//cout << "Part 2" << endl; Was used for debugging
			}

			 //PlayersSP = PlayerSP + 

		}

	}
	else if (EnemyTurn == true)
	{
		MaxSPReachageAmount = EMaxSP / 4;
		if (EMaxSP > EnemySP)
		{
			if (EnemySP <= MaxSPReachageAmount)
			{
				SPRechargeAmount = MaxSPReachageAmount;

				EnemySP = EnemySP + SPRechargeAmount;
				cout << "You recharged " << SPRechargeAmount << " SP back" << endl;
				//cout << "Part 1" << endl; Was used for debugging
				//cout <<"Healing count is"<< PHealingCount <<endl;

			}
			else
			{
				SPRechargeAmount = EMaxSP - EnemySP;
				EnemySP = EnemySP + SPRechargeAmount;
				cout << "The "<<Enemy<<" recharged "<< SPRechargeAmount <<" SP back" << endl;
				//cout << "Part 2" << endl; Was used for debugging
			}

			//PlayersSP = PlayerSP + 

		}
	}
	else 
	{
		DebugCode();

	}
	
	if (PlayerTurn == true)
	{
		EnemyTurnF();

	}
	else if (EnemyTurn == true)
	{
		PlayerTurnF();
	}
	else
	{
		DebugCode();

	}

}

void EnemyStats() // This will change depending on the enemy
{
	cout << "The stats of the " << Enemy << " Stats are as follows" << endl;
	cout << "Health = " << EnemyHealth <<" Out of "<<EMaxhealth<< endl;
	cout << "Speed = " << EnemySpeed << endl;
	cout << "Damage = " << EnemyDamage << endl;
	cout << "level = " << EnemysFuzzlingsLevel << endl;
	cout << "SP = " << EnemySP <<" Out of "<<EMaxSP<< endl; 
	cout << "Fuzzlings Type:" << EType << endl;
	cout << endl;

}

void Fight()
{
	cout << "You are now fighting the enemy" << endl;

	if (PlayerSpeed > EnemySpeed)
	{
		PlayerTurn = true;
		EnemyTurn = false;
	}
	else if (PlayerSpeed == EnemySpeed)
	{
		RandomInt = 1;
		RandomInt2 = 2;
		RandomGenerator();
		if (RandomGenAnswer == 1)
		{
			PlayerTurn = true;
			EnemyTurn = false;

		}
		else
		{
			PlayerTurn = false;
			EnemyTurn = true;

		}
	}
	else
	{
		PlayerTurn = false;
		EnemyTurn = true;

	}

	if (PlayerTurn == true)
	{
		PlayerTurnF();



	}
	else
	{
		cout << "The enemy fuzzling is faster so it will chose a action first" << endl;
		EnemyTurnF();
	}
}

void AtteptingToRun() 
{
	int Runchance = 1;
	int EnemyChaseChance = 1;

	RandomInt = 1 ;
	RandomInt2 = 5;
	RandomGenerator();
	Runchance = RandomGenAnswer + PlayerSpeed;
	RandomGenerator();
	EnemyChaseChance = RandomGenAnswer + EnemySpeed;

	if (Runchance >= EnemyChaseChance)
	{
		cout <<"You successfully ran away"<<endl;

	}
	else
	{
		cout<< "you tried to escape but the " << Enemy << " caught you" << endl;
		Fight();
	}


}

void Maxhealth()
{
	PMaxhealth = PlayerHealth;
	EMaxhealth = EnemyHealth;

}

void GeneratePlayerFuzzlingsBaseStats()
{
	//Player's health
	RandomInt =  1;
	RandomInt2 = 2;
	RandomGenerator();
	PlayerHealth = (PFuzzlingsLevel + RandomGenAnswer) * 12;
	PMaxhealth = PlayerHealth;
	//now damage
	RandomInt = 2;
	RandomInt2 = 5;
	RandomGenerator();
	PlayerDamage = PFuzzlingsLevel + RandomGenAnswer;
	//Now speed
	RandomInt = 2;
	RandomInt2 = 4;
	RandomGenerator();
	PlayerSpeed = PFuzzlingsLevel + RandomGenAnswer;
	//SP
	PlayersSP = PFuzzlingsLevel * 2;
	PMaxSP = PlayersSP;
	
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
	RandomInt = PFuzzlingsLevel - 2;
	RandomInt2 = PFuzzlingsLevel + 1;
	RandomGenerator();
	EnemysFuzzlingsLevel = RandomGenAnswer;
	// This next part is for health
	RandomInt = 1;
	RandomInt2 = 2;
	RandomGenerator();
	EnemyHealth = (EnemysFuzzlingsLevel + RandomGenAnswer) * 12;
	EMaxhealth = EnemyHealth;
	
	// This next part is the base damage it can do more or less later
	RandomInt = 2;
	RandomInt2 = 5;
	RandomGenerator();
	EnemyDamage = EnemysFuzzlingsLevel + RandomGenAnswer; 
	//This next part is speed
	RandomInt = 2;
	RandomInt2 = 4;
	RandomGenerator();
	EnemySpeed = EnemysFuzzlingsLevel + RandomGenAnswer;
	//This is its sp it will always be 2x the level so if its level 5 it will be 10
	EnemySP = EnemysFuzzlingsLevel * 2;
	EMaxSP = EnemySP;
}

void RandomEncounter() //The code for random encounters
{


	RandomInt = 1;
	RandomInt2 = 6;
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
	EType = Enemy;
	EnemyStatsdecideing();
	Maxhealth();
	cout << "Do you chose to Fight(F) or Run(R) ? (default is Fight)" << endl;
	Reusablechar = 'F';
	cin >> Reusablechar;
	ValidateChar();
	switch (tolower(Reusablechar))
	{
	case'f':
		cout << "You have chosen to fight the " << Enemy << endl;
		Fight();
		ResetVariablesToDefault();
		break;
	case'r':
		cout << "You have chosen to try and run from the " << Enemy << " The speed of your fuzzlings will now be compared and you will have a chance to escape" << endl;
		AtteptingToRun();
		ResetVariablesToDefault();
		
		break;
	default:
	break;
	}

	



}

//Some old unused code 
    /*
	if (Reusablechar == 'Y')
	{
		cout << "Please enter your fuzzlings name";
		cin >> nameOfFirstFuzzling;
	}
	else if (Reusablechar == 'N')
	{
		cout << "Are you sure ? Your fuzzling will just be called Fuzz by default" << endl;
		cout << "Please enter Y or n" << endl;
		cin >> Reusablechar;
		if (Reusablechar == 'y')
		{
			cin >> nameOfFirstFuzzling;
		}
		else if (Reusablechar == 'n')
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

void DebugCode() //This will be used for me to debug stuff
{

	cout << "You have mucked up the code somewhere please fix" << endl << endl;
	cout << "yourName " << yourName << endl;
	cout << "yourDisplayName " << yourDisplayName << endl;
	cout << "nameOfIntroductionGuy " << nameOfIntroductionGuy << endl;
	cout << "nameOfNPC " << nameOfNPC << endl;
	cout << "nameOfFirstFuzzling " << nameOfFirstFuzzling << endl;
	cout << "ReusableeAnswer " << ReusableeAnswer << endl;
	cout << "Reusablechar " << Reusablechar << endl;
	cout << "ReusableBool " << ReusableBool << endl;
	cout << "AmountOfFuzzlings " << AmountOfFuzzlings << endl;
	cout << "location " << location << endl;
	cout << "RandomInt " << RandomInt << endl;
	cout << "RandomInt2 " << RandomInt2 << endl;
	cout << "SpecialFuzzling " << SpecialFuzzling << endl;
	cout << "SpecialFuzzlingItem " << SpecialFuzzlingItem << endl;
	cout << "Enemy " << Enemy << endl;
	cout << "RandomGenAnswer " << RandomGenAnswer << endl;
	cout << "PMaxhealth " << PMaxhealth << endl;
	cout << "PlayerHealth " << PlayerHealth << endl;
	cout << "PlayerSpeed " << PlayerSpeed << endl;
	cout << "EnemyDamage" << EnemyDamage << endl;
	cout << "EnemysFuzzlingsLevel  " << EnemysFuzzlingsLevel << endl;
	cout << "EnemySP " << EnemySP << endl;
	cout << "EType " << EType << endl;
	cout << " PlayerTurne " << PlayerTurn << endl;
	cout << "EnemyTurn " << EnemyTurn << endl;
	cout << "PlayerRechargeing " << PlayerRechargeing << endl;
	cout << "LocationPicked "  << LocationPicked << endl;
	cout << "PHealingCount " << PHealingCount << endl;
	cout << "DamageDelt " << DamageDelt << endl;
	cout << "Damage " << Damage << endl;
	cout << "MaxHealingAmount " << MaxHealingAmount << endl;
	cout << "HealingAmount " << HealingAmount << endl;
	cout << "Runchance " << Runchance << endl;
	cout << "EnemyChaseChance " << EnemyChaseChance << endl;



}


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
	cout << yourDisplayName << " Basic Fuzzling? You mean to tell me there is more ?" << endl;
	cout << nameOfIntroductionGuy << " Yes Fuzzlings come with many different types which have unique abilities."<<endl<<"They can also have strengths and weaknesses against other types." << endl<<"Your fuzzling is also able to evolve into different types and has no strengths or weaknesses because its basic so hasen't evolved yet" << endl;
	cout << nameOfIntroductionGuy << " Anyway, here is your fuzzling" << endl;
	NameingFuzzling();
	cout << " Your Fuzzling is officaly called " << nameOfFirstFuzzling << endl;
	cout << nameOfIntroductionGuy <<""<< yourName << " Congratulations you did it you and " << nameOfFirstFuzzling << " are officaly ready for your first adventure" << endl;
	GeneratePlayerFuzzlingsBaseStats();
	ResetVariablesToDefault();
	cout << " Would you like to know the stats of your fuzzling ?"<<endl;
	while (ReusableBool == false)
	{
		cout << "Y for yes N for no" << endl;
		cin >> Reusablechar;
		ValidateChar();
		switch (tolower(Reusablechar))
		{
		case'y':
			ReusableBool = true;
			FuzzlingStats();
			break;
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
	while(true)
	{
	ChangeingLocation();
	RandomEncounter();
	}


	system("PAUSE");
}





