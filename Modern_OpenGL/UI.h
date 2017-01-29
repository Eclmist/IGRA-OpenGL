#pragma once
#include <math.h>                    
#include <stdio.h>                      
#include <stdarg.h>     
#include <Windows.h>
#include <gl/GL.h>

extern HDC hDC;

class UI
{
public:
	static GLuint  base;                           // Base Display List For The Font Set

	static int lastFontSize;

	static GLvoid BuildFont(int fontsize = -16)
	{
		if (lastFontSize == fontsize)
			return;

		lastFontSize = fontsize;

		KillFont(); //Kill the previous font

		HFONT   font;                       // Windows Font ID
		HFONT   oldfont;                    // Used For Good House Keeping

		base = glGenLists(96);                  // Storage For 96 Characters ( NEW )

		font = CreateFont(fontsize,                // Height Of Font ( NEW )
			0,              // Width Of Font
			0,              // Angle Of Escapement
			0,              // Orientation Angle
			FW_BOLD,            // Font Weight
			FALSE,              // Italic
			FALSE,              // Underline
			FALSE,              // Strikeout
			ANSI_CHARSET,           // Character Set Identifier
			OUT_TT_PRECIS,          // Output Precision
			CLIP_DEFAULT_PRECIS,        // Clipping Precision
			ANTIALIASED_QUALITY,        // Output Quality
			FF_DONTCARE | DEFAULT_PITCH,  // Family And Pitch
			"Courier New");         // Font Name

		oldfont = (HFONT)SelectObject(hDC, font);       // Selects The Font We Want
		wglUseFontBitmaps(hDC, 32, 96, base);           // Builds 96 Characters Starting At Character 32
		SelectObject(hDC, oldfont);             // Selects The Font We Want
		DeleteObject(font);                 // Delete The Font

	}

	static GLvoid KillFont(GLvoid)                     // Delete The Font List
	{
		glDeleteLists(base, 96);                // Delete All 96 Characters ( NEW )
	}

	static GLvoid glPrint(const char *fmt, ...)                // Custom GL "Print" Routine
	{
		char        text[256];              // Holds Our String
		va_list     ap;                 // Pointer To List Of Arguments
		
		if (fmt == NULL)                    // If There's No Text
			return;                     // Do Nothing
		
		va_start(ap, fmt);                  // Parses The String For Variables
		vsprintf(text, fmt, ap);                // And Converts Symbols To Actual Numbers
		va_end(ap);                     // Results Are Stored In Text

		glPushAttrib(GL_LIST_BIT);              // Pushes The Display List Bits     ( NEW )
		glListBase(base - 32);                  // Sets The Base Character to 32    ( NEW )

		glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);  // Draws The Display List Text  ( NEW )
		glPopAttrib();                      // Pops The Display List Bits   ( NEW )
	}
};

