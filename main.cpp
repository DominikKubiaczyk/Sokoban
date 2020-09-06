#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<string.h>

extern "C" {
#include"./sdl-2.0.7/include/SDL.h"
#include"./sdl-2.0.7/include/SDL_main.h"
}

#define SCREEN_WIDTH    750
#define SCREEN_HEIGHT   650
#define ROZMIAR 19
#define SCIANA 1
#define PUSTE_POLE 2
#define POLE_DOCELOWE 3
#define SKRZYNIA 4
#define POLE_SKRZYNIA 5
#define POLE_DOCELOWE_SKRZYNIA 6
#define POLE_PLAYER 7
#define POLE_DOCELOWE_PLAYER 8
#define POCZATKOWY_X1 1
#define POCZATKOWY_Y1 7
#define POCZATKOWY_X2 2
#define POCZATKOWY_Y2 7
#define GRA 1

void DrawString(SDL_Surface *screen, int x, int y, const char *text,
                SDL_Surface *charset) {
        int px, py, c;
        SDL_Rect s, d;
        s.w = 8;
        s.h = 8;
        d.w = 8;
        d.h = 8;
        while(*text) {
                c = *text & 255;
                px = (c % 16) * 8;
                py = (c / 16) * 8;
                s.x = px;
                s.y = py;
                d.x = x;
                d.y = y;
                SDL_BlitSurface(charset, &s, screen, &d);
                x += 8;
                text++;
                };
        };

void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y) {
        SDL_Rect dest;
        dest.x = x - sprite->w / 2;
        dest.y = y - sprite->h / 2;
        dest.w = sprite->w;
        dest.h = sprite->h;
        SDL_BlitSurface(sprite, NULL, screen, &dest);
        };

void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 color) {
        int bpp = surface->format->BytesPerPixel;
        Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
        *(Uint32 *)p = color;
        };

void DrawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color) {
        for(int i = 0; i < l; i++) {
                DrawPixel(screen, x, y, color);
                x += dx;
                y += dy;
                };
        };

void DrawRectangle(SDL_Surface *screen, int x, int y, int l, int k,
                   Uint32 outlineColor, Uint32 fillColor) {
        int i;
        DrawLine(screen, x, y, k, 0, 1, outlineColor);
        DrawLine(screen, x + l - 1, y, k, 0, 1, outlineColor);
        DrawLine(screen, x, y, l, 1, 0, outlineColor);
        DrawLine(screen, x, y + k - 1, l, 1, 0, outlineColor);
        for(i = y + 1; i < y + k - 1; i++)
                DrawLine(screen, x + 1, i, l - 2, 1, 0, fillColor);
        };

void tworzenie_tablicy1(int T[ROZMIAR][ROZMIAR])//tworzenie tablicy dla gry nr 1
{
        for (int i = 0;i < ROZMIAR;i++)
        {
                for (int j = 0;j < ROZMIAR;j++)
                {
                        T[i][j] = 0;
                }
        }

        T[2][7] = SKRZYNIA;
        T[5][7] = SKRZYNIA;
        T[5][4] = SKRZYNIA;
        T[5][2] = SKRZYNIA;
        T[7][3] = SKRZYNIA;
        T[7][4] = SKRZYNIA;
        T[16][6] = POLE_DOCELOWE;
        T[16][7] = POLE_DOCELOWE;
        T[16][8] = POLE_DOCELOWE;
        T[17][6] = POLE_DOCELOWE;
        T[17][7] = POLE_DOCELOWE;
        T[17][8] = POLE_DOCELOWE;
        T[0][6] = SCIANA;
        T[0][7] = SCIANA;
        T[0][8] = SCIANA;
        T[0][5] = SCIANA;
        T[1][5] = SCIANA;
        T[1][8] = SCIANA;
        T[2][3] = SCIANA;
        T[2][4] = SCIANA;
        T[2][5] = SCIANA;
        T[2][8] = SCIANA;
        T[3][3] = SCIANA;
        T[3][8] = SCIANA;
        T[4][0] = SCIANA;
        T[4][1] = SCIANA;
        T[4][2] = SCIANA;
        T[4][3] = SCIANA;
        T[4][5] = SCIANA;
        T[4][6] = SCIANA;
        T[4][8] = SCIANA;
        T[4][9] = SCIANA;
        T[4][10] = SCIANA;
        T[5][0] = SCIANA;
        T[5][10] = SCIANA;
        T[6][0] = SCIANA;
        T[6][5] = SCIANA;
        T[6][6] = SCIANA;
        T[6][8] = SCIANA;
        T[6][10] = SCIANA;
        T[7][0] = SCIANA;
        T[7][5] = SCIANA;
        T[7][6] = SCIANA;
        T[7][8] = SCIANA;
        T[7][10] = SCIANA;
        T[8][0] = SCIANA;
        T[8][1] = SCIANA;
        T[8][2] = SCIANA;
        T[8][3] = SCIANA;
        T[8][8] = SCIANA;
        T[8][10] = SCIANA;
        T[9][3] = SCIANA;
        T[9][4] = SCIANA;
        T[9][5] = SCIANA;
        T[9][6] = SCIANA;
        T[9][10] = SCIANA;
        T[10][6] = SCIANA;
        T[10][8] = SCIANA;
        T[10][9] = SCIANA;
        T[10][10] = SCIANA;
        T[11][6] = SCIANA;
        T[11][9] = SCIANA;
        T[12][6] = SCIANA;
        T[12][8] = SCIANA;
        T[12][9] = SCIANA;
        T[13][5] = SCIANA;
        T[13][6] = SCIANA;
        T[13][8] = SCIANA;
        T[13][9] = SCIANA;
        T[14][5] = SCIANA;
        T[14][9] = SCIANA;
        T[15][5] = SCIANA;
        T[15][9] = SCIANA;
        T[16][5] = SCIANA;
        T[16][9] = SCIANA;
        T[16][5] = SCIANA;
        T[16][9] = SCIANA;
        T[17][9] = SCIANA;
        T[17][5] = SCIANA;
        T[18][5] = SCIANA;
        T[18][6] = SCIANA;
        T[18][7] = SCIANA;
        T[18][8] = SCIANA;
        T[18][9] = SCIANA;
        T[1][6] = PUSTE_POLE;
        T[1][7] = PUSTE_POLE;
        T[2][6] = PUSTE_POLE;
        T[3][4] = PUSTE_POLE;
        T[3][5] = PUSTE_POLE;
        T[3][6] = PUSTE_POLE;
        T[3][7] = PUSTE_POLE;
        T[4][4] = PUSTE_POLE;
        T[4][7] = PUSTE_POLE;
        T[5][1] = PUSTE_POLE;
        T[5][3] = PUSTE_POLE;
        T[5][5] = PUSTE_POLE;
        T[5][6] = PUSTE_POLE;
        T[5][8] = PUSTE_POLE;
        T[5][9] = PUSTE_POLE;
        T[6][1] = PUSTE_POLE;
        T[6][2] = PUSTE_POLE;
        T[6][3] = PUSTE_POLE;
        T[6][4] = PUSTE_POLE;
        T[6][7] = PUSTE_POLE;
        T[6][9] = PUSTE_POLE;
        T[7][1] = PUSTE_POLE;
        T[7][2] = PUSTE_POLE;
        T[7][7] = PUSTE_POLE;
        T[7][9] = PUSTE_POLE;
        T[8][4] = PUSTE_POLE;
        T[8][5] = PUSTE_POLE;
        T[8][6] = PUSTE_POLE;
        T[8][7] = PUSTE_POLE;
        T[8][9] = PUSTE_POLE;
        T[9][7] = PUSTE_POLE;
        T[9][8] = PUSTE_POLE;
        T[9][9] = PUSTE_POLE;
        T[10][7] = PUSTE_POLE;
        T[11][7] = PUSTE_POLE;
        T[11][8] = PUSTE_POLE;
        T[12][7] = PUSTE_POLE;
        T[13][7] = PUSTE_POLE;
        T[14][6] = PUSTE_POLE;
        T[14][7] = PUSTE_POLE;
        T[14][8] = PUSTE_POLE;
        T[15][6] = PUSTE_POLE;
        T[15][7] = PUSTE_POLE;
        T[15][8] = PUSTE_POLE;
        T[POCZATKOWY_X1][POCZATKOWY_Y1] = POLE_PLAYER;
}

void tworzenie_tablicy2(int T[ROZMIAR][ROZMIAR])//tworzenie tablicy dla gry nr 2
{
        for (int i = 0;i < ROZMIAR;i++)
        {
                for (int j = 0;j < ROZMIAR;j++)
                {
                        T[i][j] = 0;
                }
        }

        T[6][4] = POLE_DOCELOWE_SKRZYNIA;
        T[7][3] = POLE_DOCELOWE_SKRZYNIA;
        T[8][2] = POLE_DOCELOWE_SKRZYNIA;
        T[2][8] = SKRZYNIA;
        T[3][7] = SKRZYNIA;
        T[3][9] = SKRZYNIA;
        T[3][12] = SKRZYNIA;
        T[4][9] = SKRZYNIA;
        T[4][11] = SKRZYNIA;
        T[5][7] = SKRZYNIA;
        T[6][8] = SKRZYNIA;
        T[6][10] = SKRZYNIA;
        T[10][2] = SKRZYNIA;
        T[14][3] = SKRZYNIA;
        T[14][4] = SKRZYNIA;
        T[15][2] = SKRZYNIA;
        T[4][4] = POLE_DOCELOWE;
        T[4][5] = POLE_DOCELOWE;
        T[5][3] = POLE_DOCELOWE;
        T[5][4] = POLE_DOCELOWE;
        T[5][5] = POLE_DOCELOWE;
        T[6][2] = POLE_DOCELOWE;
        T[6][3] = POLE_DOCELOWE;
        T[6][5] = POLE_DOCELOWE;
        T[7][1] = POLE_DOCELOWE;
        T[7][2] = POLE_DOCELOWE;
        T[7][4] = POLE_DOCELOWE;
        T[8][1] = POLE_DOCELOWE;
        T[8][3] = POLE_DOCELOWE;
        T[0][5] = SCIANA;
        T[0][6] = SCIANA;
        T[0][7] = SCIANA;
        T[0][8] = SCIANA;
        T[0][9] = SCIANA;
        T[1][5] = SCIANA;
        T[1][9] = SCIANA;
        T[2][5] = SCIANA;
        T[2][9] = SCIANA;
        T[2][10] = SCIANA;
        T[2][11] = SCIANA;
        T[2][12] = SCIANA;
        T[2][13] = SCIANA;
        T[2][14] = SCIANA;
        T[2][15] = SCIANA;
        T[3][3] = SCIANA;
        T[3][4] = SCIANA;
        T[3][5] = SCIANA;
        T[3][6] = SCIANA;
        T[3][15] = SCIANA;
        T[4][2] = SCIANA;
        T[4][3] = SCIANA;
        T[4][6] = SCIANA;
        T[4][15] = SCIANA;
        T[5][1] = SCIANA;
        T[5][2] = SCIANA;
        T[5][11] = SCIANA;
        T[5][13] = SCIANA;
        T[5][14] = SCIANA;
        T[5][15] = SCIANA;
        T[6][0] = SCIANA;
        T[6][1] = SCIANA;
        T[6][6] = SCIANA;
        T[6][13] = SCIANA;
        T[7][0] = SCIANA;
        T[7][5] = SCIANA;
        T[7][7] = SCIANA;
        T[7][11] = SCIANA;
        T[7][12] = SCIANA;
        T[7][13] = SCIANA;
        T[8][0] = SCIANA;
        T[8][4] = SCIANA;
        T[8][7] = SCIANA;
        T[8][9] = SCIANA;
        T[8][11] = SCIANA;
        T[9][0] = SCIANA;
        T[9][3] = SCIANA;
        T[9][7] = SCIANA;
        T[9][11] = SCIANA;
        T[10][0] = SCIANA;
        T[10][4] = SCIANA;
        T[10][5] = SCIANA;
        T[10][8] = SCIANA;
        T[10][9] = SCIANA;
        T[10][10] = SCIANA;
        T[10][11] = SCIANA;
        T[11][0] = SCIANA;
        T[11][3] = SCIANA;
        T[11][11] = SCIANA;
        T[11][12] = SCIANA;
        T[11][13] = SCIANA;
        T[12][0] = SCIANA;
        T[12][4] = SCIANA;
        T[12][7] = SCIANA;
        T[12][8] = SCIANA;
        T[12][9] = SCIANA;
        T[12][10] = SCIANA;
        T[12][13] = SCIANA;
        T[12][14] = SCIANA;
        T[12][15] = SCIANA;
        T[13][0] = SCIANA;
        T[13][1] = SCIANA;
        T[13][3] = SCIANA;
        T[13][15] = SCIANA;
        T[14][0] = SCIANA;
        T[14][7] = SCIANA;
        T[14][9] = SCIANA;
        T[14][10] = SCIANA;
        T[14][15] = SCIANA;
        T[15][0] = SCIANA;
        T[15][5] = SCIANA;
        T[15][10] = SCIANA;
        T[15][12] = SCIANA;
        T[15][15] = SCIANA;
        T[16][0] = SCIANA;
        T[16][3] = SCIANA;
        T[16][7] = SCIANA;
        T[16][8] = SCIANA;
        T[16][9] = SCIANA;
        T[16][10] = SCIANA;
        T[16][15] = SCIANA;
        T[17][0] = SCIANA;
        T[17][1] = SCIANA;
        T[17][2] = SCIANA;
        T[17][3] = SCIANA;
        T[17][4] = SCIANA;
        T[17][5] = SCIANA;
        T[17][6] = SCIANA;
        T[17][7] = SCIANA;
        T[17][10] = SCIANA;
        T[17][14] = SCIANA;
        T[17][15] = SCIANA;
        T[18][10] = SCIANA;
        T[18][11] = SCIANA;
        T[18][12] = SCIANA;
        T[18][13] = SCIANA;
        T[18][14] = SCIANA;
        T[POCZATKOWY_X2][POCZATKOWY_Y2] = POLE_PLAYER;
        T[1][6] = PUSTE_POLE;
        T[1][7] = PUSTE_POLE;
        T[1][8] = PUSTE_POLE;
        T[2][6] = PUSTE_POLE;
        T[3][8] = PUSTE_POLE;
        T[3][10] = PUSTE_POLE;
        T[3][11] = PUSTE_POLE;
        T[3][13] = PUSTE_POLE;
        T[3][14] = PUSTE_POLE;
        T[4][7] = PUSTE_POLE;
        T[4][8] = PUSTE_POLE;
        T[4][10] = PUSTE_POLE;
        T[4][12] = PUSTE_POLE;
        T[4][13] = PUSTE_POLE;
        T[4][14] = PUSTE_POLE;
        T[5][6] = PUSTE_POLE;
        T[5][8] = PUSTE_POLE;
        T[5][9] = PUSTE_POLE;
        T[5][10] = PUSTE_POLE;
        T[5][12] = PUSTE_POLE;
        T[6][7] = PUSTE_POLE;
        T[6][9] = PUSTE_POLE;
        T[6][11] = PUSTE_POLE;
        T[6][12] = PUSTE_POLE;
        T[7][6] = PUSTE_POLE;
        T[7][8] = PUSTE_POLE;
        T[7][9] = PUSTE_POLE;
        T[7][10] = PUSTE_POLE;
        T[8][5] = PUSTE_POLE;
        T[8][6] = PUSTE_POLE;
        T[8][8] = PUSTE_POLE;
        T[8][10] = PUSTE_POLE;
        T[9][1] = PUSTE_POLE;
        T[9][2] = PUSTE_POLE;
        T[9][4] = PUSTE_POLE;
        T[9][5] = PUSTE_POLE;
        T[9][6] = PUSTE_POLE;
        T[9][8] = PUSTE_POLE;
        T[9][9] = PUSTE_POLE;
        T[9][10] = PUSTE_POLE;
        T[10][1] = PUSTE_POLE;
        T[10][3] = PUSTE_POLE;
        T[10][6] = PUSTE_POLE;
        T[10][7] = PUSTE_POLE;
        T[11][1] = PUSTE_POLE;
        T[11][2] = PUSTE_POLE;
        T[11][4] = PUSTE_POLE;
        T[11][5] = PUSTE_POLE;
        T[11][6] = PUSTE_POLE;
        T[11][7] = PUSTE_POLE;
        T[11][8] = PUSTE_POLE;
        T[11][9] = PUSTE_POLE;
        T[11][10] = PUSTE_POLE;
        T[12][1] = PUSTE_POLE;
        T[12][2] = PUSTE_POLE;
        T[12][3] = PUSTE_POLE;
        T[12][5] = PUSTE_POLE;
        T[12][6] = PUSTE_POLE;
        T[12][11] = PUSTE_POLE;
        T[12][12] = PUSTE_POLE;
        T[13][2] = PUSTE_POLE;
        T[13][4] = PUSTE_POLE;
        T[13][5] = PUSTE_POLE;
        T[13][6] = PUSTE_POLE;
        T[13][7] = PUSTE_POLE;
        T[13][8] = PUSTE_POLE;
        T[13][9] = PUSTE_POLE;
        T[13][10] = PUSTE_POLE;
        T[13][11] = PUSTE_POLE;
        T[13][12] = PUSTE_POLE;
        T[13][13] = PUSTE_POLE;
        T[13][14] = PUSTE_POLE;
        T[14][1] = PUSTE_POLE;
        T[14][2] = PUSTE_POLE;
        T[14][5] = PUSTE_POLE;
        T[14][6] = PUSTE_POLE;
        T[14][8] = PUSTE_POLE;
        T[14][11] = PUSTE_POLE;
        T[14][12] = PUSTE_POLE;
        T[14][13] = PUSTE_POLE;
        T[14][14] = PUSTE_POLE;
        T[15][1] = PUSTE_POLE;
        T[15][3] = PUSTE_POLE;
        T[15][4] = PUSTE_POLE;
        T[15][6] = PUSTE_POLE;
        T[15][7] = PUSTE_POLE;
        T[15][8] = PUSTE_POLE;
        T[15][9] = PUSTE_POLE;
        T[15][11] = PUSTE_POLE;
        T[15][13] = PUSTE_POLE;
        T[15][14] = PUSTE_POLE;
        T[16][1] = PUSTE_POLE;
        T[16][2] = PUSTE_POLE;
        T[16][4] = PUSTE_POLE;
        T[16][5] = PUSTE_POLE;
        T[16][6] = PUSTE_POLE;
        T[16][11] = PUSTE_POLE;
        T[16][12] = PUSTE_POLE;
        T[16][13] = PUSTE_POLE;
        T[16][14] = PUSTE_POLE;
        T[17][11] = PUSTE_POLE;
        T[17][12] = PUSTE_POLE;
        T[17][13] = PUSTE_POLE;
}

int ile_skrzyn(int T[ROZMIAR][ROZMIAR]) //funkcja zlicza ilość skrzyń na mapie na początku gry
{
        int s=0;
        for (int i = 0; i < ROZMIAR; i++)
        {
                for (int j = 0; j < ROZMIAR; j++)
                {
                        if (T[i][j] == SKRZYNIA || T[i][j] == POLE_DOCELOWE_SKRZYNIA || T[i][j] == POLE_SKRZYNIA) { s += 1; }
                }
        }
        return s;
}

void skrzynia_w_lewo(int T[ROZMIAR][ROZMIAR], int *x, int *y)//funkcja przesuwająca skrzynię i gracza w lewo
{
        int a = (*x);
        int b = (*y);
        if (T[a - 2][b] == PUSTE_POLE)
        {
                T[a - 2][b] = POLE_SKRZYNIA;
                if (T[a - 1][b] == POLE_SKRZYNIA || T[a-1][b] == SKRZYNIA) { T[a - 1][b] = POLE_PLAYER; }
                if (T[a - 1][b] == POLE_DOCELOWE_SKRZYNIA) { T[a - 1][b] = POLE_DOCELOWE_PLAYER; }
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*x) -= 1;
        }
         if (T[a - 2][b] == POLE_DOCELOWE)
        {
                T[a - 2][b] = POLE_DOCELOWE_SKRZYNIA;
                if (T[a - 1][b] == POLE_SKRZYNIA || T[a-1][b] == SKRZYNIA) { T[a - 1][b] = POLE_PLAYER; }
         if (T[a - 1][b] == POLE_DOCELOWE_SKRZYNIA) { T[a - 1][b] = POLE_DOCELOWE_PLAYER; }
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*x) -= 1;
        }
}

void skrzynia_w_prawo(int T[ROZMIAR][ROZMIAR], int *x, int *y)//funkcja przesuwająca gracza i skrzynię w prawo
{
        int a = (*x);
        int b = (*y);
        if (T[a + 2][b] == PUSTE_POLE)
        {
                T[a + 2][b] = POLE_SKRZYNIA;
                if (T[a + 1][b] == POLE_SKRZYNIA || T[a + 1][b] == SKRZYNIA) { T[a + 1][b] = POLE_PLAYER; }
                if (T[a + 1][b] == POLE_DOCELOWE_SKRZYNIA) { T[a + 1][b] = POLE_DOCELOWE_PLAYER; }
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*x) += 1;
        }
        if (T[a + 2][b] == POLE_DOCELOWE)
        {
                T[a + 2][b] = POLE_DOCELOWE_SKRZYNIA;
                if (T[a + 1][b] == POLE_SKRZYNIA || T[a + 1][b] == SKRZYNIA) { T[a + 1][b] = POLE_PLAYER; }
                if (T[a + 1][b] == POLE_DOCELOWE_SKRZYNIA) { T[a + 1][b] = POLE_DOCELOWE_PLAYER; }
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*x) += 1;
        }
}

void skrzynia_w_gore(int T[ROZMIAR][ROZMIAR], int *x, int *y)//funkcja przesuwająca skrzynię i gracza w górę
{
        int a = (*x);
        int b = (*y);
        if (T[a][b-2] == PUSTE_POLE)
        {
                T[a][b-2] = POLE_SKRZYNIA;
                if (T[a][b-1] == POLE_SKRZYNIA || T[a][b-1] == SKRZYNIA) { T[a][b-1] = POLE_PLAYER; }
                if (T[a][b-1] == POLE_DOCELOWE_SKRZYNIA) { T[a][b-1] = POLE_DOCELOWE_PLAYER; }
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*y) -= 1;
        }
        if (T[a][b-2] == POLE_DOCELOWE)
        {
                T[a][b-2] = POLE_DOCELOWE_SKRZYNIA;
                if (T[a][b-1] == POLE_SKRZYNIA || T[a][b-1] == SKRZYNIA) { T[a][b-1] = POLE_PLAYER; }
                if (T[a][b-1] == POLE_DOCELOWE_SKRZYNIA) { T[a][b-1] = POLE_DOCELOWE_PLAYER; }
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*y) -= 1;
        }
}

void skrzynia_w_dol(int T[ROZMIAR][ROZMIAR], int *x, int *y)//funkcja przesuwająca skrzynię i gracza w dół
{
        int a = (*x);
        int b = (*y);
        if (T[a][b + 2] == PUSTE_POLE)
        {
                T[a][b + 2] = POLE_SKRZYNIA;
                if (T[a][b + 1] == POLE_SKRZYNIA || T[a][b + 1] == SKRZYNIA) { T[a][b + 1] = POLE_PLAYER; }
                if (T[a][b + 1] == POLE_DOCELOWE_SKRZYNIA) { T[a][b + 1] = POLE_DOCELOWE_PLAYER; }
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*y) += 1;
        }
        if (T[a][b + 2] == POLE_DOCELOWE)
        {
                T[a][b + 2] = POLE_DOCELOWE_SKRZYNIA;
                if (T[a][b + 1] == POLE_SKRZYNIA || T[a][b + 1] == SKRZYNIA) { T[a][b + 1] = POLE_PLAYER; }
                if (T[a][b + 1] == POLE_DOCELOWE_SKRZYNIA) { T[a][b + 1] = POLE_DOCELOWE_PLAYER; }
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*y) += 1;
        }
}

void ruch_w_dol(int T[ROZMIAR][ROZMIAR], int *x, int *y)//funkcja przesuwająca gracza w dół na wolne pole
{
        int a = (*x);
        int b = (*y);
        if (T[a][b +1] == PUSTE_POLE)
        {
                T[a][b + 1] = POLE_PLAYER;
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE;}
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*y) += 1;
        }
        if (T[a][b +1] == POLE_DOCELOWE)
        {
                T[a][b + 1] = POLE_DOCELOWE_PLAYER;
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*y) += 1;
        }
        if (T[a][b + 1] == POLE_SKRZYNIA || T[a][b + 1] == SKRZYNIA || T[a][b + 1] == POLE_DOCELOWE_SKRZYNIA) { skrzynia_w_dol(T, x, y); }
}

void ruch_w_gore(int T[ROZMIAR][ROZMIAR], int *x, int *y)//funkcja przesuwająca gracza w górę na wolne pole
{
        int a = (*x);
        int b = (*y);
        if (T[a][b - 1] == PUSTE_POLE)
        {
                T[a][b - 1] = POLE_PLAYER;
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*y) -= 1;
        }
        if (T[a][b - 1] == POLE_DOCELOWE)
        {
                T[a][b - 1] = POLE_DOCELOWE_PLAYER;
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*y) -= 1;
        }
        if (T[a][b-1] == POLE_SKRZYNIA || T[a][b-1] == SKRZYNIA || T[a][b-1] == POLE_DOCELOWE_SKRZYNIA) { skrzynia_w_gore(T, x, y); }
}

void ruch_w_prawo(int T[ROZMIAR][ROZMIAR], int *x, int *y)//funkcja przesuwająca gracza w prawo na wolne pole
{
        int a = (*x);
        int b = (*y);
        if (T[a + 1][b] == PUSTE_POLE)
        {
                T[a + 1][b] = POLE_PLAYER;
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*x) += 1;
        }
        if (T[a + 1][b] == POLE_DOCELOWE)
        {
                T[a + 1][b] = POLE_DOCELOWE_PLAYER;
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*x) += 1;
        }
        if (T[a + 1][b] == POLE_SKRZYNIA || T[a + 1][b] == SKRZYNIA || T[a + 1][b] == POLE_DOCELOWE_SKRZYNIA) { skrzynia_w_prawo(T, x, y); }
}

void ruch_w_lewo(int T[ROZMIAR][ROZMIAR], int *x, int *y)//funkcja przesuwająca gracza w lewo na wolne pole
{
        int a = (*x);
        int b = (*y);
        if (T[a - 1][b] == PUSTE_POLE)
        {
                T[a - 1][b] = POLE_PLAYER;
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*x) -= 1;
        }
        if (T[a - 1][b] == POLE_DOCELOWE)
        {
                T[a - 1][b] = POLE_DOCELOWE_PLAYER;
                if (T[a][b] == POLE_PLAYER) { T[a][b] = PUSTE_POLE; }
                if (T[a][b] == POLE_DOCELOWE_PLAYER) { T[a][b] = POLE_DOCELOWE; }
                (*x) -= 1;
        }

        if (T[a - 1][b] == POLE_SKRZYNIA || T[a - 1][b] == SKRZYNIA || T[a - 1][b] == POLE_DOCELOWE_SKRZYNIA) { skrzynia_w_lewo(T, x, y);}
}

int detekcja_konca(int T[ROZMIAR][ROZMIAR], int s)//funkcja sprawdzająca czy gra została ukończona (czy na wszystkich polach docelowych stoją skrzynie)
{
        int z=0;
        for (int i = 0;i < ROZMIAR;i++)
        {
                for (int j = 0;j < ROZMIAR;j++)
                {
                        if (T[i][j] == POLE_DOCELOWE_SKRZYNIA) { z += 1; }
                }
        }
        if (z == s) { return 1; }
        else { return 0; }
}

void rysuj_plansze(int T[ROZMIAR][ROZMIAR], SDL_Surface *screen, SDL_Surface *tlo, SDL_Surface *mur, SDL_Surface *pole_doc, SDL_Surface *crate, SDL_Surface *pole, SDL_Surface *player, SDL_Surface *skrzynia_doc)
{
        //funkcja rysująca planszę na ekran
        for (int a = 0; a < SCREEN_HEIGHT; a++)
        {
                for (int b = 0; b < SCREEN_WIDTH; b++)
                {
                        DrawSurface(screen, tlo, a * 30, b * 30);
                }
        }

        for (int i = 0; i < ROZMIAR; i++)
        {
                for (int j = 0; j < ROZMIAR; j++)
                {
                        if (T[i][j] == SCIANA) { DrawSurface(screen, mur, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); }
                        if (T[i][j] == POLE_DOCELOWE) { DrawSurface(screen, pole_doc, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); }
                        if (T[i][j] == SKRZYNIA || T[i][j] == POLE_SKRZYNIA) { DrawSurface(screen, crate, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); }
                        if (T[i][j] == PUSTE_POLE) { DrawSurface(screen, pole, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); }
                        if (T[i][j] == POLE_PLAYER) { DrawSurface(screen, pole, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); DrawSurface(screen, player, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); }
                        if (T[i][j] == POLE_DOCELOWE_PLAYER) { DrawSurface(screen, pole_doc, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); DrawSurface(screen, player, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); }
                        if (T[i][j] == POLE_DOCELOWE_SKRZYNIA) { DrawSurface(screen, skrzynia_doc, (SCREEN_WIDTH / 5) + i * 30, (SCREEN_HEIGHT / 6) + j * 30); }

                }
        }
}

#ifdef __cplusplus
extern "C"
#endif

int main(int argc, char **argv) {
        int t1, t2, quit, frames, rc, gra;
        double delta, worldTime, fpsTimer, fps;
        int T[ROZMIAR][ROZMIAR];
        SDL_Event event;
        SDL_Surface *screen, *charset;
        SDL_Surface *pole_doc, *tlo, *mur, *player, *crate, *pole, *skrzynia_doc;
        SDL_Texture *scrtex;
        SDL_Window *window;
        SDL_Renderer *renderer;

        gra = GRA;

        int pozycjax;
        int pozycjay;

        if (gra == 1)
        {
                tworzenie_tablicy1(T);

                pozycjax = POCZATKOWY_X1;
                pozycjay = POCZATKOWY_Y1;

        }
        else if (gra == 2)
        {
                tworzenie_tablicy2(T);

                pozycjax = POCZATKOWY_X2;
            pozycjay = POCZATKOWY_Y2;

        }

        int *px = &pozycjax;
        int *py = &pozycjay;

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                printf("SDL_Init error: %s\n", SDL_GetError());
                return 1;
        }

        // tryb pełnoekranowy / fullscreen mode
        //      rc = SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP,
        //                                       &window, &renderer);
        rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0,
                &window, &renderer);
        if (rc != 0) {
                SDL_Quit();
                printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
                return 1;
        };

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_SetWindowTitle(window, "SOKOBAN");


        screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
                0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

        scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                SDL_TEXTUREACCESS_STREAMING,
                SCREEN_WIDTH, SCREEN_HEIGHT);


        // wyłączenie widoczności kursora myszy
        SDL_ShowCursor(SDL_DISABLE);

        // wczytywanie obrazków:
        charset = SDL_LoadBMP("./cs8x8.bmp");
        if (charset == NULL) {
                printf("SDL_LoadBMP(cs8x8.bmp) error: %s\n", SDL_GetError());
                SDL_FreeSurface(screen);
                SDL_DestroyTexture(scrtex);
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                return 1;
        };

        SDL_SetColorKey(charset, true, 0x000000);

        pole_doc = SDL_LoadBMP("./environment_04.bmp");
        if (pole_doc == NULL) {
                printf("SDL_LoadBMP(environment_04.bmp) error: %s\n", SDL_GetError());
                SDL_FreeSurface(charset);
                SDL_FreeSurface(screen);
                SDL_DestroyTexture(scrtex);
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                return 1;
        };

        tlo = SDL_LoadBMP("./ground_05.bmp");
        if (tlo == NULL) {
                printf("SDL_LoadBMP(ground_05.bmp) error: %s\n", SDL_GetError());
                SDL_FreeSurface(charset);
                SDL_FreeSurface(screen);
                SDL_DestroyTexture(scrtex);
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                return 1;
        };

        mur = SDL_LoadBMP("./block_05.bmp");
        if (mur == NULL) {
                printf("SDL_LoadBMP(block_05.bmp) error: %s\n", SDL_GetError());
                SDL_FreeSurface(charset);
                SDL_FreeSurface(screen);
                SDL_DestroyTexture(scrtex);
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                return 1;
        };

        player = SDL_LoadBMP("./playerFace.bmp");
        if (player == NULL) {
                printf("SDL_LoadBMP(playerFace.bmp) error: %s\n", SDL_GetError());
                SDL_FreeSurface(charset);
                SDL_FreeSurface(screen);
                SDL_DestroyTexture(scrtex);
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                return 1;
        };

        crate = SDL_LoadBMP("./crate_01.bmp");
        if (crate == NULL) {
                printf("SDL_LoadBMP(crate_01.bmp) error: %s\n", SDL_GetError());
                SDL_FreeSurface(charset);
                SDL_FreeSurface(screen);
                SDL_DestroyTexture(scrtex);
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                return 1;
        };

        pole = SDL_LoadBMP("./environment_15.bmp");
        if (pole == NULL) {
                printf("SDL_LoadBMP(environment_15.bmp) error: %s\n", SDL_GetError());
                SDL_FreeSurface(charset);
                SDL_FreeSurface(screen);
                SDL_DestroyTexture(scrtex);
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                return 1;
        };

        skrzynia_doc = SDL_LoadBMP("./crate_111.bmp");
        if (skrzynia_doc == NULL) {
                printf("SDL_LoadBMP(crate_111.bmp) error: %s\n", SDL_GetError());
                SDL_FreeSurface(charset);
                SDL_FreeSurface(screen);
                SDL_DestroyTexture(scrtex);
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                return 1;
        };



        char text[128];
        int czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
        int zielony = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
        int czerwony = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
        int niebieski = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);

        t1 = SDL_GetTicks();

        frames = 0;
        fpsTimer = 0;
        fps = 0;
        quit = 0;
        worldTime = 0;

        int ilosc_skrzyn = ile_skrzyn(T);

        while (!quit) {
                if (detekcja_konca(T, ilosc_skrzyn) == 0)
                {
                        t2 = SDL_GetTicks();
                }

                delta = (t2 - t1) * 0.001;
                t1 = t2;

                worldTime += delta;

                SDL_FillRect(screen, NULL, czarny);

                rysuj_plansze(T, screen, tlo, mur, pole_doc, crate, pole, player, skrzynia_doc);

                fpsTimer += delta;
                if (fpsTimer > 0.5) {
                        fps = frames * 2;
                        frames = 0;
                        fpsTimer -= 0.5;
                };

                //tekst u góry ekranu:
                DrawRectangle(screen, 4, 4, SCREEN_WIDTH - 8, 36, czerwony, niebieski);
                sprintf_s(text, "SOKOBAN - Dominik Kubiaczyk 171739, czas trwania = %.1lf s", worldTime);
                DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
                sprintf_s(text, "Esc - wyjscie, n - nowa gra, \030 \031 \032 \033 - sterowanie");
                DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text, charset);

                if (detekcja_konca(T, ilosc_skrzyn))
                {
                        //komunikat wyskakujący w momencie zakończenia gry
                        DrawRectangle(screen, 4, 400, SCREEN_WIDTH - 8, 34, czerwony, niebieski);
                        sprintf_s(text, "GRATULACJE! WYGRALES W CZASIE: %.1lf s", worldTime);
                        DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 405, text, charset);
                        sprintf_s(text, "'esc' - ZAKONCZ GRE, 'n' - ZAGRAJ OD NOWA, 's' - ZAGRAJ KOLEJNY POZIOM");
                        DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 415, text, charset);

                }

                SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
                SDL_RenderCopy(renderer, scrtex, NULL, NULL);
                SDL_RenderPresent(renderer);

                // obsługa zdarzeń (akcja na wciśnięcie klawisza)
                while (SDL_PollEvent(&event)) {
                                switch (event.type) {
                                case SDL_KEYDOWN:
                                        if (detekcja_konca(T, ilosc_skrzyn) == 0) {
                                                if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
                                                else if (event.key.keysym.sym == SDLK_DOWN) {
                                                        ruch_w_dol(T, px, py);
                                                }
                                                else if (event.key.keysym.sym == SDLK_UP)
                                                {
                                                        ruch_w_gore(T, px, py);
                                                }
                                                else if (event.key.keysym.sym == SDLK_RIGHT)
                                                {
                                                        ruch_w_prawo(T, px, py);
                                                }
                                                else if (event.key.keysym.sym == SDLK_LEFT)
                                                {
                                                        ruch_w_lewo(T, px, py);
                                                }
                                                else if (event.key.keysym.sym == SDLK_n)
                                                {
                                                        worldTime = 0;
                                                        if (gra == 1)
                                                        {
                                                                tworzenie_tablicy1(T);
                                                                (*px) = POCZATKOWY_X1;
                                                                (*py) = POCZATKOWY_Y1;
                                                        }
                                                        else if (gra == 2)
                                                        {
                                                                tworzenie_tablicy2(T);
                                                                (*px) = POCZATKOWY_X2;
                                                                (*py) = POCZATKOWY_Y2;
                                                        }
                                        
                                                }
                                        }
                                        //akcje po ukończeniu gry:
                                        else if (event.key.keysym.sym == SDLK_n)
                                        {
                                                worldTime = 0;
                                                if (gra == 1)
                                                {
                                                        tworzenie_tablicy1(T);
                                                        (*px) = POCZATKOWY_X1;
                                                        (*py) = POCZATKOWY_Y1;
                                                }
                                                else if (gra == 2)
                                                {
                                                        tworzenie_tablicy2(T);
                                                        (*px) = POCZATKOWY_X2;
                                                        (*py) = POCZATKOWY_Y2;
                                                }
                                                
                                        }
                                        else if (event.key.keysym.sym == SDLK_s)
                                        {
                                                worldTime = 0;
                                                if (gra == 1)
                                                {
                                                        tworzenie_tablicy2(T);
                                                        (*px) = POCZATKOWY_X2;
                                                        (*py) = POCZATKOWY_Y2;
                                                        gra = 2;
                                                        ilosc_skrzyn = ile_skrzyn(T);
                                                }
                                                else if (gra == 2)
                                                {
                                                        tworzenie_tablicy1(T);
                                                        (*px) = POCZATKOWY_X1;
                                                        (*py) = POCZATKOWY_Y1;
                                                        gra = 1;
                                                        ilosc_skrzyn = ile_skrzyn(T);
                                                }
                                        }
                                        else if (event.key.keysym.sym == SDLK_ESCAPE) { if (detekcja_konca(T, ilosc_skrzyn)) { quit = 1; } }
                                        break;
                        };
                };
                frames++;
        };

        // zwolnienie powierzchni
        SDL_FreeSurface(charset);
        SDL_FreeSurface(screen);
        SDL_DestroyTexture(scrtex);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

        SDL_Quit();
        return 0;
};