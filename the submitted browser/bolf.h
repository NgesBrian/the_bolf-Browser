
#ifndef BOLF_H
#define BOLF_H

	#include <gtk/gtk.h>
	#include "bolf.h"
	#include <webkit/webkit.h>

	typedef GtkWidget * Widget; 


	int Delete(GtkWidget *widget ,GtkWidget *event ,gpointer data);
	GtkWidget* ImageButton( char name[]);
	GtkWidget * MyEvent(char name[]);
	Widget BolfView();
	void addNewTab( GtkWidget* browserForm, gpointer data);
	void delete_tab( GtkWidget* browserForm, gpointer data);
	void InputConnect(GtkWidget* widget,gpointer* wid);
	void activate( GtkWidget* ,gpointer* wid);
	void progress (WebKitWebView *web, gint progress,gpointer* data);
	void finished (WebKitWebView  *web_view, WebKitWebFrame *frame,gpointer*  data);
	void back(GtkWidget* widget, gpointer* wid);
	void forward(GtkWidget* widget, gpointer* wid);
	void stop(GtkWidget* widget, gpointer* wid);
	
	void AfricaMusic();
	void KamerHits();
	void NijiaMusic();
	void HipHopMusic();

	void Nollywood();
	void Hollywood();
	void Bollywood();
	void Horosmov();

	void NijiaBoys();
	void AmericaFun();
	void AfricaFun();
	void KidsMovies();


	void Basketball(GtkWidget* widget, GdkEvent * event , gpointer UrlText);
	
	void Football(GtkWidget* widget, GdkEvent * event , gpointer UrlText);
	void OtherSports(GtkWidget* widget, GdkEvent * event , gpointer UrlText);
	void Resling(GtkWidget* widget, GdkEvent * event , gpointer UrlText);


	void RaceGame(GtkWidget* widget,gpointer* wid);
	void WarGame(GtkWidget* widget,gpointer* wid);
	void HeroGame(GtkWidget* widget,gpointer* wid);
	void KidGames(GtkWidget* widget,gpointer* wid);

	void viewSearchedPage( GtkWidget *expander, gpointer button);

	void Home();
	void Newso();
#endif
