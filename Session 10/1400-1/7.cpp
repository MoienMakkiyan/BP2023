#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfx.h>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;

typedef struct point
{
    int xp, yp;
};
void turnPoints(point *P, int angle) // turns 4 points relative to center
{
    int xm = (P[0].xp + P[1].xp + P[2].xp + P[3].xp) / 4, ym = (P[0].yp + P[1].yp + P[2].yp + P[3].yp) / 4;
    for (int i = 0; i < 4; i++)
    {
        int tempX = P[i].xp, tempY = P[i].yp;
        P[i].xp = xm + (tempX - xm) * cos(M_PI * angle / 180.0) - (tempY - ym) * sin(M_PI * angle / 180.0);
        P[i].yp = ym + (tempX - xm) * sin(M_PI * angle / 180.0) + (tempY - ym) * cos(M_PI * angle / 180.0);
    }
}
void hilbert(int x, int y, int L, int n, SDL_Renderer *renderer, int angle)
{
    point P[4];
    P[1 - 1].xp = x;
    P[1 - 1].yp = y;
    P[2 - 1].xp = x;
    P[2 - 1].yp = y + L;
    P[3 - 1].xp = x + L;
    P[3 - 1].yp = y + L;
    P[4 - 1].xp = x + L;
    P[4 - 1].yp = y;
    turnPoints(P, angle);
    if (n == 0)
    {
        aalineColor(renderer, P[0].xp, P[0].yp, P[1].xp, P[1].yp, 0xFFFFFFFF);
        aalineColor(renderer, P[1].xp, P[1].yp, P[2].xp, P[2].yp, 0xFFFFFFFF);
        aalineColor(renderer, P[2].xp, P[2].yp, P[3].xp, P[3].yp, 0xFFFFFFFF);
    }
    else
    {
        float alpha = 1 / float((1 << n+1) - 1 );
        int Lprim = L * alpha;
        int size = L/2 - Lprim/2;
        hilbert(x, y,size, n - 1, renderer, angle-90);
        aalineColor(renderer,x,y + L/2 - Lprim/2,x, y + L/2 + Lprim/2,0xFFFFFFFF);
        hilbert(x, y + L - size,size, n - 1, renderer, angle);
        aalineColor(renderer , x +  L/2 - Lprim/2 , y + L - Lprim , x + L/2 + Lprim/2 , y + L - Lprim , 0xFFFFFFFF);
        hilbert(x + L - size, y + L -size,size, n - 1, renderer, angle);
        aalineColor(renderer ,  x + L  , y + L/2 - Lprim/2 , x + L, y +L/2 + Lprim/2 , 0xFFFFFFFF);
        hilbert(x + L - size, y,size, n - 1, renderer, angle + 90);
    }
}
int main(int argc, char *argv[])
{
    int n;
    cin>>n;

    /*fstream input;
    input.open("input.txt" , ios::in);
    string xs , ys , Ls , ns;
    int x , y , L , n;
    getline(input , xs);
    getline(input , ys);
    getline(input , Ls);
    getline(input , ns);
    input.close();*/
    // Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP; // SDL_WINDOW_BORDERLESS ;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(1920, 480, WND_flags, &m_window, &m_renderer);
    // Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    // Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    // Clear the window with a black background
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    // Show the window
    hilbert(100, 100, 400, n, m_renderer, 0);
    SDL_RenderPresent(m_renderer);
    // Wait for a key to be pressed
    SDL_Event *e = new SDL_Event();
    while (e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);
    // Finalize and free resources
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    return 0;
}

