// UDPServer.cpp : ���� �����Դϴ�.
//

#include "TabEventLog.h"
#include "stdafx.h"
#include "TeamProject.h"
#include "UDPServer.h"
#include "TabEventLog.h"
#include "ChildFrm.h"
#include "MainFrm.h"

// CUDPServer


CUDPServer::CUDPServer()
	: m_pThis(NULL)
{
}

CUDPServer::~CUDPServer()
{
}


// CUDPServer ��� �Լ�


void CUDPServer::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CString ip;
	UINT port;
	TCHAR sBuf[1024];
	ReceiveFrom(sBuf, 1024, ip, port);

	m_pThis->ReceiveUpdate(sBuf);

	CAsyncSocket::OnReceive(nErrorCode);
}


void CUDPServer::GetDialog(CTabEventLog* pThis)
{
	m_pThis = (CTabEventLog*)pThis;
}
