#pragma once
#include "../cGameObject.h"

class cMonster : public cGameObject
{
public:
	float			m_fRotY;
	D3DXVECTOR3		m_vDirection;
	D3DXMATRIX		m_matWorld;

	float			m_fSpeed;

	//iMap*			m_pMap;

	float			m_fCosVal; // ī�޶� ���� ����

	//�̰͵� ��ġ�غ�����~ ��~

	float a;

	D3DXMATRIX		m_matAnimWorld;
	D3DXVECTOR3		m_vCurAnimPos;
	D3DXVECTOR3		m_vBeforeAnimPos;

	float			m_fHpMax;
	float			m_fHpCur;
	float			m_fHpUI;

	float			m_fMpMax;
	float			m_fMpCur;
	float			m_fMpUI;



public:
	SYNTHESIZE(D3DXVECTOR3, m_vPosition, Position);

public:
	cMonster();
	~cMonster();

	void Setup();
	void Update();
	void Render();
};

