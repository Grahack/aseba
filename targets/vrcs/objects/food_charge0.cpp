/*
	VRCS - Virtual Robot Challenge System
	Copyright (C) 1999 - 2008:
		Stephane Magnenat <stephane at magnenat dot net>
		(http://stephane.magnenat.net)
	3D models
	Copyright (C) 2008:
		Basilio Noris
	Aseba - an event-based framework for distributed robot control
	Copyright (C) 2006 - 2008:
		Stephane Magnenat <stephane at magnenat dot net>
		(http://stephane.magnenat.net)
		Mobots group (http://mobots.epfl.ch)
		Laboratory of Robotics Systems (http://lsro.epfl.ch)
		EPFL, Lausanne (http://www.epfl.ch)
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any other version as decided by the two original authors
	Stephane Magnenat and Valentin Longchamp.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <GL/gl.h>
#define BYTE unsigned char

namespace Enki
{
	// 48 Verticies
	// 74 Texture Coordinates
	// 49 Normals
	// 70 Triangles
	
	static BYTE face_indicies[70][9] = {
	// Object #-1
		{38,34,37 ,0,0,0 ,0,1,2 }, {45,34,38 ,0,0,0 ,3,1,0 }, {45,33,34 ,0,0,0 ,3,4,1 },
		{46,33,45 ,0,0,0 ,5,4,3 }, {46,30,33 ,0,0,0 ,5,6,4 }, {47,30,46 ,0,0,0 ,7,6,5 },
		{47,29,30 ,0,0,0 ,7,8,6 }, {43,29,47 ,0,0,0 ,9,8,7 }, {43,28,29 ,0,0,0 ,9,10,8 },
		{44,28,43 ,0,0,0 ,11,10,9 }, {44,27,28 ,0,0,0 ,11,12,10 }, {41,27,44 ,0,0,0 ,13,12,11 },
		{41,26,27 ,0,0,0 ,13,14,12 }, {42,26,41 ,0,0,0 ,15,14,13 }, {42,25,26 ,0,0,0 ,15,16,14 },
		{39,25,42 ,0,0,0 ,17,16,15 }, {39,24,25 ,0,0,0 ,17,18,16 }, {40,24,39 ,0,0,0 ,19,18,17 },
		{40,32,24 ,0,0,0 ,19,20,18 }, {35,32,40 ,0,0,0 ,21,20,19 }, {32,35,31 ,0,0,0 ,20,21,22 },
		{31,35,36 ,0,0,0 ,22,21,23 }, {5,25,4 ,1,2,3 ,24,25,26 }, {5,26,25 ,1,4,2 ,24,27,25 },
		{6,26,5 ,5,4,1 ,28,27,24 }, {6,27,26 ,5,6,4 ,28,29,27 }, {7,27,6 ,7,6,5 ,30,29,28 },
		{7,28,27 ,7,8,6 ,30,31,29 }, {8,28,7 ,9,8,7 ,32,31,30 }, {8,29,28 ,9,10,8 ,32,33,31 },
		{9,29,8 ,11,10,9 ,34,33,32 }, {9,30,29 ,11,12,10 ,34,35,33 },
		{10,30,9 ,13,12,11 ,36,35,34 }, {10,33,30 ,13,14,12 ,36,37,35 },
		{11,33,10 ,15,14,13 ,38,37,36 }, {11,34,33 ,15,16,14 ,38,39,37 },
		{12,34,11 ,17,16,15 ,40,39,38 }, {12,37,34 ,17,18,16 ,40,41,39 },
		{13,37,12 ,19,18,17 ,42,43,44 }, {13,38,37 ,19,20,18 ,42,45,43 },
		{14,38,13 ,21,20,19 ,46,45,42 }, {14,45,38 ,21,22,20 ,46,47,45 },
		{15,45,14 ,23,22,21 ,48,47,46 }, {15,46,45 ,23,24,22 ,48,49,47 },
		{16,46,15 ,25,24,23 ,50,49,48 }, {16,47,46 ,25,26,24 ,50,51,49 },
		{17,47,16 ,27,26,25 ,52,51,50 }, {17,43,47 ,27,28,26 ,52,53,51 },
		{18,43,17 ,29,28,27 ,54,53,52 }, {18,44,43 ,29,30,28 ,54,55,53 },
		{19,44,18 ,31,30,29 ,56,55,54 }, {19,41,44 ,31,32,30 ,56,57,55 },
		{20,41,19 ,33,32,31 ,58,57,56 }, {20,42,41 ,33,34,32 ,58,59,57 },
		{21,42,20 ,35,34,33 ,60,59,58 }, {21,39,42 ,35,36,34 ,60,61,59 },
		{22,39,21 ,37,36,35 ,62,61,60 }, {22,40,39 ,37,38,36 ,62,63,61 },
		{23,40,22 ,39,38,37 ,64,63,62 }, {23,35,40 ,39,40,38 ,64,65,63 },
		{0,35,23 ,41,40,39 ,66,65,64 }, {0,36,35 ,41,42,40 ,66,67,65 },
		{1,36,0 ,43,42,41 ,68,67,66 }, {1,31,36 ,43,44,42 ,68,69,67 },
		{2,31,1 ,45,44,43 ,70,69,68 }, {2,32,31 ,45,46,44 ,70,71,69 },
		{3,32,2 ,47,46,45 ,72,71,70 }, {3,24,32 ,47,48,46 ,72,73,71 },
		{4,24,3 ,3,48,47 ,26,73,72 }, {4,25,24 ,3,2,48 ,26,25,73 }
	};
	static GLfloat vertices [48][3] = {
	{0.02f,0.0f,0.066f},{0.0193185f,0.00517638f,0.066f},{0.0173205f,0.01f,0.066f},
	{0.0141421f,0.0141421f,0.066f},{0.01f,0.0173205f,0.066f},{0.00517638f,0.0193185f,0.066f},
	{0.0f,0.02f,0.066f},{-0.00517638f,0.0193185f,0.066f},{-0.01f,0.0173205f,0.066f},
	{-0.0141421f,0.0141421f,0.066f},{-0.0173205f,0.01f,0.066f},{-0.0193185f,0.00517638f,0.066f},
	{-0.02f,0.0f,0.066f},{-0.0193185f,-0.00517638f,0.066f},{-0.0173205f,-0.01f,0.066f},
	{-0.0141421f,-0.0141421f,0.066f},{-0.01f,-0.0173205f,0.066f},{-0.00517638f,-0.0193185f,0.066f},
	{0.0f,-0.02f,0.066f},{0.00517638f,-0.0193185f,0.066f},{0.01f,-0.0173205f,0.066f},
	{0.0141421f,-0.0141421f,0.066f},{0.0173205f,-0.01f,0.066f},{0.0193185f,-0.00517638f,0.066f},
	{0.0146159f,0.0146159f,0.07475f},{0.010335f,0.0179007f,0.07475f},{0.00534979f,0.0199657f,0.07475f},
	{0.0f,0.02067f,0.07475f},{-0.00534979f,0.0199657f,0.07475f},{-0.010335f,0.0179007f,0.07475f},
	{-0.0146159f,0.0146159f,0.07475f},{0.0199657f,0.00534979f,0.07475f},{0.0179007f,0.010335f,0.07475f},
	{-0.0179007f,0.010335f,0.07475f},{-0.0199657f,0.00534979f,0.07475f},{0.0199657f,-0.00534979f,0.07475f},
	{0.02067f,0.0f,0.07475f},{-0.02067f,0.0f,0.07475f},{-0.0199657f,-0.00534979f,0.07475f},
	{0.0146159f,-0.0146159f,0.07475f},{0.0179007f,-0.010335f,0.07475f},{0.00534979f,-0.0199657f,0.07475f},
	{0.010335f,-0.0179007f,0.07475f},{-0.00534979f,-0.0199657f,0.07475f},{0.0f,-0.02067f,0.07475f},
	{-0.0179007f,-0.010335f,0.07475f},{-0.0146159f,-0.0146159f,0.07475f},{-0.010335f,-0.0179007f,0.07475f}
	};
	static GLfloat normals [49][3] = {
	{0.0f,0.0f,1.0f},{0.300042f,0.950872f,-0.0762749f},{0.460207f,0.884529f,-0.0762749f},
	{0.535922f,0.840815f,-0.0762749f},{0.215592f,0.9735f,-0.076275f},{0.0437142f,0.996128f,-0.076275f},
	{-0.0437142f,0.996128f,-0.076275f},{-0.215592f,0.9735f,-0.076275f},{-0.300042f,0.950872f,-0.0762749f},
	{-0.460207f,0.884529f,-0.0762749f},{-0.535922f,0.840815f,-0.0762749f},{-0.673458f,0.73528f,-0.0762749f},
	{-0.73528f,0.673458f,-0.0762749f},{-0.840815f,0.535922f,-0.0762749f},{-0.884529f,0.460207f,-0.0762749f},
	{-0.950872f,0.300042f,-0.0762749f},{-0.9735f,0.215592f,-0.076275f},{-0.996128f,0.0437142f,-0.076275f},
	{-0.996128f,-0.0437142f,-0.076275f},{-0.9735f,-0.215592f,-0.076275f},{-0.950872f,-0.300042f,-0.0762749f},
	{-0.884529f,-0.460207f,-0.0762749f},{-0.840815f,-0.535922f,-0.0762749f},{-0.73528f,-0.673458f,-0.0762749f},
	{-0.673458f,-0.73528f,-0.0762749f},{-0.535922f,-0.840815f,-0.0762749f},{-0.460207f,-0.884529f,-0.0762749f},
	{-0.300042f,-0.950872f,-0.0762749f},{-0.215592f,-0.9735f,-0.076275f},{-0.0437142f,-0.996128f,-0.076275f},
	{0.0437142f,-0.996128f,-0.076275f},{0.215592f,-0.9735f,-0.076275f},{0.300042f,-0.950872f,-0.0762749f},
	{0.460207f,-0.884529f,-0.0762749f},{0.535922f,-0.840815f,-0.0762749f},{0.673458f,-0.73528f,-0.0762749f},
	{0.73528f,-0.673458f,-0.0762749f},{0.840815f,-0.535922f,-0.0762749f},{0.884529f,-0.460207f,-0.0762749f},
	{0.950872f,-0.300042f,-0.0762749f},{0.9735f,-0.215592f,-0.076275f},{0.996128f,-0.0437142f,-0.076275f},
	{0.996128f,0.0437142f,-0.076275f},{0.9735f,0.215592f,-0.076275f},{0.950872f,0.300042f,-0.0762749f},
	{0.884529f,0.460207f,-0.0762749f},{0.840815f,0.535922f,-0.0762749f},{0.73528f,0.673458f,-0.0762749f},
	{0.673458f,0.73528f,-0.0762749f}
	};
	static GLfloat textures [74][2] = {
	{0.511035f,0.0343294f},{0.511035f,0.0521932f},{0.509859f,0.0432613f},
	{0.514483f,0.0260062f},{0.514483f,0.0605164f},{0.519967f,0.018859f},
	{0.519967f,0.0676636f},{0.527115f,0.0133746f},{0.527115f,0.0731479f},
	{0.535438f,0.00992709f},{0.535438f,0.0765955f},{0.54437f,0.00875115f},
	{0.54437f,0.0777714f},{0.553302f,0.00992709f},{0.553302f,0.0765955f},
	{0.561625f,0.0133746f},{0.561625f,0.0731479f},{0.568772f,0.018859f},
	{0.568772f,0.0676636f},{0.574256f,0.0260062f},{0.574256f,0.0605164f},
	{0.577704f,0.0343294f},{0.577704f,0.0521932f},{0.57888f,0.0432613f},
	{0.624689f,0.162312f},{0.613751f,0.194494f},{0.613751f,0.162312f},
	{0.624689f,0.194494f},{0.635626f,0.162312f},{0.635626f,0.194494f},
	{0.646564f,0.162312f},{0.646564f,0.194494f},{0.657502f,0.162312f},
	{0.657502f,0.194494f},{0.66844f,0.162312f},{0.66844f,0.194494f},
	{0.679377f,0.162312f},{0.679377f,0.194494f},{0.690315f,0.162312f},
	{0.690315f,0.194494f},{0.701253f,0.162312f},{0.701253f,0.194494f},
	{0.449685f,0.162312f},{0.438747f,0.194336f},{0.438747f,0.162312f},
	{0.449685f,0.194494f},{0.460623f,0.162312f},{0.460623f,0.194494f},
	{0.47156f,0.162312f},{0.47156f,0.194494f},{0.482498f,0.162312f},
	{0.482498f,0.194494f},{0.493436f,0.162312f},{0.493436f,0.194494f},
	{0.504374f,0.162312f},{0.504374f,0.194494f},{0.515311f,0.162312f},
	{0.515311f,0.194494f},{0.526249f,0.162312f},{0.526249f,0.194494f},
	{0.537187f,0.162312f},{0.537187f,0.194494f},{0.548125f,0.162312f},
	{0.548125f,0.194494f},{0.559062f,0.162312f},{0.559062f,0.194494f},
	{0.57f,0.162312f},{0.57f,0.194494f},{0.580938f,0.162312f},
	{0.580938f,0.194494f},{0.591875f,0.162312f},{0.591875f,0.194494f},
	{0.602813f,0.162312f},{0.602813f,0.194494f}
	};
	GLint GenFeederCharge0()
	{
		int i;
		int j;
		
		GLint lid=glGenLists(1);
		glNewList(lid, GL_COMPILE);
		
			glBegin (GL_TRIANGLES);
			for(i=0;i<sizeof(face_indicies)/sizeof(face_indicies[0]);i++)
			{
			for(j=0;j<3;j++)
				{
				int vi=face_indicies[i][j];
				int ni=face_indicies[i][j+3];//Normal index
				int ti=face_indicies[i][j+6];//Texture index
				/*glNormal3f (normals[ni][0],normals[ni][1],normals[ni][2]);
				glTexCoord2f(textures[ti][0],textures[ti][1]);
				glVertex3f (vertices[vi][0],vertices[vi][1],vertices[vi][2]);*/
				
				// rotate 90 deg around z
				glNormal3f (normals[ni][1],-normals[ni][0],normals[ni][2]);
				glTexCoord2f(textures[ti][0],textures[ti][1]);
				glVertex3f (100.f*vertices[vi][1],-100.f*vertices[vi][0],100.f*vertices[vi][2]);
				}
			}
			glEnd ();
		
		glEndList();
		return lid;
	};
}
