#include <string>
#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>

using namespace std;

struct Point{
    int x;
    int y;
};

Point midPoint(Point A,Point B);
void triangleRGBA(SDL_Renderer* m_renderer, Point A, Point B, Point C, short Red, short Green, short Blue, short Alpha);
void serp(SDL_Renderer* m_renderer, int n, Point A, Point B, Point C);


int main( int argc, char * argv[] )
{
    Point A,B,C;
    int n;
    ifstream input;
    input.open("input.txt");
    input>>A.x>>A.y;
    input>>B.x>>B.y;
    input>>C.x>>C.y;
    input>>n;
    input.close();

    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image
    SDL_Texture* m_img = NULL;
    int img_w, img_h;
    SDL_Rect img_rect;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 480, 480, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );

    serp(m_renderer,n,A,B,C);

    SDL_RenderPresent( m_renderer );

    //Wait for a key to be pressed
    SDL_Event *e = new SDL_Event();
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);


    //Finalize and free resources
    SDL_DestroyTexture(m_img);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

}

Point midPoint(Point A,Point B)
{
    Point R;
    R.x=(A.x+B.x)/2;
    R.y=(A.y+B.y)/2;
    return R;
}

void triangleRGBA(SDL_Renderer* m_renderer, Point A, Point B, Point C, short Red, short Green, short Blue, short Alpha)
{
    aalineRGBA(m_renderer,A.x,A.y,B.x,B.y,Red,Green,Blue,Alpha);
    aalineRGBA(m_renderer,A.x,A.y,C.x,C.y,Red,Green,Blue,Alpha);
    aalineRGBA(m_renderer,C.x,C.y,B.x,B.y,Red,Green,Blue,Alpha);
}

void serp(SDL_Renderer* m_renderer, int n, Point A, Point B, Point C)
{
    if(n==0)
    {
        triangleRGBA(m_renderer,A,B,C,255,255,255,255);
        SDL_RenderPresent(m_renderer);
    }
    else if(n>0)
    {
        Point M,N,P;
        M=midPoint(A,B);
        N=midPoint(B,C);
        P=midPoint(A,C);
        serp(m_renderer,n-1,A,M,P);
        serp(m_renderer,n-1,M,B,N);
        serp(m_renderer,n-1,P,N,C);
    }
}



