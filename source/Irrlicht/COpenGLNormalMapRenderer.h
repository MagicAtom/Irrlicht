// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef IRR_C_OPENGL_NORMAL_MAP_RENDERER_H_INCLUDED
#define IRR_C_OPENGL_NORMAL_MAP_RENDERER_H_INCLUDED

#include "IrrCompileConfig.h"

#ifdef _IRR_COMPILE_WITH_OPENGL_

#include "IShaderConstantSetCallBack.h"

#include "COpenGLShaderMaterialRenderer.h"

namespace irr
{
namespace video
{

//! Class for rendering normal maps with OpenGL
class COpenGLNormalMapRenderer : public COpenGLShaderMaterialRenderer, public IShaderConstantSetCallBack
{
public:

	//! Constructor
	COpenGLNormalMapRenderer(video::COpenGLDriver* driver,
		s32& outMaterialTypeNr, E_MATERIAL_TYPE baseMaterial);

	//! Destructor
	~COpenGLNormalMapRenderer();

	//! Called by the engine when the vertex and/or pixel shader constants for an
	//! material renderer should be set.
	virtual void OnSetConstants(IMaterialRendererServices* services, s32 userData) IRR_OVERRIDE;

	//! Returns the render capability of the material.
	virtual s32 getRenderCapability() const IRR_OVERRIDE;

protected:

	bool CompiledShaders;
};


} // end namespace video
} // end namespace irr

#endif
#endif
