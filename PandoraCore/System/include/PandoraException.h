#ifndef PANDORAEXCEPTION_H
#define PANDORAEXCEPTION_H

#include <exception>
#include <string>

namespace Pandora
{
    class Exception : public std::exception
    {
        protected:
            long line;
            int number;
            std::string typeName;
            std::string description;
            std::string source;
            std::string file;

        public:
            enum ExceptionCode {
                INDEX_OUT_OF_BOUNDS,
                INVALID_STATE,
                CANNOT_WRITE_TO_FILE,
                FILE_NOT_FOUND,
                NOT_IMPLEMENTED
            };

            /**
             *  Make a simple exception.
             */
            Exception( int num, const std::string& descr,
                    const std::string& src );

            /**
             *  Make a full exception.
             */
            Exception(int num, const std::string& desc, const std::string& src,
                    const std::string& fileName, const std::string& type,
                    long lineNum );

            /**
             *  Copy an exception.
             */
            Exception( const Exception& except );

            /**
             *  Destructor.
             */
            ~Exception() throw() {}

            void operator=( const Exception& except );

            virtual const std::string& getFullDescription() const;

            virtual int getNumber() const throw();

            virtual const std::string& getSource() const
            {
                return source;
            }

            virtual const std::string& getFile() const
            {
                return file;
            }

            virtual long getLine() const
            {
                return line;
            }

            virtual const std::string& getDescription() const
            {
                return description;
            }

            const char* what() const throw()
            {
                return getFullDescription().c_str();
            }
    };
}

#endif
