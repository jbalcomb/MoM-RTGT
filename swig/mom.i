/* File : mom.i */
%module mom

%{
#include "MoMCommon.h"
#include "MoMCore.h"
#include "MoMExeMagic.h"
#include "MoMExeWizards.h"
#include "MoMGameBase.h"
#include "MoMProcess.h"
%}

%include "cpointer.i"
%pointer_class(uint8_t, uint8_ptr);
%pointer_class(uint16_t, uint16_ptr);
%pointer_class(uint32_t, uint32_ptr);
%pointer_class(int8_t, int8_ptr);
%pointer_class(int16_t, int16_ptr);
%pointer_class(int32_t, int32_ptr);
%pointer_class(MoM::eTerrainBonusDeposit, eTerrainBonusDeposit_ptr);
%pointer_class(MoM::eTerrainType, eTerrainType_ptr);

%include "carrays.i"
%array_class(uint8_t, uint8_array);
%array_class(uint16_t, uint16_array);
%array_class(uint32_t, uint32_array);
%array_class(int8_t, int8_array);
%array_class(int16_t, int16_array);
%array_class(int32_t, int32_array);
%array_class(MoM::DS_Offset, DS_Offset_array);
%array_class(MoM::eSpell, eSpell_array);
%array_class(MoM::eSpell16, eSpell16_array);

// Swig wrappers for the standard C++ library
%include "cdata.i"
%include "std_string.i"

// MoM interfaces
%include "MoMCommon.h"
%include "MoMTemplate.h"
%include "MoMLocation.h"
%include "MoMExeBase.h"
%include "MoMExeMagic.h"
%include "MoMExeWizards.h"
%include "MoMProcess.h"
%include "MoMGameBase.h"
%include "MoMCore.h"

