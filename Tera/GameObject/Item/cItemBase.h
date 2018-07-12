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

	ST_PNT_VERTEX		m_arrPos[50];
	int					m_nIndex;
	float				m_fTime;

	D3DXVECTOR3			m_vOnPos;
	D3DXVECTOR3			m_vDownPos;

	vector<ST_PNT_VERTEX>	m_vecVertex;

public:
	cItemBase();
	virtual~cItemBase();

	virtual void Setup();
	virtual void Update();
	virtual void Render();

};


