/*
 * Copyright 2012-2014 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// C++ standard includes
#include <iostream>
#include <sstream>
#include <string.h>

// Falltergeist includes
#include "../Engine/Graphics/Texture.h"
#include "../Engine/ResourceManager.h"
#include "../UI/Image.h"
#include "../UI/SmallCounter.h"

// Third party includes

namespace Falltergeist
{

SmallCounter::SmallCounter(int x, int y) : ActiveUI(x, y)
{
}

SmallCounter::~SmallCounter()
{
}

std::shared_ptr<Texture> SmallCounter::texture()
{
    if (_texture) return _texture;

    auto numbers = std::shared_ptr<Image>(new Image("art/intrface/numbers.frm"));

    // number as text, always positive
    signed int result = _number;
    std::stringstream ss;
    if (_number<0)
    {
        result = abs(_number);
    }
    ss << result;

    _texture = std::shared_ptr<Texture>(new Texture(9*(_length+1), 16));

    char* textNumber = new char[_length + 1]();

    for (unsigned int i = 0; i < _length; ++i)
    {
        textNumber[i] = '0';
    }

    unsigned int length = strlen(ss.str().c_str());
    unsigned int diff = _length - length;
    for (unsigned int i = 0; i < length; i++)
    {
        textNumber[diff + i] = ss.str().c_str()[i];
    }

    for (unsigned int i = 0; i < _length; i++)
    {
        int key = 9 -  ('9' - textNumber[i]);
        unsigned int x = 9 * key;
        switch (_color)
        {
            case COLOR_WHITE:
                break;
            case COLOR_YELLOW:
                x += 120;
                break;
            case COLOR_RED:
                x += 240;
                break;
        }
        numbers->texture()->copyTo(_texture, 9+9*i, 0, x+1, 0, 9, 16);
    }
    // sign of _number
    if (_number<0)
    {
        numbers->texture()->copyTo(_texture, 0, 0, 9*12+1, 0, 9, 16);
    }
    else
    {
        numbers->texture()->copyTo(_texture, 0, 0, 113, 0, 9, 16); // must be 9*13+1, but it is 113
    }
    delete [] textNumber;
    return _texture;
}

void SmallCounter::setNumber(signed int number)
{
    if (_number == number) return;
    _texture.reset();
    _number = number;
}

signed int SmallCounter::number()
{
    return _number;
}


void SmallCounter::setColor(unsigned char color)
{
    switch(color)
    {
        case COLOR_WHITE:
        case COLOR_YELLOW:
        case COLOR_RED:
            if (_color != color)
            {
                _color = color;
                _texture.reset();
            }
            break;
    }
}

unsigned char SmallCounter::color()
{
    return _color;
}

}