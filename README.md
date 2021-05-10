<h1>갓 cpp로 만드는 콘솔 엔진!</h1>
<br>

<h1> 예제 </h1>

    Screen screen(Vector2(400, 400), "example");

    screen.SetConsole();

    for (int i = 0; i < 400; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            screen.SetPixelInScreen(Vector2(j, i), 255 * i / 400);
            screen.SetPixelInScreen(Vector2(i, j), 255 * i / 400);
        }
    }
    screen.DrawScreen();

    Sleep(5000);

    screen.ResetConsole();

<br>

<ul>
  <li><h1> Screen.h </h1> </li>
  
  
  <h2> Screen(const Vector2 size, const char* const title) </h2>
  <h5> 타이틀이 title인 size 크기의 콘솔의 생성을 예약한다. </h5>
  <br>
  
  <h2> SetConsole() </h2>
  <h5> Screen의 정보에 따른 콘솔을 생성한다. </h5>
  <br>
  
  <h2> ResetConsole() </h2>
  <h5> 콘솔을 복귀시킨다. (꼭 있어야한다.) </h5>
  <br>
  
  <h2> GetScreenSize() </h2>
  <h5> return type : const Vector2 </h5>
  <h5> 콘솔에 예약된 size를 반환한다. </h5>
  <br>
  
  <h2> ReSize(const Vector2 size) </h2>
  <h5> 콘솔에 예약된 크기를 size로 바꾼다. </h5>
  <h5> SetConsole() 함수를 호출해야한다. </h5>
  <br>
  
  <h2> SetPixelInScreen(const Vector2 position, const WORD color) </h2>
  <h5> 스크린의 position 위치에 color 값을 초기화한다.  </h5>
  <br>
  
  <h2> GetPixelInScreen(const Vector2 position) </h2>
  <h5> return type : const WORD </h5>
  <h5> 스크린의 position 위치에 있는 color 값을 반환한다.  </h5>
  <br>
  
  <h2> DrawScreen() </h2>
  <h5> 콘솔에 스크린을 그린다. </h5>
  <br>
  
  <li><h2> Vector2.h </h2> </li>
  
  
  <h2> Vector2::zero </h2> : static
  <h5> Vector2(0, 0) 의 값을 가진다. </h5>
  <br>
  
  <h2> Vector2::one </h2> : static
  <h5> Vector2(1, 1) 의 값을 가진다. </h5>
  <br>
  
  <h2> GetDistance(Vector2 target) </h2>
  <h5> return type : float </h5>
  <h5> 해당 벡터와 target의 거리를 반환한다. </h5>
  <br>
  
  <h2> GetLine(Vector2 target) </h2>
  <h5> return type : std::vector<Vector2> </h5>
  <h5> 해당 벡터와 target까지의 모든 벡터의 열을 반환한다. </h5>
  <br>
  
  <h2> Vector2::GetMeshTriangle(std::array<Vector2, 3>& triangle) </h2> : static
  <h5> return type : std::vector<Vector2> </h5>
  <h5> 세 점에 대한 면에 해당하는 벡터의 열이 반환된다. </h5>
  <br>
  
  <h2> Vector2::GetWireFrameTriangle(std::array<Vector2, 3>& triangle) </h2> : static
  <h5> return type : std::vector<Vector2> </h5>
  <h5> 세 점에 대한 선에 해당하는 벡터의 열이 반환된다. </h5>
  <br>
  
</ul>
