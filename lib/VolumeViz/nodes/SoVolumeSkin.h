#ifndef CVR_SOVOLUMESKIN_H
#define CVR_SOVOLUMESKIN_H

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

#include <Inventor/nodes/SoShape.h>
#include <Inventor/fields/SoSFEnum.h>
#include <VolumeViz/C/basic.h>

class SIMVOLEON_DLL_API SoVolumeSkin : public SoShape {
  typedef SoShape inherited;

  SO_NODE_HEADER(SoVolumeSkin);

public:
  SoVolumeSkin(void);
  static void initClass(void);

  enum Interpolation { NEAREST, LINEAR };
  SoSFEnum interpolation;

protected:
  ~SoVolumeSkin();

  virtual void GLRender(SoGLRenderAction * action);
  virtual void generatePrimitives(SoAction * action);
  virtual void computeBBox(SoAction * action, SbBox3f & box, SbVec3f & center);
  
private:
  friend class SoVolumeSkinP;
  class SoVolumeSkinP * pimpl;
};

#endif // !CVR_SOVOLUMESKIN_H
