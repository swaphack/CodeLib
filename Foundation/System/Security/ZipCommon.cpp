#include "ZipCommon.h"

using namespace wc;

ZipText::ZipText()
:text(nullptr)
,size(0)
{

}

ZipText::ZipText( const char* text, int size )
:text((char*)text)
,size(size)
{

}
