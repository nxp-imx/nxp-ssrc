/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcNeonTest.h"
extern "C" void getInfo(WaveFileIO *inputFile, struct WaveFileInfo *info);
unsigned getNumberOfFilters();

const char *ConverterExample::qualityList[3] =
{
    "qualityHigh","qualityMedium","qualityLow"
};

/*
   convert input file to output file
*/

bool ConverterExample::convertFile(string &inputFileName, string &outputFileName, unsigned outputSamplingRate, string  quality)
{
    /*
        open input wave file and get the headers
    */
    const char *error = inputFile.openRead(inputFileName);
    if (error != nullptr)
    {
        cerr << error << " for file input file:" << inputFileName << endl;
        return false;
    }
    /*
        SSRC only accept 32 bits int or 32 bits float
    */

    SampleFormat sampleFormat = inputFile.getSampleFormat();

    if (sampleFormat == SampleFormat_LE_PCM_32_bits)
    {
        config.requestedSampleFormat = SsrcSampleFormat_int32;
    }
    else if (sampleFormat == SampleFormat_LE_FLOAT_32_bits)
    {
        config.requestedSampleFormat = SsrcSampleFormat_float32;
    }
    else
    {
        cerr << "only 32 bits integer and 32 bits float sample formats are supported" << endl;
        return false;
    }
    /*
        SSRC only accept stereo or mono 
    */
    if (inputFile.NumChannels > 2)
    {
        cerr << "Error:only mono or stereo supported, inputfile:" << inputFileName << " has :" << inputFile.NumChannels << endl;
        return false;
    }
    /*
        open output file with same format as input file
    */
    WaveFileInfo outHeader;
    getInfo(&inputFile, &outHeader);


     
    outHeader.SampleRate = outputSamplingRate;
    error = outputFile.openWrite(outputFileName, &outHeader);
    if (error != nullptr)
    {
        cerr << error << " for output file:" << outputFileName << endl;
        return false;
    }
    /*
        configure SSRC 
    */
    config.inputSampleRate = inputFile.SampleRate;
    config.outputSampleRate = outputSamplingRate;
    // stereo or mono
    config.stereo = inputFile.NumChannels == 2;
    // using 112 tap interpolator
    config.requestedInterpolationNumberOfTaps = 0;
    // using 112 tap interpolator
    if (strcmp(quality.c_str(), qualityList[0]) == 0)
    {
        config.sampleRateConversionQuality = SsrcResampleConversionQuality_high;
    }
    else if (strcmp(quality.c_str(), qualityList[1]) == 0)
    {
        config.sampleRateConversionQuality = SsrcResampleConversionQuality_medium;
    }
    else if (strcmp(quality.c_str(), qualityList[2]) == 0)
    {
        config.sampleRateConversionQuality = SsrcResampleConversionQuality_low;
    }
    else
    {
        cerr << quality << "  not supported" << endl;
        return false;
    }
    // input chunck size of 128 (only multiple of 128 allowed)
    config.inputTrasferSizeInTransferUnits = 1;
    // output chunck size of 128 (only multiple of 128 allowed)
    config.outputTrasferSizeInTransferUnits = 1 ;

    /*
        get the converter according to configuration
        return false if can't find converter according to the configuration
    */
    if (!converterList.getConverter(config, converterContainer))
    {
        // walk through error list if failed
        for (int index = 0; index < converterContainer.log.index; index++)
        {
            cerr << converterContainer.log.list[index] << endl;
        }

        return false;
    }
    /*
        run the converter according to input sample type
    */
    bool status = processFile();

    delete(converterContainer.converterPointer);

    return status;
}
/*
    template function based of input sample type
*/
bool ConverterExample::processFile()
{
    /*
        easy buffer allocator with destructor
        using int32_t for both int32_t samples and float sample
        since only the bit depth matters for the buffers
    */
    int transferSize = config.inputTrasferSizeInTransferUnits*  converterContainer.inputOutputTransferTransferUnitSize;
    vector<int32_t> inputBuffer(transferSize);
    vector<int32_t> outputBuffer(transferSize);
    inputBuffer.assign(transferSize, 0);
    outputBuffer.assign(transferSize, 0);
    /*
        if memory allocation error return false
    */
    if (inputBuffer.size() != transferSize || outputBuffer.size() != transferSize)
    {
        cerr << "memory allocation error" << endl;
        return false;
    }
    /*
        more input is from input file
    */
    bool haveMoreInput = true;
    /*
        get the converter pointer from 
    */
    SsrcSampleRateConverterInterface *converter;
    if (!converterContainer.getConverterObject(converter))
    {
        // this should not happen
        cerr << "internal error" << endl;
        return false;
    }
    converter->reset(0);
    bool exitAfterTrace = false;
    bool processedSamples = false;
    /*
        prcesss input file loop
    */
    do
    {
        /*
            while there is not enough input samples to generate output 
        */
        while (!converter->haveEnoughSamplesToProcess())
        {
            /*
                read samples from input file
            */
            if ((haveMoreInput = (inputFile.read(inputBuffer) == transferSize)))
            {
                bool inputBufferFull = !converter->put(inputBuffer.data());
                /*
                    Something has gone wrong
                    the is not enough samples in the queue to process, but we can not put more samples
                */
                if (inputBufferFull)
                {
                    // this should not happen
                    cerr << "internal error" << endl;
                    return false;
                }

            }
            /*
            out of input
            */
            else
            {
                break;
            }
        }
        /*
            generate as much ouput as we have enough input samples 
            and output samples that are generated
        */
        while (converter->process())
        {
            processedSamples = true;
            while(converter->get(outputBuffer.data()))
            {
                outputFile.write(outputBuffer);
            }
        }
        if (exitAfterTrace && processedSamples)
        {
            break;
        }
        /*
            no more input and not enough enough samples to generate output, exit 
        */
    } while (haveMoreInput);
    return true;
}
/*
   ssrc converter
*/

int ssrcConverter(int argc, char **argv)
{
    /*
        need input file, output file and output sample rate
    */
    if (argc < 5)
    {
        printf("Not Enough parameter, Usage:\n");
        printf("%s <input file>  <output file> <output sampling rate> <qualityHigh,qualityMedium,qualityLow>\n", argv[0]);
        return 1;
    }

    /*
        for simplicity this sample program using string containers for names
    */
    string inputFileName (argv[1]);
    string outputFileName (argv[2]);
    /*
        output sample rate from text to integer
    */
    unsigned outputSampleRate = atoi(argv[3]);
    string quality(argv[4]);

    ConverterExample converter;
    return converter.convertFile(inputFileName, outputFileName, outputSampleRate, quality) == false;
}

void printSsrcSampleRateConverterDefinition(ofstream &outputFile, SsrcSampleRateConverterDefinition *in)
{
	if (in != nullptr)
	{
		outputFile << in->sampleRateConverterNo << ",";
		outputFile << in->libSymbolToGet << ",";
		outputFile << in->sampleRateRatioInput << ",";
		outputFile << in->sampleRateRatioOutput << ",";
		outputFile << in->numberOftapsPerPhase << ",";
		outputFile << (in->sampleFormat == SsrcSampleFormat_int32 ? "int32": "float32") << endl;
	}
}

void printQuantizedFitlerEntry(ofstream &outputFile, const QuantizedFitlerEntry *in)
{
	if (in != nullptr)
	{
		outputFile << in->filterNumber << ",";
		outputFile << in->libSymbolToGet << ",";
		outputFile << in->sampleRateRatioInput << ",";
		outputFile << in->sampleRateRatioOutput << ",";
		outputFile << in->numberOftapsPerPhase << ",";
		outputFile << (in->sampleFormat == SsrcSampleFormat_int32 ? "int32" : "float32") << endl;
	}
}

/*
    main !
*/
 
int main(int argc, char **argv)
{
	if (true)
	{
		ofstream filterListFile("filterList.csv", ofstream::out);
		ofstream converterListFile("converterList.csv", ofstream::out);
		int numberOfFilters = getNumberOfFilters();
		for (int index = 0; index < numberOfFilters; index++)
		{
			const QuantizedFitlerEntry *filter = InterpolationFilterList::getInterpolationFilter(index);
			printQuantizedFitlerEntry(filterListFile, filter);
		}
		SsrcSampleRateConverterList converterList;
		int numberOFConverters = converterList.getNumberOfConverters();
		for (int index = 0; index < numberOFConverters; index++)
		{
			SsrcSampleRateConverterDefinition *converterP = converterList.getConverter(index);
			printSsrcSampleRateConverterDefinition(converterListFile, converterP);
		}
	}

	return ssrcConverter(argc, argv);
}
