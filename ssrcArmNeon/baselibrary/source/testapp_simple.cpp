/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcSampleRateConverterConfig.h"
#include "wavHeader.h"

/*******************************************************************************
 * 
 * open an input wave file
 * input:
 *      char *fileName: file name
 * 
*******************************************************************************/
extern "C" WaveFileIO *openInputWaveFile(char *fileName)
{
    string inputFileName(fileName);
    WaveFileIO *inputFile  = new  WaveFileIO;    // wave input file object
    if (inputFile == nullptr)
    {
        return nullptr;
    }
    const char *error = inputFile->openRead(inputFileName);
    if (error != nullptr)
    {
        delete inputFile;
        return nullptr;
    }

    return inputFile;

}
/*******************************************************************************
 * 
 * close wave file
 * input:
 *      WaveFileIO *file : file control block structure ppointer
 * 
*******************************************************************************/
extern "C" void closeWaveFile(WaveFileIO *file)
{
    if (file != nullptr)
    {
        delete file;
    }
}
/*******************************************************************************
 * 
 * open an output wave file
 * input:
 *      char *fileName: file name
 *      WaveFileIO *inputFile : the input file header the output is based on
 *      int outputSampleRate : output sample rate
 * 
*******************************************************************************/
extern "C" WavfileHeader *openOutputWaveFile(char *fileName, WaveFileInfo *formatInfo)
{
    string inputFileName(fileName);
    if (fileName == nullptr)
    {
        return nullptr;
    }
    WaveFileIO *outputFile  = new  WaveFileIO;    // wave output file object
    if (formatInfo == nullptr)
    {
        return nullptr;
    }
    /*
        open output wave file and get the headers
    */
    const char *error = outputFile->openWrite(inputFileName, formatInfo);
    if (error != nullptr)
    {
        delete outputFile;
        return nullptr;
    }
    return outputFile;
}
/*******************************************************************************
 *
 * get wave file info
 * 
*******************************************************************************/
extern "C" void getInfo(WaveFileIO *inputFile, struct WaveFileInfo *info)
{
    info->AudioFormat = inputFile->AudioFormat;
    info->NumChannels = inputFile->NumChannels;
    info->SampleRate = inputFile->SampleRate;
    info->ByteRate = inputFile->ByteRate;
    info->BlockAlign = inputFile->BlockAlign;
    info->BitsPerSample = inputFile->BitsPerSample;
    info->DataBlockSize = inputFile->DataBlockSize;
}
/*******************************************************************************
 * 
 * read from a wave file
 * input:
 *      WaveFileIO *file : file control block structure ppointer
 *      int32_t *inputBuffer: input buffer
 *      size_t inputTransferSize : number of samples to read
 * 
*******************************************************************************/

extern "C" size_t readInputWaveFile(WaveFileIO *inputFile,int32_t *inputBuffer,size_t inputTransferSize)
{
    return inputFile->read(inputBuffer, inputTransferSize);
}
/*******************************************************************************
 * 
 * write into a wave file
 * input:
 *      WaveFileIO *file : file control block structure ppointer
 *      int32_t *inputBuffer: output buffer
 *      size_t inputTransferSize : number of samples to write
 * 
*******************************************************************************/

extern "C" int writeOutputWaveFile(WaveFileIO *outputFile,int32_t *outputBuffer,size_t outputTransferSize)
{
    return outputFile->write(outputBuffer, outputTransferSize);
}
/*******************************************************************************
 * 
 * get number of samples red or written
 * output:
 *      size_t : number of samples red or written
 * 
*******************************************************************************/

extern "C" size_t getSampleCount(WaveFileIO *file)
{
    return file->getIoCount();
}

