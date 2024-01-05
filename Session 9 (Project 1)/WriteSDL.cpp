#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_ttf.h>
#include<vector>
#include<string>

using namespace std;

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void show_scores(SDL_Renderer *Renderer,string file_name,int xs,int ys);

int main( int argc, char * argv[] )
{
    int W = 600;
    int L = 600;

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    window_color(m_renderer,255,255,255);

    show_scores(m_renderer,"scores_sorted.txt",10,10);
    //textRGBA(m_renderer,20,20,"ABC",2,75,0,0,0,255);

    SDL_RenderPresent(m_renderer);

    int RNX = 200, RNY = 200;
    SDL_Event *event = new SDL_Event();

    while (1)
    {
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
        }
    }
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor(Renderer,R,G,B,255);
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
}

void show_scores(SDL_Renderer *Renderer,string file_name,int xs,int ys)
{
    ifstream input;
    input.open(file_name.c_str(),ios::in);

    string line;
    while(getline(input,line))
    {
        int pos = line.find(":");
        textRGBA(Renderer,xs,ys,line.substr(0,pos-1).c_str(),2,50,0,0,0,255);
        textRGBA(Renderer,xs+300,ys,line.substr(pos+2).c_str(),2,50,0,0,0,255);
        aalineRGBA(Renderer,0,ys+55,600,ys+55,255,0,0,255);
        SDL_RenderPresent(Renderer);
        ys+=57;
    }



}
