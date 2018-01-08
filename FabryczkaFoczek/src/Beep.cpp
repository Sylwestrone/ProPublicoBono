#include "Beep.h"

Beeep::Beeep()
{
    frequency = 0;
    pause = 0;
    dotTime = 0;
    dashTime = 0;
    spacePause = 0;
    charPause = 0;
}

Beeep::~Beeep()
{
    //dtor
}

void Beeep::setExternalInfo(std::string info)
{
    std::string tmp;
    std::stringstream stream(info);
    stream >> tmp;
    frequency = std::atoi(tmp.c_str());


    stream >> tmp;
    dotTime = std::atoi(tmp.c_str());

    stream >> tmp;
    dashTime = std::atoi(tmp.c_str());

    stream >> tmp;
    spacePause = std::atoi(tmp.c_str());

    stream >> tmp;
    pause = std::atoi(tmp.c_str());

    stream >> tmp;
    charPause = std::atoi(tmp.c_str());
    std::cout << info;
}


void Beeep::convert(std::string text)
{
    std::string result = translator.convert(text);
    for(int i = 0; i < result.size(); ++i)
    {
        if (result[i] == '.')
		{
			Beep(frequency, dotTime);
			Sleep(dotTime);
		}
		else if (result[i] == '-')
		{
			Beep(frequency, dashTime);
			Sleep(dashTime);
		}
		if(result[i] == ' ')
        {
            Sleep(pause);
        }
	}
	Beep(0, charPause);
}

void Beeep::convert(int number)
{
    std::string numberStr = to_string(number);
    convert(number);
}

Beeep& Beeep::operator<<(std::string text)
{
    convert(text);
    return *this;
}
