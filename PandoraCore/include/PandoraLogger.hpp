/*
 * ----------------------------------------------------------------------------
 * This source file is part of Pandora3D. For information, see 
 * http://Pandora3D.sourceforge.net.
 *
 * Copyright (c) 2009 Martin Erts�s
 *
 * This program is free software. You can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the license, or any later version.
 *
 * This program is distributed in hope that it will be useful, but WITHOUT ANY 
 * WARRANTY.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston MA 02111-1307, USA, or go to:
 *
 * http://www.gnu.org/licenses/#GPL
 * ----------------------------------------------------------------------------
 */

#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <stdio.h>
#include <stdlib.h>

#include "PandoraSingleton.hpp"

namespace Pandora
{
    class Logger : public Singleton<Logger>
    {
        protected:
            FILE* appLog;
            FILE* clientLog;
            FILE* serverLog;
        public:
            Logger(char* appName, char* clientName, char* serverName);
            ~Logger();
            Logger* getSingletonPtr();
            Logger& getSingleton();

            void write(unsigned int log, char* logmsg);
    };
}
#endif