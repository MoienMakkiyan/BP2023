#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <windows.h>
#include<vector>


void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian);

using namespace std;

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

    int x_center = L/2;
    int y_center = W/2;

    int r = 100;
    int step = 20;

    circleRGBA(m_renderer,x_center,y_center,r,255,0,0,255);
    SDL_RenderPresent(m_renderer);

    int x_circle = x_center;
    int y_circle = y_center;

    vector<int> xs;
    vector<int> ys;

    int RNX = 200, RNY = 200;
    SDL_Event *event = new SDL_Event();

    while (1)
    {
        /// draw filled circle
        for(int i=0;i<xs.size();i++)
        {
            cout<<"X = "<<xs.at(i)<<endl;
            cout<<"Y = "<<ys.at(i)<<endl;
            filledCircleRGBA(m_renderer,xs.at(i),ys.at(i),r,255,0,0,255);
        }

        //rect(m_renderer,0,0,L,W,0,0,0,1);
        if( SDL_PollEvent(event) )
            {
                if( event->type == SDL_KEYDOWN )
                {
                    switch( event->key.keysym.sym )
                    {
                        case SDLK_UP:
                            {
                                y_circle-=step;
                                break;
                            }

                        case SDLK_DOWN:
                            {
                                y_circle+=step;
                                break;
                            }

                        case SDLK_RIGHT:
                            {
                                x_circle+=step;
                                break;
                            }

                        case SDLK_LEFT:
                            {
                                x_circle-=step;
                                break;
                            }

                        case SDLK_SPACE:
                            {
                                filledCircleRGBA(m_renderer,x_circle,y_circle,r,255,0,0,255);
                                SDL_RenderPresent(m_renderer);
                                //Sleep(5000);
                                xs.push_back(x_circle);
                                ys.push_back(y_circle);
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
        circleRGBA(m_renderer,x_circle,y_circle,r,255,0,0,255);
        SDL_RenderPresent(m_renderer);
        circleRGBA(m_renderer,x_circle,y_circle,r,0,0,0,255);//Instead of draw a big black rectangle!
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

