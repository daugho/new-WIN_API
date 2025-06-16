// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#define SCREEN_START1 300
#define SCREEN_START2 250
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 600
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
using namespace std;
extern HWND hWnd;
#include <vector>

#include "utill/float2.h"
#include "Object/Circle.h"
#include "Object/Player.h"
#include "Object/Bullet.h"
#include "Manager/GameManager.h"
