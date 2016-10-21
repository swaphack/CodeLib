#pragma once

#include "Creater/ProtocolCreater.h"
#include "Sample/import.h"
#include "XML/tinyxml2.h"

#include <cstdio>

int main(int argc, char** argv)
{
	ProtocolCreater* pCreater;
	tinyxml2::XMLDocument* pDocument;
	
	pCreater = new ProtocolCreater();
	pCreater->addProtocol(new CSharpProtocol());
	pCreater->addProtocol(new CPlusProtocol());

	pDocument = new tinyxml2::XMLDocument();
	pDocument->LoadFile("Protocol.xml");
	pCreater->Flush(pDocument);

	delete pDocument;
	delete pCreater;

	pCreater = new ProtocolCreater();
	pCreater->addProtocol(new CSharpProtocolID());
	pCreater->addProtocol(new CPlusProtocolID());

	pDocument = new tinyxml2::XMLDocument();
	pDocument->LoadFile("ProtocolID.xml");
	pCreater->Flush(pDocument);

	delete pDocument;
	delete pCreater;

	return 0;
}

