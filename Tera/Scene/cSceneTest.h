#pragma once
#include "../cGameNode.h"

class cCharaPopori;
class cDummyObj;
class cSprite;
class cMonster01;

class cSceneTest : public cGameNode
{
private :

	cSprite*			m_pBackGroundBlack;
	int					m_nBGBlackAlpha;
	cCharaPopori*		m_pPopori;
	cDummyObj*			m_pDummy;

	cMonster01*			m_pMonster01;

public:
	cSceneTest();
	~cSceneTest();

	void Setup();
	void Update();
	void Render();
};

