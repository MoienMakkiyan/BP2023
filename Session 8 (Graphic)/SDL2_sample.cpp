#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <math.h>

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);
using namespace std;

int main( int argc, char * argv[] )
{
    int WW = 700;
    int LL = 1300;
    int W = 600;
    int L = 1200;
    int a = 300;
    int v1 = 2;
    int v2 = 3;
    int delay = 10;

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( LL, WW, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    window_color(m_renderer,0,0,0);
//    int x1=0;
//    int x2=1000;
//    int sign1=1;
//    int sign2=-1;
//    int i1=2;
//    int i2=3;
//    while(true)
//    {
//        rect(m_renderer,x1,120,200,200,0,55,255,1);
//        rect(m_renderer,x2,120,200,200,0,245,20,1);
//        if(abs(x1-x2)<=200)
//           {
//               if(x1-x2<0)rect(m_renderer,x2,120,200-abs(x1-x2),200,255,abs(x1-x2)*1.257,abs(x1-x2)*1.257,1);
//               if(x1-x2>0)rect(m_renderer,x1,120,200-x1+x2,200,255,abs(x1-x2)*1.257,abs(x1-x2)*1.257,1);
//           }
//        SDL_RenderPresent(m_renderer);
//        SDL_Delay(5);
//        rect(m_renderer,x1,120,200,200,0,0,0,1);
//        rect(m_renderer,x2,120,200,200,0,0,0,1);
//        x1+=(i1*sign1);
//        x2+=(i2*sign2);
//        if(x1<0||x1>1000) sign1*=-1;
//        if(x2<0||x2>1000) sign2*=-1;
//    }
    int x1 = 50;
    int x2 = L-a+50;

    int y1 = 50;
    int y2 = W-a+50;

    int sign_x1 = 1;
    int sign_y1 = 1;
    int sign_x2 = 1;
    int sign_y2 = 1;


    int color = 0;

    int RNX = 200, RNY = 200;
SDL_Event *event = new SDL_Event();

while (1)
{
    rect(m_renderer,x1,y1,a,a,0,0,255,1);
    rect(m_renderer,x2,y2,a,a,0,255,0,1);

    color = 255 - (255/(double)(a*a))*(a-abs(x1-x2))*(a-abs(y1-y2));

    if(abs(x1-x2)<a&&abs(y1-y2)<a)
    {
        if(x1-x2>0)
        {
            if(y1-y2>0)
                rect(m_renderer,x1,y1,x2+a-x1,y2+a-y1,255,color,color,1);
            else
                rect(m_renderer,x1,y2,x2+a-x1,y1+a-y2,255,color,color,1);
        }
        else
        {
            if(y1-y2>0)
                rect(m_renderer,x2,y1,x1+a-x2,y2+a-y1,255,color,color,1);
            else
                rect(m_renderer,x2,y2,x1+a-x2,y1+a-y2,255,color,color,1);

        }
    }

    SDL_RenderPresent(m_renderer);
    SDL_Delay(delay);

    rect(m_renderer,0,0,L+50,W+50,0,0,0,1);

    rect(m_renderer,0,0,50,WW,100,100,100,1);
    rect(m_renderer,L+50,0,50,WW,100,100,100,1);
    rect(m_renderer,0,0,LL,50,100,100,100,1);
    rect(m_renderer,0,W+50,LL,50,100,100,100,1);

    x1+=v1*sign_x1;
    y1+=v1*sign_y1;

    x2+=v2*sign_x2;
    y2+=v2*sign_y2;

    if(x1>L-a+50||x1<50) sign_x1*=-1;
    if(x2>L-a+50||x2<50) sign_x2*=-1;

    if(y1>W-a+50||y1<50) sign_y1*=-1;
    if(y2>W-a+50||y2<50) sign_y2*=-1;

    if( SDL_PollEvent( event ) )
        {
            if( event->type == SDL_KEYDOWN )
            {
                switch( event->key.keysym.sym )
                {
                    case SDLK_ESCAPE:
                        {
                            SDL_DestroyWindow( m_window );
                            SDL_DestroyRenderer( m_renderer );
                            IMG_Quit();
                            SDL_Quit();
                            return 0;
                        }


                }
            }
        }
    }
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
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor(Renderer,R,G,B,255);
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
}
