/**************************************************************************\
 *
 *  This file is part of the SIM Voleon visualization library.
 *  Copyright (C) 2003-2004 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using SIM Voleon with software that can not be combined with
 *  the GNU GPL, and for taking advantage of the additional benefits
 *  of our support services, please contact Systems in Motion about
 *  acquiring a SIM Voleon Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Teknobyen, Abels Gate 5, 7030 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

#include <VolumeViz/render/common/Cvr3DRGBATexture.h>
#include <Inventor/SbName.h>
#include <assert.h>
#include <Inventor/C/tidbits.h>

// Don't set value explicitly to SoType::badType(), to avoid a bug in
// Sun CC v4.0. (Bitpattern 0x0000 equals SoType::badType()).
SoType Cvr3DRGBATexture::classTypeId;

SoType Cvr3DRGBATexture::getTypeId(void) const { return Cvr3DRGBATexture::classTypeId; }
SoType Cvr3DRGBATexture::getClassTypeId(void) { return Cvr3DRGBATexture::classTypeId; }

void
Cvr3DRGBATexture::initClass(void)
{
  assert(Cvr3DRGBATexture::classTypeId == SoType::badType());
  Cvr3DRGBATexture::classTypeId =
    SoType::createType(CvrTextureObject::getClassTypeId(), "Cvr3DRGBATexture");
}

Cvr3DRGBATexture::Cvr3DRGBATexture(const SbVec3s & size)
{
  assert(Cvr3DRGBATexture::classTypeId != SoType::badType());

  assert(coin_is_power_of_two(size[0]));
  assert(coin_is_power_of_two(size[1]));
  assert(coin_is_power_of_two(size[2]));
  
  this->dimensions = size;
}

Cvr3DRGBATexture::~Cvr3DRGBATexture()
{
}

// Returns pointer to RGBA buffer. Allocates memory for it if
// necessary.
uint32_t *
Cvr3DRGBATexture::getRGBABuffer(void) const
{
  if (this->rgbabuffer == NULL) {
    // Cast away constness.
    Cvr3DRGBATexture * that = (Cvr3DRGBATexture *)this;
    that->rgbabuffer = new uint32_t[this->dimensions[0] * this->dimensions[1] * this->dimensions[2]];
  }

  return this->rgbabuffer;
}

// Blank out unused texture parts, to make sure we don't get any
// artifacts due to fp-inaccuracies when rendering.
void
Cvr3DRGBATexture::blankUnused(const SbVec3s & texsize) const
{
  assert(this->rgbabuffer);
 
  for (short z=texsize[2]; z < this->dimensions[2]; z++) {    
    for (short y=texsize[1]; y < this->dimensions[1]; y++) {
      for (short x=0; x < this->dimensions[0]; x++) {
        this->rgbabuffer[(z * this->dimensions[0] * this->dimensions[1]) + 
                         (y * this->dimensions[0]) + x] = 0x00000000;
      }
    }        
    for (short x=texsize[0]; x < this->dimensions[0]; x++) {
      for (short y=0; y < this->dimensions[1]; y++) {
        this->rgbabuffer[(z * this->dimensions[0] * this->dimensions[1]) + 
                         (y * this->dimensions[0]) + x] = 0x00000000;
      }
    }    
  }
  
}