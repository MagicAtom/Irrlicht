cmake_minimum_required(VERSION 3.14)
project(Irrlicht)
set(PROJECT_NAME Irrlicht)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
ADD_DEFINITIONS( -D_CRT_SECURE_NO_WARNINGS )
ADD_DEFINITIONS( -D_CRT_SECURE_NO_DEPRECATE )

set(CMAKE_CFLAGS "-I../../include -Izlib -Ijpeglib -Ilibpng")
set(CMAKE_CXX_FLAGS "-Wall -pipe -fno-exceptions -fno-rtti")
set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
    libavdevice
    libavfilter
    libavformat
    libavcodec
    libswresample
    libswscale
    libavutil
)

if(APPLE)
add_compile_options(-Wno-deprecated-declarations)
add_compile_options(-x objective-c++)
set(CMAKE_EXE_LINKER_FLAGS "-framework.cppundation -framework.cppcoa -framework AppKit -framework opengl -framework.cppKit")
endif (APPLE)
add_compile_options(-Wno-deprecated-declarations)

include_directories(../../include)
include_directories(zlib)
include_directories(bzip2)
include_directories(libpng)
include_directories(lzma)
include_directories(jpeglib)
set(IRRMESHLOADER CBSPMeshFileLoader.cpp CMD2MeshFileLoader.cpp CMD3MeshFileLoader.cpp CMS3DMeshFileLoader.cpp CB3DMeshFileLoader.cpp C3DSMeshFileLoader.cpp COgreMeshFileLoader.cpp COBJMeshFileLoader.cpp CColladaFileLoader.cpp CCSMLoader.cpp CDMFLoader.cpp CLMTSMeshFileLoader.cpp CMY3DMeshFileLoader.cpp COCTLoader.cpp CXMeshFileLoader.cpp CIrrMeshFileLoader.cpp CSTLMeshFileLoader.cpp CLWOMeshFileLoader.cpp CPLYMeshFileLoader.cpp CSMFMeshFileLoader.cpp CMeshTextureLoader.cpp)
set(IRRMESHWRITER CColladaMeshWriter.cpp CIrrMeshWriter.cpp CSTLMeshWriter.cpp COBJMeshWriter.cpp CPLYMeshWriter.cpp CB3DMeshWriter.cpp)
set(IRRMESHOBJ ${IRRMESHLOADER} ${IRRMESHWRITER} CSkinnedMesh.cpp CBoneSceneNode.cpp CMeshSceneNode.cpp CAnimatedMeshSceneNode.cpp CAnimatedMeshMD2.cpp CAnimatedMeshMD3.cpp CQ3LevelMesh.cpp CQuake3ShaderSceneNode.cpp CAnimatedMeshHalfLife.cpp)
set(IRROBJ CBillboardSceneNode.cpp CCameraSceneNode.cpp CDummyTransformationSceneNode.cpp CEmptySceneNode.cpp CGeometryCreator.cpp CLightSceneNode.cpp CMeshManipulator.cpp CMetaTriangleSelector.cpp COctreeSceneNode.cpp COctreeTriangleSelector.cpp CSceneCollisionManager.cpp CSceneManager.cpp CShadowVolumeSceneNode.cpp CSkyBoxSceneNode.cpp CSkyDomeSceneNode.cpp CTerrainSceneNode.cpp CTerrainTriangleSelector.cpp CVolumeLightSceneNode.cpp CCubeSceneNode.cpp CSphereSceneNode.cpp CTextSceneNode.cpp CTriangleBBSelector.cpp CTriangleSelector.cpp CWaterSurfaceSceneNode.cpp CMeshCache.cpp CDefaultSceneNodeAnimatorFactory.cpp CDefaultSceneNodeFactory.cpp CSceneLoaderIrr.cpp)
set(IRRPARTICLEOBJ CParticleAnimatedMeshSceneNodeEmitter.cpp CParticleBoxEmitter.cpp CParticleCylinderEmitter.cpp CParticleMeshEmitter.cpp CParticlePointEmitter.cpp CParticleRingEmitter.cpp CParticleSphereEmitter.cpp CParticleAttractionAffector.cpp CParticleFadeOutAffector.cpp CParticleGravityAffector.cpp CParticleRotationAffector.cpp CParticleSystemSceneNode.cpp CParticleScaleAffector.cpp)
set(IRRANIMOBJ CSceneNodeAnimatorCameraFPS.cpp CSceneNodeAnimatorCameraMaya.cpp CSceneNodeAnimatorCollisionResponse.cpp CSceneNodeAnimatorDelete.cpp CSceneNodeAnimatorFlyCircle.cpp CSceneNodeAnimatorFlyStraight.cpp CSceneNodeAnimatorFollowSpline.cpp CSceneNodeAnimatorRotation.cpp CSceneNodeAnimatorTexture.cpp)
set(IRRDRVROBJ CNullDriver.cpp COpenGLCacheHandler.cpp COpenGLDriver.cpp COpenGLNormalMapRenderer.cpp COpenGLParallaxMapRenderer.cpp COpenGLShaderMaterialRenderer.cpp COpenGLSLMaterialRenderer.cpp COpenGLExtensionHandler.cpp CD3D9Driver.cpp CD3D9HLSLMaterialRenderer.cpp CD3D9NormalMapRenderer.cpp CD3D9ParallaxMapRenderer.cpp CD3D9ShaderMaterialRenderer.cpp CD3D9Texture.cpp CGLXManager.cpp CWGLManager.cpp)
set(IRRIMAGEOBJ CColorConverter.cpp CImage.cpp CImageLoaderBMP.cpp CImageLoaderDDS.cpp CImageLoaderJPG.cpp CImageLoaderPCX.cpp CImageLoaderPNG.cpp CImageLoaderPSD.cpp CImageLoaderPVR.cpp CImageLoaderTGA.cpp CImageLoaderPPM.cpp CImageLoaderWAL.cpp CImageLoaderRGB.cpp CImageWriterBMP.cpp CImageWriterJPG.cpp CImageWriterPCX.cpp CImageWriterPNG.cpp CImageWriterPPM.cpp CImageWriterPSD.cpp CImageWriterTGA.cpp)
set(IRRVIDEOOBJ CVideoModeList.cpp CFPSCounter.cpp ${IRRDRVROBJ} ${IRRIMAGEOBJ})
set(IRRSWRENDEROBJ CSoftwareDriver.cpp CSoftwareTexture.cpp CTRFlat.cpp CTRFlatWire.cpp CTRGouraud.cpp CTRGouraudWire.cpp CTRNormalMap.cpp CTRStencilShadow.cpp CTRTextureFlat.cpp CTRTextureFlatWire.cpp CTRTextureGouraud.cpp CTRTextureGouraudAdd.cpp CTRTextureGouraudNoZ.cpp CTRTextureGouraudWire.cpp CZBuffer.cpp CTRTextureGouraudVertexAlpha2.cpp CTRTextureGouraudNoZ2.cpp CTRTextureLightMap2_M2.cpp CTRTextureLightMap2_M4.cpp CTRTextureLightMap2_M1.cpp CSoftwareDriver2.cpp CSoftwareTexture2.cpp CTRTextureGouraud2.cpp CTRGouraud2.cpp CTRGouraudAlpha2.cpp CTRGouraudAlphaNoZ2.cpp CTRTextureDetailMap2.cpp CTRTextureGouraudAdd2.cpp CTRTextureGouraudAddNoZ2.cpp CTRTextureWire2.cpp CTRTextureLightMap2_Add.cpp CTRTextureLightMapGouraud2_M4.cpp IBurningShader.cpp CTRTextureBlend.cpp CTRTextureGouraudAlpha.cpp CTRTextureGouraudAlphaNoZ.cpp CDepthBuffer.cpp CBurningShader_Raster_Reference.cpp CTR_transparent_reflection_2_layer.cpp CTRGouraudNoZ2.cpp burning_shader_color.cpp)
set(IRRIOOBJ CFileList.cpp CFileSystem.cpp CLimitReadFile.cpp CMemoryFile.cpp CReadFile.cpp CWriteFile.cpp CXMLReader.cpp CXMLWriter.cpp CWADReader.cpp CZipReader.cpp CPakReader.cpp CNPKReader.cpp CTarReader.cpp CMountPointReader.cpp irrXML.cpp CAttributes.cpp lzma/LzmaDec.c)
set(IRROTHEROBJ CIrrDeviceSDL.cpp CIrrDeviceLinux.cpp CIrrDeviceConsole.cpp CIrrDeviceStub.cpp CIrrDeviceWin32.cpp CIrrDeviceFB.cpp CLogger.cpp COSOperator.cpp Irrlicht.cpp os.cpp leakHunter.cpp 	CProfiler.cpp utf8.cpp)
set(IRRGUIOBJ CGUIButton.cpp CGUICheckBox.cpp CGUIComboBox.cpp CGUIContextMenu.cpp CGUIEditBox.cpp CGUIEnvironment.cpp CGUIFileOpenDialog.cpp CGUIFont.cpp CGUIImage.cpp CGUIInOutFader.cpp CGUIListBox.cpp CGUIMenu.cpp CGUIMeshViewer.cpp CGUIMessageBox.cpp CGUIModalScreen.cpp CGUIScrollBar.cpp CGUISpinBox.cpp CGUISkin.cpp CGUIStaticText.cpp CGUITabControl.cpp CGUITable.cpp CGUIToolBar.cpp CGUIWindow.cpp CGUIColorSelectDialog.cpp CDefaultGUIElementFactory.cpp CGUISpriteBank.cpp CGUIImageList.cpp CGUITreeView.cpp CGUIProfiler.cpp)
#set(LZMAOBJ lzma/LzmaDec.c lzma/LzmaDec.h lzma/Types.h)
set(LIBAESGM aesGladman/aescrypt.cpp aesGladman/aeskey.cpp aesGladman/aestab.cpp aesGladman/fileenc.cpp aesGladman/hmac.cpp aesGladman/prng.cpp aesGladman/pwd2key.cpp aesGladman/sha1.cpp aesGladman/sha2.cpp)
set(BZIP2OBJ bzip2/blocksort.c bzip2/huffman.c bzip2/crctable.c bzip2/randtable.c bzip2/bzcompress.c bzip2/decompress.c bzip2/bzlib.c)
set(JPEGLIBOBJ jpeglib/jcapimin.c jpeglib/jcapistd.c jpeglib/jccoefct.c jpeglib/jccolor.c jpeglib/jcdctmgr.c jpeglib/jchuff.c jpeglib/jcinit.c jpeglib/jcmainct.c jpeglib/jcmarker.c jpeglib/jcmaster.c jpeglib/jcomapi.c jpeglib/jcparam.c jpeglib/jcprepct.c jpeglib/jcsample.c jpeglib/jctrans.c jpeglib/jdapimin.c jpeglib/jdapistd.c jpeglib/jdatadst.c jpeglib/jdatasrc.c jpeglib/jdcoefct.c jpeglib/jdcolor.c jpeglib/jddctmgr.c jpeglib/jdhuff.c jpeglib/jdinput.c jpeglib/jdmainct.c jpeglib/jdmarker.c jpeglib/jdmaster.c jpeglib/jdmerge.c jpeglib/jdpostct.c jpeglib/jdsample.c jpeglib/jdtrans.c jpeglib/jerror.c jpeglib/jfdctflt.c jpeglib/jfdctfst.c jpeglib/jfdctint.c jpeglib/jidctflt.c jpeglib/jidctfst.c jpeglib/jidctint.c jpeglib/jmemmgr.c jpeglib/jmemnobs.c jpeglib/jquant1.c jpeglib/jquant2.c jpeglib/jutils.c jpeglib/jcarith.c jpeglib/jdarith.c jpeglib/jaricom.c)
set(LIBPNGOBJ libpng/png.c libpng/pngerror.c libpng/pngget.c libpng/pngmem.c libpng/pngpread.c libpng/pngread.c libpng/pngrio.c libpng/pngrtran.c libpng/pngrutil.c libpng/pngset.c libpng/pngtrans.c libpng/pngwio.c libpng/pngwrite.c libpng/pngwtran.c libpng/pngwutil.c)
set(ZLIBOBJ zlib/adler32.c zlib/compress.c zlib/crc32.c zlib/deflate.c zlib/inffast.c zlib/inflate.c zlib/inftrees.c zlib/trees.c zlib/uncompr.c zlib/zutil.c)

set(SRC ${IRRMESHOBJ} ${IRROBJ} ${IRRPARTICLEOBJ} ${IRRANIMOBJ} ${IRRVIDEOOBJ} ${IRRSWRENDEROBJ} ${IRRIOOBJ} ${IRROTHEROBJ} ${IRRGUIOBJ})

if(APPLE)
ADD_LIBRARY(Irrlicht CIrrDeviceOSX.mm ${SRC} ${LIBAESGM} ${BZIP2OBJ} ${JPEGLIBOBJ} ${LIBPNGOBJ} ${ZLIBOBJ})
endif(APPLE)

if(UNIX AND NOT APPLE)
ADD_LIBRARY(Irrlicht ${SRC} ${LIBAESGM} ${BZIP2OBJ} ${LZMAOBJ} ${JPEGLIBOBJ} ${LIBPNGOBJ} ${ZLIBOBJ})
endif(UNIX AND NOT APPLE)

target_link_libraries(Irrlicht PkgConfig::LIBAV)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../lib)
