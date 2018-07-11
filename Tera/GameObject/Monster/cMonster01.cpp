#include "stdafx.h"
#include "cMonster01.h"

#include "SkinnedMesh\cSkinnedMesh.h"
#include "BoundingBox\cBoundingBox.h"
#include "Spere\cSpere.h"

cMonster01::cMonster01()
	: m_pMonster(NULL)
	, m_currState(MON_STATE_Wait)
{
	m_state = MON_STATE_Wait;

	//�����ִϸ��̼��� �ƴҶ�, ������ ������ �˷��ִ� ����.
	m_bIsDone = true;

	m_fCurAnimTime = 0.0f;
	m_fTime = 0.0f;
	float animTime[27] =
	{
		51, 46, 76, 76, 31,
		76, 76, 131, 1, 40,
		31, 30, 41, 41, 31,
		31, 50, 31, 50, 61,
		29, 35, 35, 66, 49,
		41, 97
	};

	memcpy(m_fAnimTime, animTime, sizeof(animTime));

	for (int i = 0; i < MON_STATE_COUNT; i++)
		m_fAnimTime[i] -= 1.0f;
	for (int i = 0; i < MON_STATE_COUNT; i++)
		m_fAnimTime[i] /= 30.0f;

	// ������ ó�� �ҰŴ�
	m_bIsBlend = true;
}


cMonster01::~cMonster01()
{
	SAFE_DELETE(m_pMonster);
}

void cMonster01::Setup()
{
	cMonster::Setup();

	m_pMonster = new cSkinnedMesh;
	m_pMonster->Setup("XFile/Monster", "Moster01.X");
	m_pMonster->SetAnimationIndexBlend(m_currState);

	// ��ġ�� ���� ��Ʈ ��
	m_pDummyRoot = (ST_BONE*)D3DXFrameFind(m_pMonster->GetFrame(),
		"Dummy_root");
}

void cMonster01::Update()
{
	if (KEYMANAGER->IsOnceKeyDown('5'))
	{
		int a = 10;
	}
	temp = *g_vPlayerPos - m_vPosition;
	if (D3DXVec3Length(&temp) > 36.0f)
	{
		// u���� -> ���غ���
		D3DXVECTOR3 u = D3DXVECTOR3(1, 0, 0);
		D3DXVECTOR3 v;
		D3DXVec3Normalize(&v, &temp);

		m_fCosVal = D3DXVec3Dot(&v, &u);
		m_fCosVal = acosf(m_fCosVal);

		if (u.z < g_vPlayerPos->z)
			m_fCosVal = D3DX_PI * 2 - m_fCosVal;

	}
	m_fRotY = m_fCosVal;

	// �ִϸ��̼� ����
	if (m_currState != m_state)
	{
		if (m_bIsBlend)
		{
			m_pMonster->SetAnimationIndexBlend(m_state);

		}
		else
		{
			m_pMonster->SetAnimationIndex(m_state);

		}

		m_currState = m_state;

		m_pMonster->AnimAdvanceTime();


		m_fTime += TIMEMANAGER->GetEllapsedTime();
	}

	// �̵����� �ִ� �ִϸ��̼��� ������Ʈ��
	// �ִϸ��̼� ��ŸƮ ������ ���忡�� ���� ������Ʈ
	// �ƴϸ� ���ó�� ����� ���忡�� ������Ʈ
	if (isUseLocalAnim())
	{
		m_pMonster->Update(m_matAnimWorld);

	}
	else
	{
		m_pMonster->Update(m_matWorld);

	}

	// �̵����� �ִ� �ִϸ��̼� ���� ��
	// �ִϸ��̼� ������ ���� ���������� �����Ű�� �������� ��� 
	m_vBeforeAnimPos = m_vCurAnimPos;
	m_vCurAnimPos = D3DXVECTOR3(m_pDummyRoot->TransformationMatrix._41, 0, 0);


	//D3DXMATRIX matR, matT;
	D3DXMATRIX mat, matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);
	D3DXVec3TransformNormal(&m_vDirection, &D3DXVECTOR3(1, 0, 0), &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);


	m_matWorld = matR * matT;

	//����

	cMonster::Update();

	cGameObject::Update();
}

void cMonster01::Render()
{
	//g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);

	m_pMonster->Render(NULL);

	char szTemp[1024];
	sprintf_s(szTemp, 1024, "length : %f", D3DXVec3Length(&temp));
	RECT rc;
	SetRect(&rc, 20, 0, 200, 100);

	LPD3DXFONT pFont = FONTMANAGER->GetFont(cFontManager::FT_DEFAULT);
	pFont->DrawTextA(NULL,
		szTemp,
		strlen(szTemp),
		&rc,
		DT_LEFT | DT_VCENTER,
		D3DCOLOR_XRGB(255, 255, 0));

	cGameObject::Render();
}

bool cMonster01::isUseLocalAnim()
{
	if (
		m_state == MON_STATE_atk04
		)
		return true;

	if (m_vCurAnimPos.x - m_vBeforeAnimPos.x > 30.0f)
	{
		m_vCurAnimPos = D3DXVECTOR3(0, 0, 0);
		m_vBeforeAnimPos = D3DXVECTOR3(0, 0, 0);
		return true;
	}

	return false;
}

void cMonster01::SetAnimWorld()
{
	// �̵����� �ִ� �ִϸ��̼��� ��ŸƮ ���� ��Ʈ������ ����
	D3DXMATRIX matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);
	D3DXVec3TransformNormal(&m_vDirection, &D3DXVECTOR3(1, 0, 0), &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matAnimWorld = matR * matT;

	m_matWorld = matR * matT;;
}

//���ʹ� ���ݵ����� �����Ƿ� �����Ѵ�.
void cMonster01::ProcessCombo()
{
}

//���Ͱ� �������� �Ծ����� �����ִ� �ൿ����
void cMonster01::ProcessDamaged()
{
}

void cMonster01::ProcessBigDamaged()
{
}

void cMonster01::ProcessDie()
{
}

void cMonster01::Move()
{
}

void cMonster01::Damaged()
{
}

void cMonster01::BigDamaged()
{
}

void cMonster01::Die()
{
}