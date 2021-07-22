#pragma once
#include "stdafx.h"
using namespace std;
class department
{
public:
	string NAME,REMARKS, ID, SENIORID;
	department();
	~department();
	void CreatePage();
	void Add();
	void Delete();
	void Modify();
	void Query();

};

