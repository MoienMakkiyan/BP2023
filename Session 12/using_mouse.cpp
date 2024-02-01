#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <string>

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
using namespace std;

int main( int argc, char * argv[] )
{
    int W = 600;
    int L = 1200;


    int x_mouse = 0;
    int y_mouse = 0;

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    window_color(m_renderer,0,0,0);


    int RNX = 200, RNY = 200;
    SDL_Event *event = new SDL_Event();

    while (1)
    {
        filledCircleRGBA(m_renderer,x_mouse,y_mouse,25,255,0,0,255);
        SDL_RenderPresent(m_renderer);
        //filledCircleRGBA(m_renderer,x_mouse,y_mouse,25,0,0,0,255);
        cout<<"x_mouse = "<<x_mouse<<"\t\t y_mouse = "<<y_mouse<<endl;
        if( SDL_PollEvent(event) )
            {
                if( event->type == SDL_KEYDOWN )
                {
                    switch( event->key.keysym.sym )
                    {
                        case SDLK_ESCAPE:
                            {
                                SDL_DestroyWindow(m_window);
                                SDL_DestroyRenderer(m_renderer);
                                IMG_Quit();
                                SDL_Quit();
                                return 0;
                            }
                }
                }
                if( event ->type != SDL_KEYDOWN )
                {
                    x_mouse = event->button.x;
                    y_mouse = event->button.y;
                    if (event->type==SDL_MOUSEBUTTONDOWN)
                    {
                        cout<<"x_mouse = "<<x_mouse<<"\t\t y_mouse = "<<y_mouse<<endl;
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

