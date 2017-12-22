#include "ConsoleInput.h"
#include <iostream>
#include <QDebug>

#define CONSOLE_INPUT_BUFFER_SIZE               10240

ConsoleInput::ConsoleInput(QObject *parent) :
    QThread(parent)
{

}

void ConsoleInput::run()
{
    int idx = 0;
    char _buffer[CONSOLE_INPUT_BUFFER_SIZE];
    memset(_buffer, 0, CONSOLE_INPUT_BUFFER_SIZE);

    while (true)
    {
        int key = getchar();
        if (key == '\n')
        {
            // Комманда не пустая строка
            if (idx > 0)
            {
                _buffer[idx++] = 0;
                idx = 0;
                update(_buffer);
            }
        }
        else
        {
            _buffer[idx++] = key;
            if (idx ==  CONSOLE_INPUT_BUFFER_SIZE)
            {
                idx = 0;
                throw ConsoleInputException("Too long command!");
            }
        }
    }
}

