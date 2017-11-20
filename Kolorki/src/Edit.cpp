#include "Edit.h"
#include <cstdio>

Edit::Edit()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    posX = 0;
    posY = 0;
    length = 0;
    text = "";
    textColor = 0;
    backgroundColor = 0;
}

Edit::~Edit()
{

}

Edit::Edit(const Edit& other)
{
    //copy ctor
}


// Metoda pobiera wspolrzedne poczatkowej pozycji kursora i ustawia ja.
void Edit::setPosition(const int posX, const int posY)
{
    this->posX = posX;
    this->posY = posY;
    coord.X = posX;
    coord.Y = posY;
    SetConsoleCursorPosition(handle, coord);
}

void Edit::setLength(const int length)
{
    this->length = length;
}

void Edit::setText(std::string text)
{
    this->text = text;
    text.resize(length);
}

void Edit::setTextColor(const int color)
{
    this->textColor = color;
   // SetConsoleTextAttribute(handle,  FOREGROUND_BLUE | BACKGROUND_BLUE);
}

void Edit::setBackground(int color)
{
    this->backgroundColor = color << 4;
    //SetBkColor(handle, color);
}

void Edit::setColors() const
{
    SetConsoleTextAttribute(handle, textColor + backgroundColor);
}

void Edit::display() const
{
    setColors();
    std::cout << text << "\n";
}


std::string Edit::getText() const
{
    return text;
}

void Edit::userText()
{
    //setPosition(posX, posY);
    setColors();

    char tmp;
    int temp;
    text = ' ';

    text.resize( length );
    for( int i = 0; i < length; i++ )
    {
        tmp = getchar();
        temp = tmp;
        if( temp == 13 )
             break;

        text[ i ] += tmp;
    }
}
