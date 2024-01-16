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
    int n;
    cout<<"Enter n:";
    cin>>n;

    int WW = 700;
    int LL = 700;

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

    int L = 500;
    int start = 100;
    for(int i = 0; i <= n; i++)
    {
        aalineRGBA(m_renderer, start, start + i * L / n, start + i * L / n, start+L, 255, 255, 255, 255);
        SDL_RenderPresent( m_renderer );
        SDL_Delay(20);
    }

    int RNX = 200, RNY = 200;
    SDL_Event *event = new SDL_Event();

while (1)
{
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



void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor(Renderer,R,G,B,255);
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
}
