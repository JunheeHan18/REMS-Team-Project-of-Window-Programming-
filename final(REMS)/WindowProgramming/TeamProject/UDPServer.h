#pragma once

// CUDPServer ��� ����Դ�

#include "TabEventLog.h"

class CTabEventLog;

class CUDPServer : public CAsyncSocket
{
public:
	CUDPServer();
	virtual ~CUDPServer();
	virtual void OnReceive(int nErrorCode);
	void GetDialog(CTabEventLog* pThis);
	CTabEventLog* m_pThis;
};

