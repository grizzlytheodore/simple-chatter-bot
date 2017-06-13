#include <iostream>
#include <string>
#include "learner.h"

using namespace std;

int main(){
	Learner AI;
	cout << "Chatter Bot by Theodore Chang\n";
	/*
		The Following is the main loop. It will continue until the application is closed.
		The user enters their input, and then the learner will respond.
	*/

	for (;;){
		cout << "\nYOU: "; //User prompt
		string phrase;
		getline(cin, phrase); //using getline for multi word input, then store in phrase
		 
		cout << "COMPUTER: ";  
		AI.respond(phrase); //pass the user input to the learner and see if he can respond
	}
}