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

/*

Special thank you to:
- Robert Bateman
- The whole open-source community

*/

#define _CRT_SECURE_NO_WARNINGS

#include "objfile.h"
#include <string>

// defines
#define MAX_GAME_OBJECTS 200
#define MAX_FACES 2000000
#define MAX_VERTICES 400000
#define MAX_TEXTURES 400000
#define MAX_MATERIALS 40

#define MAX_VERTPERFACE 3 // a triangle

FILE *stream;

OBJECT * newobject[2];

int numobjects = 0;

int objectsInFile = 0;

int LoadObj(OBJECT * &aObject, char *filename)
{
	// open and read obj file
	int i = 0;
	if ((stream = fopen(filename, "r+t")) != NULL)
	{
		//  CountObjects();

		numobjects = 1;
		objectsInFile = 1;

		newobject[0] = NULL;
		newobject[0] = (OBJECT*)malloc(sizeof(OBJECT));
		newobject[0]->faces = NULL;
		newobject[0]->materials = NULL;
		newobject[0]->vertices = NULL;
		newobject[0]->texturecoords = NULL;
		newobject[0]->normals = NULL;

		std::string fullpath = filename;
		std::string::size_type pos2 = fullpath.find_last_of("/");
		std::string dir = fullpath.substr(0, pos2);
		CreateMaterials(0, (char*)dir.c_str());
		// Load in the faces
		LoadFaces(0);
		// Load the vertices
		LoadVertices(0);
		LoadTextureMaps(0);
		LoadNormals(0);

		aObject = newobject[0];

		fclose(stream);

		return 0;
	}
	else
		return 2; // errorcode for file not found


}

void CountObjects()
{
	// determine number of objects in currently open .obj file
	// and update 'numobjects' global

	char s[100];
	char objectname[100];
	char *tok;


	objectsInFile = 0;
	while ((fgets(s, 100, stream)) != NULL)
	{
		if (s[0] == 'g')
		{
			if (strlen(s) > 2) {
				tok = strtok(s, " ");
				tok = strtok(NULL, " ");
				if (strcmp(objectname, tok) != 0){
					strcpy(objectname, tok);
					objectname[strlen(tok) - 1] = 0;
					objectsInFile++;
				}
			}

		}
	}
	if (objectsInFile == 0)
		objectsInFile = 1;
	numobjects += objectsInFile;
}

void CreateMaterials(int theobject, char *dir)
{
	FILE* matlib;

	unsigned int hasfile = 0;
	char buffer[256];

	int CurrentMaterialIndex = -1;

	rewind(stream);

	while (!feof(stream))
	{
		memset(buffer, 0, 200);
		fgets(buffer, 256, stream);

		if (strncmp("mtllib ", buffer, 7) == 0)
		{
			sscanf((buffer + 6), "%s", &newobject[theobject + (numobjects -
				objectsInFile)]->matlibname);
			hasfile = 1;
			break;
		}
	}

	rewind(stream);

	newobject[theobject + (numobjects - objectsInFile)]->nummat = 0;
	newobject[theobject + (numobjects - objectsInFile)]->materials = NULL;

	if (hasfile == 1)
	{
		std::string fullpath = dir;
		fullpath.append("/").append(newobject[theobject + (numobjects -
			objectsInFile)]->matlibname);
		matlib = fopen(fullpath.c_str(), "r+t");

		if (matlib != NULL)
		{

			rewind(matlib);


			while (!feof(matlib))
			{
				memset(buffer, 0, 200);

				/*	Grab a line at a time	*/
				fgets(buffer, 256, matlib);

				if (strncmp("newmtl ", buffer, 7) == 0)
				{
					newobject[theobject + (numobjects - objectsInFile)]->nummat++;

				}

			}


			newobject[theobject + (numobjects - objectsInFile)]->materials =
				(MAT*)malloc(newobject[theobject + (numobjects - objectsInFile)]->nummat * sizeof(MAT));

			if (newobject[theobject + (numobjects - objectsInFile)]->nummat == 0)
				newobject[theobject + (numobjects - objectsInFile)]->materials = NULL;

			rewind(matlib);

			while (!feof(matlib))
			{
				memset(buffer, 0, 200);

				/*	Grab a line at a time	*/
				fgets(buffer, 256, matlib);

				if (strncmp("newmtl ", buffer, 7) == 0)
				{
					CurrentMaterialIndex++;
					sscanf((buffer + 6), "%s",
						&newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_MaterialName);
				}
				else if (strncmp("Ka ", buffer, 3) == 0)
				{
					sscanf((buffer + 2), "%f%f%f", &newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_AmbientColor[0],
						&newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_AmbientColor[1],
						&newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_AmbientColor[2]);
					newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_AmbientColor[3] = 1.0f;
				}
				else if (strncmp("Kd ", buffer, 3) == 0)
				{
					sscanf((buffer + 2), "%f%f%f", &newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_DiffuseColor[0],
						&newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_DiffuseColor[1],
						&newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_DiffuseColor[2]);

					newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_DiffuseColor[3] = 1.0f;
				}
				else if (strncmp("Ks ", buffer, 3) == 0)
				{
					sscanf((buffer + 2), "%f%f%f", &newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_SpecularColor[0],
						&newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_SpecularColor[1],
						&newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_SpecularColor[2]);

					newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_SpecularColor[3] = 1.0f;
				}
				else if (strncmp("Ns ", buffer, 3) == 0)
				{
					sscanf((buffer + 2), "%f", &newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_Shininess);
				}
				else if (strncmp("d ", buffer, 2) == 0)
				{
					sscanf((buffer + 1), "%f", &newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_Alpha);
				}
				else if (strncmp("map_Ka ", buffer, 2) == 0)
				{
					sscanf((buffer + 6), "%s", &newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_TextureMap1);
				}
				else if (strncmp("map_Kd ", buffer, 2) == 0)
				{
					sscanf((buffer + 6), "%s", &newobject[theobject + (numobjects - objectsInFile)]->materials[CurrentMaterialIndex].m_TextureMap2);
				}
			}

			fclose(matlib);
		}

	}

}

void LoadNormals(int theobject)
{
	// load vertex data for specified object from .obj
	char s[200];
	char *tok;
	char temp[200];
	float coor[3];
	int texcount = 0, i;
	NORM newtex;

	rewind(stream);
	texcount = 0;
	while ((fgets(s, 200, stream)) != NULL)
	{

		if (s[0] == 'v' && s[1] == 'n')
		{
			texcount++;
		}

	}
	newobject[theobject + (numobjects - objectsInFile)]->normals =
		(NORM *)malloc(texcount * sizeof(NORM));

	newobject[theobject + (numobjects - objectsInFile)]->numnorm = texcount;


	texcount = 0;
	rewind(stream);
	while ((fgets(s, 100, stream)) != NULL)
	{

		if (s[0] == 'v' && s[1] == 'n')
		{

			tok = strtok(s, " ");
			for (i = 0; i < 3; i++)
			{
				tok = strtok(NULL, " ");
				strcpy(temp, tok);
				temp[strcspn(temp, " ")] = 0;
				coor[i] = (float)atof(temp);
			}
			newtex.x = coor[0];
			newtex.y = coor[1];
			newtex.z = coor[2];

			newobject[theobject + (numobjects - objectsInFile)]->normals[texcount] = newtex;
			texcount++;

		}
	}
}

int GetMatIndexFromName(int theobject, const char *name)
{
	int i;

	for (i = 0; i < newobject[theobject + (numobjects - objectsInFile)]->nummat; i++)
		if (strcmp(name,
			newobject[theobject + (numobjects - objectsInFile)]->materials[i].m_MaterialName) == 0)
			return i;

	return -1;
}

void LoadTextureMaps(int theobject)
{
	// load vertex data for specified object from .obj
	char s[200];
	char *tok;
	char temp[200];
	float coor[2];
	int texcount = 0, i;
	TEX newtex;

	rewind(stream);
	while ((fgets(s, 100, stream)) != NULL)
	{
		if (s[0] == 'v' && s[1] == 't')
		{
			texcount++;
		}

	}
	newobject[theobject + (numobjects - objectsInFile)]->texturecoords =
		(TEX*)malloc(texcount * sizeof(TEX));
	newobject[theobject + (numobjects - objectsInFile)]->numtex = texcount;

	texcount = 0;
	rewind(stream);
	while ((fgets(s, 100, stream)) != NULL)
	{
		if (s[0] == 'v' && s[1] == 't')
		{

			tok = strtok(s, " ");
			for (i = 0; i < 2; i++)
			{
				tok = strtok(NULL, " ");
				strcpy(temp, tok);
				temp[strcspn(temp, " ")] = 0;
				coor[i] = (float)atof(temp);
			}
			// newtex = (TEX *)malloc(sizeof(TEX));
			newtex.u = coor[0];
			newtex.v = coor[1];

			newobject[theobject + (numobjects - objectsInFile)]->texturecoords[texcount] = newtex;

			texcount++;

			//  newobject[theobject + (numobjects - objectsInFile)]->numtex = texcount;
		}
	}

}

void LoadVertices(int theobject)
{
	// load vertex data for specified object from .obj
	char s[200];
	char *tok;
	char temp[200];
	float coor[3];
	int vertcount = 0, i;
	VERTEX newvert;

	rewind(stream);
	while ((fgets(s, 100, stream)) != NULL)
	{

		if (s[0] == 'v' && s[1] == ' ')
		{
			vertcount++;
		}

	}

	newobject[theobject + (numobjects - objectsInFile)]->vertices =
		(VERTEX *)malloc(vertcount * sizeof(VERTEX));
	newobject[theobject + (numobjects - objectsInFile)]->numverts = vertcount;

	vertcount = 0;
	rewind(stream);
	while ((fgets(s, 100, stream)) != NULL)
	{

		if (s[0] == 'v' && s[1] == ' ')
		{

			tok = strtok(s, " ");
			for (i = 0; i < 3; i++)
			{
				tok = strtok(NULL, " ");
				strcpy(temp, tok);
				temp[strcspn(temp, " ")] = 0;
				coor[i] = (float)atof(temp);
			}
			//   newvert = (VERTEX *)malloc(sizeof(VERTEX));
			newvert.x = coor[0];
			newvert.y = coor[1];
			newvert.z = coor[2];

			//      newobject[theobject + (numobjects - objectsInFile)]->vertices[vertcount] = newvert;
			newobject[theobject + (numobjects - objectsInFile)]->vertices[vertcount].x = coor[0];
			newobject[theobject + (numobjects - objectsInFile)]->vertices[vertcount].y = coor[1];
			newobject[theobject + (numobjects - objectsInFile)]->vertices[vertcount].z = coor[2];
			vertcount++;

			//     newobject[theobject + (numobjects - objectsInFile)]->numverts = vertcount;
		}
	}

}

int GetIndices(char *pString, int *pVert, int *pNorm, int *pUV)
{
	int newline = 0;
	char *pV = pString,
		*pN = NULL,
		*pT = NULL;

	while (*pString != '\0')
	{
		if (*pString == '\\') // the information continues on a new line
			newline = 1;

		if (*pString == '/')
		{
			*pString = '\0';
			if (!pT)
			{
				pT = pString + 1;
			}
			else
			{
				pN = pString + 1;
			}
		}
		pString++;
	}

	sscanf(pV, "%d", pVert);


	if (pN == NULL || *pN == '\0')
	{
		*pNorm = 0;
	}
	else
	{
		sscanf(pN, "%d", pNorm);
	}

	if (pT == NULL || *pT == '\0')
	{
		*pUV = 0;
	}
	else
	{
		sscanf(pT, "%d", pUV);
	}

	return newline;
}

void LoadFaces(int theobject)
{
	// load face data for specified object from .obj
	char s[500];
	int numsides, vert[50], norm[50], tex[50]; // LIMITED TO 50!!! <- *TODO*
	char *tok;
	char temp[500];
	int i, facecount = 0;
	int state = 0;
	int ii, j;
	int hasnorm = 0, hastex = 0;
	int hasnewline = 0;

	int CurrentMatIndex = -1;

	rewind(stream);
	while ((fgets(s, 500, stream)) != NULL)
	{
		if (s[0] == 'f')
		{
			facecount++;
		}
	}

	newobject[theobject + (numobjects - objectsInFile)]->faces =
		(FACE *)malloc(facecount * sizeof(FACE));
	newobject[theobject + (numobjects - objectsInFile)]->numfaces = facecount;


	facecount = 0;
	rewind(stream);
	while ((fgets(s, 500, stream)) != NULL)
	{

		if (strncmp(s, "usemtl ", 7) == 0)
		{
			sscanf((s + 6), "%s", &temp);
			CurrentMatIndex = GetMatIndexFromName(theobject, temp);
		}


		if (s[0] == 'f')
		{
			hasnorm = 0;
			hastex = 0;

			numsides = 3;
			tok = strtok((s + 2), " \t\n");

			i = 0;
			ii = 0;
			while (tok != NULL)
			{
				hasnewline = GetIndices(tok, &vert[i], &norm[i], &tex[i]);

				hasnorm = norm[i] > 0;
				hastex = tex[i] > 0;

				i++;
				ii++;
				tok = strtok(NULL, " \t\n");

				if (hasnewline)
				{
					fgets(s, 500, stream);
					tok = strtok((s), " \t\n");

				}

			}

			newobject[theobject + (numobjects - objectsInFile)]->faces =
				(FACE *)realloc(newobject[theobject + (numobjects - objectsInFile)]->faces,
				(newobject[theobject + (numobjects - objectsInFile)]->numfaces + ii - 3) * sizeof(FACE));

			newobject[theobject + (numobjects - objectsInFile)]->numfaces += (ii - 3);



			// newface = (FACE *)malloc(sizeof(FACE));
			// newobject[theobject + (numobjects - objectsInFile)]->faces[facecount] = newface;
			newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].hasnorm = hasnorm;
			newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].hastex = hastex;
			newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].numsides = 3;
			newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].matindex = CurrentMatIndex;

			newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].vert[0] = vert[0] - 1;
			newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].tex[0] = tex[0] - 1;
			newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].norm[0] = norm[0] - 1;


			for (i = 0; i < 3; i++)
			{
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].vert[i] = vert[i] - 1;
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].tex[i] = tex[i] - 1;
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].norm[i] = norm[i] - 1;
			}
			facecount++;

			for (j = 0; j < ii - 3; j++) // for the extra vertexes
			{
				// newface = (FACE *)malloc(sizeof(FACE));
				// newobject[theobject + (numobjects - objectsInFile)]->faces[facecount] = newface;
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].hasnorm = hasnorm;
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].hastex = hastex;
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].numsides = 3;
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].matindex = CurrentMatIndex;

				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].vert[0] = vert[0] - 1;
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].tex[0] = tex[0] - 1;
				newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].norm[0] = norm[0] - 1;

				for (i = 0; i < 2; i++)
				{
					newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].vert[i + 1] = vert[j + 3 + i - 1] - 1;
					newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].tex[i + 1] = tex[j + 3 + i - 1] - 1;
					newobject[theobject + (numobjects - objectsInFile)]->faces[facecount].norm[i + 1] = norm[j + 3 + i - 1] - 1;
				}
				facecount++;
			}

			//    newobject[theobject + (numobjects - objectsInFile)].numfaces = facecount;
		}
	}


}

void ReleaseObj(OBJECT* aObject)
{
	if (aObject == nullptr)
	{
		return;
	}

	if (aObject->faces)free(aObject->faces);
	if (aObject->vertices)free(aObject->vertices);
	if (aObject->texturecoords)free(aObject->texturecoords);
	if (aObject->normals)free(aObject->normals);
	if (aObject->materials)free(aObject->materials);
	free(aObject);
}
