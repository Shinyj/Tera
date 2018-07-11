#pragma once

#define FONTMANAGER cFontManager::GetInstance()

class cFontManager
{
public:
	enum eFontType // UI �� ��ġ�� ���¿� ���� ����ϴ� ��Ʈ�� �ٸ�
	{
		FT_DEFAULT,
		FT_QUEST
	};

	SINGLETONE(cFontManager);

	map<eFontType, LPD3DXFONT> m_mapFont;

public:
	// ����ų� ������� ������ ������ (Ÿ�Կ� ���� )
	LPD3DXFONT GetFont(eFontType type);
	void Destroy();
};

// ����

/*
char szTemp[1024];
RECT rc;
SetRect(&rc,100,100,200,100);
LPD#DXFONT pFont = g_pFontManager->GetFont(cFontManager::FT_DEFAULT);
pFont->DrawText(NULL,szTemp,strlen(szTemp),&rc,
DT_LEFT| DT_CENTER| DT_NOCLIP,
D3DCOLOR_XRGB(255,0,255));

*/