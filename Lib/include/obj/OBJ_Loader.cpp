#include "OBJ_Loader.h"

bool objl::Vector2::operator!=(const Vector2& other) const
{
	return !(this->X == other.X && this->Y == other.Y);
}

bool objl::Vector2::operator==(const Vector2& other) const
{
	return (this->X == other.X && this->Y == other.Y);
}

objl::Vector2::Vector2(float X_, float Y_)
{
	X = X_;
	Y = Y_;
}

objl::Vector2::Vector2()
{
	X = 0.0f;
	Y = 0.0f;
}

objl::Vector2 objl::Vector2::operator+(const Vector2& right) const
{
	return Vector2(this->X + right.X, this->Y + right.Y);
}

objl::Vector2 objl::Vector2::operator-(const Vector2& right) const
{
	return Vector2(this->X - right.X, this->Y - right.Y);
}

objl::Vector2 objl::Vector2::operator*(const float& other) const
{
	return Vector2(this->X *other, this->Y * other);
}

//////////////////////////////////////////////////////////////////////////
bool objl::Vector3::operator!=(const Vector3& other) const
{
	return !(this->X == other.X && this->Y == other.Y && this->Z == other.Z);
}

bool objl::Vector3::operator==(const Vector3& other) const
{
	return (this->X == other.X && this->Y == other.Y && this->Z == other.Z);
}

objl::Vector3::Vector3(float X_, float Y_, float Z_)
{
	X = X_;
	Y = Y_;
	Z = Z_;
}

objl::Vector3::Vector3()
{
	X = 0.0f;
	Y = 0.0f;
	Z = 0.0f;
}

objl::Vector3 objl::Vector3::operator+(const Vector3& right) const
{
	return Vector3(this->X + right.X, this->Y + right.Y, this->Z + right.Z);
}

objl::Vector3 objl::Vector3::operator-(const Vector3& right) const
{
	return Vector3(this->X - right.X, this->Y - right.Y, this->Z - right.Z);
}

objl::Vector3 objl::Vector3::operator*(const float& other) const
{
	return Vector3(this->X * other, this->Y * other, this->Z * other);
}

objl::Vector3 objl::Vector3::operator/(const float& other) const
{
	return Vector3(this->X / other, this->Y / other, this->Z / other);
}

//////////////////////////////////////////////////////////////////////////


objl::Mesh::Mesh(const std::vector<Vertex>& _Vertices, const std::vector<unsigned int>& _Indices)
{
	Vertices = _Vertices;
	Indices = _Indices;
}

objl::Mesh::Mesh()
{

}

//////////////////////////////////////////////////////////////////////////


objl::Vector3 objl::math::CrossV3(const Vector3& a, const Vector3& b)
{
	return Vector3(a.Y * b.Z - a.Z * b.Y,
		a.Z * b.X - a.X * b.Z,
		a.X * b.Y - a.Y * b.X);
}

float objl::math::MagnitudeV3(const Vector3& in)
{
	return (sqrtf(powf(in.X, 2) + powf(in.Y, 2) + powf(in.Z, 2)));
}

float objl::math::DotV3(const Vector3& a, const Vector3& b)
{
	return (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z);
}

float objl::math::AngleBetweenV3(const Vector3& a, const Vector3& b)
{
	float angle = DotV3(a, b);
	angle /= (MagnitudeV3(a) * MagnitudeV3(b));
	return angle = acosf(angle);
}

objl::Vector3 objl::math::ProjV3(const Vector3& a, const Vector3& b)
{
	Vector3 bn = b / MagnitudeV3(b);
	return bn * DotV3(a, bn);
}

//////////////////////////////////////////////////////////////////////////


objl::Vector3 objl::algorithm::operator*(const float& left, const Vector3& right)
{
	return Vector3(right.X * left, right.Y * left, right.Z * left);
}

bool objl::algorithm::SameSide(const Vector3& p1, const Vector3& p2, const Vector3& a, const Vector3& b)
{
	Vector3 cp1 = math::CrossV3(b - a, p1 - a);
	Vector3 cp2 = math::CrossV3(b - a, p2 - a);

	if (math::DotV3(cp1, cp2) >= 0)
		return true;
	else
		return false;
}

objl::Vector3 objl::algorithm::GenTriNormal(const Vector3& t1, const Vector3& t2, const Vector3& t3)
{
	Vector3 u = t2 - t1;
	Vector3 v = t3 - t1;

	Vector3 normal = math::CrossV3(u, v);

	return normal;
}

bool objl::algorithm::inTriangle(const Vector3& point, const Vector3& tri1, const Vector3& tri2, const Vector3& tri3)
{
	// Test to see if it is within an infinite prism that the triangle outlines.
	bool within_tri_prisim = SameSide(point, tri1, tri2, tri3) && SameSide(point, tri2, tri1, tri3)
		&& SameSide(point, tri3, tri1, tri2);

	// If it isn't it will never be on the triangle
	if (!within_tri_prisim)
		return false;

	// Calulate Triangle's Normal
	Vector3 n = GenTriNormal(tri1, tri2, tri3);

	// Project the point onto this normal
	Vector3 proj = math::ProjV3(point, n);

	// If the distance from the triangle to the point is 0
	//	it lies on the triangle
	if (math::MagnitudeV3(proj) == 0)
		return true;
	else
		return false;
}

void objl::algorithm::split(const std::string &in, std::vector<std::string> &out, const std::string& token)
{
	out.clear();

	std::string temp;

	for (int i = 0; i < int(in.size()); i++)
	{
		std::string test = in.substr(i, token.size());

		if (test == token)
		{
			if (!temp.empty())
			{
				out.push_back(temp);
				temp.clear();
				i += (int)token.size() - 1;
			}
			else
			{
				out.push_back("");
			}
		}
		else if (i + token.size() >= in.size())
		{
			temp += in.substr(i, token.size());
			out.push_back(temp);
			break;
		}
		else
		{
			temp += in[i];
		}
	}
}

std::string objl::algorithm::firstToken(const std::string &in)
{
	if (!in.empty())
	{
		size_t token_start = in.find_first_not_of(" \t");
		size_t token_end = in.find_first_of(" \t", token_start);
		if (token_start != std::string::npos && token_end != std::string::npos)
		{
			return in.substr(token_start, token_end - token_start);
		}
		else if (token_start != std::string::npos)
		{
			return in.substr(token_start);
		}
	}
	return "";
}

objl::Loader::Loader()
{

}

objl::Loader::~Loader()
{
	LoadedMeshes.clear();
}

bool objl::Loader::LoadFile(std::string Path)
{
	// If the file is not an .obj file return false
	if (Path.substr(Path.size() - 4, 4) != ".obj")
		return false;


	std::ifstream file(Path);

	if (!file.is_open())
		return false;

	LoadedMeshes.clear();
	//LoadedVertices.clear();
	//LoadedIndices.clear();

	std::vector<Vector3> Positions;
	std::vector<Vector2> TCoords;
	std::vector<Vector3> Normals;

	std::vector<Vertex> Vertices;
	std::vector<unsigned int> Indices;

	std::vector<std::string> MeshMatNames;

	bool listening = false;
	std::string meshname;

	Mesh tempMesh;

#ifdef OBJL_CONSOLE_OUTPUT
	const unsigned int outputEveryNth = 1000;
	unsigned int outputIndicator = outputEveryNth;
#endif

	std::string curline;
	while (std::getline(file, curline))
	{
#ifdef OBJL_CONSOLE_OUTPUT
		if ((outputIndicator = ((outputIndicator + 1) % outputEveryNth)) == 1)
		{
			if (!meshname.empty())
			{
				std::cout
					<< "\r- " << meshname
					<< "\t| vertices > " << Positions.size()
					<< "\t| texcoords > " << TCoords.size()
					<< "\t| normals > " << Normals.size()
					<< "\t| triangles > " << (Vertices.size() / 3)
					<< (!MeshMatNames.empty() ? "\t| material: " + MeshMatNames.back() : "");
			}
		}
#endif

		// Generate a Mesh Object or Prepare for an object to be created
		auto firstToken = algorithm::firstToken(curline);
		auto tailLine = algorithm::tail(curline);
		if (firstToken == "o" || firstToken == "g" || curline[0] == 'g')
		{
			if (!listening)
			{
				listening = true;

				if (firstToken == "o" || firstToken == "g")
				{
					meshname = tailLine;
				}
				else
				{
					meshname = "unnamed";
				}
			}
			else
			{
				// Generate the mesh to put into the array

				if (!Indices.empty() && !Vertices.empty())
				{
					// Create Mesh
					tempMesh = Mesh(Vertices, Indices);
					tempMesh.MeshName = meshname;

					// Insert Mesh
					LoadedMeshes.push_back(tempMesh);

					// Cleanup
					Vertices.clear();
					Indices.clear();
					meshname.clear();

					meshname = tailLine;
				}
				else
				{
					if (firstToken == "o" || firstToken == "g")
					{
						meshname = tailLine;
					}
					else
					{
						meshname = "unnamed";
					}
				}
			}
#ifdef OBJL_CONSOLE_OUTPUT
			std::cout << std::endl;
			outputIndicator = 0;
#endif
		}
		// Generate a Vertex Position
		else if (firstToken == "v")
		{
			std::vector<std::string> spos;
			Vector3 vpos;
			algorithm::split(tailLine, spos, " ");

			vpos.X = std::stof(spos[0]);
			vpos.Y = std::stof(spos[1]);
			vpos.Z = std::stof(spos[2]);

			Positions.push_back(vpos);
		}
		// Generate a Vertex Texture Coordinate
		else if (firstToken == "vt")
		{
			std::vector<std::string> stex;
			Vector2 vtex;
			algorithm::split(tailLine, stex, " ");

			vtex.X = std::stof(stex[0]);
			vtex.Y = std::stof(stex[1]);

			TCoords.push_back(vtex);
		}
		// Generate a Vertex Normal;
		else if (firstToken == "vn")
		{
			std::vector<std::string> snor;
			Vector3 vnor;
			algorithm::split(tailLine, snor, " ");

			vnor.X = std::stof(snor[0]);
			vnor.Y = std::stof(snor[1]);
			vnor.Z = std::stof(snor[2]);

			Normals.push_back(vnor);
		}
		// Generate a Face (vertices & indices)
		else if (firstToken == "f")
		{
			// Generate the vertices
			std::vector<Vertex> vVerts;
			GenVerticesFromRawOBJ(vVerts, Positions, TCoords, Normals, tailLine);

			// Add Vertices
			/*
			for (int i = 0; i < int(vVerts.size()); i++)
			{
				Vertices.push_back(vVerts[i]);

				//LoadedVertices.push_back(vVerts[i]);
			}
			*/
			Vertices.insert(Vertices.end(), vVerts.begin(), vVerts.end());

			std::vector<unsigned int> iIndices;

			VertexTriangluation(iIndices, vVerts);

			// Add Indices
			for (int i = 0; i < int(iIndices.size()); i++)
			{
				unsigned int indnum = (unsigned int)((Vertices.size()) - vVerts.size()) + iIndices[i];
				Indices.push_back(indnum);

				//indnum = (unsigned int)((LoadedVertices.size()) - vVerts.size()) + iIndices[i];
				//LoadedIndices.push_back(indnum);
			}
		}
		// Get Mesh Material Name
		else if (firstToken == "usemtl")
		{
			MeshMatNames.push_back(tailLine);

			// Create new Mesh, if Material changes within a group
			if (!Indices.empty() && !Vertices.empty())
			{
				// Create Mesh
				tempMesh = Mesh(Vertices, Indices);
				tempMesh.MeshName = meshname;
				int i = 2;
				while (1) {
					tempMesh.MeshName = meshname + "_" + std::to_string(i);

					for (auto &m : LoadedMeshes)
						if (m.MeshName == tempMesh.MeshName)
							continue;
					break;
				}

				// Insert Mesh
				LoadedMeshes.push_back(tempMesh);

				// Cleanup
				Vertices.clear();
				Indices.clear();
			}

#ifdef OBJL_CONSOLE_OUTPUT
			outputIndicator = 0;
#endif
		}
		// Load Materials
		else if (firstToken == "mtllib")
		{
			// Generate LoadedMaterial

			// Generate a path to the material file
			std::vector<std::string> temp;
			algorithm::split(Path, temp, "/");

			std::string pathtomat = "";

			if (temp.size() != 1)
			{
				for (int i = 0; i < temp.size() - 1; i++)
				{
					pathtomat += temp[i] + "/";
				}
			}


			pathtomat += tailLine;

#ifdef OBJL_CONSOLE_OUTPUT
			std::cout << std::endl << "- find materials in: " << pathtomat << std::endl;
#endif

			// Load Materials
			LoadMaterials(pathtomat);
		}
	}

#ifdef OBJL_CONSOLE_OUTPUT
	std::cout << std::endl;
#endif

	// Deal with last mesh

	if (!Indices.empty() && !Vertices.empty())
	{
		// Create Mesh
		tempMesh = Mesh(Vertices, Indices);
		tempMesh.MeshName = meshname;

		// Insert Mesh
		LoadedMeshes.push_back(tempMesh);
	}

	file.close();

	// Set Materials for each Mesh
	for (int i = 0; i < MeshMatNames.size(); i++)
	{
		std::string matname = MeshMatNames[i];

		// Find corresponding material name in loaded materials
		// when found copy material variables into mesh material
		for (int j = 0; j < LoadedMaterials.size(); j++)
		{
			if (LoadedMaterials[j].name == matname)
			{
				LoadedMeshes[i].MeshMaterial = LoadedMaterials[j];
				break;
			}
		}
	}

	if (LoadedMeshes.empty()/* && LoadedVertices.empty() && LoadedIndices.empty()*/)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void objl::Loader::GenVerticesFromRawOBJ(std::vector<Vertex>& oVerts, const std::vector<Vector3>& iPositions, const std::vector<Vector2>& iTCoords, const std::vector<Vector3>& iNormals, const std::string& icurline)
{
	std::vector<std::string> sface, svert;
	Vertex vVert;
	algorithm::split(icurline, sface, " ");

	bool noNormal = false;

	// For every given vertex do this
	for (int i = 0; i < int(sface.size()); i++)
	{
		// See What type the vertex is.
		int vtype;

		algorithm::split(sface[i], svert, "/");

		// Check for just position - v1
		if (svert.size() == 1)
		{
			// Only position
			vtype = 1;
		}

		// Check for position & texture - v1/vt1
		if (svert.size() == 2)
		{
			// Position & Texture
			vtype = 2;
		}

		// Check for Position, Texture and Normal - v1/vt1/vn1
		// or if Position and Normal - v1//vn1
		if (svert.size() == 3)
		{
			if (svert[1] != "")
			{
				// Position, Texture, and Normal
				vtype = 4;
			}
			else
			{
				// Position & Normal
				vtype = 3;
			}
		}

		// Calculate and store the vertex
		switch (vtype)
		{
		case 1: // P
		{
			vVert.Position = algorithm::getElement(iPositions, svert[0]);
			vVert.TextureCoordinate = Vector2(0, 0);
			noNormal = true;
			oVerts.push_back(vVert);
			break;
		}
		case 2: // P/T
		{
			vVert.Position = algorithm::getElement(iPositions, svert[0]);
			vVert.TextureCoordinate = algorithm::getElement(iTCoords, svert[1]);
			noNormal = true;
			oVerts.push_back(vVert);
			break;
		}
		case 3: // P//N
		{
			vVert.Position = algorithm::getElement(iPositions, svert[0]);
			vVert.TextureCoordinate = Vector2(0, 0);
			vVert.Normal = algorithm::getElement(iNormals, svert[2]);
			oVerts.push_back(vVert);
			break;
		}
		case 4: // P/T/N
		{
			vVert.Position = algorithm::getElement(iPositions, svert[0]);
			vVert.TextureCoordinate = algorithm::getElement(iTCoords, svert[1]);
			vVert.Normal = algorithm::getElement(iNormals, svert[2]);
			oVerts.push_back(vVert);
			break;
		}
		default:
		{
			break;
		}
		}
	}

	// take care of missing normals
	// these may not be truly acurate but it is the 
	// best they get for not compiling a mesh with normals	
	if (noNormal)
	{
		Vector3 A = oVerts[0].Position - oVerts[1].Position;
		Vector3 B = oVerts[2].Position - oVerts[1].Position;

		Vector3 normal = math::CrossV3(A, B);

		for (int i = 0; i < int(oVerts.size()); i++)
		{
			oVerts[i].Normal = normal;
		}
	}
}

void objl::Loader::VertexTriangluation(std::vector<unsigned int>& oIndices, const std::vector<Vertex>& iVerts)
{
	// If there are 2 or less verts,
	// no triangle can be created,
	// so exit
	if (iVerts.size() < 3)
	{
		return;
	}
	// If it is a triangle no need to calculate it
	if (iVerts.size() == 3)
	{
		oIndices.push_back(0);
		oIndices.push_back(1);
		oIndices.push_back(2);
		return;
	}

	// Create a list of vertices
	std::vector<Vertex> tVerts = iVerts;

	while (true)
	{
		// For every vertex
		for (int i = 0; i < int(tVerts.size()); i++)
		{
			// pPrev = the previous vertex in the list
			Vertex pPrev;
			if (i == 0)
			{
				pPrev = tVerts[tVerts.size() - 1];
			}
			else
			{
				pPrev = tVerts[i - 1];
			}

			// pCur = the current vertex;
			Vertex pCur = tVerts[i];

			// pNext = the next vertex in the list
			Vertex pNext;
			if (i == tVerts.size() - 1)
			{
				pNext = tVerts[0];
			}
			else
			{
				pNext = tVerts[i + 1];
			}

			// Check to see if there are only 3 verts left
			// if so this is the last triangle
			if (tVerts.size() == 3)
			{
				// Create a triangle from pCur, pPrev, pNext
				for (int j = 0; j < int(tVerts.size()); j++)
				{
					if (iVerts[j].Position == pCur.Position)
						oIndices.push_back(j);
					if (iVerts[j].Position == pPrev.Position)
						oIndices.push_back(j);
					if (iVerts[j].Position == pNext.Position)
						oIndices.push_back(j);
				}

				tVerts.clear();
				break;
			}
			if (tVerts.size() == 4)
			{
				// Create a triangle from pCur, pPrev, pNext
				for (int j = 0; j < int(iVerts.size()); j++)
				{
					if (iVerts[j].Position == pCur.Position)
						oIndices.push_back(j);
					if (iVerts[j].Position == pPrev.Position)
						oIndices.push_back(j);
					if (iVerts[j].Position == pNext.Position)
						oIndices.push_back(j);
				}

				Vector3 tempVec;
				for (int j = 0; j < int(tVerts.size()); j++)
				{
					if (tVerts[j].Position != pCur.Position
						&& tVerts[j].Position != pPrev.Position
						&& tVerts[j].Position != pNext.Position)
					{
						tempVec = tVerts[j].Position;
						break;
					}
				}

				// Create a triangle from pCur, pPrev, pNext
				for (int j = 0; j < int(iVerts.size()); j++)
				{
					if (iVerts[j].Position == pPrev.Position)
						oIndices.push_back(j);
					if (iVerts[j].Position == pNext.Position)
						oIndices.push_back(j);
					if (iVerts[j].Position == tempVec)
						oIndices.push_back(j);
				}

				tVerts.clear();
				break;
			}

			// If Vertex is not an interior vertex
			float angle = math::AngleBetweenV3(pPrev.Position - pCur.Position, pNext.Position - pCur.Position) * (180 / 3.14159265359);
			if (angle <= 0 && angle >= 180)
				continue;

			// If any vertices are within this triangle
			bool inTri = false;
			for (int j = 0; j < int(iVerts.size()); j++)
			{
				if (algorithm::inTriangle(iVerts[j].Position, pPrev.Position, pCur.Position, pNext.Position)
					&& iVerts[j].Position != pPrev.Position
					&& iVerts[j].Position != pCur.Position
					&& iVerts[j].Position != pNext.Position)
				{
					inTri = true;
					break;
				}
			}
			if (inTri)
				continue;

			// Create a triangle from pCur, pPrev, pNext
			for (int j = 0; j < int(iVerts.size()); j++)
			{
				if (iVerts[j].Position == pCur.Position)
					oIndices.push_back(j);
				if (iVerts[j].Position == pPrev.Position)
					oIndices.push_back(j);
				if (iVerts[j].Position == pNext.Position)
					oIndices.push_back(j);
			}

			// Delete pCur from the list
			for (int j = 0; j < int(tVerts.size()); j++)
			{
				if (tVerts[j].Position == pCur.Position)
				{
					tVerts.erase(tVerts.begin() + j);
					break;
				}
			}

			// reset i to the start
			// -1 since loop will add 1 to it
			i = -1;
		}

		// if no triangles were created
		if (oIndices.size() == 0)
			break;

		// if no more vertices
		if (tVerts.size() == 0)
			break;
	}
}

//////////////////////////////////////////////////////////////////////////



bool objl::Loader::LoadMaterials(const std::string& path)
{
	// If the file is not a material file return false
	if (path.substr(path.size() - 4, path.size()) != ".mtl")
		return false;

	std::ifstream file(path);

	// If the file is not found return false
	if (!file.is_open())
		return false;

	Material tempMaterial;

	bool listening = false;

	// Go through each line looking for material variables
	std::string curline;
	while (std::getline(file, curline))
	{
		auto firstToken = algorithm::firstToken(curline);
		auto tailLine = algorithm::tail(curline);
		// new material and material name
		if (firstToken == "newmtl")
		{
			if (!listening)
			{
				listening = true;

				if (curline.size() > 7)
				{
					tempMaterial.name = tailLine;
				}
				else
				{
					tempMaterial.name = "none";
				}
			}
			else
			{
				// Generate the material

				// Push Back loaded Material
				LoadedMaterials.push_back(tempMaterial);

				// Clear Loaded Material
				tempMaterial = Material();

				if (curline.size() > 7)
				{
					tempMaterial.name = tailLine;
				}
				else
				{
					tempMaterial.name = "none";
				}
			}
		}
		// Ambient Color
		else if (firstToken == "Ka")
		{
			std::vector<std::string> temp;
			algorithm::split(tailLine, temp, " ");

			if (temp.size() != 3)
				continue;

			tempMaterial.Ka.X = std::stof(temp[0]);
			tempMaterial.Ka.Y = std::stof(temp[1]);
			tempMaterial.Ka.Z = std::stof(temp[2]);
		}
		// Diffuse Color
		else if (firstToken == "Kd")
		{
			std::vector<std::string> temp;
			algorithm::split(tailLine, temp, " ");

			if (temp.size() != 3)
				continue;

			tempMaterial.Kd.X = std::stof(temp[0]);
			tempMaterial.Kd.Y = std::stof(temp[1]);
			tempMaterial.Kd.Z = std::stof(temp[2]);
		}
		// Specular Color
		else if (firstToken == "Ks")
		{
			std::vector<std::string> temp;
			algorithm::split(tailLine, temp, " ");

			if (temp.size() != 3)
				continue;

			tempMaterial.Ks.X = std::stof(temp[0]);
			tempMaterial.Ks.Y = std::stof(temp[1]);
			tempMaterial.Ks.Z = std::stof(temp[2]);
		}
		// Specular Exponent
		else if (firstToken == "Ns")
		{
			tempMaterial.Ns = std::stof(tailLine);
		}
		// Optical Density
		else if (firstToken == "Ni")
		{
			tempMaterial.Ni = std::stof(tailLine);
		}
		// Dissolve
		else if (firstToken == "d")
		{
			tempMaterial.d = std::stof(tailLine);
		}
		// Illumination
		else if (firstToken == "illum")
		{
			tempMaterial.illum = std::stoi(tailLine);
		}
		// Ambient Texture Map
		else if (firstToken == "map_Ka")
		{
			tempMaterial.map_Ka = tailLine;
		}
		// Diffuse Texture Map
		else if (firstToken == "map_Kd")
		{
			tempMaterial.map_Kd = tailLine;
		}
		// Specular Texture Map
		else if (firstToken == "map_Ks")
		{
			tempMaterial.map_Ks = tailLine;
		}
		// Specular Hightlight Map
		else if (firstToken == "map_Ns")
		{
			tempMaterial.map_Ns = tailLine;
		}
		// Alpha Texture Map
		else if (firstToken == "map_d")
		{
			tempMaterial.map_d = tailLine;
		}
		// Bump Map
		else if (firstToken == "map_Bump" || firstToken == "map_bump" || firstToken == "bump")
		{
			tempMaterial.map_bump = tailLine;
		}
	}

	// Deal with last material

	// Push Back loaded Material
	LoadedMaterials.push_back(tempMaterial);

	// Test to see if anything was loaded
	// If not return false
	if (LoadedMaterials.empty())
		return false;
	// If so return true
	else
		return true;
}
