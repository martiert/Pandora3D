#include "PandoraException.h"

namespace Pandora
{
    Exception::Exception( int num, const std::string& descr,
            const std::string& src ) :
        line( 0 ),
        number( num ),
        description( descr ),
        source( src )
    {
    }

    Exception::Exception( int num, const std::string& desc,
            const std::string& src, const std::string& fileName,
            const std::string& type, long lineNum ) :
        line( lineNum ),
        number( num ),
        typeName( type ),
        description( desc ),
        source( src ),
        file( fileName )
    {
    }

    Exception::Exceptiion( const Exception& except ) :
        line( except.line ),
        number( except.number ),
        typeName( except.typeName ),
        description( except.description ),
        source( except.source ),
        file( except.file)
    {
    }

    void operator=( const Exception& except )
    {
        line        = except.line;
        number      = except.number;
        typeName    = except.typeName;
        description = except.description;
        source      = except.source;
        file        = except.file;
    }
}
