#include "stdafx.h"
#include "cCharacter.h"
#include "ProgressBar\cProgressBar.h"
#include "Sprite\cSprite.h"

cCharacter::cCharacter()
	: m_fRotY(0.0f)
	, m_vDirection(1, 0, 0)
	, m_vPosition(0, 0, 0)
	, m_fSpeed(1.0f)
	, m_vBeforeAnimPos(0,0,0)
	, m_vCurAnimPos(0, 0, 0)
	, m_fHpMax(300.0f)
	, m_fHpCur(300.0f)
	, m_fMpMax(150.0f)
	, m_fMpCur(150.0f)
	, m_pHpBar(NULL)
	, m_pMpBar(NULL)
	, m_BackBar(NULL)
{
	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matAnimWorld);
}


cCharacter::~cCharacter()
{
	SAFE_DELETE(m_pHpBar);
	SAFE_DELETE(m_pMpBar);
	SAFE_DELETE(m_BackBar);
}

void cCharacter::Setup()
{

	m_BackBar = TEXTUREMANAGER->GetSprite("Texture/CharacterInfo/CharacterInfo.png");
	
	m_pHpBar = new cProgressBar;
	m_pHpBar->Setup("Texture/CharacterInfo/HP.png",
		"Texture/CharacterInfo/HPLose.png",
		10,10,WINSIZEX / 3.0f, WINSIZEY/30.0f);

	m_pMpBar = new cProgressBar;
	m_pMpBar->Setup("Texture/CharacterInfo/MP.png",
		"Texture/CharacterInfo/MPLose.png",
		10, 10 + WINSIZEY / 30.0f, WINSIZEX / 3.0f, WINSIZEY / 30.0f);
}

void cCharacter::Update()
{
	m_pHpBar->SetGauge(m_fHpCur, m_fHpMax);
	m_pMpBar->SetGauge(m_fMpCur, m_fMpMax);

}

void cCharacter::Render()
{
	m_BackBar->Render(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(20, 20, 0));
	m_pHpBar->Render();
	m_pMpBar->Render();
}
