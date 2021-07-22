#pragma once
#include "stdafx.h"
using namespace std;
class worker
{
public:
	string NAME, ID, GENDER, BIRTHDAY, DEPAERTID;
	worker();
	~worker();
	void CreatePage();
	void Add();
	void Delete();
	void Modify();
	void Query();
};

