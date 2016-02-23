
#include <stdio.h>
#include <gtk/gtk.h>
#include "bolf.h"

int main(int argc, char  *argv[])
{
	gtk_init(&argc,&argv);

	GtkTooltips *Tooltips;
	Tooltips=gtk_tooltips_new();

	
	//Declaration of variables
	Widget  Window, TableHeading, HboxHeader, HboxLabel, NoteBook, Cancel, Add, Table,Image2,Image3;
	NoteBook=gtk_notebook_new();
	
	Image2=gtk_image_new_from_stock(GTK_STOCK_ADD,1);
	Image3=gtk_image_new_from_stock(GTK_STOCK_CANCEL,1);
	//declearing Window

	Window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(Window),"THE BOLF");
	gtk_widget_set_size_request(Window,1000,600);
	gtk_container_set_border_width(GTK_CONTAINER(Window),0);
	g_signal_connect(G_OBJECT(Window),"delete_event",G_CALLBACK(Delete),NULL);

	//Initialising the Add and linking it with its callback function when clicked
	Add = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(Add),Image2);
	gtk_button_set_relief( GTK_BUTTON(Add), GTK_RELIEF_NONE);
	gtk_tooltips_set_tip(Tooltips,Add,"Add Tab",NULL);
	g_signal_connect_swapped( G_OBJECT(Add), "clicked", G_CALLBACK(addNewTab), (gpointer) NoteBook);
	//Initialises the hbox-It contains the Add, Cancel and the HboxLabel 
	HboxHeader = gtk_hbox_new( TRUE, 0);
	gtk_widget_set_size_request( HboxHeader, 200, 20);

	HboxLabel = gtk_label_new("The Bolf");
	gtk_widget_set_size_request( HboxLabel, 95, 20);
	
	//Initialising the Cancel and linking it with its callback function when clicked
	Cancel = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(Cancel),Image3);
	gtk_button_set_relief( GTK_BUTTON(Cancel), GTK_RELIEF_NONE);
	gtk_tooltips_set_tip(Tooltips,Cancel,"Cancel",NULL);
	//g_signal_connect_swapped( G_OBJECT(Cancel), "clicked", G_CALLBACK(delete_tab), (gpointer) NoteBook);

	//Adding widgets to the hbox
	gtk_box_pack_start_defaults( GTK_BOX(HboxHeader), HboxLabel);
	gtk_box_pack_start_defaults( GTK_BOX(HboxHeader), Cancel);
	gtk_box_pack_start_defaults( GTK_BOX(HboxHeader), Add);

	gtk_widget_show_all(HboxHeader);
 
 	//getting the table
	Table=BolfView();
	
	gtk_notebook_append_page( GTK_NOTEBOOK(NoteBook), Table, HboxHeader);

	//sets the browser form scrollable and then add the NoteBook to the main window
	gtk_notebook_set_scrollable( GTK_NOTEBOOK(NoteBook), TRUE);
	gtk_container_add(GTK_CONTAINER(Window), NoteBook);

	//gtk_container_add(GTK_CONTAINER(Window),Table);

	
	gtk_widget_show_all(Window);

	
	gtk_main();
	return 0;
}
