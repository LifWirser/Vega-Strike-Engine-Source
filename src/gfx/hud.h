/*
 * Vega Strike
 * Copyright (C) 2001-2002 Daniel Horn & Alan Shieh
 *
 * http://vegastrike.sourceforge.net/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#include <string>
#include "vec.h"

struct Texture;

class TextPlane {
	std::string myText;

	Texture *myFont;
	Vector myFontMetrics; // i = width, j = height
	Vector myDims;
	int numlet;
	struct GlyphPosition {
		float left, right, top, bottom;
	} myGlyphPos[256];
public:
	TextPlane(const char *filename);
	~TextPlane();
	void SetPos (float x, float y) {
	  myFontMetrics.k = y;
	  myDims.k=x;
	}
	void SetCharSize (float x, float y) {
	  myFontMetrics.i = x;
	  myFontMetrics.j = y;
	}
	void GetCharSize (float &x, float &y) {
	  x = myFontMetrics.i;
	  y = myFontMetrics.j;
	}
	void GetPos (float &x, float &y) {
	  x = myFontMetrics.k;
	  y = myDims.k;
	}
	void SetSize (float x, float y) {
	  myDims.i = x;
	  myDims.j = y;
	}
	void Draw();
	void Draw (const string &text);
	void SetText(const string &newText) {
		myText = newText;
	}

};
