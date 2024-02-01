///DEFINE CORNOMETR

#ifndef CHRONOMETER_HPP
#define CHRONOMETER_HPP

#include<ctime>

using std::clock;
using std::clock_t;

const double pps = CLOCKS_PER_SEC;

class chronometer
{

public:

  chronometer():active{false},t0{},t1{}{}

  void run(){active = true; t0 = clock(); }
  void stop(){if(active){active = false; t1 = clock();}}

  void reset(){ active = false; t0 = clock_t(); t1=clock_t();}

  double get_time()const{return ((active ? clock(): t1)-t0)/pps;}

private:

  bool active ;

  clock_t t0, t1;

};

#endif
///DEFINE CORNOMETR



#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_ttf.h>
#include <string>

using namespace std;


void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void show_corno(SDL_Renderer *Renderer,int x,int y,string s,int size_font,int R,int G,int B);


chronometer crono{};

int main( int argc, char * argv[] )
{
    int W = 600;
    int L = 1200;

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
        if(crono.get_time()>5)
        {
            crono.reset();
            cout<<"Corno Reseted by 5 sec limit."<<endl;
            crono.run();
        }
        if( SDL_PollEvent(event) )
            {
                if( event->type == SDL_KEYDOWN )
                {
                    switch( event->key.keysym.sym )
                    {
                        case SDLK_s:
                            {
                                crono.run();
                                cout<<"Crono is Started!..."<<endl;
                                break;
                            }

                        case SDLK_e:
                            {
                                crono.stop();
                                cout<<"Crono Stopped!..."<<endl;
                                break;
                            }

                        case SDLK_p:
                            {
                                cout<<"takes "<<crono.get_time()<<" seconds :))"<<endl;
                                show_corno(m_renderer,100,100,to_string(crono.get_time()),40,255,0,0);
                                break;
                            }
                        case SDLK_r:
                            {
                                cout<<"Crono Reseted!..."<<endl;
                                crono.reset();
                                break;
                            }
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


void show_corno(SDL_Renderer *Renderer,int x,int y,string s,int size_font,int R,int G,int B)
{
    rect(Renderer,0,0,600,1200,0,0,0,1);
    textRGBA(Renderer,x,y,s.c_str(),2,size_font,R,G,B,255);
    SDL_RenderPresent(Renderer);
}
