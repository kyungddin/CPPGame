## Code Structure
- /header
    - Point.h
    - Direction.h
    - Game.h
    - Snake.h
    - Food.h

- /source
    - main.cpp
    - Game.cpp
    - Snake.cpp
    - Food.cpp


## Point & Direction
- Point: 구조체를 사용해서 x,y 좌표값을 저장
- Direction: enum class를 사용해서 상하좌우 구현


## 2. Snake Class
- 목표: 움직이는 뱀의 정보

- 클래스 멤버
    - private
        - 뱀의 머리
        - 뱀의 몸체
        - 뱀의 길이

    - public
        - 생성자: 뱀 초기화
        - 소멸자: vector는 소멸자에서 어떻게 처리해주지?


## 3. Food Class


## 4. Game Class (Main Class)
- 목표: 게임 엔진 구현

- 전역 상수: ROW, COL (extern const 사용, Game.cpp에서 정의)

- 클래스 멤버


## Note
1. 2차원 배열 크기의 경우 "컴파일 타임 상수"로만 지정 가능하다

2. extern을 쓰는 전역 상수의 경우 링킹 에러가 발생할 수도 있다. 다른 방법을 강구할 것.
    - constexpr를 상수에 써주면 컴파일 타임에서 전역 상수가 가능하므로 매우 강력하다
    - 또한, 컴파일 타임 상수이므로, 메모리를 차지 않는 "값"이기에 여러 파일에 중복되어도 문제 X
    - constexpr는 경우의 수에 분기가 발생하므로.. 충분히 공부하고 사용할 것..!
