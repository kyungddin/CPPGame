#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <ctime>

static int g_nScreenIndex;
static HANDLE g_hScreen[2]; // HANDLE: Windows API에서 사용하는 객체에 대한 추상적 참조값 (직접 조작은 OS에 맡김)
int g_numofFPS;
clock_t CurTime, OldTime;   // clock_t: CPU 시간 측정값 저장 자료형
char* FPSTextInfo;
// DWORD: unsigned 4 bytes(32 bits) integer
// C에서 int, long은 플랫폼에 따라 크기가 다르지만
// DWORD는 항상 32bit를 고정적으로 보장
// DWORD는 Double WORD라서 32bit인거임 (WORD는 16bit)

void ScreenInit()
{
    /*
    typedef struct _CONSOLE_CURSOR_INFO {
        DWORD  dwSize;
        BOOL   bVisible;
    } CONSOLE_CURSOR_INFO, *PCONSOLE_CURSOR_INFO; // 변수 별명과 포인터 별명 따로
    */
    CONSOLE_CURSOR_INFO cci;

    /*
    WINBASEAPI
    HANDLE
    WINAPI
    CreateConsoleScreenBuffer(
        _In_ DWORD dwDesiredAccess,
        _In_ DWORD dwShareMode,
        _In_opt_ CONST SECURITY_ATTRIBUTES* lpSecurityAttributes,
        _In_ DWORD dwFlags,
        _Reserved_ LPVOID lpScreenBufferData
        );
    */ // 매크로 덩어리..
    // 화면 버퍼 2개를 만든다.

    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 커서를 숨긴다.
    cci.dwSize = 1;         // 커서 크기를 1로 설정
    cci.bVisible = FALSE;   // 그러나 산만하니 invisible
    SetConsoleCursorInfo(g_hScreen[0], &cci);
    SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void ScreenFlipping() // 화면 전환 함수
{
    SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
    g_nScreenIndex = !g_nScreenIndex;
}

void ScreenClear()
{
    COORD Coor = { 0, 0 }; // 좌표에 대한 구조체
    DWORD dw;              // 결과 저장 변수

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(g_hScreen[g_nScreenIndex], &csbi);

    int width = csbi.dwSize.X;
    int height = csbi.dwSize.Y;

    FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ',
        width * height, Coor, &dw);
}

void ScreenRelease() // Close Screen
{
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}

void ScreenPrint(int x, int y, char* string)
{
    DWORD dw;
    COORD CursorPosition = { x, y };
    SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
    WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

void Render()
{
    ScreenClear();

    if (CurTime - OldTime >= 1000) // 출력 코드
    {
        sprintf(FPSTextInfo, "FPS : %d", g_numofFPS);
        OldTime = CurTime;
        g_numofFPS = 0;
    }

    g_numofFPS++;
    ScreenPrint(0, 0, FPSTextInfo);
    ScreenFlipping();
}

void Release()
{
    delete[] FPSTextInfo;
}

int main()
{
    g_numofFPS = 0;
    FPSTextInfo = new char[128];
    memset(FPSTextInfo, '\0', 128);

    ScreenInit();

    OldTime = clock(); // 시간을 측정한다. 1초마다 갱신한다.

    while (1)
    {
        CurTime = clock();
        Render();
    }

    Release();
    ScreenRelease();

    return 0;
}

// https://coding-factory.tistory.com/692
