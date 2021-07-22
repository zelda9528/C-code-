// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#import "C:\Program Files (x86)\Common Files\System\ado\msado15.dll" rename("EOF", "EndOfFile")


#include "targetver.h"
#include <stdio.h>

#include<algorithm>
#include <tchar.h>
#include <iostream>
#include <typeinfo>
#include <string>
#include <assert.h>
#include<vector>

#include <sstream>
#include"attendquery.h"
#include"department.h"
#include"attendence.h"
#include"worker.h"
#include "HomePage.h"
#include"LoginPage.h"
#include "DB.h"

class administrator;
class LoginPage;
string& replace_all(string& str, const string& old_value, const string& new_value);
// TODO:  在此处引用程序需要的其他头文件
