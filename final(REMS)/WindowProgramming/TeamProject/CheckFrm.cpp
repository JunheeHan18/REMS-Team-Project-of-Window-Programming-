#include "stdafx.h"
#include "CheckFrm.h"
#include "TeamProject.h"
// CInfoManageFrm

IMPLEMENT_DYNCREATE(CCheckFrm, CMDIChildWndEx)


CCheckFrm::CCheckFrm()
{
}


CCheckFrm::~CCheckFrm()
{
}

BEGIN_MESSAGE_MAP(CCheckFrm, CMDIChildWndEx)
END_MESSAGE_MAP()



BOOL CCheckFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (!CMDIChildWndEx::PreCreateWindow(cs))
		return FALSE;

	cs.style &= ~(LONG)FWS_ADDTOTITLE;
	cs.lpszName = _T("��� ���� ����");
	return TRUE;
}

// �̰� ���� �������׿�;��...�̷��� ���� ���̹� �����ο� ������� ������ �����ؾ��ұ�� �������������� ����.. �����ο��� �˷��ֳ���. �̷��Ŵ� �����ٰŰ����� ����
//���� ���ø��� �ȿ� 2,2 ���� ���� �࿭ ���� �������� �˰� �̹� �� 3�� �����Ǿ������� 3,3���� �ߴµ� �׷��� �ٷ� ����������󱸿� .. ��.. �פä��� ���Ŵ� �ش� �� �ȿ�
// ����� �Ŷ� �ܺο� �ִ°Ŷ� ������°� �������� �̰� ����ź��� ���� �˱�� ..�� �̰� ���߰��� �� �ϸ� ������׳� �ڵ� ���� ���� �Ǵµ� ���� �� �ȵǳ���?�� ������ ����� �־ �����ߴµ� ���� �׽ð����� �Ծ��
//��.. �̰Ŷ����� ������ �Ⱥ����ϱ� �� �λ��� ���ǹ� �Ѱ� ���� �����̿��� ������ �ƴϿ��ˤ� ����... ���� �̷��� �΋H���� ���...����.. ���������� ���庸�� �˱��
//��ȣ�� �ִµ� ī���ϰ� ������������ ��.. ���λ����̶� �𸣽ǰŰ�������... ������Ȳ���� ���� ���ϰھ��
// �̰� ���ο��� �� �߸������ؼ� �Ϻη� �ñ�� �ϴ� �ڵ忡 �ɸ��Ű��׿�
BOOL CCheckFrm::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: �� �� ���� ������ �����մϴ�.
		CSize(10, 10),	// TODO: �ּ� â ũ�⸦ �����մϴ�.
		pContext);

}
