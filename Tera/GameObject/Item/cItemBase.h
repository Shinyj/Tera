#pragma once
#include "GameObject/cGameObject.h"

class cXMesh;
class cBoundingBox;

class cItemBase : public cGameObject
{
protected :

	SYNTHESIZE(D3DXMATRIX, m_matWorld, World);

	char *			m_sName;
	cXMesh*			m_pBody;

public:
	cItemBase();
	virtual~cItemBase();

	virtual void Setup();
	virtual void Update();
	virtual void Render();

};


