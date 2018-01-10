#include "HTTPParsingException.h"

HTTPParsingException::HTTPParsingException(int row, const char *message) :
    NetDataStreamException(NetDataStreamException::enNDSE_DataFormatError, message),
    _row(row)
{

}
