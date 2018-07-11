#include "stdafx.h"
#include "cItemBase.h"

#include "XMesh\cXLoader.h"
#include "XMesh\cXMesh.h"

#include "BoundingBox\cBoundingBox.h"


cItemBase::cItemBase()
	: m_sName(NULL)
	, m_pBody(NULL)
{
	D3DXMatrixIdentity(&m_matWorld);
}


cItemBase::~cItemBase()
{
	SAFE_DELETE(m_sName);
	SAFE_DELETE(m_pBody);
}

void cItemBase::Setup()
{
}

void cItemBase::Update()
{
	m_pBoundingBox->SetWorld(m_matWorld);

	cGameObject::Update();
}

void cItemBase::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	m_pBody->Render();
	
	cGameObject::Render();
}
