/*
-------------------------------------------------------------------------------
This source file is part of Pandora3D.

This program is free software: you can redistribute it and/or modify it under 
the terms of the GNU General Public License as published by the Free Software 
Foundation. Either version 2 of the License, or (at your option) any later 
version.

This program comes without any warranty whatsoever, but under the hope that it
will be useful. See the GNU General Public License for more information.

You should have received a copy of the GNU Lesser General Public License along 
with this program; if not, write to the Free Software Foundation, Inc., 59 
Temple Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-------------------------------------------------------------------------------
*/

//---------------------------------------------------------------------
// Constructor.
//---------------------------------------------------------------------
String::String(const char *text)
{
    m_length = strlen(text);
    m_string = new char[m_length + 1];
    strcpy(m_string, text);
}

//---------------------------------------------------------------------
// Constructor.
//---------------------------------------------------------------------
String::String(size_t length, const char *text)
{
    m_length = length;
    m_string = new char[m_length + 1];
    strcpy(m_string, text);
}

//---------------------------------------------------------------------
// Copy constructor.
//---------------------------------------------------------------------
String::String(const String& text)
{
    m_length = text.m_length;
    m_string = new char[m_length + 1];
    strcpy(m_string, text.m_string);
}

//---------------------------------------------------------------------
// Destructor.
//---------------------------------------------------------------------
String::~String()
{
    delete[] m_string;
}

//---------------------------------------------------------------------
// Get length of string.
//---------------------------------------------------------------------
int String::getLength() const
{
    return m_length;
}

//---------------------------------------------------------------------
// Get the char array.
//---------------------------------------------------------------------
String::operator const char* () const
{
    return m_string;
}

//---------------------------------------------------------------------
// Assign a String to this String.
//---------------------------------------------------------------------
void String::operator=(const String& text)
{
    delete[] m_string;
    *this = text;
}

//---------------------------------------------------------------------
// Check for equality.
//---------------------------------------------------------------------
bool String::operator==(const String& text) const
{
    if(m_length != text.m_length)
        return false;

    for(int i = 0; i < m_length; ++i) {
        if(m_string[i] != text.m_string[i])
            return false;
    }
    return true;
}

//---------------------------------------------------------------------
// Checks if the strings are different.
//---------------------------------------------------------------------
bool String::operator!=(const String& text) const
{
    return !(*this == text);
}

//---------------------------------------------------------------------
// Returns a hashed numerical representation of the string.
//---------------------------------------------------------------------
String::operator unsigned int () const
{
    int key = 0;
    for(int i = 0; i < m_length; ++i) {
        key += (key << 2) + m_string[i];
    }
    return key;
}
