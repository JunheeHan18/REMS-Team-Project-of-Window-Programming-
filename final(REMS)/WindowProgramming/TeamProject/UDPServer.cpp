// UDPServer.cpp : 구현 파일입니다.
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


// CUDPServer 멤버 함수


void CUDPServer::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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
