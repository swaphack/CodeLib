#include "ModelDetailFbx.h"
#include "../extensions.h"
#include "Base/macros.h"
#include "MaterialDetail.h"
#include "MeshDetail.h"

using namespace sys;

void handNode(ModelDetailFbx* file, FbxNode* node);
void handNodeMesh(ModelDetailFbx* file, FbxNode* node);
void handNodeMaterial(ModelDetailFbx* file, FbxNode* node);

void handMaterial(ModelDetailFbx* file, FbxSurfaceMaterial* mat);
void handMaterialTexture(ModelDetailFbx* file, FbxSurfaceMaterial* mat, int textureIndex);

void handNode(ModelDetailFbx* file, FbxNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	//PRINT("Node Name:%s Type:%s\n", node->GetName(), node->GetTypeName());

	handNodeMesh(file, node);
	handNodeMaterial(file, node);
	
	int nCount = node->GetChildCount();

	//PRINT("Node Child Count:%d\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		handNode(file, node->GetChild(i));
	}
}

void handNodeMesh(ModelDetailFbx* file, FbxNode* node)
{
	auto pMeshData = node->GetMesh();
	if (pMeshData == nullptr)
	{
		return;
	}
	auto pMesh = CREATE_OBJECT(MeshDetail);
	pMesh->setName(node->GetName());
	int meshCount = file->getMeshes().size();
	file->addMesh(node->GetName(), pMesh);

	int nPolygonCount = pMeshData->GetPolygonCount();
	//ASSERT(nPolygonCount <= 1);

	int nPointCount = pMeshData->GetControlPointsCount();
	if (nPointCount > 0)
	{
		FbxVector4* lControlPoints = pMeshData->GetControlPoints();

		float* verticeData = (float*)pMesh->createVertices(nPointCount, sizeof(float), 3);

		for (int i = 0; i < nPointCount; i++)
		{
			float pos[3] = { 0 };
			pos[0] = (float)lControlPoints[i].mData[0];
			pos[1] = (float)lControlPoints[i].mData[1];
			pos[2] = (float)lControlPoints[i].mData[2];
			memcpy(verticeData + 3 * i, pos, 3 * sizeof(float));
		}
	}


	int nNormalCount = pMeshData->GetElementNormalCount();
	if (nNormalCount > 0)
	{
		ASSERT(nNormalCount == 1);

		FbxGeometryElementNormal* leNormal = pMeshData->GetElementNormal(0);
		auto vector = leNormal->GetDirectArray();

		int nVerticeCount = vector.GetCount();
		float* normalData = (float*)pMesh->createNormals(nVerticeCount, sizeof(float), 3);

		for (int i = 0; i < nVerticeCount; i++)
		{
			float pos[3] = { 0 };
			pos[0] = (float)vector.GetAt(i).mData[0];
			pos[1] = (float)vector.GetAt(i).mData[1];
			pos[2] = (float)vector.GetAt(i).mData[2];
			memcpy(normalData + 3 * i, pos, 3 * sizeof(float));
		}
	}

	int nTangentCount = pMeshData->GetElementTangentCount();
	if (nTangentCount > 0)
	{
		ASSERT(nTangentCount == 1);

		FbxGeometryElementTangent* leTangent = pMeshData->GetElementTangent(0);
		auto vector = leTangent->GetDirectArray();

		int nVerticeCount = vector.GetCount();
		float* normalData = (float*)pMesh->createTangents(nVerticeCount, sizeof(float), 3);

		for (int i = 0; i < nVerticeCount; i++)
		{
			float pos[3] = { 0 };
			pos[0] = (float)vector.GetAt(i).mData[0];
			pos[1] = (float)vector.GetAt(i).mData[1];
			pos[2] = (float)vector.GetAt(i).mData[2];
			memcpy(normalData + 3 * i, pos, 3 * sizeof(float));
		}
	}

	int nBitangentCount = pMeshData->GetElementBinormalCount();
	if (nBitangentCount > 0)
	{
		ASSERT(nBitangentCount == 1);

		FbxGeometryElementBinormal* leBinormal = pMeshData->GetElementBinormal(0);
		auto vector = leBinormal->GetDirectArray();

		int nVerticeCount = vector.GetCount();
		float* normalData = (float*)pMesh->createBitangents(nVerticeCount, sizeof(float), 3);

		for (int i = 0; i < nVerticeCount; i++)
		{
			float pos[3] = { 0 };
			pos[0] = (float)vector.GetAt(i).mData[0];
			pos[1] = (float)vector.GetAt(i).mData[1];
			pos[2] = (float)vector.GetAt(i).mData[2];
			memcpy(normalData + 3 * i, pos, 3 * sizeof(float));
		}
	}

	int nUVCount = pMeshData->GetElementUVCount();
	if (nUVCount > 0)
	{
		ASSERT(nUVCount == 1);

		FbxGeometryElementUV* leUV = pMeshData->GetElementUV(0);
		auto vector = leUV->GetDirectArray();

		int nVerticeCount = vector.GetCount();
		float* uvData = (float*)pMesh->createUVs(nVerticeCount, sizeof(float), 2);

		for (int i = 0; i < nVerticeCount; i++)
		{
			float pos[2] = { 0 };
			pos[0] = (float)vector.GetAt(i).mData[0];
			pos[1] = (float)vector.GetAt(i).mData[1];
			memcpy(uvData + 2 * i, pos, 2 * sizeof(float));
		}
	}

	
	int nColorCount = pMeshData->GetElementVertexColorCount();
	if (nColorCount > 0)
	{
		ASSERT(nColorCount == 1);

		FbxGeometryElementVertexColor* leVtxc = pMeshData->GetElementVertexColor(0);
		auto vector = leVtxc->GetDirectArray();

		int nVerticeCount = vector.GetCount();
		float* colorData = (float*)pMesh->createColors(nVerticeCount, sizeof(float), 4);

		for (int i = 0; i < nVerticeCount; i++)
		{
			float pos[4] = { 0 };
			pos[0] = (float)vector.GetAt(i).mRed;
			pos[1] = (float)vector.GetAt(i).mGreen;
			pos[2] = (float)vector.GetAt(i).mBlue;
			pos[3] = (float)vector.GetAt(i).mAlpha;
			memcpy(colorData + 4 * i, pos, 4 * sizeof(float));
		}
	}
	else
	{
		float* colorData = (float*)pMesh->createColors(nPointCount, sizeof(float), 4);

		for (int i = 0; i < nPointCount; i++)
		{
			float pos[4] = { 0 };
			pos[0] = 1.0f;
			pos[1] = 1.0f;
			pos[2] = 1.0f;
			pos[3] = 1.0f;
			memcpy(colorData + 4 * i, pos, 4 * sizeof(float));
		}
	}

	int nIndexCount = pMeshData->GetPolygonVertexCount();
	uint32_t* indices = (uint32_t*)pMesh->createIndices(nIndexCount, sizeof(uint32_t), 1);
	for (int i = 0; i < nIndexCount; i++)
	{
		indices[i] = pMeshData->GetPolygonVertices()[i];
	}

	int nMatCount = pMeshData->GetElementMaterialCount();
	if (nMatCount > 0)
	{
		ASSERT(nMatCount == 1);
		FbxGeometryElementMaterial* pMaterialElement = pMeshData->GetElementMaterial(0);
		FbxSurfaceMaterial* lMaterial = node->GetMaterial(pMaterialElement->GetIndexArray().GetAt(0));
		pMesh->setMaterial(lMaterial->GetName());
	}

	{
		FbxAMatrix& mat = node->EvaluateLocalTransform();

		const FbxVector4& pT = mat.GetT();
		const FbxVector4& pR = mat.GetR();
		const FbxVector4& pS = mat.GetS();

		FbxAMatrix nmat(pT, pR, pS);


		double* value = (double*)nmat;

		float v[16] = { 0 };
		for (int i = 0; i < 16; i++)
		{
			v[i] = value[i];
		}
		math::Matrix4x4 m(v);
		pMesh->setMatrix(m);
	}
}

void handNodeMaterial(ModelDetailFbx* file, FbxNode* node)
{
	int nMatCount = node->GetMaterialCount();
	for (int i = 0; i < nMatCount; i++)
	{
		FbxSurfaceMaterial *mat = node->GetMaterial(i);
		if (mat)
		{
			PRINT("FBX MATERIAL Name : %s\n", mat->GetName());
			handMaterial(file, mat);
			int lTextureIndex = 0;
			FBXSDK_FOR_EACH_TEXTURE(lTextureIndex)
			{
				handMaterialTexture(file, mat, lTextureIndex);
			}
		}
	}
}

void handMaterial(ModelDetailFbx* file, FbxSurfaceMaterial* mat)
{
	FbxPropertyT<FbxDouble3> lKFbxDouble3;
	FbxPropertyT<FbxDouble> lKFbxDouble1;
	FbxColor theColor;

	const FbxImplementation* lImplementation = GetImplementation(mat, FBXSDK_IMPLEMENTATION_HLSL);
	FbxString lImplemenationType = "HLSL";
	if (!lImplementation)
	{
		lImplementation = GetImplementation(mat, FBXSDK_IMPLEMENTATION_CGFX);
		lImplemenationType = "CGFX";
	}
	if (lImplementation)
	{
		//Now we have a hardware shader, let's read it
		PRINT("            Hardware Shader Type: %s\n", lImplemenationType.Buffer());
		const FbxBindingTable* lRootTable = lImplementation->GetRootTable();
		FbxString lFileName = lRootTable->DescAbsoluteURL.Get();
		FbxString lTechniqueName = lRootTable->DescTAG.Get();


		const FbxBindingTable* lTable = lImplementation->GetRootTable();
		size_t lEntryNum = lTable->GetEntryCount();

		for (int i = 0; i < (int)lEntryNum; ++i)
		{
			const FbxBindingTableEntry& lEntry = lTable->GetEntry(i);
			const char* lEntrySrcType = lEntry.GetEntryType(true);
			FbxProperty lFbxProp;


			FbxString lTest = lEntry.GetSource();
			PRINT("            Entry: %s\n", lTest.Buffer());


			if (strcmp(FbxPropertyEntryView::sEntryType, lEntrySrcType) == 0)
			{
				lFbxProp = mat->FindPropertyHierarchical(lEntry.GetSource());
				if (!lFbxProp.IsValid())
				{
					lFbxProp = mat->RootProperty.FindHierarchical(lEntry.GetSource());
				}


			}
			else if (strcmp(FbxConstantEntryView::sEntryType, lEntrySrcType) == 0)
			{
				lFbxProp = lImplementation->GetConstants().FindHierarchical(lEntry.GetSource());
			}
			if (lFbxProp.IsValid())
			{
				if (lFbxProp.GetSrcObjectCount<FbxTexture>() > 0)
				{
					//do what you want with the textures
					for (int j = 0; j < lFbxProp.GetSrcObjectCount<FbxFileTexture>(); ++j)
					{
						FbxFileTexture *lTex = lFbxProp.GetSrcObject<FbxFileTexture>(j);
						PRINT("           File Texture: %s\n", lTex->GetFileName());
					}
					for (int j = 0; j < lFbxProp.GetSrcObjectCount<FbxLayeredTexture>(); ++j)
					{
						FbxLayeredTexture *lTex = lFbxProp.GetSrcObject<FbxLayeredTexture>(j);
						PRINT("        Layered Texture: %s\n", lTex->GetName());
					}
					for (int j = 0; j < lFbxProp.GetSrcObjectCount<FbxProceduralTexture>(); ++j)
					{
						FbxProceduralTexture *lTex = lFbxProp.GetSrcObject<FbxProceduralTexture>(j);
						PRINT("     Procedural Texture: %s\n", lTex->GetName());
					}
				}
				else
				{
					FbxDataType lFbxType = lFbxProp.GetPropertyDataType();
					FbxString blah = lFbxType.GetName();

					if (FbxBoolDT == lFbxType)
					{
						//DisplayBool("                Bool: ", lFbxProp.Get<FbxBool>());
					}
					else if (FbxIntDT == lFbxType || FbxEnumDT == lFbxType)
					{
						//DisplayInt("                Int: ", lFbxProp.Get<FbxInt>());
					}
					else if (FbxFloatDT == lFbxType)
					{
						//DisplayDouble("                Float: ", lFbxProp.Get<FbxFloat>());

					}
					else if (FbxDoubleDT == lFbxType)
					{
						//DisplayDouble("                Double: ", lFbxProp.Get<FbxDouble>());
					}
					else if (FbxStringDT == lFbxType
						|| FbxUrlDT == lFbxType
						|| FbxXRefUrlDT == lFbxType)
					{
						//DisplayString("                String: ", lFbxProp.Get<FbxString>().Buffer());
					}
					else if (FbxDouble2DT == lFbxType)
					{
						FbxDouble2 lDouble2 = lFbxProp.Get<FbxDouble2>();
						FbxVector2 lVect;
						lVect[0] = lDouble2[0];
						lVect[1] = lDouble2[1];

						//Display2DVector("                2D vector: ", lVect);
					}
					else if (FbxDouble3DT == lFbxType || FbxColor3DT == lFbxType)
					{
						FbxDouble3 lDouble3 = lFbxProp.Get<FbxDouble3>();


						FbxVector4 lVect;
						lVect[0] = lDouble3[0];
						lVect[1] = lDouble3[1];
						lVect[2] = lDouble3[2];
						//Display3DVector("                3D vector: ", lVect);
					}

					else if (FbxDouble4DT == lFbxType || FbxColor4DT == lFbxType)
					{
						FbxDouble4 lDouble4 = lFbxProp.Get<FbxDouble4>();
						FbxVector4 lVect;
						lVect[0] = lDouble4[0];
						lVect[1] = lDouble4[1];
						lVect[2] = lDouble4[2];
						lVect[3] = lDouble4[3];
						//Display4DVector("                4D vector: ", lVect);
					}
					else if (FbxDouble4x4DT == lFbxType)
					{
						FbxDouble4x4 lDouble44 = lFbxProp.Get<FbxDouble4x4>();
						for (int j = 0; j < 4; ++j)
						{

							FbxVector4 lVect;
							lVect[0] = lDouble44[j][0];
							lVect[1] = lDouble44[j][1];
							lVect[2] = lDouble44[j][2];
							lVect[3] = lDouble44[j][3];
							//Display4DVector("                4x4D vector: ", lVect);
						}
					}
				}
			}
		}
	}
	else if (mat->GetClassId().Is(FbxSurfacePhong::ClassId))
	{
		auto it = file->getMaterial(mat->GetName());
		if (it != nullptr)
		{
			return;
		}
		FbxSurfacePhong* phong = (FbxSurfacePhong *)mat;
		auto pMat = CREATE_OBJECT(MaterialDetail);
		pMat->setName(phong->GetName());
		pMat->setEmission((float)phong->Emissive.Get()[0], (float)phong->Emissive.Get()[1], (float)phong->Emissive.Get()[2]);
		pMat->setAmbient((float)phong->Ambient.Get()[0], (float)phong->Ambient.Get()[1], (float)phong->Ambient.Get()[2]);
		pMat->setDiffuse((float)phong->Diffuse.Get()[0], (float)phong->Diffuse.Get()[1], (float)phong->Diffuse.Get()[2]);
		pMat->setSpecular((float)phong->Specular.Get()[0], (float)phong->Specular.Get()[1], (float)phong->Specular.Get()[2]);
		pMat->setSpecularShiness((float)phong->Shininess.Get());
		file->addMaterial(phong->GetName(), pMat);
	}
	else if (mat->GetClassId().Is(FbxSurfaceLambert::ClassId))
	{
		auto it = file->getMaterial(mat->GetName());
		if (it != nullptr)
		{
			return;
		}

		FbxSurfaceLambert* lambert = (FbxSurfaceLambert *)mat;
		auto pMat = CREATE_OBJECT(MaterialDetail);
		pMat->setName(lambert->GetName());
		pMat->setEmission((float)lambert->Emissive.Get()[0], (float)lambert->Emissive.Get()[1], (float)lambert->Emissive.Get()[2]);
		pMat->setAmbient((float)lambert->Ambient.Get()[0], (float)lambert->Ambient.Get()[1], (float)lambert->Ambient.Get()[2]);
		pMat->setDiffuse((float)lambert->Diffuse.Get()[0], (float)lambert->Diffuse.Get()[1], (float)lambert->Diffuse.Get()[2]);
		pMat->setEmission((float)lambert->Emissive.Get()[0], (float)lambert->Emissive.Get()[1], (float)lambert->Emissive.Get()[2]);
		file->addMaterial(lambert->GetName(), pMat);
	}
	else if (mat->GetClassId().Is(FbxSurfaceMaterial::ClassId))
	{
		auto it = file->getMaterial(mat->GetName());
		if (it != nullptr)
		{
			return;
		}

		FbxSurfaceMaterial* material = (FbxSurfaceMaterial*)mat;
		auto pMat = CREATE_OBJECT(MaterialDetail);
		pMat->setName(material->GetName());
		//pMat->setEmission((float)material->Emissive.Get()[0], (float)material->Emissive.Get()[1], (float)material->Emissive.Get()[2]);
		//pMat->setAmbient((float)material->Ambient.Get()[0], (float)material->Ambient.Get()[1], (float)material->Ambient.Get()[2]);
		//pMat->setDiffuse((float)material->Diffuse.Get()[0], (float)material->Diffuse.Get()[1], (float)material->Diffuse.Get()[2]);
		//pMat->setEmission((float)material->Emissive.Get()[0], (float)material->Emissive.Get()[1], (float)material->Emissive.Get()[2]);
		file->addMaterial(material->GetName(), pMat);
	}
}

void handMaterialTexture(ModelDetailFbx* file, FbxSurfaceMaterial* mat, int textureIndex)
{
	auto pProperty = mat->FindProperty(FbxLayerElement::sTextureChannelNames[textureIndex]);
	if (!pProperty.IsValid())
	{
		return;
	}

	int lTextureCount = pProperty.GetSrcObjectCount<FbxTexture>();
	if (lTextureCount == 0)
	{
		return;
	}
	auto pMat = file->getMaterial(mat->GetName());

	for (int j = 0; j < lTextureCount; ++j)
	{
		//Here we have to check if it's layeredtextures, or just textures:
		FbxLayeredTexture *lLayeredTexture = pProperty.GetSrcObject<FbxLayeredTexture>(j);
		if (lLayeredTexture)
		{
			int lNbTextures = lLayeredTexture->GetSrcObjectCount<FbxTexture>();
			for (int k = 0; k < lNbTextures; ++k)
			{
				FbxTexture* lTexture = lLayeredTexture->GetSrcObject<FbxTexture>(k);
				if (lTexture)
				{
					FbxFileTexture *lFileTexture = FbxCast<FbxFileTexture>(lTexture);
					if (lFileTexture)
					{
						//PRINT("Fbx LayeredTexture Path :%s\n", lFileTexture->GetFileName());
					}
				}

			}
		}
		else
		{
			FbxTexture* lTexture = pProperty.GetSrcObject<FbxTexture>(j);
			if (lTexture)
			{
				FbxFileTexture *lFileTexture = FbxCast<FbxFileTexture>(lTexture);
				if (lFileTexture)
				{
					if (lFileTexture->GetFileName() == nullptr || strlen(lFileTexture->GetFileName()) == 0)
					{
						continue;
					}
					std::string fullpath = lFileTexture->GetFileName();
					std::string name = lFileTexture->GetRelativeFileName();
					if (fullpath.empty())
					{
						continue;
					}
					file->addTexturePath(name, fullpath);
// 					Texture2D* textureID = file->createTexture(fullpath);
// 					if (textureID == nullptr)
// 					{
// 						continue;
// 					}
// 
// 					file->addTexture(name, textureID);

					if (j == 0)
					{
						pMat->setAmbientTextureMap(name);
					}
					else if (j == 1)
					{
						pMat->setDiffuseTextureMap(name);
					}
					else
					{
						int a = 1;
					}
				}
			}
		}
	}
}

static FbxManager* lSdkManager = nullptr;


ModelDetailFbx::ModelDetailFbx()
{
}

ModelDetailFbx::~ModelDetailFbx()
{

}


bool ModelDetailFbx::load(const std::string& fullpath)
{
	if (fullpath.empty())
	{
		return false;
	}
	// Initialize the SDK manager. This object handles all our memory management.
	if (lSdkManager == nullptr)
	{
		lSdkManager = FbxManager::Create();
	}
	

	// Create the IO settings object.
	FbxIOSettings *ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
	lSdkManager->SetIOSettings(ios);

	// Create an importer using the SDK manager.
	FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

	// Use the first argument as the filename for the importer.
	if (!lImporter->Initialize(fullpath.c_str(), -1, lSdkManager->GetIOSettings())) {
		PRINT("Call to FbxImporter::Initialize() failed.\n");
		PRINT("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
		return false;
	}

	// Create a new scene so that it can be populated by the imported file.
	FbxScene* lScene = FbxScene::Create(lSdkManager, "myScene");

	// Import the contents of the file into the scene.
	lImporter->Import(lScene);

	FbxNode* lRootNode = lScene->GetRootNode();
	if (lRootNode)
	{
		handNode(this, lRootNode);
	}

	// The file is imported; so get rid of the importer.
	lImporter->Destroy();

	//lSdkManager->Destroy();

	return true;
}