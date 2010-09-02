/*
-------------------------------------------------------------------------------
File Name :

Purpose :

Creation Date : 2010-08-27

Last Modified : Thu 02 Sep 2010 15:16:48 CEST

Created By :  Martin Ertsaas (martiert@student.matnat.uio.no)
-------------------------------------------------------------------------------
*/

#include "../include/PandoraString.h"

namespace Pandora
{
    namespace Utils
    {

/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
String::String(const char* string)
{
    m_len = strlen(string);
    memcpy((void*)m_string, (void*)string, m_len+1);
}


/********************************************************************************
 * Constructor.                                                                 *
 *******************************************************************************/
String::String(const String& string)
{
    m_len = string.length();
    memcpy((void*)m_string, (void*)string.c_str(), m_len + 1);
}


/********************************************************************************
 * Destructor.                                                                  *
 *******************************************************************************/
String::~String() { }


/********************************************************************************
 * Assignment.                                                                  *
 *******************************************************************************/
String& String::operator=(const char *string)
{
    m_len = strlen(string);
    memcpy((void*)m_string, (void*) string, m_len+1);

    return *this;
}


/********************************************************************************
 * Assignment.                                                                  *
 *******************************************************************************/
String& String::operator=(const String string)
{
    m_len = string.length();
    memcpy((void*) m_string, (void*) string.c_str(), m_len+1);

    return *this;
}


/********************************************************************************
 * Get char number.                                                             *
 *******************************************************************************/
char& String::operator[](const ptrdiff_t i)
{
    assert(i < m_len && "String::operator[]: Index out of bounds");

    return m_string[i];
}


/********************************************************************************
 * Get char number.                                                             *
 *******************************************************************************/
const char String::operator[](const ptrdiff_t i) const
{
    assert(i < m_len && "String::operator[]: Index out of bounds");

    return m_string[i];
}

/********************************************************************************
 * Get c-string.                                                                *
 *******************************************************************************/
char* String::c_str()
{
    return m_string;
}


/********************************************************************************
 * Get constant c-string.                                                       *
 *******************************************************************************/
const char* String::c_str() const
{
    return m_string;
}


/********************************************************************************
 * Get length of the string.                                                    *
 *******************************************************************************/
unsigned int String::length() const
{
    return m_len;
}


/********************************************************************************
 * Find a substring.                                                            *
 * Uses the Bayer-Moore algorithm.                                              *
 *******************************************************************************/
int String::substr(const char* substring) const
{
    int badCharShift[256];
    int sublen = strlen(substring);

    for(int i = 0; i < 256; i++)
        badCharShift[i] = sublen;

    int last = sublen - 1;
    for(int i = 0; i < last; i++)
        badCharShift[ (int)m_string[i] ] = last - i;

    int scan = 0;
    int offset = 0;
    int maxoffset = m_len - sublen;

    while(offset <= maxoffset) {
        for(scan = last; substring[scan] == m_string[scan + offset]; scan--) {
            if(scan == 0) { // match found!
                return offset;
            }
        }

        offset += badCharShift[ (int)m_string[offset + last] ];
    }

    return -1;
}


/********************************************************************************
 * Find a substring.                                                            *
 *******************************************************************************/
int String::substr(const String substring) const
{
    return substr(substring.c_str());
}

} // namespace Utils
} // namespace Pandora
