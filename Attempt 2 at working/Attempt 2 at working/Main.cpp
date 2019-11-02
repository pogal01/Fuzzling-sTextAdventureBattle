#include <iostream>
#include <random>
#include <ctime>
using namespace std;
string yourName = "You";  //Players name
string yourDisplayName = yourName+":"; //Simplely your name with a : at the end so you can tell its you who is speaking and I don't have to hard code a : evey time.
string nameOfIntroductionGuy = "???:"; //Variable for the guy who speaks at the start
string nameOfNPC = "???:"; // Variable for first other guys you meet I just have to simply reset it to ??? if they are going to speak to someone new
string nameOfFirstFuzzling = "Fuzz"; //Name of your fuzzling will be used in the battel and story
string Reusableeawnser = "N/A"; // Saves me from making millions of variables
char Reusableechar = '?'; // saves me from making many char variables (mainly for switch statements)
bool ReusableBool = false;
int AmountOfFuzzlings = 0; // This might or might not be used later if the player can have multaple fuzzlings. the idea is to allow them to use the Nameing function to name each one I will probably need a dynamic array for this.
string location = "Lab"; //This just displays the current location useful for which creatures will pop up
int SiturationalInt = 1; //Used in random generator can be changed depending on what I want
int SituratinalInt2 = 6; //Used in random generator can be changed depending on what I want
string SpecialFuzzling; // This is to determine which enemy will be faced it will depend on the location
string Enemy; // just a variable to determine what the enemy is


//Function to name your fuzzling Basicalu just exists so I can collapse the code
void NameingFirstFuzzling()
{
	bool FuzzlingHasName = false;
	char UserNameFuzzling;
	
	while (FuzzlingHasName == false)

	{ 
		cin >> UserNameFuzzling;
		switch (UserNameFuzzling)
		{
		case 'Y'://I could have put this next part in its own function but I chose not to since it was easy to just copy and paste it twice
			cout << "Please enter your fuzzlings name"<<endl;
			cin >> nameOfFirstFuzzling;
			cout << "So you want to name your fuzzling" << nameOfFirstFuzzling << " Correct ?"<<endl;
			cin >> Reusableeawnser; // This is a generic variable which I can use over and over for players choices
			if (Reusableeawnser == "Y")
			{
				FuzzlingHasName = true;
				break;
				
			}
			else if (Reusableeawnser == "y")
			{
				FuzzlingHasName = true;
				break;

			}
			else if (Reusableeawnser == "N")
			{
				//Should just loop


			}
			else if (Reusableeawnser == "n")
			{
				//Should just loop


			}
			else 
			{
				cout << "Please enter either Y for yes or N for No";
			}
			break;
		case 'y':
			cout << "Please enter your fuzzlings name" << endl;
			cin >> nameOfFirstFuzzling;
			cout << "So you want to name your fuzzling " << nameOfFirstFuzzling << " Correct ? (please still enter either y or n)"<<endl;
			cin >> Reusableeawnser;
			if (Reusableeawnser == "Y")
			{
				FuzzlingHasName = true;
				break;

			}
			else if (Reusableeawnser == "y")
			{
				FuzzlingHasName = true;
				break;

			}
			else if (Reusableeawnser == "N")
			{
				//Should just loop


			}
			else if (Reusableeawnser == "n")
			{
				//Should just loop


			}
			else
			{
				
			}

		case 'N': //I could have put this next part in its own function but I chose not to since it was easy to just copy and paste it twice
			cout << "Are you sure ? Your fuzzling will just be called Fuzz by default" << endl;
			cout << "Please enter Y if you are sure that you don't want to name your fuzzling or N if you actually do" << endl;
			cin >> UserNameFuzzling;

			if (UserNameFuzzling == 'y')
			{
				cout << "What would you like to name your fuzzling" << endl;
				cin >> nameOfFirstFuzzling;
			}
			else if (UserNameFuzzling == 'n')
			{
				cout << "Ok your fuzzling is called Fuzz" << endl;
				nameOfFirstFuzzling = "Fuzz";
			}
			else
			{
				cout << "Please enter either y or n" << endl;
				NameingFirstFuzzling();
			}
		case 'n': //I could have put this next part in its own function but I chose not to since it was easy to just copy and paste it twice
			cout << "Are you sure ? Your fuzzling will just be called Fuzz by default" << endl;
			cout << "Please enter Y if you are sure that you don't want to name your fuzzling or N if you actually do" << endl;
			cin >> UserNameFuzzling;

			if (UserNameFuzzling == 'n')
			{
				//Should just loop
			}
			else if (UserNameFuzzling == 'y')
			{
				cout << "Ok your fuzzling is called Fuzz" << endl;
				nameOfFirstFuzzling = "Fuzz";
				FuzzlingHasName = true;
				break;
			}
			else if (UserNameFuzzling == 'Y')
			{
				cout << "Ok your fuzzling is called Fuzz" << endl;
				nameOfFirstFuzzling = "Fuzz";
				FuzzlingHasName = true;
				break;
			}
			else if (UserNameFuzzling == 'N')
			{
				//Should just loop
			}
			else
			{
				cout << "Please enter either y or n" << endl;
			}

		default:
			cout << "Would you like to name your Fuzzling ?" << endl;
			cout << "Please enter either Y for yes or N for No"<<endl;
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
		cout << "Please make sure to capitalize your awnser" << endl;
		cin >> Reusableechar;
		switch (Reusableechar)
		{
		case 'F':
			location = "Forest";
			cout << "So you would like to go to the " << location <<"? "<< endl;
			cout << "Y for yes or N for no"<<endl;
			cin >> Reusableeawnser;
			if (Reusableeawnser == "Y") 
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				break;
			}
			else if (Reusableeawnser == "y")
			{
			LocationPicked = true;
			cout << "You are now at the " << location << endl;
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
			cin >> Reusableeawnser;
			if (Reusableeawnser == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				break;
			}
			else if (Reusableeawnser == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
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
			cin >> Reusableeawnser;
			if (Reusableeawnser == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				break;
			}
			else if (Reusableeawnser == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
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
			cin >> Reusableeawnser;
			if (Reusableeawnser == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				break;
			}
			else if (Reusableeawnser == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				break;
			}
			else
			{
				break;
			}
		

		case 'Y':
			location = "Junkyard";
			cout << "So you would like to go to the " << location << "? " << endl;
			cin >> Reusableeawnser;
			if (Reusableeawnser == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				break;
			}
			else if (Reusableeawnser == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
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
			cin >> Reusableeawnser;
			if (Reusableeawnser == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				break;
			}
			else if (Reusableeawnser == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
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
			cin >> Reusableeawnser;
			if (Reusableeawnser == "Y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
				break;
			}
			else if (Reusableeawnser == "y")
			{
				LocationPicked = true;
				cout << "You are now at the " << location << endl;
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

void RandomEncounter() 
{

	mt19937 generator;
	generator.seed(time(0));

	uniform_int_distribution<uint32_t> dice(SiturationalInt, SituratinalInt2);  //This is so I can change the numbers if I need to on other scripts

	cout << "Wait what is this ?"<<endl;

	int random = dice(generator);

	if (random <= 3) 
	{
		cout << "you have encountered a basic Fuzzling" << endl;

	}
	else
	{
		cout << "You have encountered a  " << SpecialFuzzling << endl;

	}
	cout << "Do you chose to Fight(F) or Run(R) ? (default is Fight)" << endl;
	Reusableechar = 'F';
	cin >> Reusableechar;
	switch (Reusableechar)
	{
	case'F':
		cout << "You have chosen to fight the " << Enemy << endl;

	case'R':
		cout << "You have chosen to try and run from the " << Enemy <<" The speed of your fuzzlings will now be compared and you will have a chance to escape"<< endl;

	default:
	break;
	}

	



}




	//Some old unused code
    /*
	if (UserNameFuzzling == 'Y')
	{
		cout << "Please enter your fuzzlings name";
		cin >> nameOfFirstFuzzling;
	}
	else if (UserNameFuzzling == 'N')
	{
		cout << "Are you sure ? Your fuzzling will just be called Fuzz by default" << endl;
		cout << "Please enter Y or n" << endl;
		cin >> UserNameFuzzling;
		if (UserNameFuzzling == 'y')
		{
			cin >> nameOfFirstFuzzling;
		}
		else if (UserNameFuzzling == 'n')
		{
			cout << "Ok your fuzzling is called Fuzz" << endl;
			nameOfFirstFuzzling = "Fuzz";
		}
		else
		{
			cout << "Please enter either y or n" << endl;
			NameingFirstFuzzling();
		}
	}
	else
	{
		cout << "Please enter either y or n" << endl;
		NameingFirstFuzzling();
	}
	
}
*/
int main()
{
	cout << nameOfIntroductionGuy << " Hello Welcome to the Fuzzling battel simulator." << endl << "Fuzzlings are mythical creatures that all have diffrent elements. You will be useing them to battle" << endl;
	cout << nameOfIntroductionGuy << " So Sorry I forgot to tell you my name. My name is Professor Pogal and I will introduce you into this world" << endl;
	nameOfIntroductionGuy = "Professor Pogal:";
	cout << nameOfIntroductionGuy << " May I ask what your name is ?" << endl;
	cout << "Please enter your name" << endl;
	cin >> yourName;
	yourDisplayName = yourName + ":"; // This is when it adds the : to your name so it can be displayed at the beginning to show you are talking but if a character references you they will use yourname instead since you don't need a colon after names mid sentance
	cout << nameOfIntroductionGuy << " Ah your name is " << yourName << " Its nice to meet you and I wish you luck on your adventure" << endl << endl;
	cout << yourDisplayName << " Wait! What is a Fuzzling and how do I get one ?" << endl;
	cout << nameOfIntroductionGuy << " Oh right I forgot thanks for reminding me" << endl;
	cout << nameOfIntroductionGuy << " I was supposed to give you a basic Fuzzling" << endl;
	cout << yourDisplayName << "Basic Fuzzling? You mean to tell me there is more ?" << endl;
	cout << nameOfIntroductionGuy << " Yes Fuzzlings come with many different types and unique abilities.They can also have strengths and weaknesses against other types." << endl<<" Your fuzzling is also able to evolve into different types and has no strengths or weaknesses before that" << endl;
	cout << nameOfIntroductionGuy << " Anyway, here is your fuzzling" << endl;
	cout << "would you like to name your Fuzzling?" << endl;
	cout << "Press Y for yes and N for no" << endl;
	NameingFirstFuzzling();
	cout << "Your Fuzzling is officaly called " << nameOfFirstFuzzling << endl;
	cout << nameOfIntroductionGuy <<""<< yourName << " Congratulations you did it you and " << nameOfFirstFuzzling << " are officaly ready for your first adventure" << endl;
	cout << "Would you like to know the stats of your fuzzling ?"<<endl;
	while (ReusableBool == false)
	{
		cout << "Y for yes N for no" << endl;
		cin >> Reusableechar;
	}
	ChangeingLocation();
	RandomEncounter();



	system("PAUSE");
}


//This function is what is used to name the first fuzzling


