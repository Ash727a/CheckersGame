#ifndef LOGS_H
#define LOGS_H

#include <iostream> 
#include <fstream>
#include <string>

#include "GameConfig.h" 



class Logs {
	

	private:

		GT::GameInputs Inputs;  // for Game logs 

	public:

		Logs						(); 
		~Logs						(); 

		void Input_GameLog			(GT::Inputs,GT::Diagonal,GT::Player);
		void Write_Inputs			(const std::string&);
		void Read_Inputs			(const std::string& GameName);
		void AppendPlayerScores		(); 
		void AppendGameName         (const std::string&); 

};


#endif // !LOGS_H


