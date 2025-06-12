// RPG_Project.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "RPG_Project.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

HWND hWnd;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void BackBuffer(HDC hdc);

Player* player = new Player(50);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_RPGPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RPGPROJECT));

   // MSG msg;
   //
   // // 기본 메시지 루프입니다:
   // while (GetMessage(&msg, nullptr, 0, 0))
   // {
   //     if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
   //     {
   //         TranslateMessage(&msg);
   //         DispatchMessage(&msg);
   //     }
   // }
   //
   // return (int) msg.wParam;

    MSG msg;
    ZeroMemory(&msg, sizeof(msg)); // msg 구조체 초기화

    while (msg.message != WM_QUIT) // WM_QUIT 메시지가 오기 전까지 반복
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) // 메시지가 있는지 확인
        {
            TranslateMessage(&msg); // 키보드 입력 메시지 변환
            DispatchMessage(&msg);  // 윈도우 프로시저로 메시지 전달
        }
        else // 메시지가 없을 때!
        {
            // ====== 여기에서 게임 상태 업데이트! ======
            // Player 객체의 Update 함수 호출
           // player->Render(hdc);
            player->Update(); // 예시 코드, 실제 객체 이름에 맞게 수정

            // 다른 게임 오브젝트들 (총알, 몬스터 등)의 Update 함수도 여기서 호출

            // 화면 다시 그리기 요청 (필요하다면)
            // InvalidateRect(hWnd, nullptr, true); // Player::Update에서 옮겨왔다면 여기서 호출
            // =======================================
        }
    }


}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RPGPROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_RPGPROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

      hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      300, 250, ScreenWidth, ScreenHeight, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
   // case WM_CREATE:
   // {
   //     player = new Player(50);
   // }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            Rectangle(hdc, 0, ScreenHeight -100, ScreenWidth, ScreenWidth);
           // Rectangle(hdc, 0, 0,100,100);
            BackBuffer(hdc);
            player->Render(hdc);
          
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
    {
       // player->Update();
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


void BackBuffer(HDC hdc)
{
    PAINTSTRUCT ps;
     hdc = BeginPaint(hWnd, &ps); // 화면 DC를 얻어와 (유리창 그림 도구)

    // TODO: 여기에 그리기 코드를 넣지 마세요.
    // 대신 아래 임시 DC에 그리세요.

    // 1. 임시 그림판(메모리 DC) 만들기
    HDC hdc_mem = CreateCompatibleDC(hdc); // 화면 DC와 호환되는 임시 DC 생성 (도화지 그림 도구)

    // 2. 임시 도화지(비트맵) 만들기
    RECT clientRect;
    GetClientRect(hWnd, &clientRect); // 윈도우 클라이언트 영역 크기 얻기
    int width = clientRect.right - clientRect.left;
    int height = clientRect.bottom - clientRect.top;

    HBITMAP hBitmap = CreateCompatibleBitmap(hdc, width, height); // 임시 도화지(비트맵) 생성 (화면 크기와 같게)

    // 3. 임시 도화지를 임시 그림 도구에 끼워 넣기
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdc_mem, hBitmap); // 임시 DC에 비트맵 선택 (원래 비트맵 저장)

    // 4. 임시 도화지에 그림 그리기 (여기서 모든 그리기 작업 수행!)
    // 배경을 흰색으로 지우기 (또는 원하는 배경색/이미지 그리기)
    FillRect(hdc_mem, &clientRect, (HBRUSH)GetStockObject(WHITE_BRUSH));

    // TODO: 여기에 게임 오브젝트들 그리기 코드를 넣으세요.
    // 예시: Player 객체 그리기
    // player.Render(hdc_mem); // player 객체가 있고 Render 함수가 있다고 가정

    // 예시: 바닥 그리기
    // RECT groundRect = { 0, groundY, width, height }; // groundY는 바닥 Y 좌표
    // FillRect(hdc_mem, &groundRect, (HBRUSH)GetStockObject(GRAY_BRUSH)); // 회색 바닥 그리기

    // 예시: 총알들 그리기 (총알 풀링 사용 시)
    // bulletManager.Render(hdc_mem); // bulletManager 객체가 있고 Render 함수가 있다고 가정
    // ========================================================

    // 5. 완성된 그림을 화면으로 한 번에 복사 (BitBlt 사용)
    BitBlt(hdc, 0, 0, width, height, hdc_mem, 0, 0, SRCCOPY); // 임시 DC 내용을 화면 DC로 고속 복사

    // 6. 뒷정리 (임시 도구와 도화지 정리)
    SelectObject(hdc_mem, hOldBitmap); // 임시 DC에 원래 비트맵 되돌리기
    DeleteObject(hBitmap); // 임시 비트맵 삭제
    DeleteDC(hdc_mem); // 임시 DC 삭제

    EndPaint(hWnd, &ps); // 화면 DC 사용 끝
}