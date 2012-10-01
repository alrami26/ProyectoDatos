/*
** Copyright © YYYY NAME
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU Library General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/**
   @file main.cpp
   @author NAME
   @date YYYY-MM-DD
   @version 0.01
*/
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
Fl_Double_Window *win;

int ver=0;
vector<int> coordx;                                                         
vector<int> coordy;
vector<int> coordxz;                                                         
vector<int> coordyz;
vector<int> vertices;
int cont;
bool paint=false;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MyCanvas : public Fl_Widget {
  void draw() {
         if (paint==true){
         int a=2;
         fl_color(FL_WHITE);
         fl_rectf(x(),y(),w(),h());
         // DRAW 'X' OVER BG
         //   Do your graphics here..
         //
         fl_color(FL_BLACK);
         redraw();
         for(int i=0; i<vertices.size();i++) {       
               cont=vertices[i];
               while (cont>0){
                     //fl_point(100+(coordx[a]-coordx[0])/10,100+(coordy[1]-coordy[a])/10);
                    //fl_point(100+(coordx[a+1]-coordx[0])/10,100+(coordy[1]-coordy[a+1])/10);
                    fl_line(100+(coordx[a]-coordx[0])/10,100+(coordy[1]-coordy[a])/10, 100+(coordx[a+1]-coordx[0])/10,100+(coordy[1]-coordy[a+1])/10); 
                    a+=2;
                    cont-=2;
                    }
               }
               }          
     }
  static void Canvas_CB(void *userdata) {
        MyCanvas *o = (MyCanvas*)userdata;
        o->redraw();
        Fl::repeat_timeout(0.1, Canvas_CB, userdata);}
        
public: 
     MyCanvas(int X,int Y,int W,int H,const char*L=0) : Fl_Widget(X,Y,W,H,L) {
     Fl::add_timeout(0.1, Canvas_CB, (void*)this);}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void leertxt(const char * archivo){

//Variable que va almacenar el string durante cada lectura
string Linea="";
//Variable que va almacenar la cantidad de líneas, le puse 3 por defecto
int Cant_Lineas=1000000000, i=0;
//Aca debés escribir el nombre exacto del archivo o la dirección absoluta
ifstream Archivo (archivo);  
bool xoy=true;
int pt=4;
int cant=0;
//Comprobás si existe el archivo  C:\\Users\\Albin\\calles.txt
if (Archivo.is_open()){
   for(i=0; i<Cant_Lineas; i++)
   { 
         getline (Archivo,Linea);   
         if (Linea==""){break;}
         string a = Linea.c_str();
         string b="nVertices=";
         if(a[0]==b[0])
         {
                 string bf=a.substr(10,9);
                 int num = (int) atof(bf.c_str());
                 vertices.push_back(num);
                 pt=num*2;
                 cant=0;
                 ver++;
         } 
         else
         {
             if(xoy==true)
             {
                    int x=(int)atof(Linea.c_str());
                    coordx.push_back(x);
                    xoy=false;
             }
             else
             {
                    int y=(int)atof(Linea.c_str());
                    coordy.push_back(y);
                    xoy=true;
             }
             cant++;
         }
   }
   coordxz=coordx;
   coordyz=coordy;
   paint=true;                                               //manda a dibujar
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "File loaded");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
}
else {
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "File error");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
}
    Archivo.close();}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//open.cpp 
void copy_cb( Fl_Widget* o , void* ) {
    try{
   Fl_Button* b=(Fl_Button*)o;
   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(1);
   leertxt(iw->value() );}
   catch(...){
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "File error");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();}
}



void open_window(Fl_Widget* buttonptr) {
   try{
   Fl_Window* win= new Fl_Window(420,200, "OPEN FILE");
   win->begin();      
      Fl_Button*  copy = new Fl_Button( 10, 150, 70, 30, "OPEN"); //child 0   : 1st widget
      Fl_Input*       inp = new Fl_Input(50, 50, 350, 30, "FILE");              //child 1 : 2rd widget
      Fl_Input*       msj = new Fl_Input(300, 20, 0, 0, "Example: C:\\\\Documents\\\\text.txt");
   win->end();
   copy->callback(  copy_cb );
   win->show();}
   catch(...){
   Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Open error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();}
 }
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//main.cxx
void right(Fl_Widget* buttonptr){
     try{
     int i=0;
     while(i<2){
        coordx[i]=coordx[i]-100;
        coordy[i]=coordy[i];
        i++;
    }
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Right error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}

void left(Fl_Widget* buttonptr){
     try{
     int i=0;
     while(i<2){
        coordx[i]=coordx[i]+100;
        coordy[i]=coordy[i];
        i++;
    }
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Left error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}
	
void up(Fl_Widget* buttonptr){
     try{
     int i=0;
     while(i<2){
        coordx[i]=coordx[i];
        coordy[i]=coordy[i]-100;
        i++;
    }
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Up error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}
	
void down(Fl_Widget* buttonptr){
     try{
     int i=0;
     while(i<2){
        coordx[i]=coordx[i];
        coordy[i]=coordy[i]+100;
        i++;
    }
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Down error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}

void zoomIn(Fl_Widget* buttonptr){
     try{
     for (int i=0; i<coordx.size();i++)
    {
        coordx[i]=coordx[i]*2;
        coordy[i]=coordy[i]*2;
    } 
    paint=true;                                                                      //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Zoom in error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}
void zoomOut(Fl_Widget* buttonptr){
     try{
     for (int i=0; i<coordx.size();i++)
    {
        coordx[i]=coordx[i]/2;
        coordy[i]=coordy[i]/2;
    } 
    paint=true;                                                                             //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Zoom out error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}

void reset(Fl_Widget* buttonptr){
     try{
     coordx=coordxz;
     coordy=coordyz;                                                                     //manda a dibujar
    }
     catch(...){Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Restore error");
	box->box(FL_UP_BOX);
	box->labelsize(36);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
	}}

int main(int argc, char **argv) 
{
try{
// Create a window - width, height, label (=title)
Fl_Double_Window win(930,700);
win.label("MAPAS");
// Set color of window to white
win.color(FL_WHITE);
// Begin adding children to this window
win.begin();
         //Create a button - x , y , width, height, label
       Fl_Button but(5,5,100,30,"OPEN");
       Fl_Button *buttonZoomIn = new Fl_Button(120,5,100,30,"ZOOM IN");
       Fl_Button *buttonReset = new Fl_Button(230,5,100,30,"RESET");
       Fl_Button *buttonZoomOut = new Fl_Button(340,5,100,30,"ZOOM OUT");
       Fl_Button *buttonUp = new Fl_Button(450,5,100,30,"UP");
       Fl_Button *buttonDown = new Fl_Button(560,5,100,30,"DOWN");
       Fl_Button *buttonLeft = new Fl_Button(670,5,100,30,"LEFT");
       Fl_Button *buttonRight = new Fl_Button(780,5,100,30,"RIGHT");
       //register callback function with this button
       buttonZoomIn->callback(zoomIn);
       buttonReset->callback(reset);
       buttonZoomOut->callback(zoomOut);
       buttonLeft->callback(left);
       buttonRight->callback(right);
       buttonUp->callback(up);
       buttonDown->callback(down);
       but.callback(open_window);   
       MyCanvas canvas(0,50,2000,2000);
// Stop adding children to this window
      
      win.end();
      win.resizable(win);
      // Display the window
      win.show();
      
      // Run and return
      return Fl::run();}
catch(...){
    Fl_Window *window;
	Fl_Box *box;
	window = new Fl_Window(300, 180);
	box = new Fl_Box(20, 40, 260, 100, "Critical error");
	box->box(FL_UP_BOX);
	box->labelsize(24);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show();
    return Fl::run();}
} 

