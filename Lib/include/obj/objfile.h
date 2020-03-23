/*
libobj - the open-source Wavefront .obj loader
Copyright (C) 2007  Ben Ruyl

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef OBJ_FILE
#define OBJ_FILE

 #ifdef __cplusplus
 extern "C" {
 #endif 

// data structures
typedef struct
{
  char filename[2][50];
  
}FILERECORD;

typedef struct
{
  float x,y,z;
}VERTEX;

typedef struct
{
  float x,y,z;
}NORM;


typedef struct
{
  int numsides;
  int vert[3];
  int norm[3];
  int tex[3];
  int matindex;
  int hasnorm, hastex;
}FACE;

typedef struct
{
  float u, v;
}TEX;

typedef struct
{
  char		  m_MaterialName[256]; // material name
  char		  m_TextureMap1[256];
  char		  m_TextureMap2[256];
  float		  m_AmbientColor[4],
  m_DiffuseColor[4],
  m_SpecularColor[4];
  float		  m_Alpha;
  float		  m_Shininess;
  
}MAT;


typedef struct
{
  int numfaces;
  FACE *faces;

  int numverts;
  VERTEX *vertices;

  int numtex;
  TEX *texturecoords;

  int numnorm;
  NORM *normals;

  char matlibname[256];

  int nummat;
  MAT *materials;//[MAX_MATERIALS];
}OBJECT;



// includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// protose
int LoadObj(OBJECT* &aObject, char *filename);
void CountObjects(void);
int ObjFileQue(int whichobject, char whatdata);
void LoadFaces(int theobject);
void LoadVertices(int theobject);
void LoadTextureMaps(int theobject);
void LoadNormals(int theobject);
void CreateMaterials(int theobject, char *dir);
int GetMatIndexFromName(int theobject, const char *name);
void ReleaseObj(OBJECT* aObject);

extern int numobjects;


 #ifdef __cplusplus
 }
 #endif 

#endif