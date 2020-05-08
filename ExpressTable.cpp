#include "ExpressTable.h"
#include <stdio.h>
#include <iostream>
using namespace std;
ExpressTable::ExpressTable()
{
	memset(MyCells, 0, sizeof(MyCells));
	FILE* FilePointer;
	const char FileName[20] = "Cells";
	if (fopen_s(&FilePointer,FileName,"rb") == 0) 
	{
		

	}
	else {

	}
}

ExpressTable::~ExpressTable()
{
}

