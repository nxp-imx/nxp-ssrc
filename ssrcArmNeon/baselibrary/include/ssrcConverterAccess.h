/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrConverterAccess_h
#define ssrConverterAccess_h
#include "ssrcSampleRateConverterConfig.h"
#include "ssrcsamplerateconverterlist_const.h"
/********************************************************************************
*
*******************************************************************************/
#ifdef DLL_COMPILE_MODE
#include <dlfcn.h>
#else
#define RTLD_LAZY 0
/********************************************************************************
* dummy function for static lib compile mode
*
*******************************************************************************/
inline void *dlopen(const char *name, int mode)
{
    return nullptr;
}
/********************************************************************************
* dummy function for static lib compile mode
*
*******************************************************************************/
inline  void *dlsym(void* handle, const char *name)
{
    return nullptr;
}
/********************************************************************************
* dummy function for static lib compile mode
*
*******************************************************************************/
inline  int dlclose(void* handle)
{
    return 0;
}
/********************************************************************************
* dummy function for static lib compile mode
*
*******************************************************************************/
inline char *dlerror()
{
    return nullptr;
}
#endif
/********************************************************************************
*  Set of of fuctions to load and unload DLL (.so) files
*
*******************************************************************************/

class LoadSharedObjectLib
{
public:
    /********************************************************************************
    * open shared object DL. Only exist if DLL compile mode 
    *
    *******************************************************************************/
    static bool openDL(QuantizedFitlerEntry &fitlerDef, SsrcLog &log);
    /********************************************************************************
    * open shared object DL. Only exist if DLL compile mode
    *
    *******************************************************************************/
    static bool openDL(SsrcSampleRateConverterDefinition &fitlerDef, SsrcLog &log);
    /********************************************************************************
    * close shared object DL. Only exist if DLL compile mode
    *
    *******************************************************************************/
    static bool closeDL(SsrcSampleRateConverterDefinition &fitlerDef);
    /********************************************************************************
    * close shared object DL. Only exist if DLL compile mode
    *
    *******************************************************************************/
    static bool closeDL(QuantizedFitlerEntry &fitlerDef);
    /********************************************************************************
    * load shared object. Exist if DLL compile mode
    *
    *******************************************************************************/
    template<class _OBJECT_INFO_>
    static bool loadSharedLib(_OBJECT_INFO_ &info, SsrcLog &log)
    {
        char *error = nullptr;
        if (info.libHandle == nullptr)
        {

            error = dlerror();
            info.libHandle = dlopen(info.libSoFileName, RTLD_LAZY);
            if (info.libHandle == nullptr)
            {
                error = dlerror();
                info.symbolPointerInLib = nullptr;
                log.add(error);
                log.add("ERROR:unable to open shared object lib file:");
                return false;
            }

            error = dlerror();
            info.symbolPointerInLib = dlsym(info.libHandle, info.libSymbolToGet);
            if (info.symbolPointerInLib == nullptr)
            {
                error = dlerror();
                log.add(error);
                log.add("ERROR:symbol not found in shared object lib file");
                log.add(info.libSymbolToGet);
                log.add(info.libSoFileName);
                info.symbolPointerInLib = nullptr;
                return false;
            }
        }
        return true;
    }
    /********************************************************************************
    * unload shared object. Exist if DLL compile mode
    *
    *******************************************************************************/
    template<class _OBJECT_INFO_>
    static bool unloadSharedLib(_OBJECT_INFO_ &info)
    {
        if (info.libHandle == nullptr)
        {
            dlclose((void*)info.libHandle);
            info.libHandle = nullptr;
        }
        return true;
    }

};

/********************************************************************************
* filter list
*
*******************************************************************************/
class InterpolationFilterList
{
public:
    /********************************************************************************
    *   get an interpolation filter according to the info given
    *
    *******************************************************************************/
    static const QuantizedFitlerEntry *getInterpolationFilter(SsrcSampleRateConverterInfo &resamplerInfo);
    /********************************************************************************
    * cleanup
    *
    *******************************************************************************/
    static void destruct();
	/********************************************************************************
	*   get an interpolation filter by index
	*
	*******************************************************************************/
	static const QuantizedFitlerEntry *getInterpolationFilter(int index);
};
/********************************************************************************
*  sample rate converter list
*
*******************************************************************************/
class SsrcSampleRateConverterList
{
    /********************************************************************************
    *  list of sample rates supported
    *
    *******************************************************************************/
    static const unsigned samplingRateList[NumberOfSampleRatesSupported];
    /********************************************************************************
    *  input/output sample rate to ratio conversion table
    *
    *******************************************************************************/
    static const SSRCSamplingRatesRatio samplingRatesRatio[NumberOfSampleRatesSupported][NumberOfSampleRatesSupported];
    static SsrcSampleRateConverterDefinition sampleRateConverterList[sampleRateConverterListSize];
public:
    /********************************************************************************
    * init
    *
    *******************************************************************************/
    SsrcSampleRateConverterList();
    /********************************************************************************
    * cleanup
    *
    *******************************************************************************/
    ~SsrcSampleRateConverterList();
    /********************************************************************************
    *  delete all loaded DLL, if in dll mode
    *
    *******************************************************************************/
    void destruct();
    /********************************************************************************
    *  get number of converters available
    *
    *******************************************************************************/
    unsigned getNumberOfConverters();

    /********************************************************************************
    *  get a converter according to the info given
    *  return false if cant find a converter withthe given spec
    *******************************************************************************/
    bool getConverter(SsrcConfig &config, SsrcSampleRateConverterInfo &resamplerInfo);
    /********************************************************************************
    *  get a converter by index
    *
    *******************************************************************************/
    SsrcSampleRateConverterDefinition *getConverter(int index);
    /********************************************************************************
    *  get sample rate index
    *
    *******************************************************************************/
    bool getSampleRateIndex(unsigned sampleRate, unsigned &index);
    /********************************************************************************
    *  get sample rate ratio
    *
    *******************************************************************************/
    bool getSampleRateRatio(unsigned inputSampleRate, unsigned outputSampleRate, SSRCSamplingRatesRatio &output);

};



#endif // ssrConverterAccess_h
