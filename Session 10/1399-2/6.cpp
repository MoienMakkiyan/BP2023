#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include<fstream>


using namespace std;

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );

struct Point{
    int x;
    int y;
};


int main( int argc, char * argv[] )
{
    ifstream in;
    Point points[100];
    int n, penalty=0;
    in.open("input.txt");
    if(in.good())
    {
        in>>n;
        for(int i=0;i<n;i++)
            in>>points[i].x>>points[i].y;
    }

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;


    int img_w, img_h;
    SDL_Rect img_rect;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 480, 360, WND_flags, &m_window, &m_renderer );

    SDL_RaiseWindow(m_window);

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;

    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    SDL_RenderPresent( m_renderer );


    int a=10, rad=5;
    rect(m_renderer,points[0].x-a,points[0].y-a/2,10,10,0,255,0,1);
    SDL_RenderPresent( m_renderer );
    SDL_Delay(250);

    for (int i=0; i<n-1; i++)
    {
        aalineRGBA(m_renderer, points[i].x, points[i].y, points[i+1].x, points[i+1].y, 255, 255, 255, 255);
        SDL_RenderPresent( m_renderer );
        SDL_Delay(150);
        if(i>0){
            int x1=points[i].x-points[i-1].x, y1=points[i].y-points[i-1].y;
            int x2=points[i+1].x-points[i].x, y2=points[i+1].y-points[i].y;
            int cross = x2*y1 - x1*y2;
            if(cross > 0){
                filledCircleRGBA(m_renderer,points[i].x,points[i].y,rad,255,0,0,255);
                penalty += 10;
            }
        }
    }

    rect(m_renderer,points[n-1].x-a,points[n-1].y-a/2,10,10,0,0,255,1);
    SDL_RenderPresent( m_renderer );

    char s[5];
    sprintf(s, "%d", penalty);
    stringRGBA(m_renderer,10,10,s,255,255,255,255);
    SDL_RenderPresent(m_renderer);


    SDL_Event *e = new SDL_Event();
    e->type = 0;

    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);

    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

}

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;


    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian==1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
    SDL_RenderPresent(Renderer);

}


