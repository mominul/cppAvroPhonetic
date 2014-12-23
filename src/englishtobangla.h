/*
 * cppAvroPhonetic
 * englishtobangla.h
 *
 * C++ implementation of popular Bnagla writing method Avro Phonetic
 *
 * Copyright (C) OmicronLab (http://www.omicronlab.com)
 * Developer: Muhammad Mominul Huque
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

 //

/*
 *  Copyright (C) OmicronLab (http://www.omicronlab.com)
 *
 *  Developer: M M Rifat-Un-Nabi, Mehdi Hasan Khan
 *
 *  Listen us on http://www.twitter.com/omicronlab
 *  Support Forum: http://www.omicronlab.com/forum/
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.find_consonent_by_key
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


#ifndef __ENGLISHTOBANGLA_H_INCLUDED__
#define __ENGLISHTOBANGLA_H_INCLUDED__

//#include <scim.h>

//using namespace scim;


class cEnglishToBangla
{

private:
    String pEnglishText;
    int ln; //Length of English string
    int pos; //Position of processing at English string
    WideString Rs; //Result string
    bool AutoCorrect;


//Bangla Numbers
    WideString b_0;
    WideString b_1;
    WideString b_2;
    WideString b_3;
    WideString b_4;
    WideString b_5;
    WideString b_6;
    WideString b_7;
    WideString b_8;
    WideString b_9;
//Bangla Vowels and Kars
    WideString b_A;
    WideString b_AA;
    WideString b_AAkar;
    WideString b_I;
    WideString b_II;
    WideString b_IIkar;
    WideString b_Ikar;
    WideString b_U;
    WideString b_Ukar;
    WideString b_UU;
    WideString b_UUkar;
    WideString b_RRI;
    WideString b_RRIkar;
    WideString b_E;
    WideString b_Ekar;
    WideString b_O;
    WideString b_OI;
    WideString b_OIkar;
    WideString b_Okar;
    WideString b_OU;
    WideString b_OUkar;
//Bangla Consonents
    WideString b_Anushar;
    WideString b_B;
    WideString b_Bh;
    WideString b_Bisharga;
    WideString b_C;
    WideString b_CH;
    WideString b_Chandra;
    WideString b_D;
    WideString b_Dd;
    WideString b_Ddh;
    WideString b_Dh;
    WideString b_G;
    WideString b_GH;
    WideString b_H;
    WideString b_J;
    WideString b_JH;
    WideString b_K;
    WideString b_KH;
    WideString b_L;
    WideString b_M;
    WideString b_N;
    WideString b_NGA;
    WideString b_Nn;
    WideString b_NYA;
    WideString b_P;
    WideString b_Ph;
    WideString b_R;
    WideString b_Rr;
    WideString b_Rrh;
    WideString b_S;
    WideString b_Sh;
    WideString b_Ss;
    WideString b_T;
    WideString b_Th;
    WideString b_Tt;
    WideString b_Tth;
    WideString b_Y;
    WideString b_Z;
    WideString AssamRa;
    WideString AssamVa;
    WideString b_Khandatta;
//Bangla Others
    WideString b_Dari;
    WideString b_Hasanta;
    WideString b_Taka;
    WideString ZWJ;
    WideString ZWNJ;
    WideString b_Nukta;


// Functions...
    void		InitVars		();// Initialize Bangla character variables
    void		CutText		(String inputEStr, String &outSIgnore, String &outMidMain, String &outEIgnore);
    WideString  	MyConvert		();
    void 		Dot			();
    void 		smallO			();
    void 		O			();
    String 		CorrectCase		(String inputT);
    void 		h			();
    void 		s			();
    void 		l			();
    void 		R			();
    void 		m			();
    void 		b			();
    void 		p			();
    void 		d			();
    void 		T			();
    void 		J			();
    void 		c			();
    void 		n			();
    void 		k			();
    void 		g			();
    bool 		Cnv			(String Compare, WideString IfTrue);
    void 		AddRs			(WideString T);
    void 		AddRsEx			(WideString T, int p);
    String 		PrevT			();
    String 		PrevTEx		(int Position);
    String 		NextT			();
    String 		NextTEx		(int Length, int skipstart);
    bool 		Vowel			(String T);
    bool 		Consonent		(String T);
    bool 		Begining		();


public:
    cEnglishToBangla	(); //constructor
    WideString 	Convert		(const String EnglishT);
};

#endif /* __ENGLISHTOBANGLA_H_INCLUDED__ */
