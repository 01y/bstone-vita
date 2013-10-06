#ifndef _JM_CIO_H_
#define _JM_CIO_H_

//
// UNIT : JM_CIO.h
//
// FUNCTION : General defines, prototypes, typedefs used in all the
//				  supported compression techniques used in JAMPAK Ver x.x
//
//


#include "SDL.h"


#ifndef _ID_HEADS_H_
//typedef Sint16 boolean;
#endif


//==========================================================================
//
//	  							PARAMETER PASSING TYPES
//
//
	// SOURCE PARAMS (LO BYTE)

#define SRC_FILE	 			(0x0001)			// GE Buffered IO
#define SRC_FFILE				(0x0002)			// Stdio File IO (fwrite etc.)
#define SRC_MEM				(0x0004)			// Std void ptr (alloc etc)
#define SRC_BFILE				(0x0008)				// Buffered File I/O

#define SRC_TYPES 			(SRC_FILE | SRC_FFILE | SRC_MEM | SRC_BFILE)

	// DESTINATION PARAMS (HI BYTE)

#define DEST_FILE				(0x0100)			// GE Buffered IO
#define DEST_FFILE			(0x0200)			// Stdio File IO (fwrite etc.)
#define DEST_MEM				(0x0400)			// Std void ptr (alloc etc)
#define DEST_IMEM				(0x0800)			// ID Memory alloc

#define DEST_TYPES 			(DEST_FILE | DEST_FFILE | DEST_MEM | DEST_IMEM)



//=========================================================================
//
// 								FILE CHUNK IDs
//
// NOTE: The only reason for changing from COMP to CMP1 and having multi
//			comp header structs is for downward compatablity.
//

#define COMP					("COMP")		// Comp type is ct_LZW ALWAYS!
#define JAMP					("JAMP")		// New Version different from SOFTDISK.


//
// 	COMPRESSION TYPES
//
typedef enum ct_TYPES
{
		ct_NONE = 0,						// No compression - Just data..Rarely used!
		ct_LZW,								// LZW data compression
		ct_LZH

} ct_TYPES;

//
//  	FILE CHUNK HEADER FORMATS
//

struct COMPStruct
{
	Uint32 DecompLen;
};


struct JAMPHeader
{
	Uint32 OriginalLen;			// Original FileLength of compressed Data.
	ct_TYPES CompType;					// SEE: ct_TYPES above for list of pos.
	Uint32 CompressLen;			// Length of data after compression (A MUST for LZHUFF!)
};


//
// Header on JAMPAKd Data
//


struct CompHeader_t {
    char NameId[4];
    Uint32 OriginalLen; // Original FileLength of compressed Data.
    ct_TYPES CompType; // SEE: ct_TYPES above for list of pos.
    Uint32 CompressLen; // Length of data after compression (A MUST for LZHUFF!)
}; // struct CompHeader_t


//---------------------------------------------------------------------------
//
//								FUNCTION PROTOTYPEING
//
//---------------------------------------------------------------------------

// FIXME
#if 0
char CIO_WritePtr(Sint32 outfile, Uint8 data, Uint16 PtrType);
Sint16 CIO_ReadPtr(Sint32 infile, Uint16 PtrType);
#endif // 0

char CIO_WritePtr(
    void*& dst,
    Uint8 value);

Sint16 CIO_ReadPtr(
    const void*& src);

#endif
