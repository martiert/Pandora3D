/*
-------------------------------------------------------------------------------
File Name : PandoraString.inl

Purpose : Implementation of the String class used in Pandora3D

Creation Date : 2010-01-24

Last Modified : sø. 31. jan. 2010 kl. 11.57 +0100

Created By : Martin Ertsås
-------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
//  Constructor.
//-----------------------------------------------------------------------------
String::String(const char *text)
{
    m_length = 0;
    while(text[m_length] != '\0') {
        m_length++;
    }

    m_string = new char[m_length + 1];

    for(int i = 0; i < m_length; i++) {
        m_string[i] = text[i];
    }
    m_string[m_length] = '\0';
}

//-----------------------------------------------------------------------------
//  Constructor.
//-----------------------------------------------------------------------------
String::String(unsigned int length, const char *text)
{
    m_length = length;
    m_string = new char[m_length + 1];

    for(int i = 0; i < m_length; i++) {
        m_string[i] = text[i];
    }
    m_string[m_length] = '\0';
}

//-----------------------------------------------------------------------------
//  Copy constructor.
//-----------------------------------------------------------------------------
String::String(const String& text)
{
    m_length = text.m_length;
    m_string = new char[m_length + 1];

    for(int i = 0; i < m_length; i++) {
        m_string[i] = text.m_string[i];
    }
    m_string[m_length] = '\0';
}

//-----------------------------------------------------------------------------
//  Destructor.
//-----------------------------------------------------------------------------
String::~String()
{
    delete[] m_string;
}

//-----------------------------------------------------------------------------
//  Get length of string.
//-----------------------------------------------------------------------------
int String::length() const
{
    return m_length;
}

//-----------------------------------------------------------------------------
//  Get the char array.
//-----------------------------------------------------------------------------
String::operator const char* () const
{
    return m_string;
}

//-----------------------------------------------------------------------------
//  Assign a String to this String.
//-----------------------------------------------------------------------------
void String::operator=(const String& text)
{
    delete[] m_string;
    *this = text;
}

//-----------------------------------------------------------------------------
//  Check for equality.
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
//  Checks if the strings are different.
//-----------------------------------------------------------------------------
bool String::operator!=(const String& text) const
{
    return !(*this == text);
}

//-----------------------------------------------------------------------------
//  Returns a hashed numerical representation of the string.
//-----------------------------------------------------------------------------
String::operator unsigned int () const
{
    int key = 0;
    for(int i = 0; i < m_length; ++i) {
        key += (key << 2) + m_string[i];
    }
    return key;
}
