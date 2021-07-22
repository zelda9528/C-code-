#pragma once
#include "stdafx.h"
using namespace std;
class attendence
{
public:
	string NAME, START, END, NORSTART, NOREND, DATE; 
	attendence();
	~attendence();
	void CreatePage();
	void Add();
	void Delete();
	void Modify();
	void Query();
	
};

