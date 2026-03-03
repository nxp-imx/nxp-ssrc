/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef wavFile_h
#define wavFile_h
#include <memory.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <malloc.h>
#ifdef __cplusplus

#include <vector>
#include <cstdint>
#include <ctime>
#include <ratio>
#include <chrono>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>   
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ostream>

/*!******************************************************************************************
**
**
**
*******************************************************************************************/
using namespace std;
#endif
/*!******************************************************************************************
**
**
**
*******************************************************************************************/
/*
The canonical WAVE format starts with the RIFF header:

0         4   ChunkID          Contains the letters "RIFF" in ASCII form
(0x52494646 big-endian form).
4         4   ChunkSize        36 + SubChunk2Size, or more precisely:
4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
This is the size of the rest of the chunk
following this number.  This is the size of the
entire file in bytes minus 8 bytes for the
two fields not included in this count:
ChunkID and ChunkSize.
8         4   Format           Contains the letters "WAVE"(0x57415645 big-endian form).

The "WAVE" format consists of two subchunks: "fmt " and "data":
The "fmt " subchunk describes the sound data's format:

12        4   FormatBlockID    Contains the letters "fmt "
(0x666d7420 big-endian form).
16        4   FormatBlockSize  16 for PCM.  This is the size of the rest of the Subchunk which follows this number.
20        2   AudioFormat      PCM = 1 (i.e. Linear quantization)
Values other than 1 indicate some form of compression.
22        2   NumChannels      Mono = 1, Stereo = 2, etc.
24        4   SampleRate       8000, 44100, etc.
28        4   ByteRate         == SampleRate * NumChannels * BitsPerSample/8
32        2   BlockAlign       == NumChannels * BitsPerSample/8
The number of bytes for one sample including all channels. I wonder what happens when this number isn't an integer?
34        2   BitsPerSample    8 bits = 8, 16 bits = 16, etc.
       2   ExtraParamSize   if PCM, then doesn't exist
       X   ExtraParams      space for extra parameters

The "data" subchunk contains the size of the data and the actual sound:

36        4   DataBlockID      Contains the letters "data"
(0x64617461 big-endian form).
40        4   DataBlockSize    == NumSamples * NumChannels * BitsPerSample/8
This is the number of bytes in the data. You can also think of this as the size of the read of the subchunk following this number.
44        *   Data             The actual sound data.
*/
/*!******************************************************************************************
*
*
*******************************************************************************************/
enum SampleFormat
{
    SampleFormat_LE_8_bits,
    SampleFormat_LE_PCM_16_bits,
    SampleFormat_LE_PCM_24_bits,
    SampleFormat_LE_PCM_32_bits,
    SampleFormat_LE_PCM_64_bits,
    SampleFormat_LE_FLOAT_32_bits,
    SampleFormat_LE_FLOAT_64_bits,
    SampleFormat_BE_PCM_16_bits,
    SampleFormat_BE_PCM_24_bits,
    SampleFormat_BE_PCM_32_bits,
    SampleFormat_BE_PCM_64_bits,
    SampleFormat_BE_FLOAT_32_bits,
    SampleFormat_BE_FLOAT_64_bits
};
/*!******************************************************************************************
*
*
*******************************************************************************************/
enum SampleFormatEndian
{
    SampleFormatLittleEndian,
    SampleFormatBigEndian
};

/*!******************************************************************************************
*
*
*******************************************************************************************/
enum WAVE_FORMATS
{
    WAVE_FORMAT_PCM = 0x0001,            // PCM
    WAVE_FORMAT_IEEE_FLOAT = 0x0003,     // IEEE float
    WAVE_FORMAT_ALAW = 0x0006,           // 8 - bit ITU - T G.711 A - law
    WAVE_FORMAT_MULAW = 0x0007,          // 8 - bit ITU - T G.711 � - law
    WAVE_FORMAT_EXTENSIBLE = 0xFFFE      // Determined by SubFormat
};



struct WavfileFormatChunkBase
{
    char     ChunkID[4];
    uint32_t ChunkSize;
    char     Format[4];
    char	 FormatBlockID[4];
    uint32_t FormatBlockSize;
};
struct WavfileFormatChunkFormatBlock
{
    uint16_t AudioFormat;
    uint16_t NumChannels;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
};
struct WavfileSubChunk
{
    char	 DataBlockID[4];
    uint32_t DataBlockSize;
};




#ifdef __cplusplus
struct int24_t
{
    uint8_t data[3];
    union Conv
    {
        uint8_t data[3];
        int val24 : 24;
        int32_t val32;
    };
    int24_t()
    {
        data[0] = data[1] = data[2] = 0;
    }
    int24_t(int32_t val)
    {
        *this = val;
    }
    operator int32_t ()
    {
        Conv conv;
        conv.data[0] = data[0];
        conv.data[1] = data[1];
        conv.data[2] = data[2];

        return conv.val24;
    }

    void operator = (int32_t val)
    {
        Conv conv;
        conv.val24 = val;
        data[0] = conv.data[0];
        data[1] = conv.data[1];
        data[2] = conv.data[2];
    }
};

struct WavfileFormatChunk:
    public WavfileFormatChunkBase,
    public WavfileFormatChunkFormatBlock
{
};
struct WavfileHeader :
    WavfileFormatChunk,
    WavfileSubChunk

{

    void clear()
    {
        memset(this, 0, sizeof(WavfileHeader));
    }
    void print(ostream &out)
    {
        out << ":ChunkID=" << ChunkID[0] << ChunkID[1] << ChunkID[2] << ChunkID[3];
        out << ":ChunkSize=" << ChunkSize;
        out << ":Format =" << Format[0] << Format[1] << Format[2] << Format[3];
        out << ":FormatBlockID =" << FormatBlockID[0] << FormatBlockID[1] << FormatBlockID[2] << FormatBlockID[3];
        out << ":FormatBlockSize=" << FormatBlockSize;
        out << ":AudioFormat=" << AudioFormat;
        out << ":NumChannels=" << NumChannels;
        out << ":SampleRate=" << SampleRate;
        out << ":ByteRate=" << ByteRate;
        out << ":BlockAlign=" << BlockAlign;
        out << ":BitsPerSample=" << BitsPerSample;
        out << ":DataBlockID=" << DataBlockID[0] << DataBlockID[1] << DataBlockID[2] << DataBlockID[3];
        out << ":DataBlockSize=" << DataBlockSize;
    }

};
/*!******************************************************************************************
*
*
*******************************************************************************************/
inline void WavfourChar(ostream &file, char *p)
{
    file << p[0] << p[1] << p[2] << p[3] << endl;

}
/*!******************************************************************************************
*
*
*******************************************************************************************/

inline ostream &operator << (ostream &file, WavfileHeader &wf)
{
    file << "ChunkID:";
    WavfourChar(file, wf.ChunkID);
    file << "ChunkSize:" << wf.ChunkSize << endl;
    file << "Format:";
    WavfourChar(file, wf.Format);
    file << "FormatBlockID:";
    WavfourChar(file, wf.FormatBlockID);
    file << "FormatBlockSize:" << wf.FormatBlockSize << endl;
    file << "AudioFormat:" << wf.AudioFormat << endl;
    file << "NumChannels:" << wf.NumChannels << endl;
    file << "SampleRate:" << wf.SampleRate << endl;
    file << "ByteRate:" << wf.ByteRate << endl;
    file << "BlockAlign:" << wf.BlockAlign << endl;
    file << "BitsPerSample:" << wf.BitsPerSample << endl;
    file << "DataBlockID:";
    WavfourChar(file, wf.DataBlockID);
    file << "DataBlockSize:" << wf.DataBlockSize << endl;
    return file;
}
/*!******************************************************************************************
*
*
*******************************************************************************************/
struct WaveFileIO:
    public WavfileHeader
{
    FILE *file;
    ios_base::openmode openMode;
    size_t ioCount;
    SampleFormatEndian endian;
    SampleFormat sampleFormat;
    bool isgood;
    bool ieeeFloat;
public:
    WaveFileIO()
    {
        WavfileHeader::clear();
        openMode = fstream::out;
        ioCount = 0;
        file = nullptr;
        isgood = false;
    }
    ~WaveFileIO()
    {
        close();
    }
    const char *close()
    {
        if (file != nullptr)
        {
            if (openMode == fstream::out)
            {
                DataBlockSize = (uint32_t)ioCount * BitsPerSample/8;
                ByteRate = SampleRate * NumChannels* BitsPerSample / 8;
                BlockAlign = NumChannels * BitsPerSample / 8;
                ChunkSize = DataBlockSize + sizeof(WavfileHeader) - 8;
                fseek(file, 0, SEEK_SET);
                WavfileHeader * header = static_cast<WavfileHeader *>(this);
                if (fwrite(header, sizeof(WavfileHeader), 1, file) != sizeof(WavfileHeader))
                {
                    isgood = false;
                    return "write error";
                }
            }
            fclose(file);
        }
        return nullptr;
    }
    const char *openRead(string &fileName)
    {
        openMode = fstream::in;
        file = fopen(fileName.c_str(),  "rb" );
        if (file == nullptr)
        {
            isgood = false;
            return "can't open file";
        }
        WavfileFormatChunk *headerFormat = static_cast<WavfileFormatChunk *>(this);

        isgood = true;
        isgood &= (fread(headerFormat, 1, sizeof(WavfileFormatChunk), file) == sizeof(WavfileFormatChunk));
        if (strncmp(ChunkID, "RIFF", 4) == 0)
        {
            endian = SampleFormatLittleEndian;
        }
        else if (strncmp(ChunkID, "RIFX", 4) == 0)
        {
            endian = SampleFormatBigEndian;
        }
        else
        {
            isgood = false;
            return "invalid chunkID";
        }
        isgood &= strncmp(Format, "WAVE", 4) == 0;
        isgood &= strncmp(FormatBlockID, "fmt ", 4) == 0;
        isgood &= (AudioFormat == WAVE_FORMAT_EXTENSIBLE || AudioFormat == WAVE_FORMAT_PCM || AudioFormat == WAVE_FORMAT_IEEE_FLOAT);

        long extra = FormatBlockSize - sizeof(WavfileFormatChunkFormatBlock);
        isgood &= fseek(file, extra, SEEK_CUR) == 0;

        while (isgood)
        {
            WavfileSubChunk * subChunk = dynamic_cast<WavfileSubChunk *>(this);
            if (fread(subChunk, 1, sizeof(WavfileSubChunk), file) != sizeof(WavfileSubChunk))
            {
                isgood = false;
                return "invalid wav file";
            }
            if (strncmp(DataBlockID, "data", 4) == 0)
            {
                break;
            }
            long blockSize = DataBlockSize;
            isgood &= fseek(file, blockSize, SEEK_CUR) == 0;
        }
        if (AudioFormat == WAVE_FORMAT_PCM || AudioFormat == WAVE_FORMAT_EXTENSIBLE)
        {
            switch (BitsPerSample)
            {
                case 8:
                    sampleFormat = SampleFormat_LE_8_bits;
                    break;
                case 16:
                    sampleFormat = endian == SampleFormatLittleEndian ? SampleFormat_LE_PCM_16_bits : SampleFormat_BE_PCM_16_bits;
                    break;
                case 24:
                    sampleFormat = endian == SampleFormatLittleEndian ? SampleFormat_LE_PCM_24_bits : SampleFormat_BE_PCM_24_bits;
                    break;
                case 32:
                    sampleFormat = endian == SampleFormatLittleEndian ? SampleFormat_LE_PCM_32_bits : SampleFormat_BE_PCM_32_bits;
                    break;
                case 64:
                    sampleFormat = endian == SampleFormatLittleEndian ? SampleFormat_LE_PCM_64_bits : SampleFormat_BE_PCM_64_bits;
                    break;

                default:
                    isgood = false;
                    return "invalid bit depth";
            }
        }
        else if (AudioFormat == WAVE_FORMAT_IEEE_FLOAT)
        {
            switch (BitsPerSample)
            {
                case 32:
                    sampleFormat = endian == SampleFormatLittleEndian ? SampleFormat_LE_FLOAT_32_bits : SampleFormat_BE_FLOAT_32_bits;
                    break;
                case 64:
                    sampleFormat = endian == SampleFormatLittleEndian ? SampleFormat_LE_FLOAT_64_bits : SampleFormat_BE_FLOAT_64_bits;
                    break;

                default:
                    isgood = false;
            }
        }
        else
        {
            isgood = false;
            return "invalid bit audio format";
        }
        return nullptr;

    }
    WavfileHeader &getHeader()
    {
        return (*this);
    }
    WavfileHeader &setHeader(WavfileHeader &_header)
    {
        WavfileHeader & header = static_cast<WavfileHeader &>(*this);
        header = _header;
        return (*this);
    }
    const char *openWrite(string &fileName, WaveFileInfo *formatInfo)
    {
        openMode = fstream::out;
        file = fopen(fileName.c_str(), "wb");
        isgood = true;
        if (file == nullptr)
        {
            isgood = false;
            return "error open file";
        }
        WavfileFormatChunk *headerFormat = static_cast<WavfileFormatChunk *>(this);

        strncpy(ChunkID, "RIFF", 4);
        strncpy(Format, "WAVE", 4);
        strncpy(FormatBlockID, "fmt ", 4);
        strncpy(DataBlockID, "data", 4);
        FormatBlockSize = sizeof(WavfileFormatChunkFormatBlock);

        AudioFormat = formatInfo->AudioFormat;
        NumChannels = formatInfo->NumChannels;
        SampleRate = formatInfo->SampleRate;
        BitsPerSample = formatInfo->BitsPerSample;
        ByteRate = (uint32_t)(NumChannels*SampleRate * (BitsPerSample / 8));;
        BlockAlign = (uint16_t)(NumChannels*BitsPerSample / 8);
        DataBlockSize = 0;
        ChunkSize = 0;

        WavfileHeader & header = static_cast<WavfileHeader &>(*this);
        if (fwrite((char *)&header,1, sizeof(WavfileHeader),file) != sizeof(WavfileHeader))
        {
            fclose(file);
            file = nullptr;
            isgood = false;
            return "file write error";
        }
        return nullptr;
    }
    template<class _TYPE_> size_t read(_TYPE_ *buffer,size_t count)
    {
        if (file != nullptr && isgood)
        {
            size_t bytes = count * sizeof(_TYPE_);
            size_t bytesRed = fread(buffer,1, bytes, file);
            streamsize red = bytesRed / sizeof(_TYPE_);
            isgood &= red == count;
            ioCount += red;
            return red;
        }
        return 0;
    }
    template<class _TYPE_> size_t read(vector<_TYPE_> &buffer)
    {
        return read(buffer.data(), buffer.size());
    }

    template<class _TYPE_> bool write(_TYPE_ *buffer, size_t count)
    {
        if (file != nullptr && isgood)
        {
            size_t bytes = count * sizeof(_TYPE_);
            size_t byteswrite = fwrite(buffer,1, bytes, file);
            streamsize wrote = byteswrite / sizeof(_TYPE_);
            isgood &= wrote == count;
            ioCount += wrote;
            return wrote;
        }
        return 0;
    }

    template<class _TYPE_> bool write(vector<_TYPE_> &buffer)
    {
        return write(buffer.data(), buffer.size());
    }
    bool good()
    {
        return file != nullptr && isgood ;
    }
    SampleFormat getSampleFormat()
    {
        return sampleFormat;
    }
    size_t getIoCount()
    {
        return ioCount;
    }

};
#endif
#endif //wavFile_h
