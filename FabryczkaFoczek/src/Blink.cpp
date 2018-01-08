#include "Blink.h"

Blink::Blink()
{
	pause = 0;
	dotTime = 0;
	dashTime = 0;
	spacePause = 0;
	charPause = 0;
    actualPause = 0;
}

Blink::~Blink()
{
    //dtor
}

void Blink::setExternalInfo(std::string info)
{
    std::string tmp;
    std::stringstream stream(info);

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

void Blink::capsLockBlink()
{
	INPUT in[2];
	in[0].type = INPUT_KEYBOARD;
	in[0].ki.wVk = VK_CAPITAL;       // wVk wirtualn klawisz wcisniety
	in[0].ki.wScan = 0;          //in 0 wcisniecie klawisza
	in[0].ki.time = 0;
	in[0].ki.dwFlags = 0;
	Sleep(actualPause);
	in[0].ki.dwExtraInfo = 0;
	in[1] = in[0];                 //in 1 puszczenie klawisza
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(2, in, sizeof(INPUT));
}

void Blink::convert(std::string text)
{
    std::string result = translator.convert(text);

	for(int i = 0; i < result.size(); ++i)
    {
        if (result[i] == '.')
		{
			capsLockBlink();
			actualPause = dotTime;
		}
		else if (result[i] == '-')
		{
		    capsLockBlink();
		    actualPause = dashTime;
		}
		else if(result[i] == ' ')
        {
            actualPause = pause;
        }
	}

}

void Blink::convert(int number)
{
    convert(to_string(number));
}

Blink& Blink::operator<<(std::string text)
{
    convert(text);
}
