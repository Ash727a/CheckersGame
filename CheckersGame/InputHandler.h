#ifndef  INPUTHANDLER_H
#define INPUTHANDLER_H

#include "GameConfig.h"

class InputHandler {

	private: 

		GT::Coord y; 
		GT::Coord x; 

	public: 

		 InputHandler		 				(); 
		~InputHandler						();

		void ParseInputs					(const GT::Inputs&);
		GT::Coord get_x						() const; 
		GT::Coord get_y						() const; 

};


#endif INPUTHANDLER_H

