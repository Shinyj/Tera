#pragma once
class iMap
{
public:
	virtual bool GetHeight(IN float x, OUT float& y, IN float z) = 0;
};