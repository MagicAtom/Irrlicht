// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef IRR_C_XML_READER_H_INCLUDED
#define IRR_C_XML_READER_H_INCLUDED

#include "IXMLReader.h"

namespace irr
{
#ifdef _IRR_COMPILE_WITH_XML_
namespace io
{
	class IReadFile;

	//! creates an IXMLReader
	IXMLReader* createIXMLReader(IReadFile* file);

	//! creates an IXMLReader
	IXMLReaderUTF8* createIXMLReaderUTF8(IReadFile* file);
} // end namespace irr
#else // _IRR_COMPILE_WITH_XML_
	//! print a message that Irrlicht is compiled without _IRR_COMPILE_WITH_XML_
	void noXML();
#endif // _IRR_COMPILE_WITH_XML_
} // end namespace io

#endif
