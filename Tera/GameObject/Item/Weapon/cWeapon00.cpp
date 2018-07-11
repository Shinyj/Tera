#include "stdafx.h"
#include "cWeapon00.h"

#include "XMesh\cXLoader.h"
#include "XMesh\cXMesh.h"
#include "BoundingBox\cBoundingBox.h"


cWeapon00::cWeapon00()
{
}


cWeapon00::~cWeapon00()
{
	SAFE_DELETE(m_sName);
	SAFE_DELETE(m_pBody);
}

void cWeapon00::Setup()
{
	cXLoader loader;
	m_pBody = loader.xFimeLoad("XFile/Item/Weapon/TwoHandSword_00.X");
	//iceSword
	//TwoHand00_SM
	//TwoHandSword_02
	// TwoHandSword_03
	// TwoHandSword_04
	m_pBoundingBox = new cBoundingBox;
	m_pBoundingBox->Setup(
		D3DXVECTOR3(-5,-10,-5),
		D3DXVECTOR3(5, 50, 5));
}

void cWeapon00::Update()
{
	cItemBase::Update();
}

void cWeapon00::Rendeer()
{
	cItemBase::Render();
	//g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	//m_pBody->Render();
}
