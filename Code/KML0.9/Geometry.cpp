#include "StdAfx.h"
#include "Geometry.h"

Geometry::Geometry(void)
:extrude(false),altitudeMode(clampToGround),tessellate(true)
{
}

Geometry::~Geometry(void)
{
}

