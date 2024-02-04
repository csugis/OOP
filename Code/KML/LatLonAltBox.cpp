#include "StdAfx.h"
#include "LatLonAltBox.h"

LatLonAltBox::LatLonAltBox(void)
:altitudeMode(clampToGround),minAltitude(0),maxAltitude(0)
{
}

LatLonAltBox::~LatLonAltBox(void)
{
}
