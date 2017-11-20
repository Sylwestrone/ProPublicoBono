#ifndef EDIT_H
#define EDIT_H

#include <windows.h>
#include <iostream>

class Edit
{
    public:
        Edit();
        ~Edit();
        Edit(const Edit& other);
        void setPosition(const int posX, const int posY);
        void setLength(const int length);
        void setText(std::string text);
        void setTextColor(int color);
        void setBackground(int color);
        void display() const;
        std::string getText() const;
        void userText();

        enum eColor { White = 97, Green = 32};
    private:
        HANDLE handle;
        COORD coord;
        int textColor;
        int backgroundColor;
        int length;
        int posX;
        int posY;
        std::string text;

        void setColors() const;
};

#endif // EDIT_H
