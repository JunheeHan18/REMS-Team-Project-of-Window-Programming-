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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (!CMDIChildWndEx::PreCreateWindow(cs))
		return FALSE;

	cs.style &= ~(LONG)FWS_ADDTOTITLE;
	cs.lpszName = _T("장비 유지 관리");
	return TRUE;
}

// 이거 감이 안잡히네요;아...이런걸 만약 네이버 지식인에 물어보려면 제목을 어케해야할까요 ㅋㅋㅋㅋㅋㅋㅋ ㅋㅋ.. 지식인에서 알려주나요. 이런거는 안해줄거같은데 ㅋㅋ
//저기 스플리터 안에 2,2 값이 저는 행열 갯수 설정인줄 알고 이미 탭 3개 생성되어있으니 3,3으로 했는데 그러면 바로 ㄹ에러잡더라구요 .. ㅋ.. 그ㅓㄴ데 저거는 해당 뷰 안에
// 생기는 거라서 외부에 있는거랑 상관없는거 같은데요 이거 만드신분이 봐야 알까요 ..ㅠ 이거 탭추가만 딱 하면 기능은그냥 코드 쑉쑉 느면 되는데 연락 잘 안되나요?음 어제도 물어본게 있어서 연락했는데 답장 네시간만에 왔어요
//아.. 이거때문에 진도가 안빠지니까 제 인생이 무의미 한것 같은 느낌이에요 그정돈 아니에ㅛㅋ ㅋㅋ... 원래 이런거 부딫히면 노답...왜지.. 교수님하테 여쭤보면 알까요
//번호는 있는데 카톡하고 ㅋㅋㅋㅋㅋㅋ 음.. 세부사항이라 모르실거같은데요... 무슨상황인지 설명도 못하겠어요
// 이거 내부에서 값 잘못설정해서 일부러 팅기게 하는 코드에 걸린거같네요
BOOL CCheckFrm::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: 행 및 열의 개수를 조정합니다.
		CSize(10, 10),	// TODO: 최소 창 크기를 조정합니다.
		pContext);

}
