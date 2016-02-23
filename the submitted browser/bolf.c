/* create Webview */
//web = webkit_web_view_new();
/* create Webview */
//web = webkit_web_view_new();
#include "bolf.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <webkit/webkit.h>

gint NUMBER_OF_TABS = 1;
gint count=1;
Widget web[20],UrlText;
const char* uri;


//the function delete.This function destroy the window when called.
int Delete(GtkWidget *widget ,GtkWidget *event ,gpointer data){
	gtk_main_quit();
	return FALSE;
}

GtkWidget * MyEvent(char name[]){
		Widget eventBox;
		Widget childWidget;
		childWidget = gtk_image_new_from_file(name);
		eventBox = gtk_event_box_new();
		gtk_event_box_set_above_child(GTK_EVENT_BOX(eventBox), TRUE);
		gtk_widget_set_events(eventBox, GDK_BUTTON_PRESS_MASK);
		gtk_container_add(GTK_CONTAINER(eventBox), childWidget);	
		return eventBox;
	
}

//adding and image to a button.
GtkWidget * ImageButton( char name[]){
	GtkWidget *image, *imageButton;
			image=gtk_image_new_from_file(name);
		imageButton=gtk_button_new();
		gtk_container_add(GTK_CONTAINER(imageButton),image);	
		return imageButton;
} 

void viewSearchedPage( GtkWidget *expander, gpointer button){
	gtk_expander_set_expanded( GTK_EXPANDER(expander), TRUE);
}

Widget BolfView(){

	GtkTooltips *Tooltips;
	Tooltips=gtk_tooltips_new();

	Widget Window, InputText, SearchButton, SelectType, Table, SelectText, Slider, News;
	Widget NijiaM, KamerM, HipHop, AfricaM;
	Widget MusicLabel, GameLabel, FunLabel, MovieLabel, SportLabel;

	GtkWidget *pageLayoutExpander, *scrolledWindow;
	pageLayoutExpander = gtk_expander_new_with_mnemonic("Page");

	MusicLabel= gtk_label_new("Music");
	GameLabel= gtk_label_new("Games");
	FunLabel= gtk_label_new("Funny");
	MovieLabel= gtk_label_new("Movies");
	SportLabel= gtk_label_new("Sports");


	//	Warning = gtk_label_new("Click On Me  \n If You wanna Quit \n Or Cancel if you dont");
	//declaring the url entry;
	UrlText=gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(UrlText),TRUE);
	gtk_widget_set_size_request(UrlText,600,25);
	gtk_entry_set_text (GTK_ENTRY(UrlText),"http://DONOT WRITE HERE!!!!!!");
	gtk_tooltips_set_tip(Tooltips,UrlText,"This is to displace th current URL",NULL);

	
	//declaring the search text
	InputText=gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(InputText),TRUE);
	gtk_widget_set_size_request(InputText,20,40);
	gtk_tooltips_set_tip(Tooltips,InputText,"Enter Your Search Here!!!!",NULL);
	
	/* create Webview */
	
	web[count] = webkit_web_view_new();


	//declaring the search button;
	SearchButton=gtk_button_new();
	SearchButton=ImageButton("pictures/search.jpeg");
	gtk_widget_set_size_request(SearchButton,130,80);
	gtk_tooltips_set_tip(Tooltips,SearchButton,"Search Button",NULL);
	g_signal_connect(SearchButton, "clicked",  G_CALLBACK(InputConnect), InputText);
	

	//creating a slider	
	Slider=MyEvent("pictures/ani1.gif");
	//gtk_widget_set_size_request(Slider,1000,3000);
	gtk_tooltips_set_tip(Tooltips,Slider,"News",NULL);
	g_signal_connect_swapped(Slider, "button_press_event", G_CALLBACK(Newso),NULL);

	//creating news
	News=MyEvent("pictures/ani2.gif");
	//gtk_widget_set_size_request(News,400,150);
	gtk_tooltips_set_tip(Tooltips,News,"News",NULL);
	g_signal_connect_swapped(News, "button_press_event", G_CALLBACK(Newso),NULL);

	//Music	
	NijiaM=MyEvent("pictures/concour.jpeg");
	gtk_widget_set_size_request(NijiaM,175,80);
	gtk_tooltips_set_tip(Tooltips,NijiaM,"Nijia Music",NULL);
	g_signal_connect_swapped(NijiaM, "button_press_event", G_CALLBACK(NijiaMusic),NULL);
	
	HipHop=MyEvent("pictures/hiphop.jpeg");
	gtk_widget_set_size_request(HipHop,175,80);
	gtk_tooltips_set_tip(Tooltips,HipHop,"Hip, HOp, R&B",NULL);
	g_signal_connect_swapped(HipHop, "button_press_event", G_CALLBACK(HipHopMusic),NULL);

	KamerM=MyEvent("pictures/camerhits.jpeg");
	gtk_widget_set_size_request(KamerM,175,80);
	gtk_tooltips_set_tip(Tooltips,KamerM,"Kamer Hits",NULL);
	g_signal_connect_swapped(KamerM, "button_press_event", G_CALLBACK(KamerHits),NULL);

	AfricaM=MyEvent("pictures/cam.jpeg");
	gtk_widget_set_size_request(AfricaM,175,80);
	gtk_tooltips_set_tip(Tooltips,AfricaM,"Africa Music",NULL);
	g_signal_connect_swapped(AfricaM,"button_press_event",G_CALLBACK(AfricaMusic),NULL);

	//Movies	
	Widget Nolly, Holly,Bolly, Horos;

	Nolly=MyEvent("pictures/nollywood.jpeg");
	gtk_widget_set_size_request(Nolly,175,80);
	gtk_tooltips_set_tip(Tooltips,Nolly,"NollyWood(Nigeria Film Industry)",NULL);
	g_signal_connect_swapped(Nolly, "button_press_event", G_CALLBACK(Nollywood),NULL);
	
	Holly=MyEvent("pictures/hollywood.jpeg");
	gtk_widget_set_size_request(Holly,175,80);
	gtk_tooltips_set_tip(Tooltips,Holly,"Hollywood(America Film Industry)",NULL);
	g_signal_connect_swapped(Holly, "button_press_event", G_CALLBACK(Hollywood),NULL);

	Bolly=MyEvent("pictures/bollywood.jpeg");
	gtk_widget_set_size_request(Bolly,175,80);
	gtk_tooltips_set_tip(Tooltips,Bolly,"Bollywood(The Indians)",NULL);
	g_signal_connect_swapped(Bolly, "button_press_event", G_CALLBACK(Bollywood),NULL);

	Horos=MyEvent("pictures/horos.jpeg");
	gtk_widget_set_size_request(Horos,175,80);
	gtk_tooltips_set_tip(Tooltips,Horos,"Horos Movies",NULL);
	g_signal_connect_swapped(Horos,"button_press_event",G_CALLBACK(Horosmov),NULL);

	//funny movies

	Widget African,American,Europe,Kids;
	African=MyEvent("pictures/basket.jpeg");
	gtk_widget_set_size_request(African,175,80);
	gtk_tooltips_set_tip(Tooltips,African,"Africa Fun",NULL);
	g_signal_connect_swapped(African, "button_press_event", G_CALLBACK(AfricaFun),NULL);
	
	American=MyEvent("pictures/amerifun.jpeg");
	gtk_widget_set_size_request(American,175,80);
	gtk_tooltips_set_tip(Tooltips,American,"American Fun",NULL);
	g_signal_connect_swapped(American, "button_press_event", G_CALLBACK(AmericaFun),NULL);

	Europe=MyEvent("pictures/africanfunny.jpeg");
	gtk_widget_set_size_request(Europe,175,80);
	gtk_tooltips_set_tip(Tooltips,Europe,"General Fun",NULL);
	g_signal_connect_swapped(Europe, "button_press_event", G_CALLBACK(NijiaBoys),NULL);

	Kids=MyEvent("pictures/kids.jpeg");
	gtk_widget_set_size_request(Kids,175,80);
	gtk_tooltips_set_tip(Tooltips,Kids,"Kid Movies And Funs",NULL);
	g_signal_connect_swapped(Kids,"button_press_event",G_CALLBACK(KidsMovies),NULL);

	//Games
	Widget Race,War,HerosGame,KidGame;
	Race=MyEvent("pictures/race.jpeg");
	gtk_widget_set_size_request(Race,175,80);
	gtk_tooltips_set_tip(Tooltips,Race,"Racee Games",NULL);
	g_signal_connect_swapped(Race, "button_press_event", G_CALLBACK(RaceGame),NULL);
	
	War=MyEvent("pictures/war.jpeg");
	gtk_widget_set_size_request(War,175,80);
	gtk_tooltips_set_tip(Tooltips,War,"War Games",NULL);
	g_signal_connect_swapped(War, "button_press_event", G_CALLBACK(WarGame),NULL);

	HerosGame=MyEvent("pictures/horos2.jpeg");
	gtk_widget_set_size_request(HerosGame,175,80);
	gtk_tooltips_set_tip(Tooltips,HerosGame,"Horo Games",NULL);
	g_signal_connect_swapped(HerosGame, "button_press_event", G_CALLBACK(HeroGame),NULL);

	KidGame=MyEvent("pictures/kidgame.jpeg");
	gtk_widget_set_size_request(KidGame,175,80);
	gtk_tooltips_set_tip(Tooltips,KidGame,"Games For Children",NULL);
	g_signal_connect_swapped(KidGame,"button_press_event",G_CALLBACK(KidGames),NULL);

	//sports
	Widget Foot,Basket,Resl,Others;
	Foot=MyEvent("pictures/fifa.png");
	gtk_widget_set_size_request(Foot,175,80);
	gtk_tooltips_set_tip(Tooltips,Foot,"Football",NULL);
	g_signal_connect(Foot, "button_press_event", G_CALLBACK(Football),UrlText);
	
	Basket=MyEvent("pictures/basketball.jpeg");
	gtk_widget_set_size_request(Basket,175,80);
	gtk_tooltips_set_tip(Tooltips,Basket,"Basketball",NULL);
	g_signal_connect(Basket, "button_press_event", G_CALLBACK(Basketball),UrlText);

	Resl=MyEvent("pictures/resling.jpeg");
	gtk_widget_set_size_request(Resl,175,80);
	gtk_tooltips_set_tip(Tooltips,Resl,"Resling",NULL);
	g_signal_connect(Resl, "button_press_event", G_CALLBACK(Resling),UrlText);
	

	Others=MyEvent("pictures/games.jpeg");
	gtk_widget_set_size_request(Others,175,80);
	gtk_tooltips_set_tip(Tooltips,Others,"Rugby,Handball, MotoGP, Athletic and Other sports",NULL);
	g_signal_connect(Others,"button_press_event",G_CALLBACK(OtherSports),UrlText);


	//define the select type of entertianment;
	SelectType=gtk_combo_new();
	gtk_entry_set_text(GTK_ENTRY((GTK_COMBO(SelectType))-> entry),"Mp3 Music");
	GList *list=NULL;
	list=g_list_append(list," Music Vidios");
	list=g_list_append(list,"Movies");
	list=g_list_append(list,"Games");
	list=g_list_append(list,"Funny Vidio");
	list=g_list_append(list,"News");

	gtk_combo_set_popdown_strings(GTK_COMBO(SelectType),list);
	gtk_combo_set_case_sensitive(GTK_COMBO(SelectType),FALSE);
	//gtk_widget_set_size_request(SelectType,100,300);
	//getting the text from the combo
	SelectText=gtk_label_new(gtk_entry_get_text(GTK_ENTRY((GTK_COMBO(SelectType))->entry)));

	Widget back_button,forward_button,home_button,Iback,Iforward,Ihome;

	Iback=gtk_image_new_from_stock(GTK_STOCK_GO_BACK,1);
	Iforward=gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD,1);
	Ihome=gtk_image_new_from_stock(GTK_STOCK_HOME,1);

	back_button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(back_button),Iback);
	gtk_widget_set_size_request(back_button,40,40);
		gtk_tooltips_set_tip(Tooltips,back_button,"go back",NULL);
	forward_button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(forward_button),Iforward);	
	gtk_widget_set_size_request(forward_button,40,40);
		gtk_tooltips_set_tip(Tooltips,forward_button,"go forward",NULL);
	home_button=gtk_button_new();
	gtk_container_add(GTK_CONTAINER(home_button),Ihome);
		gtk_tooltips_set_tip(Tooltips,home_button,"Home",NULL);

	//create a table and insert struffs.
	Table=gtk_table_new(50,50,FALSE);
	gtk_table_attach_defaults(GTK_TABLE(Table),UrlText,10,40,0,1);
	gtk_table_attach(GTK_TABLE(Table),back_button,8,10,0,1,1,1,0,0);
	gtk_table_attach(GTK_TABLE(Table),forward_button,40,42,0,1,1,1,0,0);
	gtk_table_attach_defaults(GTK_TABLE(Table),home_button,46,48,0,1);
	gtk_table_attach(GTK_TABLE(Table), Slider,12,25,12,14, 1, 1, 0, 0 );	
	gtk_table_attach(GTK_TABLE(Table), News,30,35,12,14, 1, 1, 0, 0 );	
	
	//input search
	gtk_table_attach_defaults(GTK_TABLE(Table),InputText,15,30,15,18);
	gtk_table_attach_defaults(GTK_TABLE(Table),SelectType,30,32,15,18);
	gtk_table_attach(GTK_TABLE(Table),SearchButton,32,36,15,17, 1, 1, 0, 0 );

	//Labels
	gtk_table_attach(GTK_TABLE(Table), MusicLabel,8,14,17,18, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), MovieLabel,16,22,17,18, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), FunLabel,24,30,17,18, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), GameLabel,32,38,17,18, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), SportLabel,40,46,17,18, 1, 1, 0, 0 );

	//Music Search
	gtk_table_attach(GTK_TABLE(Table), AfricaM,8,14,18,25, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), NijiaM,8,14,26,30, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), KamerM,8,14,31,35, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), HipHop,8,14,36,40, 1, 1, 0, 0 );
	
	//movies Search
	gtk_table_attach(GTK_TABLE(Table), Nolly,16,22,18,25, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), Holly,16,22,26,30, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), Bolly,16,22,31,35, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), Horos,16,22,36,40, 1, 1, 0, 0 );

	//Funny Vidios
	gtk_table_attach(GTK_TABLE(Table), African,24,30,18,25, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), American,24,30,26,30, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), Europe,24,30,31,35, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), Kids,24,30,36,40, 1, 1, 0, 0 );

	//Game Search
	gtk_table_attach(GTK_TABLE(Table), Race,32,38,18,25, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), War,32,38,26,30, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), HerosGame,32,38,31,35, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), KidGame,32,38,36,40, 1, 1, 0, 0 );

	//Sports
	gtk_table_attach(GTK_TABLE(Table), Foot,40,46,18,25, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), Basket,40,46,26,30, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), Resl,40,46,31,35, 1, 1, 0, 0 );
	gtk_table_attach(GTK_TABLE(Table), Others,40,46,36,40, 1, 1, 0, 0 );

	

	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_scrolled_window_set_policy( GTK_SCROLLED_WINDOW(scrolledWindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_scrolled_window_add_with_viewport( GTK_SCROLLED_WINDOW(scrolledWindow), web[count]);
	gtk_widget_show_all(scrolledWindow);

	gtk_container_add( GTK_CONTAINER(pageLayoutExpander), scrolledWindow);
	gtk_table_attach_defaults(GTK_TABLE(Table), pageLayoutExpander,0,50,11,50);
	g_signal_connect_swapped(WEBKIT_WEB_VIEW(web[count]),"load-finished",G_CALLBACK(viewSearchedPage),pageLayoutExpander);


	g_signal_connect(InputText, "activate",  G_CALLBACK(activate), web[count]);

	g_signal_connect(WEBKIT_WEB_VIEW(web[count]),"load-progress-changed",G_CALLBACK(progress),UrlText);
	g_signal_connect(WEBKIT_WEB_VIEW(web[count]),"load-finished",G_CALLBACK(finished),UrlText);
	g_signal_connect_swapped(G_OBJECT(Window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(back_button, "clicked",  G_CALLBACK(back), web[count]);
	g_signal_connect(forward_button, "clicked",  G_CALLBACK(forward), web[count]);
 	g_signal_connect(home_button, "clicked",  G_CALLBACK(Home), web[count]);
 	g_signal_connect(NijiaM, "button_press_event",  G_CALLBACK(NijiaM), web[count]);
 	
 	

	return Table;
}


//This function deletes the current browser notebook page each time its called
void delete_tab( GtkWidget*  Notebook, gpointer data){
	gint pageNum;
	pageNum = gtk_notebook_get_current_page( GTK_NOTEBOOK(Notebook));

	//If there exist more than one tab it deletes else it notifies the user of the current status of only one tab
	if( NUMBER_OF_TABS > 1){
		gtk_notebook_remove_page( GTK_NOTEBOOK(Notebook), pageNum);
		//Number of tabs decrease by one each time a tab is deleted
		NUMBER_OF_TABS--;
	}
	else{
		GtkWidget * WindowPup, *Warning;
		WindowPup = gtk_window_new(GTK_WINDOW_TOPLEVEL);

		gtk_window_set_position( GTK_WINDOW(WindowPup), GTK_WIN_POS_CENTER_ALWAYS);
		gtk_window_set_title(GTK_WINDOW(WindowPup), "WARNING!!!!!!!!");
		gtk_window_set_default_size( GTK_WINDOW(WindowPup), 200, 200);
		gtk_window_set_resizable( GTK_WINDOW(WindowPup), TRUE);
		gtk_widget_set_size_request( WindowPup, 500, 300);

		//g_signal_connect(G_OBJECT(WindowPup), "destroy", G_CALLBACK( gtk_widget_hide), (gpointer) WindowPup);

		Warning = gtk_label_new("Click On Me  \n If You wanna Quit \n Or Cancel if you dont");
		g_signal_connect(G_OBJECT(Warning), "destroy", G_CALLBACK(Delete), (gpointer) Warning);
		gtk_container_add( GTK_CONTAINER(WindowPup), Warning);
		gtk_widget_show_all(WindowPup);
	}

}

//This function adds a new tab to the browser notebook each time its called
void addNewTab( GtkWidget* Notebook, gpointer data){

	Widget  Window, TableHeading, HboxHeader, HboxLabel, NoteBook, Cancel, Add, Table,Image2,Image3;
	gint currentPageNum;
	gint nextPageNum;

	Image2=gtk_image_new_from_stock(GTK_STOCK_ADD,1);
	Image3=gtk_image_new_from_stock(GTK_STOCK_CANCEL,1);

	//seting the count of the notebook
	count =gtk_notebook_get_current_page(GTK_NOTEBOOK(Notebook));
	web[count]=webkit_web_view_new();
	//Number of tabs increase by one each time a tab is added
	NUMBER_OF_TABS++;
	
	HboxHeader = gtk_hbox_new( TRUE, 0);
	gtk_widget_set_size_request( HboxHeader, 200, 20);

	HboxLabel = gtk_label_new("The Bolf");
	gtk_widget_set_size_request(HboxLabel, 95, 20);
	gtk_box_pack_start_defaults( GTK_BOX(HboxHeader), HboxLabel);

	Cancel = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(Cancel),Image3);
	gtk_button_set_relief( GTK_BUTTON( Cancel), GTK_RELIEF_NONE);
	//Connects signal related to close button
	g_signal_connect_swapped( G_OBJECT(Cancel), "clicked", G_CALLBACK(delete_tab), (gpointer) Notebook);
	gtk_box_pack_start_defaults( GTK_BOX(HboxHeader), Cancel);

	Add = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(Add),Image2);
	gtk_widget_set_size_request( Add, 20, 20);
	//Connects the Add to its callback function when clicked
	g_signal_connect_swapped( G_OBJECT(Add), "clicked", G_CALLBACK(addNewTab), (gpointer) Notebook);
	gtk_box_pack_start_defaults( GTK_BOX(HboxHeader), Add);
	gtk_widget_show_all(HboxHeader);
	
	//Table = gtk_table_new( 50, 50, FALSE);
	Table = BolfView();

	currentPageNum = gtk_notebook_get_current_page(GTK_NOTEBOOK(Notebook));
	//g_signal_connect(SearchButton, "clicked",  G_CALLBACK(InputConnect), InputText);
	nextPageNum = currentPageNum + 1;
	gtk_notebook_insert_page( GTK_NOTEBOOK(Notebook), Table, HboxHeader, nextPageNum);
	gtk_notebook_next_page( GTK_NOTEBOOK(Notebook));
	gtk_widget_show_all(Notebook);
}

//Internet Functions
void InputConnect( GtkWidget* widget,gpointer* wid)
{
	
/*	char url[35]="http://";
	Widget InputText = GTK_WIDGET(wid);
	uri = gtk_entry_get_text(GTK_ENTRY(InputText));
	strcat(url,uri);
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web),url);
*/
	//Checking if the web address already has http attached to if, if not it is attached to the address
	Widget Input = GTK_WIDGET(wid);
	uri = gtk_entry_get_text(GTK_ENTRY(Input));

	//These if constructs ensure that the url is in order
	//If address is online or on user's machine
		//seting the count of the notebook

	
	
	if( (uri[0] == 'h' && uri[1] == 't' && uri[2] == 't' && uri[3] == 'p') || (uri[0] == 'f' && uri[1] == 'i' && uri[2] == 'l' && uri[3] == 'e')){
		//The address is in the correct format
//		uri = gtk_entry__text(GTK_ENTRY(InputText));
	}
	else{

		if( uri[0] == 'w' && uri[1] == 'w' && uri[2] == 'w'){
			//address lacks http://, which is added
			gtk_entry_prepend_text(GTK_ENTRY(Input),"http://");
			uri = gtk_entry_get_text(GTK_ENTRY(Input));
		}
		else{
			
			if(  strstr(uri, ".com") && uri[0] != '.'){
				//if address ends with .com like youtube.com
				gtk_entry_prepend_text(GTK_ENTRY(Input),"http://www.");
				uri = gtk_entry_get_text(GTK_ENTRY(Input));
			}
			else{
				//if address has none of the above, google is used to search for the user's text
				gtk_entry_prepend_text(GTK_ENTRY(Input),"http://www.google.com/");
				uri = gtk_entry_get_text(GTK_ENTRY(Input));
				
			}
		}
	}
	gtk_entry_set_text(GTK_ENTRY(UrlText),uri);
	//gtk_entry_set_text(GTK_ENTRY(Input),".");
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);
} 



void back( GtkWidget* widget , gpointer* wid)
{
	 web[count] = GTK_WIDGET(wid);
	webkit_web_view_go_back(WEBKIT_WEB_VIEW(web[count]));
 
}
void forward(GtkWidget* widget , gpointer* wid){
	 web[count] = GTK_WIDGET(wid);
	webkit_web_view_go_forward(WEBKIT_WEB_VIEW(web[count]));
	 
}
void stop(GtkWidget* widget, gpointer* wid)
{
	web[count] = GTK_WIDGET(wid);
	webkit_web_view_stop_loading(WEBKIT_WEB_VIEW(web[count]));
	 
}
void activate( GtkWidget* widget , gpointer* wid)
{
	web[count] = GTK_WIDGET(wid);
	uri = gtk_entry_get_text(GTK_ENTRY(widget));
	gtk_entry_progress_pulse(GTK_ENTRY(widget));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);
	 
}
void progress (WebKitWebView *web, gint progress,gpointer* data)
{
	GtkWidget* wid = GTK_WIDGET(data);
	gtk_entry_set_progress_fraction (GTK_ENTRY(wid),progress);
}
 
void finished (WebKitWebView  *web_view, WebKitWebFrame *frame,gpointer*  data)
{
	GtkWidget* wid = GTK_WIDGET(data);
	gtk_entry_set_progress_fraction (GTK_ENTRY(wid),0.0);
}

void Newso()
{
	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.gistus.com/music");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);

}
//Music
void NijiaMusic()
{
		char url[45];	
	strcpy(url,"http://www.last.fm/tag/nigermusic");
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);

}


void AfricaMusic()
{

	char url[45];	
	strcpy(url,"http://tooxclusive.com/");
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);

}

void KamerHits( )
{
	char url[45];	
	strcpy(url,"http://www.last.fm/tag/cameroon");
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);
}

void HipHopMusic( )
{
	
	char url[45];
	
	strcpy(url,"http://allhiphop.com/");
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);

}


//Movies
void Nollywood( )
{

	
	char url[45];
	
	strcpy(url,"http://www.nollywoodmovies.tv/files/index.php");
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);
	
}

void Hollywood()
{

	char url[45];
	
	strcpy(url,"http://www.hollood.com");
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);
	
}

void Horosmov( )
{

	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.gamespot.com/gallery/the-best-horror-movies-of-2015-so-far-ranked/2900-294/");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);

}

void Bollywood( )
{

	char url[45];
	
	strcpy(url,"http://www.bollywood.com");
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);
	
}


//fun
void NijiaBoys()
{

	
	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.gq234.com/basketmouth-night-of-a-thousand-laughs-vol-19/");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);

}

void AmericaFun()
{
	
	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://abc.go.com/shows/americas-funniest-home-videos");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);
}
	

void AfricaFun()
{


	gtk_entry_set_text(GTK_ENTRY(UrlText),"https://www.youtube.com/watch?v=sPLVhVutaHE");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);
	

}

void KidsMovies()
{

		char url[45];
	
	strcpy(url,"http://pbskids.org/video/");
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);
	
}


//games
void RaceGame(GtkWidget* widget , gpointer* wid)
{

	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.thecargames.org/‎");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);

}

void WarGame(GtkWidget* widget , gpointer* wid)
{


	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://armorgames.com/category/war-games");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);

}

void HeroGame(GtkWidget* widget , gpointer* wid)
{

	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.horoscope.com/us/games/index-games.aspx");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);	 
}

void KidGames( GtkWidget* widget , gpointer* wid)
{

	gtk_entry_set_text(GTK_ENTRY(UrlText),"https://www.gofundme.com/blackberrycreek");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);

 
}



//sports

void Football(GtkWidget* widget, GdkEvent * event , gpointer UrlText)
{

	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.xscores.com/soccer/livescores/06-12");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);
 
}


void Basketball(GtkWidget* widget, GdkEvent * event , gpointer UrlText)
{

	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.supersport.com/basketball/nba?r=www");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);
 
}


void OtherSports(GtkWidget* widget, GdkEvent * event , gpointer UrlText)
{

	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.bbc.co.uk/sport/0/");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);
 
}

void Resling(GtkWidget* widget, GdkEvent * event , gpointer UrlText)
{

	gtk_entry_set_text(GTK_ENTRY(UrlText),"http://www.dailymotion.com/video/x2s29rs");
	gtk_widget_show_all(UrlText);
	uri = gtk_entry_get_text(GTK_ENTRY(UrlText));
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),uri);
 
}

void Home()
{
	char url[200]="file://";
	char name[200];
	getcwd(name,200);
	
	strcat(name,"/bolf/bolfhome.html");
	strcat(url,name);
	gtk_entry_set_text(GTK_ENTRY(UrlText),url);
	gtk_entry_progress_pulse(GTK_ENTRY(UrlText));
	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web[count]),url);
}

