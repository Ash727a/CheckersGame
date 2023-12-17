#include "Logs.h"

Logs::Logs()
{

}

Logs::~Logs()
{
    Inputs.clear(); // clean out buffer 
}

void Logs::Input_GameLog(GT::Inputs PawnPos, GT::Diagonal Diagonal, GT::Player currentPlayer) // this should work for all use cases 
{
    Inputs.push_back(
        {
            PawnPos,
            Diagonal,
            currentPlayer
        }
    );
}

void Logs::Write_Inputs(const std::string& GameName)
{
    std::ofstream* GameLog = new  std::ofstream(GT::GameLog, std::ios::binary | std::ios::app); // making sure its in append mode and not nuking anything

    if (GameLog->is_open())
    {
        *GameLog << GameName << "\n";

        for (auto i = Inputs.begin(); i != Inputs.end(); i++) // Output iterator 
        {
            *GameLog

                << i->PawnLocation << " "
                << i->Diag << " "
                << i->Currentplayer << " ";

            if (std::next(i) != Inputs.end())
            {
                *GameLog << " ";
            }

        }
        /*
            Output iterator writes the elements in the sequence to a file 
        */

        *GameLog << "\n";
    }
    else
    {
        throw(GT::FILERRR); 
    }

    Inputs.clear(); // remove all contents from the list 
    delete GameLog;
}

void Logs::Read_Inputs(const std::string& GameName) // use this to pass in a queue data structure to queue the inputs 
{
    std::ifstream* GameLog = new std::ifstream(GT::GameLog, std::ios::binary); 
    bool is_found = false; 

    if (GameLog->is_open())
    {
        std::string tmp; 

        while (std::getline(*GameLog, tmp))
        {
            if (tmp == GameName)
            {
                is_found = true; 
                break; 
            }
        }

        if (is_found)
        {
            while (std::getline(*GameLog, tmp) && !tmp.empty())
            {
                std::cout << tmp << std::endl; 
            }
        }
        else
        {
            std::cout << "Nothing here exists \n"; 
        }
    }
    else
    {
        std::cout << "File error\n"; 
    }

    delete GameLog; 

}

void Logs::AppendGameName(const std::string& GameName)
{
    std::ofstream* GameLog = new  std::ofstream(GT::GameNames, std::ios::binary | std::ios::app); // making sure its in append mode and not nuking anything

    if (GameLog->is_open())
    {
        *GameLog << GameName << "\n";
    }
    else
    {
        throw(GT::FILERRR);
    }

    delete GameLog;
}

void Logs::LoadGameNames()
{
    std::ifstream* GameNames = new std::ifstream(GT::GameNames, std::ios::binary); 
    std::string tmpdata; 

    if (GameNames->is_open())
    {
        while (!GameNames->eof())
        {
            *GameNames >> tmpdata; 
            std::cout<<"Game: "<< tmpdata << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to open file \n"; 
    }
}
