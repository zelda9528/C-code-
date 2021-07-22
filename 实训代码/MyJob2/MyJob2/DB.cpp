#include "stdafx.h"
#include "DB.h"
using namespace adosql;

AdoCenter::AdoCenter()
{
	HRESULT hr = CoInitialize(NULL);
	if (SUCCEEDED(hr))
	{
		connect();
	}
	else
	{
		cout << "数据库载入失败!!!" << endl;
	}
}

AdoCenter::~AdoCenter()
{

}

bool AdoCenter::connect()
{
	if (NULL == m_pConn || adStateClosed == m_pConn->State)
	{
		try
		{  //Connecting

			if (!FAILED(m_pConn.CreateInstance(_uuidof(Connection))))  
			{
				m_pConn->CommandTimeout = 30;                 

				if (!FAILED(m_pConn->Open("DSN=550;server=localhost;database=mydb", "root", "", adModeUnknown)))
				{
					return true;
				}
			}
		}
		catch (_com_error e)
		{
			cout << "数据库载入失败!!!" << endl;
		}
	}
	return false;
}

bool AdoCenter::reConnect()
{
	long  reConnectTimes = 0;
	while (true)
	{
		++reConnectTimes;
		cout << "连接出错" << endl;
		Sleep(2000);
		m_pConn = NULL;
		if (connect())
		{
			return true;
		}
	}
	return false;
}


int AdoCenter::selectData(const string& sql, vector<string>& results)
{
	int ret = -1;

	if (sql.size() > 0)
	{
		if (NULL == m_pConn || adStateClosed == m_pConn->State)
		{
			reConnect();
		}

		try
		{
			_variant_t RefreshNum;
			_RecordsetPtr pRecordset = m_pConn->Execute(_bstr_t(sql.c_str()), &RefreshNum, adCmdText);
			long line = 0;
			while (NULL != pRecordset && !pRecordset->EndOfFile && adStateClosed != pRecordset->State)
			{
				long count = pRecordset->Fields->Count;
				++line;
				stringstream ss;
				ss << line;
				for (long i = 0; i < count; ++i)
				{
					_variant_t rusultGet = pRecordset->Fields->GetItem(long(i))->Value;

					char midData[MAXCHAR] = { 0 };
					rusultGet.ChangeType(VT_BSTR);
					WideCharToMultiByte(CP_ACP, 0, rusultGet.bstrVal, -1, midData, MAXCHAR, NULL, NULL);
					ss << "," << midData;
				}
				results.emplace_back(ss.str());
				pRecordset->MoveNext();
			}
			pRecordset = NULL;
			ret = 0;
		}
		catch (_com_error e)
		{
			string errorInfo(e.Description());
			if (errorInfo.find("DBNETLIB") != string::npos)
			{
				if (reConnect())
				{
					ret = selectData(sql, results);//再次执行
				}
				if (ret != 0)
				{
					cout << "连接出错" << endl;
				}
			}
		}
	}
	return ret;
}

int AdoCenter::executeSql(const string& sql)
{
	int ret = -1;

	if (sql.size() > 0)
	{
		if (NULL == m_pConn || adStateClosed == m_pConn->State)
		{
			connect();
		}

		try
		{
			_variant_t RefreshNum;
			m_pConn->Execute(_bstr_t(sql.c_str()), &RefreshNum, adCmdText);
			ret = 0;
		}
		catch (_com_error e)
		{
			cout << "连接出错" << endl;
		}
	}
	return ret;
}