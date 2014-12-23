/*
 * cppAvroPhonetic
 * englishtobangla.cpp
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


//#include <scim.h>
#include "englishtobangla.h"



////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
////////////                                       ////////////
////////////          Public Functions             ////////////
////////////                                       ////////////
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////




cEnglishToBangla::cEnglishToBangla()
{
    InitVars();
    AutoCorrect = false;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



WideString
cEnglishToBangla::Convert (const String EnglishT)
{
    WideString tempConvert ;

    String EngStr = "";

    String Starting_Ignoreable_T = "";
    String Middle_Main_T = "";
    String Ending_Ignorable_T = "";

    EngStr = CorrectCase(EnglishT);

    /*
    if (AutoCorrect == true)
    	{
    		if (Dict::Exist(EngStr) == true)
    		{
    			pEnglishText = Dict[EngStr];
    			tempConvert = MyConvert;
    		}
    		else
    		{
    			//Whole word not found in the dictionary, lets try ignoring punctuations

    			CutText EngStr, Starting_Ignoreable_T, Middle_Main_T, Ending_Ignorable_T;

    			if (Dict::Exist(Middle_Main_T) == true)
    			{

    std::string tempStr = "";

    				if (Starting_Ignoreable_T != "")
    				{
    					pEnglishText = Starting_Ignoreable_T;
    					tempStr = MyConvert;
    				}

    				if (Middle_Main_T != "")
    				{
    					pEnglishText = Dict[Middle_Main_T];
    					tempStr = tempStr + MyConvert;
    				}

    				if (Ending_Ignorable_T != "")
    				{
    					pEnglishText = Ending_Ignorable_T;
    					tempStr = tempStr + MyConvert;
    				}

    				tempConvert = tempStr;

    			}
    			else //Autocorrect enabled but word not found even after ignoring punctuations
    			{
    				pEnglishText = EngStr;
    				tempConvert = MyConvert;
    			}
    		}
    	}
    	else
    	{
    		pEnglishText = EngStr;
    		tempConvert = MyConvert;
    	}
    */


    /* FIXME:  Eliminate the following two lines and uncomment above when autocorrect is implemented */
    pEnglishText = EngStr;
    tempConvert = MyConvert();

    return tempConvert;

}



////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
////////////                                       ////////////
////////////          Private Functions            ////////////
////////////                                       ////////////
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


void
cEnglishToBangla::InitVars()
{
//Bangla Numbers
    b_0=ucs4_t(0x9E6);
    b_1=ucs4_t(0x9E7);
    b_2=ucs4_t(0x9E8);
    b_3=ucs4_t(0x9E9);
    b_4=ucs4_t(0x9EA);
    b_5=ucs4_t(0x9EB);
    b_6=ucs4_t(0x9EC);
    b_7=ucs4_t(0x9ED);
    b_8=ucs4_t(0x9EE);
    b_9=ucs4_t(0x9EF);
//Bangla Vowels and Kars
    b_A=ucs4_t(0x985);
    b_AA=ucs4_t(0x986);
    b_AAkar=ucs4_t(0x9BE);
    b_I=ucs4_t(0x987);
    b_II=ucs4_t(0x988);
    b_IIkar=ucs4_t(0x9C0);
    b_Ikar=ucs4_t(0x9BF);
    b_U=ucs4_t(0x989);
    b_Ukar=ucs4_t(0x9C1);
    b_UU=ucs4_t(0x98A);
    b_UUkar=ucs4_t(0x9C2);
    b_RRI=ucs4_t(0x98B);
    b_RRIkar=ucs4_t(0x9C3);
    b_E=ucs4_t(0x98F);
    b_Ekar=ucs4_t(0x9C7);
    b_O=ucs4_t(0x993);
    b_OI=ucs4_t(0x990);
    b_OIkar=ucs4_t(0x9C8);
    b_Okar=ucs4_t(0x9CB);
    b_OU=ucs4_t(0x994);
    b_OUkar=ucs4_t(0x9CC);
//Bangla Consonents
    b_Anushar=ucs4_t(0x982);
    b_B=ucs4_t(0x9AC);
    b_Bh=ucs4_t(0x9AD);
    b_Bisharga=ucs4_t(0x983);
    b_C=ucs4_t(0x99A);
    b_CH=ucs4_t(0x99B);
    b_Chandra=ucs4_t(0x981);
    b_D=ucs4_t(0x9A6);
    b_Dd=ucs4_t(0x9A1);
    b_Ddh=ucs4_t(0x9A2);
    b_Dh=ucs4_t(0x9A7);
    b_G=ucs4_t(0x997);
    b_GH=ucs4_t(0x998);
    b_H=ucs4_t(0x9B9);
    b_J=ucs4_t(0x99C);
    b_JH=ucs4_t(0x99D);
    b_K=ucs4_t(0x995);
    b_KH=ucs4_t(0x996);
    b_L=ucs4_t(0x9B2);
    b_M=ucs4_t(0x9AE);
    b_N=ucs4_t(0x9A8);
    b_NGA=ucs4_t(0x999);
    b_Nn=ucs4_t(0x9A3);
    b_NYA=ucs4_t(0x99E);
    b_P=ucs4_t(0x9AA);
    b_Ph=ucs4_t(0x9AB);
    b_R=ucs4_t(0x9B0);
    b_Rr=ucs4_t(0x9DC);
    b_Rrh=ucs4_t(0x9DD);
    b_S=ucs4_t(0x9B8);
    b_Sh=ucs4_t(0x9B6);
    b_Ss=ucs4_t(0x9B7);
    b_T=ucs4_t(0x9A4);
    b_Th=ucs4_t(0x9A5);
    b_Tt=ucs4_t(0x99F);
    b_Tth=ucs4_t(0x9A0);
    b_Y=ucs4_t(0x9DF);
    b_Z=ucs4_t(0x9AF);
    AssamRa=ucs4_t(0x9F0);
    AssamVa=ucs4_t(0x9F1);
    b_Khandatta=ucs4_t(0x9CE);
//Bangla Others
    b_Dari=ucs4_t(0x964);
    b_Hasanta=ucs4_t(0x9CD);
    b_Taka=ucs4_t(0x9F3);
    ZWJ=ucs4_t(0x200D);
    ZWNJ=ucs4_t(0x200C);
    b_Nukta=ucs4_t(0x9BC);
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::CutText (String inputEStr, String &outSIgnore, String &outMidMain, String &outEIgnore)
{
    int i = 0;
    int p = 0;
    int q = 0;
    int EStrLen = 0;
    String tStr = "";

    EStrLen = inputEStr.length();

    //Start Cutting outSIgnore
    for (i = 1; i <= EStrLen; i++)
    {
        tStr = inputEStr.substr(i - 1, 1);

        if ((tStr == "~") || (tStr == "!") || (tStr == "@") || (tStr == "#") || (tStr == "%") || (tStr == "&") || (tStr == "*") || (tStr == "(") || (tStr == ")") || (tStr == "-") || (tStr == "_") || (tStr == "=") || (tStr == "+") || (tStr == "[") || (tStr == "]") || (tStr == "{") || (tStr == "}") || (tStr == "'") || (tStr == "\"") || (tStr == ";") || (tStr == "<") || (tStr == ">") || (tStr == "/") || (tStr == "?") || (tStr == "|") || (tStr == "\\") || (tStr == "."))
        {
            p = i;
        }
        else if (tStr == ",")
        {
            if (inputEStr.substr(i, 1) == ",")
            {
                goto ExitLabel1;
            }
            else
            {
                p = i;
            }
        }
        else if (tStr == ":")
        {
            if (inputEStr.substr(i, 1) == "`")
            {
                p = i;
            }
            else
            {
                goto ExitLabel1;
            }
        }
        else if (tStr == "`")
        {
            if (i - 1 >= 1)
            {
                if (inputEStr.substr(i - 2, 1) == "." || inputEStr.substr(i - 2, 1) == ":")
                {
                    p = i;
                }
                else
                {
                    goto ExitLabel1;
                }
            }
            else
            {
                goto ExitLabel1;
            }
        }
        else
        {
            goto ExitLabel1;
        }
    }
    /* FIXME: Eliminate goto */
ExitLabel1:

    outSIgnore = inputEStr.substr(0, p);
    //End Cutting outSIgnore

    //Start Cutting outEIgnore
    String reverse_inputEStr = inputEStr;

    std::reverse(reverse_inputEStr.begin(),reverse_inputEStr.end());


    for (i = 1; i <= EStrLen - p; i++)
    {
        tStr = reverse_inputEStr.substr(i - 1, 1);
        if ((tStr == "~") || (tStr == "!") || (tStr == "@") || (tStr == "#") || (tStr == "%") || (tStr == "&") || (tStr == "*") || (tStr == "(") || (tStr == ")") || (tStr == "-") || (tStr == "_") || (tStr == "=") || (tStr == "+") || (tStr == "[") || (tStr == "]") || (tStr == "{") || (tStr == "}") || (tStr == "'") || (tStr == "\"") || (tStr == ";") || (tStr == "<") || (tStr == ">") || (tStr == "/") || (tStr == ".") || (tStr == "?") || (tStr == "|") || (tStr == "\\"))
        {
            q = i;
        }
        else if (tStr == ",")
        {
            if (reverse_inputEStr.substr(i, 1) == ",")
            {
                goto ExitLabel2;
            }
            else
            {
                q = i;
            }
        }
        else if (tStr == "`")
        {
            if (reverse_inputEStr.substr(i, 1) == ":" || reverse_inputEStr.substr(i, 1) == ".")
            {
                q = i;
            }
            else
            {
                goto ExitLabel2;
            }
        }
        else if (tStr == ":")
        {
            if (i - 1 >= 1)
            {
                if (reverse_inputEStr.substr(i - 2, 1) == "`")
                {
                    q = i;
                }
                else
                {
                    goto ExitLabel2;
                }
            }
            else
            {
                goto ExitLabel2;
            }
        }
        else
        {
            goto ExitLabel2;
        }
    }
    /* FIXME: Eliminate goto */
ExitLabel2:
    outEIgnore = inputEStr.substr(inputEStr.length() - q);
    //End Cutting outEIgnore

    //Start Cutting outMidMain
    tStr = inputEStr.substr(p);
    tStr = tStr.substr(0, tStr.length() - q);
    outMidMain = tStr;
    //End Cutting outMidMain


}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


WideString
cEnglishToBangla::MyConvert()
{
    String tt = ""; //Temporary string

    ln = pEnglishText.length();
    pos = 1;
    Rs = utf8_mbstowcs(String(""));

    do
    {
        tt = pEnglishText.substr(pos - 1, 1);


        //--------START Number Generation---------------
        //1st, we'll convert numbers. Hassel free :)
        if (tt == "0")
        {
            AddRs (b_0);
        }
        else if (tt == "1")
        {
            AddRs (b_1);
        }
        else if (tt == "2")
        {
            AddRs (b_2);
        }
        else if (tt == "3")
        {
            AddRs (b_3);
        }
        else if (tt == "4")
        {
            AddRs (b_4);
        }
        else if (tt == "5")
        {
            AddRs (b_5);
        }
        else if (tt == "6")
        {
            AddRs (b_6);
        }
        else if (tt == "7")
        {
            AddRs (b_7);
        }
        else if (tt == "8")
        {
            AddRs (b_8);
        }
        else if (tt == "9")
        {
            AddRs (b_9);
            //------------End Number Generation-------------

            //--------START Vowel Generation---------------
            //2nd, we'll convert Vowels.Comperatively easy
        }
        else if (tt == "o") //Lower case O, it will be shore o
        {
            smallO();

        }
	else if (tt=="A")
	{
	    AddRs (b_AA); //Force AA
	}
        else if (tt == "a")
        {
            if (NextT() == "Z")
            {
                AddRsEx (b_A + b_Hasanta + b_Z + b_AAkar, 2);
            }
            else if ((Begining() == true) && (NextT() != "`"))
            {
                AddRs (b_AA);
            }
            else if ((Consonent(PrevT()) == false) && (PrevT() != "a") && (NextT() != "`"))
            {
                AddRs (b_Y + b_AAkar);
            }
            else if (NextT() == "`")
            {
                AddRsEx (b_AAkar, 2);
            }
            else if ((PrevT() == "a") && (NextT() != "`"))
            {
                AddRs (b_AA);
            }
            else
            {
                AddRs (b_AAkar);
            }

        }
        else if (tt == "i")
        {
            if (((Consonent(PrevT()) == false) || (Begining() == true)) && (NextT() != "`"))
            {
                AddRs (b_I);
            }
            else if (NextT() == "`")
            {
                AddRsEx (b_Ikar, 2);
            }
            else
            {
                AddRs (b_Ikar);
            }

        }
        else if (tt == "I")
        {
            if (((Consonent(PrevT()) == false) || (Begining() == true)) && (NextT() != "`"))
            {
                AddRs (b_II);
            }
            else if (NextT() == "`")
            {
                AddRsEx (b_IIkar, 2);
            }
            else
            {
                AddRs (b_IIkar);
            }

        }
        else if (tt == "u")
        {
            if (((Consonent(PrevT()) == false) || (Begining() == true)) && (NextT() != "`"))
            {
                AddRs (b_U);
            }
            else if (NextT() == "`")
            {
                AddRsEx (b_Ukar, 2);
            }
            else
            {
                AddRs (b_Ukar);
            }

        }
        else if (tt == "U")
        {
            if (((Consonent(PrevT()) == false) || (Begining() == true)) && (NextT() != "`"))
            {
                AddRs (b_UU);
            }
            else if (NextT() == "`")
            {
                AddRsEx (b_UUkar, 2);
            }
            else
            {
                AddRs (b_UUkar);
            }
            //We'll process ra, Ra,Rha, rri, rrikar, ra fola, reph later

        }

        else if ((tt == "e") || (tt == "E"))
        {
            if (((Consonent(PrevT()) == false) || (Begining() == true)) && (NextT() != "`"))
            {
                if (NextT() == "e")
                {
                    AddRsEx (b_II, 2);
                }
                else
                {
                    AddRs (b_E);
                }
            }
            else if (NextT() == "`")
            {
                AddRsEx (b_Ekar, 2);
            }
            else
            {
                if (NextT() == "e")
                {
                    AddRsEx (b_IIkar, 2);
                }
                else
                {
                    AddRs (b_Ekar);
                }
            }


        }
        else if (tt == "O") //Capital O
        {
            O();
        }
        //-----------------End Vowel Generation---------------

        //-----------------START Consonent Generation---------------
        //K
        else if (tt == "k")
        {
            k();
        }
        //G
        else if ((tt == "G") || (tt == "g"))
        {
            g();
        }
        //N
        else if ((tt == "N") || (tt == "n"))
        {
            n();
        }
        //C
        else if (tt == "c")
        {
            c();
        }
        //J
        else if ((tt == "J") || (tt == "j"))
        {
            J();
        }
        //T
        else if ((tt == "T") || (tt == "t"))
        {
            T();
        }
        //D
        else if ((tt == "D") || (tt == "d"))
        {
            d();
        }
        //P
        else if ((tt == "p") || (tt == "f"))
        {
            p();
        }
        //B
        else if ((tt == "b") || (tt == "v"))
        {
            b();
        }
        //M
        else if (tt == "m")
        {
            m();
        }
        //Z
        else if (tt == "z")
        {
            AddRs (b_Z);

        }
        else if (tt == "Z")
        {
            if (PrevT() == "r")
            {
                if ((Consonent(PrevTEx(2))) && (PrevTEx(2) != "r") && (PrevTEx(2) != "y") && (PrevTEx(2) != "w") && (PrevTEx(2) != "x"))
                {
                    //Previous character is R-Fola, don't add ZWJ
                    AddRs (b_Hasanta + b_Z);
                }
                else
                {
                    AddRs (ZWJ + b_Hasanta + b_Z); // RAM, RAB : In Windows, we've to use ZWNJ
                }
            }
            else
            {
                AddRs (b_Hasanta + b_Z);
            }
        }
        //R
        else if ((tt == "R") || (tt == "r"))
        {
            R();
        }
        //L
        else if (tt == "l")
        {
            l();
        }
        //S
        else if ((tt == "S") || (tt == "s"))
        {
            s();
        }
        //H
        else if (tt == "h")
        {
            h();
        }
        //y
        else if (tt == "y")
        {
            if ((Consonent(PrevT()) == false) && (Begining() != true))
            {
                AddRs (b_Y);
            }
            else if (Begining() == true)
            {
                AddRs (b_I + b_Y);
            }
            else
            {
                if (PrevT() == "r")
                {
                    if ((Consonent(PrevTEx(2))) && (PrevTEx(2) != "r") && (PrevTEx(2) != "y") && (PrevTEx(2) != "w") && (PrevTEx(2) != "x"))
                    {
                        //Previous character is R-Fola, don't add ZWJ
                        AddRs (b_Hasanta + b_Z);
                    }
                    else
                    {
                        AddRs (ZWJ + b_Hasanta + b_Z); // RAM, RAB : In Windows, we've to use ZWNJ
                    }
                }
                else
                {
                    AddRs (b_Hasanta + b_Z);
                }
            }
        }
        //Y
        else if (tt == "Y")
        {
            AddRs (b_Y); //Force Y
        }
        //W
        else if (tt == "w")
        {
            if ((Begining() == true) && (Vowel(NextT()) == true))
            {
                AddRs (b_O + b_Y);
            }
            else if (Consonent(PrevT()) == true)
            {
                AddRs (b_Hasanta + b_B);
            }
            else
            {
                AddRs (b_O);
            }
        }
        //Q
        else if (tt == "q")
        {
            AddRs (b_K);
        }
        //x
        else if (tt == "x")
        {
            if (Begining() == true)
            {
                AddRs (b_E + b_K + b_Hasanta + b_S);
            }
            else
            {
                AddRs (b_K + b_Hasanta + b_S);
            }
        }
        //-----------------End Consonent Generation---------------

        //-----------------Start Symbol Generation---------------
        else if (tt == ".")
        {
            Dot();

        }
        else if (tt == ":")
        {
            if (NextT() != "`")
            {
                AddRs (b_Bisharga);
            }
            else
            {
                AddRsEx (utf8_mbstowcs(String(":")), 2);
            }

        }
        else if (tt == "^")
        {
            if (NextT() != "`")
            {
                AddRs (b_Chandra);
            }
            else
            {
                AddRsEx (utf8_mbstowcs(String("^")), 2);
            }

        }
        else if (tt == ",")
        {
            if (NextT() == ",")
            {
                AddRsEx (b_Hasanta + ZWNJ, 2);
            }
            else
            {
                AddRs (utf8_mbstowcs(String(",")));
            }

        }
        else if (tt == "$")
        {
            AddRs (b_Taka);
        }
        //-----------------End Symbol Generation---------------

        //` - Make sure it is just above case else!
        else if (tt == "`")
        {
            pos = pos + 1; //No change made here,just to bypass juktakkhar making
        }
        else
        {
            AddRs (utf8_mbstowcs(tt));

        }
    }
    while (pos <= ln);

    return Rs;

}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::Dot()
{
    if (Cnv("...", utf8_mbstowcs(String("..."))) == true) //...
    {
        return;
    }

    if (Cnv(".`", utf8_mbstowcs(String("."))) == true) //.
    {
        return;
    }
    if (Cnv("..", b_Dari + b_Dari) == true) //||
    {
        return;
    }

    if (Cnv(".", b_Dari) == true) //|
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::smallO()
{
    if (((Consonent(PrevT()) == false) || (Begining() == true)) && (NextT() != "`"))
    {
        if (Cnv("oo", b_U) == true) //U
        {
            return;
        }
        if (Cnv("oZ", b_A + b_Hasanta + b_Z) == true) //U
        {
            return;
        }

        if ((Vowel(PrevT()) == true) && (PrevT() != "o"))
        {
            if (Cnv("o", b_O) == true) //O
            {
                return;
            }
        }
        else
        {
            if (Cnv("o", b_A) == true) //A
            {
                return;
            }
        }
    }

    if (Cnv("oo", b_Ukar) == true) //U Kar
    {
        return;
    }
    if (Cnv("o`", utf8_mbstowcs(String(""))) == true) //Nothing
    {
        return;
    }
    if (Cnv("o", utf8_mbstowcs(String(""))) == true) //Nothing
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::O()
{
    if (Cnv("OI`", b_OIkar) == true) //OIKar
    {
        return;
    }
    if (Cnv("OU`", b_OUkar) == true) //OUKar
    {
        return;
    }

    if (Cnv("O`", b_Okar) == true) //OKar
    {
        return;
    }

    if ((Consonent(PrevT()) == false) || (Begining() == true))
    {
        if (Cnv("OI", b_OI) == true) //OI
        {
            return;
        }
        if (Cnv("OU", b_OU) == true) //OU
        {
            return;
        }
        if (Cnv("O", b_O) == true) //O
        {
            return;
        }
    }
    else
    {
        if (Cnv("OI", b_OIkar) == true) //OIKar
        {
            return;
        }
        if (Cnv("OU", b_OUkar) == true) //OUKar
        {
            return;
        }
        if (Cnv("O", b_Okar) == true) //OKar
        {
            return;
        }
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



String
cEnglishToBangla::CorrectCase (String inputT)
{
    int i = 0;
    String s = "";
    int l = 0;
    String T = "";

    l = inputT.length();

    for (i = 1; i <= l; i++)
    {
        T = inputT.substr(i - 1, 1);
        if ((T == "a") || (T == "A") || (T == "o") || (T == "O") || (T == "i") || (T == "I") || (T == "u") || (T == "U"))
        {
            s = s + T;
        }
        else if ((T == "d") || (T == "D") || (T == "g") || (T == "G") || (T == "j") || (T == "J") || (T == "n") || (T == "N") || (T == "r") || (T == "R") || (T == "s") || (T == "S") || (T == "t") || (T == "T") || (T == "y") || (T == "Y") || (T == "z") || (T == "Z"))
        {
            s = s + T;
        }
        else
        {
            std::transform (T.begin(), T.end(), T.begin(), tolower);
            s = s + T;
        }
    }

    return s;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::h()
{
    if (Cnv("hN", b_H + b_Hasanta + b_Nn) == true) //H+Nn
    {
        return;
    }
    if (Cnv("hn", b_H + b_Hasanta + b_N) == true) //H+N
    {
        return;
    }
    if (Cnv("hm", b_H + b_Hasanta + b_M) == true) //H+m
    {
        return;
    }
    if (Cnv("hl", b_H + b_Hasanta + b_L) == true) //H+L
    {
        return;
    }

    if (Cnv("h", b_H) == true) //H
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::s()
{
    if (Cnv("shch", b_Sh + b_Hasanta + b_CH) == true) //Sh+Chh
    {
        return;
    }
    if (Cnv("ShTh", b_Ss + b_Hasanta + b_Tth) == true) //Sh+Tth
    {
        return;
    }
    if (Cnv("Shph", b_Ss + b_Hasanta + b_Ph) == true) //Sh+Ph
    {
        return;
    }

    if (Cnv("Sch", b_Sh + b_Hasanta + b_CH) == true) //Sh+Chh
    {
        return;
    }
    if (Cnv("skl", b_S + b_Hasanta + b_K + b_Hasanta + b_L) == true) //S+K+L
    {
        return;
    }
    if (Cnv("skh", b_S + b_Hasanta + b_KH) == true) //S+Kh
    {
        return;
    }
    if (Cnv("sth", b_S + b_Hasanta + b_Th) == true) //S+Th
    {
        return;
    }
    if (Cnv("sph", b_S + b_Hasanta + b_Ph) == true) //S+Ph
    {
        return;
    }
    if (Cnv("shc", b_Sh + b_Hasanta + b_C) == true) //Sh+C
    {
        return;
    }
    if (Cnv("sht", b_Sh + b_Hasanta + b_T) == true) //Sh+T
    {
        return;
    }
    if (Cnv("shn", b_Sh + b_Hasanta + b_N) == true) //Sh+N
    {
        return;
    }
    if (Cnv("shm", b_Sh + b_Hasanta + b_M) == true) //Sh+M
    {
        return;
    }
    if (Cnv("shl", b_Sh + b_Hasanta + b_L) == true) //Sh+L
    {
        return;
    }
    if (Cnv("Shk", b_Ss + b_Hasanta + b_K) == true) //Sh+K
    {
        return;
    }
    if (Cnv("ShT", b_Ss + b_Hasanta + b_Tt) == true) //Sh+Tt
    {
        return;
    }
    if (Cnv("ShN", b_Ss + b_Hasanta + b_Nn) == true) //Sh+Nn
    {
        return;
    }
    if (Cnv("Shp", b_Ss + b_Hasanta + b_P) == true) //Sh+P
    {
        return;
    }
    if (Cnv("Shf", b_Ss + b_Hasanta + b_Ph) == true) //Sh+Ph
    {
        return;
    }
    if (Cnv("Shm", b_Ss + b_Hasanta + b_M) == true) //Sh+M
    {
        return;
    }

    if (Cnv("sk", b_S + b_Hasanta + b_K) == true) //S+K
    {
        return;
    }
    if (Cnv("Sc", b_Sh + b_Hasanta + b_C) == true) //Sh+Ch
    {
        return;
    }
    if (Cnv("sT", b_S + b_Hasanta + b_Tt) == true) //S+Tt
    {
        return;
    }
    if (Cnv("st", b_S + b_Hasanta + b_T) == true) //S+T
    {
        return;
    }
    if (Cnv("sn", b_S + b_Hasanta + b_N) == true) //S+N
    {
        return;
    }
    if (Cnv("sp", b_S + b_Hasanta + b_P) == true) //S+P
    {
        return;
    }
    if (Cnv("sf", b_S + b_Hasanta + b_Ph) == true) //S+Ph
    {
        return;
    }
    if (Cnv("sm", b_S + b_Hasanta + b_M) == true) //S+M
    {
        return;
    }
    if (Cnv("sl", b_S + b_Hasanta + b_L) == true) //S+L
    {
        return;
    }
    if (Cnv("sh", b_Sh) == true) //Sh
    {
        return;
    }
    if (Cnv("Sc", b_Sh + b_Hasanta + b_C) == true) //Sh+Ch
    {
        return;
    }
    if (Cnv("St", b_Sh + b_Hasanta + b_T) == true) //Sh+T
    {
        return;
    }
    if (Cnv("Sn", b_Sh + b_Hasanta + b_N) == true) //Sh+N
    {
        return;
    }
    if (Cnv("Sm", b_Sh + b_Hasanta + b_M) == true) //Sh+M
    {
        return;
    }
    if (Cnv("Sl", b_Sh + b_Hasanta + b_L) == true) //Sh+L
    {
        return;
    }
    if (Cnv("Sh", b_Ss) == true) //Sh
    {
        return;
    }

    if (Cnv("s", b_S) == true) //S
    {
        return;
    }
    if (Cnv("S", b_Sh) == true) //Sh
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::l()
{
    if (Cnv("lbh", b_L + b_Hasanta + b_Bh) == true) //L+Bh
    {
        return;
    }
    if (Cnv("ldh", b_L + b_Hasanta + b_Dh) == true) //L+Dh
    {
        return;
    }

    if (Cnv("lkh", b_L + b_KH) == true) //L & Kk
    {
        return;
    }
    if (Cnv("lgh", b_L + b_GH) == true) //L & Gh
    {
        return;
    }
    if (Cnv("lph", b_L + b_Ph) == true) //L & Ph
    {
        return;
    }

    if (Cnv("lk", b_L + b_Hasanta + b_K) == true) //L+K
    {
        return;
    }
    if (Cnv("lg", b_L + b_Hasanta + b_G) == true) //L+G
    {
        return;
    }
    if (Cnv("lT", b_L + b_Hasanta + b_Tt) == true) //L+T
    {
        return;
    }
    if (Cnv("lD", b_L + b_Hasanta + b_Dd) == true) //L+Dd
    {
        return;
    }
    if (Cnv("lp", b_L + b_Hasanta + b_P) == true) //L+P
    {
        return;
    }
    if (Cnv("lv", b_L + b_Hasanta + b_Bh) == true) //L+Bh
    {
        return;
    }
    if (Cnv("lm", b_L + b_Hasanta + b_M) == true) //L+M
    {
        return;
    }
    if (Cnv("ll", b_L + b_Hasanta + b_L) == true) //L+L
    {
        return;
    }
    if (Cnv("lb", b_L + b_Hasanta + b_B) == true) //L+B
    {
        return;
    }

    if (Cnv("l", b_L) == true) //L
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::R()
{
    if (NextTEx(1, 2) == "`")
    {
        if (Cnv("rri", b_RRIkar) == true) //RRI-Kar
        {
            return;
        }
    }

    if (Consonent(PrevT()) == false)
    {
        if (Cnv("rri", b_RRI) == true) //RRI
        {
            return;
        }
    }
    else if (Begining() == true)
    {
        if (Cnv("rri", b_RRI) == true) //RRI
        {
            return;
        }
    }
    else
    {
        if (Cnv("rri", b_RRIkar) == true) //RRI-Kar
        {
            return;
        }
    }

    if (Consonent(PrevT()) == false && Vowel(NextTEx(1, 1)) == false && NextTEx(1, 1) != "r" & NextTEx(1, 1) != "")
    {
        if (Cnv("rr", b_R + b_Hasanta) == true) //Reph
        {
            return;
        }
    }

    if (Cnv("Rg", b_Rr + b_Hasanta + b_G) == true) //Rh+G
    {
        return;
    }
    if (Cnv("Rh", b_Rrh) == true) //Rrh
    {
        return;
    }

    if ((Consonent(PrevT()) == true) && (PrevT() != "r") && (PrevT() != "y") && (PrevT() != "w") && (PrevT() != "x") && (PrevT() != "Z"))
    {
        if (Cnv("r", b_Hasanta + b_R) == true) //R-Fola
        {
            return;
        }
    }
    else
    {
        if (Cnv("r", b_R) == true) //R
        {
            return;
        }
    }

    if (Cnv("R", b_Rr) == true) //Rh
    {
        return;
    }
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::m()
{
    if (Cnv("mth", b_M + b_Hasanta + b_Th) == true) //M+Th
    {
        return;
    }
    if (Cnv("mph", b_M + b_Hasanta + b_Ph) == true) //M+Ph
    {
        return;
    }
    if (Cnv("mbh", b_M + b_Hasanta + b_Bh) == true) //M+V
    {
        return;
    }

    if (Cnv("mn", b_M + b_Hasanta + b_N) == true) //M+N
    {
        return;
    }
    if (Cnv("mp", b_M + b_Hasanta + b_P) == true) //M+P
    {
        return;
    }
    if (Cnv("mv", b_M + b_Hasanta + b_Bh) == true) //M+V
    {
        return;
    }
    if (Cnv("mm", b_M + b_Hasanta + b_M) == true) //M+M
    {
        return;
    }
    if (Cnv("ml", b_M + b_Hasanta + b_L) == true) //M+L
    {
        return;
    }
    if (Cnv("mb", b_M + b_Hasanta + b_B) == true) //M+B
    {
        return;
    }
    if (Cnv("mf", b_M + b_Hasanta + b_Ph) == true) //M+Ph
    {
        return;
    }

    if (Cnv("m", b_M) == true) //M
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::b()
{
    if (Cnv("bdh", b_B + b_Hasanta + b_Dh) == true) //B+Dh
    {
        return;
    }
    if (Cnv("bhl", b_Bh + b_Hasanta + b_L) == true) //Bh+L
    {
        return;
    }

    if (Cnv("bj", b_B + b_Hasanta + b_J) == true) //B+J
    {
        return;
    }
    if (Cnv("bd", b_B + b_Hasanta + b_D) == true) //B+D
    {
        return;
    }
    if (Cnv("bb", b_B + b_Hasanta + b_B) == true) //B+B
    {
        return;
    }
    if (Cnv("bl", b_B + b_Hasanta + b_L) == true) //B+L
    {
        return;
    }
    if (Cnv("bh", b_Bh) == true) //Bh
    {
        return;
    }
    if (Cnv("vl", b_Bh + b_Hasanta + b_L) == true) //Bh+L
    {
        return;
    }

    if (Cnv("b", b_B) == true) //B
    {
        return;
    }
    if (Cnv("v", b_Bh) == true) //Bh
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::p()
{
    if (Cnv("phl", b_Ph + b_Hasanta + b_L) == true) //Ph+L
    {
        return;
    }

    if (Cnv("pT", b_P + b_Hasanta + b_Tt) == true) //P+Tt
    {
        return;
    }
    if (Cnv("pt", b_P + b_Hasanta + b_T) == true) //P+T
    {
        return;
    }
    if (Cnv("pn", b_P + b_Hasanta + b_N) == true) //P+N
    {
        return;
    }
    if (Cnv("pp", b_P + b_Hasanta + b_P) == true) //P+P
    {
        return;
    }
    if (Cnv("pl", b_P + b_Hasanta + b_L) == true) //P+L
    {
        return;
    }
    if (Cnv("ps", b_P + b_Hasanta + b_S) == true) //P+S
    {
        return;
    }
    if (Cnv("ph", b_Ph) == true) //Ph
    {
        return;
    }
    if (Cnv("fl", b_Ph + b_Hasanta + b_L) == true) //Ph+L
    {
        return;
    }

    if (Cnv("f", b_Ph) == true) //Ph
    {
        return;
    }
    if (Cnv("p", b_P) == true) //P
    {
        return;
    }
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::d()
{
    if (Cnv("dhn", b_Dh + b_Hasanta + b_N) == true) //Dh+N
    {
        return;
    }
    if (Cnv("dhm", b_Dh + b_Hasanta + b_M) == true) //Dh+M
    {
        return;
    }
    if (Cnv("dgh", b_D + b_Hasanta + b_GH) == true) //D+Gh
    {
        return;
    }
    if (Cnv("ddh", b_D + b_Hasanta + b_Dh) == true) //D+Dh
    {
        return;
    }
    if (Cnv("dbh", b_D + b_Hasanta + b_Bh) == true) //D+Bh
    {
        return;
    }

    if (Cnv("dv", b_D + b_Hasanta + b_Bh) == true) //D+Bh
    {
        return;
    }
    if (Cnv("dm", b_D + b_Hasanta + b_M) == true) //D+M
    {
        return;
    }
    if (Cnv("DD", b_Dd + b_Hasanta + b_Dd) == true) //Dd+Dd
    {
        return;
    }
    if (Cnv("Dh", b_Ddh) == true) //Ddh
    {
        return;
    }
    if (Cnv("dh", b_Dh) == true) //Dh
    {
        return;
    }
    if (Cnv("dg", b_D + b_Hasanta + b_G) == true) //D+G
    {
        return;
    }
    if (Cnv("dd", b_D + b_Hasanta + b_D) == true) //D+D
    {
        return;
    }

    if (Cnv("D", b_Dd) == true) //Dd
    {
        return;
    }
    if (Cnv("d", b_D) == true) //D
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::T()
{
    if (Cnv("tth", b_T + b_Hasanta + b_Th) == true) //T+Th
    {
        return;
    }
    if (Cnv("t``", b_Khandatta) == true) //Khandatta
    {
        return;
    }

    if (Cnv("TT", b_Tt + b_Hasanta + b_Tt) == true) //Tt+Tt
    {
        return;
    }
    if (Cnv("Tm", b_Tt + b_Hasanta + b_M) == true) //Tt+M
    {
        return;
    }
    if (Cnv("Th", b_Tth) == true) //Tth
    {
        return;
    }
    if (Cnv("tn", b_T + b_Hasanta + b_N) == true) //T+N
    {
        return;
    }
    if (Cnv("tm", b_T + b_Hasanta + b_M) == true) //T+M
    {
        return;
    }
    if (Cnv("th", b_Th) == true) //Th
    {
        return;
    }
    if (Cnv("tt", b_T + b_Hasanta + b_T) == true) //T+T
    {
        return;
    }

    if (Cnv("T", b_Tt) == true) //Tt
    {
        return;
    }
    if (Cnv("t", b_T) == true) //T
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::J()
{
    if (Cnv("jjh", b_J + b_Hasanta + b_JH) == true) //J+Jh
    {
        return;
    }
    if (Cnv("jNG", b_J + b_Hasanta + b_NYA) == true) //J+NYA
    {
        return;
    }
    if (Cnv("jh", b_JH) == true) //Jh
    {
        return;
    }
    if (Cnv("jj", b_J + b_Hasanta + b_J) == true) //J+J
    {
        return;
    }
    if (Cnv("j", b_J) == true) //J
    {
        return;
    }
    if (Cnv("J", b_J + b_Nukta) == true) //J+Nukta
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::c()
{
    if (Cnv("cNG", b_C + b_Hasanta + b_NYA) == true) //C+NYA
    {
        return;
    }
    if (Cnv("cch", b_C + b_Hasanta + b_CH) == true) //C+C
    {
        return;
    }
    if (Cnv("cc", b_C + b_Hasanta + b_C) == true) //C+C
    {
        return;
    }

    if (Cnv("ch", b_CH) == true) //C
    {
        return;
    }
    if (Cnv("c", b_C) == true) //C
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::n()
{
    if (Cnv("NgkSh", b_NGA + b_Hasanta + b_K + b_Hasanta + b_Ss) == true) //NGA+Khio
    {
        return;
    }
    if (Cnv("Ngkkh", b_NGA + b_Hasanta + b_K + b_Hasanta + b_Ss) == true) //NGA+Khio
    {
        return;
    }


    if (Cnv("NGch", b_NYA + b_Hasanta + b_CH) == true) //NYA+Ch
    {
        return;
    }
    if (Cnv("Nggh", b_NGA + b_Hasanta + b_GH) == true) //NGA+Gh
    {
        return;
    }
    if (Cnv("Ngkh", b_NGA + b_Hasanta + b_KH) == true) //NGA+Kh
    {
        return;
    }
    if (Cnv("NGjh", b_NYA + b_Hasanta + b_JH) == true) //NYA+Jh
    {
        return;
    }
    if (Cnv("ngOU", b_NGA + b_Hasanta + b_G + b_OUkar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("ngOI", b_NGA + b_Hasanta + b_G + b_OIkar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("Ngkx", b_NGA + b_Hasanta + b_K + b_Hasanta + b_Ss) == true) //NGA+Khio
    {
        return;
    }

    if (Cnv("NGc", b_NYA + b_Hasanta + b_C) == true) //NYA+Ch
    {
        return;
    }
    if (Cnv("nch", b_NYA + b_Hasanta + b_CH) == true) //NYA+Ch
    {
        return;
    }
    if (Cnv("njh", b_NYA + b_Hasanta + b_JH) == true) //NYA+Jh
    {
        return;
    }
    if (Cnv("nch", b_NYA + b_Hasanta + b_C) == true) //NYA+Ch
    {
        return;
    }
    if (Cnv("ngh", b_NGA + b_Hasanta + b_GH) == true) //NGA+Gh
    {
        return;
    }
    if (Cnv("Ngk", b_NGA + b_Hasanta + b_K) == true) //NGA+K
    {
        return;
    }
    if (Cnv("Ngx", b_NGA + b_Hasanta + b_Ss) == true) //NGA+Khio
    {
        return;
    }
    if (Cnv("Ngg", b_NGA + b_Hasanta + b_G) == true) //NGA+G
    {
        return;
    }
    if (Cnv("Ngm", b_NGA + b_Hasanta + b_M) == true) //NGA+M
    {
        return;
    }
    if (Cnv("NGj", b_NYA + b_Hasanta + b_J) == true) //NYA+J
    {
        return;
    }
    if (Cnv("ndh", b_N + b_Hasanta + b_Dh) == true) //N+Dh
    {
        return;
    }
    if (Cnv("nTh", b_N + b_Hasanta + b_Tth) == true) //N+Tth
    {
        return;
    }
    if (Cnv("NTh", b_Nn + b_Hasanta + b_Tth) == true) //Nn+Tth
    {
        return;
    }
    if (Cnv("nth", b_N + b_Hasanta + b_Th) == true) //N+Th
    {
        return;
    }
    if (Cnv("nkh", b_NGA + b_Hasanta + b_KH) == true) //NGA+Kh
    {
        return;
    }
    if (Cnv("ngo", b_NGA + b_Hasanta + b_G) == true) //NGA+G
    {
        return;
    }
    if (Cnv("nga", b_NGA + b_Hasanta + b_G + b_AAkar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("ngi", b_NGA + b_Hasanta + b_G + b_Ikar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("ngI", b_NGA + b_Hasanta + b_G + b_IIkar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("ngu", b_NGA + b_Hasanta + b_G + b_Ukar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("ngU", b_NGA + b_Hasanta + b_G + b_UUkar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("nge", b_NGA + b_Hasanta + b_G + b_Ekar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("ngO", b_NGA + b_Hasanta + b_G + b_Okar) == true) //NGA+G
    {
        return;
    }
    if (Cnv("NDh", b_Nn + b_Hasanta + b_Ddh) == true) //Nn+Ddh
    {
        return;
    }

    if (Cnv("nsh", b_N + b_Sh) == true) //N & Sh
    {
        return;
    }

    if (Cnv("Ngr", b_NGA + b_R) == true) //NGA & R
    {
        return;
    }
    if (Cnv("NGr", b_NYA + b_R) == true) //NYA & R
    {
        return;
    }
    if (Cnv("ngr", b_Anushar + b_R) == true) //Anushar & R
    {
        return;
    }

    if (Cnv("nj", b_NYA + b_Hasanta + b_J) == true) //NYA+J
    {
        return;
    }
    if (Cnv("Ng", b_NGA) == true) //NGA
    {
        return;
    }
    if (Cnv("NG", b_NYA) == true) //NYA
    {
        return;
    }
    if (Cnv("nk", b_NGA + b_Hasanta + b_K) == true) //NGA+K
    {
        return;
    }
    if (Cnv("ng", b_Anushar) == true) //Anushar
    {
        return;
    }
    if (Cnv("nn", b_N + b_Hasanta + b_N) == true) //N+N
    {
        return;
    }
    if (Cnv("NN", b_Nn + b_Hasanta + b_Nn) == true) //Nn+Nn
    {
        return;
    }
    if (Cnv("Nn", b_Nn + b_Hasanta + b_N) == true) //Nn+N
    {
        return;
    }
    if (Cnv("nm", b_N + b_Hasanta + b_M) == true) //N+M
    {
        return;
    }
    if (Cnv("Nm", b_Nn + b_Hasanta + b_M) == true) //Nn+M
    {
        return;
    }
    if (Cnv("nd", b_N + b_Hasanta + b_D) == true) //N+D
    {
        return;
    }
    if (Cnv("nT", b_N + b_Hasanta + b_Tt) == true) //N+Tt
    {
        return;
    }
    if (Cnv("NT", b_Nn + b_Hasanta + b_Tt) == true) //Nn+Tt
    {
        return;
    }
    if (Cnv("nD", b_N + b_Hasanta + b_Dd) == true) //N+Dd
    {
        return;
    }
    if (Cnv("ND", b_Nn + b_Hasanta + b_Dd) == true) //Nn+Dd
    {
        return;
    }
    if (Cnv("nt", b_N + b_Hasanta + b_T) == true) //N+T
    {
        return;
    }
    if (Cnv("ns", b_N + b_Hasanta + b_S) == true) //N+S
    {
        return;
    }
    if (Cnv("nc", b_NYA + b_Hasanta + b_C) == true) //NYA+C
    {
        return;
    }

    if (Cnv("n", b_N) == true) //N
    {
        return;
    }
    if (Cnv("N", b_Nn) == true) //N
    {
        return;
    }
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::k()
{
    if (Cnv("kkhN", b_K + b_Hasanta + b_Ss + b_Hasanta + b_Nn) == true) //khioN
    {
        return;
    }
    if (Cnv("kShN", b_K + b_Hasanta + b_Ss + b_Hasanta + b_Nn) == true) //khioN
    {
        return;
    }
    if (Cnv("kkhm", b_K + b_Hasanta + b_Ss + b_Hasanta + b_M) == true) //khioM
    {
        return;
    }
    if (Cnv("kShm", b_K + b_Hasanta + b_Ss + b_Hasanta + b_M) == true) //khioM
    {
        return;
    }

    if (Cnv("kxN", b_K + b_Hasanta + b_Ss + b_Hasanta + b_Nn) == true) //khioN
    {
        return;
    }
    if (Cnv("kxm", b_K + b_Hasanta + b_Ss + b_Hasanta + b_M) == true) //khioM
    {
        return;
    }
    if (Cnv("kkh", b_K + b_Hasanta + b_Ss) == true) //khio
    {
        return;
    }
    if (Cnv("kSh", b_K + b_Hasanta + b_Ss) == true) //khio
    {
        return;
    }

    if (Cnv("ksh", b_K + b_Sh) == true) //K`Sh
    {
        return;
    }

    if (Cnv("kx", b_K + b_Hasanta + b_Ss) == true) //khio
    {
        return;
    }
    if (Cnv("kk", b_K + b_Hasanta + b_K) == true) //k+k
    {
        return;
    }
    if (Cnv("kT", b_K + b_Hasanta + b_Tt) == true) //k+T
    {
        return;
    }
    if (Cnv("kt", b_K + b_Hasanta + b_T) == true) //k+t
    {
        return;
    }
    if (Cnv("km", b_K + b_Hasanta + b_M) == true) //k+M
    {
        return;
    }
    if (Cnv("kl", b_K + b_Hasanta + b_L) == true) //k+L
    {
        return;
    }
    if (Cnv("ks", b_K + b_Hasanta + b_S) == true) //k+S
    {
        return;
    }

    if (Cnv("kh", b_KH) == true) //kh
    {
        return;
    }

    if (Cnv("k", b_K) == true) //k
    {
        return;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::g()
{
    if (Cnv("ghn", b_GH + b_Hasanta + b_N) == true) //gh+N
    {
        return;
    }
    if (Cnv("Ghn", b_GH + b_Hasanta + b_N) == true) //gh+N
    {
        return;
    }

    if (Cnv("gdh", b_G + b_Hasanta + b_Dh) == true) //g+dh
    {
        return;
    }
    if (Cnv("Gdh", b_G + b_Hasanta + b_Dh) == true) //g+dh
    {
        return;
    }

    if (Cnv("gN", b_G + b_Hasanta + b_Nn) == true) //g+N
    {
        return;
    }
    if (Cnv("GN", b_G + b_Hasanta + b_Nn) == true) //g+N
    {
        return;
    }

    if (Cnv("gn", b_G + b_Hasanta + b_N) == true) //g+n
    {
        return;
    }
    if (Cnv("Gn", b_G + b_Hasanta + b_N) == true) //g+n
    {
        return;
    }

    if (Cnv("gm", b_G + b_Hasanta + b_M) == true) //g+M
    {
        return;
    }
    if (Cnv("Gm", b_G + b_Hasanta + b_M) == true) //g+M
    {
        return;
    }

    if (Cnv("gl", b_G + b_Hasanta + b_L) == true) //g+L
    {
        return;
    }
    if (Cnv("Gl", b_G + b_Hasanta + b_L) == true) //g+L
    {
        return;
    }

    if (Cnv("gg", b_J + b_Hasanta + b_NYA) == true) //gg
    {
        return;
    }
    if (Cnv("GG", b_J + b_Hasanta + b_NYA) == true) //gg
    {
        return;
    }
    if (Cnv("Gg", b_J + b_Hasanta + b_NYA) == true) //gg
    {
        return;
    }
    if (Cnv("gG", b_J + b_Hasanta + b_NYA) == true) //gg
    {
        return;
    }

    if (Cnv("gh", b_GH) == true) //gh
    {
        return;
    }
    if (Cnv("Gh", b_GH) == true) //gh
    {
        return;
    }


    if (Cnv("g", b_G) == true) //g
    {
        return;
    }
    if (Cnv("G", b_G) == true) //g
    {
        return;
    }

}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



bool
cEnglishToBangla::Cnv (String Compare, WideString IfTrue)
{
    bool tempCnv = false;

    int i = 0;
    String tmp = "";

    i = Compare.length();
    tmp = pEnglishText.substr(pos - 1, i);

    if (Compare == tmp)
    {
        tempCnv = true;
        Rs = Rs + IfTrue;
        pos = pos + i;
    }
    else
    {
        tempCnv = false;
    }

    return tempCnv;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void
cEnglishToBangla::AddRs (WideString T)
{
    Rs = Rs + T;
    pos = pos + 1;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void
cEnglishToBangla::AddRsEx (WideString T, int p)
{
    Rs = Rs + T;
    pos = pos + p;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


String
cEnglishToBangla::PrevT ()
{
    int i = 0;

    i = pos - 1;
    if (i < 1)
    {
        return "";
    }

    return pEnglishText.substr(i - 1, 1);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


String
cEnglishToBangla::PrevTEx (int Position)
{
    int i = 0;

    i = pos - Position;
    if (i < 1)
    {
        return "";
    }

    return pEnglishText.substr(i - 1, 1);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


String
cEnglishToBangla::NextT	()
{
    return pEnglishText.substr(pos, 1);
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


String
cEnglishToBangla::NextTEx (int Length, int skipstart)
{
    if (Length < 1)
    {
        Length = 1;
    }

    if (pEnglishText.length()>=(pos + skipstart + Length))
        return pEnglishText.substr(pos + skipstart, Length);
    return "";

}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


bool
cEnglishToBangla::Vowel	(String T)
{
    bool tempVowel = false;

    std::transform (T.begin(), T.end(), T.begin(), tolower);
    if (T == "a" || T == "e" || T == "i" || T == "o" || T == "u")
    {
        tempVowel = true;
    }
    else
    {
        tempVowel = false;
    }

    return tempVowel;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


bool
cEnglishToBangla::Consonent(String T)
{
    bool tempConsonent = false;

    std::transform (T.begin(), T.end(), T.begin(), tolower);

    if ((T == "b") || (T == "c") || (T == "d") || (T == "f") || (T == "g") || (T == "h") || (T == "j") || (T == "k") || (T == "l") || (T == "m") || (T == "n") || (T == "p") || (T == "q") || (T == "r") || (T == "s") || (T == "t") || (T == "v") || (T == "w") || (T == "x") || (T == "y") || (T == "z"))
    {
        tempConsonent = true;
    }
    else
    {
        tempConsonent = false;
    }

    return tempConsonent;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


bool
cEnglishToBangla::Begining()
{
    bool tempBegining = false;

    String T = "";

    T = PrevT();


    if ((T == "0") || (T == "1") || (T == "2") || (T == "3") || (T == "4") || (T == "5") || (T == "6") || (T == "7") || (T == "8") || (T == "9"))
    {
        tempBegining = false;
    }
    else if ((T == "A") || (T == "B") || (T == "C") || (T == "D") || (T == "E") || (T == "F") || (T == "G") || (T == "H") || (T == "I") || (T == "J") || (T == "K") || (T == "L") || (T == "M") || (T == "N") || (T == "O") || (T == "P") || (T == "Q") || (T == "R") || (T == "S") || (T == "T") || (T == "U") || (T == "V") || (T == "W") || (T == "X") || (T == "Y") || (T == "Z"))
    {
        tempBegining = false;
    }
    else if ((T == "a") || (T == "b") || (T == "c") || (T == "d") || (T == "e") || (T == "f") || (T == "g") || (T == "h") || (T == "i") || (T == "j") || (T == "k") || (T == "l") || (T == "m") || (T == "n") || (T == "o") || (T == "p") || (T == "q") || (T == "r") || (T == "s") || (T == "t") || (T == "u") || (T == "v") || (T == "w") || (T == "x") || (T == "y") || (T == "z"))
    {
        tempBegining = false;
    }
    else
    {
        tempBegining = true;
    }

    return tempBegining;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
