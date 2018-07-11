#pragma once
#include "../cGameNode.h"

class cCharaPopori;
class cDummyObj;
class cSprite;

class cSceneTest : public cGameNode
{
private :

	cSprite*			m_pBackGroundBlack;
	int					m_nBGBlackAlpha;
	cCharaPopori*		m_pPopori;
	cDummyObj*			m_pDummy;

public:
	cSceneTest();
	~cSceneTest();

	void Setup();
	void Update();
	void Render();
};

