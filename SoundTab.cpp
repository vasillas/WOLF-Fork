//---------------------------------------------------------------------------
// File  :  SoundTab.cpp
// Date  :  2008-01-16   (yyyy-mm-dd)
// Author:  Wolfgang Buescher  (DL4YHF)
//
// Description:
//     A few TABLES for audio processing, including some filter coeffs
//     and a large sine/cosine table .
//
// Used by/in :
//     \CBproj\SoundUtl\SndInput
//     \CBproj\SoundUtl\SndOutpt
//     \CBproj\SpecLab\SpecLab
//     \CBproj\WOLF\WOLF_gui
//
// Revision history (yyyy-mm-dd):
//   2002-05-05  Written for the "Audio Input Tool" in c:\CBProj\SndInput\..
//   2003-07-07  Optional selection of the internal data type
//               via compiler switch "SWI_FLOAT_PRECISION"
//               (with BCB-IDE: Project..Options..Conditionals)
//   2008-01-16  SoundTab.cpp now also used in the WOLF GUI .
//
//---------------------------------------------------------------------------

#include <windows.h>
#include <math.h>

#pragma hdrstop   // no precompiled headers after this point


#include "SoundTab.h"

#pragma warn -8017


//**************************************************************************
//    Tables used in this module
//**************************************************************************

const T_Float SoundTab_Dec2FilterCoeffs[SoundTab_DEC_FIR_LENGTH] =
{ // Reasonably short 'decimate by 2' - filter (FIR)
  // Design method: Parks-McClellan
  //  25 coefficients,
  //  2 bands,
  // Band Lower Upper Value Weight
  //  1  0.000 0.120 1.000  001.0
  //  2  0.250 0.500 0.0001 100.0
  // Generated by SpecLab's "FIR-Designer2"
    -0.001086881568768   ,
    -0.00367797341826391 ,
    -0.0047920411648502  ,
     0.00129370756629773 ,
     0.0145245113499293  ,
     0.0211455982811658  ,
     0.00276341141492466 ,
    -0.0369726519862278  ,
    -0.0567732234406836  ,
    -0.0041615169748691  ,
     0.128367871654144   ,
     0.275162804208724   ,
     0.339561154995869   ,
     0.275162804208724   ,
     0.128367871654144   ,
    -0.0041615169748691  ,
    -0.0567732234406836  ,
    -0.0369726519862278  ,
     0.00276341141492466 ,
     0.0211455982811658  ,
     0.0145245113499293  ,
     0.00129370756629773 ,
    -0.0047920411648502  ,
    -0.00367797341826391 ,
    -0.001086881568768
}; // end .._Dec2FilterCoeffs[]

const T_Float SoundTab_Dec3FilterCoeffs[SoundTab_DEC_FIR_LENGTH] =
{ // Reasonably short 'decimate by 3' - filter (FIR)
  // Design method: Parks-McClellan
  //  25 coefficients,
  //  2 bands,
  // Band Lower Upper Value Weight
  //  1  0.000 0.120 1.000  001.0
  //  2  0.250 0.500 0.0001 100.0
  // Generated by SpecLab's "FIR-Designer2"
    -0.000286440582680371,
    -0.00188366938636472 ,
    -0.00506620307896015 ,
    -0.00974817248307781 ,
    -0.0139407470519893  ,
    -0.0139210800449785  ,
    -0.00502634467052337 ,
     0.0163468116202039  ,
     0.0504694707843042  ,
     0.0928642782132562  ,
     0.134771696647059   ,
     0.16568873828291    ,
     0.177106618781497   ,
     0.16568873828291    ,
     0.134771696647059   ,
     0.0928642782132562  ,
     0.0504694707843042  ,
     0.0163468116202039  ,
    -0.00502634467052337 ,
    -0.0139210800449785  ,
    -0.0139407470519893  ,
    -0.00974817248307781 ,
    -0.00506620307896015 ,
    -0.00188366938636472 ,
    -0.000286440582680371
}; // end .._Dec3FilterCoeffs[]



const T_Float SoundTab_HalfbandIIR20Lowpass[2 + 2*20] =
{ // Sharp lowpass with cutoff frequency at f_sample/4  (IIR!!!)
  // Used for frequency shifter with WEAVER method for SSB generation.
  // Design: IIR-lowpass, 20 poles, 10% ripple.
  // Generated with an algorithm from
  // "The Scientist and Engineer's Guide to Digital Signal Processing",
  //  (www.dspguide.com/ch33.pdf),  implemented in SpecLab's IIR-designer.
     4.70393767569322E-8,  // alpha0
     0.00000000000000,     // beta 0 (must ALWAYS be zero)
     9.40787535138644E-7,  // alpha1
    -7.37937507944975,     // beta 1
     8.93748158381712E-6,  // alpha2
    31.35383471157,        // beta 2
     5.36248895029027E-5,  // alpha3
   -95.7669628382699,      // beta 3
     0.000227905780387336, // alpha4
   230.742166761759,       // beta 4
     0.000729298497239477, // alpha5
  -459.648957783366,       // beta 5
     0.00182324624309869,  // alpha6
   778.55527523619,        // beta 6
     0.00364649248619738,  // alpha7
 -1141.18099426738,        // beta 7
     0.00592555029007075,  // alpha8
  1463.94098955599,        // beta 8
     0.00790073372009433,  // alpha9
 -1655.07761650689,        // beta 9
     0.00869080709210376,  // alpha10
  1655.14599332697,        // beta 10
     0.00790073372009433,  // alpha11
 -1465.43260621866,        // beta 11
     0.00592555029007075,  // alpha12
  1146.68419764568,        // beta 12
     0.00364649248619738,  // alpha13
  -789.353435959327,       // beta 13
     0.00182324624309869,  // alpha14
   474.203967067946,       // beta 14
     0.000729298497239477, // alpha15
  -245.503175016472,       // beta 15
     0.000227905780387336, // alpha16
   107.435273474231,       // beta 16
     5.36248895029027E-5,  // alpha17
   -38.54803576573,        // beta 17
     8.93748158381712E-6,  // alpha18
    10.7729912453745,      // beta 18
     9.40787535138644E-7,  // alpha19
    -2.12369860323379,     // beta 19
     4.70393767569322E-8,  // alpha20
     0.229493374581084     // beta 20
}; // end T_Float SoundTab_HalfbandIIRLowpass[]



//**************************************************************************
//    Global Variables
//**************************************************************************


// A reasonably long cosine table with a length of ONE period.
//  Used for test signal generators,  frequency converters etc etc.
// Filled with :
//  SOUND_cos_table[i] = cos((T_Float)i * 2.0 * PI / (T_Float)SOUND_COS_TABLE_LEN);
// Note: SOUND_COS_TABLE_LEN is now fixed to 32768, because the same table is
//  used in various "DSP plugins" now - and changing the table size would
//  render those plugins incompatible with their hosts !
float SoundTab_fltCosTable[SOUND_COS_TABLE_LEN];


//**************************************************************************
//    Routines (no class methods)
//**************************************************************************


//***************************************************************************
void SoundTab_InitCosTable(void) // should be called ONCE in the initialization
{
   // Build a reasonably long cosine table with a length of ONE period.
   for(int i=0; i<SOUND_COS_TABLE_LEN; ++i)
     SoundTab_fltCosTable[i] = cos((T_Float)i * 2.0 * M_PI / (T_Float)SOUND_COS_TABLE_LEN);
} // end SoundTab_InitCosTable()

/***************************************************************************/
void SoundTab_GetNcoParams(
      T_Float dblNcoFreqDivSampleRate, // input : NCO frequency divided by sampling rate
      int    *piSineTableOffset,      // output: offset from cosine- to sine table index
      T_Float *pdblPhzInc )            // output: phase increment value (floating point!!)
{
  // Prepare the NCO for the "mixer" frequency ...
  // Note: SoundTab_fltCosTable[SOUND_COS_TABLE_LEN] contains exactly ONE PERIOD.
  //       "Negative" frequencies are possible by inverting the Q-channel .
  *pdblPhzInc = (T_Float)SOUND_COS_TABLE_LEN * dblNcoFreqDivSampleRate;
   if(*pdblPhzInc > 0)
    { // array index offset to read a SINE WAVE from a COSINE TABLE :
      if(piSineTableOffset)
        *piSineTableOffset = (int) (0.499 + 3.0 * (T_Float)SOUND_COS_TABLE_LEN / 4.0);
    }
   else // phase increment negative, "negative" mixer frequency (yep, thats possible)...
    {
      *pdblPhzInc = -*pdblPhzInc; // Make sure the table reading index INCREMENTS,
                                  // because the wrap test will not look for negative indices.
      // Get array index offset to read a NEGATIVE SINE WAVE from a COSINE TABLE :
      if(piSineTableOffset)
        *piSineTableOffset = (int)(0.499 + (T_Float)SOUND_COS_TABLE_LEN / 4.0);
    } // end if <produce NEGATIVE frequencies ... possible only with I/Q mult. >


   // How to generate a complex oscillator signal ( NCO with sin/cos output ) :
   //
   // if(dblNcoPhase<0) dblNcoPhase=0;
   // dblNcoPhase += dblPhzInc;
   // while(dblNcoPhase >=(T_Float)SOUND_COS_TABLE_LEN) // "while", not "if" !!
   //       dblNcoPhase -=(T_Float)SOUND_COS_TABLE_LEN; // table index wrap
   // iCosTableIndex = (int)pBigBuffer->dblNcoPhase;
   // nco.re = SoundTab_fltCosTable[iCosTableIndex];
   // nco.im = SoundTab_fltCosTable[(iCosTableIndex+iSineTableOffset) % SOUND_COS_TABLE_LEN];

} // end SndTab_GetNcoParams()




/* EOF <SoundTab.cpp> */

