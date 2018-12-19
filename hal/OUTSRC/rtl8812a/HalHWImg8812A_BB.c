/****************************************************************************** 
* 
* Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved. 
* 
* This program is free software; you can redistribute it and/or modify it 
* under the terms of version 2 of the GNU General Public License as 
* published by the Free Software Foundation. 
* 
* This program is distributed in the hope that it will be useful, but WITHOUT 
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
* more details. 
* 
* You should have received a copy of the GNU General Public License along with 
* this program; if not, write to the Free Software Foundation, Inc., 
* 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA 
* 
* 
******************************************************************************/

#include "../odm_precomp.h"

#if (RTL8812A_SUPPORT == 1)
static BOOLEAN
CheckCondition(
    const u4Byte  Condition,
    const u4Byte  Hex
    )
{
    u4Byte _board     = (Hex & 0x000000FF);
    u4Byte _interface = (Hex & 0x0000FF00) >> 8;
    u4Byte _platform  = (Hex & 0x00FF0000) >> 16;
    u4Byte cond = Condition;

    if ( Condition == 0xCDCDCDCD )
        return TRUE;

    cond = Condition & 0x000000FF;
    if ( (_board != cond) && (cond != 0xFF) )
        return FALSE;

    cond = Condition & 0x0000FF00;
    cond = cond >> 8;
    if ( ((_interface & cond) == 0) && (cond != 0x07) )
        return FALSE;

    cond = Condition & 0x00FF0000;
    cond = cond >> 16;
    if ( ((_platform & cond) == 0) && (cond != 0x0F) )
        return FALSE;
    return TRUE;
}


/******************************************************************************
*                           AGC_TAB.TXT
******************************************************************************/

u4Byte Array_MP_8812A_AGC_TAB[] = { 
	0xFF0F07D8, 0xABCD,
		0x81C, 0xFF000001,
		0x81C, 0xFF020001,
		0x81C, 0xFF040001,
		0x81C, 0xFE060001,
		0x81C, 0xFD080001,
		0x81C, 0xFC0A0001,
		0x81C, 0xFB0C0001,
		0x81C, 0xFA0E0001,
		0x81C, 0xF9100001,
		0x81C, 0xF8120001,
		0x81C, 0xF7140001,
		0x81C, 0xF6160001,
		0x81C, 0xF5180001,
		0x81C, 0xF41A0001,
		0x81C, 0xF31C0001,
		0x81C, 0xF21E0001,
		0x81C, 0xF1200001,
		0x81C, 0xF0220001,
		0x81C, 0xEF240001,
		0x81C, 0xEE260001,
		0x81C, 0xED280001,
		0x81C, 0xEC2A0001,
		0x81C, 0xEB2C0001,
		0x81C, 0xEA2E0001,
		0x81C, 0xE9300001,
		0x81C, 0xE8320001,
		0x81C, 0xC7340001,
		0x81C, 0xC6360001,
		0x81C, 0xC5380001,
		0x81C, 0xC43A0001,
		0x81C, 0xC33C0001,
		0x81C, 0xC23E0001,
		0x81C, 0xC1400001,
		0x81C, 0xA6420001,
		0x81C, 0xA5440001,
		0x81C, 0xA4460001,
		0x81C, 0x69480001,
		0x81C, 0x684A0001,
		0x81C, 0x674C0001,
		0x81C, 0x664E0001,
		0x81C, 0x65500001,
		0x81C, 0x64520001,
		0x81C, 0x63540001,
		0x81C, 0x62560001,
		0x81C, 0x48580001,
		0x81C, 0x475A0001,
		0x81C, 0x465C0001,
		0x81C, 0x455E0001,
		0x81C, 0x44600001,
		0x81C, 0x43620001,
		0x81C, 0x42640001,
		0x81C, 0x41660001,
		0x81C, 0x41680001,
		0x81C, 0x416A0001,
		0x81C, 0x416C0001,
		0x81C, 0x416E0001,
		0x81C, 0x41700001,
		0x81C, 0x41720001,
		0x81C, 0x41740001,
		0x81C, 0x41760001,
		0x81C, 0x41780001,
		0x81C, 0x417A0001,
		0x81C, 0x417C0001,
		0x81C, 0x417E0001,
	0xCDCDCDCD, 0xCDCD,
		0x81C, 0xFF000001,
		0x81C, 0xFF020001,
		0x81C, 0xFF040001,
		0x81C, 0xFF060001,
		0x81C, 0xFF080001,
		0x81C, 0xFE0A0001,
		0x81C, 0xFD0C0001,
		0x81C, 0xFC0E0001,
		0x81C, 0xFB100001,
		0x81C, 0xFA120001,
		0x81C, 0xF9140001,
		0x81C, 0xF8160001,
		0x81C, 0xF7180001,
		0x81C, 0xF61A0001,
		0x81C, 0xF51C0001,
		0x81C, 0xF41E0001,
		0x81C, 0xF3200001,
		0x81C, 0xF2220001,
		0x81C, 0xF1240001,
		0x81C, 0xF0260001,
		0x81C, 0xEF280001,
		0x81C, 0xEE2A0001,
		0x81C, 0xED2C0001,
		0x81C, 0xEC2E0001,
		0x81C, 0xEB300001,
		0x81C, 0xEA320001,
		0x81C, 0xE9340001,
		0x81C, 0xE8360001,
		0x81C, 0xE7380001,
		0x81C, 0xE63A0001,
		0x81C, 0xE53C0001,
		0x81C, 0xC73E0001,
		0x81C, 0xC6400001,
		0x81C, 0xC5420001,
		0x81C, 0xC4440001,
		0x81C, 0xC3460001,
		0x81C, 0xC2480001,
		0x81C, 0xC14A0001,
		0x81C, 0xA74C0001,
		0x81C, 0xA64E0001,
		0x81C, 0xA5500001,
		0x81C, 0xA4520001,
		0x81C, 0xA3540001,
		0x81C, 0xA2560001,
		0x81C, 0xA1580001,
		0x81C, 0x675A0001,
		0x81C, 0x665C0001,
		0x81C, 0x655E0001,
		0x81C, 0x64600001,
		0x81C, 0x63620001,
		0x81C, 0x48640001,
		0x81C, 0x47660001,
		0x81C, 0x46680001,
		0x81C, 0x456A0001,
		0x81C, 0x446C0001,
		0x81C, 0x436E0001,
		0x81C, 0x42700001,
		0x81C, 0x41720001,
		0x81C, 0x41740001,
		0x81C, 0x41760001,
		0x81C, 0x41780001,
		0x81C, 0x417A0001,
		0x81C, 0x417C0001,
		0x81C, 0x417E0001,
	0xFF0F07D8, 0xDEAD,
	0xFF0F0780, 0xABCD,
		0x81C, 0xFC800001,
		0x81C, 0xFB820001,
		0x81C, 0xFA840001,
		0x81C, 0xF9860001,
		0x81C, 0xF8880001,
		0x81C, 0xF78A0001,
		0x81C, 0xF68C0001,
		0x81C, 0xF58E0001,
		0x81C, 0xF4900001,
		0x81C, 0xF3920001,
		0x81C, 0xF2940001,
		0x81C, 0xF1960001,
		0x81C, 0xF0980001,
		0x81C, 0xEF9A0001,
		0x81C, 0xEE9C0001,
		0x81C, 0xED9E0001,
		0x81C, 0xECA00001,
		0x81C, 0xEBA20001,
		0x81C, 0xEAA40001,
		0x81C, 0xE9A60001,
		0x81C, 0xE8A80001,
		0x81C, 0xE7AA0001,
		0x81C, 0xE6AC0001,
		0x81C, 0xE5AE0001,
		0x81C, 0xE4B00001,
		0x81C, 0xE3B20001,
		0x81C, 0xA8B40001,
		0x81C, 0xA7B60001,
		0x81C, 0xA6B80001,
		0x81C, 0xA5BA0001,
		0x81C, 0xA4BC0001,
		0x81C, 0xA3BE0001,
		0x81C, 0xA2C00001,
		0x81C, 0xA1C20001,
		0x81C, 0x68C40001,
		0x81C, 0x67C60001,
		0x81C, 0x66C80001,
		0x81C, 0x65CA0001,
		0x81C, 0x64CC0001,
		0x81C, 0x47CE0001,
		0x81C, 0x46D00001,
		0x81C, 0x45D20001,
		0x81C, 0x44D40001,
		0x81C, 0x43D60001,
		0x81C, 0x42D80001,
		0x81C, 0x08DA0001,
		0x81C, 0x07DC0001,
		0x81C, 0x06DE0001,
		0x81C, 0x05E00001,
		0x81C, 0x04E20001,
		0x81C, 0x03E40001,
		0x81C, 0x02E60001,
		0x81C, 0x01E80001,
		0x81C, 0x01EA0001,
		0x81C, 0x01EC0001,
		0x81C, 0x01EE0001,
		0x81C, 0x01F00001,
		0x81C, 0x01F20001,
		0x81C, 0x01F40001,
		0x81C, 0x01F60001,
		0x81C, 0x01F80001,
		0x81C, 0x01FA0001,
		0x81C, 0x01FC0001,
		0x81C, 0x01FE0001,
	0xFF0F07C0, 0xCDEF,
		0x81C, 0xFC800001,
		0x81C, 0xFB820001,
		0x81C, 0xFA840001,
		0x81C, 0xF9860001,
		0x81C, 0xF8880001,
		0x81C, 0xF78A0001,
		0x81C, 0xF68C0001,
		0x81C, 0xF58E0001,
		0x81C, 0xF4900001,
		0x81C, 0xF3920001,
		0x81C, 0xF2940001,
		0x81C, 0xF1960001,
		0x81C, 0xF0980001,
		0x81C, 0xEF9A0001,
		0x81C, 0xEE9C0001,
		0x81C, 0xED9E0001,
		0x81C, 0xECA00001,
		0x81C, 0xEBA20001,
		0x81C, 0xEAA40001,
		0x81C, 0xE9A60001,
		0x81C, 0xE8A80001,
		0x81C, 0xE7AA0001,
		0x81C, 0xE6AC0001,
		0x81C, 0xE5AE0001,
		0x81C, 0xE4B00001,
		0x81C, 0xE3B20001,
		0x81C, 0xA8B40001,
		0x81C, 0xA7B60001,
		0x81C, 0xA6B80001,
		0x81C, 0xA5BA0001,
		0x81C, 0xA4BC0001,
		0x81C, 0xA3BE0001,
		0x81C, 0xA2C00001,
		0x81C, 0xA1C20001,
		0x81C, 0x68C40001,
		0x81C, 0x67C60001,
		0x81C, 0x66C80001,
		0x81C, 0x65CA0001,
		0x81C, 0x64CC0001,
		0x81C, 0x47CE0001,
		0x81C, 0x46D00001,
		0x81C, 0x45D20001,
		0x81C, 0x44D40001,
		0x81C, 0x43D60001,
		0x81C, 0x42D80001,
		0x81C, 0x08DA0001,
		0x81C, 0x07DC0001,
		0x81C, 0x06DE0001,
		0x81C, 0x05E00001,
		0x81C, 0x04E20001,
		0x81C, 0x03E40001,
		0x81C, 0x02E60001,
		0x81C, 0x01E80001,
		0x81C, 0x01EA0001,
		0x81C, 0x01EC0001,
		0x81C, 0x01EE0001,
		0x81C, 0x01F00001,
		0x81C, 0x01F20001,
		0x81C, 0x01F40001,
		0x81C, 0x01F60001,
		0x81C, 0x01F80001,
		0x81C, 0x01FA0001,
		0x81C, 0x01FC0001,
		0x81C, 0x01FE0001,
	0xFF0F07D8, 0xCDEF,
		0x81C, 0xFC800001,
		0x81C, 0xFB820001,
		0x81C, 0xFA840001,
		0x81C, 0xF9860001,
		0x81C, 0xF8880001,
		0x81C, 0xF78A0001,
		0x81C, 0xF68C0001,
		0x81C, 0xF58E0001,
		0x81C, 0xF4900001,
		0x81C, 0xF3920001,
		0x81C, 0xF2940001,
		0x81C, 0xF1960001,
		0x81C, 0xF0980001,
		0x81C, 0xEF9A0001,
		0x81C, 0xEE9C0001,
		0x81C, 0xED9E0001,
		0x81C, 0xECA00001,
		0x81C, 0xEBA20001,
		0x81C, 0xEAA40001,
		0x81C, 0xE9A60001,
		0x81C, 0xE8A80001,
		0x81C, 0xE7AA0001,
		0x81C, 0xE6AC0001,
		0x81C, 0xE5AE0001,
		0x81C, 0xE4B00001,
		0x81C, 0xE3B20001,
		0x81C, 0xA8B40001,
		0x81C, 0xA7B60001,
		0x81C, 0xA6B80001,
		0x81C, 0xA5BA0001,
		0x81C, 0xA4BC0001,
		0x81C, 0xA3BE0001,
		0x81C, 0xA2C00001,
		0x81C, 0xA1C20001,
		0x81C, 0x68C40001,
		0x81C, 0x67C60001,
		0x81C, 0x66C80001,
		0x81C, 0x65CA0001,
		0x81C, 0x64CC0001,
		0x81C, 0x47CE0001,
		0x81C, 0x46D00001,
		0x81C, 0x45D20001,
		0x81C, 0x44D40001,
		0x81C, 0x43D60001,
		0x81C, 0x42D80001,
		0x81C, 0x08DA0001,
		0x81C, 0x07DC0001,
		0x81C, 0x06DE0001,
		0x81C, 0x05E00001,
		0x81C, 0x04E20001,
		0x81C, 0x03E40001,
		0x81C, 0x02E60001,
		0x81C, 0x01E80001,
		0x81C, 0x01EA0001,
		0x81C, 0x01EC0001,
		0x81C, 0x01EE0001,
		0x81C, 0x01F00001,
		0x81C, 0x01F20001,
		0x81C, 0x01F40001,
		0x81C, 0x01F60001,
		0x81C, 0x01F80001,
		0x81C, 0x01FA0001,
		0x81C, 0x01FC0001,
		0x81C, 0x01FE0001,
	0xCDCDCDCD, 0xCDCD,
		0x81C, 0xFF800001,
		0x81C, 0xFF820001,
		0x81C, 0xFF840001,
		0x81C, 0xFE860001,
		0x81C, 0xFD880001,
		0x81C, 0xFC8A0001,
		0x81C, 0xFB8C0001,
		0x81C, 0xFA8E0001,
		0x81C, 0xF9900001,
		0x81C, 0xF8920001,
		0x81C, 0xF7940001,
		0x81C, 0xF6960001,
		0x81C, 0xF5980001,
		0x81C, 0xF49A0001,
		0x81C, 0xF39C0001,
		0x81C, 0xF29E0001,
		0x81C, 0xF1A00001,
		0x81C, 0xF0A20001,
		0x81C, 0xEFA40001,
		0x81C, 0xEEA60001,
		0x81C, 0xEDA80001,
		0x81C, 0xECAA0001,
		0x81C, 0xEBAC0001,
		0x81C, 0xEAAE0001,
		0x81C, 0xE9B00001,
		0x81C, 0xE8B20001,
		0x81C, 0xE7B40001,
		0x81C, 0xE6B60001,
		0x81C, 0xE5B80001,
		0x81C, 0xE4BA0001,
		0x81C, 0xE3BC0001,
		0x81C, 0xA8BE0001,
		0x81C, 0xA7C00001,
		0x81C, 0xA6C20001,
		0x81C, 0xA5C40001,
		0x81C, 0xA4C60001,
		0x81C, 0xA3C80001,
		0x81C, 0xA2CA0001,
		0x81C, 0xA1CC0001,
		0x81C, 0x68CE0001,
		0x81C, 0x67D00001,
		0x81C, 0x66D20001,
		0x81C, 0x65D40001,
		0x81C, 0x64D60001,
		0x81C, 0x47D80001,
		0x81C, 0x46DA0001,
		0x81C, 0x45DC0001,
		0x81C, 0x44DE0001,
		0x81C, 0x43E00001,
		0x81C, 0x42E20001,
		0x81C, 0x08E40001,
		0x81C, 0x07E60001,
		0x81C, 0x06E80001,
		0x81C, 0x05EA0001,
		0x81C, 0x04EC0001,
		0x81C, 0x03EE0001,
		0x81C, 0x02F00001,
		0x81C, 0x01F20001,
		0x81C, 0x01F40001,
		0x81C, 0x01F60001,
		0x81C, 0x01F80001,
		0x81C, 0x01FA0001,
		0x81C, 0x01FC0001,
		0x81C, 0x01FE0001,
	0xFF0F0780, 0xDEAD,
		0xC50, 0x00000022,
		0xC50, 0x00000020,
		0xE50, 0x00000022,
		0xE50, 0x00000020,

};

void
ODM_ReadAndConfig_MP_8812A_AGC_TAB(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8812A_AGC_TAB)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8812A_AGC_TAB;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8812A_AGC_TAB, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		    odm_ConfigBB_AGC_8812A(pDM_Odm, v1, bMaskDWord, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		     		odm_ConfigBB_AGC_8812A(pDM_Odm, v1, bMaskDWord, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           AGC_TAB_DIFF.TXT
******************************************************************************/

u4Byte Array_MP_8812A_AGC_TAB_DIFF_LB[] = { 
	0xFF0F0780, 0xABCD,
		0x81C, 0x47CE0001,
		0x81C, 0x46D00001,
		0x81C, 0x45D20001,
		0x81C, 0x44D40001,
		0x81C, 0x43D60001,
		0x81C, 0x42D80001,
		0x81C, 0x08DA0001,
		0x81C, 0x07DC0001,
		0x81C, 0x06DE0001,
		0x81C, 0x05E00001,
		0x81C, 0x04E20001,
		0x81C, 0x03E40001,
		0x81C, 0x02E60001,
	0xFF0F07C0, 0xCDEF,
		0x81C, 0x47CE0001,
		0x81C, 0x46D00001,
		0x81C, 0x45D20001,
		0x81C, 0x44D40001,
		0x81C, 0x43D60001,
		0x81C, 0x42D80001,
		0x81C, 0x08DA0001,
		0x81C, 0x07DC0001,
		0x81C, 0x06DE0001,
		0x81C, 0x05E00001,
		0x81C, 0x04E20001,
		0x81C, 0x03E40001,
		0x81C, 0x02E60001,
	0xFF0F07D8, 0xCDEF,
		0x81C, 0x47CE0001,
		0x81C, 0x46D00001,
		0x81C, 0x45D20001,
		0x81C, 0x44D40001,
		0x81C, 0x43D60001,
		0x81C, 0x42D80001,
		0x81C, 0x08DA0001,
		0x81C, 0x07DC0001,
		0x81C, 0x06DE0001,
		0x81C, 0x05E00001,
		0x81C, 0x04E20001,
		0x81C, 0x03E40001,
		0x81C, 0x02E60001,
	0xCDCDCDCD, 0xCDCD,
		0x81C, 0x47D80001,
		0x81C, 0x46DA0001,
		0x81C, 0x45DC0001,
		0x81C, 0x44DE0001,
		0x81C, 0x43E00001,
		0x81C, 0x42E20001,
		0x81C, 0x08E40001,
		0x81C, 0x07E60001,
		0x81C, 0x06E80001,
		0x81C, 0x05EA0001,
		0x81C, 0x04EC0001,
		0x81C, 0x03EE0001,
		0x81C, 0x02F00001,
	0xFF0F0780, 0xDEAD,
};

u4Byte Array_MP_8812A_AGC_TAB_DIFF_HB[] = { 
	0xFF0F0780, 0xABCD,
		0x81C, 0x45CE0001,
		0x81C, 0x44D00001,
		0x81C, 0x43D20001,
		0x81C, 0x42D40001,
		0x81C, 0x08D60001,
		0x81C, 0x07D80001,
		0x81C, 0x06DA0001,
		0x81C, 0x05DC0001,
		0x81C, 0x04DE0001,
		0x81C, 0x03E00001,
		0x81C, 0x02E20001,
		0x81C, 0x01E40001,
		0x81C, 0x01E60001,
	0xFF0F07C0, 0xCDEF,
		0x81C, 0x45CE0001,
		0x81C, 0x44D00001,
		0x81C, 0x43D20001,
		0x81C, 0x42D40001,
		0x81C, 0x08D60001,
		0x81C, 0x07D80001,
		0x81C, 0x06DA0001,
		0x81C, 0x05DC0001,
		0x81C, 0x04DE0001,
		0x81C, 0x03E00001,
		0x81C, 0x02E20001,
		0x81C, 0x01E40001,
		0x81C, 0x01E60001,
	0xFF0F07D8, 0xCDEF,
		0x81C, 0x45CE0001,
		0x81C, 0x44D00001,
		0x81C, 0x43D20001,
		0x81C, 0x42D40001,
		0x81C, 0x08D60001,
		0x81C, 0x07D80001,
		0x81C, 0x06DA0001,
		0x81C, 0x05DC0001,
		0x81C, 0x04DE0001,
		0x81C, 0x03E00001,
		0x81C, 0x02E20001,
		0x81C, 0x01E40001,
		0x81C, 0x01E60001,
	0xCDCDCDCD, 0xCDCD,
		0x81C, 0x45D80001,
		0x81C, 0x44DA0001,
		0x81C, 0x43DC0001,
		0x81C, 0x42DE0001,
		0x81C, 0x08E00001,
		0x81C, 0x07E20001,
		0x81C, 0x06E40001,
		0x81C, 0x05E60001,
		0x81C, 0x04E80001,
		0x81C, 0x03EA0001,
		0x81C, 0x02EC0001,
		0x81C, 0x01EE0001,
		0x81C, 0x01F00001,
	0xFF0F0780, 0xDEAD,
};

void
ODM_ReadAndConfig_MP_8812A_AGC_TAB_DIFF(
 	IN   PDM_ODM_T  pDM_Odm,
 	IN   u4Byte  	Array[],
 	IN   u4Byte  	ArrayLen 
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  

	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8812A_AGC_TAB_DIFF, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		    odm_ConfigBB_AGC_8812A(pDM_Odm, v1, bMaskDWord, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		     		odm_ConfigBB_AGC_8812A(pDM_Odm, v1, bMaskDWord, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           PHY_REG.TXT
******************************************************************************/

u4Byte Array_MP_8812A_PHY_REG[] = { 
		0x800, 0x8020D010,
		0x804, 0x080112E0,
		0x808, 0x0E028233,
		0x80C, 0x12131113,
		0x810, 0x20101263,
		0x814, 0x020C3D10,
		0x818, 0x03A00385,
		0x820, 0x00000000,
		0x824, 0x00030FE0,
		0x828, 0x00000000,
		0x82C, 0x002083DD,
		0x830, 0x2AAA6C86,
		0x834, 0x0037A706,
		0x838, 0x06C89B44,
		0x83C, 0x0000095B,
		0x840, 0xC0000001,
		0x844, 0x40003CDE,
		0x848, 0x6210FF8B,
		0x84C, 0x6CFDFFB8,
		0x850, 0x28874706,
		0x854, 0x0001520C,
		0x858, 0x8060E000,
		0x85C, 0x74210168,
		0x860, 0x6929C321,
		0x864, 0x796A7432,
		0x868, 0x8CA7A314,
		0x86C, 0x338C2878,
		0x870, 0x03333333,
		0x874, 0x31602C2E,
		0x878, 0x00003152,
		0x87C, 0x000FC000,
		0x8A0, 0x00000013,
		0x8A4, 0x7F7F7F7F,
		0x8A8, 0xA202033E,
		0x8AC, 0x0FF0FA0A,
		0x8B0, 0x00000600,
		0x8B4, 0x000FC080,
		0x8B8, 0x7C0057FF,
		0x8BC, 0x4CA520A3,
		0x8C0, 0x27F00020,
		0x8C4, 0x00000000,
		0x8C8, 0x00013169,
		0x8CC, 0x08248492,
		0x8D0, 0x0000B800,
		0x8DC, 0x00000000,
		0x8D4, 0x940008A0,
		0x8D8, 0x290B1612,
		0x8F8, 0x400002C0,
		0x8FC, 0x00000000,
	0xFF0F07D8, 0xABCD,
		0x900, 0x00000701,
	0xCDCDCDCD, 0xCDCD,
		0x900, 0x00000700,
	0xFF0F07D8, 0xDEAD,
		0x90C, 0x00000000,
		0x910, 0x0000FC00,
		0x914, 0x00000404,
		0x918, 0x1C1028C0,
		0x91C, 0x64B11A1C,
		0x920, 0xE0767233,
		0x924, 0x055AA500,
		0x928, 0x00000004,
		0x92C, 0xFFFE0000,
		0x930, 0xFFFFFFFE,
		0x934, 0x001FFFFF,
		0x960, 0x00000000,
		0x964, 0x00000000,
		0x968, 0x00000000,
		0x96C, 0x00000000,
		0x970, 0x801FFFFF,
		0x978, 0x00000000,
		0x97C, 0x00000000,
		0x980, 0x00000000,
		0x984, 0x00000000,
		0x988, 0x00000000,
		0x9A4, 0x00080080,
		0x9A8, 0x00000000,
		0x9AC, 0x00000000,
		0x9B0, 0x01081008,
		0x9B4, 0x00000000,
		0x9B8, 0x01081008,
		0x9BC, 0x01081008,
		0x9D0, 0x00000000,
		0x9D4, 0x00000000,
		0x9D8, 0x00000000,
		0x9DC, 0x00000000,
		0x9E4, 0x00000002,
		0x9E8, 0x000002D4,
		0xA00, 0x00D047C8,
		0xA04, 0x01FF000C,
		0xA08, 0x8C8A8300,
		0xA0C, 0x2E7F000F,
		0xA10, 0x9500BB78,
		0xA14, 0x11144028,
		0xA18, 0x00881117,
		0xA1C, 0x89140F00,
		0xA20, 0x1A1B0000,
		0xA24, 0x090E1317,
		0xA28, 0x00000204,
		0xA2C, 0x00900000,
		0xA70, 0x101FFF00,
		0xA74, 0x00000008,
		0xA78, 0x00000900,
		0xA7C, 0x225B0606,
		0xA80, 0x218075B2,
		0xA84, 0x001F8C80,
		0xB00, 0x03100000,
		0xB04, 0x0000B000,
		0xB08, 0xAE0201EB,
		0xB0C, 0x01003207,
		0xB10, 0x00009807,
		0xB14, 0x01000000,
		0xB18, 0x00000002,
		0xB1C, 0x00000002,
		0xB20, 0x0000001F,
		0xB24, 0x03020100,
		0xB28, 0x07060504,
		0xB2C, 0x0B0A0908,
		0xB30, 0x0F0E0D0C,
		0xB34, 0x13121110,
		0xB38, 0x17161514,
		0xB3C, 0x0000003A,
		0xB40, 0x00000000,
		0xB44, 0x00000000,
		0xB48, 0x13000032,
		0xB4C, 0x48080000,
		0xB50, 0x00000000,
		0xB54, 0x00000000,
		0xB58, 0x00000000,
		0xB5C, 0x00000000,
		0xC00, 0x00000007,
		0xC04, 0x00042020,
		0xC08, 0x80410231,
		0xC0C, 0x00000000,
		0xC10, 0x00000100,
		0xC14, 0x01000000,
		0xC1C, 0x40000003,
		0xC20, 0x12121212,
		0xC24, 0x12121212,
		0xC28, 0x12121212,
		0xC2C, 0x12121212,
		0xC30, 0x12121212,
		0xC34, 0x12121212,
		0xC38, 0x12121212,
		0xC3C, 0x12121212,
		0xC40, 0x12121212,
		0xC44, 0x12121212,
		0xC48, 0x12121212,
		0xC4C, 0x12121212,
		0xC50, 0x00000020,
		0xC54, 0x0008121C,
		0xC58, 0x30000C1C,
		0xC5C, 0x00000058,
		0xC60, 0x34344443,
		0xC64, 0x07003333,
		0xC68, 0x59791979,
		0xC6C, 0x59795979,
		0xC70, 0x19795979,
		0xC74, 0x19795979,
		0xC78, 0x19791979,
		0xC7C, 0x19791979,
		0xC80, 0x19791979,
		0xC84, 0x19791979,
		0xC94, 0x0100005C,
		0xC98, 0x00000000,
		0xC9C, 0x00000000,
		0xCA0, 0x00000029,
		0xCA4, 0x08040201,
		0xCA8, 0x80402010,
	0xFF0F0740, 0xABCD,
		0xCB0, 0x77547717,
	0xFF0F07C0, 0xCDEF,
		0xCB0, 0x77547717,
	0xFF0F07D8, 0xCDEF,
		0xCB0, 0x54547710,
	0xCDCDCDCD, 0xCDCD,
		0xCB0, 0x77547777,
	0xFF0F0740, 0xDEAD,
		0xCB4, 0x00000077,
		0xCB8, 0x00508242,
		0xE00, 0x00000007,
		0xE04, 0x00042020,
		0xE08, 0x80410231,
		0xE0C, 0x00000000,
		0xE10, 0x00000100,
		0xE14, 0x01000000,
		0xE1C, 0x40000003,
		0xE20, 0x12121212,
		0xE24, 0x12121212,
		0xE28, 0x12121212,
		0xE2C, 0x12121212,
		0xE30, 0x12121212,
		0xE34, 0x12121212,
		0xE38, 0x12121212,
		0xE3C, 0x12121212,
		0xE40, 0x12121212,
		0xE44, 0x12121212,
		0xE48, 0x12121212,
		0xE4C, 0x12121212,
		0xE50, 0x00000020,
		0xE54, 0x0008121C,
		0xE58, 0x30000C1C,
		0xE5C, 0x00000058,
		0xE60, 0x34344443,
		0xE64, 0x07003333,
		0xE68, 0x59791979,
		0xE6C, 0x59795979,
		0xE70, 0x19795979,
		0xE74, 0x19795979,
		0xE78, 0x19791979,
		0xE7C, 0x19791979,
		0xE80, 0x19791979,
		0xE84, 0x19791979,
		0xE94, 0x0100005C,
		0xE98, 0x00000000,
		0xE9C, 0x00000000,
		0xEA0, 0x00000029,
		0xEA4, 0x08040201,
		0xEA8, 0x80402010,
	0xFF0F0740, 0xABCD,
		0xEB0, 0x77547717,
	0xFF0F07C0, 0xCDEF,
		0xEB0, 0x77547717,
	0xFF0F07D8, 0xCDEF,
		0xEB0, 0x54547710,
	0xCDCDCDCD, 0xCDCD,
		0xEB0, 0x77547777,
	0xFF0F0740, 0xDEAD,
		0xEB4, 0x00000077,
		0xEB8, 0x00508242,

};

void
ODM_ReadAndConfig_MP_8812A_PHY_REG(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8812A_PHY_REG)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8812A_PHY_REG;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8812A_PHY_REG, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		   	odm_ConfigBB_PHY_8812A(pDM_Odm, v1, bMaskDWord, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		   			odm_ConfigBB_PHY_8812A(pDM_Odm, v1, bMaskDWord, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           PHY_REG_MP.TXT
******************************************************************************/

u4Byte Array_MP_8812A_PHY_REG_MP[] = { 
		0x800, 0x8020D410,
		0x830, 0x2EAA8EB6,
		0xC90, 0x01E00000,

};

void
ODM_ReadAndConfig_MP_8812A_PHY_REG_MP(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8812A_PHY_REG_MP)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8812A_PHY_REG_MP;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8812A_PHY_REG_MP, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		   	odm_ConfigBB_PHY_8812A(pDM_Odm, v1, bMaskDWord, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		   			odm_ConfigBB_PHY_8812A(pDM_Odm, v1, bMaskDWord, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           PHY_REG_PG.TXT
******************************************************************************/

u4Byte Array_MP_8812A_PHY_REG_PG[] = { 
		0xC20, 0x00000000, 0x34363840,
		0xC24, 0x00000000, 0x42424444,
		0xC28, 0x00000000, 0x30323638,
		0xC2C, 0x00000000, 0x40424444,
		0xC30, 0x00000000, 0x28303236,
		0xC34, 0x00000000, 0x38404242,
		0xC38, 0x00000000, 0x26283034,
		0xE20, 0x00000000, 0x34363840,
		0xE24, 0x00000000, 0x42424444,
		0xE28, 0x00000000, 0x30323638,
		0xE2C, 0x00000000, 0x40424444,
		0xE30, 0x00000000, 0x28303236,
		0xE34, 0x00000000, 0x38404242,
		0xE38, 0x00000000, 0x26283034,
		0xC24, 0x00000000, 0x42424444,
		0xC28, 0x00000000, 0x30323640,
		0xC2C, 0x00000000, 0x40424444,
		0xC30, 0x00000000, 0x28303236,
		0xC34, 0x00000000, 0x38404242,
		0xC38, 0x00000000, 0x26283034,
		0xC3C, 0x00000000, 0x40424444,
		0xC40, 0x00000000, 0x28303236,
		0xC44, 0x00000000, 0x42422426,
		0xC48, 0x00000000, 0x30343840,
		0xC4C, 0x00000000, 0x22242628,
		0xE24, 0x00000000, 0x42424444,
		0xE28, 0x00000000, 0x30323640,
		0xE2C, 0x00000000, 0x40424444,
		0xE30, 0x00000000, 0x28303236,
		0xE34, 0x00000000, 0x38404242,
		0xE38, 0x00000000, 0x26283034,
		0xE3C, 0x00000000, 0x40424444,
		0xE40, 0x00000000, 0x28303236,
		0xE44, 0x00000000, 0x42422426,
		0xE48, 0x00000000, 0x30343840,
		0xE4C, 0x00000000, 0x22242628,

};

void
ODM_ReadAndConfig_MP_8812A_PHY_REG_PG(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	u4Byte     hex = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8812A_PHY_REG_PG)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8812A_PHY_REG_PG;

	pDM_Odm->PhyRegPgValueType = PHY_REG_PG_EXACT_VALUE;
	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	for (i = 0; i < ArrayLen; i += 3 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	    u4Byte v3 = Array[i+2];

	    // this line is a line of pure_body
	    if ( v1 < 0xCDCDCDCD )
	    {
		 	 odm_ConfigBB_PHY_REG_PG_8812A(pDM_Odm, v1, v2, v3);
		 	 continue;
	    }
	    else
	    { // this line is the start of branch
	        if ( !CheckCondition(Array[i], hex) )
	        { // don't need the hw_body
	            i += 2; // skip the pair of expression
	            v1 = Array[i];
	            v2 = Array[i+1];
	            v3 = Array[i+2];
	            while (v2 != 0xDEAD)
	            {
	                i += 3;
	                v1 = Array[i];
	                v2 = Array[i+1];
	                v3 = Array[i+1];
	            }
	        }
	    }
	}
}



/******************************************************************************
*                           PHY_REG_PG_ASUS.TXT
******************************************************************************/

u4Byte Array_MP_8812A_PHY_REG_PG_ASUS[] = { 
		0xC20, 0x00000000, 0x34343434,
		0xC24, 0x00000000, 0x32323232,
		0xC28, 0x00000000, 0x28303232,
		0xC2C, 0x00000000, 0x32323232,
		0xC30, 0x00000000, 0x24283032,
		0xC34, 0x00000000, 0x32323232,
		0xC38, 0x00000000, 0x24283032,
		0xE20, 0x00000000, 0x34343434,
		0xE24, 0x00000000, 0x32323232,
		0xE28, 0x00000000, 0x28303232,
		0xE2C, 0x00000000, 0x32323232,
		0xE30, 0x00000000, 0x24283032,
		0xE34, 0x00000000, 0x32323232,
		0xE38, 0x00000000, 0x24283032,
		0xC24, 0x00000000, 0x32323232,
		0xC28, 0x00000000, 0x28303232,
		0xC2C, 0x00000000, 0x32323232,
		0xC30, 0x00000000, 0x24283032,
		0xC34, 0x00000000, 0x32323232,
		0xC38, 0x00000000, 0x24283032,
		0xC3C, 0x00000000, 0x32323232,
		0xC40, 0x00000000, 0x24283032,
		0xC44, 0x00000000, 0x32322222,
		0xC48, 0x00000000, 0x30323232,
		0xC4C, 0x00000000, 0x22222428,
		0xE24, 0x00000000, 0x32323232,
		0xE28, 0x00000000, 0x28303232,
		0xE2C, 0x00000000, 0x32323232,
		0xE30, 0x00000000, 0x24283032,
		0xE34, 0x00000000, 0x32323232,
		0xE38, 0x00000000, 0x24283032,
		0xE3C, 0x00000000, 0x32323232,
		0xE40, 0x00000000, 0x24283032,
		0xE44, 0x00000000, 0x32322222,
		0xE48, 0x00000000, 0x30323232,
		0xE4C, 0x00000000, 0x22222428,

};

void
ODM_ReadAndConfig_MP_8812A_PHY_REG_PG_ASUS(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8812A_PHY_REG_PG_ASUS)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8812A_PHY_REG_PG_ASUS;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8812A_PHY_REG_PG_ASUS, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		   	odm_ConfigBB_PHY_8812A(pDM_Odm, v1, bMaskDWord, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		   			odm_ConfigBB_PHY_8812A(pDM_Odm, v1, bMaskDWord, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

/******************************************************************************
*                           PHY_REG_PG_NEC.TXT
******************************************************************************/

u4Byte Array_MP_8812A_PHY_REG_PG_NEC[] = { 
		0xC20, 0x00000000, 0x32323232,
		0xC24, 0x00000000, 0x32343434,
		0xC28, 0x00000000, 0x24262830,
		0xC2C, 0x00000000, 0x32343434,
		0xC30, 0x00000000, 0x24262830,
		0xC34, 0x00000000, 0x32343434,
		0xC38, 0x00000000, 0x24262830,
		0xE20, 0x00000000, 0x32323232,
		0xE24, 0x00000000, 0x32343434,
		0xE28, 0x00000000, 0x24262830,
		0xE2C, 0x00000000, 0x32343434,
		0xE30, 0x00000000, 0x24262830,
		0xE34, 0x00000000, 0x32343434,
		0xE38, 0x00000000, 0x24262830,
		0xC24, 0x00000000, 0x32343434,
		0xC28, 0x00000000, 0x24262830,
		0xC2C, 0x00000000, 0x32343434,
		0xC30, 0x00000000, 0x24262830,
		0xC34, 0x00000000, 0x28282828,
		0xC38, 0x00000000, 0x24262828,
		0xC3C, 0x00000000, 0x32343434,
		0xC40, 0x00000000, 0x24262830,
		0xC44, 0x00000000, 0x28282022,
		0xC48, 0x00000000, 0x28282828,
		0xC4C, 0x00000000, 0x20222426,
		0xE24, 0x00000000, 0x32343434,
		0xE28, 0x00000000, 0x24262830,
		0xE2C, 0x00000000, 0x32343434,
		0xE30, 0x00000000, 0x24262830,
		0xE34, 0x00000000, 0x28282828,
		0xE38, 0x00000000, 0x24262828,
		0xE3C, 0x00000000, 0x32343434,
		0xE40, 0x00000000, 0x24262830,
		0xE44, 0x00000000, 0x28282022,
		0xE48, 0x00000000, 0x28282828,
		0xE4C, 0x00000000, 0x20222426,

};

void
ODM_ReadAndConfig_MP_8812A_PHY_REG_PG_NEC(
 	IN   PDM_ODM_T  pDM_Odm
 	)
{
	#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = Array[i]; v2 = Array[i+1]; } while(0)

	u4Byte     hex         = 0;
	u4Byte     i           = 0;
	u2Byte     count       = 0;
	pu4Byte    ptr_array   = NULL;
	u1Byte     platform    = pDM_Odm->SupportPlatform;
	u1Byte     _interface   = pDM_Odm->SupportInterface;
	u1Byte     board       = pDM_Odm->BoardType;  
	u4Byte     ArrayLen    = sizeof(Array_MP_8812A_PHY_REG_PG_NEC)/sizeof(u4Byte);
	pu4Byte    Array       = Array_MP_8812A_PHY_REG_PG_NEC;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8812A_PHY_REG_PG_NEC, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2 )
	{
	    u4Byte v1 = Array[i];
	    u4Byte v2 = Array[i+1];
	
	    // This (offset, data) pair meets the condition.
	    if ( v1 < 0xCDCDCDCD )
	    {
		   	odm_ConfigBB_PHY_8812A(pDM_Odm, v1, bMaskDWord, v2);
		    continue;
	 	}
		else
		{ // This line is the start line of branch.
		    if ( !CheckCondition(Array[i], hex) )
		    { // Discard the following (offset, data) pairs.
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        i -= 2; // prevent from for-loop += 2
		    }
		    else // Configure matched pairs and skip to end of if-else.
		    {
		        READ_NEXT_PAIR(v1, v2, i);
		        while (v2 != 0xDEAD && 
		               v2 != 0xCDEF && 
		               v2 != 0xCDCD && i < ArrayLen -2)
		        {
		   			odm_ConfigBB_PHY_8812A(pDM_Odm, v1, bMaskDWord, v2);
		            READ_NEXT_PAIR(v1, v2, i);
		        }

		        while (v2 != 0xDEAD && i < ArrayLen -2)
		        {
		            READ_NEXT_PAIR(v1, v2, i);
		        }
		        
		    }
		}	
	}

}

#endif // end of HWIMG_SUPPORT

