#include "Learner.h"
#include <iostream>
#include <fstream>
#include <string> 


using namespace std;
/* 
	The following function will look for the passed phrase in the memory file.
	If there is a match, the accompanying response, stored below the initial phrase, will be outputed.
	If the response cannot be found, the Learner will repeat the phrase, and prompt the user to enter an ideal response.
	This response will be stored in the memory file along with the initial phrase.
*/

void Learner::respond(string phrase){
	fstream memory;
	memory.open("memory/memory.txt", ios::in);

	// Search through the file until the end is reached
	while (!memory.eof()){  // while not at end of file
		string identifier;
		getline(memory, identifier);  //get next phrase

		if (identifier == phrase){ // Is it the phrase we are looking for
			string response;
			getline(memory, response); //if so, get the response
			voice.say(response); // textually and audibly output the response!
			return;   //Leave the function
		}
	}

	memory.close(); //looks like we couldnt find the phrase in memory. close the file!
	memory.open("memory/memory.txt", ios::out | ios::app); //now open for output, and append at end of file
	memory << phrase << endl; //record initial phrase in memory

	voice.say(phrase); //repeat the phrase the user entered
	string userResponse;
	cout << "YOU: ";
	getline(cin, userResponse);        //get the ideal response
	memory << userResponse << endl;   //write the ideal response to memory
 	memory.close();           //close the file
}


/*
	This function simply communicates a phrase textually and audibly
*/

void Learner::say(string phrase){
	this->voice.say(phrase);
}
