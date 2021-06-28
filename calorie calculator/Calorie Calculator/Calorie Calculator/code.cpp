#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char activityChoice;
string gainOrLose, sexChoice, name;
double weight, height, age, BMR;
double inches, feet, calories;
bool isMale, isFemale;

void verifyGainOrLose();
void verifyAge();
void verifySex();
void verifyWeight();
void getHeight();
void getActivity();
void getBMR();
void getNewCalories();
void gainWeight();
void loseWeight();

int main()
{
	
	cout << "Calorie Calculator! \n";
	cout << "What is your full name? ";
	getline(cin, name);
	cout << "Do you need to gain weight or lose weight? \n";
	cin >> gainOrLose;

	verifyGainOrLose();
	
	if (gainOrLose == "Gain" || gainOrLose == "gain")
	{
		gainWeight();
	}
	else if(gainOrLose == "Lose" || gainOrLose == "lose")
	{
		loseWeight();
	}

	return 0;
}

void verifyGainOrLose()
{
	while (gainOrLose != "Gain" && gainOrLose != "gain" && gainOrLose != "Lose" && gainOrLose != "lose")
	{
		cout << "You have to choose either gain or lose: ";
		cin >> gainOrLose;
	}
}

void verifyAge()
{
	cout << "How old are you? ";
	cin >> age;

	while (age < 15 || age > 80)
	{
		cout << "Please enter an age between 15 and 80: ";
		cin >> age;
	}
}

void verifySex()
{
	cout << "Are you male or female? ";
	cin >> sexChoice;

	while (sexChoice != "Male" && sexChoice != "male" && sexChoice != "Female" && sexChoice != "female")
	{
		cout << "You have to enter either male or female ";
		cin >> sexChoice;
	}

	if (sexChoice == "Male" || sexChoice == "male")
	{
		isMale = true;
		isFemale = false;

	}
	else if (sexChoice == "Female" || sexChoice == "female")
	{
		isFemale = true;
		isMale = false;

	}
	
}

void verifyWeight()
{
	cout << "How much do you weigh in lbs? ";
	cin >> weight;

	while (weight < 10 || weight > 1000)
	{
		cout << "Enter a valid weight in lbs: ";
		cin >> weight;
	}

}

void getHeight()
{
	cout << "How tall are you? \n";

	cout << "Feet: ";
	cin >> feet;

	while (feet < 2 || feet > 8)
	{
		cout << "You can't be that tall! Try again, feet: ";
		cin >> feet;
	}

	cout << "Inches: ";
	cin >> inches;

	while (inches > 11 || inches < 0)
	{
		cout << "Enter inches again: ";
		cin >> inches;
	}

	height = (feet * 12) + inches;

	//cout << "Height: " << height << " inches";
}

void getActivity()
{
	cout << "How active are you per day? \n";
	cout << "A. Sendentary: Little to no exercise \n";
	cout << "B. Light: 1-3 days of exercise per week \n";
	cout << "C. Active: Daily exericse or intense exercise 3-4 times per week \n";
	cout << "D. Very active: Intense exercise 6-7 times per week \n";
	cout << "E. Extra active: Intense exercise daily, or a physical job \n";

	cin >> activityChoice;

	switch (activityChoice)
	{
	case 'A':
	case 'a':

		calories = BMR * 1.2;
		cout << "Matinence Calories: " << calories << endl;

		getNewCalories();
		
		break;

	case 'b':
	case 'B':

		calories = BMR * 1.375;
		cout << "Matinence Calories: " << calories << endl;

		getNewCalories();

		break;

	case 'c':
	case 'C':

		calories = BMR * 1.55;
		cout << "Matinence Calories: " << calories << endl;

		getNewCalories();
		break;
	
	case 'd':
	case 'D':

		calories = BMR * 1.725;
		cout << "Matinence Calories: " << calories << endl;

		getNewCalories();

		break;
	
	case 'e':
	case 'E':
		calories = BMR * 1.9;
		cout << "Matinence Calories: " << calories << endl;

		getNewCalories();

		break;

	default:

		cout << "Enter a valid input from the menu: ";

	}
	
}

void getBMR()
{
	if (isMale)
	{
		isFemale = false;

		BMR = 66 + (6.2 * weight) + (12.7 * height) - (6.76 * age);
	}
	else if (isFemale)
	{
		isMale = false;

		BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
	}
}

void getNewCalories()
{
	if (gainOrLose == "Gain" || gainOrLose == "gain")
	{
		calories += 900;
		cout << "In order to be in a caloric surplus, you need to eat about " << calories << " calories per day " << endl;
	}
	else if (gainOrLose == "Lose" || gainOrLose == "lose")
	{
		calories -= 500;
		cout << "In order to be in a caloric deficit, you need to eat about " << calories << " calories per day" << endl;

	}
}

void gainWeight()
{
	cout << "Nice, it seems like you want to gain some weight \n";

	verifyAge();
	verifySex();
	verifyWeight();
	getHeight();
	getBMR();
	getActivity();
}

void loseWeight()
{
	cout << "Nice, it seems like you want to lose some weight \n";

	verifyAge();
	verifySex();
	verifyWeight();
	getHeight();
	getBMR();
	getActivity();
}

