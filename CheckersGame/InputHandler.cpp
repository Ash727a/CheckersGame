#include "InputHandler.h"

InputHandler::InputHandler()
{

}

InputHandler::~InputHandler()
{

}

void InputHandler::ParseInputs(const GT::Inputs& input)
{
	this->x = static_cast<GT::Coord>(input[0] - GT::yOffset);
	this->y = static_cast<GT::Coord>(input[1] - GT::xOffset);

}


GT::Coord  InputHandler::get_x() const
{
	return this->x;
}

GT::Coord  InputHandler::get_y() const
{
	return this->y; 
}

