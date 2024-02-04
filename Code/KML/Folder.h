#pragma once
#include "container.h"

class Folder :
	public Container
{
public:
	virtual bool IsAbstract(void) {return false;};
	Folder(void);
	virtual ~Folder(void);
};

typedef class Folder kmlFolder;